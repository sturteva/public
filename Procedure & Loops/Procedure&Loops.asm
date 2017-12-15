TITLE Project 3   (project3.asm)

; Author: Andrew P. Sturtevant
; Course / Project ID: CS271-400               Date: 26 July 2017
; Description: This program will calculate composite numbers. First the user 
; will enter the number of composites to be displayed, and will be prompted
; until s/he enters a value in a specified range. The program then calculates
; and displays all of the composite numbers up to and including the nth 
; composite. The results will be displayed 10 composites per line with at least
; 3 spaces between numbers.

INCLUDE Irvine32.inc

UPPER_COMPOSITE_LIMIT = 400 ;This is the max for the base program
LOWER_LIMIT = 1 ;This is the lower limit for the base program
.data

	authorName		BYTE	"CS271-400 Project 2		by Andrew P. Sturtevant", 0
	goodBye			BYTE	"Results Verified by Andrew Sturtevant. Goodbye", 0
	instruction		BYTE	"Enter the number of composite numbers you would like to see", 0
	warning			BYTE	"I'll accept orders for up to 400 composites.", 0
	requestInput	BYTE	"Enter the number of composites to display [1 .. 400]: ",0
	outRange		BYTE	"Out of range. Try again.",0
	spaces			BYTE	"   ",0
	userInput		DWORD	?
	compositeNum	DWORD	3
	valueCount		DWORD	1
	oddCompare		DWORD	3
	evenCompare		DWORD	2

	
.code
main PROC

	call		introduction
	call		getUserData	
	call		showComposites
	call		farewell

	exit	; exit to operating system
main ENDP


introduction PROC
	pushad

	mov			edx, OFFSET authorName
	call		WriteString
	call		CrLF
	call		CrLF

	popad
	ret
introduction ENDP

getUserData PROC

	pushad

	mov			edx, OFFSET instruction
	call		WriteString
	call		CrLF

	mov			edx, OFFSET warning
	call		WriteString
	call		CrLF
	call		CrLF

	mov			edx, OFFSET requestInput
	call		WriteString
	call		validate

	popad
	ret
getUserData ENDP

validate PROC

pushad

startValid:
	;gets an integer from the User
	call		ReadInt
	cmp			eax, UPPER_COMPOSITE_LIMIT 
	jbe			secondCheck ;if the input is below the upper limit,
							;it will jump to do a second check for the lower
							;limit

inputInvalid:
	
	;Lets the user know that the input is out of range
	mov			edx, OFFSET outRange
	call		WriteString
	call		CrLF

	;Requests for input against, starting the validation over again
	mov			edx, OFFSET  requestInput
	call		WriteString
	jmp			startValid

secondCheck:
	;A simple check for the lower limit, if it is lower, then it goes to
	;inputInvalid label and follows its process, otherwise it continues. 
	cmp			eax,LOWER_LIMIT
	jl			inputInvalid

	mov			userInput, eax
	popad
	ret
validate ENDP

showComposites PROC
	pushad

	mov ecx, userInput
;Will loop through equal to the number of composites the user wants
startLoop:	

	call		isComposite	

	;Prints the composite number once it is found
	mov			eax,compositeNum
	call		WriteDec
	mov			edx, OFFSET spaces
	call		WriteString

	;Ensures there are only 10 values per line
	cmp			valueCount,10
	je			newLine
	inc			valueCount

	loop		startLoop
	jmp			endComposites

newLine:
	call		CrLF

	mov			eax, 1
	mov			valueCount, eax

	loop		startLoop

endComposites:
	call		CrLF
	call		CrLF
	popad
	ret
showComposites ENDP

isComposite PROC
	pushad

	inc compositeNum
	
;All even numbers are composite because they are divisible by 2. The following
;checks to see if a number is even.
evenCheck:	

	mov		eax,compositeNum
	mov		edx, 0
	div		evenCompare
	cmp		edx,0
	je		calculated
	
;If compositeNum is not even, it will then try and divide itself by all odd
;numbers less than itself, starting at 3. 
notEven:
	
	mov		eax,compositeNum
	mov		edx, 0
	div		oddCompare
	cmp		edx,0
	je		calculated
	
	mov		eax, oddCompare
	add		eax,2
	mov		oddCompare,eax
	mov		ebx,compositeNum
	cmp		eax,ebx
	jb		notEven
	
	;increment numbers
	inc		compositeNum
	
	;resets the oddCompare back to 3.
	mov		eax,3
	mov		oddCompare,eax

	jmp		evenCheck
	

calculated:	

	;Resets oddCompare back to 
	mov		eax,3
	mov		oddCompare,eax

	;Matches nextComposite to the current compositeNum and then increments it up
	;by one for the next time this procedure is called. 
	;mov		eax, compositeNum
	;mov		nextComposite, eax
	;inc		nextComposite
	
	popad
	ret

isComposite ENDP

farewell PROC
	
	mov			edx, OFFSET goodBye
	call		WriteString
	call		CrLF
	call		CrLF

	ret
farewell ENDP


END main
