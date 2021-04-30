section	.text
	global		_ft_strdup
	extern		_ft_strcpy
	extern		_ft_strlen
	extern 		_malloc

; delete RDX, RCX, RAX and everything that malloc destroy

_ft_strdup:
	mov		rax, 0				; i = 0;
	call	_ft_strlen			; rax = ft_strlen(rdi)
	add		rax, 1				; rax + 1 (for nul terminator)
	push	rdi					; push rdi into the stack
	push	rax					; push rax into the stack
	pop		rdi					; pulling the value of rax from the stack and saving it in rdi
	call	_malloc				; malloc of rdi
	jc		_error				; if malloc fails jump to error
	pop		rsi					; pulling rdi in rsi
	push	rax					; pushing rax (that is an allocated memory) into the stack
	pop		rdi					; pulling the allocated memory in rdi
	call	_ft_strcpy
	ret

_error:
	pop		rax
	mov		rax, 0
	ret
