section .text
	global _ft_write
	extern ___error

_ft_write:
	mov			rax, 0x2000004		; MacOS calling convention
	syscall
	jc			_error				; if an error occurs, jump to _error
	ret

_error:
	push		rax					; push the code error in rax into the stack
	call		___error			; rax points to the address where the system finds the error
	pop			r10					; pulls/saves in r10 the error code that was pushed in rax(that is in the stack)
	mov			[rax], r10			; saves the error code at the address pointed to by rax (where the error was found)
	mov			rax, -1				; saving -1 (the result of write when it fail) in rax
	ret
