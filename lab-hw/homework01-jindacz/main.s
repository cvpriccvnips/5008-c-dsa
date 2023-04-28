	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 1
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.file	1 "/Users/megami-sama/Documents/CS-entertaining-plays-tracker/ current-tracker/1-cs5008/hw/homework01-jindacz" "main.c"
	.loc	1 5 0                           ## main.c:5:0
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	xorl	%ebx, %ebx
Ltmp0:
	.loc	1 6 11 prologue_end             ## main.c:6:11
	xorl	%edi, %edi
	callq	_time
Ltmp1:
	.loc	1 6 5 is_stmt 0                 ## main.c:6:5
	movl	%eax, %edi
	callq	_srand
Ltmp2:
	##DEBUG_VALUE: guess <- 0
	##DEBUG_VALUE: main:i <- undef
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	##DEBUG_VALUE: main:numOfRounds <- 1
	.loc	1 13 13 is_stmt 1               ## main.c:13:13
	movl	$0, -44(%rbp)
Ltmp3:
	##DEBUG_VALUE: count <- 0
	.loc	1 16 9                          ## main.c:16:9
	leaq	L_str.14(%rip), %r14
	movq	%r14, %rdi
	callq	_puts
Ltmp4:
	.loc	1 17 9                          ## main.c:17:9
	leaq	L_str.13(%rip), %rdi
	callq	_puts
Ltmp5:
	.loc	1 18 9                          ## main.c:18:9
	movq	%r14, %rdi
	callq	_puts
Ltmp6:
	.loc	1 20 22                         ## main.c:20:22
	callq	_rand
Ltmp7:
	.loc	1 20 29 is_stmt 0               ## main.c:20:29
	movslq	%eax, %r13
	imulq	$1717986919, %r13, %rax         ## imm = 0x66666667
	movq	%rax, %rcx
	shrq	$63, %rcx
	sarq	$34, %rax
	addl	%ecx, %eax
	addl	%eax, %eax
	leal	(%rax,%rax,4), %eax
	subl	%eax, %r13d
	.loc	1 20 34                         ## main.c:20:34
	movl	%r13d, %r14d
	incl	%r14d
Ltmp8:
	##DEBUG_VALUE: target <- $r14d
	.loc	1 22 9 is_stmt 1                ## main.c:22:9
	jne	LBB0_1
Ltmp9:
LBB0_6:
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	.loc	1 32 9                          ## main.c:32:9
	leaq	L_str.15(%rip), %rdi
	callq	_puts
Ltmp10:
	##DEBUG_VALUE: main:i <- undef
	.loc	1 36 5                          ## main.c:36:5
	leaq	L_str.11(%rip), %r14
Ltmp11:
	movq	%r14, %rdi
	callq	_puts
Ltmp12:
	.loc	1 37 5                          ## main.c:37:5
	leaq	L_str.10(%rip), %rdi
	callq	_puts
Ltmp13:
	.loc	1 38 5                          ## main.c:38:5
	movq	%r14, %rdi
	callq	_puts
Ltmp14:
	.loc	1 41 9                          ## main.c:41:9
	leaq	L_.str.9(%rip), %rdi
	xorl	%esi, %esi
	movl	%ebx, %edx
	xorl	%eax, %eax
	callq	_printf
Ltmp15:
	.loc	1 44 1                          ## main.c:44:1
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
Ltmp16:
LBB0_1:
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: count <- 0
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	##DEBUG_VALUE: guess <- 0
	.loc	1 0 1 is_stmt 0                 ## main.c:0:1
	leaq	-44(%rbp), %r12
	leaq	L_str.17(%rip), %r15
	xorl	%ebx, %ebx
	jmp	LBB0_2
Ltmp17:
	.p2align	4, 0x90
LBB0_4:                                 ##   in Loop: Header=BB0_2 Depth=1
	##DEBUG_VALUE: guess <- $eax
	##DEBUG_VALUE: count <- $ebx
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	callq	_puts
Ltmp18:
LBB0_5:                                 ##   in Loop: Header=BB0_2 Depth=1
	##DEBUG_VALUE: count <- $ebx
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	##DEBUG_VALUE: guess <- undef
	.loc	1 25 19 is_stmt 1               ## main.c:25:19
	addl	$1, %ebx
Ltmp19:
	##DEBUG_VALUE: count <- $ebx
	.loc	1 22 22                         ## main.c:22:22
	cmpl	%r14d, -44(%rbp)
	.loc	1 22 9 is_stmt 0                ## main.c:22:9
	je	LBB0_6
Ltmp20:
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	##DEBUG_VALUE: count <- $ebx
	.loc	1 23 13 is_stmt 1               ## main.c:23:13
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
Ltmp21:
	##DEBUG_VALUE: guess <- [DW_OP_constu 44, DW_OP_minus, DW_OP_deref] $rbp
	.loc	1 24 13                         ## main.c:24:13
	leaq	L_.str.3(%rip), %rdi
	movq	%r12, %rsi
	xorl	%eax, %eax
	callq	_scanf
Ltmp22:
	.loc	1 26 18                         ## main.c:26:18
	movl	-44(%rbp), %eax
Ltmp23:
	##DEBUG_VALUE: guess <- $eax
	.loc	1 0 18 is_stmt 0                ## main.c:0:18
	movq	%r15, %rdi
	.loc	1 26 24                         ## main.c:26:24
	cmpl	%r13d, %eax
Ltmp24:
	.loc	1 26 18                         ## main.c:26:18
	jle	LBB0_4
Ltmp25:
## %bb.3:                               ##   in Loop: Header=BB0_2 Depth=1
	##DEBUG_VALUE: guess <- $eax
	##DEBUG_VALUE: count <- $ebx
	##DEBUG_VALUE: target <- $r14d
	##DEBUG_VALUE: main:numOfRounds <- 1
	##DEBUG_VALUE: main:__vla_expr0 <- 1
	.loc	1 0 18                          ## main.c:0:18
	leaq	L_str.16(%rip), %rdi
Ltmp26:
	.loc	1 28 31 is_stmt 1               ## main.c:28:31
	cmpl	%r14d, %eax
Ltmp27:
	.loc	1 28 25 is_stmt 0               ## main.c:28:25
	jg	LBB0_4
	jmp	LBB0_5
Ltmp28:
Lfunc_end0:
	.cfi_endproc
	.file	2 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include" "time.h"
	.file	3 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386" "_types.h"
	.file	4 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types" "_time_t.h"
	.file	5 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include" "stdlib.h"
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"Make a guess:"

L_.str.3:                               ## @.str.3
	.asciz	"%d"

L_.str.9:                               ## @.str.9
	.asciz	"Game %d took you %d guesses\n"

L_str.10:                               ## @str.10
	.asciz	"|Here are the results of your guessing abilities|"

L_str.11:                               ## @str.11
	.asciz	"================================================="

L_str.13:                               ## @str.13
	.asciz	"CPU Says: Pick a number 1-10"

L_str.14:                               ## @str.14
	.asciz	"=========================="

L_str.15:                               ## @str.15
	.asciz	"You got it!"

L_str.16:                               ## @str.16
	.asciz	"No guess lower!"

L_str.17:                               ## @str.17
	.asciz	"No guess higher!"

	.section	__DWARF,__debug_loc,regular,debug
Lsection_debug_loc:
Ldebug_loc0:
.set Lset0, Ltmp2-Lfunc_begin0
	.quad	Lset0
.set Lset1, Ltmp9-Lfunc_begin0
	.quad	Lset1
	.short	3                               ## Loc expr size
	.byte	17                              ## DW_OP_consts
	.byte	0                               ## 0
	.byte	159                             ## DW_OP_stack_value
.set Lset2, Ltmp17-Lfunc_begin0
	.quad	Lset2
.set Lset3, Ltmp18-Lfunc_begin0
	.quad	Lset3
	.short	1                               ## Loc expr size
	.byte	80                              ## super-register DW_OP_reg0
.set Lset4, Ltmp21-Lfunc_begin0
	.quad	Lset4
.set Lset5, Ltmp23-Lfunc_begin0
	.quad	Lset5
	.short	2                               ## Loc expr size
	.byte	118                             ## DW_OP_breg6
	.byte	84                              ## -44
.set Lset6, Ltmp23-Lfunc_begin0
	.quad	Lset6
.set Lset7, Lfunc_end0-Lfunc_begin0
	.quad	Lset7
	.short	1                               ## Loc expr size
	.byte	80                              ## super-register DW_OP_reg0
	.quad	0
	.quad	0
Ldebug_loc1:
.set Lset8, Ltmp2-Lfunc_begin0
	.quad	Lset8
.set Lset9, Lfunc_end0-Lfunc_begin0
	.quad	Lset9
	.short	2                               ## Loc expr size
	.byte	49                              ## DW_OP_lit1
	.byte	159                             ## DW_OP_stack_value
	.quad	0
	.quad	0
Ldebug_loc2:
.set Lset10, Ltmp2-Lfunc_begin0
	.quad	Lset10
.set Lset11, Lfunc_end0-Lfunc_begin0
	.quad	Lset11
	.short	3                               ## Loc expr size
	.byte	17                              ## DW_OP_consts
	.byte	1                               ## 1
	.byte	159                             ## DW_OP_stack_value
	.quad	0
	.quad	0
Ldebug_loc3:
.set Lset12, Ltmp3-Lfunc_begin0
	.quad	Lset12
.set Lset13, Ltmp9-Lfunc_begin0
	.quad	Lset13
	.short	3                               ## Loc expr size
	.byte	17                              ## DW_OP_consts
	.byte	0                               ## 0
	.byte	159                             ## DW_OP_stack_value
.set Lset14, Ltmp17-Lfunc_begin0
	.quad	Lset14
.set Lset15, Lfunc_end0-Lfunc_begin0
	.quad	Lset15
	.short	1                               ## Loc expr size
	.byte	83                              ## super-register DW_OP_reg3
	.quad	0
	.quad	0
Ldebug_loc4:
.set Lset16, Ltmp8-Lfunc_begin0
	.quad	Lset16
.set Lset17, Ltmp11-Lfunc_begin0
	.quad	Lset17
	.short	1                               ## Loc expr size
	.byte	94                              ## super-register DW_OP_reg14
.set Lset18, Ltmp17-Lfunc_begin0
	.quad	Lset18
.set Lset19, Lfunc_end0-Lfunc_begin0
	.quad	Lset19
	.short	1                               ## Loc expr size
	.byte	94                              ## super-register DW_OP_reg14
	.quad	0
	.quad	0
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                               ## Abbreviation Code
	.byte	17                              ## DW_TAG_compile_unit
	.byte	1                               ## DW_CHILDREN_yes
	.byte	37                              ## DW_AT_producer
	.byte	14                              ## DW_FORM_strp
	.byte	19                              ## DW_AT_language
	.byte	5                               ## DW_FORM_data2
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.ascii	"\202|"                         ## DW_AT_LLVM_sysroot
	.byte	14                              ## DW_FORM_strp
	.ascii	"\357\177"                      ## DW_AT_APPLE_sdk
	.byte	14                              ## DW_FORM_strp
	.byte	16                              ## DW_AT_stmt_list
	.byte	23                              ## DW_FORM_sec_offset
	.byte	27                              ## DW_AT_comp_dir
	.byte	14                              ## DW_FORM_strp
	.ascii	"\341\177"                      ## DW_AT_APPLE_optimized
	.byte	25                              ## DW_FORM_flag_present
	.byte	17                              ## DW_AT_low_pc
	.byte	1                               ## DW_FORM_addr
	.byte	18                              ## DW_AT_high_pc
	.byte	6                               ## DW_FORM_data4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	2                               ## Abbreviation Code
	.byte	46                              ## DW_TAG_subprogram
	.byte	1                               ## DW_CHILDREN_yes
	.byte	17                              ## DW_AT_low_pc
	.byte	1                               ## DW_FORM_addr
	.byte	18                              ## DW_AT_high_pc
	.byte	6                               ## DW_FORM_data4
	.byte	64                              ## DW_AT_frame_base
	.byte	24                              ## DW_FORM_exprloc
	.byte	122                             ## DW_AT_call_all_calls
	.byte	25                              ## DW_FORM_flag_present
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	63                              ## DW_AT_external
	.byte	25                              ## DW_FORM_flag_present
	.ascii	"\341\177"                      ## DW_AT_APPLE_optimized
	.byte	25                              ## DW_FORM_flag_present
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	3                               ## Abbreviation Code
	.byte	52                              ## DW_TAG_variable
	.byte	0                               ## DW_CHILDREN_no
	.byte	2                               ## DW_AT_location
	.byte	23                              ## DW_FORM_sec_offset
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	52                              ## DW_AT_artificial
	.byte	25                              ## DW_FORM_flag_present
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	4                               ## Abbreviation Code
	.byte	52                              ## DW_TAG_variable
	.byte	0                               ## DW_CHILDREN_no
	.byte	2                               ## DW_AT_location
	.byte	23                              ## DW_FORM_sec_offset
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	5                               ## Abbreviation Code
	.byte	52                              ## DW_TAG_variable
	.byte	0                               ## DW_CHILDREN_no
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	6                               ## Abbreviation Code
	.byte	11                              ## DW_TAG_lexical_block
	.byte	1                               ## DW_CHILDREN_yes
	.byte	85                              ## DW_AT_ranges
	.byte	23                              ## DW_FORM_sec_offset
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	7                               ## Abbreviation Code
	.byte	72                              ## DW_TAG_call_site
	.byte	1                               ## DW_CHILDREN_yes
	.byte	127                             ## DW_AT_call_origin
	.byte	19                              ## DW_FORM_ref4
	.byte	125                             ## DW_AT_call_return_pc
	.byte	1                               ## DW_FORM_addr
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	8                               ## Abbreviation Code
	.byte	73                              ## DW_TAG_call_site_parameter
	.byte	0                               ## DW_CHILDREN_no
	.byte	2                               ## DW_AT_location
	.byte	24                              ## DW_FORM_exprloc
	.byte	126                             ## DW_AT_call_value
	.byte	24                              ## DW_FORM_exprloc
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	9                               ## Abbreviation Code
	.byte	72                              ## DW_TAG_call_site
	.byte	0                               ## DW_CHILDREN_no
	.byte	127                             ## DW_AT_call_origin
	.byte	19                              ## DW_FORM_ref4
	.byte	125                             ## DW_AT_call_return_pc
	.byte	1                               ## DW_FORM_addr
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	10                              ## Abbreviation Code
	.byte	46                              ## DW_TAG_subprogram
	.byte	1                               ## DW_CHILDREN_yes
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	39                              ## DW_AT_prototyped
	.byte	25                              ## DW_FORM_flag_present
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	60                              ## DW_AT_declaration
	.byte	25                              ## DW_FORM_flag_present
	.byte	63                              ## DW_AT_external
	.byte	25                              ## DW_FORM_flag_present
	.ascii	"\341\177"                      ## DW_AT_APPLE_optimized
	.byte	25                              ## DW_FORM_flag_present
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	11                              ## Abbreviation Code
	.byte	5                               ## DW_TAG_formal_parameter
	.byte	0                               ## DW_CHILDREN_no
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	12                              ## Abbreviation Code
	.byte	22                              ## DW_TAG_typedef
	.byte	0                               ## DW_CHILDREN_no
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	13                              ## Abbreviation Code
	.byte	36                              ## DW_TAG_base_type
	.byte	0                               ## DW_CHILDREN_no
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	62                              ## DW_AT_encoding
	.byte	11                              ## DW_FORM_data1
	.byte	11                              ## DW_AT_byte_size
	.byte	11                              ## DW_FORM_data1
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	14                              ## Abbreviation Code
	.byte	15                              ## DW_TAG_pointer_type
	.byte	0                               ## DW_CHILDREN_no
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	15                              ## Abbreviation Code
	.byte	46                              ## DW_TAG_subprogram
	.byte	1                               ## DW_CHILDREN_yes
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	39                              ## DW_AT_prototyped
	.byte	25                              ## DW_FORM_flag_present
	.byte	60                              ## DW_AT_declaration
	.byte	25                              ## DW_FORM_flag_present
	.byte	63                              ## DW_AT_external
	.byte	25                              ## DW_FORM_flag_present
	.ascii	"\341\177"                      ## DW_AT_APPLE_optimized
	.byte	25                              ## DW_FORM_flag_present
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	16                              ## Abbreviation Code
	.byte	46                              ## DW_TAG_subprogram
	.byte	0                               ## DW_CHILDREN_no
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	58                              ## DW_AT_decl_file
	.byte	11                              ## DW_FORM_data1
	.byte	59                              ## DW_AT_decl_line
	.byte	11                              ## DW_FORM_data1
	.byte	39                              ## DW_AT_prototyped
	.byte	25                              ## DW_FORM_flag_present
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	60                              ## DW_AT_declaration
	.byte	25                              ## DW_FORM_flag_present
	.byte	63                              ## DW_AT_external
	.byte	25                              ## DW_FORM_flag_present
	.ascii	"\341\177"                      ## DW_AT_APPLE_optimized
	.byte	25                              ## DW_FORM_flag_present
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	17                              ## Abbreviation Code
	.byte	1                               ## DW_TAG_array_type
	.byte	1                               ## DW_CHILDREN_yes
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	18                              ## Abbreviation Code
	.byte	33                              ## DW_TAG_subrange_type
	.byte	0                               ## DW_CHILDREN_no
	.byte	73                              ## DW_AT_type
	.byte	19                              ## DW_FORM_ref4
	.byte	55                              ## DW_AT_count
	.byte	19                              ## DW_FORM_ref4
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	19                              ## Abbreviation Code
	.byte	36                              ## DW_TAG_base_type
	.byte	0                               ## DW_CHILDREN_no
	.byte	3                               ## DW_AT_name
	.byte	14                              ## DW_FORM_strp
	.byte	11                              ## DW_AT_byte_size
	.byte	11                              ## DW_FORM_data1
	.byte	62                              ## DW_AT_encoding
	.byte	11                              ## DW_FORM_data1
	.byte	0                               ## EOM(1)
	.byte	0                               ## EOM(2)
	.byte	0                               ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
.set Lset20, Ldebug_info_end0-Ldebug_info_start0 ## Length of Unit
	.long	Lset20
Ldebug_info_start0:
	.short	4                               ## DWARF version number
.set Lset21, Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset21
	.byte	8                               ## Address Size (in bytes)
	.byte	1                               ## Abbrev [1] 0xb:0x14a DW_TAG_compile_unit
	.long	0                               ## DW_AT_producer
	.short	12                              ## DW_AT_language
	.long	49                              ## DW_AT_name
	.long	56                              ## DW_AT_LLVM_sysroot
	.long	151                             ## DW_AT_APPLE_sdk
.set Lset22, Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset22
	.long	162                             ## DW_AT_comp_dir
                                        ## DW_AT_APPLE_optimized
	.quad	Lfunc_begin0                    ## DW_AT_low_pc
.set Lset23, Lfunc_end0-Lfunc_begin0    ## DW_AT_high_pc
	.long	Lset23
	.byte	2                               ## Abbrev [2] 0x32:0xac DW_TAG_subprogram
	.quad	Lfunc_begin0                    ## DW_AT_low_pc
.set Lset24, Lfunc_end0-Lfunc_begin0    ## DW_AT_high_pc
	.long	Lset24
	.byte	1                               ## DW_AT_frame_base
	.byte	86
                                        ## DW_AT_call_all_calls
	.long	269                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	5                               ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
                                        ## DW_AT_external
                                        ## DW_AT_APPLE_optimized
	.byte	3                               ## Abbrev [3] 0x4b:0xd DW_TAG_variable
.set Lset25, Ldebug_loc1-Lsection_debug_loc ## DW_AT_location
	.long	Lset25
	.long	341                             ## DW_AT_name
	.long	311                             ## DW_AT_type
                                        ## DW_AT_artificial
	.byte	4                               ## Abbrev [4] 0x58:0xf DW_TAG_variable
.set Lset26, Ldebug_loc2-Lsection_debug_loc ## DW_AT_location
	.long	Lset26
	.long	367                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	8                               ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
	.byte	5                               ## Abbrev [5] 0x67:0xb DW_TAG_variable
	.long	392                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	9                               ## DW_AT_decl_line
	.long	318                             ## DW_AT_type
	.byte	5                               ## Abbrev [5] 0x72:0xb DW_TAG_variable
	.long	419                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	10                              ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
	.byte	6                               ## Abbrev [6] 0x7d:0x33 DW_TAG_lexical_block
.set Lset27, Ldebug_ranges0-Ldebug_range ## DW_AT_ranges
	.long	Lset27
	.byte	4                               ## Abbrev [4] 0x82:0xf DW_TAG_variable
.set Lset28, Ldebug_loc0-Lsection_debug_loc ## DW_AT_location
	.long	Lset28
	.long	335                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	13                              ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
	.byte	4                               ## Abbrev [4] 0x91:0xf DW_TAG_variable
.set Lset29, Ldebug_loc3-Lsection_debug_loc ## DW_AT_location
	.long	Lset29
	.long	379                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	14                              ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
	.byte	4                               ## Abbrev [4] 0xa0:0xf DW_TAG_variable
.set Lset30, Ldebug_loc4-Lsection_debug_loc ## DW_AT_location
	.long	Lset30
	.long	385                             ## DW_AT_name
	.byte	1                               ## DW_AT_decl_file
	.byte	20                              ## DW_AT_decl_line
	.long	304                             ## DW_AT_type
	.byte	0                               ## End Of Children Mark
	.byte	7                               ## Abbrev [7] 0xb0:0x13 DW_TAG_call_site
	.long	222                             ## DW_AT_call_origin
	.quad	Ltmp1                           ## DW_AT_call_return_pc
	.byte	8                               ## Abbrev [8] 0xbd:0x5 DW_TAG_call_site_parameter
	.byte	1                               ## DW_AT_location
	.byte	85
	.byte	1                               ## DW_AT_call_value
	.byte	48
	.byte	0                               ## End Of Children Mark
	.byte	9                               ## Abbrev [9] 0xc3:0xd DW_TAG_call_site
	.long	273                             ## DW_AT_call_origin
	.quad	Ltmp2                           ## DW_AT_call_return_pc
	.byte	9                               ## Abbrev [9] 0xd0:0xd DW_TAG_call_site
	.long	293                             ## DW_AT_call_origin
	.quad	Ltmp7                           ## DW_AT_call_return_pc
	.byte	0                               ## End Of Children Mark
	.byte	10                              ## Abbrev [10] 0xde:0x11 DW_TAG_subprogram
	.long	274                             ## DW_AT_name
	.byte	2                               ## DW_AT_decl_file
	.byte	118                             ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	239                             ## DW_AT_type
                                        ## DW_AT_declaration
                                        ## DW_AT_external
                                        ## DW_AT_APPLE_optimized
	.byte	11                              ## Abbrev [11] 0xe9:0x5 DW_TAG_formal_parameter
	.long	268                             ## DW_AT_type
	.byte	0                               ## End Of Children Mark
	.byte	12                              ## Abbrev [12] 0xef:0xb DW_TAG_typedef
	.long	250                             ## DW_AT_type
	.long	279                             ## DW_AT_name
	.byte	4                               ## DW_AT_decl_file
	.byte	31                              ## DW_AT_decl_line
	.byte	12                              ## Abbrev [12] 0xfa:0xb DW_TAG_typedef
	.long	261                             ## DW_AT_type
	.long	286                             ## DW_AT_name
	.byte	3                               ## DW_AT_decl_file
	.byte	122                             ## DW_AT_decl_line
	.byte	13                              ## Abbrev [13] 0x105:0x7 DW_TAG_base_type
	.long	302                             ## DW_AT_name
	.byte	5                               ## DW_AT_encoding
	.byte	8                               ## DW_AT_byte_size
	.byte	14                              ## Abbrev [14] 0x10c:0x5 DW_TAG_pointer_type
	.long	239                             ## DW_AT_type
	.byte	15                              ## Abbrev [15] 0x111:0xd DW_TAG_subprogram
	.long	307                             ## DW_AT_name
	.byte	5                               ## DW_AT_decl_file
	.byte	164                             ## DW_AT_decl_line
                                        ## DW_AT_prototyped
                                        ## DW_AT_declaration
                                        ## DW_AT_external
                                        ## DW_AT_APPLE_optimized
	.byte	11                              ## Abbrev [11] 0x118:0x5 DW_TAG_formal_parameter
	.long	286                             ## DW_AT_type
	.byte	0                               ## End Of Children Mark
	.byte	13                              ## Abbrev [13] 0x11e:0x7 DW_TAG_base_type
	.long	313                             ## DW_AT_name
	.byte	7                               ## DW_AT_encoding
	.byte	4                               ## DW_AT_byte_size
	.byte	16                              ## Abbrev [16] 0x125:0xb DW_TAG_subprogram
	.long	326                             ## DW_AT_name
	.byte	5                               ## DW_AT_decl_file
	.byte	162                             ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	304                             ## DW_AT_type
                                        ## DW_AT_declaration
                                        ## DW_AT_external
                                        ## DW_AT_APPLE_optimized
	.byte	13                              ## Abbrev [13] 0x130:0x7 DW_TAG_base_type
	.long	331                             ## DW_AT_name
	.byte	5                               ## DW_AT_encoding
	.byte	4                               ## DW_AT_byte_size
	.byte	13                              ## Abbrev [13] 0x137:0x7 DW_TAG_base_type
	.long	353                             ## DW_AT_name
	.byte	7                               ## DW_AT_encoding
	.byte	8                               ## DW_AT_byte_size
	.byte	17                              ## Abbrev [17] 0x13e:0xf DW_TAG_array_type
	.long	304                             ## DW_AT_type
	.byte	18                              ## Abbrev [18] 0x143:0x9 DW_TAG_subrange_type
	.long	333                             ## DW_AT_type
	.long	75                              ## DW_AT_count
	.byte	0                               ## End Of Children Mark
	.byte	19                              ## Abbrev [19] 0x14d:0x7 DW_TAG_base_type
	.long	399                             ## DW_AT_name
	.byte	8                               ## DW_AT_byte_size
	.byte	7                               ## DW_AT_encoding
	.byte	0                               ## End Of Children Mark
Ldebug_info_end0:
	.section	__DWARF,__debug_ranges,regular,debug
Ldebug_range:
Ldebug_ranges0:
.set Lset31, Ltmp2-Lfunc_begin0
	.quad	Lset31
.set Lset32, Ltmp10-Lfunc_begin0
	.quad	Lset32
.set Lset33, Ltmp17-Lfunc_begin0
	.quad	Lset33
.set Lset34, Ltmp28-Lfunc_begin0
	.quad	Lset34
	.quad	0
	.quad	0
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple clang version 14.0.0 (clang-1400.0.29.202)" ## string offset=0
	.asciz	"main.c"                        ## string offset=49
	.asciz	"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk" ## string offset=56
	.asciz	"MacOSX.sdk"                    ## string offset=151
	.asciz	"/Users/megami-sama/Documents/CS-entertaining-plays-tracker/ current-tracker/1-cs5008/hw/homework01-jindacz" ## string offset=162
	.asciz	"main"                          ## string offset=269
	.asciz	"time"                          ## string offset=274
	.asciz	"time_t"                        ## string offset=279
	.asciz	"__darwin_time_t"               ## string offset=286
	.asciz	"long"                          ## string offset=302
	.asciz	"srand"                         ## string offset=307
	.asciz	"unsigned int"                  ## string offset=313
	.asciz	"rand"                          ## string offset=326
	.asciz	"int"                           ## string offset=331
	.asciz	"guess"                         ## string offset=335
	.asciz	"__vla_expr0"                   ## string offset=341
	.asciz	"unsigned long"                 ## string offset=353
	.asciz	"numOfRounds"                   ## string offset=367
	.asciz	"count"                         ## string offset=379
	.asciz	"target"                        ## string offset=385
	.asciz	"rounds"                        ## string offset=392
	.asciz	"__ARRAY_SIZE_TYPE__"           ## string offset=399
	.asciz	"i"                             ## string offset=419
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712                      ## Header Magic
	.short	1                               ## Header Version
	.short	0                               ## Header Hash Function
	.long	1                               ## Header Bucket Count
	.long	1                               ## Header Hash Count
	.long	12                              ## Header Data Length
	.long	0                               ## HeaderData Die Offset Base
	.long	1                               ## HeaderData Atom Count
	.short	1                               ## DW_ATOM_die_offset
	.short	6                               ## DW_FORM_data4
	.long	0                               ## Bucket 0
	.long	2090499946                      ## Hash in Bucket 0
.set Lset35, LNames0-Lnames_begin       ## Offset in Bucket 0
	.long	Lset35
LNames0:
	.long	269                             ## main
	.long	1                               ## Num DIEs
	.long	50
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712                      ## Header Magic
	.short	1                               ## Header Version
	.short	0                               ## Header Hash Function
	.long	1                               ## Header Bucket Count
	.long	0                               ## Header Hash Count
	.long	12                              ## Header Data Length
	.long	0                               ## HeaderData Die Offset Base
	.long	1                               ## HeaderData Atom Count
	.short	1                               ## DW_ATOM_die_offset
	.short	6                               ## DW_FORM_data4
	.long	-1                              ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712                      ## Header Magic
	.short	1                               ## Header Version
	.short	0                               ## Header Hash Function
	.long	1                               ## Header Bucket Count
	.long	0                               ## Header Hash Count
	.long	12                              ## Header Data Length
	.long	0                               ## HeaderData Die Offset Base
	.long	1                               ## HeaderData Atom Count
	.short	1                               ## DW_ATOM_die_offset
	.short	6                               ## DW_FORM_data4
	.long	-1                              ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712                      ## Header Magic
	.short	1                               ## Header Version
	.short	0                               ## Header Hash Function
	.long	7                               ## Header Bucket Count
	.long	7                               ## Header Hash Count
	.long	20                              ## Header Data Length
	.long	0                               ## HeaderData Die Offset Base
	.long	3                               ## HeaderData Atom Count
	.short	1                               ## DW_ATOM_die_offset
	.short	6                               ## DW_FORM_data4
	.short	3                               ## DW_ATOM_die_tag
	.short	5                               ## DW_FORM_data2
	.short	4                               ## DW_ATOM_type_flags
	.short	11                              ## DW_FORM_data1
	.long	-1                              ## Bucket 0
	.long	0                               ## Bucket 1
	.long	3                               ## Bucket 2
	.long	4                               ## Bucket 3
	.long	-1                              ## Bucket 4
	.long	-1                              ## Bucket 5
	.long	5                               ## Bucket 6
	.long	2090479413                      ## Hash in Bucket 1
	.long	-594775205                      ## Hash in Bucket 1
	.long	-243996567                      ## Hash in Bucket 1
	.long	-103762318                      ## Hash in Bucket 2
	.long	193495088                       ## Hash in Bucket 3
	.long	505346631                       ## Hash in Bucket 6
	.long	-1304652851                     ## Hash in Bucket 6
.set Lset36, Ltypes0-Ltypes_begin       ## Offset in Bucket 1
	.long	Lset36
.set Lset37, Ltypes3-Ltypes_begin       ## Offset in Bucket 1
	.long	Lset37
.set Lset38, Ltypes2-Ltypes_begin       ## Offset in Bucket 1
	.long	Lset38
.set Lset39, Ltypes6-Ltypes_begin       ## Offset in Bucket 2
	.long	Lset39
.set Lset40, Ltypes5-Ltypes_begin       ## Offset in Bucket 3
	.long	Lset40
.set Lset41, Ltypes1-Ltypes_begin       ## Offset in Bucket 6
	.long	Lset41
.set Lset42, Ltypes4-Ltypes_begin       ## Offset in Bucket 6
	.long	Lset42
Ltypes0:
	.long	302                             ## long
	.long	1                               ## Num DIEs
	.long	261
	.short	36
	.byte	0
	.long	0
Ltypes3:
	.long	399                             ## __ARRAY_SIZE_TYPE__
	.long	1                               ## Num DIEs
	.long	333
	.short	36
	.byte	0
	.long	0
Ltypes2:
	.long	286                             ## __darwin_time_t
	.long	1                               ## Num DIEs
	.long	250
	.short	22
	.byte	0
	.long	0
Ltypes6:
	.long	353                             ## unsigned long
	.long	1                               ## Num DIEs
	.long	311
	.short	36
	.byte	0
	.long	0
Ltypes5:
	.long	331                             ## int
	.long	1                               ## Num DIEs
	.long	304
	.short	36
	.byte	0
	.long	0
Ltypes1:
	.long	279                             ## time_t
	.long	1                               ## Num DIEs
	.long	239
	.short	22
	.byte	0
	.long	0
Ltypes4:
	.long	313                             ## unsigned int
	.long	1                               ## Num DIEs
	.long	286
	.short	36
	.byte	0
	.long	0
.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
