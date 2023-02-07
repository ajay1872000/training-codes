	.file	"scf.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\n0.exit\n1.Reverse a number\n2.Palindrome\n3.sum of digits\n4.no of digits\n5.Decimal to binary\n6.Binary to decimal\n enter a option"
.LC1:
	.string	"%d"
.LC2:
	.string	"enter a value"
.LC3:
	.string	"%d reverse is %d"
.LC4:
	.string	"%d is a palindrome"
.LC5:
	.string	"%d is not a palindrome"
.LC6:
	.string	"%d is sum of digits of %d"
.LC7:
	.string	"%d is no of digits in %d"
.LC8:
	.string	"%d is binary number for %d"
.LC9:
	.string	"invalid number"
.LC10:
	.string	"%d is decimal number for %d"
.LC11:
	.string	"invalid case"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L17:
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	stdin(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__fpurge@PLT
	movl	-16(%rbp), %eax
	cmpl	$6, %eax
	jg	.L2
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	jle	.L2
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
.L2:
	movl	-16(%rbp), %eax
	cmpl	$6, %eax
	ja	.L3
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L5(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L5(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L11-.L5
	.long	.L10-.L5
	.long	.L9-.L5
	.long	.L8-.L5
	.long	.L7-.L5
	.long	.L6-.L5
	.long	.L4-.L5
	.text
.L11:
	movl	$0, %edi
	call	exit@PLT
.L10:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	rev_digit@PLT
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %eax
	movl	-12(%rbp), %edx
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L9:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	rev_digit@PLT
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jne	.L13
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L13:
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L8:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	sum_of_digit@PLT
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L7:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	no_of_digit@PLT
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L6:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	dec_to_bin@PLT
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L4:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	bin_to_dec@PLT
	movl	%eax, -12(%rbp)
	cmpl	$-1, -12(%rbp)
	jne	.L15
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L15:
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L12
.L3:
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L12:
	jmp	.L17
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
