	.file	"funcpointarg.c"
	.text
.globl addition
	.type	addition, @function
addition:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	leal	(%edx,%eax), %eax
	popl	%ebp
	ret
	.size	addition, .-addition
.globl substraction
	.type	substraction, @function
substraction:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	popl	%ebp
	ret
	.size	substraction, .-substraction
.globl operation
	.type	operation, @function
operation:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	16(%ebp), %eax
	call	*%eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	ret
	.size	operation, .-operation
	.section	.rodata
.LC0:
	.string	"%d %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$substraction, 28(%esp)
	movl	$addition, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$20, 4(%esp)
	movl	$10, (%esp)
	call	operation
	movl	%eax, 20(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$30, 4(%esp)
	movl	$40, (%esp)
	call	operation
	movl	%eax, 16(%esp)
	movl	$.LC0, %eax
	movl	16(%esp), %edx
	movl	%edx, 8(%esp)
	movl	20(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
