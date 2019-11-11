	.file	"8.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$10, 28(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC0, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	movl	$.LC0, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	movl	$.LC0, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
