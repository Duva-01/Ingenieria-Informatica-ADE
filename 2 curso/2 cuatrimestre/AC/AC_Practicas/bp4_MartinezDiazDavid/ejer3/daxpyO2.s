	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"NUMERO DE PARAMETROS INTRODUCIDOS INCORRECTO"
	.align 8
.LC3:
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
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leal	-1(%rdi), %eax
	cmpl	$1, %eax
	ja	.L15
	movl	$134217728, %r12d
	cmpl	$2, %edi
	je	.L16
.L3:
	xorl	%eax, %eax
	movsd	a(%rip), %xmm1
	movsd	.LC1(%rip), %xmm3
	leaq	y(%rip), %rcx
	leaq	x(%rip), %rdx
	.p2align 4,,10
	.p2align 3
.L5:
	pxor	%xmm0, %xmm0
	movapd	%xmm1, %xmm2
	cvtsi2sdl	%eax, %xmm0
	mulsd	%xmm3, %xmm0
	subsd	%xmm0, %xmm2
	addsd	%xmm1, %xmm0
	movsd	%xmm2, (%rcx,%rax,8)
	movsd	%xmm0, (%rdx,%rax,8)
	addq	$1, %rax
	cmpl	%eax, %r12d
	jg	.L5
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	leaq	x(%rip), %rdx
	leal	-1(%r12), %ecx
	movsd	a(%rip), %xmm1
	leaq	8(%rdx), %rsi
	leaq	y(%rip), %rax
	leaq	(%rsi,%rcx,8), %rcx
	.p2align 4,,10
	.p2align 3
.L6:
	movsd	(%rdx), %xmm0
	addq	$8, %rdx
	addq	$8, %rax
	mulsd	%xmm1, %xmm0
	addsd	-8(%rax), %xmm0
	movsd	%xmm0, -8(%rax)
	cmpq	%rcx, %rdx
	jne	.L6
.L7:
	xorl	%edi, %edi
	leaq	16(%rsp), %rsi
	call	clock_gettime@PLT
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	movl	%r12d, %edx
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	movl	$1, %edi
	leaq	.LC3(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L17
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L16:
	.cfi_restore_state
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol@PLT
	cmpl	$134217728, %eax
	cmovle	%eax, %r12d
	testl	%eax, %eax
	jg	.L3
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	jmp	.L7
.L15:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L17:
	call	__stack_chk_fail@PLT
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
