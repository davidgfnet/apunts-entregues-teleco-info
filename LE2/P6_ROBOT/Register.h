/*
/////////////////////////////////////////////////////
// REGISTER.H : fitxer auxiliar amb les adreces dels
// registres interns del V25 per al control dels perifärics.
*/
#if     !defined(_REGISTRES)
#define _REGISTRES

#define RSEG    (WORD)0xfff0    /* segment de dades */

#define P0              (WORD)0x0000    /* Port 0 */
#define PM0     (WORD)0x0001            /* Port 0 Mode reg. */
#define PMC0    (WORD)0x0002    /* Port 0 Mode Control reg. */
#define P1              (WORD)0x0008    /* Port 1 */
#define PM1     (WORD)0x0009            /* Port 1 Mode reg. */
#define PMC1    (WORD)0x000a    /* Port 1 Mode Control reg. */
#define P2              (WORD)0x0010    /* Port 2 */
#define PM2     (WORD)0x0011            /* Port 2 Mode reg. */
#define PMC2    (WORD)0x0012    /* Port 2 Mode Control reg. */
#define PT              (WORD)0x0038    /* Port T */
#define PMT     (WORD)0x003b            /* Port T Mode reg. */

#define INTM    (WORD)0x0040    /* registre INTM */

#define EXIC0   (WORD)0x004C    /* registre EXIC0 */
#define EXIC1   (WORD)0x004d    /* registre EXIC1 */

#define SCM0    (WORD)0x0068    /* Establece como sera la se§al serie 0 */
#define SCC0    (WORD)0x0069    /* n del puerto serie 0 BAUDIOS */
#define BRG0    (WORD)0x006A    /* G del puerto serie 0 BAUDIOS */
#define SCM1    (WORD)0x0078
#define SEIC0   (WORD)0x006C
#define SEIC1   (WORD)0x007C
#define SRIC0   (WORD)0x006D
#define SRIC1   (WORD)0x007D
#define STIC0   (WORD)0x006E
#define STIC1   (WORD)0x007E
#define SCE0    (WORD)0x006B
#define SCE1    (WORD)0x007B


#define PRC     (WORD)0x00eb            /* registre PRC control rellotge i temp. */
#define TBIC    (WORD)0x00ec    /* registre TBIC timer base interrupt control */
#define TM0   (WORD)0x0080              /* timer register 0 */
#define MD0   (WORD)0x0082              /* Modulo / timer register 0 */
#define TM1   (WORD)0x0088              /* timer register 1 */
#define MD1   (WORD)0x008a              /* Modulo / timer register 1 */
#define TMC0  (WORD)0x0090              /* timer control register 0 */
#define TMC1  (WORD)0x0091              /* timer control register 1 */
#define TMIC0 (WORD)0x009c              /* timer unit interrupt request register 0 */
#define TMIC1 (WORD)0x009d              /* timer unit interrupt request register 1 */
#define TMIC2 (WORD)0x009e              /* timer unit interrupt request register 2 */

#define RxB0 (WORD) 0x0060
#define TxB0 (WORD) 0x0062
#define RxB1 (WORD) 0x0070
#define TxB1 (WORD) 0x0072

#endif  /* !defined(_REGISTRES) */
