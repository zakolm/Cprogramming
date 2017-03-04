	.file	"main.c"
	.intel_syntax noprefix
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
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 80
	.seh_stackalloc	80
	movaps	XMMWORD PTR -16[rbp], xmm6
	.seh_savexmm	xmm6, 64
	.seh_endprologue
	call	__main
	lea	rcx, .LC0[rip]
	call	printf
	lea	rax, -32[rbp]
	mov	rdx, rax
	lea	rcx, .LC1[rip]
	call	scanf
	lea	rcx, .LC2[rip]
	call	printf
	lea	rax, -28[rbp]
	mov	rdx, rax
	lea	rcx, .LC1[rip]
	call	scanf
	lea	rcx, .LC3[rip]
	call	printf
	lea	rax, -24[rbp]
	mov	rdx, rax
	lea	rcx, .LC1[rip]
	call	scanf
	movss	xmm0, DWORD PTR -32[rbp]
	movss	xmm1, DWORD PTR -28[rbp]
	subss	xmm0, xmm1
	movss	xmm1, DWORD PTR .LC4[rip]
	andps	xmm0, xmm1
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC5[rip]
	movapd	xmm6, xmm0
	divsd	xmm6, xmm1
	movss	xmm0, DWORD PTR -24[rbp]
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC6[rip]
	mulsd	xmm0, xmm1
	movsd	xmm1, QWORD PTR .LC7[rip]
	divsd	xmm0, xmm1
	call	sin
	mulsd	xmm6, xmm0
	movss	xmm0, DWORD PTR -24[rbp]
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC6[rip]
	mulsd	xmm0, xmm1
	movsd	xmm1, QWORD PTR .LC7[rip]
	divsd	xmm0, xmm1
	call	cos
	divsd	xmm6, xmm0
	movapd	xmm0, xmm6
	cvtsd2ss	xmm2, xmm0
	movss	DWORD PTR -20[rbp], xmm2
	cvtss2sd	xmm0, DWORD PTR -20[rbp]
	movq	rax, xmm0
	mov	rdx, rax
	mov	QWORD PTR -40[rbp], rdx
	movsd	xmm0, QWORD PTR -40[rbp]
	movapd	xmm1, xmm0
	mov	rdx, rax
	lea	rcx, .LC8[rip]
	call	printf
	mov	eax, 0
	movaps	xmm6, XMMWORD PTR -16[rbp]
	add	rsp, 80
	pop	rbp
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
