section 	.text
	global		_ft_strcmp



_ft_strcmp:
	mov			rcx, -1					; i = -1;

_compare:
	inc			rcx						; i++
	mov			r8b, BYTE[rdi + rcx]	; char temp_1 = s1[i]
	mov			r9b, BYTE[rsi + rcx]	; char temp_2 = s2[i]
	cmp			r8b, r9b
	jne			_return					; while ((s1[i] == s2[i]) && ...
	cmp			r8b, 0
	je			_return					; ... (s1[i] != 0) && ...
	cmp			r9b, 0
	je			_return					; ...(s2[i] != 0))
	jmp			_compare

_return:
	sub			r8b, r9b				; char temp = s1[i] - s2[i]
	movsx		rax, r8b				; ret = temp
	ret

