TITLE Project 4    (project4.asm)

; Author: Andrew P. Sturtevant
; Course / Project ID: CS271-400               Date: 26 July 2017
; Description: This program will first ask the user how many integers 
; they would like between 10 and 200. It will then generate that many integers.
; The program will then display the array. Then it will sort the array. 
; Calculate the median, display that. Then display the sorted array.  

INCLUDE Irvine32.inc

MIN_RANGE = 10 ;smallest number of integers in the array
MAX_RANGE = 200 ;largest number of integers in the array
LO = 100 ;lowest the random integers will be 
HI = 999 ; highest the random integers will be
LINE_COUNT = 10 ;The maximum number of items in a line

.data

authorName		BYTE	"CS271-400 Project 4		by Andrew P. Sturtevant", 0
goodBye			BYTE	"Results Verified by Andrew Sturtevant. Goodbye", 0
listArray		DWORD	MAX_RANGE DUP(?)
count			DWORD	?
intro			BYTE	"This program generates randoms numbers in the range"
				BYTE	" [100 .. 999], displays the original list, sorts"
				BYTE	" the list, and calculates the median value. Finally,"
				BYTE	" it displays the list sorted in descending order.",0

prompt1			BYTE	"How many numbers should be generated? [10 ..200]: ",0

outRange		BYTE	"Invalid Input",0
spaces			BYTE	"   ",0
median			BYTE	"The Median of this Array is: ",0
unsorted		BYTE	"The unsorted random numbers: ",0
sorted			BYTE	"The sorted list: ",0


.code
main PROC

call	Randomize ;Creates a random seed to be used later

call	introduction

push	OFFSET count
call	getData

push	OFFSET listArray
push	count
call	fillArray

mov		edx, OFFSET unsorted
call	writeString
call	CrLF
push	OFFSET	listArray
push	count
call	displayArray

push	OFFSET listArray
push	count
call	sortArray

push	OFFSET listArray
push	count
call	displayMedian

mov		edx, OFFSET sorted
call	writeString
call	CrLF

push	OFFSET	listArray
push	count
call	displayArray

call	farewell

	exit	; exit to operating system
main ENDP

introduction PROC
pushad

mov		edx, OFFSET authorName
call	WriteString
call	CrLF
call	CrLF

mov		edx, OFFSET intro
call	WriteString
call	CrLF
call	CrLF


popad
ret
introduction ENDP

;Must get the Count as a reference
getData PROC
push ebp
mov ebp,esp
mov edx, OFFSET prompt1
call	WriteString

push	[ebp+8]
call	validate

pop ebp
ret 4
getData ENDP

validate PROC
push ebp
mov	ebp, esp

startValid:

	;gets an integer from the User
	call	ReadInt
	cmp		eax, MAX_RANGE
	jbe		secondCheck

inputInvalid:

	;Lets the user know that the input is out of range
	mov		edx, OFFSET outRange
	call	WriteString 
	call	CrLF

;Requests for input again, starting the validation over again
	mov		edx, OFFSET prompt1
	call	WriteString
	jmp		startValid

secondCheck:

	;Checks for the lower limit of the range
	cmp		eax,MIN_RANGE
	jl		inputInvalid

	mov		ebx, [ebp+8] 
	mov		[ebx], eax

	pop ebp
	ret 4
validate ENDP

;Most of this was modified or copied from ArrayFill.asm in the Irvine library
fillArray PROC

push	ebp
mov		ebp,esp
pushad

mov		edi, [ebp+12]
mov		ecx, [ebp+8]
cmp		ecx, 0 
je		L2

L1:
;This will randomly generate a number from 100-999
mov		eax,HI
sub		eax,LO
inc		eax
call	RandomRange
add		eax,LO

;This places the Random Number into the array
mov		[edi],eax
add		edi, TYPE DWORD
loop	L1

L2:
popad
pop ebp
ret 8
fillArray ENDP

displayArray PROC
push ebp
mov		ebp,esp
pushad

mov		eax, 0
mov		edi, [ebp + 12]
mov		ecx, [ebp + 8]
mov		ebx, 1

startDisplay:
;Prints the number in the array
mov		eax, [edi]
call	WriteDec
mov		edx, OFFSET spaces
call	WriteString
add		edi, TYPE DWORD

;Ensures there are only 10 values per line
cmp		ebx, LINE_COUNT
je		newLine
inc		ebx

loop	startDisplay
jmp		endDisplay

newLine:
call	CrLF
mov		ebx,1
loop	startDisplay

endDisplay:
call	CrLF
call	CrLF

popad	
pop ebp
ret 8 
ret
displayArray ENDP

;This is a Bubble Sort that was modified from Bsort.asm from the provided asm files in Irvine.
sortArray PROC
push	ebp
mov		ebp,esp


mov		ecx, [ebp+8]
dec		ecx

outerSort:
push	ecx 
mov		edi, [ebp+12]

innerSort:
mov		eax, [edi]
cmp		[edi+4],eax
jle		incSort
xchg	eax, [edi+4]
mov		[edi],eax

incSort:
add		edi,4
loop	innerSort

pop		ecx
loop	outerSort

endSort:
pop		ebp
ret 8
sortArray ENDP



displayMedian PROC
push ebp
mov		ebp,esp
pushad

mov		edi, [ebp + 12]
mov		eax, [ebp + 8]
mov		ebx, 2
mov		edx, 0

;Checks to see if there are an even number of elements. If so, median calculation needs to happen.

div		ebx
cmp		edx,0
je		evenElements

oddElements:

mov		ebx,4
mul		ebx
add		edi,eax
mov		eax, [edi]
jmp		endMedian

evenElements:
mov		edx, 0

mov		ebx,4
mul		ebx
add		edi,eax
mov		ecx, [edi]

mov		eax, [edi - 4]

add		eax,ecx
mov		ebx, 2
div		ebx
cmp		edx, 0
je		endMedian
cmp		edx,4
jl		endMedian

roundUp:
add		eax,1
jmp		endMedian

endMedian:

mov		edx, OFFSET median
call	WriteString
call	WriteDec
call	CrLF
call	CrLF

popad
pop		ebp
ret 8 
displayMedian ENDP

farewell PROC
mov			edx, OFFSET goodBye
call		WriteString
call		CrLF
call		CrLF

ret
farewell ENDP

END main
