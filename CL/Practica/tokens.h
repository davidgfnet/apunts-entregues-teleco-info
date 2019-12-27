#ifndef tokens_h
#define tokens_h
/* tokens.h -- List of labelled tokens and stuff
 *
 * Generated from: cl.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
 * ANTLR Version 1.33MR33
 */
#define zzEOF_TOKEN 1
#define INPUTEND 1
#define PROGRAM 2
#define ENDPROGRAM 3
#define PROCEDURE 4
#define ENDPROCEDURE 5
#define FUNCTION 6
#define ENDFUNCTION 7
#define RETURN 8
#define VARS 9
#define ENDVARS 10
#define INT 11
#define STRUCT 12
#define ENDSTRUCT 13
#define WRITELN 14
#define WRITE 15
#define READ 16
#define ARRAY 17
#define OF 18
#define PLUS 19
#define MINUS 20
#define AND 21
#define OR 22
#define NOT 23
#define TRUECONST 24
#define FALSECONST 25
#define IF 26
#define THEN 27
#define ENDIF 28
#define ELSE 29
#define WHILE 30
#define ENDWHILE 31
#define PARVAL 32
#define PARREF 33
#define DO 34
#define PRODUCT 35
#define DIVISION 36
#define EQUAL 37
#define LESSTHAN 38
#define GREATERTHAN 39
#define OPENPAR 40
#define CLOSEPAR 41
#define INDOPEN 42
#define INDCLOSE 43
#define ASIG 44
#define DOT 45
#define COMMA 46
#define COMILLAS 47
#define STRING 48
#define INTCONST 49
#define IDENT 50
#define COMMENT 51
#define WHITESPACE 52
#define NEWLINE 53
#define LEXICALERROR 54
#define BOOL 55

#ifdef __USE_PROTOS
void program(AST**_root);
#else
extern void program();
#endif

#ifdef __USE_PROTOS
void dec_vars(AST**_root);
#else
extern void dec_vars();
#endif

#ifdef __USE_PROTOS
void l_dec_vars(AST**_root);
#else
extern void l_dec_vars();
#endif

#ifdef __USE_PROTOS
void dec_var(AST**_root);
#else
extern void dec_var();
#endif

#ifdef __USE_PROTOS
void param_dec(AST**_root);
#else
extern void param_dec();
#endif

#ifdef __USE_PROTOS
void params_dec(AST**_root);
#else
extern void params_dec();
#endif

#ifdef __USE_PROTOS
void l_dec_blocs(AST**_root);
#else
extern void l_dec_blocs();
#endif

#ifdef __USE_PROTOS
void procedure_declaration(AST**_root);
#else
extern void procedure_declaration();
#endif

#ifdef __USE_PROTOS
void function_declaration(AST**_root);
#else
extern void function_declaration();
#endif

#ifdef __USE_PROTOS
void dec_bloc(AST**_root);
#else
extern void dec_bloc();
#endif

#ifdef __USE_PROTOS
void constr_type(AST**_root);
#else
extern void constr_type();
#endif

#ifdef __USE_PROTOS
void field(AST**_root);
#else
extern void field();
#endif

#ifdef __USE_PROTOS
void l_instrs(AST**_root);
#else
extern void l_instrs();
#endif

#ifdef __USE_PROTOS
void fparamlist(AST**_root);
#else
extern void fparamlist();
#endif

#ifdef __USE_PROTOS
void instruction(AST**_root);
#else
extern void instruction();
#endif

#ifdef __USE_PROTOS
void expression(AST**_root);
#else
extern void expression();
#endif

#ifdef __USE_PROTOS
void expression2(AST**_root);
#else
extern void expression2();
#endif

#ifdef __USE_PROTOS
void expression3(AST**_root);
#else
extern void expression3();
#endif

#ifdef __USE_PROTOS
void expression4(AST**_root);
#else
extern void expression4();
#endif

#ifdef __USE_PROTOS
void expression5(AST**_root);
#else
extern void expression5();
#endif

#ifdef __USE_PROTOS
void expression6(AST**_root);
#else
extern void expression6();
#endif

#ifdef __USE_PROTOS
void expression7(AST**_root);
#else
extern void expression7();
#endif

#endif
extern SetWordType zzerr1[];
extern SetWordType zzerr2[];
extern SetWordType zzerr3[];
extern SetWordType setwd1[];
extern SetWordType zzerr4[];
extern SetWordType zzerr5[];
extern SetWordType zzerr6[];
extern SetWordType setwd2[];
extern SetWordType zzerr7[];
extern SetWordType zzerr8[];
extern SetWordType zzerr9[];
extern SetWordType zzerr10[];
extern SetWordType zzerr11[];
extern SetWordType zzerr12[];
extern SetWordType zzerr13[];
extern SetWordType setwd3[];
extern SetWordType zzerr14[];
extern SetWordType zzerr15[];
extern SetWordType zzerr16[];
extern SetWordType zzerr17[];
extern SetWordType setwd4[];
extern SetWordType zzerr18[];
extern SetWordType zzerr19[];
extern SetWordType zzerr20[];
extern SetWordType zzerr21[];
extern SetWordType zzerr22[];
extern SetWordType setwd5[];
extern SetWordType setwd6[];
