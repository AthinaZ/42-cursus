section .text
	global _ft_strlen

_ft_strlen:
	mov			rax, -1				; i = -1

_start:
	inc			rax					; i++
	cmp byte	[rdi + rax], 0
	jne			_start				; while (s[i] != 0)
	ret								; return (i)
