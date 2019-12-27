#ifndef tokens_h
#define tokens_h
/* tokens.h -- List of labelled tokens and stuff
 *
 * Generated from: example1.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
 * ANTLR Version 1.33MR33
 */
#define zzEOF_TOKEN 1
#define NUM 2
#define PLUS 3
#define MINUS 4
#define PROD 5
#define DIVI 6
#define SPACE 7
#define OPENPAR 8
#define CLOSEPAR 9
#define WRITE 10
#define IDENT 11
#define ASSIGN 12
#define IF 13
#define THEN 14
#define ENDIF 15
#define DO 16
#define WHILE 17
#define ENDWHILE 18

#ifdef __USE_PROTOS
void expr(AST**_root);
#else
extern void expr();
#endif

#ifdef __USE_PROTOS
void expr2(AST**_root);
#else
extern void expr2();
#endif

#ifdef __USE_PROTOS
void expr3(AST**_root);
#else
extern void expr3();
#endif

#ifdef __USE_PROTOS
void instruction(AST**_root);
#else
extern void instruction();
#endif

#ifdef __USE_PROTOS
void program(AST**_root);
#else
extern void program();
#endif

#endif
extern SetWordType zzerr1[];
extern SetWordType zzerr2[];
extern SetWordType zzerr3[];
extern SetWordType zzerr4[];
extern SetWordType setwd1[];
extern SetWordType setwd2[];
