;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v5.1.0 *
;* Date/Time created: Mon May 23 11:07:05 2011                                *
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
;*****************************************************************************
;* CINIT RECORDS                                                             *
;*****************************************************************************
	.sect	".cinit"
	.align	8
	.field  	IR_1,32
	.field  	_hFIR+0,32
	.word	03e800000h		; _hFIR[0] @ 0
	.word	000000000h		; _hFIR[1] @ 32
	.word	000000000h		; _hFIR[2] @ 64
	.word	000000000h		; _hFIR[3] @ 96
	.word	03e800000h		; _hFIR[4] @ 128
	.word	000000000h		; _hFIR[5] @ 160
	.word	000000000h		; _hFIR[6] @ 192
	.word	000000000h		; _hFIR[7] @ 224
	.word	000000000h		; _hFIR[8] @ 256
	.word	000000000h		; _hFIR[9] @ 288
	.word	000000000h		; _hFIR[10] @ 320
IR_1:	.set	44

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_guany+0,32
	.word	000000000h		; _guany @ 0

	.sect	".cinit"
	.align	8
	.field  	IR_2,32
	.field  	_retard+0,32
	.word	000000000h		; _retard[0] @ 0
IR_2:	.set	4

	.sect	".cinit"
	.align	8
	.field  	IR_3,32
	.field  	_x$1+0,32
	.word	000000000h		; _x$1[0] @ 0
IR_3:	.set	4


DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("sqrtf"), DW_AT_symbol_name("_sqrtf")
	.dwattr DW$1, DW_AT_type(*DW$T$16)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$16)
	.dwendtag DW$1

	.global	_hFIR
_hFIR:	.usect	".far",44,4
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("hFIR"), DW_AT_symbol_name("_hFIR")
	.dwattr DW$3, DW_AT_location[DW_OP_addr _hFIR]
	.dwattr DW$3, DW_AT_type(*DW$T$28)
	.dwattr DW$3, DW_AT_external(0x01)
	.global	_guany
_guany:	.usect	".far",4,4
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("guany"), DW_AT_symbol_name("_guany")
	.dwattr DW$4, DW_AT_location[DW_OP_addr _guany]
	.dwattr DW$4, DW_AT_type(*DW$T$16)
	.dwattr DW$4, DW_AT_external(0x01)
	.global	_retard
_retard:	.usect	".far",9600,4
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("retard"), DW_AT_symbol_name("_retard")
	.dwattr DW$5, DW_AT_location[DW_OP_addr _retard]
	.dwattr DW$5, DW_AT_type(*DW$T$29)
	.dwattr DW$5, DW_AT_external(0x01)
_x$1:	.usect	".far",4040,4
;	C:\CCStudio_v3.1\c6000\cgtools\bin\acp6x.exe -@C:\DOCUME~1\lc2125\CONFIG~1\Temp\TI39212 
	.sect	".text"
	.global	_inicialitzacio

DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("inicialitzacio"), DW_AT_symbol_name("_inicialitzacio")
	.dwattr DW$6, DW_AT_low_pc(_inicialitzacio)
	.dwattr DW$6, DW_AT_high_pc(0x00)
	.dwattr DW$6, DW_AT_begin_file("process.c")
	.dwattr DW$6, DW_AT_begin_line(0x0b)
	.dwattr DW$6, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",11,23

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _inicialitzacio                                             *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_inicialitzacio:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  11 | void inicialitzacio() {                                                
;  12 | int i;                                                                 
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |11| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$7, DW_AT_type(*DW$T$10)
	.dwattr DW$7, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	"process.c",13,2
;----------------------------------------------------------------------
;  13 | guany = 0;                                                             
;----------------------------------------------------------------------
           MVKL    .S1     _guany,A3         ; |13| 

           MVKH    .S1     _guany,A3         ; |13| 
||         ZERO    .L1     A4                ; |13| 

           STW     .D1T1   A4,*A3            ; |13| 
           NOP             2
	.dwpsn	"process.c",14,7
;----------------------------------------------------------------------
;  14 | for (i = 0; i< L_FIR; i++)                                             
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |14| 
           STW     .D2T2   B4,*+SP(4)        ; |14| 
           NOP             2
	.dwpsn	"process.c",14,14
           CMPLT   .L2     B4,11,B0          ; |14| 
   [!B0]   B       .S1     L2                ; |14| 
           NOP             5
           ; BRANCHCC OCCURS {L2}            ; |14| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L1:    
DW$L$_inicialitzacio$2$B:
	.dwpsn	"process.c",15,3
;----------------------------------------------------------------------
;  15 | guany += hFIR[i]*hFIR[i];                                              
;----------------------------------------------------------------------

           MVKL    .S2     _hFIR,B4          ; |15| 
||         MVKL    .S1     _hFIR,A3          ; |15| 
||         MV      .L2     B4,B5
||         MV      .L1X    B4,A4

           MVKH    .S2     _hFIR,B4          ; |15| 
||         MVKH    .S1     _hFIR,A3          ; |15| 

           LDW     .D2T2   *+B4[B5],B4       ; |15| 
||         LDW     .D1T1   *+A3[A4],A4       ; |15| 

           MVKL    .S1     _guany,A9         ; |15| 
           MVKH    .S1     _guany,A9         ; |15| 
           LDW     .D1T1   *A9,A5            ; |15| 
           NOP             1
           MPYSP   .M1X    A4,B4,A4          ; |15| 
           NOP             3
           ADDSP   .L1     A4,A5,A4          ; |15| 
           NOP             3
           STW     .D1T1   A4,*A9            ; |15| 
           NOP             2
	.dwpsn	"process.c",14,24
           LDW     .D2T2   *+SP(4),B4        ; |14| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |14| 
           STW     .D2T2   B4,*+SP(4)        ; |14| 
           NOP             2
	.dwpsn	"process.c",14,14
           CMPLT   .L2     B4,11,B0          ; |14| 
   [ B0]   B       .S1     L1                ; |14| 
           NOP             5
           ; BRANCHCC OCCURS {L1}            ; |14| 
DW$L$_inicialitzacio$2$E:
;** --------------------------------------------------------------------------*
L2:    
	.dwpsn	"process.c",17,2
;----------------------------------------------------------------------
;  17 | guany = sqrtf(1-guany);                                                
;----------------------------------------------------------------------
           MVKL    .S1     _guany,A3         ; |17| 
           MVKH    .S1     _guany,A3         ; |17| 
           LDW     .D1T1   *A3,A3            ; |17| 
           ZERO    .L2     B4                ; |17| 
           MVKH    .S2     0x3f800000,B4     ; |17| 
           CALL    .S1     _sqrtf            ; |17| 
           MVKL    .S2     RL0,B3            ; |17| 
           SUBSP   .L1X    B4,A3,A4          ; |17| 
           MVKH    .S2     RL0,B3            ; |17| 
           NOP             2
RL0:       ; CALL OCCURS {_sqrtf}            ; |17| 
           MVKL    .S2     _guany,B4         ; |17| 
           MVKH    .S2     _guany,B4         ; |17| 
           STW     .D2T1   A4,*B4            ; |17| 
           NOP             2
	.dwpsn	"process.c",18,1
           LDW     .D2T2   *++SP(8),B3       ; |18| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |18| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |18| 

DW$8	.dwtag  DW_TAG_loop
	.dwattr DW$8, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L1:1:1306141625")
	.dwattr DW$8, DW_AT_begin_file("process.c")
	.dwattr DW$8, DW_AT_begin_line(0x0e)
	.dwattr DW$8, DW_AT_end_line(0x0f)
DW$9	.dwtag  DW_TAG_loop_range
	.dwattr DW$9, DW_AT_low_pc(DW$L$_inicialitzacio$2$B)
	.dwattr DW$9, DW_AT_high_pc(DW$L$_inicialitzacio$2$E)
	.dwendtag DW$8

	.dwattr DW$6, DW_AT_end_file("process.c")
	.dwattr DW$6, DW_AT_end_line(0x12)
	.dwattr DW$6, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$6

	.sect	".text"
	.global	_fir

DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("fir"), DW_AT_symbol_name("_fir")
	.dwattr DW$10, DW_AT_low_pc(_fir)
	.dwattr DW$10, DW_AT_high_pc(0x00)
	.dwattr DW$10, DW_AT_begin_file("process.c")
	.dwattr DW$10, DW_AT_begin_line(0x14)
	.dwattr DW$10, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",20,54

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
;  20 | void fir(float *x, float *y, float *h, int k, int n) {                 
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           ADDK    .S2     -32,SP            ; |20| 
	.dwcfa	0x0e, 32
DW$11	.dwtag  DW_TAG_formal_parameter, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$11, DW_AT_type(*DW$T$20)
	.dwattr DW$11, DW_AT_location[DW_OP_reg4]
DW$12	.dwtag  DW_TAG_formal_parameter, DW_AT_name("y"), DW_AT_symbol_name("_y")
	.dwattr DW$12, DW_AT_type(*DW$T$20)
	.dwattr DW$12, DW_AT_location[DW_OP_reg20]
DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$13, DW_AT_type(*DW$T$20)
	.dwattr DW$13, DW_AT_location[DW_OP_reg6]
DW$14	.dwtag  DW_TAG_formal_parameter, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$14, DW_AT_type(*DW$T$10)
	.dwattr DW$14, DW_AT_location[DW_OP_reg22]
DW$15	.dwtag  DW_TAG_formal_parameter, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$15, DW_AT_type(*DW$T$10)
	.dwattr DW$15, DW_AT_location[DW_OP_reg8]
DW$16	.dwtag  DW_TAG_variable, DW_AT_name("x"), DW_AT_symbol_name("_x")
	.dwattr DW$16, DW_AT_type(*DW$T$20)
	.dwattr DW$16, DW_AT_location[DW_OP_breg31 4]
DW$17	.dwtag  DW_TAG_variable, DW_AT_name("y"), DW_AT_symbol_name("_y")
	.dwattr DW$17, DW_AT_type(*DW$T$20)
	.dwattr DW$17, DW_AT_location[DW_OP_breg31 8]
DW$18	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$18, DW_AT_type(*DW$T$20)
	.dwattr DW$18, DW_AT_location[DW_OP_breg31 12]
DW$19	.dwtag  DW_TAG_variable, DW_AT_name("k"), DW_AT_symbol_name("_k")
	.dwattr DW$19, DW_AT_type(*DW$T$10)
	.dwattr DW$19, DW_AT_location[DW_OP_breg31 16]
DW$20	.dwtag  DW_TAG_variable, DW_AT_name("n"), DW_AT_symbol_name("_n")
	.dwattr DW$20, DW_AT_type(*DW$T$10)
	.dwattr DW$20, DW_AT_location[DW_OP_breg31 20]
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$21, DW_AT_type(*DW$T$10)
	.dwattr DW$21, DW_AT_location[DW_OP_breg31 24]
DW$22	.dwtag  DW_TAG_variable, DW_AT_name("j"), DW_AT_symbol_name("_j")
	.dwattr DW$22, DW_AT_type(*DW$T$10)
	.dwattr DW$22, DW_AT_location[DW_OP_breg31 28]
;----------------------------------------------------------------------
;  21 | int i,j;                                                               
;----------------------------------------------------------------------
           STW     .D2T1   A8,*+SP(20)       ; |20| 
           STW     .D2T1   A6,*+SP(12)       ; |20| 
           STW     .D2T2   B4,*+SP(8)        ; |20| 

           STW     .D2T1   A4,*+SP(4)        ; |20| 
||         MV      .L1X    B6,A3             ; |20| 

           STW     .D2T1   A3,*+SP(16)       ; |20| 
           NOP             2
	.dwpsn	"process.c",22,7
;----------------------------------------------------------------------
;  22 | for (i = 0; i < n; i++) {                                              
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |22| 
           STW     .D2T2   B4,*+SP(24)       ; |22| 
           NOP             2
	.dwpsn	"process.c",22,14
           LDW     .D2T2   *+SP(24),B5       ; |22| 
           NOP             4
           CMPLT   .L2X    B5,A8,B0          ; |22| 
   [!B0]   B       .S1     L6                ; |22| 
           NOP             5
           ; BRANCHCC OCCURS {L6}            ; |22| 
;** --------------------------------------------------------------------------*
;**   BEGIN LOOP L3
;** --------------------------------------------------------------------------*
L3:    
DW$L$_fir$2$B:

DW$23	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
DW$24	.dwtag  DW_TAG_variable, DW_AT_name("accum"), DW_AT_symbol_name("_accum")
	.dwattr DW$24, DW_AT_type(*DW$T$16)
	.dwattr DW$24, DW_AT_location[DW_OP_breg31 32]
	.dwpsn	"process.c",23,9
;----------------------------------------------------------------------
;  23 | float accum = 0;                                                       
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |23| 
           STW     .D2T2   B4,*+SP(32)       ; |23| 
           NOP             2
	.dwpsn	"process.c",24,8
;----------------------------------------------------------------------
;  24 | for (j = 0; j < k; j++)                                                
;----------------------------------------------------------------------
           STW     .D2T2   B4,*+SP(28)       ; |24| 
           NOP             2
	.dwpsn	"process.c",24,15
           LDW     .D2T2   *+SP(28),B5       ; |24| 
           LDW     .D2T2   *+SP(16),B4       ; |24| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |24| 
   [!B0]   B       .S1     L5                ; |24| 
           NOP             5
           ; BRANCHCC OCCURS {L5}            ; |24| 
DW$L$_fir$2$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L4:    
DW$L$_fir$3$B:
	.dwpsn	"process.c",25,4
;----------------------------------------------------------------------
;  25 | accum += h[j]*x[i-j];                                                  
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(12),B6       ; |25| 
           LDW     .D2T2   *+SP(24),B8       ; |25| 
           LDW     .D2T2   *+SP(4),B4        ; |25| 
           MV      .L2     B5,B7             ; |25| 
           LDW     .D2T2   *+SP(32),B9       ; |25| 
           NOP             1

           SUB     .L2     B8,B7,B6          ; |25| 
||         LDW     .D2T2   *+B6[B5],B5       ; |25| 

           LDW     .D2T2   *+B4[B6],B6       ; |25| 
           NOP             4
           MPYSP   .M2     B6,B5,B5          ; |25| 
           NOP             3
           ADDSP   .L2     B5,B9,B4          ; |25| 
           NOP             3
           STW     .D2T2   B4,*+SP(32)       ; |25| 
           NOP             2
	.dwpsn	"process.c",24,22
           ADD     .L2     1,B7,B4           ; |24| 
           STW     .D2T2   B4,*+SP(28)       ; |24| 
           NOP             2
	.dwpsn	"process.c",24,15
           LDW     .D2T2   *+SP(16),B4       ; |24| 
           LDW     .D2T2   *+SP(28),B5       ; |24| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |24| 
   [ B0]   B       .S1     L4                ; |24| 
           NOP             5
           ; BRANCHCC OCCURS {L4}            ; |24| 
DW$L$_fir$3$E:
;** --------------------------------------------------------------------------*
L5:    
DW$L$_fir$4$B:
	.dwpsn	"process.c",26,3
;----------------------------------------------------------------------
;  26 | y[i] = accum;                                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B5       ; |26| 
           LDW     .D2T2   *+SP(8),B6        ; |26| 
           LDW     .D2T2   *+SP(32),B4       ; |26| 
           NOP             4
           STW     .D2T2   B4,*+B6[B5]       ; |26| 
           NOP             2
	.dwendtag DW$23

	.dwpsn	"process.c",22,21
           LDW     .D2T2   *+SP(24),B4       ; |22| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |22| 
           STW     .D2T2   B4,*+SP(24)       ; |22| 
           NOP             2
	.dwpsn	"process.c",22,14
           LDW     .D2T2   *+SP(20),B4       ; |22| 
           LDW     .D2T2   *+SP(24),B5       ; |22| 
           NOP             4
           CMPLT   .L2     B5,B4,B0          ; |22| 
   [ B0]   B       .S1     L3                ; |22| 
           NOP             5
           ; BRANCHCC OCCURS {L3}            ; |22| 
DW$L$_fir$4$E:
;** --------------------------------------------------------------------------*
L6:    
	.dwpsn	"process.c",28,1
           ADDK    .S2     32,SP             ; |28| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |28| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |28| 

DW$25	.dwtag  DW_TAG_loop
	.dwattr DW$25, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L3:1:1306141625")
	.dwattr DW$25, DW_AT_begin_file("process.c")
	.dwattr DW$25, DW_AT_begin_line(0x16)
	.dwattr DW$25, DW_AT_end_line(0x1b)
DW$26	.dwtag  DW_TAG_loop_range
	.dwattr DW$26, DW_AT_low_pc(DW$L$_fir$2$B)
	.dwattr DW$26, DW_AT_high_pc(DW$L$_fir$2$E)
DW$27	.dwtag  DW_TAG_loop_range
	.dwattr DW$27, DW_AT_low_pc(DW$L$_fir$4$B)
	.dwattr DW$27, DW_AT_high_pc(DW$L$_fir$4$E)

DW$28	.dwtag  DW_TAG_loop
	.dwattr DW$28, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L4:2:1306141625")
	.dwattr DW$28, DW_AT_begin_file("process.c")
	.dwattr DW$28, DW_AT_begin_line(0x18)
	.dwattr DW$28, DW_AT_end_line(0x19)
DW$29	.dwtag  DW_TAG_loop_range
	.dwattr DW$29, DW_AT_low_pc(DW$L$_fir$3$B)
	.dwattr DW$29, DW_AT_high_pc(DW$L$_fir$3$E)
	.dwendtag DW$28

	.dwendtag DW$25

	.dwattr DW$10, DW_AT_end_file("process.c")
	.dwattr DW$10, DW_AT_end_line(0x1c)
	.dwattr DW$10, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$10

	.sect	".text"
	.global	_processFIR

DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("processFIR"), DW_AT_symbol_name("_processFIR")
	.dwattr DW$30, DW_AT_low_pc(_processFIR)
	.dwattr DW$30, DW_AT_high_pc(0x00)
	.dwattr DW$30, DW_AT_begin_file("process.c")
	.dwattr DW$30, DW_AT_begin_line(0x1f)
	.dwattr DW$30, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",32,1

	.dwfde DW$CIE
DW$31	.dwtag  DW_TAG_variable, DW_AT_name("x"), DW_AT_symbol_name("_x$1")
	.dwattr DW$31, DW_AT_type(*DW$T$30)
	.dwattr DW$31, DW_AT_location[DW_OP_addr _x$1]
;----------------------------------------------------------------------
;  31 | void processFIR(float *block, float *h)                                
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
           STW     .D2T2   B3,*SP--(16)      ; |32| 
           NOP             2
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 19, 0
DW$32	.dwtag  DW_TAG_formal_parameter, DW_AT_name("block"), DW_AT_symbol_name("_block")
	.dwattr DW$32, DW_AT_type(*DW$T$20)
	.dwattr DW$32, DW_AT_location[DW_OP_reg4]
DW$33	.dwtag  DW_TAG_formal_parameter, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$33, DW_AT_type(*DW$T$20)
	.dwattr DW$33, DW_AT_location[DW_OP_reg20]
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("block"), DW_AT_symbol_name("_block")
	.dwattr DW$34, DW_AT_type(*DW$T$20)
	.dwattr DW$34, DW_AT_location[DW_OP_breg31 4]
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("h"), DW_AT_symbol_name("_h")
	.dwattr DW$35, DW_AT_type(*DW$T$20)
	.dwattr DW$35, DW_AT_location[DW_OP_breg31 8]
DW$36	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$36, DW_AT_type(*DW$T$10)
	.dwattr DW$36, DW_AT_location[DW_OP_breg31 12]
;----------------------------------------------------------------------
;  33 | int i;                                                                 
;  34 | static float x[(L_FIR-1)+N] = {0};         // FIR Input buffer
;     |                                                                        
;----------------------------------------------------------------------

           STW     .D2T1   A4,*+SP(4)        ; |32| 
||         MV      .L1X    B4,A3             ; |32| 

           STW     .D2T1   A3,*+SP(8)        ; |32| 
           NOP             2
	.dwpsn	"process.c",36,10
;----------------------------------------------------------------------
;  36 | for (i=0; i<N; i++) x[L_FIR-1+i] = block[i];                           
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |36| 
           STW     .D2T2   B4,*+SP(12)       ; |36| 
           NOP             2
	.dwpsn	"process.c",36,15
           MVK     .S2     1000,B5           ; |36| 
           CMPLT   .L2     B4,B5,B0          ; |36| 
   [!B0]   B       .S1     L8                ; |36| 
           NOP             5
           ; BRANCHCC OCCURS {L8}            ; |36| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L7:    
DW$L$_processFIR$2$B:
	.dwpsn	"process.c",36,25
           LDW     .D2T2   *+SP(4),B6        ; |36| 
           MV      .L2     B4,B5
           SHL     .S2     B4,2,B4           ; |36| 
           MVKL    .S1     _x$1,A3           ; |36| 
           ADDK    .S2     40,B4             ; |36| 
           LDW     .D2T2   *+B6[B5],B5       ; |36| 
           MVKH    .S1     _x$1,A3           ; |36| 
           ADD     .L2X    A3,B4,B4          ; |36| 
           NOP             2
           STW     .D2T2   B5,*B4            ; |36| 
           NOP             2
	.dwpsn	"process.c",36,20
           LDW     .D2T2   *+SP(12),B4       ; |36| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |36| 
           STW     .D2T2   B4,*+SP(12)       ; |36| 
           NOP             2
	.dwpsn	"process.c",36,15
           MVK     .S2     1000,B5           ; |36| 
           CMPLT   .L2     B4,B5,B0          ; |36| 
   [ B0]   B       .S1     L7                ; |36| 
           NOP             5
           ; BRANCHCC OCCURS {L7}            ; |36| 
DW$L$_processFIR$2$E:
;** --------------------------------------------------------------------------*
L8:    
	.dwpsn	"process.c",37,5
;----------------------------------------------------------------------
;  37 | fir(&x[L_FIR], block, h, L_FIR, N);                                    
;----------------------------------------------------------------------

           CALL    .S1     _fir              ; |37| 
||         LDW     .D2T1   *+SP(8),A6        ; |37| 

           LDW     .D2T2   *+SP(4),B4        ; |37| 
           MVKL    .S1     _x$1+44,A4        ; |37| 
           MVKL    .S2     RL1,B3            ; |37| 

           MVK     .S2     0xb,B6            ; |37| 
||         MVK     .S1     0x3e8,A8          ; |37| 

           MVKH    .S1     _x$1+44,A4        ; |37| 
||         MVKH    .S2     RL1,B3            ; |37| 

RL1:       ; CALL OCCURS {_fir}              ; |37| 
	.dwpsn	"process.c",38,10
;----------------------------------------------------------------------
;  38 | for (i=0; i<(L_FIR-1); i++) x[i] = x[i+N];                             
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |38| 
           STW     .D2T2   B4,*+SP(12)       ; |38| 
           NOP             2
	.dwpsn	"process.c",38,15
           CMPLT   .L2     B4,10,B0          ; |38| 
   [!B0]   B       .S1     L10               ; |38| 
           NOP             5
           ; BRANCHCC OCCURS {L10}           ; |38| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L9:    
DW$L$_processFIR$4$B:
	.dwpsn	"process.c",38,33

           MVKL    .S1     _x$1,A3           ; |38| 
||         SHL     .S2     B4,2,B4           ; |38| 

           MVKH    .S1     _x$1,A3           ; |38| 
||         ADDK    .S2     4000,B4           ; |38| 

           ADD     .L1X    A3,B4,A3          ; |38| 

           LDW     .D1T1   *A3,A3            ; |38| 
||         LDW     .D2T2   *+SP(12),B5       ; |38| 

           MVKL    .S2     _x$1,B9           ; |38| 
           MVKH    .S2     _x$1,B9           ; |38| 
           NOP             2
           STW     .D2T1   A3,*+B9[B5]       ; |38| 
           NOP             2
	.dwpsn	"process.c",38,28
           LDW     .D2T2   *+SP(12),B4       ; |38| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |38| 
           STW     .D2T2   B4,*+SP(12)       ; |38| 
           NOP             2
	.dwpsn	"process.c",38,15
           CMPLT   .L2     B4,10,B0          ; |38| 
   [ B0]   B       .S1     L9                ; |38| 
           NOP             5
           ; BRANCHCC OCCURS {L9}            ; |38| 
DW$L$_processFIR$4$E:
;** --------------------------------------------------------------------------*
L10:    
	.dwpsn	"process.c",39,1
           LDW     .D2T2   *++SP(16),B3      ; |39| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |39| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |39| 

DW$37	.dwtag  DW_TAG_loop
	.dwattr DW$37, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L9:1:1306141625")
	.dwattr DW$37, DW_AT_begin_file("process.c")
	.dwattr DW$37, DW_AT_begin_line(0x26)
	.dwattr DW$37, DW_AT_end_line(0x26)
DW$38	.dwtag  DW_TAG_loop_range
	.dwattr DW$38, DW_AT_low_pc(DW$L$_processFIR$4$B)
	.dwattr DW$38, DW_AT_high_pc(DW$L$_processFIR$4$E)
	.dwendtag DW$37


DW$39	.dwtag  DW_TAG_loop
	.dwattr DW$39, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L7:1:1306141625")
	.dwattr DW$39, DW_AT_begin_file("process.c")
	.dwattr DW$39, DW_AT_begin_line(0x24)
	.dwattr DW$39, DW_AT_end_line(0x24)
DW$40	.dwtag  DW_TAG_loop_range
	.dwattr DW$40, DW_AT_low_pc(DW$L$_processFIR$2$B)
	.dwattr DW$40, DW_AT_high_pc(DW$L$_processFIR$2$E)
	.dwendtag DW$39

	.dwattr DW$30, DW_AT_end_file("process.c")
	.dwattr DW$30, DW_AT_end_line(0x27)
	.dwattr DW$30, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$30

	.sect	".text"
	.global	_calculaEco

DW$41	.dwtag  DW_TAG_subprogram, DW_AT_name("calculaEco"), DW_AT_symbol_name("_calculaEco")
	.dwattr DW$41, DW_AT_low_pc(_calculaEco)
	.dwattr DW$41, DW_AT_high_pc(0x00)
	.dwattr DW$41, DW_AT_begin_file("process.c")
	.dwattr DW$41, DW_AT_begin_line(0x2a)
	.dwattr DW$41, DW_AT_begin_column(0x06)
	.dwpsn	"process.c",42,35

	.dwfde DW$CIE

;******************************************************************************
;* FUNCTION NAME: _calculaEco                                                 *
;*                                                                            *
;*   Regs Modified     : A1,A3,A4,A6,A8,B0,B3,B4,B5,B6,B7,B8,B9,SP            *
;*   Regs Used         : A1,A3,A4,A6,A8,B0,B3,B4,B5,B6,B7,B8,B9,SP            *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_calculaEco:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  42 | void calculaEco(float * io_block) {                                    
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(16)      ; |42| 
           NOP             2
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 19, 0
DW$42	.dwtag  DW_TAG_formal_parameter, DW_AT_name("io_block"), DW_AT_symbol_name("_io_block")
	.dwattr DW$42, DW_AT_type(*DW$T$20)
	.dwattr DW$42, DW_AT_location[DW_OP_reg4]
DW$43	.dwtag  DW_TAG_variable, DW_AT_name("io_block"), DW_AT_symbol_name("_io_block")
	.dwattr DW$43, DW_AT_type(*DW$T$20)
	.dwattr DW$43, DW_AT_location[DW_OP_breg31 4]
DW$44	.dwtag  DW_TAG_variable, DW_AT_name("i"), DW_AT_symbol_name("_i")
	.dwattr DW$44, DW_AT_type(*DW$T$10)
	.dwattr DW$44, DW_AT_location[DW_OP_breg31 8]
DW$45	.dwtag  DW_TAG_variable, DW_AT_name("j"), DW_AT_symbol_name("_j")
	.dwattr DW$45, DW_AT_type(*DW$T$10)
	.dwattr DW$45, DW_AT_location[DW_OP_breg31 12]
           STW     .D2T1   A4,*+SP(4)        ; |42| 
           NOP             2
	.dwpsn	"process.c",43,9
;----------------------------------------------------------------------
;  43 | int i, j = 0;                                                          
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |43| 
           STW     .D2T1   A3,*+SP(12)       ; |43| 
           NOP             2
	.dwpsn	"process.c",44,2
;----------------------------------------------------------------------
;  44 | processFIR(retard,hFIR);            // Procesa bloque                  
;----------------------------------------------------------------------
           CALL    .S1     _processFIR       ; |44| 
           MVKL    .S2     _retard,B5        ; |44| 
           MVKL    .S2     RL2,B3            ; |44| 
           MVKL    .S1     _hFIR,A3          ; |44| 

           MVKH    .S1     _hFIR,A3          ; |44| 
||         MVKH    .S2     _retard,B5        ; |44| 

           MV      .L2X    A3,B4             ; |44| 
||         MV      .L1X    B5,A4             ; |44| 
||         MVKH    .S2     RL2,B3            ; |44| 

RL2:       ; CALL OCCURS {_processFIR}       ; |44| 
	.dwpsn	"process.c",45,7
;----------------------------------------------------------------------
;  45 | for (i = 0; i < N; i++)                                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |45| 
           STW     .D2T2   B4,*+SP(8)        ; |45| 
           NOP             2
	.dwpsn	"process.c",45,14
           MVK     .S2     1000,B5           ; |45| 
           CMPLT   .L2     B4,B5,B0          ; |45| 
   [!B0]   B       .S1     L12               ; |45| 
           NOP             5
           ; BRANCHCC OCCURS {L12}           ; |45| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L11:    
DW$L$_calculaEco$2$B:
	.dwpsn	"process.c",46,3
;----------------------------------------------------------------------
;  46 | io_block[i] = io_block[i]*guany + retard[i];                           
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B6        ; |46| 
           MVKL    .S1     _guany,A3         ; |46| 
           MVKH    .S1     _guany,A3         ; |46| 
           LDW     .D1T1   *A3,A3            ; |46| 
           MVKL    .S2     _retard,B9        ; |46| 
           LDW     .D2T2   *+B6[B4],B6       ; |46| 
           MVKH    .S2     _retard,B9        ; |46| 
           MV      .L2     B4,B5             ; |46| 
           LDW     .D2T2   *+B9[B5],B4       ; |46| 
           LDW     .D2T2   *+SP(4),B8        ; |46| 
           MPYSP   .M1X    A3,B6,A3          ; |46| 
           NOP             3
           ADDSP   .L1X    B4,A3,A3          ; |46| 
           NOP             3
           STW     .D2T1   A3,*+B8[B5]       ; |46| 
           NOP             2
	.dwpsn	"process.c",45,21
           LDW     .D2T2   *+SP(8),B4        ; |45| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |45| 
           STW     .D2T2   B4,*+SP(8)        ; |45| 
           NOP             2
	.dwpsn	"process.c",45,14
           MVK     .S2     1000,B5           ; |45| 
           CMPLT   .L2     B4,B5,B0          ; |45| 
   [ B0]   B       .S1     L11               ; |45| 
           NOP             5
           ; BRANCHCC OCCURS {L11}           ; |45| 
DW$L$_calculaEco$2$E:
;** --------------------------------------------------------------------------*
L12:    
	.dwpsn	"process.c",47,7
;----------------------------------------------------------------------
;  47 | for (i = N; i < D; i++)                                                
;----------------------------------------------------------------------
           MVK     .S1     1000,A3           ; |47| 
           STW     .D2T1   A3,*+SP(8)        ; |47| 
           NOP             2
	.dwpsn	"process.c",47,14
           MVK     .S2     2400,B5           ; |47| 
           CMPLT   .L2X    A3,B5,B0          ; |47| 
   [!B0]   B       .S1     L14               ; |47| 
           MV      .L2X    A3,B4
           NOP             4
           ; BRANCHCC OCCURS {L14}           ; |47| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L13:    
DW$L$_calculaEco$4$B:
	.dwpsn	"process.c",48,3
;----------------------------------------------------------------------
;  48 | retard[i-N] = retard[i];                                               
;----------------------------------------------------------------------
           MVKL    .S2     _retard,B5        ; |48| 

           MVKH    .S2     _retard,B5        ; |48| 
||         MV      .L2     B4,B6

           LDW     .D2T2   *+B5[B6],B5       ; |48| 
           SHL     .S2     B4,2,B4           ; |48| 
           MVKL    .S1     _retard,A3        ; |48| 

           ADDK    .S2     -4000,B4          ; |48| 
||         MVKH    .S1     _retard,A3        ; |48| 

           ADD     .L2X    A3,B4,B4          ; |48| 
           STW     .D2T2   B5,*B4            ; |48| 
           NOP             2
	.dwpsn	"process.c",47,21
           LDW     .D2T2   *+SP(8),B4        ; |47| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |47| 
           STW     .D2T2   B4,*+SP(8)        ; |47| 
           NOP             2
	.dwpsn	"process.c",47,14
           MVK     .S2     2400,B5           ; |47| 
           CMPLT   .L2     B4,B5,B0          ; |47| 
   [ B0]   B       .S1     L13               ; |47| 
           NOP             5
           ; BRANCHCC OCCURS {L13}           ; |47| 
DW$L$_calculaEco$4$E:
;** --------------------------------------------------------------------------*
L14:    
	.dwpsn	"process.c",49,7
;----------------------------------------------------------------------
;  49 | for (i = D-N; i < D; i++)                                              
;----------------------------------------------------------------------
           MVK     .S1     1400,A3           ; |49| 
           STW     .D2T1   A3,*+SP(8)        ; |49| 
           NOP             2
	.dwpsn	"process.c",49,16
           CMPLT   .L2X    A3,B5,B0          ; |49| 
   [!B0]   B       .S1     L16               ; |49| 
           NOP             5
           ; BRANCHCC OCCURS {L16}           ; |49| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L15:    
DW$L$_calculaEco$6$B:
	.dwpsn	"process.c",50,3
;----------------------------------------------------------------------
;  50 | retard[i] = io_block[j++];                                             
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(12),B4       ; |50| 
           LDW     .D2T2   *+SP(4),B7        ; |50| 
           LDW     .D2T2   *+SP(8),B6        ; |50| 
           MVKL    .S2     _retard,B9        ; |50| 
           MVKH    .S2     _retard,B9        ; |50| 
           ADD     .L2     1,B4,B5           ; |50| 
           STW     .D2T2   B5,*+SP(12)       ; |50| 
           LDW     .D2T2   *+B7[B4],B5       ; |50| 
           NOP             4
           STW     .D2T2   B5,*+B9[B6]       ; |50| 
           NOP             2
	.dwpsn	"process.c",49,23
           LDW     .D2T2   *+SP(8),B4        ; |49| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |49| 
           STW     .D2T2   B4,*+SP(8)        ; |49| 
           NOP             2
	.dwpsn	"process.c",49,16
           MVK     .S1     2400,A3           ; |49| 
           CMPLT   .L1X    B4,A3,A1          ; |49| 
   [ A1]   B       .S1     L15               ; |49| 
           NOP             5
           ; BRANCHCC OCCURS {L15}           ; |49| 
DW$L$_calculaEco$6$E:
;** --------------------------------------------------------------------------*
L16:    
	.dwpsn	"process.c",51,1
           LDW     .D2T2   *++SP(16),B3      ; |51| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |51| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |51| 

DW$46	.dwtag  DW_TAG_loop
	.dwattr DW$46, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L15:1:1306141625")
	.dwattr DW$46, DW_AT_begin_file("process.c")
	.dwattr DW$46, DW_AT_begin_line(0x31)
	.dwattr DW$46, DW_AT_end_line(0x32)
DW$47	.dwtag  DW_TAG_loop_range
	.dwattr DW$47, DW_AT_low_pc(DW$L$_calculaEco$6$B)
	.dwattr DW$47, DW_AT_high_pc(DW$L$_calculaEco$6$E)
	.dwendtag DW$46


DW$48	.dwtag  DW_TAG_loop
	.dwattr DW$48, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L13:1:1306141625")
	.dwattr DW$48, DW_AT_begin_file("process.c")
	.dwattr DW$48, DW_AT_begin_line(0x2f)
	.dwattr DW$48, DW_AT_end_line(0x30)
DW$49	.dwtag  DW_TAG_loop_range
	.dwattr DW$49, DW_AT_low_pc(DW$L$_calculaEco$4$B)
	.dwattr DW$49, DW_AT_high_pc(DW$L$_calculaEco$4$E)
	.dwendtag DW$48


DW$50	.dwtag  DW_TAG_loop
	.dwattr DW$50, DW_AT_name("C:\Documents and Settings\lc2125\Escritorio\generador_eco_bo\process.asm:L11:1:1306141625")
	.dwattr DW$50, DW_AT_begin_file("process.c")
	.dwattr DW$50, DW_AT_begin_line(0x2d)
	.dwattr DW$50, DW_AT_end_line(0x2e)
DW$51	.dwtag  DW_TAG_loop_range
	.dwattr DW$51, DW_AT_low_pc(DW$L$_calculaEco$2$B)
	.dwattr DW$51, DW_AT_high_pc(DW$L$_calculaEco$2$E)
	.dwendtag DW$50

	.dwattr DW$41, DW_AT_end_file("process.c")
	.dwattr DW$41, DW_AT_end_line(0x33)
	.dwattr DW$41, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$41

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_sqrtf

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

DW$T$19	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$19, DW_AT_language(DW_LANG_C)

DW$T$21	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$21, DW_AT_language(DW_LANG_C)
DW$52	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
DW$53	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
DW$54	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
DW$55	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$56	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
	.dwendtag DW$T$21


DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$23, DW_AT_language(DW_LANG_C)
DW$57	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
DW$58	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
	.dwendtag DW$T$23


DW$T$25	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$25, DW_AT_language(DW_LANG_C)
DW$59	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$20)
	.dwendtag DW$T$25

DW$T$10	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$10, DW_AT_byte_size(0x04)
DW$T$16	.dwtag  DW_TAG_base_type, DW_AT_name("float")
	.dwattr DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr DW$T$16, DW_AT_byte_size(0x04)
DW$T$20	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$20, DW_AT_address_class(0x20)

DW$T$26	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$26, DW_AT_language(DW_LANG_C)
DW$60	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$16)
	.dwendtag DW$T$26


DW$T$28	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$28, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$28, DW_AT_byte_size(0x2c)
DW$61	.dwtag  DW_TAG_subrange_type
	.dwattr DW$61, DW_AT_upper_bound(0x0a)
	.dwendtag DW$T$28


DW$T$29	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$29, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$29, DW_AT_byte_size(0x2580)
DW$62	.dwtag  DW_TAG_subrange_type
	.dwattr DW$62, DW_AT_upper_bound(0x95f)
	.dwendtag DW$T$29


DW$T$30	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$30, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$30, DW_AT_byte_size(0xfc8)
DW$63	.dwtag  DW_TAG_subrange_type
	.dwattr DW$63, DW_AT_upper_bound(0x3f1)
	.dwendtag DW$T$30


	.dwattr DW$41, DW_AT_external(0x01)
	.dwattr DW$10, DW_AT_external(0x01)
	.dwattr DW$6, DW_AT_external(0x01)
	.dwattr DW$30, DW_AT_external(0x01)
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

DW$64	.dwtag  DW_TAG_assign_register, DW_AT_name("A0")
	.dwattr DW$64, DW_AT_location[DW_OP_reg0]
DW$65	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$65, DW_AT_location[DW_OP_reg1]
DW$66	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$66, DW_AT_location[DW_OP_reg2]
DW$67	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$67, DW_AT_location[DW_OP_reg3]
DW$68	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$68, DW_AT_location[DW_OP_reg4]
DW$69	.dwtag  DW_TAG_assign_register, DW_AT_name("A5")
	.dwattr DW$69, DW_AT_location[DW_OP_reg5]
DW$70	.dwtag  DW_TAG_assign_register, DW_AT_name("A6")
	.dwattr DW$70, DW_AT_location[DW_OP_reg6]
DW$71	.dwtag  DW_TAG_assign_register, DW_AT_name("A7")
	.dwattr DW$71, DW_AT_location[DW_OP_reg7]
DW$72	.dwtag  DW_TAG_assign_register, DW_AT_name("A8")
	.dwattr DW$72, DW_AT_location[DW_OP_reg8]
DW$73	.dwtag  DW_TAG_assign_register, DW_AT_name("A9")
	.dwattr DW$73, DW_AT_location[DW_OP_reg9]
DW$74	.dwtag  DW_TAG_assign_register, DW_AT_name("A10")
	.dwattr DW$74, DW_AT_location[DW_OP_reg10]
DW$75	.dwtag  DW_TAG_assign_register, DW_AT_name("A11")
	.dwattr DW$75, DW_AT_location[DW_OP_reg11]
DW$76	.dwtag  DW_TAG_assign_register, DW_AT_name("A12")
	.dwattr DW$76, DW_AT_location[DW_OP_reg12]
DW$77	.dwtag  DW_TAG_assign_register, DW_AT_name("A13")
	.dwattr DW$77, DW_AT_location[DW_OP_reg13]
DW$78	.dwtag  DW_TAG_assign_register, DW_AT_name("A14")
	.dwattr DW$78, DW_AT_location[DW_OP_reg14]
DW$79	.dwtag  DW_TAG_assign_register, DW_AT_name("A15")
	.dwattr DW$79, DW_AT_location[DW_OP_reg15]
DW$80	.dwtag  DW_TAG_assign_register, DW_AT_name("B0")
	.dwattr DW$80, DW_AT_location[DW_OP_reg16]
DW$81	.dwtag  DW_TAG_assign_register, DW_AT_name("B1")
	.dwattr DW$81, DW_AT_location[DW_OP_reg17]
DW$82	.dwtag  DW_TAG_assign_register, DW_AT_name("B2")
	.dwattr DW$82, DW_AT_location[DW_OP_reg18]
DW$83	.dwtag  DW_TAG_assign_register, DW_AT_name("B3")
	.dwattr DW$83, DW_AT_location[DW_OP_reg19]
DW$84	.dwtag  DW_TAG_assign_register, DW_AT_name("B4")
	.dwattr DW$84, DW_AT_location[DW_OP_reg20]
DW$85	.dwtag  DW_TAG_assign_register, DW_AT_name("B5")
	.dwattr DW$85, DW_AT_location[DW_OP_reg21]
DW$86	.dwtag  DW_TAG_assign_register, DW_AT_name("B6")
	.dwattr DW$86, DW_AT_location[DW_OP_reg22]
DW$87	.dwtag  DW_TAG_assign_register, DW_AT_name("B7")
	.dwattr DW$87, DW_AT_location[DW_OP_reg23]
DW$88	.dwtag  DW_TAG_assign_register, DW_AT_name("B8")
	.dwattr DW$88, DW_AT_location[DW_OP_reg24]
DW$89	.dwtag  DW_TAG_assign_register, DW_AT_name("B9")
	.dwattr DW$89, DW_AT_location[DW_OP_reg25]
DW$90	.dwtag  DW_TAG_assign_register, DW_AT_name("B10")
	.dwattr DW$90, DW_AT_location[DW_OP_reg26]
DW$91	.dwtag  DW_TAG_assign_register, DW_AT_name("B11")
	.dwattr DW$91, DW_AT_location[DW_OP_reg27]
DW$92	.dwtag  DW_TAG_assign_register, DW_AT_name("B12")
	.dwattr DW$92, DW_AT_location[DW_OP_reg28]
DW$93	.dwtag  DW_TAG_assign_register, DW_AT_name("B13")
	.dwattr DW$93, DW_AT_location[DW_OP_reg29]
DW$94	.dwtag  DW_TAG_assign_register, DW_AT_name("DP")
	.dwattr DW$94, DW_AT_location[DW_OP_reg30]
DW$95	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$95, DW_AT_location[DW_OP_reg31]
DW$96	.dwtag  DW_TAG_assign_register, DW_AT_name("FP")
	.dwattr DW$96, DW_AT_location[DW_OP_regx 0x20]
DW$97	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$97, DW_AT_location[DW_OP_regx 0x21]
DW$98	.dwtag  DW_TAG_assign_register, DW_AT_name("IRP")
	.dwattr DW$98, DW_AT_location[DW_OP_regx 0x22]
DW$99	.dwtag  DW_TAG_assign_register, DW_AT_name("IFR")
	.dwattr DW$99, DW_AT_location[DW_OP_regx 0x23]
DW$100	.dwtag  DW_TAG_assign_register, DW_AT_name("NRP")
	.dwattr DW$100, DW_AT_location[DW_OP_regx 0x24]
DW$101	.dwtag  DW_TAG_assign_register, DW_AT_name("A16")
	.dwattr DW$101, DW_AT_location[DW_OP_regx 0x25]
DW$102	.dwtag  DW_TAG_assign_register, DW_AT_name("A17")
	.dwattr DW$102, DW_AT_location[DW_OP_regx 0x26]
DW$103	.dwtag  DW_TAG_assign_register, DW_AT_name("A18")
	.dwattr DW$103, DW_AT_location[DW_OP_regx 0x27]
DW$104	.dwtag  DW_TAG_assign_register, DW_AT_name("A19")
	.dwattr DW$104, DW_AT_location[DW_OP_regx 0x28]
DW$105	.dwtag  DW_TAG_assign_register, DW_AT_name("A20")
	.dwattr DW$105, DW_AT_location[DW_OP_regx 0x29]
DW$106	.dwtag  DW_TAG_assign_register, DW_AT_name("A21")
	.dwattr DW$106, DW_AT_location[DW_OP_regx 0x2a]
DW$107	.dwtag  DW_TAG_assign_register, DW_AT_name("A22")
	.dwattr DW$107, DW_AT_location[DW_OP_regx 0x2b]
DW$108	.dwtag  DW_TAG_assign_register, DW_AT_name("A23")
	.dwattr DW$108, DW_AT_location[DW_OP_regx 0x2c]
DW$109	.dwtag  DW_TAG_assign_register, DW_AT_name("A24")
	.dwattr DW$109, DW_AT_location[DW_OP_regx 0x2d]
DW$110	.dwtag  DW_TAG_assign_register, DW_AT_name("A25")
	.dwattr DW$110, DW_AT_location[DW_OP_regx 0x2e]
DW$111	.dwtag  DW_TAG_assign_register, DW_AT_name("A26")
	.dwattr DW$111, DW_AT_location[DW_OP_regx 0x2f]
DW$112	.dwtag  DW_TAG_assign_register, DW_AT_name("A27")
	.dwattr DW$112, DW_AT_location[DW_OP_regx 0x30]
DW$113	.dwtag  DW_TAG_assign_register, DW_AT_name("A28")
	.dwattr DW$113, DW_AT_location[DW_OP_regx 0x31]
DW$114	.dwtag  DW_TAG_assign_register, DW_AT_name("A29")
	.dwattr DW$114, DW_AT_location[DW_OP_regx 0x32]
DW$115	.dwtag  DW_TAG_assign_register, DW_AT_name("A30")
	.dwattr DW$115, DW_AT_location[DW_OP_regx 0x33]
DW$116	.dwtag  DW_TAG_assign_register, DW_AT_name("A31")
	.dwattr DW$116, DW_AT_location[DW_OP_regx 0x34]
DW$117	.dwtag  DW_TAG_assign_register, DW_AT_name("B16")
	.dwattr DW$117, DW_AT_location[DW_OP_regx 0x35]
DW$118	.dwtag  DW_TAG_assign_register, DW_AT_name("B17")
	.dwattr DW$118, DW_AT_location[DW_OP_regx 0x36]
DW$119	.dwtag  DW_TAG_assign_register, DW_AT_name("B18")
	.dwattr DW$119, DW_AT_location[DW_OP_regx 0x37]
DW$120	.dwtag  DW_TAG_assign_register, DW_AT_name("B19")
	.dwattr DW$120, DW_AT_location[DW_OP_regx 0x38]
DW$121	.dwtag  DW_TAG_assign_register, DW_AT_name("B20")
	.dwattr DW$121, DW_AT_location[DW_OP_regx 0x39]
DW$122	.dwtag  DW_TAG_assign_register, DW_AT_name("B21")
	.dwattr DW$122, DW_AT_location[DW_OP_regx 0x3a]
DW$123	.dwtag  DW_TAG_assign_register, DW_AT_name("B22")
	.dwattr DW$123, DW_AT_location[DW_OP_regx 0x3b]
DW$124	.dwtag  DW_TAG_assign_register, DW_AT_name("B23")
	.dwattr DW$124, DW_AT_location[DW_OP_regx 0x3c]
DW$125	.dwtag  DW_TAG_assign_register, DW_AT_name("B24")
	.dwattr DW$125, DW_AT_location[DW_OP_regx 0x3d]
DW$126	.dwtag  DW_TAG_assign_register, DW_AT_name("B25")
	.dwattr DW$126, DW_AT_location[DW_OP_regx 0x3e]
DW$127	.dwtag  DW_TAG_assign_register, DW_AT_name("B26")
	.dwattr DW$127, DW_AT_location[DW_OP_regx 0x3f]
DW$128	.dwtag  DW_TAG_assign_register, DW_AT_name("B27")
	.dwattr DW$128, DW_AT_location[DW_OP_regx 0x40]
DW$129	.dwtag  DW_TAG_assign_register, DW_AT_name("B28")
	.dwattr DW$129, DW_AT_location[DW_OP_regx 0x41]
DW$130	.dwtag  DW_TAG_assign_register, DW_AT_name("B29")
	.dwattr DW$130, DW_AT_location[DW_OP_regx 0x42]
DW$131	.dwtag  DW_TAG_assign_register, DW_AT_name("B30")
	.dwattr DW$131, DW_AT_location[DW_OP_regx 0x43]
DW$132	.dwtag  DW_TAG_assign_register, DW_AT_name("B31")
	.dwattr DW$132, DW_AT_location[DW_OP_regx 0x44]
DW$133	.dwtag  DW_TAG_assign_register, DW_AT_name("AMR")
	.dwattr DW$133, DW_AT_location[DW_OP_regx 0x45]
DW$134	.dwtag  DW_TAG_assign_register, DW_AT_name("CSR")
	.dwattr DW$134, DW_AT_location[DW_OP_regx 0x46]
DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("ISR")
	.dwattr DW$135, DW_AT_location[DW_OP_regx 0x47]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("ICR")
	.dwattr DW$136, DW_AT_location[DW_OP_regx 0x48]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("IER")
	.dwattr DW$137, DW_AT_location[DW_OP_regx 0x49]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("ISTP")
	.dwattr DW$138, DW_AT_location[DW_OP_regx 0x4a]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("IN")
	.dwattr DW$139, DW_AT_location[DW_OP_regx 0x4b]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("OUT")
	.dwattr DW$140, DW_AT_location[DW_OP_regx 0x4c]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("ACR")
	.dwattr DW$141, DW_AT_location[DW_OP_regx 0x4d]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("ADR")
	.dwattr DW$142, DW_AT_location[DW_OP_regx 0x4e]
DW$143	.dwtag  DW_TAG_assign_register, DW_AT_name("FADCR")
	.dwattr DW$143, DW_AT_location[DW_OP_regx 0x4f]
DW$144	.dwtag  DW_TAG_assign_register, DW_AT_name("FAUCR")
	.dwattr DW$144, DW_AT_location[DW_OP_regx 0x50]
DW$145	.dwtag  DW_TAG_assign_register, DW_AT_name("FMCR")
	.dwattr DW$145, DW_AT_location[DW_OP_regx 0x51]
DW$146	.dwtag  DW_TAG_assign_register, DW_AT_name("GFPGFR")
	.dwattr DW$146, DW_AT_location[DW_OP_regx 0x52]
DW$147	.dwtag  DW_TAG_assign_register, DW_AT_name("DIER")
	.dwattr DW$147, DW_AT_location[DW_OP_regx 0x53]
DW$148	.dwtag  DW_TAG_assign_register, DW_AT_name("REP")
	.dwattr DW$148, DW_AT_location[DW_OP_regx 0x54]
DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCL")
	.dwattr DW$149, DW_AT_location[DW_OP_regx 0x55]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCH")
	.dwattr DW$150, DW_AT_location[DW_OP_regx 0x56]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("ARP")
	.dwattr DW$151, DW_AT_location[DW_OP_regx 0x57]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("ILC")
	.dwattr DW$152, DW_AT_location[DW_OP_regx 0x58]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("RILC")
	.dwattr DW$153, DW_AT_location[DW_OP_regx 0x59]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("DNUM")
	.dwattr DW$154, DW_AT_location[DW_OP_regx 0x5a]
DW$155	.dwtag  DW_TAG_assign_register, DW_AT_name("SSR")
	.dwattr DW$155, DW_AT_location[DW_OP_regx 0x5b]
DW$156	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYA")
	.dwattr DW$156, DW_AT_location[DW_OP_regx 0x5c]
DW$157	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYB")
	.dwattr DW$157, DW_AT_location[DW_OP_regx 0x5d]
DW$158	.dwtag  DW_TAG_assign_register, DW_AT_name("TSR")
	.dwattr DW$158, DW_AT_location[DW_OP_regx 0x5e]
DW$159	.dwtag  DW_TAG_assign_register, DW_AT_name("ITSR")
	.dwattr DW$159, DW_AT_location[DW_OP_regx 0x5f]
DW$160	.dwtag  DW_TAG_assign_register, DW_AT_name("NTSR")
	.dwattr DW$160, DW_AT_location[DW_OP_regx 0x60]
DW$161	.dwtag  DW_TAG_assign_register, DW_AT_name("EFR")
	.dwattr DW$161, DW_AT_location[DW_OP_regx 0x61]
DW$162	.dwtag  DW_TAG_assign_register, DW_AT_name("ECR")
	.dwattr DW$162, DW_AT_location[DW_OP_regx 0x62]
DW$163	.dwtag  DW_TAG_assign_register, DW_AT_name("IERR")
	.dwattr DW$163, DW_AT_location[DW_OP_regx 0x63]
DW$164	.dwtag  DW_TAG_assign_register, DW_AT_name("DMSG")
	.dwattr DW$164, DW_AT_location[DW_OP_regx 0x64]
DW$165	.dwtag  DW_TAG_assign_register, DW_AT_name("CMSG")
	.dwattr DW$165, DW_AT_location[DW_OP_regx 0x65]
DW$166	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr DW$166, DW_AT_location[DW_OP_regx 0x66]
DW$167	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr DW$167, DW_AT_location[DW_OP_regx 0x67]
DW$168	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr DW$168, DW_AT_location[DW_OP_regx 0x68]
DW$169	.dwtag  DW_TAG_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr DW$169, DW_AT_location[DW_OP_regx 0x69]
DW$170	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr DW$170, DW_AT_location[DW_OP_regx 0x6a]
DW$171	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr DW$171, DW_AT_location[DW_OP_regx 0x6b]
DW$172	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr DW$172, DW_AT_location[DW_OP_regx 0x6c]
DW$173	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr DW$173, DW_AT_location[DW_OP_regx 0x6d]
DW$174	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr DW$174, DW_AT_location[DW_OP_regx 0x6e]
DW$175	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr DW$175, DW_AT_location[DW_OP_regx 0x6f]
DW$176	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr DW$176, DW_AT_location[DW_OP_regx 0x70]
DW$177	.dwtag  DW_TAG_assign_register, DW_AT_name("MFREG0")
	.dwattr DW$177, DW_AT_location[DW_OP_regx 0x71]
DW$178	.dwtag  DW_TAG_assign_register, DW_AT_name("DBG_STAT")
	.dwattr DW$178, DW_AT_location[DW_OP_regx 0x72]
DW$179	.dwtag  DW_TAG_assign_register, DW_AT_name("BRK_EN")
	.dwattr DW$179, DW_AT_location[DW_OP_regx 0x73]
DW$180	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr DW$180, DW_AT_location[DW_OP_regx 0x74]
DW$181	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0")
	.dwattr DW$181, DW_AT_location[DW_OP_regx 0x75]
DW$182	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP1")
	.dwattr DW$182, DW_AT_location[DW_OP_regx 0x76]
DW$183	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP2")
	.dwattr DW$183, DW_AT_location[DW_OP_regx 0x77]
DW$184	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP3")
	.dwattr DW$184, DW_AT_location[DW_OP_regx 0x78]
DW$185	.dwtag  DW_TAG_assign_register, DW_AT_name("OVERLAY")
	.dwattr DW$185, DW_AT_location[DW_OP_regx 0x79]
DW$186	.dwtag  DW_TAG_assign_register, DW_AT_name("PC_PROF")
	.dwattr DW$186, DW_AT_location[DW_OP_regx 0x7a]
DW$187	.dwtag  DW_TAG_assign_register, DW_AT_name("ATSR")
	.dwattr DW$187, DW_AT_location[DW_OP_regx 0x7b]
DW$188	.dwtag  DW_TAG_assign_register, DW_AT_name("TRR")
	.dwattr DW$188, DW_AT_location[DW_OP_regx 0x7c]
DW$189	.dwtag  DW_TAG_assign_register, DW_AT_name("TCRR")
	.dwattr DW$189, DW_AT_location[DW_OP_regx 0x7d]
DW$190	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$190, DW_AT_location[DW_OP_regx 0x7e]
	.dwendtag DW$CU

