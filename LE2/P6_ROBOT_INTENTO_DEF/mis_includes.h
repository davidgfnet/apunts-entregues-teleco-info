

#ifndef  MIS_INCLUDES
#define  MIS_INCLUDES

// Muy Util:
#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10
#define BIT5  0x20
#define BIT6  0x40
#define BIT7  0x80

void motor_estat (BYTE num_motor, BYTE codi_estat);

#define pinza_abrir motor_estat(4,0x2)
#define pinza_cerrar motor_estat(4,0x1)
#define pinza_parar motor_estat(4,0x3)

#define rot_antihorario motor_estat(1,0x2)
#define rot_horario motor_estat(1,0x1)
#define rot_parar motor_estat(1,0x3)

#define movh_atras motor_estat(2,0x2)
#define movh_delante motor_estat(2,0x1)
#define movh_parar motor_estat(2,0x3)

#define movv_arriba motor_estat(3,0x2)
#define movv_abajo motor_estat(3,0x1)
#define movv_parar motor_estat(3,0x3)

#define parar_todo pinza_parar;rot_parar;movh_parar;movv_parar


///// CODIS DE TECLA!!!!   
#define ABRIR_PINZA	0x00
#define CERRAR_PINZA	0x04
#define DELANTE		0x06
#define ATRAS		   0x02
#define ARRIBA		   0x01
#define ABAJO		   0x05
#define ANTIHORARIO	0x03
#define HORARIO		0x07
#define INICIO       0x0E
#define ALMACENAR    0x09
#define REPRODUCIR   0x0D
#define BORRAR       0x0A

#endif

