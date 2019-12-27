/*
 INT.H: fitxer auxiliar amb les dades dels vectors de les
interrupcions associades al hardware del V25 (CISE-4),
i amb la definició del codi d'operació de la instrucció
FINT (de fi d'una RSI per al V25) com una constant.
*/

/* control de compilació única */
#if	!defined(_INT_H)
#define	_INT_H

/*
 Constants definides per aquest mòdul: número de vector
 d'interrupció associat a cada temporitzador.
*/

#define	INTCOUNTER0	0x1C	/* Servei del comptador 0 */
#define	INTCOUNTER1	0x1D	/* Servei del comptador 1 */
#define	INTCOUNTER2	0x1E	/* Servei del comptador 2 */
#define	INTBASETEMPS	0x1F	/* Interrupció de servei de la base de temps */

#define	INTNMI		0x02	/* vector de la int. no emmascarable */
#define	INTP0		0x18	/* interrupció associada al perifèric '0' */
#define	INTP1		0x19	/* interrupció associada al perifèric '1' */
#define	INTP2		0x1A	/* interrupció associada al perifèric '2' */

#define INTDMA0		0x14	/* int. associada al canal de DMA '0' */
#define INTDMA1		0x15	/* int. associada al canal de DMA '1' */

#define INTSERR0	0x0C	/* int. associada a un error en el port sèrie '0' */
#define INTSRX0		0x0D	/* int. associada a recepció pel port sèrie '0' */
#define INTSTX0		0x0E	/* int. associada a transmissió pel port sèrie '0' */

#define INTSERR1	0x10	/* int. associada a un error en el port sèrie '1' */
#define INTSRX1		0x11	/* int. associada a recepció pel port sèrie '1' */
#define INTSTX1		0x12	/* int. associada a transmissió pel port sèrie '1' */

/*
  MACRO que genera una instrucció FINT del V25 (que no pot generar el
  compilador de C directament)
*/

#define	FINT		asm dw 0x920f

#endif
