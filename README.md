Proyecto cpp_lib32
==================

[![Build Status](https://secure.travis-ci.org/Manu343726/cpp_lib32.png?branch=BigRefactoring)](http://travis-ci.org/Manu343726/cpp_lib32)


Éste proyecto es un intento de portar dx_lib32 a C++ utilizando DirectX9, y en un futuro OpenGL.


¿Que es dx_lib32?
-----------------

El proyecto dx_lib32 es un sencillo API de programación multimedia diseñado para desarrollar juegos con Visual Basic 6, VB.NET, o C#.
dx_lib32 encapsula la mayoría de llamadas a rutinas de DirectX, ofreciendo al programador una interfaz sencilla y eficiente para 
programar videojuegos 2D sin preocupaciones. La API provee de cinco clases dedicadas al manejo de gráficos, audio, input, 
reproducción de video, y una colección de otras funciones útiles para otras tareas.


Acerca del proyecto:
--------------------

El proyecto dx_lib32 fue desarrollado por José Miguel Sánchez Fernandez a lo largo de diez años, con el propósito
de proveer una herramienta sencilla para desarrollar un videojuego con Visual Basic 6. En junio de 2012, el código fuente 
fue liberado bajo licencia LGPL2 ( https://github.com/VisualStudioEX3/dx_lib32 ), momento en el que decidí portar la librería a C++, lenguaje que me parece mucho más adecuado 
para la programación de videojuegos.

Dadas las diferencias entre C++ y Visual Basic 6, el port no puede mantener exactamente la estructura y funcionamiento de la
API original, pero procuro implementarlo de manera que no se pierda la "esencia" de la librería. 

El proyecto aún está en una fase temprana del desarrollo, de manera que por ahora no ofrezco ninguna garantía de funcionamiento.
Cada poco tiempo suelo comentar los avances en el blog sobre el desarrollo del proyecto ( http://dxlib32cpp.blogspot.com.es/ )
Para conocer los cambios día a día es mejor seguir el proyecto vía twitter, suelo escribir en mi cuenta mientras programo 
( https://twitter.com/Manu343726 ). Agradezco sugerencias, críticas, e información sobre errores.


Código fuente:
--------------

El código fuente está organizado en diferentes subcarpetas:
 - **code/headers**: Cabeceras del proyecto. 
 - **code/headers/utils**: Utilidades (Mayormente herramientas para depuración) que forman parte de la API. Incluye el archivo de configuración de la API (dl32Config.h)
 - **code/source**: Implementación de las cabeceras del proyecto.
 - **code/source/utils**: Implementacion de las utilidades.
 
Además, el proyecto incluye una serie de test utilizados para depurar la API:
 - **code/tests/general tests**: Test generales del proyecto. Incluye un test de stress de la API gráfica (General stress test.cpp)
 - **code/tests/particle engine**: Un sencillo motor de partículas para probar las capacidades de la API gráfica (En concreto de la función dl32GraphicsClass::DRAW_Pixels())
 - **code/tests/pong**: Una sencilla implementación del clásico Pong
 - **code/tests/polyline**: Test de implementación de polyline. El algoritmo utilizado por dl32GraphicsClass::DRAW_Polyline() fue implementado y probado  en éste test,
   y posteriormente fue incluido en la API gráfica.
 - **code/tests/isometric tilemap**: Implementación de un engine para renderizar tilemaps isometricos al estilo de Sim City 3000

*NOTA: El test a ejecutar se selecciona mediante la macro "DL32DEBUG_DEBUGTEST" que se incluye en dl32TestConfig.h*
 
 
Por último, se incluye un proyecto de Visual Studio ya configurado, compatible tanto con la versión 2010 como con la versión 2012.

Como se menciona en el apartado anterior, "Acerca del proyecto", el proyecto se encuentra en una fase muy temprana de desarrollo. Ésto implica que el código está expuesto
a continuos cambios y revisiones, además de no estar todavía debidamente documentado. Es muy posible que muchas versiones del código contengan bugs, o incluso no funcionen.
En un futuro, cuando el proyecto esté mas avanzado, separaré el proyecto en varias ramas, una versión estable, y otra en fase de desarrollo. Pero por ahora todos los cambios y revisiones serán realizadas en la rama master. 

Estado del proyecto:
--------------------

Desde hace un par de meses estoy llevando a cabo una profunda refactorización del proyecto, limpieza de la API, y documentación en general. 
Todo este desarrollo se lleva acabo en la rama "BigRefactoring" ( https://github.com/Manu343726/cpp_lib32/tree/BigRefactoring ), que actualmente es la rama principal del proyecto.
La rama "master" está completamente desactualizada, y en estos momentos no está pensada para ser utilizada. Hasta que no termine todo este "lavado de cara", no volveré a trabajar sobre master.

La última versión de la librería que considero completamente funcional es https://github.com/Manu343726/cpp_lib32/commit/444429b03759e045119c45cbeeb0297a4c7af40b.


Contribuidores y agradecimientos:
---------------------------------

En primer lugar me gustaría agredecer a [EX3] el haber liberado la dx_lib32, y así permitir el acceso al código. Además, agradezco también la ayuda que me 
presta muy de vez en cuando, resolución de dudas, dilemas, etc. 
Por otro lado me gustaría dar las gracias a la gente de los foros de StratosAD, siempre dispuestos a resolver dudas y a compartir conociemintos. De lo mejorcito
que hay por españa en cuanto a desarrolladores de videojuegos se refiere.

Por último, y no por ello menos importante, me gustaría dar diversos agradecimientos a gente que me aguanta día a día; me ha resuelto alguna duda que otra, o simplemente
me ha ayudado en el momento adecuado:
 - A Miguel Oliver, quien fue durante un perdiodo corto de tiempo colaborador en el proyecto. Sienta bien tener otros puntos de vista, y espero que en un futuro puedas
   volver a unirte al "equipo".
 - A Gorka Suarez, quien siempre está ahí para resolver mis desvaríos varios, y nunca        pone trabas a ayudarme. 
 - Seguramente mucha gente más, poco a poco iré rellenando. 

 
 
 
 
 
 