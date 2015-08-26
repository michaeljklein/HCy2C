	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_counter
	.align	4, 0x90
_counter:                               ## @counter
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rax
	shrq	$32, %rax
	movl	%edi, %ecx
	shrl	%ecx
	andl	$1431655765, %ecx       ## imm = 0x55555555
	movl	%edi, %edx
	subl	%ecx, %edx
	shrq	$33, %rdi
	andl	$1431655765, %edi       ## imm = 0x55555555
	subl	%edi, %eax
	movl	%edx, %ecx
	andl	$858993459, %ecx        ## imm = 0x33333333
	shrl	$2, %edx
	andl	$858993459, %edx        ## imm = 0x33333333
	addl	%ecx, %edx
	movl	%eax, %ecx
	andl	$858993459, %ecx        ## imm = 0x33333333
	shrl	$2, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	addl	%ecx, %eax
	movl	%edx, %ecx
	shrl	$4, %ecx
	addl	%edx, %ecx
	andl	$252645135, %ecx        ## imm = 0xF0F0F0F
	movl	%eax, %edx
	shrl	$4, %edx
	addl	%eax, %edx
	andl	$252645135, %edx        ## imm = 0xF0F0F0F
	addl	%ecx, %edx
	imull	$16843009, %edx, %eax   ## imm = 0x1010101
	shrl	$24, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_f
	.align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
                                        ## kill: EDI<def> EDI<kill> RDI<def>
	movl	%esi, %eax
	negl	%eax
	sbbq	%rax, %rax
	movq	_y@GOTPCREL(%rip), %rcx
	movq	%rax, (%rcx)
	leal	-1(%rdi), %ecx
	movslq	%ecx, %rcx
	leaq	_A(%rip), %r8
	notq	%rax
	movslq	%edi, %rdi
	leaq	_C(%rip), %rdx
	orq	(%rdx,%rdi,8), %rax
	andq	(%r8,%rcx,8), %rax
	leaq	_D(%rip), %rcx
	cmpl	$1, %esi
	sbbq	%rdx, %rdx
	notq	%rdx
	orq	(%rcx,%rdi,8), %rdx
	andq	%rax, %rdx
	movq	%rdx, (%r8,%rdi,8)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_checkifbest
	.align	4, 0x90
_checkifbest:                           ## @checkifbest
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	movq	_A+40(%rip), %rcx
	movq	%rcx, %rax
	shrq	$32, %rax
	movl	%ecx, %edx
	shrl	%edx
	andl	$1431655765, %edx       ## imm = 0x55555555
	movl	%ecx, %esi
	subl	%edx, %esi
	shrq	$33, %rcx
	andl	$1431655765, %ecx       ## imm = 0x55555555
	subl	%ecx, %eax
	movl	%esi, %ecx
	andl	$858993459, %ecx        ## imm = 0x33333333
	shrl	$2, %esi
	andl	$858993459, %esi        ## imm = 0x33333333
	addl	%ecx, %esi
	movl	%eax, %ecx
	andl	$858993459, %ecx        ## imm = 0x33333333
	shrl	$2, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	addl	%ecx, %eax
	movl	%esi, %ecx
	shrl	$4, %ecx
	addl	%esi, %ecx
	andl	$252645135, %ecx        ## imm = 0xF0F0F0F
	movl	%eax, %edx
	shrl	$4, %edx
	addl	%eax, %edx
	andl	$252645135, %edx        ## imm = 0xF0F0F0F
	addl	%ecx, %edx
	imull	$16843009, %edx, %eax   ## imm = 0x1010101
	shrl	$24, %eax
	movq	_this@GOTPCREL(%rip), %rcx
	movl	%eax, (%rcx)
	cmpl	_best(%rip), %eax
	jbe	LBB2_2
## BB#1:
	movl	%eax, _best(%rip)
LBB2_2:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_r
	.align	4, 0x90
_r:                                     ## @r
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
Ltmp12:
	.cfi_offset %rbx, -56
Ltmp13:
	.cfi_offset %r12, -48
Ltmp14:
	.cfi_offset %r13, -40
Ltmp15:
	.cfi_offset %r14, -32
Ltmp16:
	.cfi_offset %r15, -24
	movq	_i@GOTPCREL(%rip), %r15
	movl	(%r15), %edx
	leaq	_X(%rip), %rcx
	movq	_y@GOTPCREL(%rip), %r14
	movq	_this@GOTPCREL(%rip), %r9
	leaq	_A(%rip), %r12
	leaq	_C(%rip), %r11
	leaq	_D(%rip), %r10
	jmp	LBB3_1
	.align	4, 0x90
LBB3_15:                                ## %.backedge
                                        ##   in Loop: Header=BB3_1 Depth=1
	incl	%edx
	movl	%edx, (%r15)
LBB3_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB3_10 Depth 2
	movl	%edx, %edi
	movl	(%rcx,%rdi,4), %eax
	cmpl	$5, %edx
	jne	LBB3_14
## BB#2:                                ##   in Loop: Header=BB3_1 Depth=1
	testl	%eax, %eax
	je	LBB3_4
## BB#3:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	$0, (%rcx,%rdi,4)
	decl	%edx
	movl	%edx, %ebx
	jmp	LBB3_9
	.align	4, 0x90
LBB3_14:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	%eax, %esi
	negl	%esi
	sbbq	%rsi, %rsi
	movq	%rsi, (%r14)
	leal	-1(%rdx), %edi
	movslq	%edi, %rdi
	notq	%rsi
	movslq	%edx, %rbx
	orq	(%r11,%rbx,8), %rsi
	andq	(%r12,%rdi,8), %rsi
	cmpl	$1, %eax
	sbbq	%rax, %rax
	notq	%rax
	orq	(%r10,%rbx,8), %rax
	andq	%rsi, %rax
	movq	%rax, (%r12,%rbx,8)
	jmp	LBB3_15
LBB3_4:                                 ##   in Loop: Header=BB3_1 Depth=1
	movq	$0, (%r14)
	movq	_A+32(%rip), %rax
	movl	$5111, %esi             ## imm = 0x13F7
	andq	%rsi, %rax
	movq	%rax, _A+40(%rip)
	movl	%eax, %ebx
	shrl	%ebx
	andl	$337, %ebx              ## imm = 0x151
	subl	%ebx, %eax
	movl	%eax, %ebx
	andl	$858993459, %ebx        ## imm = 0x33333333
	shrl	$2, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	addl	%ebx, %eax
	movl	%eax, %ebx
	shrl	$4, %ebx
	addl	%eax, %ebx
	andl	$252645135, %ebx        ## imm = 0xF0F0F0F
	imull	 $16843009, %ebx        ## imm = 0x1010101
	shrl	$24, %ebx
	movl	%ebx, (%r9)
	movl	_best(%rip), %r13d
	cmpl	%r13d, %ebx
	jbe	LBB3_6
## BB#5:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	%ebx, _best(%rip)
	movl	%ebx, %r13d
LBB3_6:                                 ## %checkifbest.exit1
                                        ##   in Loop: Header=BB3_1 Depth=1
	movl	$1, (%rcx,%rdi,4)
	movq	$-1, (%r14)
	leal	-1(%rdx), %ebx
	movslq	%ebx, %rsi
	movslq	%edx, %rdx
	movq	(%r11,%rdx,8), %rax
	andq	(%r12,%rsi,8), %rax
	movq	%rax, (%r12,%rdx,8)
	movq	_A+40(%rip), %rax
	movq	%rax, %rdx
	shrq	$32, %rdx
	movl	%eax, %esi
	shrl	%esi
	andl	$1431655765, %esi       ## imm = 0x55555555
	movl	%eax, %r8d
	subl	%esi, %r8d
	shrq	$33, %rax
	andl	$1431655765, %eax       ## imm = 0x55555555
	subl	%eax, %edx
	movl	%r8d, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	shrl	$2, %r8d
	andl	$858993459, %r8d        ## imm = 0x33333333
	addl	%eax, %r8d
	movl	%edx, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	shrl	$2, %edx
	andl	$858993459, %edx        ## imm = 0x33333333
	addl	%eax, %edx
	movl	%r8d, %eax
	shrl	$4, %eax
	addl	%r8d, %eax
	andl	$252645135, %eax        ## imm = 0xF0F0F0F
	movl	%edx, %esi
	shrl	$4, %esi
	addl	%edx, %esi
	andl	$252645135, %esi        ## imm = 0xF0F0F0F
	addl	%eax, %esi
	imull	$16843009, %esi, %edx   ## imm = 0x1010101
	shrl	$24, %edx
	movl	%edx, (%r9)
	cmpl	%r13d, %edx
	jbe	LBB3_8
## BB#7:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	%edx, _best(%rip)
LBB3_8:                                 ## %checkifbest.exit
                                        ##   in Loop: Header=BB3_1 Depth=1
	movl	$0, (%rcx,%rdi,4)
LBB3_9:                                 ## %.preheader
                                        ##   in Loop: Header=BB3_1 Depth=1
	movl	%ebx, (%r15)
	movl	%ebx, %edx
	leaq	(%rcx,%rdx,4), %rax
	cmpl	$0, (%rcx,%rdx,4)
	je	LBB3_12
	.align	4, 0x90
LBB3_10:                                ## %.lr.ph
                                        ##   Parent Loop BB3_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	$0, (%rax)
	decl	%ebx
	leaq	(%rcx,%rbx,4), %rax
	cmpl	$0, (%rcx,%rbx,4)
	jne	LBB3_10
## BB#11:                               ## %._crit_edge
                                        ##   in Loop: Header=BB3_1 Depth=1
	movl	%ebx, (%r15)
LBB3_12:                                ##   in Loop: Header=BB3_1 Depth=1
	cmpl	$1, %ebx
	je	LBB3_16
## BB#13:                               ##   in Loop: Header=BB3_1 Depth=1
	movl	$1, (%rax)
	movslq	(%r15), %rdx
	movq	$-1, (%r14)
	leal	-1(%rdx), %eax
	cltq
	movq	(%r11,%rdx,8), %rsi
	andq	(%r12,%rax,8), %rsi
	movq	%rsi, (%r12,%rdx,8)
	jmp	LBB3_15
LBB3_16:
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp17:
	.cfi_def_cfa_offset 16
Ltmp18:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp19:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
Ltmp20:
	.cfi_offset %rbx, -24
	rdtsc
	movq	%rdx, %rbx
	shlq	$32, %rbx
	orq	%rax, %rbx
	movq	_i@GOTPCREL(%rip), %rax
	movl	$1, (%rax)
	callq	_r
	rdtsc
	shlq	$32, %rdx
	orq	%rax, %rdx
	subq	%rbx, %rdx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rdx, %rsi
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_best                   ## @best
	.align	2
_best:
	.long	1                       ## 0x1

	.globl	_starthere              ## @starthere
.zerofill __DATA,__common,_starthere,4,2
	.globl	_str                    ## @str
.zerofill __DATA,__common,_str,16,4
	.globl	_X                      ## @X
.zerofill __DATA,__common,_X,24,4
	.globl	_A                      ## @A
	.align	4
_A:
	.quad	13935                   ## 0x366f
	.quad	16383                   ## 0x3fff
	.quad	16383                   ## 0x3fff
	.quad	16383                   ## 0x3fff
	.quad	16383                   ## 0x3fff
	.quad	16383                   ## 0x3fff

	.comm	_y,8,3                  ## @y
	.section	__TEXT,__const
	.align	4                       ## @C
_C:
	.quad	16368                   ## 0x3ff0
	.quad	16143                   ## 0x3f0f
	.quad	12543                   ## 0x30ff
	.quad	11772                   ## 0x2dfc
	.quad	8147                    ## 0x1fd3
	.quad	12093                   ## 0x2f3d

	.align	4                       ## @D
_D:
	.quad	13935                   ## 0x366f
	.quad	14838                   ## 0x39f6
	.quad	16281                   ## 0x3f99
	.quad	6095                    ## 0x17cf
	.quad	11391                   ## 0x2c7f
	.quad	5111                    ## 0x13f7

	.comm	_this,4,2               ## @this
	.comm	_i,4,2                  ## @i
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%llu\n"

	.comm	_fout,8,3               ## @fout

.subsections_via_symbols
