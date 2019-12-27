/*
//		TYPEDEFS.H - General purpose definition file, Version 5.0
//		Copyright (C) 1989, 1994 Paradigm Systems.  All rights reserved.
//
//		*********************************************************************
//		Permission to modify and distribute object files based on this
//		source code is granted to licensed users of Paradigm LOCATE.
//
//		Under no circumstances is this source code to be re-distributed
//		without the express permission of Paradigm Systems.
//		*********************************************************************
//
//		Function		
//		========
//		This file contains the general purpose definitions common to the
//		all Paradigm applications.  By defining synonyms for the physical
//		data types to be manipulated, portability between memory models
//		and machines is maximized.
//
//		Note that this file follows the system include files and before
//		any application include files.
//
*/

#if	!defined(_TYPEDEFS)
#define	_TYPEDEFS

/*
//		Define the types to be used to manipulate 8-, 16-, 32- and 64-bit
//		data.
*/
#if	!defined(__TURBOC__)
typedef	unsigned char	BIT ;			/* Use for defining MSC bit fields */
#else
typedef	unsigned 		BIT ;			/* Use for defining Turbo C bit fields */
#endif	/* __TURBOC__ */

typedef	unsigned char	BYTE ;		/* 8-bit data */
typedef	unsigned int	WORD ;		/* 16-bit data */
typedef	unsigned long	DWORD ;		/* 32-bit data */
typedef	double			QWORD ;		/* 64-bit data */

typedef	float				FLOAT ;		/* 32-bit floating point data */
typedef	double			DOUBLE ;		/* 64-bit floating point data */

typedef	void far *		PTR ;			/* Pointer to any data type */
typedef	BYTE far *		BYTE_PTR ;	/* Pointer to 8-bit data */
typedef	WORD far *		WORD_PTR ;	/* Pointer to 16-bit data */
typedef	DWORD far *		DWORD_PTR ;	/* Pointer to 32-bit data */
typedef	QWORD far *		QWORD_PTR ;	/* Pointer to 64-bit data */

/*
//		Define the boolean data type
*/
typedef	enum { FALSE = 0, TRUE } BOOL ;


/*
//		Define some common macros that show up everywhere.  These are
//
//			lowbyte(x)		Extract the low order byte of WORD x
//			highbyte(x)		Extract the high order byte of WORD x
//			dim(x)			Computes the dimension of an array
*/
#define	lowbyte(word)		((word) & 0xff)
#define	highbyte(word)		lowbyte((word) >> 8)
#define	dim(x)				(sizeof(x) / sizeof(x[0]))

#if	!defined(min)
#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#endif



#endif	/* _TYPEDEFS */
