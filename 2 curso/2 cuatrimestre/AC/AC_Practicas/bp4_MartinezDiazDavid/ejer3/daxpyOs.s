	.file	"daxpy.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"NUMERO DE PARAMETROS INTRODUCIDOS INCORRECTO"
.LC3:
	.string	"\n>> TIEMPO DE EJECUCION: %11.9f | DIMENSION: %d\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leal	-1(%rdi), %eax
	cmpl	$1, %eax
	jbe	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	movl	$134217728, %r12d
	cmpl	$2, %edi
	jne	.L3
	movq	8(%rsi), %rdi
	call	atoi@PLT
	cmpl	$134217728, %eax
	cmovle	%eax, %r12d
.L3:
	leaq	y(%rip), %rdx
	leaq	x(%rip), %rcx
	xorl	%eax, %eax
	movsd	a(%rip), %xmm1
	movsd	.LC1(%rip), %xmm2
.L4:
	cmpl	%eax, %r12d
	jle	.L12
	cvtsi2sdl	%eax, %xmm0
	movapd	%xmm1, %xmm3
	mulsd	%xmm2, %xmm0
	subsd	%xmm0, %xmm3
	addsd	%xmm1, %xmm0
	movsd	%xmm3, (%rdx,%rax,8)
	movsd	%xmm0, (%rcx,%rax,8)
	incq	%rax
	jmp	.L4
.L12:
	leaq	8(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movsd	a(%rip), %xmm1
	xorl	%eax, %eax
	leaq	y(%rip), %rdx
	leaq	x(%rip), %rcx
.L6:
	cmpl	%eax, %r12d
	jle	.L13
	movsd	(%rcx,%rax,8), %xmm0
	mulsd	%xmm1, %xmm0
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	incq	%rax
	jmp	.L6
.L13:
	xorl	%edi, %edi
	leaq	24(%rsp), %rsi
	call	clock_gettime@PLT
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	movl	%r12d, %edx
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movb	$1, %al
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	addq	$48, %rsp
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.long	3862034593
	.long	1086856406
	.comm	y,1073741824,32
	.comm	x,1073741824,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	1951633139
	.long	1069520676
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
