	.file	"daxpy.c"
	.text
	.comm	x,1073741824,32
	.comm	y,1073741824,32
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.long	3862034593
	.long	1086856406
	.section	.rodata
	.align 8
.LC0:
	.string	"NUMERO DE PARAMETROS INTRODUCIDOS INCORRECTO"
	.align 8
.LC3:
	.string	"\n>> TIEMPO DE EJECUCION: %11.9f | DIMENSION: %d\n"
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
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -84(%rbp)
	je	.L2
	cmpl	$1, -84(%rbp)
	je	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	cmpl	$2, -84(%rbp)
	jne	.L3
	movq	-96(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -68(%rbp)
	cmpl	$134217728, -68(%rbp)
	jle	.L3
	movl	$134217728, -68(%rbp)
.L3:
	cmpl	$1, -84(%rbp)
	jne	.L4
	movl	$134217728, -68(%rbp)
.L4:
	movl	$0, -64(%rbp)
	jmp	.L5
.L6:
	movsd	a(%rip), %xmm0
	cvtsi2sdl	-64(%rbp), %xmm2
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm2, %xmm1
	subsd	%xmm1, %xmm0
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	y(%rip), %rax
	movsd	%xmm0, (%rdx,%rax)
	cvtsi2sdl	-64(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	a(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	x(%rip), %rax
	movsd	%xmm0, (%rdx,%rax)
	addl	$1, -64(%rbp)
.L5:
	movl	-64(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L6
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movl	$0, -60(%rbp)
	jmp	.L7
.L8:
	movl	-60(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	x(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movsd	a(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movl	-60(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	y(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	addsd	%xmm1, %xmm0
	movl	-60(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	y(%rip), %rax
	movsd	%xmm0, (%rdx,%rax)
	addl	$1, -60(%rbp)
.L7:
	movl	-60(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L8
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	-32(%rbp), %rdx
	movq	-48(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-24(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC2(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	movl	-68(%rbp), %edx
	movq	-56(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
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
