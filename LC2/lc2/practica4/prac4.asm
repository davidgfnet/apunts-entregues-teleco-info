;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v5.1.0 *
;* Date/Time created: Mon Mar 28 10:57:21 2011                                *
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
	.dwattr DW$CU, DW_AT_name("prac4.c")
	.dwattr DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v5.1.0 Copyright (c) 1996-2005 Texas Instruments Incorporated")
	.dwattr DW$CU, DW_AT_stmt_list(0x00)
	.dwattr DW$CU, DW_AT_TI_VERSION(0x01)
;*****************************************************************************
;* CINIT RECORDS                                                             *
;*****************************************************************************
	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_fs+0,32
	.field  	2,32			; _fs @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_index+0,32
	.field  	0,32			; _index @ 0


DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("processFIR"), DW_AT_symbol_name("_processFIR")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$3	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$1


DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("output_sample"), DW_AT_symbol_name("_output_sample")
	.dwattr DW$4, DW_AT_type(*DW$T$10)
	.dwattr DW$4, DW_AT_declaration(0x01)
	.dwattr DW$4, DW_AT_external(0x01)

DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("input_left_sample"), DW_AT_symbol_name("_input_left_sample")
	.dwattr DW$5, DW_AT_type(*DW$T$10)
	.dwattr DW$5, DW_AT_declaration(0x01)
	.dwattr DW$5, DW_AT_external(0x01)

DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("init_processFIR1"), DW_AT_symbol_name("_init_processFIR1")
	.dwattr DW$6, DW_AT_type(*DW$T$10)
	.dwattr DW$6, DW_AT_declaration(0x01)
	.dwattr DW$6, DW_AT_external(0x01)

DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("comm_intr"), DW_AT_symbol_name("_comm_intr")
	.dwattr DW$7, DW_AT_type(*DW$T$10)
	.dwattr DW$7, DW_AT_declaration(0x01)
	.dwattr DW$7, DW_AT_external(0x01)
	.global	_fs
_fs:	.usect	".far",4,4
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("fs"), DW_AT_symbol_name("_fs")
	.dwattr DW$8, DW_AT_location[DW_OP_addr _fs]
	.dwattr DW$8, DW_AT_type(*DW$T$27)
	.dwattr DW$8, DW_AT_external(0x01)
	.global	_io1
_io1:	.usect	".far",4000,4
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("io1"), DW_AT_symbol_name("_io1")
	.dwattr DW$9, DW_AT_location[DW_OP_addr _io1]
	.dwattr DW$9, DW_AT_type(*DW$T$28)
	.dwattr DW$9, DW_AT_external(0x01)
	.global	_io2
_io2:	.usect	".far",4000,4
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("io2"), DW_AT_symbol_name("_io2")
	.dwattr DW$10, DW_AT_location[DW_OP_addr _io2]
	.dwattr DW$10, DW_AT_type(*DW$T$28)
	.dwattr DW$10, DW_AT_external(0x01)
	.global	_io_block
_io_block:	.usect	".far",4,4
DW$11	.dwtag  DW_TAG_variable, DW_AT_name("io_block"), DW_AT_symbol_name("_io_block")
	.dwattr DW$11, DW_AT_location[DW_OP_addr _io_block]
	.dwattr DW$11, DW_AT_type(*DW$T$19)
	.dwattr DW$11, DW_AT_external(0x01)
	.global	_io_buffer
_io_buffer:	.usect	".far",4,4
DW$12	.dwtag  DW_TAG_variable, DW_AT_name("io_buffer"), DW_AT_symbol_name("_io_buffer")
	.dwattr DW$12, DW_AT_location[DW_OP_addr _io_buffer]
	.dwattr DW$12, DW_AT_type(*DW$T$19)
	.dwattr DW$12, DW_AT_external(0x01)
	.global	_index
_index:	.usect	".far",4,4
DW$13	.dwtag  DW_TAG_variable, DW_AT_name("index"), DW_AT_symbol_name("_index")
	.dwattr DW$13, DW_AT_location[DW_OP_addr _index]
	.dwattr DW$13, DW_AT_type(*DW$T$10)
	.dwattr DW$13, DW_AT_external(0x01)
;	C:\CCStudio_v3.1\c6000\cgtools\bin\acp6x.exe -@C:\DOCUME~1\lc2125\CONFIG~1\Temp\TI82012 
	.sect	".text"
	.global	_c_int11

DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("c_int11"), DW_AT_symbol_name("_c_int11")
	.dwattr DW$14, DW_AT_low_pc(_c_int11)
	.dwattr DW$14, DW_AT_high_pc(0x00)
	.dwattr DW$14, DW_AT_begin_file("prac4.c")
	.dwattr DW$14, DW_AT_begin_line(0x0c)
	.dwattr DW$14, DW_AT_begin_column(0x10)
	.dwpsn	"prac4.c",13,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  12 | interrupt void c_int11()                // Rutina de servicio de interr
;     | upcion                                                                 
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _c_int11                                                    *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 84 Save = 84 byte                  *
;******************************************************************************
_c_int11:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B9,*SP--(88)      ; |13| 
           NOP             2
	.dwcfa	0x0e, 88
	.dwcfa	0x80, 25, 0
           STW     .D2T2   B7,*+SP(84)       ; |13| 
           NOP             2
	.dwcfa	0x80, 23, 1
           STW     .D2T2   B6,*+SP(80)       ; |13| 
           NOP             2
	.dwcfa	0x80, 22, 2
           STW     .D2T2   B5,*+SP(76)       ; |13| 
           NOP             2
	.dwcfa	0x80, 21, 3
           STW     .D2T2   B4,*+SP(72)       ; |13| 
           NOP             2
	.dwcfa	0x80, 20, 4
           STW     .D2T2   B3,*+SP(68)       ; |13| 
           NOP             2
	.dwcfa	0x80, 19, 5
           STW     .D2T2   B2,*+SP(64)       ; |13| 
           NOP             2
	.dwcfa	0x80, 18, 6
           STW     .D2T2   B1,*+SP(60)       ; |13| 
           NOP             2
	.dwcfa	0x80, 17, 7
           STW     .D2T2   B0,*+SP(56)       ; |13| 
           NOP             2
	.dwcfa	0x80, 16, 8
           STW     .D2T2   B8,*+SP(52)       ; |13| 
           NOP             2
	.dwcfa	0x80, 24, 9
           STW     .D2T1   A9,*+SP(48)       ; |13| 
           NOP             2
	.dwcfa	0x80, 9, 10
           STW     .D2T1   A7,*+SP(44)       ; |13| 
           NOP             2
	.dwcfa	0x80, 7, 11
           STW     .D2T1   A6,*+SP(40)       ; |13| 
           NOP             2
	.dwcfa	0x80, 6, 12
           STW     .D2T1   A5,*+SP(36)       ; |13| 
           NOP             2
	.dwcfa	0x80, 5, 13
           STW     .D2T1   A4,*+SP(32)       ; |13| 
           NOP             2
	.dwcfa	0x80, 4, 14
           STW     .D2T1   A3,*+SP(28)       ; |13| 
           NOP             2
	.dwcfa	0x80, 3, 15
           STW     .D2T1   A2,*+SP(24)       ; |13| 
           NOP             2
	.dwcfa	0x80, 2, 16
           STW     .D2T1   A1,*+SP(20)       ; |13| 
           NOP             2
	.dwcfa	0x80, 1, 17
           STW     .D2T1   A0,*+SP(16)       ; |13| 
           NOP             2
	.dwcfa	0x80, 0, 18
           STW     .D2T1   A8,*+SP(12)       ; |13| 
           NOP             2
	.dwcfa	0x80, 8, 19
	.dwpsn	"prac4.c",14,3
;----------------------------------------------------------------------
;  14 | if (index < N)                                                         
;----------------------------------------------------------------------
           MVKL    .S1     _index,A3         ; |14| 
           MVKH    .S1     _index,A3         ; |14| 
           LDW     .D1T1   *A3,A3            ; |14| 
           MVK     .S2     1000,B4           ; |14| 
           NOP             3
           CMPLT   .L2X    A3,B4,B0          ; |14| 
   [!B0]   B       .S1     L1                ; |14| 
           NOP             5
           ; BRANCHCC OCCURS {L1}            ; |14| 
;** --------------------------------------------------------------------------*
	.dwpsn	"prac4.c",16,4
;----------------------------------------------------------------------
;  16 | output_sample((int)io_buffer[index]);                                  
;----------------------------------------------------------------------
           MVKL    .S1     _index,A3         ; |16| 

           MVKH    .S1     _index,A3         ; |16| 
||         MVKL    .S2     _io_buffer,B4     ; |16| 

           LDW     .D1T1   *A3,A4            ; |16| 
||         MVKH    .S2     _io_buffer,B4     ; |16| 

           LDW     .D2T1   *B4,A3            ; |16| 
           MVKL    .S2     RL0,B3            ; |16| 
           MVKH    .S2     RL0,B3            ; |16| 
           NOP             2
           LDW     .D1T1   *+A3[A4],A3       ; |16| 
           NOP             2
           CALL    .S1     _output_sample    ; |16| 
           NOP             1
           SPTRUNC .L1     A3,A4             ; |16| 
           NOP             3
RL0:       ; CALL OCCURS {_output_sample}    ; |16| 
	.dwpsn	"prac4.c",17,3
;----------------------------------------------------------------------
;  17 | io_buffer[index++]=(float)input_left_sample();                         
;----------------------------------------------------------------------
           CALL    .S1     _input_left_sample ; |17| 
           MVKL    .S2     RL1,B3            ; |17| 
           MVKH    .S2     RL1,B3            ; |17| 
           NOP             3
RL1:       ; CALL OCCURS {_input_left_sample}  ; |17| 
           MVKL    .S2     _index,B4         ; |17| 
           MVKH    .S2     _index,B4         ; |17| 
           MV      .L1X    B4,A5             ; |17| 
           LDW     .D1T1   *A5,A6            ; |17| 
           MVKL    .S1     _io_buffer,A3     ; |17| 
           MVKH    .S1     _io_buffer,A3     ; |17| 
           NOP             2
           ADD     .L1     1,A6,A7           ; |17| 
           STW     .D1T1   A7,*A5            ; |17| 
           LDW     .D1T1   *A3,A3            ; |17| 
           INTSP   .L1     A4,A4             ; |17| 
           NOP             3
           STW     .D1T1   A4,*+A3[A6]       ; |17| 
           NOP             1
	.dwpsn	"prac4.c",19,2
;----------------------------------------------------------------------
;  19 | return;                                                                
;----------------------------------------------------------------------
;** --------------------------------------------------------------------------*
L1:    
	.dwpsn	"prac4.c",20,1
           LDDW    .D2T2   *+SP(80),B7:B6    ; |20| 
           NOP             4
	.dwcfa	0xc0, 22
	.dwcfa	0xc0, 23
           LDDW    .D2T2   *+SP(72),B5:B4    ; |20| 
           NOP             4
	.dwcfa	0xc0, 20
	.dwcfa	0xc0, 21
           LDDW    .D2T2   *+SP(64),B3:B2    ; |20| 
           NOP             4
	.dwcfa	0xc0, 18
	.dwcfa	0xc0, 19
           LDDW    .D2T2   *+SP(56),B1:B0    ; |20| 
           NOP             4
	.dwcfa	0xc0, 16
	.dwcfa	0xc0, 17
           LDW     .D2T2   *+SP(52),B8       ; |20| 
           NOP             4
	.dwcfa	0xc0, 24
           LDW     .D2T1   *+SP(48),A9       ; |20| 
           NOP             4
	.dwcfa	0xc0, 9
           LDDW    .D2T1   *+SP(40),A7:A6    ; |20| 
           NOP             4
	.dwcfa	0xc0, 6
	.dwcfa	0xc0, 7
           LDDW    .D2T1   *+SP(32),A5:A4    ; |20| 
           NOP             4
	.dwcfa	0xc0, 4
	.dwcfa	0xc0, 5
           LDDW    .D2T1   *+SP(24),A3:A2    ; |20| 
           NOP             4
	.dwcfa	0xc0, 2
	.dwcfa	0xc0, 3
           LDDW    .D2T1   *+SP(16),A1:A0    ; |20| 
           NOP             4
	.dwcfa	0xc0, 0
	.dwcfa	0xc0, 1
           LDW     .D2T1   *+SP(12),A8       ; |20| 
           NOP             4
	.dwcfa	0xc0, 8
           LDW     .D2T2   *++SP(88),B9      ; |20| 
           NOP             4
	.dwcfa	0xc0, 25
	.dwcfa	0x0e, 0
           RET     .S2     IRP               ; |20| 
           NOP             5
           ; BRANCH OCCURS {IRP}             ; |20| 
	.dwattr DW$14, DW_AT_end_file("prac4.c")
	.dwattr DW$14, DW_AT_end_line(0x14)
	.dwattr DW$14, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$14

	.sect	".text"
	.global	_init_buffer_block

DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("init_buffer_block"), DW_AT_symbol_name("_init_buffer_block")
	.dwattr DW$15, DW_AT_low_pc(_init_buffer_block)
	.dwattr DW$15, DW_AT_high_pc(0x00)
	.dwattr DW$15, DW_AT_begin_file("prac4.c")
	.dwattr DW$15, DW_AT_begin_line(0x16)
	.dwattr DW$15, DW_AT_begin_column(0x06)
	.dwpsn	"prac4.c",23,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  22 | void init_buffer_block(void)                                           
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _init_buffer_block                                          *
;*                                                                            *
;*   Regs Modified     : A3,B4                                                *
;*   Regs Used         : A3,B3,B4                                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************
_init_buffer_block:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
	.dwpsn	"prac4.c",24,5
;----------------------------------------------------------------------
;  24 | io_buffer = io1;                                                       
;----------------------------------------------------------------------

           MVKL    .S1     _io1,A3           ; |24| 
||         MVKL    .S2     _io_buffer,B4     ; |24| 

           MVKH    .S1     _io1,A3           ; |24| 
||         MVKH    .S2     _io_buffer,B4     ; |24| 

           STW     .D2T1   A3,*B4            ; |24| 
           NOP             2
	.dwpsn	"prac4.c",25,5
;----------------------------------------------------------------------
;  25 | io_block  = io2;                                                       
;----------------------------------------------------------------------

           MVKL    .S2     _io2,B4           ; |25| 
||         MVKL    .S1     _io_block,A3      ; |25| 

           MVKH    .S2     _io2,B4           ; |25| 
||         MVKH    .S1     _io_block,A3      ; |25| 

           STW     .D1T2   B4,*A3            ; |25| 
           NOP             2
	.dwpsn	"prac4.c",26,1
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |26| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |26| 
	.dwattr DW$15, DW_AT_end_file("prac4.c")
	.dwattr DW$15, DW_AT_end_line(0x1a)
	.dwattr DW$15, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$15

	.sect	".text"
	.global	_wait_buffer_block

DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("wait_buffer_block"), DW_AT_symbol_name("_wait_buffer_block")
	.dwattr DW$16, DW_AT_low_pc(_wait_buffer_block)
	.dwattr DW$16, DW_AT_high_pc(0x00)
	.dwattr DW$16, DW_AT_begin_file("prac4.c")
	.dwattr DW$16, DW_AT_begin_line(0x1c)
	.dwattr DW$16, DW_AT_begin_column(0x06)
	.dwpsn	"prac4.c",29,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  28 | void wait_buffer_block(void)                                           
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _wait_buffer_block                                          *
;*                                                                            *
;*   Regs Modified     : A3,B0,B4,B5,SP                                       *
;*   Regs Used         : A3,B0,B3,B4,B5,SP                                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                    *
;******************************************************************************
_wait_buffer_block:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  30 | float *ptmp;                        // Puntero auxiliar
;     |                                                                        
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           SUB     .L2     SP,8,SP           ; |29| 
	.dwcfa	0x0e, 8
DW$17	.dwtag  DW_TAG_variable, DW_AT_name("ptmp"), DW_AT_symbol_name("_ptmp")
	.dwattr DW$17, DW_AT_type(*DW$T$19)
	.dwattr DW$17, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	"prac4.c",32,11
;----------------------------------------------------------------------
;  32 | while(index < N);           // Espera a que se llene el buffer         
;----------------------------------------------------------------------
           MVKL    .S1     _index,A3         ; |32| 
           MVKH    .S1     _index,A3         ; |32| 
           LDW     .D1T1   *A3,A3            ; |32| 
           MVK     .S2     1000,B4           ; |32| 
           NOP             3
           CMPLT   .L2X    A3,B4,B0          ; |32| 
   [!B0]   B       .S1     L3                ; |32| 
           NOP             5
           ; BRANCHCC OCCURS {L3}            ; |32| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L2:    
DW$L$_wait_buffer_block$2$B:
           MVKL    .S1     _index,A3         ; |32| 
           MVKH    .S1     _index,A3         ; |32| 
           LDW     .D1T1   *A3,A3            ; |32| 
           NOP             4
           CMPLT   .L2X    A3,B4,B0          ; |32| 
   [ B0]   B       .S1     L2                ; |32| 
           NOP             5
           ; BRANCHCC OCCURS {L2}            ; |32| 
DW$L$_wait_buffer_block$2$E:
;** --------------------------------------------------------------------------*
L3:    
	.dwpsn	"prac4.c",33,5
;----------------------------------------------------------------------
;  33 | ptmp = io_buffer;           // Intercambia punteros:                   
;----------------------------------------------------------------------
           MVKL    .S2     _io_buffer,B4     ; |33| 
           MVKH    .S2     _io_buffer,B4     ; |33| 
           LDW     .D2T2   *B4,B4            ; |33| 
           NOP             4
           STW     .D2T2   B4,*+SP(4)        ; |33| 
           NOP             2
	.dwpsn	"prac4.c",34,5
;----------------------------------------------------------------------
;  34 | io_buffer = io_block;       // nuevo buffer de entrada/salida          
;----------------------------------------------------------------------
           MVKL    .S1     _io_block,A3      ; |34| 
           MVKH    .S1     _io_block,A3      ; |34| 
           LDW     .D1T1   *A3,A3            ; |34| 
           MVKL    .S2     _io_buffer,B4     ; |34| 
           MVKH    .S2     _io_buffer,B4     ; |34| 
           NOP             2
           STW     .D2T1   A3,*B4            ; |34| 
           NOP             2
	.dwpsn	"prac4.c",35,5
;----------------------------------------------------------------------
;  35 | io_block = ptmp;            // nuevo bloque de datos                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |35| 
           MVKL    .S1     _io_block,A3      ; |35| 
           MVKH    .S1     _io_block,A3      ; |35| 
           NOP             2
           STW     .D1T2   B4,*A3            ; |35| 
           NOP             2
	.dwpsn	"prac4.c",36,5
;----------------------------------------------------------------------
;  36 | index = 0;                          // Inicializa index
;     |                                                                        
;----------------------------------------------------------------------
           MVKL    .S2     _index,B4         ; |36| 

           MVKH    .S2     _index,B4         ; |36| 
||         ZERO    .L2     B5                ; |36| 

           STW     .D2T2   B5,*B4            ; |36| 
           NOP             2
	.dwpsn	"prac4.c",37,1
           ADD     .L2     8,SP,SP           ; |37| 
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |37| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |37| 

DW$18	.dwtag  DW_TAG_loop
	.dwattr DW$18, DW_AT_name("H:\practica4\prac4.asm:L2:1:1301302641")
	.dwattr DW$18, DW_AT_begin_file("prac4.c")
	.dwattr DW$18, DW_AT_begin_line(0x20)
	.dwattr DW$18, DW_AT_end_line(0x20)
DW$19	.dwtag  DW_TAG_loop_range
	.dwattr DW$19, DW_AT_low_pc(DW$L$_wait_buffer_block$2$B)
	.dwattr DW$19, DW_AT_high_pc(DW$L$_wait_buffer_block$2$E)
	.dwendtag DW$18

	.dwattr DW$16, DW_AT_end_file("prac4.c")
	.dwattr DW$16, DW_AT_end_line(0x25)
	.dwattr DW$16, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$16

	.sect	".text"
	.global	_main

DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("main"), DW_AT_symbol_name("_main")
	.dwattr DW$20, DW_AT_low_pc(_main)
	.dwattr DW$20, DW_AT_high_pc(0x00)
	.dwattr DW$20, DW_AT_begin_file("prac4.c")
	.dwattr DW$20, DW_AT_begin_line(0x27)
	.dwattr DW$20, DW_AT_begin_column(0x06)
	.dwpsn	"prac4.c",40,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  39 | void main()                                                            
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _main                                                       *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 516 Auto + 4 Save = 520 byte                *
;******************************************************************************
_main:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  41 | float hFIR[L_FIR];                      // Respuesta impulsional del fi
;     | ltro FIR                                                               
;  42 | //      filter_iir2 hIIR;                       // Coeficientes del fil
;     | tro IIR                                                                
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           ADDK    .S2     -520,SP           ; |40| 
	.dwcfa	0x0e, 520
           STW     .D2T2   B3,*+SP(520)      ; |40| 
           NOP             2
	.dwcfa	0x80, 19, 0
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("hFIR"), DW_AT_symbol_name("_hFIR")
	.dwattr DW$21, DW_AT_type(*DW$T$29)
	.dwattr DW$21, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	"prac4.c",44,2
;----------------------------------------------------------------------
;  44 | init_processFIR1(hFIR);         // Filtro paso alto                    
;  45 | //      init_processFIR2(hFIR);         // Filtro generado con MATLAB  
;  46 | //      init_processIIR(&hIIR);         // Filtro generado con MATLAB  
;----------------------------------------------------------------------
           CALL    .S1     _init_processFIR1 ; |44| 
           MVKL    .S2     RL2,B3            ; |44| 
           MVKH    .S2     RL2,B3            ; |44| 
           ADD     .L1X    4,SP,A4           ; |44| 
           NOP             2
RL2:       ; CALL OCCURS {_init_processFIR1}  ; |44| 
	.dwpsn	"prac4.c",48,2
;----------------------------------------------------------------------
;  48 | init_buffer_block();                                                   
;----------------------------------------------------------------------
           CALL    .S1     _init_buffer_block ; |48| 
           MVKL    .S2     RL3,B3            ; |48| 
           MVKH    .S2     RL3,B3            ; |48| 
           NOP             3
RL3:       ; CALL OCCURS {_init_buffer_block}  ; |48| 
	.dwpsn	"prac4.c",49,2
;----------------------------------------------------------------------
;  49 | comm_intr();                    // inicio DSK, codec, McBSP usando inte
;     | rrupciones                                                             
;----------------------------------------------------------------------
           CALL    .S1     _comm_intr        ; |49| 
           MVKL    .S2     RL4,B3            ; |49| 
           MVKH    .S2     RL4,B3            ; |49| 
           NOP             3
RL4:       ; CALL OCCURS {_comm_intr}        ; |49| 
	.dwpsn	"prac4.c",51,8
;----------------------------------------------------------------------
;  51 | while(1)                                // bucle infinito              
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L4:    
DW$L$_main$2$B:
	.dwpsn	"prac4.c",53,3
;----------------------------------------------------------------------
;  53 | wait_buffer_block();            // Espera a que se llene el buffer     
;----------------------------------------------------------------------
           CALL    .S1     _wait_buffer_block ; |53| 
           MVKL    .S2     RL5,B3            ; |53| 
           MVKH    .S2     RL5,B3            ; |53| 
           NOP             3
RL5:       ; CALL OCCURS {_wait_buffer_block}  ; |53| 
	.dwpsn	"prac4.c",54,3
;----------------------------------------------------------------------
;  54 | processFIR(io_block,hFIR);          // Procesa bloque                  
;  55 | //              processIIR(io_block,&hIIR,L_IIR,N);         // Procesa
;     | bloque                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     _io_block,A3      ; |54| 

           CALL    .S2     _processFIR       ; |54| 
||         MVKH    .S1     _io_block,A3      ; |54| 

           LDW     .D1T1   *A3,A4            ; |54| 
           MVKL    .S2     RL6,B3            ; |54| 
           MVKH    .S2     RL6,B3            ; |54| 
           ADD     .L2     4,SP,B4           ; |54| 
           NOP             1
RL6:       ; CALL OCCURS {_processFIR}       ; |54| 
	.dwpsn	"prac4.c",51,8
           B       .S1     L4                ; |51| 
           NOP             5
           ; BRANCH OCCURS {L4}              ; |51| 
DW$L$_main$2$E:
;** --------------------------------------------------------------------------*
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0

DW$22	.dwtag  DW_TAG_loop
	.dwattr DW$22, DW_AT_name("H:\practica4\prac4.asm:L4:1:1301302641")
	.dwattr DW$22, DW_AT_begin_file("prac4.c")
	.dwattr DW$22, DW_AT_begin_line(0x33)
	.dwattr DW$22, DW_AT_end_line(0x38)
DW$23	.dwtag  DW_TAG_loop_range
	.dwattr DW$23, DW_AT_low_pc(DW$L$_main$2$B)
	.dwattr DW$23, DW_AT_high_pc(DW$L$_main$2$E)
	.dwendtag DW$22

	.dwattr DW$20, DW_AT_end_file("prac4.c")
	.dwattr DW$20, DW_AT_end_line(0x39)
	.dwattr DW$20, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$20

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_processFIR
	.global	_output_sample
	.global	_input_left_sample
	.global	_init_processFIR1
	.global	_comm_intr

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

DW$T$20	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$20, DW_AT_language(DW_LANG_C)
DW$24	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$25	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$20


DW$T$22	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$22, DW_AT_language(DW_LANG_C)

DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$23, DW_AT_language(DW_LANG_C)
DW$T$10	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$10, DW_AT_byte_size(0x04)

DW$T$25	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$10)
	.dwattr DW$T$25, DW_AT_language(DW_LANG_C)
DW$T$27	.dwtag  DW_TAG_typedef, DW_AT_name("Uint32"), DW_AT_type(*DW$T$11)
	.dwattr DW$T$27, DW_AT_language(DW_LANG_C)
DW$T$19	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$19, DW_AT_address_class(0x20)

DW$T$28	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$28, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$28, DW_AT_byte_size(0xfa0)
DW$26	.dwtag  DW_TAG_subrange_type
	.dwattr DW$26, DW_AT_upper_bound(0x3e7)
	.dwendtag DW$T$28


DW$T$29	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$16)
	.dwattr DW$T$29, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$29, DW_AT_byte_size(0x204)
DW$27	.dwtag  DW_TAG_subrange_type
	.dwattr DW$27, DW_AT_upper_bound(0x80)
	.dwendtag DW$T$29

DW$T$11	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DW$T$11, DW_AT_byte_size(0x04)
DW$T$16	.dwtag  DW_TAG_base_type, DW_AT_name("float")
	.dwattr DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr DW$T$16, DW_AT_byte_size(0x04)

	.dwattr DW$14, DW_AT_external(0x01)
	.dwattr DW$15, DW_AT_external(0x01)
	.dwattr DW$20, DW_AT_external(0x01)
	.dwattr DW$16, DW_AT_external(0x01)
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

DW$28	.dwtag  DW_TAG_assign_register, DW_AT_name("A0")
	.dwattr DW$28, DW_AT_location[DW_OP_reg0]
DW$29	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$29, DW_AT_location[DW_OP_reg1]
DW$30	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$30, DW_AT_location[DW_OP_reg2]
DW$31	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$31, DW_AT_location[DW_OP_reg3]
DW$32	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$32, DW_AT_location[DW_OP_reg4]
DW$33	.dwtag  DW_TAG_assign_register, DW_AT_name("A5")
	.dwattr DW$33, DW_AT_location[DW_OP_reg5]
DW$34	.dwtag  DW_TAG_assign_register, DW_AT_name("A6")
	.dwattr DW$34, DW_AT_location[DW_OP_reg6]
DW$35	.dwtag  DW_TAG_assign_register, DW_AT_name("A7")
	.dwattr DW$35, DW_AT_location[DW_OP_reg7]
DW$36	.dwtag  DW_TAG_assign_register, DW_AT_name("A8")
	.dwattr DW$36, DW_AT_location[DW_OP_reg8]
DW$37	.dwtag  DW_TAG_assign_register, DW_AT_name("A9")
	.dwattr DW$37, DW_AT_location[DW_OP_reg9]
DW$38	.dwtag  DW_TAG_assign_register, DW_AT_name("A10")
	.dwattr DW$38, DW_AT_location[DW_OP_reg10]
DW$39	.dwtag  DW_TAG_assign_register, DW_AT_name("A11")
	.dwattr DW$39, DW_AT_location[DW_OP_reg11]
DW$40	.dwtag  DW_TAG_assign_register, DW_AT_name("A12")
	.dwattr DW$40, DW_AT_location[DW_OP_reg12]
DW$41	.dwtag  DW_TAG_assign_register, DW_AT_name("A13")
	.dwattr DW$41, DW_AT_location[DW_OP_reg13]
DW$42	.dwtag  DW_TAG_assign_register, DW_AT_name("A14")
	.dwattr DW$42, DW_AT_location[DW_OP_reg14]
DW$43	.dwtag  DW_TAG_assign_register, DW_AT_name("A15")
	.dwattr DW$43, DW_AT_location[DW_OP_reg15]
DW$44	.dwtag  DW_TAG_assign_register, DW_AT_name("B0")
	.dwattr DW$44, DW_AT_location[DW_OP_reg16]
DW$45	.dwtag  DW_TAG_assign_register, DW_AT_name("B1")
	.dwattr DW$45, DW_AT_location[DW_OP_reg17]
DW$46	.dwtag  DW_TAG_assign_register, DW_AT_name("B2")
	.dwattr DW$46, DW_AT_location[DW_OP_reg18]
DW$47	.dwtag  DW_TAG_assign_register, DW_AT_name("B3")
	.dwattr DW$47, DW_AT_location[DW_OP_reg19]
DW$48	.dwtag  DW_TAG_assign_register, DW_AT_name("B4")
	.dwattr DW$48, DW_AT_location[DW_OP_reg20]
DW$49	.dwtag  DW_TAG_assign_register, DW_AT_name("B5")
	.dwattr DW$49, DW_AT_location[DW_OP_reg21]
DW$50	.dwtag  DW_TAG_assign_register, DW_AT_name("B6")
	.dwattr DW$50, DW_AT_location[DW_OP_reg22]
DW$51	.dwtag  DW_TAG_assign_register, DW_AT_name("B7")
	.dwattr DW$51, DW_AT_location[DW_OP_reg23]
DW$52	.dwtag  DW_TAG_assign_register, DW_AT_name("B8")
	.dwattr DW$52, DW_AT_location[DW_OP_reg24]
DW$53	.dwtag  DW_TAG_assign_register, DW_AT_name("B9")
	.dwattr DW$53, DW_AT_location[DW_OP_reg25]
DW$54	.dwtag  DW_TAG_assign_register, DW_AT_name("B10")
	.dwattr DW$54, DW_AT_location[DW_OP_reg26]
DW$55	.dwtag  DW_TAG_assign_register, DW_AT_name("B11")
	.dwattr DW$55, DW_AT_location[DW_OP_reg27]
DW$56	.dwtag  DW_TAG_assign_register, DW_AT_name("B12")
	.dwattr DW$56, DW_AT_location[DW_OP_reg28]
DW$57	.dwtag  DW_TAG_assign_register, DW_AT_name("B13")
	.dwattr DW$57, DW_AT_location[DW_OP_reg29]
DW$58	.dwtag  DW_TAG_assign_register, DW_AT_name("DP")
	.dwattr DW$58, DW_AT_location[DW_OP_reg30]
DW$59	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$59, DW_AT_location[DW_OP_reg31]
DW$60	.dwtag  DW_TAG_assign_register, DW_AT_name("FP")
	.dwattr DW$60, DW_AT_location[DW_OP_regx 0x20]
DW$61	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$61, DW_AT_location[DW_OP_regx 0x21]
DW$62	.dwtag  DW_TAG_assign_register, DW_AT_name("IRP")
	.dwattr DW$62, DW_AT_location[DW_OP_regx 0x22]
DW$63	.dwtag  DW_TAG_assign_register, DW_AT_name("IFR")
	.dwattr DW$63, DW_AT_location[DW_OP_regx 0x23]
DW$64	.dwtag  DW_TAG_assign_register, DW_AT_name("NRP")
	.dwattr DW$64, DW_AT_location[DW_OP_regx 0x24]
DW$65	.dwtag  DW_TAG_assign_register, DW_AT_name("A16")
	.dwattr DW$65, DW_AT_location[DW_OP_regx 0x25]
DW$66	.dwtag  DW_TAG_assign_register, DW_AT_name("A17")
	.dwattr DW$66, DW_AT_location[DW_OP_regx 0x26]
DW$67	.dwtag  DW_TAG_assign_register, DW_AT_name("A18")
	.dwattr DW$67, DW_AT_location[DW_OP_regx 0x27]
DW$68	.dwtag  DW_TAG_assign_register, DW_AT_name("A19")
	.dwattr DW$68, DW_AT_location[DW_OP_regx 0x28]
DW$69	.dwtag  DW_TAG_assign_register, DW_AT_name("A20")
	.dwattr DW$69, DW_AT_location[DW_OP_regx 0x29]
DW$70	.dwtag  DW_TAG_assign_register, DW_AT_name("A21")
	.dwattr DW$70, DW_AT_location[DW_OP_regx 0x2a]
DW$71	.dwtag  DW_TAG_assign_register, DW_AT_name("A22")
	.dwattr DW$71, DW_AT_location[DW_OP_regx 0x2b]
DW$72	.dwtag  DW_TAG_assign_register, DW_AT_name("A23")
	.dwattr DW$72, DW_AT_location[DW_OP_regx 0x2c]
DW$73	.dwtag  DW_TAG_assign_register, DW_AT_name("A24")
	.dwattr DW$73, DW_AT_location[DW_OP_regx 0x2d]
DW$74	.dwtag  DW_TAG_assign_register, DW_AT_name("A25")
	.dwattr DW$74, DW_AT_location[DW_OP_regx 0x2e]
DW$75	.dwtag  DW_TAG_assign_register, DW_AT_name("A26")
	.dwattr DW$75, DW_AT_location[DW_OP_regx 0x2f]
DW$76	.dwtag  DW_TAG_assign_register, DW_AT_name("A27")
	.dwattr DW$76, DW_AT_location[DW_OP_regx 0x30]
DW$77	.dwtag  DW_TAG_assign_register, DW_AT_name("A28")
	.dwattr DW$77, DW_AT_location[DW_OP_regx 0x31]
DW$78	.dwtag  DW_TAG_assign_register, DW_AT_name("A29")
	.dwattr DW$78, DW_AT_location[DW_OP_regx 0x32]
DW$79	.dwtag  DW_TAG_assign_register, DW_AT_name("A30")
	.dwattr DW$79, DW_AT_location[DW_OP_regx 0x33]
DW$80	.dwtag  DW_TAG_assign_register, DW_AT_name("A31")
	.dwattr DW$80, DW_AT_location[DW_OP_regx 0x34]
DW$81	.dwtag  DW_TAG_assign_register, DW_AT_name("B16")
	.dwattr DW$81, DW_AT_location[DW_OP_regx 0x35]
DW$82	.dwtag  DW_TAG_assign_register, DW_AT_name("B17")
	.dwattr DW$82, DW_AT_location[DW_OP_regx 0x36]
DW$83	.dwtag  DW_TAG_assign_register, DW_AT_name("B18")
	.dwattr DW$83, DW_AT_location[DW_OP_regx 0x37]
DW$84	.dwtag  DW_TAG_assign_register, DW_AT_name("B19")
	.dwattr DW$84, DW_AT_location[DW_OP_regx 0x38]
DW$85	.dwtag  DW_TAG_assign_register, DW_AT_name("B20")
	.dwattr DW$85, DW_AT_location[DW_OP_regx 0x39]
DW$86	.dwtag  DW_TAG_assign_register, DW_AT_name("B21")
	.dwattr DW$86, DW_AT_location[DW_OP_regx 0x3a]
DW$87	.dwtag  DW_TAG_assign_register, DW_AT_name("B22")
	.dwattr DW$87, DW_AT_location[DW_OP_regx 0x3b]
DW$88	.dwtag  DW_TAG_assign_register, DW_AT_name("B23")
	.dwattr DW$88, DW_AT_location[DW_OP_regx 0x3c]
DW$89	.dwtag  DW_TAG_assign_register, DW_AT_name("B24")
	.dwattr DW$89, DW_AT_location[DW_OP_regx 0x3d]
DW$90	.dwtag  DW_TAG_assign_register, DW_AT_name("B25")
	.dwattr DW$90, DW_AT_location[DW_OP_regx 0x3e]
DW$91	.dwtag  DW_TAG_assign_register, DW_AT_name("B26")
	.dwattr DW$91, DW_AT_location[DW_OP_regx 0x3f]
DW$92	.dwtag  DW_TAG_assign_register, DW_AT_name("B27")
	.dwattr DW$92, DW_AT_location[DW_OP_regx 0x40]
DW$93	.dwtag  DW_TAG_assign_register, DW_AT_name("B28")
	.dwattr DW$93, DW_AT_location[DW_OP_regx 0x41]
DW$94	.dwtag  DW_TAG_assign_register, DW_AT_name("B29")
	.dwattr DW$94, DW_AT_location[DW_OP_regx 0x42]
DW$95	.dwtag  DW_TAG_assign_register, DW_AT_name("B30")
	.dwattr DW$95, DW_AT_location[DW_OP_regx 0x43]
DW$96	.dwtag  DW_TAG_assign_register, DW_AT_name("B31")
	.dwattr DW$96, DW_AT_location[DW_OP_regx 0x44]
DW$97	.dwtag  DW_TAG_assign_register, DW_AT_name("AMR")
	.dwattr DW$97, DW_AT_location[DW_OP_regx 0x45]
DW$98	.dwtag  DW_TAG_assign_register, DW_AT_name("CSR")
	.dwattr DW$98, DW_AT_location[DW_OP_regx 0x46]
DW$99	.dwtag  DW_TAG_assign_register, DW_AT_name("ISR")
	.dwattr DW$99, DW_AT_location[DW_OP_regx 0x47]
DW$100	.dwtag  DW_TAG_assign_register, DW_AT_name("ICR")
	.dwattr DW$100, DW_AT_location[DW_OP_regx 0x48]
DW$101	.dwtag  DW_TAG_assign_register, DW_AT_name("IER")
	.dwattr DW$101, DW_AT_location[DW_OP_regx 0x49]
DW$102	.dwtag  DW_TAG_assign_register, DW_AT_name("ISTP")
	.dwattr DW$102, DW_AT_location[DW_OP_regx 0x4a]
DW$103	.dwtag  DW_TAG_assign_register, DW_AT_name("IN")
	.dwattr DW$103, DW_AT_location[DW_OP_regx 0x4b]
DW$104	.dwtag  DW_TAG_assign_register, DW_AT_name("OUT")
	.dwattr DW$104, DW_AT_location[DW_OP_regx 0x4c]
DW$105	.dwtag  DW_TAG_assign_register, DW_AT_name("ACR")
	.dwattr DW$105, DW_AT_location[DW_OP_regx 0x4d]
DW$106	.dwtag  DW_TAG_assign_register, DW_AT_name("ADR")
	.dwattr DW$106, DW_AT_location[DW_OP_regx 0x4e]
DW$107	.dwtag  DW_TAG_assign_register, DW_AT_name("FADCR")
	.dwattr DW$107, DW_AT_location[DW_OP_regx 0x4f]
DW$108	.dwtag  DW_TAG_assign_register, DW_AT_name("FAUCR")
	.dwattr DW$108, DW_AT_location[DW_OP_regx 0x50]
DW$109	.dwtag  DW_TAG_assign_register, DW_AT_name("FMCR")
	.dwattr DW$109, DW_AT_location[DW_OP_regx 0x51]
DW$110	.dwtag  DW_TAG_assign_register, DW_AT_name("GFPGFR")
	.dwattr DW$110, DW_AT_location[DW_OP_regx 0x52]
DW$111	.dwtag  DW_TAG_assign_register, DW_AT_name("DIER")
	.dwattr DW$111, DW_AT_location[DW_OP_regx 0x53]
DW$112	.dwtag  DW_TAG_assign_register, DW_AT_name("REP")
	.dwattr DW$112, DW_AT_location[DW_OP_regx 0x54]
DW$113	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCL")
	.dwattr DW$113, DW_AT_location[DW_OP_regx 0x55]
DW$114	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCH")
	.dwattr DW$114, DW_AT_location[DW_OP_regx 0x56]
DW$115	.dwtag  DW_TAG_assign_register, DW_AT_name("ARP")
	.dwattr DW$115, DW_AT_location[DW_OP_regx 0x57]
DW$116	.dwtag  DW_TAG_assign_register, DW_AT_name("ILC")
	.dwattr DW$116, DW_AT_location[DW_OP_regx 0x58]
DW$117	.dwtag  DW_TAG_assign_register, DW_AT_name("RILC")
	.dwattr DW$117, DW_AT_location[DW_OP_regx 0x59]
DW$118	.dwtag  DW_TAG_assign_register, DW_AT_name("DNUM")
	.dwattr DW$118, DW_AT_location[DW_OP_regx 0x5a]
DW$119	.dwtag  DW_TAG_assign_register, DW_AT_name("SSR")
	.dwattr DW$119, DW_AT_location[DW_OP_regx 0x5b]
DW$120	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYA")
	.dwattr DW$120, DW_AT_location[DW_OP_regx 0x5c]
DW$121	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYB")
	.dwattr DW$121, DW_AT_location[DW_OP_regx 0x5d]
DW$122	.dwtag  DW_TAG_assign_register, DW_AT_name("TSR")
	.dwattr DW$122, DW_AT_location[DW_OP_regx 0x5e]
DW$123	.dwtag  DW_TAG_assign_register, DW_AT_name("ITSR")
	.dwattr DW$123, DW_AT_location[DW_OP_regx 0x5f]
DW$124	.dwtag  DW_TAG_assign_register, DW_AT_name("NTSR")
	.dwattr DW$124, DW_AT_location[DW_OP_regx 0x60]
DW$125	.dwtag  DW_TAG_assign_register, DW_AT_name("EFR")
	.dwattr DW$125, DW_AT_location[DW_OP_regx 0x61]
DW$126	.dwtag  DW_TAG_assign_register, DW_AT_name("ECR")
	.dwattr DW$126, DW_AT_location[DW_OP_regx 0x62]
DW$127	.dwtag  DW_TAG_assign_register, DW_AT_name("IERR")
	.dwattr DW$127, DW_AT_location[DW_OP_regx 0x63]
DW$128	.dwtag  DW_TAG_assign_register, DW_AT_name("DMSG")
	.dwattr DW$128, DW_AT_location[DW_OP_regx 0x64]
DW$129	.dwtag  DW_TAG_assign_register, DW_AT_name("CMSG")
	.dwattr DW$129, DW_AT_location[DW_OP_regx 0x65]
DW$130	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr DW$130, DW_AT_location[DW_OP_regx 0x66]
DW$131	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr DW$131, DW_AT_location[DW_OP_regx 0x67]
DW$132	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr DW$132, DW_AT_location[DW_OP_regx 0x68]
DW$133	.dwtag  DW_TAG_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr DW$133, DW_AT_location[DW_OP_regx 0x69]
DW$134	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr DW$134, DW_AT_location[DW_OP_regx 0x6a]
DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr DW$135, DW_AT_location[DW_OP_regx 0x6b]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr DW$136, DW_AT_location[DW_OP_regx 0x6c]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr DW$137, DW_AT_location[DW_OP_regx 0x6d]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr DW$138, DW_AT_location[DW_OP_regx 0x6e]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr DW$139, DW_AT_location[DW_OP_regx 0x6f]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr DW$140, DW_AT_location[DW_OP_regx 0x70]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("MFREG0")
	.dwattr DW$141, DW_AT_location[DW_OP_regx 0x71]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("DBG_STAT")
	.dwattr DW$142, DW_AT_location[DW_OP_regx 0x72]
DW$143	.dwtag  DW_TAG_assign_register, DW_AT_name("BRK_EN")
	.dwattr DW$143, DW_AT_location[DW_OP_regx 0x73]
DW$144	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr DW$144, DW_AT_location[DW_OP_regx 0x74]
DW$145	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0")
	.dwattr DW$145, DW_AT_location[DW_OP_regx 0x75]
DW$146	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP1")
	.dwattr DW$146, DW_AT_location[DW_OP_regx 0x76]
DW$147	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP2")
	.dwattr DW$147, DW_AT_location[DW_OP_regx 0x77]
DW$148	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP3")
	.dwattr DW$148, DW_AT_location[DW_OP_regx 0x78]
DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("OVERLAY")
	.dwattr DW$149, DW_AT_location[DW_OP_regx 0x79]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("PC_PROF")
	.dwattr DW$150, DW_AT_location[DW_OP_regx 0x7a]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("ATSR")
	.dwattr DW$151, DW_AT_location[DW_OP_regx 0x7b]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("TRR")
	.dwattr DW$152, DW_AT_location[DW_OP_regx 0x7c]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("TCRR")
	.dwattr DW$153, DW_AT_location[DW_OP_regx 0x7d]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$154, DW_AT_location[DW_OP_regx 0x7e]
	.dwendtag DW$CU

