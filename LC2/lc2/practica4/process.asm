;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v5.1.0 *
;* Date/Time created: Mon Mar 28 11:04:56 2011                                *
;******************************************************************************
	.compiler_opts --endian=little --mem_model:code=near --mem_model:data=far --quiet --silicon_version=6710 

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture      : TMS320C671x                                          *
;*   Optimization      : Disabled                                             *
;*   Optimizing for    : Compile time, Ease of Development                    *
;*                       Based on options: no -o, no -ms                      *
;*   Endian            : Little                                               *
;*   Interrupt Thrshld : Disabled                                             *
;*   Data Access Model : Far                                                  *
;*   Pipelining        : Disabled                                             *
;*   Memory Aliases    : Presume are aliases (pessimistic)                    *
;*   Debug Info        : DWARF Debug                                          *
;*                                                                            *
;******************************************************************************

	.asg	A15, FP
	.asg	B14, DP
	.asg	B15, SP
	.global	$bss


DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr DW$CU, DW_AT_name("process.c")
	.dwattr DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v5.1.0 Copyright (c) 1996-2005 Texas Instruments Incorporated")
	.dwattr DW$CU, DW_AT_stmt_list(0x00)
	.dwattr DW$CU, DW_AT_TI_VERSION(0x01)

DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("sin"), DW_AT_symbol_name("_sin")
	.dwattr DW$1, DW_AT_type(*DW$T$17)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$17)
	.dwendtag DW$1


DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("cos"), DW_AT_symbol_name("_cos")
	.dwattr DW$3, DW_AT_type(*DW$T$17)
	.dwattr DW$3, DW_AT_declaration(0x01)
	.dwattr DW$3, DW_AT_external(0x01)
DW$4	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$17)
	.dwendtag DW$3

	.sect	".const"
	.align	4
_$T0$1:
	.word	000000000h		; _$T0$1[0] @ 0

DW$5	.dwtag  DW_TAG_variable, DW_AT_name("$T0$1"), DW_AT_symbol_name("_$T0$1")
	.dwattr DW$5, DW_AT_type(*DW$T$34)
	.dwattr DW$5, DW_AT_location[DW_OP_addr _$T0$1]
_x$2:	.usect	".far",4512,4
	.sect	".const"
	.align	4
_$T1$3:
	.word	000000000h		; _$T1$3[0] @ 0

DW$6	.dwtag  DW_TAG_variable, DW_AT_name("$T1$3"), DW_AT_symbol_name("_$T1$3")
	.dwattr DW$6, DW_AT_type(*DW$T$34)
	.dwattr DW$6, DW_AT_location[DW_OP_addr _$T1$3]
	.sect	".const"
	.align	4
_$T2$4:
	.word	000000000h		; _$T2$4[0] @ 0

DW$7	.dwtag  DW_TAG_variable, DW_AT_name("$T2$4"), DW_AT_symbol_name("_$T2$4")
	.dwattr DW$7, DW_AT_type(*DW$T$34)
	.dwattr DW$7, DW_AT_location[DW_OP_addr _$T2$4]
;	C:\CCStudio_v3.1\c6000\cgtools\bin\acp6x.exe -@C:\DOCUME~1\lc2125\CONFIG~1\Temp\TI97212 
	.sect	".text"
	.global	_sinc

DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("sinc"), DW_AT_symbol_name("_sinc")
	.dwattr DW$8, DW_AT_low_pc(_sinc)
	.dwattr DW$8, DW_AT_high_pc(0x00)
	.dwattr DW$8, DW_AT_begin_file("process.c")
	.dwattr DW$8, DW_AT_begin_line(0x08)
	.dwattr DW$8, DW_AT_begin_column(0x07)
	.dwpsn	"process.c",9,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;   8 | float sinc(float s)                                                    
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _sinc                                                       *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_sinc:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |9| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$9	.dwtag  DW_TAG_formal_parameter, DW_AT_name("s"), DW_AT_symbol_name("_s")
	.dwattr DW$9, DW_AT_type(*DW$T$16)
	.dwattr DW$9, DW_AT_location[DW_OP_reg4]
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("s"), DW_AT_symbol_name("_s")
	.dwattr DW$10, DW_AT_type(*DW$T$16)
	.dwattr DW$10, DW_AT_location[DW_OP_breg31 4]
           STW     .D2T1   A4,*+SP(4)        ; |9| 
           NOP             2
	.dwpsn	"process.c",10,5
;----------------------------------------------------------------------
;  10 | if (s==0)                                                              
;----------------------------------------------------------------------

           MV      .L2X    A4,B4
||         ZERO    .S2     B5                ; |10| 

           CMPEQSP .S2     B4,B5,B0          ; |10| 
   [!B0]   B       .S1     L1                ; |10| 
           NOP             5
           ; BRANCHCC OCCURS {L1}            ; |10| 
;** --------------------------------------------------------------------------*
	.dwpsn	"process.c",11,3
;----------------------------------------------------------------------
;  11 | return(1);                                                             
;  12 | else                                                                   
;----------------------------------------------------------------------
           B       .S1     L2                ; |11| 
           NOP             3
           ZERO    .L1     A4                ; |11| 
           MVKH    .S1     0x3f800000,A4     ; |11| 
           ; BRANCH OCCURS {L2}              ; |11| 
;** --------------------------------------------------------------------------*
L1:    
	.dwpsn	"process.c",13,3
;----------------------------------------------------------------------
;  13 | return(sin(s)/s);                                                      
;----------------------------------------------------------------------
           CALL    .S1     _sin              ; |13| 
           MVKL    .S2     RL1,B3            ; |13| 
           SPDP    .S2     B4,B5:B4          ; |13| 
           NOP             1
           MV      .L1X    B5,A5             ; |13| 

           MVKH    .S2     RL1,B3            ; |13| 
||         MV      .L1X    B4,A4             ; |13| 

RL1:       ; CALL OCCURS {_sin}              ; |13| 
           LDW     .D2T2   *+SP(4),B4        ; |13| 
           MVKL    .S2     RL2,B3            ; |13| 
           MVKH    .S2     RL2,B3            ; |13| 
           CALL    .S1     __divd            ; |13| 
           NOP             1
           SPDP    .S2     B4,B5:B4          ; |13| 
           NOP             3
RL2:       ; CALL OCCURS {__divd}            ; |13| 
           DPSP    .L1     A5:A4,A4          ; |13| 
;** --------------------------------------------------------------------------*
L2:    
	.dwpsn	"process.c",14,1
           LDW     .D2T2   *++SP(8),B3       ; |14| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |14| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |14| 
	.dwattr DW$8, DW_AT_end_file("process.c")
	.dwattr DW$8, DW_AT_end_line(0x0e)
	.dwattr DW$8, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$8

	.sect	".text"
	.global	_init_processFIR1

DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("init_processFIR1"), DW_AT_symbol_name("_init_processFIR1")
	.dwattr DW$11, DW_AT_low_pc(_init_processFIR1)
	.dwattr DW$11, DW_AT_high_pc(0x00)
	.dwattr DW$11, DW_AT_begin_file("process.c")
	.dwattr DW$11, DW_AT_begin_line(0x10)
	.dwattr DW$11, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",18,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  16 | void init_processFIR1(float *h)         // Filtrado FIR paso alto obten
;     | ido mediante                                                           
;  17 | // enventadado de Hamming                                              
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _init_processFIR1                                           *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,B10,B11,SP                              *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,B10,B11,SP                              *
;*   Local Frame Size  : 0 Args + 8 Auto + 12 Save = 20 byte                  *
;******************************************************************************
_init_processFIR1:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B11,*SP--(24)     ; |18| 
           NOP             2
	.dwcfa	0x0e, 24
	.dwcfa	0x80, 27, 0
           STW     .D2T2   B10,*+SP(20)      ; |18| 
           NOP             2
	.dwcfa	0x80, 26, 1
           STW     .D2T2   B3,*+SP(16)       ; |18| 
           NOP             2
	.dwcfa	0x80, 19, 2
DW$12	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$12, DW_AT_type(*DW$T$21)
	.dwattr DW$12, DW_AT_location[DW_OP_reg4]
DW$13	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$13, DW_AT_type(*DW$T$21)
	.dwattr DW$13, DW_AT_location[DW_OP_breg31 4]
DW$14	.dwtag  DW_TAG_variable, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$14, DW_AT_type(*DW$T$10)
	.dwattr DW$14, DW_AT_location[DW_OP_breg31 8]
;----------------------------------------------------------------------
;  19 | int n;                                                                 
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |18| 
           NOP             2
	.dwpsn	"process.c",21,10
;----------------------------------------------------------------------
;  21 | for (n=0; n<L_FIR; n++) {                                              
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |21| 
           STW     .D2T2   B4,*+SP(8)        ; |21| 
           NOP             2
	.dwpsn	"process.c",21,15
           MVK     .S2     129,B5            ; |21| 
           CMPLT   .L2     B4,B5,B0          ; |21| 
   [!B0]   B       .S1     L5                ; |21| 
           NOP             5
           ; BRANCHCC OCCURS {L5}            ; |21| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L3:    
DW$L$_init_processFIR1$2$B:
	.dwpsn	"process.c",22,3
;----------------------------------------------------------------------
;  22 | h[n] = -(WC/PI)*sinc(WC*(n-(L_FIR-1)/2));      // Highpass filter      
;----------------------------------------------------------------------
           ADDK    .S2     -64,B4            ; |22| 
           INTDP   .L2     B4,B5:B4          ; |22| 
           MVKL    .S1     0x3ff921fb,A5     ; |22| 
           MVKL    .S1     0x54524550,A4     ; |22| 
           MVKH    .S1     0x3ff921fb,A5     ; |22| 
           MVKH    .S1     0x54524550,A4     ; |22| 
           MPYDP   .M1X    B5:B4,A5:A4,A5:A4 ; |22| 
           NOP             7
           CALL    .S1     _sinc             ; |22| 
           NOP             1
           DPSP    .L1     A5:A4,A4          ; |22| 
           NOP             1
           MVKL    .S2     RL4,B3            ; |22| 
           MVKH    .S2     RL4,B3            ; |22| 
RL4:       ; CALL OCCURS {_sinc}             ; |22| 

           SPDP    .S1     A4,A5:A4          ; |22| 
||         ZERO    .L2     B5                ; |22| 

           MVKH    .S2     0xbfe00000,B5     ; |22| 
||         ZERO    .L2     B4                ; |22| 

           MPYDP   .M2X    A5:A4,B5:B4,B5:B4 ; |22| 
           NOP             7
           LDW     .D2T2   *+SP(8),B6        ; |22| 
           LDW     .D2T2   *+SP(4),B7        ; |22| 
           DPSP    .L2     B5:B4,B4          ; |22| 
           NOP             3
           STW     .D2T2   B4,*+B7[B6]       ; |22| 
           NOP             2
	.dwpsn	"process.c",23,3
;----------------------------------------------------------------------
;  23 | if (n==(L_FIR-1)/2) h[n] = h[n] + 1;                                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |23| 
           NOP             3
           MVK     .S2     64,B5             ; |23| 
           CMPEQ   .L2     B4,B5,B0          ; |23| 
   [!B0]   B       .S1     L4                ; |23| 
           NOP             5
           ; BRANCHCC OCCURS {L4}            ; |23| 
DW$L$_init_processFIR1$2$E:
;** --------------------------------------------------------------------------*
DW$L$_init_processFIR1$3$B:
	.dwpsn	"process.c",23,23
           LDW     .D2T2   *+SP(4),B5        ; |23| 
           ZERO    .L1     A3                ; |23| 
           MVKH    .S1     0x3f800000,A3     ; |23| 
           NOP             2
           LDW     .D2T2   *+B5[B4],B6       ; |23| 
           NOP             4
           ADDSP   .L1X    A3,B6,A3          ; |23| 
           NOP             3
           STW     .D2T1   A3,*+B5[B4]       ; |23| 
DW$L$_init_processFIR1$3$E:
;** --------------------------------------------------------------------------*
L4:    
DW$L$_init_processFIR1$4$B:
	.dwpsn	"process.c",24,3
;----------------------------------------------------------------------
;  24 | h[n] *= (0.54 - 0.46*cos(2*PI*n/L_FIR));    // Hamming window          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |24| 
           NOP             4
           INTDP   .L2     B4,B5:B4          ; |24| 
           MVKL    .S1     0x401921fb,A5     ; |24| 
           MVKL    .S1     0x54524550,A4     ; |24| 
           MVKH    .S1     0x401921fb,A5     ; |24| 
           MVKH    .S1     0x54524550,A4     ; |24| 
           MPYDP   .M1X    B5:B4,A5:A4,A5:A4 ; |24| 
           NOP             3

           CALL    .S1     __divd            ; |24| 
||         LDW     .D2T2   *+SP(8),B10       ; |24| 

           LDW     .D2T2   *+SP(4),B11       ; |24| 
           MVKL    .S2     RL6,B3            ; |24| 
           MVKH    .S2     RL6,B3            ; |24| 
           MVKL    .S2     0x40602000,B5     ; |24| 

           MVKH    .S2     0x40602000,B5     ; |24| 
||         ZERO    .L2     B4                ; |24| 

RL6:       ; CALL OCCURS {__divd}            ; |24| 
           CALL    .S1     _cos              ; |24| 
           NOP             3
           MVKL    .S2     RL7,B3            ; |24| 
           MVKH    .S2     RL7,B3            ; |24| 
RL7:       ; CALL OCCURS {_cos}              ; |24| 
           MVKL    .S2     0x3fdd70a3,B5     ; |24| 
           MVKL    .S2     0xd70a3d71,B4     ; |24| 
           MVKH    .S2     0x3fdd70a3,B5     ; |24| 
           MVKH    .S2     0xd70a3d71,B4     ; |24| 
           MPYDP   .M2X    A5:A4,B5:B4,B7:B6 ; |24| 
           NOP             5
           MVKL    .S1     0x147ae148,A4     ; |24| 
           MVKL    .S1     0x3fe147ae,A5     ; |24| 
           MVKH    .S1     0x147ae148,A4     ; |24| 

           MVKH    .S1     0x3fe147ae,A5     ; |24| 
||         ADDAW   .D2     B11,B10,B2        ; |24| 

           SUBDP   .L2X    A5:A4,B7:B6,B9:B8 ; |24| 
||         LDW     .D2T2   *B2,B5            ; |24| 

           NOP             4
           SPDP    .S2     B5,B7:B6          ; |24| 
           NOP             1
           MPYDP   .M2     B9:B8,B7:B6,B7:B6 ; |24| 
           NOP             9
           DPSP    .L2     B7:B6,B5          ; |24| 
           NOP             3
           STW     .D2T2   B5,*B2            ; |24| 
           NOP             2
	.dwpsn	"process.c",21,24
           LDW     .D2T2   *+SP(8),B4        ; |21| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |21| 
           STW     .D2T2   B4,*+SP(8)        ; |21| 
           NOP             2
	.dwpsn	"process.c",21,15
           MVK     .S1     129,A3            ; |21| 
           CMPLT   .L1X    B4,A3,A1          ; |21| 
   [ A1]   B       .S1     L3                ; |21| 
           NOP             5
           ; BRANCHCC OCCURS {L3}            ; |21| 
DW$L$_init_processFIR1$4$E:
;** --------------------------------------------------------------------------*
L5:    
	.dwpsn	"process.c",26,1
           LDW     .D2T2   *+SP(20),B10      ; |26| 
           NOP             4
	.dwcfa	0xc0, 26
           LDW     .D2T2   *+SP(16),B3       ; |26| 
           NOP             4
	.dwcfa	0xc0, 19
           LDW     .D2T2   *++SP(24),B11     ; |26| 
           NOP             4
	.dwcfa	0xc0, 27
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |26| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |26| 

DW$15	.dwtag  DW_TAG_loop
	.dwattr DW$15, DW_AT_name("H:\practica4\process.asm:L3:1:1301303096")
	.dwattr DW$15, DW_AT_begin_file("process.c")
	.dwattr DW$15, DW_AT_begin_line(0x15)
	.dwattr DW$15, DW_AT_end_line(0x19)
DW$16	.dwtag  DW_TAG_loop_range
	.dwattr DW$16, DW_AT_low_pc(DW$L$_init_processFIR1$2$B)
	.dwattr DW$16, DW_AT_high_pc(DW$L$_init_processFIR1$2$E)
DW$17	.dwtag  DW_TAG_loop_range
	.dwattr DW$17, DW_AT_low_pc(DW$L$_init_processFIR1$3$B)
	.dwattr DW$17, DW_AT_high_pc(DW$L$_init_processFIR1$3$E)
DW$18	.dwtag  DW_TAG_loop_range
	.dwattr DW$18, DW_AT_low_pc(DW$L$_init_processFIR1$4$B)
	.dwattr DW$18, DW_AT_high_pc(DW$L$_init_processFIR1$4$E)
	.dwendtag DW$15

	.dwattr DW$11, DW_AT_end_file("process.c")
	.dwattr DW$11, DW_AT_end_line(0x1a)
	.dwattr DW$11, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$11

	.sect	".text"
	.global	_init_processFIR2

DW$19	.dwtag  DW_TAG_subprogram, DW_AT_name("init_processFIR2"), DW_AT_symbol_name("_init_processFIR2")
	.dwattr DW$19, DW_AT_low_pc(_init_processFIR2)
	.dwattr DW$19, DW_AT_high_pc(0x00)
	.dwattr DW$19, DW_AT_begin_file("process.c")
	.dwattr DW$19, DW_AT_begin_line(0x1c)
	.dwattr DW$19, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",29,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  28 | void init_processFIR2(float *h)         // Filtrado FIR con coeficiente
;     | s obtenidos en MATLAB                                                  
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _init_processFIR2                                           *
;*                                                                            *
;*   Regs Modified     : A3,B0,B4,B5,B6,SP                                    *
;*   Regs Used         : A3,A4,B0,B3,B4,B5,B6,SP                              *
;*   Local Frame Size  : 0 Args + 12 Auto + 0 Save = 12 byte                  *
;******************************************************************************
_init_processFIR2:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           SUB     .D2     SP,16,SP          ; |29| 
	.dwcfa	0x0e, 16
DW$20	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$20, DW_AT_type(*DW$T$21)
	.dwattr DW$20, DW_AT_location[DW_OP_reg4]
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$21, DW_AT_type(*DW$T$21)
	.dwattr DW$21, DW_AT_location[DW_OP_breg31 4]
DW$22	.dwtag  DW_TAG_variable, DW_AT_name("hh"), DW_AT_symbol_name("_hh")
	.dwattr DW$22, DW_AT_type(*DW$T$19)
	.dwattr DW$22, DW_AT_location[DW_OP_breg31 8]
DW$23	.dwtag  DW_TAG_variable, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$23, DW_AT_type(*DW$T$10)
	.dwattr DW$23, DW_AT_location[DW_OP_breg31 12]
           STW     .D2T1   A4,*+SP(4)        ; |29| 
           NOP             2
	.dwpsn	"process.c",30,8
;----------------------------------------------------------------------
;  30 | float hh[]={0};                                                        
;  31 | int n;                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     _$T0$1,A3         ; |30| 
           MVKH    .S1     _$T0$1,A3         ; |30| 
           LDW     .D1T1   *A3,A3            ; |30| 
           NOP             4
           STW     .D2T1   A3,*+SP(8)        ; |30| 
           NOP             2
	.dwpsn	"process.c",33,10
;----------------------------------------------------------------------
;  33 | for (n=0; n<L_FIR; n++)                                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |33| 
           STW     .D2T2   B4,*+SP(12)       ; |33| 
           NOP             2
	.dwpsn	"process.c",33,15
           MVK     .S2     129,B5            ; |33| 
           CMPLT   .L2     B4,B5,B0          ; |33| 
   [!B0]   B       .S1     L7                ; |33| 
           NOP             5
           ; BRANCHCC OCCURS {L7}            ; |33| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L6:    
DW$L$_init_processFIR2$2$B:
	.dwpsn	"process.c",34,3
;----------------------------------------------------------------------
;  34 | h[n] = hh[n];                                                          
;----------------------------------------------------------------------

           ADDAW   .D2     SP,B4,B4          ; |34| 
||         MV      .L2     B4,B5

           LDW     .D2T2   *+SP(4),B6        ; |34| 
           LDW     .D2T2   *+B4(8),B4        ; |34| 
           NOP             4
           STW     .D2T2   B4,*+B6[B5]       ; |34| 
           NOP             2
	.dwpsn	"process.c",33,24
           LDW     .D2T2   *+SP(12),B4       ; |33| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |33| 
           STW     .D2T2   B4,*+SP(12)       ; |33| 
           NOP             2
	.dwpsn	"process.c",33,15
           MVK     .S2     129,B5            ; |33| 
           CMPLT   .L2     B4,B5,B0          ; |33| 
   [ B0]   B       .S1     L6                ; |33| 
           NOP             5
           ; BRANCHCC OCCURS {L6}            ; |33| 
DW$L$_init_processFIR2$2$E:
;** --------------------------------------------------------------------------*
L7:    
	.dwpsn	"process.c",36,1
           ADDK    .S2     16,SP             ; |36| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |36| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |36| 

DW$24	.dwtag  DW_TAG_loop
	.dwattr DW$24, DW_AT_name("H:\practica4\process.asm:L6:1:1301303096")
	.dwattr DW$24, DW_AT_begin_file("process.c")
	.dwattr DW$24, DW_AT_begin_line(0x21)
	.dwattr DW$24, DW_AT_end_line(0x22)
DW$25	.dwtag  DW_TAG_loop_range
	.dwattr DW$25, DW_AT_low_pc(DW$L$_init_processFIR2$2$B)
	.dwattr DW$25, DW_AT_high_pc(DW$L$_init_processFIR2$2$E)
	.dwendtag DW$24

	.dwattr DW$19, DW_AT_end_file("process.c")
	.dwattr DW$19, DW_AT_end_line(0x24)
	.dwattr DW$19, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$19

	.sect	".text"
	.global	_fir

DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("fir"), DW_AT_symbol_name("_fir")
	.dwattr DW$26, DW_AT_low_pc(_fir)
	.dwattr DW$26, DW_AT_high_pc(0x00)
	.dwattr DW$26, DW_AT_begin_file("process.c")
	.dwattr DW$26, DW_AT_begin_line(0x26)
	.dwattr DW$26, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",38,54

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _fir                                                        *
;*                                                                            *
;*   Regs Modified     : A3,B0,B4,B5,B6,B7,B8,B9,SP                           *
;*   Regs Used         : A3,A4,A6,A8,B0,B3,B4,B5,B6,B7,B8,B9,SP               *
;*   Local Frame Size  : 0 Args + 32 Auto + 0 Save = 32 byte                  *
;******************************************************************************
_fir:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  38 | void fir(float *x, float *y, float *h, int k, int n) {                 
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           ADDK    .S2     -32,SP            ; |38| 
	.dwcfa	0x0e, 32
DW$27	.dwtag  DW_TAG_formal_parameter, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$27, DW_AT_type(*DW$T$21)
	.dwattr DW$27, DW_AT_location[DW_OP_reg4]
DW$28	.dwtag  DW_TAG_formal_parameter, DW_AT_name("y"), DW_AT_symbol_name("_y")
	.dwattr DW$28, DW_AT_type(*DW$T$21)
	.dwattr DW$28, DW_AT_location[DW_OP_reg20]
DW$29	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$29, DW_AT_type(*DW$T$21)
	.dwattr DW$29, DW_AT_location[DW_OP_reg6]
DW$30	.dwtag  DW_TAG_formal_parameter, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$30, DW_AT_type(*DW$T$10)
	.dwattr DW$30, DW_AT_location[DW_OP_reg22]
DW$31	.dwtag  DW_TAG_formal_parameter, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$31, DW_AT_type(*DW$T$10)
	.dwattr DW$31, DW_AT_location[DW_OP_reg8]
DW$32	.dwtag  DW_TAG_variable, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$32, DW_AT_type(*DW$T$21)
	.dwattr DW$32, DW_AT_location[DW_OP_breg31 4]
DW$33	.dwtag  DW_TAG_variable, DW_AT_name("y"), DW_AT_symbol_name("_y")
	.dwattr DW$33, DW_AT_type(*DW$T$21)
	.dwattr DW$33, DW_AT_location[DW_OP_breg31 8]
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$34, DW_AT_type(*DW$T$21)
	.dwattr DW$34, DW_AT_location[DW_OP_breg31 12]
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$35, DW_AT_type(*DW$T$10)
	.dwattr DW$35, DW_AT_location[DW_OP_breg31 16]
DW$36	.dwtag  DW_TAG_variable, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$36, DW_AT_type(*DW$T$10)
	.dwattr DW$36, DW_AT_location[DW_OP_breg31 20]
DW$37	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$37, DW_AT_type(*DW$T$10)
	.dwattr DW$37, DW_AT_location[DW_OP_breg31 24]
DW$38	.dwtag  DW_TAG_variable, DW_AT_name("j"), DW_AT_symbol_name("_j")
	.dwattr DW$38, DW_AT_type(*DW$T$10)
	.dwattr DW$38, DW_AT_location[DW_OP_breg31 28]
;----------------------------------------------------------------------
;  39 | int i,j;                                                               
;----------------------------------------------------------------------
           STW     .D2T1   A8,*+SP(20)       ; |38| 
           STW     .D2T1   A6,*+SP(12)       ; |38| 
           STW     .D2T2   B4,*+SP(8)        ; |38| 

           STW     .D2T1   A4,*+SP(4)        ; |38| 
||         MV      .L1X    B6,A3             ; |38| 

           STW     .D2T1   A3,*+SP(16)       ; |38| 
           NOP             2
	.dwpsn	"process.c",40,7
;----------------------------------------------------------------------
;  40 | for (i = 0; i < n; i++) {                                              
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |40| 
           STW     .D2T2   B4,*+SP(24)       ; |40| 
           NOP             2
	.dwpsn	"process.c",40,14
           LDW     .D2T2   *+SP(24),B5       ; |40| 
           NOP             4
           CMPLT   .L2X    B5,A8,B0          ; |40| 
   [!B0]   B       .S1     L11               ; |40| 
           NOP             5
           ; BRANCHCC OCCURS {L11}           ; |40| 
;** --------------------------------------------------------------------------*
;**   BEGIN LOOP L8
;** --------------------------------------------------------------------------*
L8:    
DW$L$_fir$2$B:

DW$39	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
DW$40	.dwtag  DW_TAG_variable, DW_AT_name("accum"), DW_AT_symbol_name("_accum")
	.dwattr DW$40, DW_AT_type(*DW$T$16)
	.dwattr DW$40, DW_AT_location[DW_OP_breg31 32]
	.dwpsn	"process.c",41,9
;----------------------------------------------------------------------
;  41 | float accum = 0;                                                       
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |41| 
           STW     .D2T2   B4,*+SP(32)       ; |41| 
           NOP             2
	.dwpsn	"process.c",42,8
;----------------------------------------------------------------------
;  42 | for (j = 0; j < k; j++)                                                
;----------------------------------------------------------------------
           STW     .D2T2   B4,*+SP(28)       ; |42| 
           NOP             2
	.dwpsn	"process.c",42,15
           LDW     .D2T2   *+SP(28),B5       ; |42| 
           LDW     .D2T2   *+SP(16),B4       ; |42| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |42| 
   [!B0]   B       .S1     L10               ; |42| 
           NOP             5
           ; BRANCHCC OCCURS {L10}           ; |42| 
DW$L$_fir$2$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L9:    
DW$L$_fir$3$B:
	.dwpsn	"process.c",43,4
;----------------------------------------------------------------------
;  43 | accum += h[j]*x[i-j];                                                  
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(12),B6       ; |43| 
           LDW     .D2T2   *+SP(24),B8       ; |43| 
           LDW     .D2T2   *+SP(4),B4        ; |43| 
           MV      .L2     B5,B7             ; |43| 
           LDW     .D2T2   *+SP(32),B9       ; |43| 
           NOP             1

           SUB     .L2     B8,B7,B6          ; |43| 
||         LDW     .D2T2   *+B6[B5],B5       ; |43| 

           LDW     .D2T2   *+B4[B6],B6       ; |43| 
           NOP             4
           MPYSP   .M2     B6,B5,B5          ; |43| 
           NOP             3
           ADDSP   .L2     B5,B9,B4          ; |43| 
           NOP             3
           STW     .D2T2   B4,*+SP(32)       ; |43| 
           NOP             2
	.dwpsn	"process.c",42,22
           ADD     .L2     1,B7,B4           ; |42| 
           STW     .D2T2   B4,*+SP(28)       ; |42| 
           NOP             2
	.dwpsn	"process.c",42,15
           LDW     .D2T2   *+SP(16),B4       ; |42| 
           LDW     .D2T2   *+SP(28),B5       ; |42| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |42| 
   [ B0]   B       .S1     L9                ; |42| 
           NOP             5
           ; BRANCHCC OCCURS {L9}            ; |42| 
DW$L$_fir$3$E:
;** --------------------------------------------------------------------------*
L10:    
DW$L$_fir$4$B:
	.dwpsn	"process.c",44,3
;----------------------------------------------------------------------
;  44 | y[i] = accum;                                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B5       ; |44| 
           LDW     .D2T2   *+SP(8),B6        ; |44| 
           LDW     .D2T2   *+SP(32),B4       ; |44| 
           NOP             4
           STW     .D2T2   B4,*+B6[B5]       ; |44| 
           NOP             2
	.dwendtag DW$39

	.dwpsn	"process.c",40,21
           LDW     .D2T2   *+SP(24),B4       ; |40| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |40| 
           STW     .D2T2   B4,*+SP(24)       ; |40| 
           NOP             2
	.dwpsn	"process.c",40,14
           LDW     .D2T2   *+SP(20),B4       ; |40| 
           LDW     .D2T2   *+SP(24),B5       ; |40| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |40| 
   [ B0]   B       .S1     L8                ; |40| 
           NOP             5
           ; BRANCHCC OCCURS {L8}            ; |40| 
DW$L$_fir$4$E:
;** --------------------------------------------------------------------------*
L11:    
	.dwpsn	"process.c",46,1
           ADDK    .S2     32,SP             ; |46| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |46| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |46| 

DW$41	.dwtag  DW_TAG_loop
	.dwattr DW$41, DW_AT_name("H:\practica4\process.asm:L8:1:1301303096")
	.dwattr DW$41, DW_AT_begin_file("process.c")
	.dwattr DW$41, DW_AT_begin_line(0x28)
	.dwattr DW$41, DW_AT_end_line(0x2d)
DW$42	.dwtag  DW_TAG_loop_range
	.dwattr DW$42, DW_AT_low_pc(DW$L$_fir$2$B)
	.dwattr DW$42, DW_AT_high_pc(DW$L$_fir$2$E)
DW$43	.dwtag  DW_TAG_loop_range
	.dwattr DW$43, DW_AT_low_pc(DW$L$_fir$4$B)
	.dwattr DW$43, DW_AT_high_pc(DW$L$_fir$4$E)

DW$44	.dwtag  DW_TAG_loop
	.dwattr DW$44, DW_AT_name("H:\practica4\process.asm:L9:2:1301303096")
	.dwattr DW$44, DW_AT_begin_file("process.c")
	.dwattr DW$44, DW_AT_begin_line(0x2a)
	.dwattr DW$44, DW_AT_end_line(0x2b)
DW$45	.dwtag  DW_TAG_loop_range
	.dwattr DW$45, DW_AT_low_pc(DW$L$_fir$3$B)
	.dwattr DW$45, DW_AT_high_pc(DW$L$_fir$3$E)
	.dwendtag DW$44

	.dwendtag DW$41

	.dwattr DW$26, DW_AT_end_file("process.c")
	.dwattr DW$26, DW_AT_end_line(0x2e)
	.dwattr DW$26, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$26

	.sect	".text"
	.global	_processFIR

DW$46	.dwtag  DW_TAG_subprogram, DW_AT_name("processFIR"), DW_AT_symbol_name("_processFIR")
	.dwattr DW$46, DW_AT_low_pc(_processFIR)
	.dwattr DW$46, DW_AT_high_pc(0x00)
	.dwattr DW$46, DW_AT_begin_file("process.c")
	.dwattr DW$46, DW_AT_begin_line(0x31)
	.dwattr DW$46, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",50,1

	.dwfde DW$CIE
DW$47	.dwtag  DW_TAG_variable, DW_AT_name("x"), DW_AT_symbol_name("_x$2")
	.dwattr DW$47, DW_AT_type(*DW$T$35)
	.dwattr DW$47, DW_AT_location[DW_OP_addr _x$2]
;----------------------------------------------------------------------
;  49 | void processFIR(float *block, float *h)                                
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _processFIR                                                 *
;*                                                                            *
;*   Regs Modified     : A3,A4,A6,A8,B0,B3,B4,B5,B6,B7,B8,B9,SP               *
;*   Regs Used         : A3,A4,A6,A8,B0,B3,B4,B5,B6,B7,B8,B9,SP               *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_processFIR:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(16)      ; |50| 
           NOP             2
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 19, 0
DW$48	.dwtag  DW_TAG_formal_parameter, DW_AT_name("block"), DW_AT_symbol_name("_block")
	.dwattr DW$48, DW_AT_type(*DW$T$21)
	.dwattr DW$48, DW_AT_location[DW_OP_reg4]
DW$49	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$49, DW_AT_type(*DW$T$21)
	.dwattr DW$49, DW_AT_location[DW_OP_reg20]
DW$50	.dwtag  DW_TAG_variable, DW_AT_name("block"), DW_AT_symbol_name("_block")
	.dwattr DW$50, DW_AT_type(*DW$T$21)
	.dwattr DW$50, DW_AT_location[DW_OP_breg31 4]
DW$51	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$51, DW_AT_type(*DW$T$21)
	.dwattr DW$51, DW_AT_location[DW_OP_breg31 8]
DW$52	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$52, DW_AT_type(*DW$T$10)
	.dwattr DW$52, DW_AT_location[DW_OP_breg31 12]
;----------------------------------------------------------------------
;  51 | int i;                                                                 
;  52 | static float x[(L_FIR-1)+N];         // FIR Input buffer               
;----------------------------------------------------------------------

           STW     .D2T1   A4,*+SP(4)        ; |50| 
||         MV      .L1X    B4,A3             ; |50| 

           STW     .D2T1   A3,*+SP(8)        ; |50| 
           NOP             2
	.dwpsn	"process.c",54,10
;----------------------------------------------------------------------
;  54 | for (i=0; i<N; i++) x[L_FIR-1+i] = block[i];                           
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |54| 
           STW     .D2T2   B4,*+SP(12)       ; |54| 
           NOP             2
	.dwpsn	"process.c",54,15
           MVK     .S2     1000,B5           ; |54| 
           CMPLT   .L2     B4,B5,B0          ; |54| 
   [!B0]   B       .S1     L13               ; |54| 
           NOP             5
           ; BRANCHCC OCCURS {L13}           ; |54| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L12:    
DW$L$_processFIR$2$B:
	.dwpsn	"process.c",54,25
           LDW     .D2T2   *+SP(4),B6        ; |54| 
           MV      .L2     B4,B5
           SHL     .S2     B4,2,B4           ; |54| 
           MVKL    .S1     _x$2,A3           ; |54| 
           ADDK    .S2     512,B4            ; |54| 
           LDW     .D2T2   *+B6[B5],B5       ; |54| 
           MVKH    .S1     _x$2,A3           ; |54| 
           ADD     .L2X    A3,B4,B4          ; |54| 
           NOP             2
           STW     .D2T2   B5,*B4            ; |54| 
           NOP             2
	.dwpsn	"process.c",54,20
           LDW     .D2T2   *+SP(12),B4       ; |54| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |54| 
           STW     .D2T2   B4,*+SP(12)       ; |54| 
           NOP             2
	.dwpsn	"process.c",54,15
           MVK     .S2     1000,B5           ; |54| 
           CMPLT   .L2     B4,B5,B0          ; |54| 
   [ B0]   B       .S1     L12               ; |54| 
           NOP             5
           ; BRANCHCC OCCURS {L12}           ; |54| 
DW$L$_processFIR$2$E:
;** --------------------------------------------------------------------------*
L13:    
	.dwpsn	"process.c",55,5
;----------------------------------------------------------------------
;  55 | fir(&x[L_FIR-1], block, h, L_FIR, N);                                  
;----------------------------------------------------------------------

           CALL    .S1     _fir              ; |55| 
||         LDW     .D2T1   *+SP(8),A6        ; |55| 

           LDW     .D2T2   *+SP(4),B4        ; |55| 
           MVKL    .S1     _x$2+512,A4       ; |55| 
           MVKL    .S2     RL8,B3            ; |55| 

           MVK     .S2     0x81,B6           ; |55| 
||         MVK     .S1     0x3e8,A8          ; |55| 

           MVKH    .S1     _x$2+512,A4       ; |55| 
||         MVKH    .S2     RL8,B3            ; |55| 

RL8:       ; CALL OCCURS {_fir}              ; |55| 
	.dwpsn	"process.c",56,10
;----------------------------------------------------------------------
;  56 | for (i=0; i<(L_FIR-1); i++) x[i] = x[i+N];                             
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |56| 
           STW     .D2T2   B4,*+SP(12)       ; |56| 
           NOP             2
	.dwpsn	"process.c",56,15
           MVK     .S2     128,B5            ; |56| 
           CMPLT   .L2     B4,B5,B0          ; |56| 
   [!B0]   B       .S1     L15               ; |56| 
           NOP             5
           ; BRANCHCC OCCURS {L15}           ; |56| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L14:    
DW$L$_processFIR$4$B:
	.dwpsn	"process.c",56,33

           MVKL    .S1     _x$2,A3           ; |56| 
||         SHL     .S2     B4,2,B4           ; |56| 

           MVKH    .S1     _x$2,A3           ; |56| 
||         ADDK    .S2     4000,B4           ; |56| 

           ADD     .L1X    A3,B4,A3          ; |56| 

           LDW     .D1T1   *A3,A3            ; |56| 
||         LDW     .D2T2   *+SP(12),B5       ; |56| 

           MVKL    .S2     _x$2,B9           ; |56| 
           MVKH    .S2     _x$2,B9           ; |56| 
           NOP             2
           STW     .D2T1   A3,*+B9[B5]       ; |56| 
           NOP             2
	.dwpsn	"process.c",56,28
           LDW     .D2T2   *+SP(12),B4       ; |56| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |56| 
           STW     .D2T2   B4,*+SP(12)       ; |56| 
           NOP             2
	.dwpsn	"process.c",56,15
           MVK     .S2     128,B5            ; |56| 
           CMPLT   .L2     B4,B5,B0          ; |56| 
   [ B0]   B       .S1     L14               ; |56| 
           NOP             5
           ; BRANCHCC OCCURS {L14}           ; |56| 
DW$L$_processFIR$4$E:
;** --------------------------------------------------------------------------*
L15:    
	.dwpsn	"process.c",57,1
           LDW     .D2T2   *++SP(16),B3      ; |57| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |57| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |57| 

DW$53	.dwtag  DW_TAG_loop
	.dwattr DW$53, DW_AT_name("H:\practica4\process.asm:L14:1:1301303096")
	.dwattr DW$53, DW_AT_begin_file("process.c")
	.dwattr DW$53, DW_AT_begin_line(0x38)
	.dwattr DW$53, DW_AT_end_line(0x38)
DW$54	.dwtag  DW_TAG_loop_range
	.dwattr DW$54, DW_AT_low_pc(DW$L$_processFIR$4$B)
	.dwattr DW$54, DW_AT_high_pc(DW$L$_processFIR$4$E)
	.dwendtag DW$53


DW$55	.dwtag  DW_TAG_loop
	.dwattr DW$55, DW_AT_name("H:\practica4\process.asm:L12:1:1301303096")
	.dwattr DW$55, DW_AT_begin_file("process.c")
	.dwattr DW$55, DW_AT_begin_line(0x36)
	.dwattr DW$55, DW_AT_end_line(0x36)
DW$56	.dwtag  DW_TAG_loop_range
	.dwattr DW$56, DW_AT_low_pc(DW$L$_processFIR$2$B)
	.dwattr DW$56, DW_AT_high_pc(DW$L$_processFIR$2$E)
	.dwendtag DW$55

	.dwattr DW$46, DW_AT_end_file("process.c")
	.dwattr DW$46, DW_AT_end_line(0x39)
	.dwattr DW$46, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$46

	.sect	".text"
	.global	_init_processIIR

DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("init_processIIR"), DW_AT_symbol_name("_init_processIIR")
	.dwattr DW$57, DW_AT_low_pc(_init_processIIR)
	.dwattr DW$57, DW_AT_high_pc(0x00)
	.dwattr DW$57, DW_AT_begin_file("process.c")
	.dwattr DW$57, DW_AT_begin_line(0x3b)
	.dwattr DW$57, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",60,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  59 | void init_processIIR(filter_iir2 *h)                                   
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _init_processIIR                                            *
;*                                                                            *
;*   Regs Modified     : A3,A4,A5,A9,B0,B4,B5,B6,SP                           *
;*   Regs Used         : A3,A4,A5,A9,B0,B3,B4,B5,B6,SP                        *
;*   Local Frame Size  : 0 Args + 16 Auto + 0 Save = 16 byte                  *
;******************************************************************************
_init_processIIR:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           SUB     .D2     SP,16,SP          ; |60| 
	.dwcfa	0x0e, 16
DW$58	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$58, DW_AT_type(*DW$T$27)
	.dwattr DW$58, DW_AT_location[DW_OP_reg4]
DW$59	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$59, DW_AT_type(*DW$T$27)
	.dwattr DW$59, DW_AT_location[DW_OP_breg31 4]
DW$60	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$60, DW_AT_type(*DW$T$10)
	.dwattr DW$60, DW_AT_location[DW_OP_breg31 8]
DW$61	.dwtag  DW_TAG_variable, DW_AT_name("a"), DW_AT_symbol_name("_a")
	.dwattr DW$61, DW_AT_type(*DW$T$19)
	.dwattr DW$61, DW_AT_location[DW_OP_breg31 12]
DW$62	.dwtag  DW_TAG_variable, DW_AT_name("b"), DW_AT_symbol_name("_b")
	.dwattr DW$62, DW_AT_type(*DW$T$19)
	.dwattr DW$62, DW_AT_location[DW_OP_breg31 16]
;----------------------------------------------------------------------
;  61 | int i;                                                                 
;  63 | // Pegue entre corchetes en la definición de a y de b la lista de los c
;     | oeficientes                                                            
;  64 | //obtenidos con MATLAB                                                 
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |60| 
           NOP             2
	.dwpsn	"process.c",66,8
;----------------------------------------------------------------------
;  66 | float a[]={0};                                                         
;----------------------------------------------------------------------
           MVKL    .S2     _$T1$3,B4         ; |66| 
           MVKH    .S2     _$T1$3,B4         ; |66| 
           LDW     .D2T2   *B4,B4            ; |66| 
           NOP             4
           STW     .D2T2   B4,*+SP(12)       ; |66| 
           NOP             2
	.dwpsn	"process.c",67,8
;----------------------------------------------------------------------
;  67 | float b[]={0};                                                         
;----------------------------------------------------------------------
           MVKL    .S1     _$T2$4,A3         ; |67| 
           MVKH    .S1     _$T2$4,A3         ; |67| 
           LDW     .D1T1   *A3,A3            ; |67| 
           NOP             4
           STW     .D2T1   A3,*+SP(16)       ; |67| 
           NOP             2
	.dwpsn	"process.c",69,7
;----------------------------------------------------------------------
;  69 | for (i=0; i<L_IIR; i++){                                               
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |69| 
           STW     .D2T2   B4,*+SP(8)        ; |69| 
           NOP             2
	.dwpsn	"process.c",69,12
           CMPGT   .L2     B4,0,B0           ; |69| 
   [ B0]   B       .S1     L17               ; |69| 
           NOP             5
           ; BRANCHCC OCCURS {L17}           ; |69| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L16:    
DW$L$_init_processIIR$2$B:
	.dwpsn	"process.c",70,3
;----------------------------------------------------------------------
;  70 | h->a[i]=a[i];                                                          
;----------------------------------------------------------------------

           ADDAW   .D2     SP,B4,B4          ; |70| 
||         MV      .L1X    B4,A4

           LDW     .D2T1   *+SP(4),A5        ; |70| 
           LDW     .D2T1   *+B4(12),A3       ; |70| 
           NOP             3
           ADDAW   .D1     A5,A4,A4          ; |70| 
           STW     .D1T1   A3,*+A4(4)        ; |70| 
           NOP             2
	.dwpsn	"process.c",71,3
;----------------------------------------------------------------------
;  71 | h->b[i]=b[i];                                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |71| 
           LDW     .D2T2   *+SP(8),B5        ; |71| 
           LDW     .D2T2   *+SP(4),B6        ; |71| 
           NOP             2
           ADDAW   .D2     SP,B4,B4          ; |71| 
           LDW     .D2T2   *+B4(16),B4       ; |71| 
           NOP             4
           STW     .D2T2   B4,*+B6[B5]       ; |71| 
           NOP             2
	.dwpsn	"process.c",72,3
;----------------------------------------------------------------------
;  72 | h->u[i]=0.0;                                                           
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(4),A4        ; |72| 
           LDW     .D2T1   *+SP(8),A3        ; |72| 
           ZERO    .L1     A9                ; |72| 
           NOP             3
           ADDAW   .D1     A4,A3,A3          ; |72| 
           STW     .D1T1   A9,*+A3(8)        ; |72| 
           NOP             2
	.dwpsn	"process.c",69,21
           LDW     .D2T2   *+SP(8),B4        ; |69| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |69| 
           STW     .D2T2   B4,*+SP(8)        ; |69| 
           NOP             2
	.dwpsn	"process.c",69,12
           CMPLT   .L2     B4,1,B0           ; |69| 
   [ B0]   B       .S1     L16               ; |69| 
           NOP             5
           ; BRANCHCC OCCURS {L16}           ; |69| 
DW$L$_init_processIIR$2$E:
;** --------------------------------------------------------------------------*
L17:    
	.dwpsn	"process.c",74,1
           ADDK    .S2     16,SP             ; |74| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |74| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |74| 

DW$63	.dwtag  DW_TAG_loop
	.dwattr DW$63, DW_AT_name("H:\practica4\process.asm:L16:1:1301303096")
	.dwattr DW$63, DW_AT_begin_file("process.c")
	.dwattr DW$63, DW_AT_begin_line(0x45)
	.dwattr DW$63, DW_AT_end_line(0x49)
DW$64	.dwtag  DW_TAG_loop_range
	.dwattr DW$64, DW_AT_low_pc(DW$L$_init_processIIR$2$B)
	.dwattr DW$64, DW_AT_high_pc(DW$L$_init_processIIR$2$E)
	.dwendtag DW$63

	.dwattr DW$57, DW_AT_end_file("process.c")
	.dwattr DW$57, DW_AT_end_line(0x4a)
	.dwattr DW$57, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$57

	.sect	".text"
	.global	_processIIR

DW$65	.dwtag  DW_TAG_subprogram, DW_AT_name("processIIR"), DW_AT_symbol_name("_processIIR")
	.dwattr DW$65, DW_AT_low_pc(_processIIR)
	.dwattr DW$65, DW_AT_high_pc(0x00)
	.dwattr DW$65, DW_AT_begin_file("process.c")
	.dwattr DW$65, DW_AT_begin_line(0x4c)
	.dwattr DW$65, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",77,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  76 | void processIIR(float *x, filter_iir2 *h, int k, int n)                
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _processIIR                                                 *
;*                                                                            *
;*   Regs Modified     : SP                                                   *
;*   Regs Used         : A4,A6,B3,B4,B6,SP                                    *
;*   Local Frame Size  : 0 Args + 16 Auto + 0 Save = 16 byte                  *
;******************************************************************************
_processIIR:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           SUB     .D2     SP,16,SP          ; |77| 
	.dwcfa	0x0e, 16
DW$66	.dwtag  DW_TAG_formal_parameter, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$66, DW_AT_type(*DW$T$21)
	.dwattr DW$66, DW_AT_location[DW_OP_reg4]
DW$67	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$67, DW_AT_type(*DW$T$27)
	.dwattr DW$67, DW_AT_location[DW_OP_reg20]
DW$68	.dwtag  DW_TAG_formal_parameter, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$68, DW_AT_type(*DW$T$10)
	.dwattr DW$68, DW_AT_location[DW_OP_reg6]
DW$69	.dwtag  DW_TAG_formal_parameter, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$69, DW_AT_type(*DW$T$10)
	.dwattr DW$69, DW_AT_location[DW_OP_reg22]
DW$70	.dwtag  DW_TAG_variable, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$70, DW_AT_type(*DW$T$21)
	.dwattr DW$70, DW_AT_location[DW_OP_breg31 4]
DW$71	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$71, DW_AT_type(*DW$T$27)
	.dwattr DW$71, DW_AT_location[DW_OP_breg31 8]
DW$72	.dwtag  DW_TAG_variable, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$72, DW_AT_type(*DW$T$10)
	.dwattr DW$72, DW_AT_location[DW_OP_breg31 12]
DW$73	.dwtag  DW_TAG_variable, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$73, DW_AT_type(*DW$T$10)
	.dwattr DW$73, DW_AT_location[DW_OP_breg31 16]
;----------------------------------------------------------------------
;  78 | // Complete el código                                                  
;----------------------------------------------------------------------
           STW     .D2T2   B6,*+SP(16)       ; |77| 
           STW     .D2T1   A6,*+SP(12)       ; |77| 
           STW     .D2T2   B4,*+SP(8)        ; |77| 
           STW     .D2T1   A4,*+SP(4)        ; |77| 
           NOP             2
	.dwpsn	"process.c",79,1
           ADDK    .S2     16,SP             ; |79| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |79| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |79| 
	.dwattr DW$65, DW_AT_end_file("process.c")
	.dwattr DW$65, DW_AT_end_line(0x4f)
	.dwattr DW$65, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$65

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_sin
	.global	_cos
	.global	__divd

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

DW$T$22	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$22, DW_AT_language(DW_LANG_C)
DW$74	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
	.dwendtag DW$T$22


DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$23, DW_AT_language(DW_LANG_C)
DW$75	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
DW$76	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
DW$77	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
DW$78	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$79	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
	.dwendtag DW$T$23


DW$T$25	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$25, DW_AT_language(DW_LANG_C)
DW$80	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
DW$81	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
	.dwendtag DW$T$25


DW$T$28	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$28, DW_AT_language(DW_LANG_C)
DW$82	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$27)
	.dwendtag DW$T$28


DW$T$29	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$29, DW_AT_language(DW_LANG_C)
DW$83	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$21)
DW$84	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$27)
DW$85	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$86	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
	.dwendtag DW$T$29

DW$T$10	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$10, DW_AT_byte_size(0x04)
DW$T$16	.dwtag  DW_TAG_base_type, DW_AT_name("float")
	.dwattr DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr DW$T$16, DW_AT_byte_size(0x04)

DW$T$19	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$19, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$19, DW_AT_byte_size(0x04)
DW$87	.dwtag  DW_TAG_subrange_type
	.dwattr DW$87, DW_AT_upper_bound(0x00)
	.dwendtag DW$T$19

DW$T$21	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$21, DW_AT_address_class(0x20)

DW$T$30	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$30, DW_AT_language(DW_LANG_C)
DW$88	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$16)
	.dwendtag DW$T$30


DW$T$34	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$33)
	.dwattr DW$T$34, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$34, DW_AT_byte_size(0x04)
DW$89	.dwtag  DW_TAG_subrange_type
	.dwattr DW$89, DW_AT_upper_bound(0x00)
	.dwendtag DW$T$34


DW$T$35	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$35, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$35, DW_AT_byte_size(0x11a0)
DW$90	.dwtag  DW_TAG_subrange_type
	.dwattr DW$90, DW_AT_upper_bound(0x467)
	.dwendtag DW$T$35

DW$T$17	.dwtag  DW_TAG_base_type, DW_AT_name("double")
	.dwattr DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr DW$T$17, DW_AT_byte_size(0x08)

DW$T$36	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$17)
	.dwattr DW$T$36, DW_AT_language(DW_LANG_C)
DW$91	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$17)
	.dwendtag DW$T$36

DW$T$27	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$26)
	.dwattr DW$T$27, DW_AT_address_class(0x20)
DW$T$33	.dwtag  DW_TAG_const_type
	.dwattr DW$T$33, DW_AT_type(*DW$T$16)
DW$T$26	.dwtag  DW_TAG_typedef, DW_AT_name("filter_iir2"), DW_AT_type(*DW$T$20)
	.dwattr DW$T$26, DW_AT_language(DW_LANG_C)

DW$T$20	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$20, DW_AT_byte_size(0x0c)
DW$92	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$92, DW_AT_name("b"), DW_AT_symbol_name("_b")
	.dwattr DW$92, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$92, DW_AT_accessibility(DW_ACCESS_public)
DW$93	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$93, DW_AT_name("a"), DW_AT_symbol_name("_a")
	.dwattr DW$93, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$93, DW_AT_accessibility(DW_ACCESS_public)
DW$94	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$94, DW_AT_name("u"), DW_AT_symbol_name("_u")
	.dwattr DW$94, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$94, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$20


	.dwattr DW$26, DW_AT_external(0x01)
	.dwattr DW$11, DW_AT_external(0x01)
	.dwattr DW$19, DW_AT_external(0x01)
	.dwattr DW$57, DW_AT_external(0x01)
	.dwattr DW$46, DW_AT_external(0x01)
	.dwattr DW$65, DW_AT_external(0x01)
	.dwattr DW$8, DW_AT_external(0x01)
	.dwattr DW$8, DW_AT_type(*DW$T$16)
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

DW$95	.dwtag  DW_TAG_assign_register, DW_AT_name("A0")
	.dwattr DW$95, DW_AT_location[DW_OP_reg0]
DW$96	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$96, DW_AT_location[DW_OP_reg1]
DW$97	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$97, DW_AT_location[DW_OP_reg2]
DW$98	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$98, DW_AT_location[DW_OP_reg3]
DW$99	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$99, DW_AT_location[DW_OP_reg4]
DW$100	.dwtag  DW_TAG_assign_register, DW_AT_name("A5")
	.dwattr DW$100, DW_AT_location[DW_OP_reg5]
DW$101	.dwtag  DW_TAG_assign_register, DW_AT_name("A6")
	.dwattr DW$101, DW_AT_location[DW_OP_reg6]
DW$102	.dwtag  DW_TAG_assign_register, DW_AT_name("A7")
	.dwattr DW$102, DW_AT_location[DW_OP_reg7]
DW$103	.dwtag  DW_TAG_assign_register, DW_AT_name("A8")
	.dwattr DW$103, DW_AT_location[DW_OP_reg8]
DW$104	.dwtag  DW_TAG_assign_register, DW_AT_name("A9")
	.dwattr DW$104, DW_AT_location[DW_OP_reg9]
DW$105	.dwtag  DW_TAG_assign_register, DW_AT_name("A10")
	.dwattr DW$105, DW_AT_location[DW_OP_reg10]
DW$106	.dwtag  DW_TAG_assign_register, DW_AT_name("A11")
	.dwattr DW$106, DW_AT_location[DW_OP_reg11]
DW$107	.dwtag  DW_TAG_assign_register, DW_AT_name("A12")
	.dwattr DW$107, DW_AT_location[DW_OP_reg12]
DW$108	.dwtag  DW_TAG_assign_register, DW_AT_name("A13")
	.dwattr DW$108, DW_AT_location[DW_OP_reg13]
DW$109	.dwtag  DW_TAG_assign_register, DW_AT_name("A14")
	.dwattr DW$109, DW_AT_location[DW_OP_reg14]
DW$110	.dwtag  DW_TAG_assign_register, DW_AT_name("A15")
	.dwattr DW$110, DW_AT_location[DW_OP_reg15]
DW$111	.dwtag  DW_TAG_assign_register, DW_AT_name("B0")
	.dwattr DW$111, DW_AT_location[DW_OP_reg16]
DW$112	.dwtag  DW_TAG_assign_register, DW_AT_name("B1")
	.dwattr DW$112, DW_AT_location[DW_OP_reg17]
DW$113	.dwtag  DW_TAG_assign_register, DW_AT_name("B2")
	.dwattr DW$113, DW_AT_location[DW_OP_reg18]
DW$114	.dwtag  DW_TAG_assign_register, DW_AT_name("B3")
	.dwattr DW$114, DW_AT_location[DW_OP_reg19]
DW$115	.dwtag  DW_TAG_assign_register, DW_AT_name("B4")
	.dwattr DW$115, DW_AT_location[DW_OP_reg20]
DW$116	.dwtag  DW_TAG_assign_register, DW_AT_name("B5")
	.dwattr DW$116, DW_AT_location[DW_OP_reg21]
DW$117	.dwtag  DW_TAG_assign_register, DW_AT_name("B6")
	.dwattr DW$117, DW_AT_location[DW_OP_reg22]
DW$118	.dwtag  DW_TAG_assign_register, DW_AT_name("B7")
	.dwattr DW$118, DW_AT_location[DW_OP_reg23]
DW$119	.dwtag  DW_TAG_assign_register, DW_AT_name("B8")
	.dwattr DW$119, DW_AT_location[DW_OP_reg24]
DW$120	.dwtag  DW_TAG_assign_register, DW_AT_name("B9")
	.dwattr DW$120, DW_AT_location[DW_OP_reg25]
DW$121	.dwtag  DW_TAG_assign_register, DW_AT_name("B10")
	.dwattr DW$121, DW_AT_location[DW_OP_reg26]
DW$122	.dwtag  DW_TAG_assign_register, DW_AT_name("B11")
	.dwattr DW$122, DW_AT_location[DW_OP_reg27]
DW$123	.dwtag  DW_TAG_assign_register, DW_AT_name("B12")
	.dwattr DW$123, DW_AT_location[DW_OP_reg28]
DW$124	.dwtag  DW_TAG_assign_register, DW_AT_name("B13")
	.dwattr DW$124, DW_AT_location[DW_OP_reg29]
DW$125	.dwtag  DW_TAG_assign_register, DW_AT_name("DP")
	.dwattr DW$125, DW_AT_location[DW_OP_reg30]
DW$126	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$126, DW_AT_location[DW_OP_reg31]
DW$127	.dwtag  DW_TAG_assign_register, DW_AT_name("FP")
	.dwattr DW$127, DW_AT_location[DW_OP_regx 0x20]
DW$128	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$128, DW_AT_location[DW_OP_regx 0x21]
DW$129	.dwtag  DW_TAG_assign_register, DW_AT_name("IRP")
	.dwattr DW$129, DW_AT_location[DW_OP_regx 0x22]
DW$130	.dwtag  DW_TAG_assign_register, DW_AT_name("IFR")
	.dwattr DW$130, DW_AT_location[DW_OP_regx 0x23]
DW$131	.dwtag  DW_TAG_assign_register, DW_AT_name("NRP")
	.dwattr DW$131, DW_AT_location[DW_OP_regx 0x24]
DW$132	.dwtag  DW_TAG_assign_register, DW_AT_name("A16")
	.dwattr DW$132, DW_AT_location[DW_OP_regx 0x25]
DW$133	.dwtag  DW_TAG_assign_register, DW_AT_name("A17")
	.dwattr DW$133, DW_AT_location[DW_OP_regx 0x26]
DW$134	.dwtag  DW_TAG_assign_register, DW_AT_name("A18")
	.dwattr DW$134, DW_AT_location[DW_OP_regx 0x27]
DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("A19")
	.dwattr DW$135, DW_AT_location[DW_OP_regx 0x28]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("A20")
	.dwattr DW$136, DW_AT_location[DW_OP_regx 0x29]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("A21")
	.dwattr DW$137, DW_AT_location[DW_OP_regx 0x2a]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("A22")
	.dwattr DW$138, DW_AT_location[DW_OP_regx 0x2b]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("A23")
	.dwattr DW$139, DW_AT_location[DW_OP_regx 0x2c]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("A24")
	.dwattr DW$140, DW_AT_location[DW_OP_regx 0x2d]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("A25")
	.dwattr DW$141, DW_AT_location[DW_OP_regx 0x2e]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("A26")
	.dwattr DW$142, DW_AT_location[DW_OP_regx 0x2f]
DW$143	.dwtag  DW_TAG_assign_register, DW_AT_name("A27")
	.dwattr DW$143, DW_AT_location[DW_OP_regx 0x30]
DW$144	.dwtag  DW_TAG_assign_register, DW_AT_name("A28")
	.dwattr DW$144, DW_AT_location[DW_OP_regx 0x31]
DW$145	.dwtag  DW_TAG_assign_register, DW_AT_name("A29")
	.dwattr DW$145, DW_AT_location[DW_OP_regx 0x32]
DW$146	.dwtag  DW_TAG_assign_register, DW_AT_name("A30")
	.dwattr DW$146, DW_AT_location[DW_OP_regx 0x33]
DW$147	.dwtag  DW_TAG_assign_register, DW_AT_name("A31")
	.dwattr DW$147, DW_AT_location[DW_OP_regx 0x34]
DW$148	.dwtag  DW_TAG_assign_register, DW_AT_name("B16")
	.dwattr DW$148, DW_AT_location[DW_OP_regx 0x35]
DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("B17")
	.dwattr DW$149, DW_AT_location[DW_OP_regx 0x36]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("B18")
	.dwattr DW$150, DW_AT_location[DW_OP_regx 0x37]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("B19")
	.dwattr DW$151, DW_AT_location[DW_OP_regx 0x38]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("B20")
	.dwattr DW$152, DW_AT_location[DW_OP_regx 0x39]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("B21")
	.dwattr DW$153, DW_AT_location[DW_OP_regx 0x3a]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("B22")
	.dwattr DW$154, DW_AT_location[DW_OP_regx 0x3b]
DW$155	.dwtag  DW_TAG_assign_register, DW_AT_name("B23")
	.dwattr DW$155, DW_AT_location[DW_OP_regx 0x3c]
DW$156	.dwtag  DW_TAG_assign_register, DW_AT_name("B24")
	.dwattr DW$156, DW_AT_location[DW_OP_regx 0x3d]
DW$157	.dwtag  DW_TAG_assign_register, DW_AT_name("B25")
	.dwattr DW$157, DW_AT_location[DW_OP_regx 0x3e]
DW$158	.dwtag  DW_TAG_assign_register, DW_AT_name("B26")
	.dwattr DW$158, DW_AT_location[DW_OP_regx 0x3f]
DW$159	.dwtag  DW_TAG_assign_register, DW_AT_name("B27")
	.dwattr DW$159, DW_AT_location[DW_OP_regx 0x40]
DW$160	.dwtag  DW_TAG_assign_register, DW_AT_name("B28")
	.dwattr DW$160, DW_AT_location[DW_OP_regx 0x41]
DW$161	.dwtag  DW_TAG_assign_register, DW_AT_name("B29")
	.dwattr DW$161, DW_AT_location[DW_OP_regx 0x42]
DW$162	.dwtag  DW_TAG_assign_register, DW_AT_name("B30")
	.dwattr DW$162, DW_AT_location[DW_OP_regx 0x43]
DW$163	.dwtag  DW_TAG_assign_register, DW_AT_name("B31")
	.dwattr DW$163, DW_AT_location[DW_OP_regx 0x44]
DW$164	.dwtag  DW_TAG_assign_register, DW_AT_name("AMR")
	.dwattr DW$164, DW_AT_location[DW_OP_regx 0x45]
DW$165	.dwtag  DW_TAG_assign_register, DW_AT_name("CSR")
	.dwattr DW$165, DW_AT_location[DW_OP_regx 0x46]
DW$166	.dwtag  DW_TAG_assign_register, DW_AT_name("ISR")
	.dwattr DW$166, DW_AT_location[DW_OP_regx 0x47]
DW$167	.dwtag  DW_TAG_assign_register, DW_AT_name("ICR")
	.dwattr DW$167, DW_AT_location[DW_OP_regx 0x48]
DW$168	.dwtag  DW_TAG_assign_register, DW_AT_name("IER")
	.dwattr DW$168, DW_AT_location[DW_OP_regx 0x49]
DW$169	.dwtag  DW_TAG_assign_register, DW_AT_name("ISTP")
	.dwattr DW$169, DW_AT_location[DW_OP_regx 0x4a]
DW$170	.dwtag  DW_TAG_assign_register, DW_AT_name("IN")
	.dwattr DW$170, DW_AT_location[DW_OP_regx 0x4b]
DW$171	.dwtag  DW_TAG_assign_register, DW_AT_name("OUT")
	.dwattr DW$171, DW_AT_location[DW_OP_regx 0x4c]
DW$172	.dwtag  DW_TAG_assign_register, DW_AT_name("ACR")
	.dwattr DW$172, DW_AT_location[DW_OP_regx 0x4d]
DW$173	.dwtag  DW_TAG_assign_register, DW_AT_name("ADR")
	.dwattr DW$173, DW_AT_location[DW_OP_regx 0x4e]
DW$174	.dwtag  DW_TAG_assign_register, DW_AT_name("FADCR")
	.dwattr DW$174, DW_AT_location[DW_OP_regx 0x4f]
DW$175	.dwtag  DW_TAG_assign_register, DW_AT_name("FAUCR")
	.dwattr DW$175, DW_AT_location[DW_OP_regx 0x50]
DW$176	.dwtag  DW_TAG_assign_register, DW_AT_name("FMCR")
	.dwattr DW$176, DW_AT_location[DW_OP_regx 0x51]
DW$177	.dwtag  DW_TAG_assign_register, DW_AT_name("GFPGFR")
	.dwattr DW$177, DW_AT_location[DW_OP_regx 0x52]
DW$178	.dwtag  DW_TAG_assign_register, DW_AT_name("DIER")
	.dwattr DW$178, DW_AT_location[DW_OP_regx 0x53]
DW$179	.dwtag  DW_TAG_assign_register, DW_AT_name("REP")
	.dwattr DW$179, DW_AT_location[DW_OP_regx 0x54]
DW$180	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCL")
	.dwattr DW$180, DW_AT_location[DW_OP_regx 0x55]
DW$181	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCH")
	.dwattr DW$181, DW_AT_location[DW_OP_regx 0x56]
DW$182	.dwtag  DW_TAG_assign_register, DW_AT_name("ARP")
	.dwattr DW$182, DW_AT_location[DW_OP_regx 0x57]
DW$183	.dwtag  DW_TAG_assign_register, DW_AT_name("ILC")
	.dwattr DW$183, DW_AT_location[DW_OP_regx 0x58]
DW$184	.dwtag  DW_TAG_assign_register, DW_AT_name("RILC")
	.dwattr DW$184, DW_AT_location[DW_OP_regx 0x59]
DW$185	.dwtag  DW_TAG_assign_register, DW_AT_name("DNUM")
	.dwattr DW$185, DW_AT_location[DW_OP_regx 0x5a]
DW$186	.dwtag  DW_TAG_assign_register, DW_AT_name("SSR")
	.dwattr DW$186, DW_AT_location[DW_OP_regx 0x5b]
DW$187	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYA")
	.dwattr DW$187, DW_AT_location[DW_OP_regx 0x5c]
DW$188	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYB")
	.dwattr DW$188, DW_AT_location[DW_OP_regx 0x5d]
DW$189	.dwtag  DW_TAG_assign_register, DW_AT_name("TSR")
	.dwattr DW$189, DW_AT_location[DW_OP_regx 0x5e]
DW$190	.dwtag  DW_TAG_assign_register, DW_AT_name("ITSR")
	.dwattr DW$190, DW_AT_location[DW_OP_regx 0x5f]
DW$191	.dwtag  DW_TAG_assign_register, DW_AT_name("NTSR")
	.dwattr DW$191, DW_AT_location[DW_OP_regx 0x60]
DW$192	.dwtag  DW_TAG_assign_register, DW_AT_name("EFR")
	.dwattr DW$192, DW_AT_location[DW_OP_regx 0x61]
DW$193	.dwtag  DW_TAG_assign_register, DW_AT_name("ECR")
	.dwattr DW$193, DW_AT_location[DW_OP_regx 0x62]
DW$194	.dwtag  DW_TAG_assign_register, DW_AT_name("IERR")
	.dwattr DW$194, DW_AT_location[DW_OP_regx 0x63]
DW$195	.dwtag  DW_TAG_assign_register, DW_AT_name("DMSG")
	.dwattr DW$195, DW_AT_location[DW_OP_regx 0x64]
DW$196	.dwtag  DW_TAG_assign_register, DW_AT_name("CMSG")
	.dwattr DW$196, DW_AT_location[DW_OP_regx 0x65]
DW$197	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr DW$197, DW_AT_location[DW_OP_regx 0x66]
DW$198	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr DW$198, DW_AT_location[DW_OP_regx 0x67]
DW$199	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr DW$199, DW_AT_location[DW_OP_regx 0x68]
DW$200	.dwtag  DW_TAG_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr DW$200, DW_AT_location[DW_OP_regx 0x69]
DW$201	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr DW$201, DW_AT_location[DW_OP_regx 0x6a]
DW$202	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr DW$202, DW_AT_location[DW_OP_regx 0x6b]
DW$203	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr DW$203, DW_AT_location[DW_OP_regx 0x6c]
DW$204	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr DW$204, DW_AT_location[DW_OP_regx 0x6d]
DW$205	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr DW$205, DW_AT_location[DW_OP_regx 0x6e]
DW$206	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr DW$206, DW_AT_location[DW_OP_regx 0x6f]
DW$207	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr DW$207, DW_AT_location[DW_OP_regx 0x70]
DW$208	.dwtag  DW_TAG_assign_register, DW_AT_name("MFREG0")
	.dwattr DW$208, DW_AT_location[DW_OP_regx 0x71]
DW$209	.dwtag  DW_TAG_assign_register, DW_AT_name("DBG_STAT")
	.dwattr DW$209, DW_AT_location[DW_OP_regx 0x72]
DW$210	.dwtag  DW_TAG_assign_register, DW_AT_name("BRK_EN")
	.dwattr DW$210, DW_AT_location[DW_OP_regx 0x73]
DW$211	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr DW$211, DW_AT_location[DW_OP_regx 0x74]
DW$212	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0")
	.dwattr DW$212, DW_AT_location[DW_OP_regx 0x75]
DW$213	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP1")
	.dwattr DW$213, DW_AT_location[DW_OP_regx 0x76]
DW$214	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP2")
	.dwattr DW$214, DW_AT_location[DW_OP_regx 0x77]
DW$215	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP3")
	.dwattr DW$215, DW_AT_location[DW_OP_regx 0x78]
DW$216	.dwtag  DW_TAG_assign_register, DW_AT_name("OVERLAY")
	.dwattr DW$216, DW_AT_location[DW_OP_regx 0x79]
DW$217	.dwtag  DW_TAG_assign_register, DW_AT_name("PC_PROF")
	.dwattr DW$217, DW_AT_location[DW_OP_regx 0x7a]
DW$218	.dwtag  DW_TAG_assign_register, DW_AT_name("ATSR")
	.dwattr DW$218, DW_AT_location[DW_OP_regx 0x7b]
DW$219	.dwtag  DW_TAG_assign_register, DW_AT_name("TRR")
	.dwattr DW$219, DW_AT_location[DW_OP_regx 0x7c]
DW$220	.dwtag  DW_TAG_assign_register, DW_AT_name("TCRR")
	.dwattr DW$220, DW_AT_location[DW_OP_regx 0x7d]
DW$221	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$221, DW_AT_location[DW_OP_regx 0x7e]
	.dwendtag DW$CU

