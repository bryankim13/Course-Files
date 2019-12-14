;Bryan Kim
;bjk3yf
;11/9/19
;threexplusone.s

				;Optimizations: 
					;Initially had a subroutine EVEN which was jumped to
					;if not jumped to odd. This was optimized by merging EVEN
					;with start.

					;instead of using mult or idiv, I used shr and shl to 
					;divide and multiply more efficiently. 

	global threexplusone

	section .text

;rdi contains the int parameter i

threexplusone:
					xor 	eax, eax		;counter = 0
					

start:
					mov		r10, rdi		;copies i to r10
					cmp 	rdi, 1			;if(i>1)
					je 		done			;goes to end if i == 0		
					inc		eax				;counter++
					push 	rdi				;if(i is odd)
					and 	rdi, 1
					cmp 	rdi, 1
					je 		odd
					pop 	rdi				;else
					push  	rdi
					shr		rdi, 1			;i/2
					jmp looping

odd:
					pop		rdi
					push 	rdi
					shl		rdi, 1
					add 	rdi, r10
					add		rdi, 1
					jmp looping

looping:
					call start
					pop rdi

done:
					ret