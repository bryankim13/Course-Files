; mathlib.s
; Bryan Kim
; bjk3yf
; 11/4/19
; mathlib.s

	global product
	global power

	section .text

; rdi and rsi contain the two int parameters k and j

product:	
		xor		rax, rax 	;makes the return object 0
		xor 	r10, r10 	;makes i counter 0
startMult: 
		cmp 	r10, rsi 	;compares i with j
		je  	proDone  	;jumps to proDone when done
		add		rax, rdi 	;adds value to rax
		inc 	r10			;increments i
		jmp 	startMult	;jumps back to the begining of the loop
proDone: 
		ret

power:
		mov 	rax, 1		;makes rax 1 for base case
		xor 	r11, r11	;clears this value	
mPow: 
		cmp 	r11, rsi	;compares i with j
		je		powDone	
		push 	rsi			;saves value of rsi
		mov 	rsi, rax	;sets up the registers to preform product
		call 	product
		pop 	rsi
		inc 	r11
		call 	mPow

powDone:
		ret