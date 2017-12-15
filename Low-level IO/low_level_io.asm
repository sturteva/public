TITLE Program 5A     (project5a.asm)

; Author: Andrew P. Sturtevant
; Course / Project ID: CS271-400               Date: 10 Aug 2017
; Description: This program implements my own ReadVal and WriteVal procedures for
; an unsigned integer.  It will also implement a getString and a displayString
; macro.  The actual body of the program will get 10 valid integers from the user
; and store the numeric values in an array.  The program will then display the 
; integers, their sum and their average.  

INCLUDE Irvine32.inc

displayString MACRO string ;Displays a string
pushad
mov	edx, string
call	WriteString
popad
ENDM

;The prompt should just be a reference to another string and input should be
;reference to an empty string location 
getString MACRO prompt, address, length
pushad

displayString prompt
mov		edx, address
mov		ecx, length
call	ReadString
call	CrLF
popad

ENDM	

MAX_SIZE = 10 ;The # of integers that we want to get from the user. 


.data

authorName		BYTE	"CS271-400 Project 5A		by Andrew P. Sturtevant", 0
goodBye			BYTE	"Results Verified by Andrew Sturtevant. Goodbye", 0
instruction1	BYTE	"Please provide unsigned decimal integers.", 0
instruction2	BYTE	"Each number needs to be small enough to fit inside a 32"
				BYTE	" bit register", 0
instruction3	BYTE	"After you have finished inputting the raw numbers, " 
				BYTE	"I will display a list of integers, their sum and their"
				BYTE	" average value.", 0
prompt1			BYTE	"Please enter an unsigned number: "
theString		BYTE	32 DUP(?),0
buffer			BYTE	255 DUP(0)
intArray		DWORD	MAX_SIZE DUP(0)
invalid			BYTE	"ERROR: You did not enter an unsigned number or your"
				BYTE	" number was too big. Please try again.",0
testNote		BYTE	"THIS IS A TEST NOTE", 0
displayPrompt	BYTE	"You entered the following numbers:",0
comma			BYTE	", ",0
sumPrompt		BYTE	"The Sum of the numbers is: ",0
avgPrompt		BYTE	"The Average(Rounded Down) is: ",0



.code
main PROC
mov		ebx, 0

push	OFFSET instruction3
push	OFFSET instruction2
push	OFFSET instruction1
push	OFFSET authorName
call	introduction

push	OFFSET prompt1
push	OFFSET invalid
push	OFFSET buffer
push	OFFSET SIZEOF buffer
push	OFFSET intArray
call	readVal

mov		ecx, MAX_SIZE
mov		edi, OFFSET intArray
displayString OFFSET displayPrompt
call	CrLF

repeatWrite:
mov		eax, [edi]
add		ebx, eax ;This is creating out Sum to display later as we go 
			 ;through each integer

push	eax
push	OFFSET theString
call	writeVal
displayString	OFFSET comma
add		edi,4
loop	repeatWrite

call	CrLF


push	OFFSET avgPrompt
push	OFFSET sumPrompt
push	OFFSET theString
push	ebx
call	math

push	OFFSET goodBye
call	farewell

	exit	; exit to operating system
main ENDP

introduction PROC
push	ebp
mov		ebp,esp
pushad

displayString [ebp+8]
call			CrLF
call			CrLF
displayString [ebp+12]
call			CrLF
displayString [ebp+16]
call			CrLF
displayString [ebp+20]
call			CrLF
call			CrLF

popad
pop ebp
ret 16
introduction ENDP

;***************************************************************
;The readVal procedure basically just loops the validate procedure
;ten times, also controlling which element of the integer Array gets
;passed to the validate function.
;****************************************************************
readVal PROC
push	ebp
mov		ebp,esp
pushad

mov		ecx, MAX_SIZE
add		ecx, 1
mov		edi, [ebp+8] ;Address of intArray

readLoop:

push	[ebp+24]
push	[ebp+20]
push	[ebp+16]
push	[ebp+12]
push	edi ;Address of intArray
call	validate
add		edi,4
mov		eax, 0
cmp		ecx, 2
je		endReadVal

loop	readLoop

endReadVal:
popad		
pop ebp

ret 20
readVal ENDP

;Validate PROC********************************************
;This procedure validates and converts a string into an 
;integer
;**********************************************************
validate PROC
push	ebp
mov		ebp,esp
pushad


setValidation:
mov		edx, [ebp+16]
mov		ecx, [ebp+12]
getString [ebp+24], edx, ecx



mov		esi, edx
mov		eax, 0
mov		edi, [ebp+8] ; Address of intArray


cld ;Resets the direction flag to 0

checkValidation:
lodsb
cmp	al, 0
je	endValidation
cmp al, 30h ;Checks to see if characer is a valid numerical digit
jl invalidInput
cmp al, 39h ;Checks to see if characer is a valid numerical digit
jg invalidInput

;begin conversion to integer
movsx ebx, al
sub   ebx, 30h

mov	eax, [edi]
mov	edx, 10
mul edx

add  eax, ebx
mov	 [edi], eax
loop checkValidation
jmp endValidation

invalidInput:
;mov		theString, 0
 
displayString [ebp+20]
call	CrLF

jmp setValidation


endValidation:
popad
pop ebp
ret 20
validate ENDP

;*********************************************************************
;The writeVal procedure converts a given integer into a string of equivalent
;ASCII characters, and then prints it out.
;**********************************************************************
writeVal PROC
push	ebp
mov		ebp,esp
pushad

mov		edi,[ebp+8]  ;This is the address of the String that will be 
					 ;taking each character of the converted int
mov		eax,[ebp+12] ;This is the integer to be converted to a string
mov		ebx, MAX_SIZE ; this will be used for the conversion to int
push	0

BeginConversion:

mov		edx, 0
div		ebx
add		edx, 30h
push	edx

cmp		eax, 0
jne		BeginConversion

AddToString:
pop		[edi]
mov		eax, [edi]
inc		edi
cmp		eax, 0
jne		AddToString

endWrite:
displayString [ebp+8]

popad
pop ebp
ret 8
writeVal ENDP

;****************************************************************
;The math procedure simplay displays the sum that is gathered in 
;the main procedure and then finds the average of the integers,
;rounded down.
;*****************************************************************
math	PROC
push	ebp
mov		ebp,esp
pushad

mov		eax, [ebp+8]

;This will display the Sum
displayString [ebp+16]
push	eax
push	[ebp+12]
call	writeVal 
call	CrLF

;This will calculate the Average
mov		edx, 0
mov		ebx, MAX_SIZE
div		ebx

displayString [ebp+20]
push	eax
push	[ebp+12]
call	writeVal

popad
pop	ebp
ret 16
math ENDP

farewell PROC
push	ebp
mov		ebp,esp
pushad

call	CrLF
displayString	[ebp+8]
call	CrLF

popad
pop	ebp
ret 4
farewell ENDP

END main
