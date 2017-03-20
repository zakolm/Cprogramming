	.file	"main.c"
	.globl	global_int
	.data
	.align 4
global_int:
	.long	10
	.comm	global_not_int, 4, 2
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Input large base: \0"
.LC1:
	.ascii "%f\0"
.LC2:
	.ascii "Input less base: \0"
.LC3:
	.ascii "Input angle: \0"
.LC8:
	.ascii "Square = %7.4f\0"
.LC9:
	.ascii "Test %d %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	movaps	%xmm6, -16(%rbp)
	.seh_savexmm	%xmm6, 64
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	-28(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	-24(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movss	-32(%rbp), %xmm0
	movss	-28(%rbp), %xmm1
	subss	%xmm1, %xmm0
	movss	.LC4(%rip), %xmm1
	andps	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC5(%rip), %xmm1
	movapd	%xmm0, %xmm6
	divsd	%xmm1, %xmm6
	movss	-24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC6(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	call	sin
	mulsd	%xmm0, %xmm6
	movss	-24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC6(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	call	cos
	divsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -20(%rbp)
	cvtss2sd	-20(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rcx
	call	printf
	leaq	global_not_int(%rip), %rax
	movl	$11, (%rax)
	leaq	global_not_int(%rip), %rax
	movl	(%rax), %edx
	movl	global_int(%rip), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC9(%rip), %rcx
	call	printf
	movl	$0, %eax
	movaps	-16(%rbp), %xmm6
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 16
.LC4:
	.long	2147483647
	.long	0
	.long	0
	.long	0
	.align 8
.LC5:
	.long	0
	.long	1073741824
	.align 8
.LC6:
	.long	1413754136
	.long	1074340347
	.align 8
.LC7:
	.long	0
	.long	1080459264
	.ident	"GCC: (Rev1, Built by MSYS2 project) 6.3.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	sin;	.scl	2;	.type	32;	.endef
	.def	cos;	.scl	2;	.type	32;	.endef
