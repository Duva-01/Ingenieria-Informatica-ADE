	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"NUMERO DE PARAMETROS INTRODUCIDOS INCORRECTO"
	.align 8
.LC6:
	.string	"\n>> TIEMPO DE EJECUCION: %11.9f | DIMENSION: %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$48, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leal	-1(%rdi), %eax
	cmpl	$1, %eax
	ja	.L26
	cmpl	$2, %edi
	je	.L27
	movsd	a(%rip), %xmm6
	movl	$134217728, %esi
	movl	$134217728, %r12d
.L6:
	movl	%esi, %ecx
	leaq	y(%rip), %rbx
	movapd	%xmm6, %xmm2
	movdqa	.LC0(%rip), %xmm3
	shrl	$2, %ecx
	unpcklpd	%xmm2, %xmm2
	movq	%rbx, %rax
	movdqa	.LC2(%rip), %xmm7
	leaq	x(%rip), %rbp
	salq	$5, %rcx
	movapd	.LC3(%rip), %xmm4
	movq	%rbp, %rdx
	addq	%rbx, %rcx
	.p2align 4,,10
	.p2align 3
.L8:
	movdqa	%xmm3, %xmm0
	movapd	%xmm2, %xmm5
	addq	$32, %rax
	addq	$32, %rdx
	cvtdq2pd	%xmm0, %xmm1
	mulpd	%xmm4, %xmm1
	pshufd	$238, %xmm0, %xmm0
	paddd	%xmm7, %xmm3
	cvtdq2pd	%xmm0, %xmm0
	mulpd	%xmm4, %xmm0
	subpd	%xmm1, %xmm5
	addpd	%xmm2, %xmm1
	movaps	%xmm5, -32(%rax)
	movapd	%xmm2, %xmm5
	subpd	%xmm0, %xmm5
	addpd	%xmm2, %xmm0
	movaps	%xmm5, -16(%rax)
	movaps	%xmm1, -32(%rdx)
	movaps	%xmm0, -16(%rdx)
	cmpq	%rcx, %rax
	jne	.L8
	movl	%esi, %eax
	andl	$-4, %eax
	andl	$3, %esi
	je	.L9
.L7:
	pxor	%xmm0, %xmm0
	movsd	.LC4(%rip), %xmm1
	movapd	%xmm6, %xmm2
	movslq	%eax, %rdx
	cvtsi2sdl	%eax, %xmm0
	mulsd	%xmm1, %xmm0
	subsd	%xmm0, %xmm2
	addsd	%xmm6, %xmm0
	movsd	%xmm2, (%rbx,%rdx,8)
	movsd	%xmm0, 0(%rbp,%rdx,8)
	leal	1(%rax), %edx
	cmpl	%r12d, %edx
	jge	.L9
	pxor	%xmm0, %xmm0
	movapd	%xmm6, %xmm2
	addl	$2, %eax
	cvtsi2sdl	%edx, %xmm0
	movslq	%edx, %rdx
	mulsd	%xmm1, %xmm0
	subsd	%xmm0, %xmm2
	addsd	%xmm6, %xmm0
	movsd	%xmm2, (%rbx,%rdx,8)
	movsd	%xmm0, 0(%rbp,%rdx,8)
	cmpl	%r12d, %eax
	jge	.L10
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	cltq
	mulsd	%xmm1, %xmm0
	movapd	%xmm6, %xmm1
	subsd	%xmm0, %xmm1
	addsd	%xmm0, %xmm6
	movsd	%xmm1, (%rbx,%rax,8)
	movsd	%xmm6, 0(%rbp,%rax,8)
.L10:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movsd	a(%rip), %xmm0
.L15:
	movl	%r12d, %ecx
	movapd	%xmm0, %xmm2
	leaq	x(%rip), %rdx
	shrl	%ecx
	unpcklpd	%xmm2, %xmm2
	leaq	y(%rip), %rax
	salq	$4, %rcx
	addq	%rbp, %rcx
	.p2align 4,,10
	.p2align 3
.L11:
	movapd	(%rdx), %xmm1
	addq	$16, %rdx
	addq	$16, %rax
	mulpd	%xmm2, %xmm1
	addpd	-16(%rax), %xmm1
	movaps	%xmm1, -16(%rax)
	cmpq	%rcx, %rdx
	jne	.L11
	movl	%r12d, %eax
	andl	$-2, %eax
	testb	$1, %r12b
	je	.L13
.L16:
	cltq
	mulsd	0(%rbp,%rax,8), %xmm0
	addsd	(%rbx,%rax,8), %xmm0
	movsd	%xmm0, (%rbx,%rax,8)
.L13:
	xorl	%edi, %edi
	leaq	16(%rsp), %rsi
	call	clock_gettime@PLT
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	movl	%r12d, %edx
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	movl	$1, %edi
	leaq	.LC6(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	divsd	.LC5(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L28
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L27:
	.cfi_restore_state
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movl	$134217728, %r12d
	call	strtol@PLT
	cmpl	$134217728, %eax
	cmovle	%eax, %r12d
	testl	%eax, %eax
	jle	.L29
	movsd	a(%rip), %xmm6
	movl	%r12d, %esi
	cmpl	$3, %eax
	jg	.L6
	xorl	%eax, %eax
	leaq	y(%rip), %rbx
	leaq	x(%rip), %rbp
	jmp	.L7
.L9:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movsd	a(%rip), %xmm0
	cmpl	$1, %r12d
	jne	.L15
	xorl	%eax, %eax
	jmp	.L16
.L29:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	jmp	.L13
.L28:
	call	__stack_chk_fail@PLT
.L26:
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE39:
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC3:
	.long	1951633139
	.long	1069520676
	.long	1951633139
	.long	1069520676
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC4:
	.long	1951633139
	.long	1069520676
	.align 8
.LC5:
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
