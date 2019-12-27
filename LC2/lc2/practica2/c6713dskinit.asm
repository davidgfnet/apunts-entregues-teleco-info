;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v5.1.0 *
;* Date/Time created: Mon Nov 13 08:43:13 2006                                *
;******************************************************************************
	.compiler_opts --endian=little --mem_model:code=near --mem_model:data=far --silicon_version=6200 

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture      : TMS320C620x                                          *
;*   Optimization      : Enabled at level 3                                   *
;*   Optimizing for    : Speed                                                *
;*                       Based on options: -o3, no -ms                        *
;*   Endian            : Little                                               *
;*   Interrupt Thrshld : Infinite                                             *
;*   Data Access Model : Far                                                  *
;*   Pipelining        : Enabled                                              *
;*   Speculate Loads   : Disabled                                             *
;*   Memory Aliases    : Presume are aliases (pessimistic)                    *
;*   Debug Info        : DWARF Debug                                          *
;*                                                                            *
;******************************************************************************

	.asg	A15, FP
	.asg	B14, DP
	.asg	B15, SP
	.global	$bss


DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v5.1.0 Copyright (c) 1996-2005 Texas Instruments Incorporated")
	.dwattr DW$CU, DW_AT_stmt_list(0x00)
	.dwattr DW$CU, DW_AT_TI_VERSION(0x01)
;*****************************************************************************
;* CINIT RECORDS                                                             *
;*****************************************************************************
	.sect	".cinit"
	.align	8
	.field  	IR_1,32
	.field  	_AIC23CfgData+0,32
	.field  	0,32			; _AIC23CfgData._spcr @ 0
	.field  	160,32			; _AIC23CfgData._rcr @ 32
	.field  	160,32			; _AIC23CfgData._xcr @ 64
	.field  	536870913,32			; _AIC23CfgData._srgr @ 96
	.field  	0,32			; _AIC23CfgData._mcr @ 128
	.field  	0,32			; _AIC23CfgData._rcer @ 160
	.field  	0,32			; _AIC23CfgData._xcer @ 192
	.field  	3,32			; _AIC23CfgData._pcr @ 224
IR_1:	.set	32

	.sect	".cinit"
	.align	8
	.field  	IR_2,32
	.field  	_config+0,32
	.field  	23,32			; _config._regs[0] @ 0
	.field  	23,32			; _config._regs[1] @ 32
	.field  	505,32			; _config._regs[2] @ 64
	.field  	505,32			; _config._regs[3] @ 96
	.field  	17,32			; _config._regs[4] @ 128
	.field  	0,32			; _config._regs[5] @ 160
	.field  	0,32			; _config._regs[6] @ 192
	.field  	67,32			; _config._regs[7] @ 224
	.field  	129,32			; _config._regs[8] @ 256
	.field  	1,32			; _config._regs[9] @ 288
IR_2:	.set	40


DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_map"), DW_AT_symbol_name("_IRQ_map")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$3	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$1


DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_setVecs"), DW_AT_symbol_name("_IRQ_setVecs")
	.dwattr DW$4, DW_AT_type(*DW$T$3)
	.dwattr DW$4, DW_AT_declaration(0x01)
	.dwattr DW$4, DW_AT_external(0x01)
DW$5	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$3)
	.dwendtag DW$4


DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_init"), DW_AT_symbol_name("_DSK6713_init")
	.dwattr DW$6, DW_AT_declaration(0x01)
	.dwattr DW$6, DW_AT_external(0x01)

DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_start"), DW_AT_symbol_name("_MCBSP_start")
	.dwattr DW$7, DW_AT_declaration(0x01)
	.dwattr DW$7, DW_AT_external(0x01)
DW$8	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$36)
DW$9	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$10	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$7


DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_AIC23_openCodec"), DW_AT_symbol_name("_DSK6713_AIC23_openCodec")
	.dwattr DW$11, DW_AT_type(*DW$T$43)
	.dwattr DW$11, DW_AT_declaration(0x01)
	.dwattr DW$11, DW_AT_external(0x01)
DW$12	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$53)
	.dwendtag DW$11


DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_AIC23_setFreq"), DW_AT_symbol_name("_DSK6713_AIC23_setFreq")
	.dwattr DW$14, DW_AT_declaration(0x01)
	.dwattr DW$14, DW_AT_external(0x01)
DW$15	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$43)
DW$16	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$14


DW$17	.dwtag  DW_TAG_subprogram, DW_AT_name("vectors"), DW_AT_symbol_name("_vectors")
	.dwattr DW$17, DW_AT_declaration(0x01)
	.dwattr DW$17, DW_AT_external(0x01)
DW$18	.dwtag  DW_TAG_variable, DW_AT_name("_IRQ_eventTable"), DW_AT_symbol_name("__IRQ_eventTable")
	.dwattr DW$18, DW_AT_type(*DW$T$61)
	.dwattr DW$18, DW_AT_declaration(0x01)
	.dwattr DW$18, DW_AT_external(0x01)
DW$19	.dwtag  DW_TAG_variable, DW_AT_name("DSK6713_AIC23_codecdatahandle"), DW_AT_symbol_name("_DSK6713_AIC23_codecdatahandle")
	.dwattr DW$19, DW_AT_type(*DW$T$36)
	.dwattr DW$19, DW_AT_declaration(0x01)
	.dwattr DW$19, DW_AT_external(0x01)
	.global	_AIC_data
_AIC_data:	.usect	".far",4,4
DW$20	.dwtag  DW_TAG_variable, DW_AT_name("AIC_data"), DW_AT_symbol_name("_AIC_data")
	.dwattr DW$20, DW_AT_location[DW_OP_addr _AIC_data]
	.dwattr DW$20, DW_AT_type(*DW$T$27)
	.dwattr DW$20, DW_AT_external(0x01)
_CODECEventId$0:	.usect	".far",4,4
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("CODECEventId"), DW_AT_symbol_name("_CODECEventId$0")
	.dwattr DW$21, DW_AT_type(*DW$T$19)
	.dwattr DW$21, DW_AT_location[DW_OP_addr _CODECEventId$0]
_poll$0:	.usect	".far",4,4
DW$22	.dwtag  DW_TAG_variable, DW_AT_name("poll"), DW_AT_symbol_name("_poll$0")
	.dwattr DW$22, DW_AT_type(*DW$T$19)
	.dwattr DW$22, DW_AT_location[DW_OP_addr _poll$0]
	.global	_AIC23CfgData
_AIC23CfgData:	.usect	".far",32,4
DW$23	.dwtag  DW_TAG_variable, DW_AT_name("AIC23CfgData"), DW_AT_symbol_name("_AIC23CfgData")
	.dwattr DW$23, DW_AT_location[DW_OP_addr _AIC23CfgData]
	.dwattr DW$23, DW_AT_type(*DW$T$40)
	.dwattr DW$23, DW_AT_external(0x01)
	.global	_config
_config:	.usect	".far",40,4
DW$24	.dwtag  DW_TAG_variable, DW_AT_name("config"), DW_AT_symbol_name("_config")
	.dwattr DW$24, DW_AT_location[DW_OP_addr _config]
	.dwattr DW$24, DW_AT_type(*DW$T$52)
	.dwattr DW$24, DW_AT_external(0x01)
	.global	_hAIC23_handle
_hAIC23_handle:	.usect	".far",4,4
DW$25	.dwtag  DW_TAG_variable, DW_AT_name("hAIC23_handle"), DW_AT_symbol_name("_hAIC23_handle")
	.dwattr DW$25, DW_AT_location[DW_OP_addr _hAIC23_handle]
	.dwattr DW$25, DW_AT_type(*DW$T$43)
	.dwattr DW$25, DW_AT_external(0x01)
DW$26	.dwtag  DW_TAG_variable, DW_AT_name("fs"), DW_AT_symbol_name("_fs")
	.dwattr DW$26, DW_AT_type(*DW$T$19)
	.dwattr DW$26, DW_AT_declaration(0x01)
	.dwattr DW$26, DW_AT_external(0x01)
;	C:\CCStudio_v3.1\c6000\cgtools\bin\opt6x.exe --gen_opt_info=2 C:\DOCUME~1\ADMINI~1\CONFIG~1\Temp\TI17610 C:\DOCUME~1\ADMINI~1\CONFIG~1\Temp\TI1764 --opt_info_filename=D:/lc2/practiques_lc2_noves/practiques_que_funcionen/practica1/prac1_int/Debug/c6713dskinit.nfo 
	.sect	".text"
	.global	_output_sample

DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("output_sample"), DW_AT_symbol_name("_output_sample")
	.dwattr DW$27, DW_AT_low_pc(_output_sample)
	.dwattr DW$27, DW_AT_high_pc(0x00)
	.dwattr DW$27, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$27, DW_AT_begin_line(0x24)
	.dwattr DW$27, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",37,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _output_sample                                              *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,A6,B4,B5                                 *
;*   Regs Used         : A1,A3,A4,A5,A6,B3,B4,B5                              *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_output_sample:
;** --------------------------------------------------------------------------*
;** 41	-----------------------    C$2 = &AIC_data;
;** 41	-----------------------    (*C$2).uint = out_data;
;** 46	-----------------------    s$1 = *(short *)C$2;
;** 47	-----------------------    *&AIC_data = *((short *)C$2+2);
;** 48	-----------------------    *(&AIC_data+2) = s$1;
;** 49	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 49	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$28	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$28, DW_AT_type(*DW$T$10)
	.dwattr DW$28, DW_AT_location[DW_OP_reg4]
DW$29	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$29, DW_AT_type(*DW$T$63)
	.dwattr DW$29, DW_AT_location[DW_OP_reg5]
DW$30	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$30, DW_AT_type(*DW$T$68)
	.dwattr DW$30, DW_AT_location[DW_OP_reg3]
DW$31	.dwtag  DW_TAG_variable, DW_AT_name("s$1"), DW_AT_symbol_name("s$1")
	.dwattr DW$31, DW_AT_type(*DW$T$8)
	.dwattr DW$31, DW_AT_location[DW_OP_reg4]
DW$32	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$32, DW_AT_type(*DW$T$35)
	.dwattr DW$32, DW_AT_location[DW_OP_reg6]
DW$33	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$33, DW_AT_type(*DW$T$57)
	.dwattr DW$33, DW_AT_location[DW_OP_reg4]
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("U$25"), DW_AT_symbol_name("U$25")
	.dwattr DW$34, DW_AT_type(*DW$T$63)
	.dwattr DW$34, DW_AT_location[DW_OP_reg5]
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("K$21"), DW_AT_symbol_name("K$21")
	.dwattr DW$35, DW_AT_type(*DW$T$11)
	.dwattr DW$35, DW_AT_location[DW_OP_reg20]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",41,2
           MVKL    .S1     _AIC_data,A3      ; |41| 
           MVKH    .S1     _AIC_data,A3      ; |41| 
           STW     .D1T1   A4,*A3            ; |41| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",46,2
           LDH     .D1T1   *A3,A4            ; |46| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",47,2

           LDH     .D1T2   *+A3(2),B5        ; |47| 
||         MVKL    .S2     _AIC_data,B4      ; |47| 

           MVKH    .S2     _AIC_data,B4      ; |47| 
           NOP             3
           STH     .D2T2   B5,*B4            ; |47| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",48,2
           MVKL    .S2     _AIC_data+2,B4    ; |48| 
           MVKH    .S2     _AIC_data+2,B4    ; |48| 
           STH     .D2T1   A4,*B4            ; |48| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",49,4

           MVKL    .S1     _poll$0,A3        ; |49| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |49| 

           MVKH    .S1     _poll$0,A3        ; |49| 
||         MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |49| 

           LDW     .D1T1   *A3,A1            ; |49| 
           LDW     .D2T1   *B4,A6            ; |49| 
           NOP             3
   [!A1]   B       .S1     L4                ; |49| 
           NOP             5
           ; BRANCHCC OCCURS {L4}            ; |49| 
;** --------------------------------------------------------------------------*
;** 229	-----------------------    C$1 = (*v$1).baseAddr+8;  // [13]
;** 229	-----------------------    if ( *(volatile unsigned *)(unsigned)C$1&0x20000u ) goto g5;  // [13]
;**  	-----------------------    U$25 = (volatile unsigned *)(unsigned)C$1;
;** 229	-----------------------    K$21 = 131072u;  // [13]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",229,3

           LDW     .D1T1   *+A6(12),A3       ; |229| 
||         ZERO    .L2     B4                ; |229| 

           MVKH    .S2     0x20000,B4        ; |229| 
           NOP             3
           ADD     .L1     8,A3,A5           ; |229| 
           LDW     .D1T1   *A5,A3            ; |229| 
           NOP             4
           EXTU    .S1     A3,14,31,A1       ; |229| 

   [!A1]   LDW     .D1T1   *A5,A3            ; |229| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L4                ; |229| 
|| [!A1]   MV      .L1X    B4,A4

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L4}            ; |229| 
;**	-----------------------g4:
;** 229	-----------------------    if ( !(*U$25&K$21) ) goto g4;  // [13]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 49
;*      Loop closing brace source line   : 229
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L1:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L2:    ; PIPED LOOP KERNEL
DW$L$_output_sample$4$B:

   [!A1]   B       .S2     L2                ; |229| <0,6> 
|| [!A1]   LDW     .D1T1   *A5,A3            ; |229| <1,0>  ^ 

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| <1,5>  ^ 
DW$L$_output_sample$4$E:
;** --------------------------------------------------------------------------*
L3:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L4:    
;**	-----------------------g5:
;** 225	-----------------------    *(volatile unsigned *)(*v$1).dxrAddr = AIC_data.uint;  // [12]
;** 225	-----------------------    return;  // [12]
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",225,3
           MVKL    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *+A6(20),A4       ; |225| 
||         MVKH    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *A3,A3            ; |225| 
           NOP             4
           STW     .D1T1   A3,*A4            ; |225| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",51,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |51| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |51| 

DW$36	.dwtag  DW_TAG_loop
	.dwattr DW$36, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L2:1:1163403793")
	.dwattr DW$36, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$36, DW_AT_begin_line(0x31)
	.dwattr DW$36, DW_AT_end_line(0xe5)
DW$37	.dwtag  DW_TAG_loop_range
	.dwattr DW$37, DW_AT_low_pc(DW$L$_output_sample$4$B)
	.dwattr DW$37, DW_AT_high_pc(DW$L$_output_sample$4$E)
	.dwendtag DW$36

	.dwattr DW$27, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$27, DW_AT_end_line(0x33)
	.dwattr DW$27, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$27

	.sect	".text"
	.global	_output_right_sample

DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("output_right_sample"), DW_AT_symbol_name("_output_right_sample")
	.dwattr DW$38, DW_AT_low_pc(_output_right_sample)
	.dwattr DW$38, DW_AT_high_pc(0x00)
	.dwattr DW$38, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$38, DW_AT_begin_line(0x3e)
	.dwattr DW$38, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",63,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _output_right_sample                                        *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,A6,B4,B5                                 *
;*   Regs Used         : A1,A3,A4,A5,A6,B3,B4,B5                              *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_output_right_sample:
;** --------------------------------------------------------------------------*
;** 64	-----------------------    AIC_data.uint = 0u;
;** 65	-----------------------    *&AIC_data = out_data;
;** 67	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 67	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$39	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$39, DW_AT_type(*DW$T$8)
	.dwattr DW$39, DW_AT_location[DW_OP_reg4]
DW$40	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$40, DW_AT_type(*DW$T$63)
	.dwattr DW$40, DW_AT_location[DW_OP_reg5]
DW$41	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$41, DW_AT_type(*DW$T$35)
	.dwattr DW$41, DW_AT_location[DW_OP_reg6]
DW$42	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$42, DW_AT_type(*DW$T$51)
	.dwattr DW$42, DW_AT_location[DW_OP_reg4]
DW$43	.dwtag  DW_TAG_variable, DW_AT_name("U$21"), DW_AT_symbol_name("U$21")
	.dwattr DW$43, DW_AT_type(*DW$T$63)
	.dwattr DW$43, DW_AT_location[DW_OP_reg5]
DW$44	.dwtag  DW_TAG_variable, DW_AT_name("K$17"), DW_AT_symbol_name("K$17")
	.dwattr DW$44, DW_AT_type(*DW$T$11)
	.dwattr DW$44, DW_AT_location[DW_OP_reg20]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",64,2

           MVKL    .S2     _AIC_data,B4      ; |64| 
||         ZERO    .L2     B5                ; |64| 

           MVKH    .S2     _AIC_data,B4      ; |64| 
           STW     .D2T2   B5,*B4            ; |64| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",65,2
           MVKL    .S2     _AIC_data,B4      ; |65| 
           MVKH    .S2     _AIC_data,B4      ; |65| 
           STH     .D2T1   A4,*B4            ; |65| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",67,2

           MVKL    .S1     _poll$0,A3        ; |67| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |67| 

           MVKH    .S1     _poll$0,A3        ; |67| 
||         MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |67| 

           LDW     .D1T1   *A3,A1            ; |67| 
           LDW     .D2T1   *B4,A6            ; |67| 
           NOP             3
   [!A1]   B       .S1     L8                ; |67| 
           NOP             5
           ; BRANCHCC OCCURS {L8}            ; |67| 
;** --------------------------------------------------------------------------*
;** 229	-----------------------    C$1 = (*v$1).baseAddr+8;  // [13]
;** 229	-----------------------    if ( *(volatile unsigned *)(unsigned)C$1&0x20000u ) goto g5;  // [13]
;**  	-----------------------    U$21 = (volatile unsigned *)(unsigned)C$1;
;** 229	-----------------------    K$17 = 131072u;  // [13]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",229,3

           LDW     .D1T1   *+A6(12),A3       ; |229| 
||         ZERO    .L2     B4                ; |229| 

           MVKH    .S2     0x20000,B4        ; |229| 
           NOP             3
           ADD     .L1     8,A3,A5           ; |229| 
           LDW     .D1T1   *A5,A3            ; |229| 
           NOP             4
           EXTU    .S1     A3,14,31,A1       ; |229| 

   [!A1]   LDW     .D1T1   *A5,A3            ; |229| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L8                ; |229| 
|| [!A1]   MV      .L1X    B4,A4

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L8}            ; |229| 
;**	-----------------------g4:
;** 229	-----------------------    if ( !(*U$21&K$17) ) goto g4;  // [13]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 67
;*      Loop closing brace source line   : 229
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L5:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L6:    ; PIPED LOOP KERNEL
DW$L$_output_right_sample$4$B:

   [!A1]   B       .S2     L6                ; |229| <0,6> 
|| [!A1]   LDW     .D1T1   *A5,A3            ; |229| <1,0>  ^ 

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| <1,5>  ^ 
DW$L$_output_right_sample$4$E:
;** --------------------------------------------------------------------------*
L7:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L8:    
;**	-----------------------g5:
;** 225	-----------------------    *(volatile unsigned *)(*v$1).dxrAddr = AIC_data.uint;  // [12]
;** 225	-----------------------    return;  // [12]
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",225,3
           MVKL    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *+A6(20),A4       ; |225| 
||         MVKH    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *A3,A3            ; |225| 
           NOP             4
           STW     .D1T1   A3,*A4            ; |225| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",69,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |69| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |69| 

DW$45	.dwtag  DW_TAG_loop
	.dwattr DW$45, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L6:1:1163403793")
	.dwattr DW$45, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$45, DW_AT_begin_line(0x43)
	.dwattr DW$45, DW_AT_end_line(0xe5)
DW$46	.dwtag  DW_TAG_loop_range
	.dwattr DW$46, DW_AT_low_pc(DW$L$_output_right_sample$4$B)
	.dwattr DW$46, DW_AT_high_pc(DW$L$_output_right_sample$4$E)
	.dwendtag DW$45

	.dwattr DW$38, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$38, DW_AT_end_line(0x45)
	.dwattr DW$38, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$38

	.sect	".text"
	.global	_output_left_sample

DW$47	.dwtag  DW_TAG_subprogram, DW_AT_name("output_left_sample"), DW_AT_symbol_name("_output_left_sample")
	.dwattr DW$47, DW_AT_low_pc(_output_left_sample)
	.dwattr DW$47, DW_AT_high_pc(0x00)
	.dwattr DW$47, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$47, DW_AT_begin_line(0x35)
	.dwattr DW$47, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",54,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _output_left_sample                                         *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,A6,B0,B4                                 *
;*   Regs Used         : A1,A3,A4,A5,A6,B0,B3,B4                              *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_output_left_sample:
;** --------------------------------------------------------------------------*
;** 55	-----------------------    C$2 = &AIC_data;
;** 55	-----------------------    (*C$2).uint = 0u;
;** 56	-----------------------    *((short *)C$2+2) = out_data;
;** 58	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 58	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$48	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$48, DW_AT_type(*DW$T$8)
	.dwattr DW$48, DW_AT_location[DW_OP_reg4]
DW$49	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$49, DW_AT_type(*DW$T$63)
	.dwattr DW$49, DW_AT_location[DW_OP_reg5]
DW$50	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$50, DW_AT_type(*DW$T$68)
	.dwattr DW$50, DW_AT_location[DW_OP_reg3]
DW$51	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$51, DW_AT_type(*DW$T$35)
	.dwattr DW$51, DW_AT_location[DW_OP_reg6]
DW$52	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$52, DW_AT_type(*DW$T$51)
	.dwattr DW$52, DW_AT_location[DW_OP_reg4]
DW$53	.dwtag  DW_TAG_variable, DW_AT_name("U$23"), DW_AT_symbol_name("U$23")
	.dwattr DW$53, DW_AT_type(*DW$T$63)
	.dwattr DW$53, DW_AT_location[DW_OP_reg5]
DW$54	.dwtag  DW_TAG_variable, DW_AT_name("K$19"), DW_AT_symbol_name("K$19")
	.dwattr DW$54, DW_AT_type(*DW$T$11)
	.dwattr DW$54, DW_AT_location[DW_OP_reg20]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",55,2

           MVKL    .S1     _AIC_data,A3      ; |55| 
||         ZERO    .L1     A5                ; |55| 

           MVKH    .S1     _AIC_data,A3      ; |55| 
           STW     .D1T1   A5,*A3            ; |55| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",56,2
           STH     .D1T1   A4,*+A3(2)        ; |56| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",58,2

           MVKL    .S2     _poll$0,B4        ; |58| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |58| 

           MVKH    .S2     _poll$0,B4        ; |58| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |58| 

           LDW     .D2T2   *B4,B0            ; |58| 
||         LDW     .D1T1   *A3,A6            ; |58| 

           NOP             4
   [!B0]   B       .S1     L12               ; |58| 
           NOP             5
           ; BRANCHCC OCCURS {L12}           ; |58| 
;** --------------------------------------------------------------------------*
;** 229	-----------------------    C$1 = (*v$1).baseAddr+8;  // [13]
;** 229	-----------------------    if ( *(volatile unsigned *)(unsigned)C$1&0x20000u ) goto g5;  // [13]
;**  	-----------------------    U$23 = (volatile unsigned *)(unsigned)C$1;
;** 229	-----------------------    K$19 = 131072u;  // [13]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",229,3

           LDW     .D1T1   *+A6(12),A3       ; |229| 
||         ZERO    .L2     B4                ; |229| 

           MVKH    .S2     0x20000,B4        ; |229| 
           NOP             3
           ADD     .L1     8,A3,A5           ; |229| 
           LDW     .D1T1   *A5,A3            ; |229| 
           NOP             4
           EXTU    .S1     A3,14,31,A1       ; |229| 

   [!A1]   LDW     .D1T1   *A5,A3            ; |229| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L12               ; |229| 
|| [!A1]   MV      .L1X    B4,A4

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L12}           ; |229| 
;**	-----------------------g4:
;** 229	-----------------------    if ( !(*U$23&K$19) ) goto g4;  // [13]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 58
;*      Loop closing brace source line   : 229
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L9:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L10:    ; PIPED LOOP KERNEL
DW$L$_output_left_sample$4$B:

   [!A1]   B       .S2     L10               ; |229| <0,6> 
|| [!A1]   LDW     .D1T1   *A5,A3            ; |229| <1,0>  ^ 

           NOP             4
           AND     .L1     A4,A3,A1          ; |229| <1,5>  ^ 
DW$L$_output_left_sample$4$E:
;** --------------------------------------------------------------------------*
L11:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L12:    
;**	-----------------------g5:
;** 225	-----------------------    *(volatile unsigned *)(*v$1).dxrAddr = AIC_data.uint;  // [12]
;** 225	-----------------------    return;  // [12]
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",225,3
           MVKL    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *+A6(20),A4       ; |225| 
||         MVKH    .S1     _AIC_data,A3      ; |225| 

           LDW     .D1T1   *A3,A3            ; |225| 
           NOP             4
           STW     .D1T1   A3,*A4            ; |225| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",60,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |60| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |60| 

DW$55	.dwtag  DW_TAG_loop
	.dwattr DW$55, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L10:1:1163403793")
	.dwattr DW$55, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$55, DW_AT_begin_line(0x3a)
	.dwattr DW$55, DW_AT_end_line(0xe5)
DW$56	.dwtag  DW_TAG_loop_range
	.dwattr DW$56, DW_AT_low_pc(DW$L$_output_left_sample$4$B)
	.dwattr DW$56, DW_AT_high_pc(DW$L$_output_left_sample$4$E)
	.dwendtag DW$55

	.dwattr DW$47, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$47, DW_AT_end_line(0x3c)
	.dwattr DW$47, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$47

	.sect	".text"
	.global	_input_sample

DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("input_sample"), DW_AT_symbol_name("_input_sample")
	.dwattr DW$57, DW_AT_low_pc(_input_sample)
	.dwattr DW$57, DW_AT_high_pc(0x00)
	.dwattr DW$57, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$57, DW_AT_begin_line(0x47)
	.dwattr DW$57, DW_AT_begin_column(0x08)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",72,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _input_sample                                               *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,B4,B5                                    *
;*   Regs Used         : A1,A3,A4,A5,B3,B4,B5                                 *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_input_sample:
;** --------------------------------------------------------------------------*
;** 75	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 75	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$58	.dwtag  DW_TAG_variable, DW_AT_name("C$11"), DW_AT_symbol_name("C$11")
	.dwattr DW$58, DW_AT_type(*DW$T$68)
	.dwattr DW$58, DW_AT_location[DW_OP_reg20]
DW$59	.dwtag  DW_TAG_variable, DW_AT_name("C$12"), DW_AT_symbol_name("C$12")
	.dwattr DW$59, DW_AT_type(*DW$T$63)
	.dwattr DW$59, DW_AT_location[DW_OP_reg4]
DW$60	.dwtag  DW_TAG_variable, DW_AT_name("s$1"), DW_AT_symbol_name("s$1")
	.dwattr DW$60, DW_AT_type(*DW$T$8)
	.dwattr DW$60, DW_AT_location[DW_OP_reg21]
DW$61	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$61, DW_AT_type(*DW$T$35)
	.dwattr DW$61, DW_AT_location[DW_OP_reg5]
DW$62	.dwtag  DW_TAG_variable, DW_AT_name("R$1"), DW_AT_symbol_name("R$1")
	.dwattr DW$62, DW_AT_type(*DW$T$11)
	.dwattr DW$62, DW_AT_location[DW_OP_reg3]
DW$63	.dwtag  DW_TAG_variable, DW_AT_name("U$16"), DW_AT_symbol_name("U$16")
	.dwattr DW$63, DW_AT_type(*DW$T$63)
	.dwattr DW$63, DW_AT_location[DW_OP_reg4]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",75,2

           MVKL    .S1     _poll$0,A3        ; |75| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |75| 

           MVKH    .S1     _poll$0,A3        ; |75| 
||         MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |75| 

           LDW     .D1T1   *A3,A1            ; |75| 
           LDW     .D2T1   *B4,A5            ; |75| 
           NOP             3
   [!A1]   B       .S1     L16               ; |75| 
           NOP             5
           ; BRANCHCC OCCURS {L16}           ; |75| 
;** --------------------------------------------------------------------------*
;** 233	-----------------------    C$12 = (*v$1).baseAddr+8;  // [14]
;** 233	-----------------------    if ( *(volatile unsigned *)(unsigned)C$12&2u ) goto g5;  // [14]
;**  	-----------------------    U$16 = (volatile unsigned *)(unsigned)C$12;
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",233,3
           LDW     .D1T1   *+A5(12),A3       ; |233| 
           NOP             4
           ADD     .L1     8,A3,A4           ; |233| 
           LDW     .D1T1   *A4,A3            ; |233| 
           NOP             4
           AND     .L1     2,A3,A1           ; |233| 

   [!A1]   LDW     .D1T1   *A4,A3            ; |233| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L16               ; |233| 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L16}           ; |233| 
;**	-----------------------g4:
;** 233	-----------------------    if ( !(*U$16&2u) ) goto g4;  // [14]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 75
;*      Loop closing brace source line   : 233
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L13:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L14:    ; PIPED LOOP KERNEL
DW$L$_input_sample$4$B:

   [!A1]   B       .S2     L14               ; |233| <0,6> 
|| [!A1]   LDW     .D1T1   *A4,A3            ; |233| <1,0>  ^ 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| <1,5>  ^ 
DW$L$_input_sample$4$E:
;** --------------------------------------------------------------------------*
L15:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L16:    
;**	-----------------------g5:
;** 221	-----------------------    R$1 = *(volatile unsigned *)(*v$1).drrAddr;  // [11]
;** 221	-----------------------    C$11 = &AIC_data;  // [11]
;** 221	-----------------------    (*C$11).uint = R$1;  // [11]
;** 79	-----------------------    s$1 = *(short *)C$11;
;** 80	-----------------------    *&AIC_data = *((short *)C$11+2);
;** 81	-----------------------    *(&AIC_data+2) = s$1;
;** 83	-----------------------    return AIC_data.uint;
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",221,3
           LDW     .D1T1   *+A5(16),A3       ; |221| 
           MVKL    .S2     _AIC_data,B4      ; |221| 
           MVKH    .S2     _AIC_data,B4      ; |221| 
           NOP             2
           LDW     .D1T1   *A3,A3            ; |221| 
           NOP             4
           STW     .D2T1   A3,*B4            ; |221| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",79,2
           LDH     .D2T2   *B4,B5            ; |79| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",80,2
           LDH     .D2T1   *+B4(2),A4        ; |80| 
           MVKL    .S1     _AIC_data,A3      ; |80| 
           MVKH    .S1     _AIC_data,A3      ; |80| 
           NOP             2
           STH     .D1T1   A4,*A3            ; |80| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",81,2
           MVKL    .S1     _AIC_data+2,A3    ; |81| 
           MVKH    .S1     _AIC_data+2,A3    ; |81| 
           STH     .D1T2   B5,*A3            ; |81| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",83,2
           MVKL    .S2     _AIC_data,B4      ; |83| 
           MVKH    .S2     _AIC_data,B4      ; |83| 
           LDW     .D2T1   *B4,A4            ; |83| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",84,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |84| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |84| 

DW$64	.dwtag  DW_TAG_loop
	.dwattr DW$64, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L14:1:1163403793")
	.dwattr DW$64, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$64, DW_AT_begin_line(0x4b)
	.dwattr DW$64, DW_AT_end_line(0xe9)
DW$65	.dwtag  DW_TAG_loop_range
	.dwattr DW$65, DW_AT_low_pc(DW$L$_input_sample$4$B)
	.dwattr DW$65, DW_AT_high_pc(DW$L$_input_sample$4$E)
	.dwendtag DW$64

	.dwattr DW$57, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$57, DW_AT_end_line(0x54)
	.dwattr DW$57, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$57

	.sect	".text"
	.global	_input_right_sample

DW$66	.dwtag  DW_TAG_subprogram, DW_AT_name("input_right_sample"), DW_AT_symbol_name("_input_right_sample")
	.dwattr DW$66, DW_AT_low_pc(_input_right_sample)
	.dwattr DW$66, DW_AT_high_pc(0x00)
	.dwattr DW$66, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$66, DW_AT_begin_line(0x5d)
	.dwattr DW$66, DW_AT_begin_column(0x07)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",94,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _input_right_sample                                         *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,B4                                       *
;*   Regs Used         : A1,A3,A4,A5,B3,B4                                    *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_input_right_sample:
;** --------------------------------------------------------------------------*
;** 95	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 95	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$67	.dwtag  DW_TAG_variable, DW_AT_name("C$11"), DW_AT_symbol_name("C$11")
	.dwattr DW$67, DW_AT_type(*DW$T$63)
	.dwattr DW$67, DW_AT_location[DW_OP_reg4]
DW$68	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$68, DW_AT_type(*DW$T$35)
	.dwattr DW$68, DW_AT_location[DW_OP_reg5]
DW$69	.dwtag  DW_TAG_variable, DW_AT_name("R$1"), DW_AT_symbol_name("R$1")
	.dwattr DW$69, DW_AT_type(*DW$T$11)
	.dwattr DW$69, DW_AT_location[DW_OP_reg3]
DW$70	.dwtag  DW_TAG_variable, DW_AT_name("U$16"), DW_AT_symbol_name("U$16")
	.dwattr DW$70, DW_AT_type(*DW$T$63)
	.dwattr DW$70, DW_AT_location[DW_OP_reg4]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",95,2

           MVKL    .S1     _poll$0,A3        ; |95| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |95| 

           MVKH    .S1     _poll$0,A3        ; |95| 
||         MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |95| 

           LDW     .D1T1   *A3,A1            ; |95| 
           LDW     .D2T1   *B4,A5            ; |95| 
           NOP             3
   [!A1]   B       .S1     L20               ; |95| 
           NOP             5
           ; BRANCHCC OCCURS {L20}           ; |95| 
;** --------------------------------------------------------------------------*
;** 233	-----------------------    C$11 = (*v$1).baseAddr+8;  // [14]
;** 233	-----------------------    if ( *(volatile unsigned *)(unsigned)C$11&2u ) goto g5;  // [14]
;**  	-----------------------    U$16 = (volatile unsigned *)(unsigned)C$11;
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",233,3
           LDW     .D1T1   *+A5(12),A3       ; |233| 
           NOP             4
           ADD     .L1     8,A3,A4           ; |233| 
           LDW     .D1T1   *A4,A3            ; |233| 
           NOP             4
           AND     .L1     2,A3,A1           ; |233| 

   [!A1]   LDW     .D1T1   *A4,A3            ; |233| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L20               ; |233| 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L20}           ; |233| 
;**	-----------------------g4:
;** 233	-----------------------    if ( !(*U$16&2u) ) goto g4;  // [14]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 95
;*      Loop closing brace source line   : 233
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L17:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L18:    ; PIPED LOOP KERNEL
DW$L$_input_right_sample$4$B:

   [!A1]   B       .S2     L18               ; |233| <0,6> 
|| [!A1]   LDW     .D1T1   *A4,A3            ; |233| <1,0>  ^ 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| <1,5>  ^ 
DW$L$_input_right_sample$4$E:
;** --------------------------------------------------------------------------*
L19:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L20:    
;**	-----------------------g5:
;** 221	-----------------------    R$1 = *(volatile unsigned *)(*v$1).drrAddr;  // [11]
;** 221	-----------------------    AIC_data.uint = R$1;  // [11]
;** 97	-----------------------    return *&AIC_data;
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",221,3
           LDW     .D1T1   *+A5(16),A3       ; |221| 
           MVKL    .S2     _AIC_data,B4      ; |221| 
           MVKH    .S2     _AIC_data,B4      ; |221| 
           NOP             2
           LDW     .D1T1   *A3,A3            ; |221| 
           NOP             4
           STW     .D2T1   A3,*B4            ; |221| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",97,2
           MVKL    .S1     _AIC_data,A3      ; |97| 
           MVKH    .S1     _AIC_data,A3      ; |97| 
           LDH     .D1T1   *A3,A4            ; |97| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",98,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |98| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |98| 

DW$71	.dwtag  DW_TAG_loop
	.dwattr DW$71, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L18:1:1163403793")
	.dwattr DW$71, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$71, DW_AT_begin_line(0x5f)
	.dwattr DW$71, DW_AT_end_line(0xe9)
DW$72	.dwtag  DW_TAG_loop_range
	.dwattr DW$72, DW_AT_low_pc(DW$L$_input_right_sample$4$B)
	.dwattr DW$72, DW_AT_high_pc(DW$L$_input_right_sample$4$E)
	.dwendtag DW$71

	.dwattr DW$66, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$66, DW_AT_end_line(0x62)
	.dwattr DW$66, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$66

	.sect	".text"
	.global	_input_left_sample

DW$73	.dwtag  DW_TAG_subprogram, DW_AT_name("input_left_sample"), DW_AT_symbol_name("_input_left_sample")
	.dwattr DW$73, DW_AT_low_pc(_input_left_sample)
	.dwattr DW$73, DW_AT_high_pc(0x00)
	.dwattr DW$73, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$73, DW_AT_begin_line(0x56)
	.dwattr DW$73, DW_AT_begin_column(0x07)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",87,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _input_left_sample                                          *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A5,B4                                       *
;*   Regs Used         : A1,A3,A4,A5,B3,B4                                    *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_input_left_sample:
;** --------------------------------------------------------------------------*
;** 88	-----------------------    v$1 = DSK6713_AIC23_codecdatahandle;
;** 88	-----------------------    if ( !poll ) goto g5;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
DW$74	.dwtag  DW_TAG_variable, DW_AT_name("C$11"), DW_AT_symbol_name("C$11")
	.dwattr DW$74, DW_AT_type(*DW$T$68)
	.dwattr DW$74, DW_AT_location[DW_OP_reg20]
DW$75	.dwtag  DW_TAG_variable, DW_AT_name("C$12"), DW_AT_symbol_name("C$12")
	.dwattr DW$75, DW_AT_type(*DW$T$63)
	.dwattr DW$75, DW_AT_location[DW_OP_reg4]
DW$76	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$76, DW_AT_type(*DW$T$35)
	.dwattr DW$76, DW_AT_location[DW_OP_reg5]
DW$77	.dwtag  DW_TAG_variable, DW_AT_name("R$1"), DW_AT_symbol_name("R$1")
	.dwattr DW$77, DW_AT_type(*DW$T$11)
	.dwattr DW$77, DW_AT_location[DW_OP_reg3]
DW$78	.dwtag  DW_TAG_variable, DW_AT_name("U$16"), DW_AT_symbol_name("U$16")
	.dwattr DW$78, DW_AT_type(*DW$T$63)
	.dwattr DW$78, DW_AT_location[DW_OP_reg4]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",88,2

           MVKL    .S1     _poll$0,A3        ; |88| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |88| 

           MVKH    .S1     _poll$0,A3        ; |88| 
||         MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |88| 

           LDW     .D1T1   *A3,A1            ; |88| 
           LDW     .D2T1   *B4,A5            ; |88| 
           NOP             3
   [!A1]   B       .S1     L24               ; |88| 
           NOP             5
           ; BRANCHCC OCCURS {L24}           ; |88| 
;** --------------------------------------------------------------------------*
;** 233	-----------------------    C$12 = (*v$1).baseAddr+8;  // [14]
;** 233	-----------------------    if ( *(volatile unsigned *)(unsigned)C$12&2u ) goto g5;  // [14]
;**  	-----------------------    U$16 = (volatile unsigned *)(unsigned)C$12;
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",233,3
           LDW     .D1T1   *+A5(12),A3       ; |233| 
           NOP             4
           ADD     .L1     8,A3,A4           ; |233| 
           LDW     .D1T1   *A4,A3            ; |233| 
           NOP             4
           AND     .L1     2,A3,A1           ; |233| 

   [!A1]   LDW     .D1T1   *A4,A3            ; |233| (P) <0,0>  ^ 
|| [ A1]   B       .S1     L24               ; |233| 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| (P) <0,5>  ^ 
           ; BRANCHCC OCCURS {L24}           ; |233| 
;**	-----------------------g4:
;** 233	-----------------------    if ( !(*U$16&2u) ) goto g4;  // [14]
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*
;*      Loop source line                 : 88
;*      Loop closing brace source line   : 233
;*      Known Minimum Trip Count         : 1                    
;*      Known Max Trip Count Factor      : 1
;*      Loop Carried Dependency Bound(^) : 1
;*      Unpartitioned Resource Bound     : 1
;*      Partitioned Resource Bound(*)    : 1
;*      Resource Partition:
;*                                A-side   B-side
;*      .L units                     0        0     
;*      .S units                     0        1*    
;*      .D units                     1*       0     
;*      .M units                     0        0     
;*      .X cross paths               0        0     
;*      .T address paths             1*       0     
;*      Long read paths              0        0     
;*      Long write paths             0        0     
;*      Logical  ops (.LS)           1        0     (.L or .S unit)
;*      Addition ops (.LSD)          0        0     (.L or .S or .D unit)
;*      Bound(.L .S .LS)             1*       1*    
;*      Bound(.L .S .D .LS .LSD)     1*       1*    
;*
;*      Searching for software pipeline schedule at ...
;*         ii = 6  Schedule found with 2 iterations in parallel
;*      Done
;*
;*      Collapsed epilog stages     : 1
;*      Prolog not removed
;*      Collapsed prolog stages     : 0
;*
;*      Minimum required memory pad : 0 bytes
;*
;*      Minimum safe trip count     : 1
;*----------------------------------------------------------------------------*
L21:    ; PIPED LOOP PROLOG
;** --------------------------------------------------------------------------*
L22:    ; PIPED LOOP KERNEL
DW$L$_input_left_sample$4$B:

   [!A1]   B       .S2     L22               ; |233| <0,6> 
|| [!A1]   LDW     .D1T1   *A4,A3            ; |233| <1,0>  ^ 

           NOP             4
           AND     .L1     2,A3,A1           ; |233| <1,5>  ^ 
DW$L$_input_left_sample$4$E:
;** --------------------------------------------------------------------------*
L23:    ; PIPED LOOP EPILOG
;** --------------------------------------------------------------------------*
L24:    
;**	-----------------------g5:
;** 221	-----------------------    R$1 = *(volatile unsigned *)(*v$1).drrAddr;  // [11]
;** 221	-----------------------    C$11 = &AIC_data;  // [11]
;** 221	-----------------------    (*C$11).uint = R$1;  // [11]
;** 90	-----------------------    return *((short *)C$11+2);
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",221,3
           LDW     .D1T1   *+A5(16),A3       ; |221| 
           MVKL    .S2     _AIC_data,B4      ; |221| 
           MVKH    .S2     _AIC_data,B4      ; |221| 
           NOP             2
           LDW     .D1T1   *A3,A3            ; |221| 
           NOP             4
           STW     .D2T1   A3,*B4            ; |221| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",90,2
           LDH     .D2T1   *+B4(2),A4        ; |90| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",91,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |91| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |91| 

DW$79	.dwtag  DW_TAG_loop
	.dwattr DW$79, DW_AT_name("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.asm:L22:1:1163403793")
	.dwattr DW$79, DW_AT_begin_file("C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h")
	.dwattr DW$79, DW_AT_begin_line(0x58)
	.dwattr DW$79, DW_AT_end_line(0xe9)
DW$80	.dwtag  DW_TAG_loop_range
	.dwattr DW$80, DW_AT_low_pc(DW$L$_input_left_sample$4$B)
	.dwattr DW$80, DW_AT_high_pc(DW$L$_input_left_sample$4$E)
	.dwendtag DW$79

	.dwattr DW$73, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$73, DW_AT_end_line(0x5b)
	.dwattr DW$73, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$73

	.sect	".text"
	.global	_c6713_dsk_init

DW$81	.dwtag  DW_TAG_subprogram, DW_AT_name("c6713_dsk_init"), DW_AT_symbol_name("_c6713_dsk_init")
	.dwattr DW$81, DW_AT_low_pc(_c6713_dsk_init)
	.dwattr DW$81, DW_AT_high_pc(0x00)
	.dwattr DW$81, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$81, DW_AT_begin_line(0x05)
	.dwattr DW$81, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",6,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _c6713_dsk_init                                             *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_c6713_dsk_init:
;** --------------------------------------------------------------------------*
;** 7	-----------------------    DSK6713_init();
;** 8	-----------------------    hAIC23_handle = v$1 = DSK6713_AIC23_openCodec(0, &config);
;** 9	-----------------------    DSK6713_AIC23_setFreq(v$1, fs);
;** 10	-----------------------    v$2 = DSK6713_AIC23_codecdatahandle;
;** 272	-----------------------    base = (*v$2).baseAddr;  // [15]
;** 354	-----------------------    gie = CSR&1u;  // [4]
;** 355	-----------------------    CSR = CSR&0xfffffffeu;  // [4]
;** 356	-----------------------    x0 = AIC23CfgData.spcr;  // [4]
;** 280	-----------------------    x1 = AIC23CfgData.rcr;  // [15]
;** 281	-----------------------    x2 = AIC23CfgData.xcr;  // [15]
;** 282	-----------------------    x3 = AIC23CfgData.srgr;  // [15]
;** 283	-----------------------    x4 = AIC23CfgData.mcr;  // [15]
;** 284	-----------------------    x5 = AIC23CfgData.rcer;  // [15]
;** 285	-----------------------    x6 = AIC23CfgData.xcer;  // [15]
;** 286	-----------------------    x7 = AIC23CfgData.pcr;  // [15]
;** 288	-----------------------    base[2] = 0u;  // [15]
;** 289	-----------------------    base[3] = x1;  // [15]
;** 290	-----------------------    base[4] = x2;  // [15]
;** 291	-----------------------    base[5] = x3;  // [15]
;** 292	-----------------------    base[6] = x4;  // [15]
;** 293	-----------------------    base[7] = x5;  // [15]
;** 294	-----------------------    base[8] = x6;  // [15]
;** 295	-----------------------    base[9] = x7;  // [15]
;** 296	-----------------------    base[2] = x0;  // [15]
;** 360	-----------------------    CSR = CSR&0xfffffffeu|gie&1u;  // [5]
;** 360	-----------------------    MCBSP_start(v$2, 15u, 220u);  // [5]
;** 11	-----------------------    return;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |6| 
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$82	.dwtag  DW_TAG_variable, DW_AT_name("x7"), DW_AT_symbol_name("_x7")
	.dwattr DW$82, DW_AT_type(*DW$T$10)
	.dwattr DW$82, DW_AT_location[DW_OP_reg20]
DW$83	.dwtag  DW_TAG_variable, DW_AT_name("x6"), DW_AT_symbol_name("_x6")
	.dwattr DW$83, DW_AT_type(*DW$T$10)
	.dwattr DW$83, DW_AT_location[DW_OP_reg8]
DW$84	.dwtag  DW_TAG_variable, DW_AT_name("x5"), DW_AT_symbol_name("_x5")
	.dwattr DW$84, DW_AT_type(*DW$T$10)
	.dwattr DW$84, DW_AT_location[DW_OP_reg23]
DW$85	.dwtag  DW_TAG_variable, DW_AT_name("x4"), DW_AT_symbol_name("_x4")
	.dwattr DW$85, DW_AT_type(*DW$T$10)
	.dwattr DW$85, DW_AT_location[DW_OP_reg7]
DW$86	.dwtag  DW_TAG_variable, DW_AT_name("x3"), DW_AT_symbol_name("_x3")
	.dwattr DW$86, DW_AT_type(*DW$T$10)
	.dwattr DW$86, DW_AT_location[DW_OP_reg25]
DW$87	.dwtag  DW_TAG_variable, DW_AT_name("x2"), DW_AT_symbol_name("_x2")
	.dwattr DW$87, DW_AT_type(*DW$T$10)
	.dwattr DW$87, DW_AT_location[DW_OP_reg6]
DW$88	.dwtag  DW_TAG_variable, DW_AT_name("x1"), DW_AT_symbol_name("_x1")
	.dwattr DW$88, DW_AT_type(*DW$T$10)
	.dwattr DW$88, DW_AT_location[DW_OP_reg21]
DW$89	.dwtag  DW_TAG_variable, DW_AT_name("x0"), DW_AT_symbol_name("_x0")
	.dwattr DW$89, DW_AT_type(*DW$T$10)
	.dwattr DW$89, DW_AT_location[DW_OP_reg24]
DW$90	.dwtag  DW_TAG_variable, DW_AT_name("base"), DW_AT_symbol_name("_base")
	.dwattr DW$90, DW_AT_type(*DW$T$21)
	.dwattr DW$90, DW_AT_location[DW_OP_reg5]
DW$91	.dwtag  DW_TAG_variable, DW_AT_name("gie"), DW_AT_symbol_name("_gie")
	.dwattr DW$91, DW_AT_type(*DW$T$19)
	.dwattr DW$91, DW_AT_location[DW_OP_reg22]
DW$92	.dwtag  DW_TAG_variable, DW_AT_name("v$1"), DW_AT_symbol_name("v$1")
	.dwattr DW$92, DW_AT_type(*DW$T$10)
	.dwattr DW$92, DW_AT_location[DW_OP_reg4]
DW$93	.dwtag  DW_TAG_variable, DW_AT_name("v$2"), DW_AT_symbol_name("v$2")
	.dwattr DW$93, DW_AT_type(*DW$T$35)
	.dwattr DW$93, DW_AT_location[DW_OP_reg4]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",7,1
           CALL    .S1     _DSK6713_init     ; |7| 
           MVKL    .S2     RL0,B3            ; |7| 
           MVKH    .S2     RL0,B3            ; |7| 
           NOP             3
RL0:       ; CALL OCCURS {_DSK6713_init}     ; |7| 
;** --------------------------------------------------------------------------*
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",8,1
           CALL    .S1     _DSK6713_AIC23_openCodec ; |8| 
           MVKL    .S2     RL1,B3            ; |8| 
           MVKL    .S2     _config,B4        ; |8| 
           MVKH    .S2     RL1,B3            ; |8| 
           MVKH    .S2     _config,B4        ; |8| 
           ZERO    .L1     A4                ; |8| 
RL1:       ; CALL OCCURS {_DSK6713_AIC23_openCodec}  ; |8| 
           MVKL    .S2     _hAIC23_handle,B4 ; |8| 
           MVKH    .S2     _hAIC23_handle,B4 ; |8| 
           STW     .D2T1   A4,*B4            ; |8| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",9,1
           MVKL    .S1     _fs,A3            ; |9| 

           CALL    .S2     _DSK6713_AIC23_setFreq ; |9| 
||         MVKH    .S1     _fs,A3            ; |9| 

           LDW     .D1T2   *A3,B4            ; |9| 
           MVKL    .S2     RL2,B3            ; |9| 
           MVKH    .S2     RL2,B3            ; |9| 
           NOP             2
RL2:       ; CALL OCCURS {_DSK6713_AIC23_setFreq}  ; |9| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",10,1
           MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |10| 
           MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |10| 
           LDW     .D1T1   *A3,A4            ; |10| 
           NOP             4
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",272,20
           LDW     .D1T1   *+A4(12),A5       ; |272| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",354,10
           MVC     .S2     CSR,B4            ; |354| 
           AND     .L2     1,B4,B6           ; |354| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",355,3
           MVC     .S2     CSR,B4            ; |355| 
           AND     .L2     -2,B4,B4          ; |355| 
           MVC     .S2     B4,CSR            ; |355| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",356,3
           MVKL    .S2     _AIC23CfgData,B4  ; |356| 
           MVKH    .S2     _AIC23CfgData,B4  ; |356| 
           LDW     .D2T2   *B4,B8            ; |356| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",280,3
           MVKL    .S2     _AIC23CfgData+4,B4 ; |280| 
           MVKH    .S2     _AIC23CfgData+4,B4 ; |280| 
           LDW     .D2T2   *B4,B5            ; |280| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",281,3
           MVKL    .S1     _AIC23CfgData+8,A3 ; |281| 
           MVKH    .S1     _AIC23CfgData+8,A3 ; |281| 
           LDW     .D1T1   *A3,A6            ; |281| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",282,3
           MVKL    .S2     _AIC23CfgData+12,B4 ; |282| 
           MVKH    .S2     _AIC23CfgData+12,B4 ; |282| 
           LDW     .D2T2   *B4,B9            ; |282| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",283,3
           MVKL    .S1     _AIC23CfgData+16,A3 ; |283| 
           MVKH    .S1     _AIC23CfgData+16,A3 ; |283| 
           LDW     .D1T1   *A3,A7            ; |283| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",284,3
           MVKL    .S2     _AIC23CfgData+20,B4 ; |284| 
           MVKH    .S2     _AIC23CfgData+20,B4 ; |284| 
           LDW     .D2T2   *B4,B7            ; |284| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",285,3
           MVKL    .S1     _AIC23CfgData+24,A3 ; |285| 
           MVKH    .S1     _AIC23CfgData+24,A3 ; |285| 
           LDW     .D1T1   *A3,A8            ; |285| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",286,3
           MVKL    .S2     _AIC23CfgData+28,B4 ; |286| 
           MVKH    .S2     _AIC23CfgData+28,B4 ; |286| 
           LDW     .D2T2   *B4,B4            ; |286| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",288,3
           ZERO    .L1     A3                ; |288| 
           STW     .D1T1   A3,*+A5(8)        ; |288| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",289,3
           STW     .D1T2   B5,*+A5(12)       ; |289| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",290,3
           STW     .D1T1   A6,*+A5(16)       ; |290| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",291,3
           STW     .D1T2   B9,*+A5(20)       ; |291| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",292,3
           STW     .D1T1   A7,*+A5(24)       ; |292| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",293,3
           STW     .D1T2   B7,*+A5(28)       ; |293| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",294,3
           STW     .D1T1   A8,*+A5(32)       ; |294| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",295,3
           STW     .D1T2   B4,*+A5(36)       ; |295| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",296,3
           STW     .D1T2   B8,*+A5(8)        ; |296| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",360,3
           MVC     .S2     CSR,B4            ; |360| 

           AND     .L2     1,B6,B4           ; |360| 
||         AND     .S2     -2,B4,B5          ; |360| 

           OR      .L2     B4,B5,B4          ; |360| 
           MVC     .S2     B4,CSR            ; |360| 
           MVKL    .S1     _MCBSP_start,A3   ; |360| 
           MVKH    .S1     _MCBSP_start,A3   ; |360| 
           CALL    .S2X    A3                ; |360| 
           MVKL    .S2     RL3,B3            ; |360| 
           MVK     .S2     0xf,B4            ; |360| 
           MVK     .S1     0xdc,A6           ; |360| 
           MVKH    .S2     RL3,B3            ; |360| 
           NOP             1
RL3:       ; CALL OCCURS {_MCBSP_start}      ; |360| 
;** --------------------------------------------------------------------------*
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",11,1
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",13,1
           LDW     .D2T2   *++SP(8),B3       ; |13| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |13| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |13| 
	.dwattr DW$81, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$81, DW_AT_end_line(0x0d)
	.dwattr DW$81, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$81

	.sect	".text"
	.global	_comm_poll

DW$94	.dwtag  DW_TAG_subprogram, DW_AT_name("comm_poll"), DW_AT_symbol_name("_comm_poll")
	.dwattr DW$94, DW_AT_low_pc(_comm_poll)
	.dwattr DW$94, DW_AT_high_pc(0x00)
	.dwattr DW$94, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$94, DW_AT_begin_line(0x0f)
	.dwattr DW$94, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",16,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _comm_poll                                                  *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_comm_poll:
;** --------------------------------------------------------------------------*
;** 17	-----------------------    poll = 1u;
;** 18	-----------------------    c6713_dsk_init();
;** 18	-----------------------    return;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |16| 
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",17,2
           MVKL    .S1     _poll$0,A3        ; |17| 

           MVKH    .S1     _poll$0,A3        ; |17| 
||         MVK     .S2     1,B4              ; |17| 

           STW     .D1T2   B4,*A3            ; |17| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",18,5
           CALL    .S1     _c6713_dsk_init   ; |18| 
           MVKL    .S2     RL4,B3            ; |18| 
           MVKH    .S2     RL4,B3            ; |18| 
           NOP             3
RL4:       ; CALL OCCURS {_c6713_dsk_init}   ; |18| 
;** --------------------------------------------------------------------------*
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",19,1
           LDW     .D2T2   *++SP(8),B3       ; |19| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |19| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |19| 
	.dwattr DW$94, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$94, DW_AT_end_line(0x13)
	.dwattr DW$94, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$94

	.sect	".text"
	.global	_comm_intr

DW$95	.dwtag  DW_TAG_subprogram, DW_AT_name("comm_intr"), DW_AT_symbol_name("_comm_intr")
	.dwattr DW$95, DW_AT_low_pc(_comm_intr)
	.dwattr DW$95, DW_AT_high_pc(0x00)
	.dwattr DW$95, DW_AT_begin_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$95, DW_AT_begin_line(0x15)
	.dwattr DW$95, DW_AT_begin_column(0x06)
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",22,1

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _comm_intr                                                  *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o3) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
_comm_intr:
;** --------------------------------------------------------------------------*
;** 23	-----------------------    poll = 0u;
;** 354	-----------------------    CSR;  // [4]
;** 355	-----------------------    CSR = CSR&0xfffffffeu;  // [4]
;** 356	-----------------------    c6713_dsk_init();  // [4]
;** 213	-----------------------    CODECEventId = (*DSK6713_AIC23_codecdatahandle).xmtEventId;  // [10]
;** 213	-----------------------    IRQ_setVecs((void *)&vectors);  // [10]
;** 28	-----------------------    IRQ_map(CODECEventId, 11u);
;** 364	-----------------------    C$1 = _IRQ_eventTable[CODECEventId];  // [6]
;** 364	-----------------------    IER &= ~C$1;  // [6]
;** 365	-----------------------    ICR = C$1;  // [6]
;** 365	-----------------------    CSR = CSR|1u;  // [6]
;** 350	-----------------------    IER |= 2u;  // [3]
;** 320	-----------------------    IER |= C$1;  // [2]
;** 320	-----------------------    output_sample(0);  // [2]
;** 33	-----------------------    return;
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |22| 
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$96	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$96, DW_AT_type(*DW$T$11)
	.dwattr DW$96, DW_AT_location[DW_OP_reg3]
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",23,3
           MVKL    .S2     _poll$0,B4        ; |23| 

           MVKH    .S2     _poll$0,B4        ; |23| 
||         ZERO    .L2     B5                ; |23| 

           STW     .D2T2   B5,*B4            ; |23| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",354,10
           MVC     .S2     CSR,B4            ; |354| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",355,3
           MVC     .S2     CSR,B4            ; |355| 
           AND     .L2     -2,B4,B4          ; |355| 
           MVC     .S2     B4,CSR            ; |355| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",356,3
           CALL    .S1     _c6713_dsk_init   ; |356| 
           MVKL    .S2     RL5,B3            ; |356| 
           MVKH    .S2     RL5,B3            ; |356| 
           NOP             3
RL5:       ; CALL OCCURS {_c6713_dsk_init}   ; |356| 
;** --------------------------------------------------------------------------*
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_mcbsp.h",213,3
           MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |213| 
           MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |213| 
           LDW     .D2T2   *B4,B4            ; |213| 
           MVKL    .S2     _CODECEventId$0,B6 ; |213| 
           MVKL    .S2     RL6,B3            ; |213| 
           MVKH    .S2     _CODECEventId$0,B6 ; |213| 
           MVKL    .S1     _vectors,A4       ; |213| 

           MVKL    .S2     _IRQ_setVecs,B4   ; |213| 
||         LDW     .D2T2   *+B4(4),B5        ; |213| 

           MVKH    .S2     _IRQ_setVecs,B4   ; |213| 
           CALL    .S2     B4                ; |213| 
           MVKH    .S2     RL6,B3            ; |213| 
           MVKH    .S1     _vectors,A4       ; |213| 
           NOP             2
           STW     .D2T2   B5,*B6            ; |213| 
RL6:       ; CALL OCCURS {_IRQ_setVecs}      ; |213| 
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",28,4
           MVKL    .S1     _IRQ_map,A3       ; |28| 
           MVKL    .S1     _CODECEventId$0,A4 ; |28| 
           MVKH    .S1     _IRQ_map,A3       ; |28| 

           CALL    .S2X    A3                ; |28| 
||         MVKH    .S1     _CODECEventId$0,A4 ; |28| 

           LDW     .D1T1   *A4,A4            ; |28| 
           MVKL    .S2     RL7,B3            ; |28| 
           MVK     .S2     0xb,B4            ; |28| 
           MVKH    .S2     RL7,B3            ; |28| 
           NOP             1
RL7:       ; CALL OCCURS {_IRQ_map}          ; |28| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",364,3
           MVKL    .S1     _CODECEventId$0,A3 ; |364| 
           MVKH    .S1     _CODECEventId$0,A3 ; |364| 
           LDW     .D1T1   *A3,A4            ; |364| 
           MVKL    .S1     __IRQ_eventTable,A3 ; |364| 
           MVKH    .S1     __IRQ_eventTable,A3 ; |364| 
           NOP             2
           LDW     .D1T1   *+A3[A4],A3       ; |364| 
           NOP             3
           MVC     .S2     IER,B4            ; |364| 
           NOT     .L1     A3,A4             ; |364| 
           AND     .L2X    A4,B4,B4          ; |364| 
           MVC     .S2     B4,IER            ; |364| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",365,3
           MVC     .S2X    A3,ICR            ; |365| 
           MVC     .S2     CSR,B4            ; |365| 
           OR      .L2     1,B4,B4           ; |365| 
           MVC     .S2     B4,CSR            ; |365| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",350,3
           MVC     .S2     IER,B4            ; |350| 
           OR      .L2     2,B4,B4           ; |350| 
           MVC     .S2     B4,IER            ; |350| 
	.dwpsn	"C:/CCStudio_v3.1/C6000/csl/include/csl_irq.h",320,3
           MVC     .S2     IER,B4            ; |320| 
           OR      .L2X    A3,B4,B4          ; |320| 
           MVC     .S2     B4,IER            ; |320| 
           CALL    .S1     _output_sample    ; |320| 
           MVKL    .S2     RL8,B3            ; |320| 
           MVKH    .S2     RL8,B3            ; |320| 
           ZERO    .L1     A4                ; |320| 
           NOP             2
RL8:       ; CALL OCCURS {_output_sample}    ; |320| 
;** --------------------------------------------------------------------------*
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",33,2
	.dwpsn	"D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c",34,1
           LDW     .D2T2   *++SP(8),B3       ; |34| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |34| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |34| 
	.dwattr DW$95, DW_AT_end_file("D:\lc2\practiques_lc2_noves\practiques_que_funcionen\practica1\prac1_int\c6713dskinit.c")
	.dwattr DW$95, DW_AT_end_line(0x22)
	.dwattr DW$95, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$95

;; Inlined function references:
;; [  2] IRQ_enable
;; [  3] IRQ_globalEnable
;; [  4] IRQ_globalDisable
;; [  5] IRQ_globalRestore
;; [  6] IRQ_reset
;; [ 10] MCBSP_getXmtEventId
;; [ 11] MCBSP_read
;; [ 12] MCBSP_write
;; [ 13] MCBSP_xrdy
;; [ 14] MCBSP_rrdy
;; [ 15] MCBSP_config
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_IRQ_map
	.global	_IRQ_setVecs
	.global	_DSK6713_init
	.global	_MCBSP_start
	.global	_DSK6713_AIC23_openCodec
	.global	_DSK6713_AIC23_setFreq
	.global	_vectors
	.global	__IRQ_eventTable
	.global	_DSK6713_AIC23_codecdatahandle
	.global	_fs

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr DW$T$3, DW_AT_address_class(0x20)

DW$T$28	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$3)
	.dwattr DW$T$28, DW_AT_language(DW_LANG_C)
DW$97	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$3)
	.dwendtag DW$T$28


DW$T$30	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$30, DW_AT_language(DW_LANG_C)
DW$98	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$99	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$30


DW$T$32	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$32, DW_AT_language(DW_LANG_C)
DW$100	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$32


DW$T$33	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$33, DW_AT_language(DW_LANG_C)

DW$T$37	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$37, DW_AT_language(DW_LANG_C)
DW$101	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$36)
DW$102	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$103	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$37


DW$T$39	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$39, DW_AT_language(DW_LANG_C)
DW$104	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$36)
DW$105	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$39


DW$T$42	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$42, DW_AT_language(DW_LANG_C)
DW$106	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$36)
DW$107	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$41)
	.dwendtag DW$T$42


DW$T$44	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$44, DW_AT_language(DW_LANG_C)
DW$108	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$43)
DW$109	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$44


DW$T$46	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$46, DW_AT_language(DW_LANG_C)
DW$110	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
	.dwendtag DW$T$46


DW$T$48	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$48, DW_AT_language(DW_LANG_C)
DW$111	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$8)
	.dwendtag DW$T$48

DW$T$8	.dwtag  DW_TAG_base_type, DW_AT_name("short")
	.dwattr DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$8, DW_AT_byte_size(0x02)

DW$T$49	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$8)
	.dwattr DW$T$49, DW_AT_language(DW_LANG_C)
DW$T$51	.dwtag  DW_TAG_const_type
	.dwattr DW$T$51, DW_AT_type(*DW$T$8)
DW$T$10	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$10, DW_AT_byte_size(0x04)
DW$T$43	.dwtag  DW_TAG_typedef, DW_AT_name("DSK6713_AIC23_CodecHandle"), DW_AT_type(*DW$T$10)
	.dwattr DW$T$43, DW_AT_language(DW_LANG_C)

DW$T$54	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$43)
	.dwattr DW$T$54, DW_AT_language(DW_LANG_C)
DW$112	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$113	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$53)
	.dwendtag DW$T$54

DW$T$57	.dwtag  DW_TAG_const_type
	.dwattr DW$T$57, DW_AT_type(*DW$T$10)
DW$T$11	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DW$T$11, DW_AT_byte_size(0x04)
DW$T$19	.dwtag  DW_TAG_typedef, DW_AT_name("Uint32"), DW_AT_type(*DW$T$11)
	.dwattr DW$T$19, DW_AT_language(DW_LANG_C)
DW$T$21	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$20)
	.dwattr DW$T$21, DW_AT_address_class(0x20)

DW$T$59	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$19)
	.dwattr DW$T$59, DW_AT_language(DW_LANG_C)

DW$T$60	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$19)
	.dwattr DW$T$60, DW_AT_language(DW_LANG_C)
DW$114	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$36)
	.dwendtag DW$T$60


DW$T$61	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$19)
	.dwattr DW$T$61, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$61, DW_AT_byte_size(0x84)
DW$115	.dwtag  DW_TAG_subrange_type
	.dwattr DW$115, DW_AT_upper_bound(0x20)
	.dwendtag DW$T$61

DW$T$62	.dwtag  DW_TAG_volatile_type
	.dwattr DW$T$62, DW_AT_type(*DW$T$11)
DW$T$63	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$62)
	.dwattr DW$T$63, DW_AT_address_class(0x20)
DW$T$35	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$22)
	.dwattr DW$T$35, DW_AT_address_class(0x20)
DW$T$36	.dwtag  DW_TAG_typedef, DW_AT_name("MCBSP_Handle"), DW_AT_type(*DW$T$35)
	.dwattr DW$T$36, DW_AT_language(DW_LANG_C)
DW$T$40	.dwtag  DW_TAG_typedef, DW_AT_name("MCBSP_Config"), DW_AT_type(*DW$T$23)
	.dwattr DW$T$40, DW_AT_language(DW_LANG_C)
DW$T$41	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$40)
	.dwattr DW$T$41, DW_AT_address_class(0x20)
DW$T$52	.dwtag  DW_TAG_typedef, DW_AT_name("DSK6713_AIC23_Config"), DW_AT_type(*DW$T$25)
	.dwattr DW$T$52, DW_AT_language(DW_LANG_C)
DW$T$53	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$52)
	.dwattr DW$T$53, DW_AT_address_class(0x20)

DW$T$27	.dwtag  DW_TAG_union_type
	.dwattr DW$T$27, DW_AT_byte_size(0x04)
DW$116	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$116, DW_AT_name("uint"), DW_AT_symbol_name("_uint")
	.dwattr DW$116, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$116, DW_AT_accessibility(DW_ACCESS_public)
DW$117	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$26)
	.dwattr DW$117, DW_AT_name("channel"), DW_AT_symbol_name("_channel")
	.dwattr DW$117, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$117, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$27

DW$T$68	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$27)
	.dwattr DW$T$68, DW_AT_address_class(0x20)

DW$T$26	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$8)
	.dwattr DW$T$26, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$26, DW_AT_byte_size(0x04)
DW$118	.dwtag  DW_TAG_subrange_type
	.dwattr DW$118, DW_AT_upper_bound(0x01)
	.dwendtag DW$T$26

DW$T$20	.dwtag  DW_TAG_volatile_type
	.dwattr DW$T$20, DW_AT_type(*DW$T$19)

DW$T$22	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$22, DW_AT_byte_size(0x18)
DW$119	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$119, DW_AT_name("allocated"), DW_AT_symbol_name("_allocated")
	.dwattr DW$119, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$119, DW_AT_accessibility(DW_ACCESS_public)
DW$120	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$120, DW_AT_name("xmtEventId"), DW_AT_symbol_name("_xmtEventId")
	.dwattr DW$120, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$120, DW_AT_accessibility(DW_ACCESS_public)
DW$121	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$121, DW_AT_name("rcvEventId"), DW_AT_symbol_name("_rcvEventId")
	.dwattr DW$121, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$121, DW_AT_accessibility(DW_ACCESS_public)
DW$122	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$21)
	.dwattr DW$122, DW_AT_name("baseAddr"), DW_AT_symbol_name("_baseAddr")
	.dwattr DW$122, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$122, DW_AT_accessibility(DW_ACCESS_public)
DW$123	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$123, DW_AT_name("drrAddr"), DW_AT_symbol_name("_drrAddr")
	.dwattr DW$123, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$123, DW_AT_accessibility(DW_ACCESS_public)
DW$124	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$124, DW_AT_name("dxrAddr"), DW_AT_symbol_name("_dxrAddr")
	.dwattr DW$124, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$124, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$22


DW$T$23	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$23, DW_AT_byte_size(0x20)
DW$125	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$125, DW_AT_name("spcr"), DW_AT_symbol_name("_spcr")
	.dwattr DW$125, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$125, DW_AT_accessibility(DW_ACCESS_public)
DW$126	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$126, DW_AT_name("rcr"), DW_AT_symbol_name("_rcr")
	.dwattr DW$126, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$126, DW_AT_accessibility(DW_ACCESS_public)
DW$127	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$127, DW_AT_name("xcr"), DW_AT_symbol_name("_xcr")
	.dwattr DW$127, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$127, DW_AT_accessibility(DW_ACCESS_public)
DW$128	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$128, DW_AT_name("srgr"), DW_AT_symbol_name("_srgr")
	.dwattr DW$128, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$128, DW_AT_accessibility(DW_ACCESS_public)
DW$129	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$129, DW_AT_name("mcr"), DW_AT_symbol_name("_mcr")
	.dwattr DW$129, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$129, DW_AT_accessibility(DW_ACCESS_public)
DW$130	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$130, DW_AT_name("rcer"), DW_AT_symbol_name("_rcer")
	.dwattr DW$130, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$130, DW_AT_accessibility(DW_ACCESS_public)
DW$131	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$131, DW_AT_name("xcer"), DW_AT_symbol_name("_xcer")
	.dwattr DW$131, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$131, DW_AT_accessibility(DW_ACCESS_public)
DW$132	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$132, DW_AT_name("pcr"), DW_AT_symbol_name("_pcr")
	.dwattr DW$132, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$132, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$23


DW$T$25	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$25, DW_AT_name("DSK6713_AIC23_Config")
	.dwattr DW$T$25, DW_AT_byte_size(0x28)
DW$133	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$24)
	.dwattr DW$133, DW_AT_name("regs"), DW_AT_symbol_name("_regs")
	.dwattr DW$133, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$133, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$25


DW$T$24	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$10)
	.dwattr DW$T$24, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$24, DW_AT_byte_size(0x28)
DW$134	.dwtag  DW_TAG_subrange_type
	.dwattr DW$134, DW_AT_upper_bound(0x09)
	.dwendtag DW$T$24


	.dwattr DW$81, DW_AT_external(0x01)
	.dwattr DW$95, DW_AT_external(0x01)
	.dwattr DW$94, DW_AT_external(0x01)
	.dwattr DW$73, DW_AT_external(0x01)
	.dwattr DW$73, DW_AT_type(*DW$T$8)
	.dwattr DW$66, DW_AT_external(0x01)
	.dwattr DW$66, DW_AT_type(*DW$T$8)
	.dwattr DW$57, DW_AT_external(0x01)
	.dwattr DW$57, DW_AT_type(*DW$T$19)
	.dwattr DW$47, DW_AT_external(0x01)
	.dwattr DW$38, DW_AT_external(0x01)
	.dwattr DW$27, DW_AT_external(0x01)
	.dwattr DW$CU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

DW$CIE	.dwcie 1, 126
	.dwcfa	0x0c, 31, 0
	.dwcfa	0x07, 0
	.dwcfa	0x07, 1
	.dwcfa	0x07, 2
	.dwcfa	0x07, 3
	.dwcfa	0x07, 4
	.dwcfa	0x07, 5
	.dwcfa	0x07, 6
	.dwcfa	0x07, 7
	.dwcfa	0x07, 8
	.dwcfa	0x07, 9
	.dwcfa	0x08, 10
	.dwcfa	0x08, 11
	.dwcfa	0x08, 12
	.dwcfa	0x08, 13
	.dwcfa	0x08, 14
	.dwcfa	0x08, 15
	.dwcfa	0x07, 16
	.dwcfa	0x07, 17
	.dwcfa	0x07, 18
	.dwcfa	0x07, 19
	.dwcfa	0x07, 20
	.dwcfa	0x07, 21
	.dwcfa	0x07, 22
	.dwcfa	0x07, 23
	.dwcfa	0x07, 24
	.dwcfa	0x07, 25
	.dwcfa	0x08, 26
	.dwcfa	0x08, 27
	.dwcfa	0x08, 28
	.dwcfa	0x08, 29
	.dwcfa	0x08, 30
	.dwcfa	0x08, 31
	.dwcfa	0x08, 32
	.dwcfa	0x07, 33
	.dwcfa	0x07, 34
	.dwcfa	0x07, 35
	.dwcfa	0x07, 36
	.dwcfa	0x07, 37
	.dwcfa	0x07, 38
	.dwcfa	0x07, 39
	.dwcfa	0x07, 40
	.dwcfa	0x07, 41
	.dwcfa	0x07, 42
	.dwcfa	0x07, 43
	.dwcfa	0x07, 44
	.dwcfa	0x07, 45
	.dwcfa	0x07, 46
	.dwcfa	0x07, 47
	.dwcfa	0x07, 48
	.dwcfa	0x07, 49
	.dwcfa	0x07, 50
	.dwcfa	0x07, 51
	.dwcfa	0x07, 52
	.dwcfa	0x07, 53
	.dwcfa	0x07, 54
	.dwcfa	0x07, 55
	.dwcfa	0x07, 56
	.dwcfa	0x07, 57
	.dwcfa	0x07, 58
	.dwcfa	0x07, 59
	.dwcfa	0x07, 60
	.dwcfa	0x07, 61
	.dwcfa	0x07, 62
	.dwcfa	0x07, 63
	.dwcfa	0x07, 64
	.dwcfa	0x07, 65
	.dwcfa	0x07, 66
	.dwcfa	0x07, 67
	.dwcfa	0x07, 68
	.dwcfa	0x07, 69
	.dwcfa	0x07, 70
	.dwcfa	0x07, 71
	.dwcfa	0x07, 72
	.dwcfa	0x07, 73
	.dwcfa	0x07, 74
	.dwcfa	0x07, 75
	.dwcfa	0x07, 76
	.dwcfa	0x07, 77
	.dwcfa	0x07, 78
	.dwcfa	0x07, 79
	.dwcfa	0x07, 80
	.dwcfa	0x07, 81
	.dwcfa	0x07, 82
	.dwcfa	0x07, 83
	.dwcfa	0x07, 84
	.dwcfa	0x07, 85
	.dwcfa	0x07, 86
	.dwcfa	0x07, 87
	.dwcfa	0x07, 88
	.dwcfa	0x07, 89
	.dwcfa	0x07, 90
	.dwcfa	0x07, 91
	.dwcfa	0x07, 92
	.dwcfa	0x07, 93
	.dwcfa	0x07, 94
	.dwcfa	0x07, 95
	.dwcfa	0x07, 96
	.dwcfa	0x07, 97
	.dwcfa	0x07, 98
	.dwcfa	0x07, 99
	.dwcfa	0x07, 100
	.dwcfa	0x07, 101
	.dwcfa	0x07, 102
	.dwcfa	0x07, 103
	.dwcfa	0x07, 104
	.dwcfa	0x07, 105
	.dwcfa	0x07, 106
	.dwcfa	0x07, 107
	.dwcfa	0x07, 108
	.dwcfa	0x07, 109
	.dwcfa	0x07, 110
	.dwcfa	0x07, 111
	.dwcfa	0x07, 112
	.dwcfa	0x07, 113
	.dwcfa	0x07, 114
	.dwcfa	0x07, 115
	.dwcfa	0x07, 116
	.dwcfa	0x07, 117
	.dwcfa	0x07, 118
	.dwcfa	0x07, 119
	.dwcfa	0x07, 120
	.dwcfa	0x07, 121
	.dwcfa	0x07, 122
	.dwcfa	0x07, 123
	.dwcfa	0x07, 124
	.dwcfa	0x07, 125
	.dwcfa	0x07, 126

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("A0")
	.dwattr DW$135, DW_AT_location[DW_OP_reg0]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$136, DW_AT_location[DW_OP_reg1]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$137, DW_AT_location[DW_OP_reg2]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$138, DW_AT_location[DW_OP_reg3]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$139, DW_AT_location[DW_OP_reg4]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("A5")
	.dwattr DW$140, DW_AT_location[DW_OP_reg5]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("A6")
	.dwattr DW$141, DW_AT_location[DW_OP_reg6]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("A7")
	.dwattr DW$142, DW_AT_location[DW_OP_reg7]
DW$143	.dwtag  DW_TAG_assign_register, DW_AT_name("A8")
	.dwattr DW$143, DW_AT_location[DW_OP_reg8]
DW$144	.dwtag  DW_TAG_assign_register, DW_AT_name("A9")
	.dwattr DW$144, DW_AT_location[DW_OP_reg9]
DW$145	.dwtag  DW_TAG_assign_register, DW_AT_name("A10")
	.dwattr DW$145, DW_AT_location[DW_OP_reg10]
DW$146	.dwtag  DW_TAG_assign_register, DW_AT_name("A11")
	.dwattr DW$146, DW_AT_location[DW_OP_reg11]
DW$147	.dwtag  DW_TAG_assign_register, DW_AT_name("A12")
	.dwattr DW$147, DW_AT_location[DW_OP_reg12]
DW$148	.dwtag  DW_TAG_assign_register, DW_AT_name("A13")
	.dwattr DW$148, DW_AT_location[DW_OP_reg13]
DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("A14")
	.dwattr DW$149, DW_AT_location[DW_OP_reg14]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("A15")
	.dwattr DW$150, DW_AT_location[DW_OP_reg15]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("B0")
	.dwattr DW$151, DW_AT_location[DW_OP_reg16]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("B1")
	.dwattr DW$152, DW_AT_location[DW_OP_reg17]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("B2")
	.dwattr DW$153, DW_AT_location[DW_OP_reg18]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("B3")
	.dwattr DW$154, DW_AT_location[DW_OP_reg19]
DW$155	.dwtag  DW_TAG_assign_register, DW_AT_name("B4")
	.dwattr DW$155, DW_AT_location[DW_OP_reg20]
DW$156	.dwtag  DW_TAG_assign_register, DW_AT_name("B5")
	.dwattr DW$156, DW_AT_location[DW_OP_reg21]
DW$157	.dwtag  DW_TAG_assign_register, DW_AT_name("B6")
	.dwattr DW$157, DW_AT_location[DW_OP_reg22]
DW$158	.dwtag  DW_TAG_assign_register, DW_AT_name("B7")
	.dwattr DW$158, DW_AT_location[DW_OP_reg23]
DW$159	.dwtag  DW_TAG_assign_register, DW_AT_name("B8")
	.dwattr DW$159, DW_AT_location[DW_OP_reg24]
DW$160	.dwtag  DW_TAG_assign_register, DW_AT_name("B9")
	.dwattr DW$160, DW_AT_location[DW_OP_reg25]
DW$161	.dwtag  DW_TAG_assign_register, DW_AT_name("B10")
	.dwattr DW$161, DW_AT_location[DW_OP_reg26]
DW$162	.dwtag  DW_TAG_assign_register, DW_AT_name("B11")
	.dwattr DW$162, DW_AT_location[DW_OP_reg27]
DW$163	.dwtag  DW_TAG_assign_register, DW_AT_name("B12")
	.dwattr DW$163, DW_AT_location[DW_OP_reg28]
DW$164	.dwtag  DW_TAG_assign_register, DW_AT_name("B13")
	.dwattr DW$164, DW_AT_location[DW_OP_reg29]
DW$165	.dwtag  DW_TAG_assign_register, DW_AT_name("DP")
	.dwattr DW$165, DW_AT_location[DW_OP_reg30]
DW$166	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$166, DW_AT_location[DW_OP_reg31]
DW$167	.dwtag  DW_TAG_assign_register, DW_AT_name("FP")
	.dwattr DW$167, DW_AT_location[DW_OP_regx 0x20]
DW$168	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$168, DW_AT_location[DW_OP_regx 0x21]
DW$169	.dwtag  DW_TAG_assign_register, DW_AT_name("IRP")
	.dwattr DW$169, DW_AT_location[DW_OP_regx 0x22]
DW$170	.dwtag  DW_TAG_assign_register, DW_AT_name("IFR")
	.dwattr DW$170, DW_AT_location[DW_OP_regx 0x23]
DW$171	.dwtag  DW_TAG_assign_register, DW_AT_name("NRP")
	.dwattr DW$171, DW_AT_location[DW_OP_regx 0x24]
DW$172	.dwtag  DW_TAG_assign_register, DW_AT_name("A16")
	.dwattr DW$172, DW_AT_location[DW_OP_regx 0x25]
DW$173	.dwtag  DW_TAG_assign_register, DW_AT_name("A17")
	.dwattr DW$173, DW_AT_location[DW_OP_regx 0x26]
DW$174	.dwtag  DW_TAG_assign_register, DW_AT_name("A18")
	.dwattr DW$174, DW_AT_location[DW_OP_regx 0x27]
DW$175	.dwtag  DW_TAG_assign_register, DW_AT_name("A19")
	.dwattr DW$175, DW_AT_location[DW_OP_regx 0x28]
DW$176	.dwtag  DW_TAG_assign_register, DW_AT_name("A20")
	.dwattr DW$176, DW_AT_location[DW_OP_regx 0x29]
DW$177	.dwtag  DW_TAG_assign_register, DW_AT_name("A21")
	.dwattr DW$177, DW_AT_location[DW_OP_regx 0x2a]
DW$178	.dwtag  DW_TAG_assign_register, DW_AT_name("A22")
	.dwattr DW$178, DW_AT_location[DW_OP_regx 0x2b]
DW$179	.dwtag  DW_TAG_assign_register, DW_AT_name("A23")
	.dwattr DW$179, DW_AT_location[DW_OP_regx 0x2c]
DW$180	.dwtag  DW_TAG_assign_register, DW_AT_name("A24")
	.dwattr DW$180, DW_AT_location[DW_OP_regx 0x2d]
DW$181	.dwtag  DW_TAG_assign_register, DW_AT_name("A25")
	.dwattr DW$181, DW_AT_location[DW_OP_regx 0x2e]
DW$182	.dwtag  DW_TAG_assign_register, DW_AT_name("A26")
	.dwattr DW$182, DW_AT_location[DW_OP_regx 0x2f]
DW$183	.dwtag  DW_TAG_assign_register, DW_AT_name("A27")
	.dwattr DW$183, DW_AT_location[DW_OP_regx 0x30]
DW$184	.dwtag  DW_TAG_assign_register, DW_AT_name("A28")
	.dwattr DW$184, DW_AT_location[DW_OP_regx 0x31]
DW$185	.dwtag  DW_TAG_assign_register, DW_AT_name("A29")
	.dwattr DW$185, DW_AT_location[DW_OP_regx 0x32]
DW$186	.dwtag  DW_TAG_assign_register, DW_AT_name("A30")
	.dwattr DW$186, DW_AT_location[DW_OP_regx 0x33]
DW$187	.dwtag  DW_TAG_assign_register, DW_AT_name("A31")
	.dwattr DW$187, DW_AT_location[DW_OP_regx 0x34]
DW$188	.dwtag  DW_TAG_assign_register, DW_AT_name("B16")
	.dwattr DW$188, DW_AT_location[DW_OP_regx 0x35]
DW$189	.dwtag  DW_TAG_assign_register, DW_AT_name("B17")
	.dwattr DW$189, DW_AT_location[DW_OP_regx 0x36]
DW$190	.dwtag  DW_TAG_assign_register, DW_AT_name("B18")
	.dwattr DW$190, DW_AT_location[DW_OP_regx 0x37]
DW$191	.dwtag  DW_TAG_assign_register, DW_AT_name("B19")
	.dwattr DW$191, DW_AT_location[DW_OP_regx 0x38]
DW$192	.dwtag  DW_TAG_assign_register, DW_AT_name("B20")
	.dwattr DW$192, DW_AT_location[DW_OP_regx 0x39]
DW$193	.dwtag  DW_TAG_assign_register, DW_AT_name("B21")
	.dwattr DW$193, DW_AT_location[DW_OP_regx 0x3a]
DW$194	.dwtag  DW_TAG_assign_register, DW_AT_name("B22")
	.dwattr DW$194, DW_AT_location[DW_OP_regx 0x3b]
DW$195	.dwtag  DW_TAG_assign_register, DW_AT_name("B23")
	.dwattr DW$195, DW_AT_location[DW_OP_regx 0x3c]
DW$196	.dwtag  DW_TAG_assign_register, DW_AT_name("B24")
	.dwattr DW$196, DW_AT_location[DW_OP_regx 0x3d]
DW$197	.dwtag  DW_TAG_assign_register, DW_AT_name("B25")
	.dwattr DW$197, DW_AT_location[DW_OP_regx 0x3e]
DW$198	.dwtag  DW_TAG_assign_register, DW_AT_name("B26")
	.dwattr DW$198, DW_AT_location[DW_OP_regx 0x3f]
DW$199	.dwtag  DW_TAG_assign_register, DW_AT_name("B27")
	.dwattr DW$199, DW_AT_location[DW_OP_regx 0x40]
DW$200	.dwtag  DW_TAG_assign_register, DW_AT_name("B28")
	.dwattr DW$200, DW_AT_location[DW_OP_regx 0x41]
DW$201	.dwtag  DW_TAG_assign_register, DW_AT_name("B29")
	.dwattr DW$201, DW_AT_location[DW_OP_regx 0x42]
DW$202	.dwtag  DW_TAG_assign_register, DW_AT_name("B30")
	.dwattr DW$202, DW_AT_location[DW_OP_regx 0x43]
DW$203	.dwtag  DW_TAG_assign_register, DW_AT_name("B31")
	.dwattr DW$203, DW_AT_location[DW_OP_regx 0x44]
DW$204	.dwtag  DW_TAG_assign_register, DW_AT_name("AMR")
	.dwattr DW$204, DW_AT_location[DW_OP_regx 0x45]
DW$205	.dwtag  DW_TAG_assign_register, DW_AT_name("CSR")
	.dwattr DW$205, DW_AT_location[DW_OP_regx 0x46]
DW$206	.dwtag  DW_TAG_assign_register, DW_AT_name("ISR")
	.dwattr DW$206, DW_AT_location[DW_OP_regx 0x47]
DW$207	.dwtag  DW_TAG_assign_register, DW_AT_name("ICR")
	.dwattr DW$207, DW_AT_location[DW_OP_regx 0x48]
DW$208	.dwtag  DW_TAG_assign_register, DW_AT_name("IER")
	.dwattr DW$208, DW_AT_location[DW_OP_regx 0x49]
DW$209	.dwtag  DW_TAG_assign_register, DW_AT_name("ISTP")
	.dwattr DW$209, DW_AT_location[DW_OP_regx 0x4a]
DW$210	.dwtag  DW_TAG_assign_register, DW_AT_name("IN")
	.dwattr DW$210, DW_AT_location[DW_OP_regx 0x4b]
DW$211	.dwtag  DW_TAG_assign_register, DW_AT_name("OUT")
	.dwattr DW$211, DW_AT_location[DW_OP_regx 0x4c]
DW$212	.dwtag  DW_TAG_assign_register, DW_AT_name("ACR")
	.dwattr DW$212, DW_AT_location[DW_OP_regx 0x4d]
DW$213	.dwtag  DW_TAG_assign_register, DW_AT_name("ADR")
	.dwattr DW$213, DW_AT_location[DW_OP_regx 0x4e]
DW$214	.dwtag  DW_TAG_assign_register, DW_AT_name("FADCR")
	.dwattr DW$214, DW_AT_location[DW_OP_regx 0x4f]
DW$215	.dwtag  DW_TAG_assign_register, DW_AT_name("FAUCR")
	.dwattr DW$215, DW_AT_location[DW_OP_regx 0x50]
DW$216	.dwtag  DW_TAG_assign_register, DW_AT_name("FMCR")
	.dwattr DW$216, DW_AT_location[DW_OP_regx 0x51]
DW$217	.dwtag  DW_TAG_assign_register, DW_AT_name("GFPGFR")
	.dwattr DW$217, DW_AT_location[DW_OP_regx 0x52]
DW$218	.dwtag  DW_TAG_assign_register, DW_AT_name("DIER")
	.dwattr DW$218, DW_AT_location[DW_OP_regx 0x53]
DW$219	.dwtag  DW_TAG_assign_register, DW_AT_name("REP")
	.dwattr DW$219, DW_AT_location[DW_OP_regx 0x54]
DW$220	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCL")
	.dwattr DW$220, DW_AT_location[DW_OP_regx 0x55]
DW$221	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCH")
	.dwattr DW$221, DW_AT_location[DW_OP_regx 0x56]
DW$222	.dwtag  DW_TAG_assign_register, DW_AT_name("ARP")
	.dwattr DW$222, DW_AT_location[DW_OP_regx 0x57]
DW$223	.dwtag  DW_TAG_assign_register, DW_AT_name("ILC")
	.dwattr DW$223, DW_AT_location[DW_OP_regx 0x58]
DW$224	.dwtag  DW_TAG_assign_register, DW_AT_name("RILC")
	.dwattr DW$224, DW_AT_location[DW_OP_regx 0x59]
DW$225	.dwtag  DW_TAG_assign_register, DW_AT_name("DNUM")
	.dwattr DW$225, DW_AT_location[DW_OP_regx 0x5a]
DW$226	.dwtag  DW_TAG_assign_register, DW_AT_name("SSR")
	.dwattr DW$226, DW_AT_location[DW_OP_regx 0x5b]
DW$227	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYA")
	.dwattr DW$227, DW_AT_location[DW_OP_regx 0x5c]
DW$228	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYB")
	.dwattr DW$228, DW_AT_location[DW_OP_regx 0x5d]
DW$229	.dwtag  DW_TAG_assign_register, DW_AT_name("TSR")
	.dwattr DW$229, DW_AT_location[DW_OP_regx 0x5e]
DW$230	.dwtag  DW_TAG_assign_register, DW_AT_name("ITSR")
	.dwattr DW$230, DW_AT_location[DW_OP_regx 0x5f]
DW$231	.dwtag  DW_TAG_assign_register, DW_AT_name("NTSR")
	.dwattr DW$231, DW_AT_location[DW_OP_regx 0x60]
DW$232	.dwtag  DW_TAG_assign_register, DW_AT_name("EFR")
	.dwattr DW$232, DW_AT_location[DW_OP_regx 0x61]
DW$233	.dwtag  DW_TAG_assign_register, DW_AT_name("ECR")
	.dwattr DW$233, DW_AT_location[DW_OP_regx 0x62]
DW$234	.dwtag  DW_TAG_assign_register, DW_AT_name("IERR")
	.dwattr DW$234, DW_AT_location[DW_OP_regx 0x63]
DW$235	.dwtag  DW_TAG_assign_register, DW_AT_name("DMSG")
	.dwattr DW$235, DW_AT_location[DW_OP_regx 0x64]
DW$236	.dwtag  DW_TAG_assign_register, DW_AT_name("CMSG")
	.dwattr DW$236, DW_AT_location[DW_OP_regx 0x65]
DW$237	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr DW$237, DW_AT_location[DW_OP_regx 0x66]
DW$238	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr DW$238, DW_AT_location[DW_OP_regx 0x67]
DW$239	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr DW$239, DW_AT_location[DW_OP_regx 0x68]
DW$240	.dwtag  DW_TAG_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr DW$240, DW_AT_location[DW_OP_regx 0x69]
DW$241	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr DW$241, DW_AT_location[DW_OP_regx 0x6a]
DW$242	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr DW$242, DW_AT_location[DW_OP_regx 0x6b]
DW$243	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr DW$243, DW_AT_location[DW_OP_regx 0x6c]
DW$244	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr DW$244, DW_AT_location[DW_OP_regx 0x6d]
DW$245	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr DW$245, DW_AT_location[DW_OP_regx 0x6e]
DW$246	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr DW$246, DW_AT_location[DW_OP_regx 0x6f]
DW$247	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr DW$247, DW_AT_location[DW_OP_regx 0x70]
DW$248	.dwtag  DW_TAG_assign_register, DW_AT_name("MFREG0")
	.dwattr DW$248, DW_AT_location[DW_OP_regx 0x71]
DW$249	.dwtag  DW_TAG_assign_register, DW_AT_name("DBG_STAT")
	.dwattr DW$249, DW_AT_location[DW_OP_regx 0x72]
DW$250	.dwtag  DW_TAG_assign_register, DW_AT_name("BRK_EN")
	.dwattr DW$250, DW_AT_location[DW_OP_regx 0x73]
DW$251	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr DW$251, DW_AT_location[DW_OP_regx 0x74]
DW$252	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0")
	.dwattr DW$252, DW_AT_location[DW_OP_regx 0x75]
DW$253	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP1")
	.dwattr DW$253, DW_AT_location[DW_OP_regx 0x76]
DW$254	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP2")
	.dwattr DW$254, DW_AT_location[DW_OP_regx 0x77]
DW$255	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP3")
	.dwattr DW$255, DW_AT_location[DW_OP_regx 0x78]
DW$256	.dwtag  DW_TAG_assign_register, DW_AT_name("OVERLAY")
	.dwattr DW$256, DW_AT_location[DW_OP_regx 0x79]
DW$257	.dwtag  DW_TAG_assign_register, DW_AT_name("PC_PROF")
	.dwattr DW$257, DW_AT_location[DW_OP_regx 0x7a]
DW$258	.dwtag  DW_TAG_assign_register, DW_AT_name("ATSR")
	.dwattr DW$258, DW_AT_location[DW_OP_regx 0x7b]
DW$259	.dwtag  DW_TAG_assign_register, DW_AT_name("TRR")
	.dwattr DW$259, DW_AT_location[DW_OP_regx 0x7c]
DW$260	.dwtag  DW_TAG_assign_register, DW_AT_name("TCRR")
	.dwattr DW$260, DW_AT_location[DW_OP_regx 0x7d]
DW$261	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$261, DW_AT_location[DW_OP_regx 0x7e]
	.dwendtag DW$CU

