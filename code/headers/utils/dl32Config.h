/******************************************
 * dx_lib32 - Configuración de compilación *
 ******************************************/

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define ANDOP(a,b) ((a == TRUE && b == TRUE) ? TRUE : FALSE) 
#define OROP(a,b) ((a == TRUE || b == TRUE) ? TRUE : FALSE) 
#define NOTOP(a) ((a == TRUE) ? FALSE : TRUE)

#ifndef YES
#define YES TRUE
#define NO FALSE
#endif
#ifndef ENABLED
#define ENABLED TRUE
#define DISABLED FALSE
#endif

//CONFIGURACI�N DE RENDIMIENTO Y SEGURIDAD:
///////////////////////////////////////////
#define DL32COMPILEMODE_PERFORMANCE 0
#define DL32COMPILEMODE_SECURE 1
#define DL32COMPILEMODE_USERDEFINED 2

#define DL32COMPILEMODE DL32COMPILEMODE_USERDEFINED

#if DL32COMPILEMODE == DL32COMPILEMODE_PERFORMANCE
#define DL32FLAGS_CHECKOVERFLOW DISABLED
#define DL32FLAGS_CHECKARRAYINDEXES DISABLED
#define DL32FLAGS_CHECKMATRIXOPERATIONS DISABLED
#define DL32FLAGS_MATRIXASIGNCOPYREF ENABLED
#elif DL32COMPILEMODE == DL32COMPILEMODE_SECURE
#define DL32FLAGS_CHECKOVERFLOW ENABLED
#define DL32FLAGS_CHECKARRAYINDEXES ENABLED
#define DL32FLAGS_CHECKMATRIXOPERATIONS ENABLED
#define DL32FLAGS_MATRIXASIGNCOPYREF DISABLED
#else
//#error DL32COMPILEMODE == DL32COMPILEMODE_USERDEFINED: No DL32FLAGS defined !!!
#define DL32FLAGS_CHECKOVERFLOW ENABLED
#define DL32FLAGS_CHECKARRAYINDEXES ENABLED
#define DL32FLAGS_CHECKMATRIXOPERATIONS ENABLED
#define DL32FLAGS_MATRIXASIGNCOPYREF ENABLED
#endif

//CONFIGURACI�N DE PRECISI�N NUM�RICA:
//////////////////////////////////////
#define DL32FLOAT_EPSILON 0.0001

#define DL32FLOAT_EQ(x,y) (((y - DL32FLOAT_EPSILON) < x) && ((y + DL32FLOAT_EPSILON) > x))
#define DL32FLOAT_NE(x,y) !DL32FLOAT_EQ(x,y)
#define DL32FLOAT_EQCERO(x) ((x < DL32FLOAT_EPSILON) && (x > -DL32FLOAT_EPSILON))
#define DL32FLOAT_NECERO(x) !DL32FLOAT_EQCERO(x)

#define DL32FLOAT_GE(x,y) (DL32FLOAT_EQ(x,y) || (x > y))
#define DL32FLOAT_LE(x,y) (DL32FLOAT_EQ(x,y) || (x < y))

//CONFIGURACI�N DE DEPURACI�N:
//////////////////////////////
#define DL32DEBUG_DL32WINDOW_PROMPTUNHANDLEDWMSGS NO
#define DL32DEBUG_DL32WINDOW_PROMPTPREPROCESSEDWMSGS NO
#define DL32DEBUG_DL32CONSOLE_AUTOOPEN ENABLED //Abre la consola autom�ticamente si se hace una escritura con la consola cerrada (Solo para depuraci�n)

#define DL32DEBUG_DL32CONSOLE_AUTOOPEN_TITLE "dx_lib32 (Debug) [AutoOpen]"

#define DL32DEBUG_SPLINE_PROMPTINTERVALDATA NO
#define DL32DEBUG_GENERAL_PROMPTUNHANDLEDEXCEPTIONS YES
#define DL32DEBUG_TIMING DISABLED
#define DL32DEBUG_TIMING_INTERNAL DISABLED
#define DL32DEBUG_TIMING_PROMPTPUSH ANDOP(OROP(DL32DEBUG_TIMING,DL32DEBUG_TIMING_INTERNAL) , YES)
#define DL32DEBUG_TIMING_PROMPTPOP ANDOP(OROP(DL32DEBUG_TIMING,DL32DEBUG_TIMING_INTERNAL) , YES)

#define DL32DEBUG_GRAPHICS_DRAWCALLSMERGE ENABLED

//CONFIGURACI�N DE TESTS:
/////////////////////////
#define DL32TEST_GENERAL_STRESS 0
#define DL32TEST_GENERAL_MATRIX 1
#define DL32TEST_GENERAL_ECUATIONSYSTEM 2

#define DL32TEST_MANDELBROTFRACTAL_SIMPLETEST 3

#define DL32TEST_PARTICLEENGINE_SIMPLETEST 4

#define DL32TEST_LAURA_PONG_PSEUDOPLAYABLE 5

#define DL32TEST_POLYLINE_SIMPLETEST 6

#define DL32TEST_ISOMETRICENGINE_ENGINETEST 7

#define DL32TESTS_CURRENTTEST DL32TEST_ISOMETRICENGINE_ENGINETEST 

//DESACTIVACI�N DE WARNINGS:
////////////////////////////
#pragma warning(disable : 4290) //Visual Studio no implementa la especificaci�n de excepciones. A cambio te lanza el 4290...