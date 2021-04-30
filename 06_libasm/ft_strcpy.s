section .text
	global	_ft_strcpy

_ft_strcpy:
	mov			rax, rdi				; char *ret = &dest
	mov			rcx, -1					; i = -1

_copy:
	inc			rcx						; i++
	mov			dh, BYTE[rsi + rcx]		; char temp = src[i]
	mov			BYTE[rdi + rcx], dh		; dest[i] = temp
	cmp			BYTE[rsi + rcx], 0
	jne			_copy					; while (s[i] != 0)
	ret									; return (ret)

