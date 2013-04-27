#ifndef DL32COLOR_H
#define DL32COLOR_H

#include "dl32Config.h"

#include <Windows.h>

typedef DWORD dl32Color;

const dl32Color ARGBMASK_NOALFA=0x00FFFFFF;
const dl32Color ARGBMASK_ALFAONLY=0xFF000000;
const dl32Color ARGBMASK_NORED=0xFF00FFFF;
const dl32Color ARGBMASK_REDONLY=0x00FF0000;
const dl32Color ARGBMASK_NOGREEN=0xFFFF00FF;
const dl32Color ARGBMASK_GREENONLY=0x0000FF00;
const dl32Color ARGBMASK_NOBLUE=0xFFFFFF00;
const dl32Color ARGBMASK_BLUEONLY=0x000000FF;

#define DL32COLOR_TRANSPARENT 0x00FFFFFF
#define DL32COLOR_ALICEBLUE 0xFFF0F8FF
#define DL32COLOR_ANTIQUEWHITE 0xFFFAEBD7
#define DL32COLOR_AQUA 0xFF00FFFF
#define DL32COLOR_AQUAMARINE 0xFF7FFFD4
#define DL32COLOR_AZURE 0xFFF0FFFF
#define DL32COLOR_BEIGE 0xFFF5F5DC
#define DL32COLOR_BISQUE 0xFFFFE4C4
#define DL32COLOR_BLACK 0xFF000000
#define DL32COLOR_BLANCHEDALMOND 0xFFFFEBCD
#define DL32COLOR_BLUE 0xFF0000FF
#define DL32COLOR_BLUEVIOLET 0xFF8A2BE2
#define DL32COLOR_BROWN 0xFFA52A2A
#define DL32COLOR_BURLYWOOD 0xFFDEB887
#define DL32COLOR_CADETBLUE 0xFF5F9EA0
#define DL32COLOR_CHARTREUSE 0xFF7FFF00
#define DL32COLOR_CHOCOLATE 0xFFD2691E
#define DL32COLOR_CORAL 0xFFFF7F50
#define DL32COLOR_CORNFLOWERBLUE 0xFF6495ED
#define DL32COLOR_CORNSILK 0xFFFFF8DC
#define DL32COLOR_CRIMSON 0xFFDC143C
#define DL32COLOR_CYAN 0xFF00FFFF
#define DL32COLOR_DARKBLUE 0xFF00008B
#define DL32COLOR_DARKCYAN 0xFF008B8B
#define DL32COLOR_DARKGOLDENROD 0xFFB8860B
#define DL32COLOR_DARKGRAY 0xFFA9A9A9
#define DL32COLOR_DARKGREEN 0xFF006400
#define DL32COLOR_DARKKHAKI 0xFFBDB76B
#define DL32COLOR_DARKMAGENTA 0xFF8B008B
#define DL32COLOR_DARKOLIVEGREEN 0xFF556B2F
#define DL32COLOR_DARKORANGE 0xFFFF8C00
#define DL32COLOR_DARKORCHID 0xFF9932CC
#define DL32COLOR_DARKRED 0xFF8B0000
#define DL32COLOR_DARKSALMON 0xFFE9967A
#define DL32COLOR_DARKSEAGREEN 0xFF8FBC8B
#define DL32COLOR_DARKSLATEBLUE 0xFF483D8B
#define DL32COLOR_DARKSLATEGRAY 0xFF2F4F4F
#define DL32COLOR_DARKTURQUOISE 0xFF00CED1
#define DL32COLOR_DARKVIOLET 0xFF9400D3
#define DL32COLOR_DEEPPINK 0xFFFF1493
#define DL32COLOR_DEEPSKYBLUE 0xFF00BFFF
#define DL32COLOR_DIMGRAY 0xFF696969
#define DL32COLOR_DODGERBLUE 0xFF1E90FF
#define DL32COLOR_FIREBRICK 0xFFB22222
#define DL32COLOR_FLORALWHITE 0xFFFFFAF0
#define DL32COLOR_FORESTGREEN 0xFF228B22
#define DL32COLOR_FUCHSIA 0xFFFF00FF
#define DL32COLOR_GAINSBORO 0xFFDCDCDC
#define DL32COLOR_GHOSTWHITE 0xFFF8F8FF
#define DL32COLOR_GOLD 0xFFFFD700
#define DL32COLOR_GOLDENROD 0xFFDAA520
#define DL32COLOR_GRAY 0xFF808080
#define DL32COLOR_GREEN 0xFF008000
#define DL32COLOR_GREENYELLOW 0xFFADFF2F
#define DL32COLOR_HONEYDEW 0xFFF0FFF0
#define DL32COLOR_HOTPINK 0xFFFF69B4
#define DL32COLOR_INDIANRED 0xFFCD5C5C
#define DL32COLOR_INDIGO 0xFF4B0082
#define DL32COLOR_IVORY 0xFFFFFFF0
#define DL32COLOR_KHAKI 0xFFF0E68C
#define DL32COLOR_LAVENDER 0xFFE6E6FA
#define DL32COLOR_LAVENDERBLUSH 0xFFFFF0F5
#define DL32COLOR_LAWNGREEN 0xFF7CFC00
#define DL32COLOR_LEMONCHIFFON 0xFFFFFACD
#define DL32COLOR_LIGHTBLUE 0xFFADD8E6
#define DL32COLOR_LIGHTCORAL 0xFFF08080
#define DL32COLOR_LIGHTCYAN 0xFFE0FFFF
#define DL32COLOR_LIGHTGOLDENRODYELLOW 0xFFFAFAD2
#define DL32COLOR_LIGHTGRAY 0xFFD3D3D3
#define DL32COLOR_LIGHTGREEN 0xFF90EE90
#define DL32COLOR_LIGHTPINK 0xFFFFB6C1
#define DL32COLOR_LIGHTSALMON 0xFFFFA07A
#define DL32COLOR_LIGHTSEAGREEN 0xFF20B2AA
#define DL32COLOR_LIGHTSKYBLUE 0xFF87CEFA
#define DL32COLOR_LIGHTSLATEGRAY 0xFF778899
#define DL32COLOR_LIGHTSTEELBLUE 0xFFB0C4DE
#define DL32COLOR_LIGHTYELLOW 0xFFFFFFE0
#define DL32COLOR_LIME 0xFF00FF00
#define DL32COLOR_LIMEGREEN 0xFF32CD32
#define DL32COLOR_LINEN 0xFFFAF0E6
#define DL32COLOR_MAGENTA 0xFFFF00FF
#define DL32COLOR_MAROON 0xFF800000
#define DL32COLOR_MEDIUMAQUAMARINE 0xFF66CDAA
#define DL32COLOR_MEDIUMBLUE 0xFF0000CD
#define DL32COLOR_MEDIUMORCHID 0xFFBA55D3
#define DL32COLOR_MEDIUMPURPLE 0xFF9370DB
#define DL32COLOR_MEDIUMSEAGREEN 0xFF3CB371
#define DL32COLOR_MEDIUMSLATEBLUE 0xFF7B68EE
#define DL32COLOR_MEDIUMSPRINGGREEN 0xFF00FA9A
#define DL32COLOR_MEDIUMTURQUOISE 0xFF48D1CC
#define DL32COLOR_MEDIUMVIOLETRED 0xFFC71585
#define DL32COLOR_MIDNIGHTBLUE 0xFF191970
#define DL32COLOR_MINTCREAM 0xFFF5FFFA
#define DL32COLOR_MISTYROSE 0xFFFFE4E1
#define DL32COLOR_MOCCASIN 0xFFFFE4B5
#define DL32COLOR_NAVAJOWHITE 0xFFFFDEAD
#define DL32COLOR_NAVY 0xFF000080
#define DL32COLOR_OLDLACE 0xFFFDF5E6
#define DL32COLOR_OLIVE 0xFF808000
#define DL32COLOR_OLIVEDRAB 0xFF6B8E23
#define DL32COLOR_ORANGE 0xFFFFA500
#define DL32COLOR_ORANGERED 0xFFFF4500
#define DL32COLOR_ORCHID 0xFFDA70D6
#define DL32COLOR_PALEGOLDENROD 0xFFEEE8AA
#define DL32COLOR_PALEGREEN 0xFF98FB98
#define DL32COLOR_PALETURQUOISE 0xFFAFEEEE
#define DL32COLOR_PALEVIOLETRED 0xFFDB7093
#define DL32COLOR_PAPAYAWHIP 0xFFFFEFD5
#define DL32COLOR_PEACHPUFF 0xFFFFDAB9
#define DL32COLOR_PERU 0xFFCD853F
#define DL32COLOR_PINK 0xFFFFC0CB
#define DL32COLOR_PLUM 0xFFDDA0DD
#define DL32COLOR_POWDERBLUE 0xFFB0E0E6
#define DL32COLOR_PURPLE 0xFF800080
#define DL32COLOR_RED 0xFFFF0000
#define DL32COLOR_ROSYBROWN 0xFFBC8F8F
#define DL32COLOR_ROYALBLUE 0xFF4169E1
#define DL32COLOR_SADDLEBROWN 0xFF8B4513
#define DL32COLOR_SALMON 0xFFFA8072
#define DL32COLOR_SANDYBROWN 0xFFF4A460
#define DL32COLOR_SEAGREEN 0xFF2E8B57
#define DL32COLOR_SEASHELL 0xFFFFF5EE
#define DL32COLOR_SIENNA 0xFFA0522D
#define DL32COLOR_SILVER 0xFFC0C0C0
#define DL32COLOR_SKYBLUE 0xFF87CEEB
#define DL32COLOR_SLATEBLUE 0xFF6A5ACD
#define DL32COLOR_SLATEGRAY 0xFF708090
#define DL32COLOR_SNOW 0xFFFFFAFA
#define DL32COLOR_SPRINGGREEN 0xFF00FF7F
#define DL32COLOR_STEELBLUE 0xFF4682B4
#define DL32COLOR_TAN 0xFFD2B48C
#define DL32COLOR_TEAL 0xFF008080
#define DL32COLOR_THISTLE 0xFFD8BFD8
#define DL32COLOR_TOMATO 0xFFFF6347
#define DL32COLOR_TURQUOISE 0xFF40E0D0
#define DL32COLOR_VIOLET 0xFFEE82EE
#define DL32COLOR_WHEAT 0xFFF5DEB3
#define DL32COLOR_WHITE 0xFFFFFFFF
#define DL32COLOR_WHITESMOKE 0xFFF5F5F5
#define DL32COLOR_YELLOW 0xFFFFFF00
#define DL32COLOR_YELLOWGREEN 0xFF9ACD32

#define DL32COLOR_MAXRAINBOWVALUE 1280
#define DL32COLOR_RAINBOW_CUSTOMINTERVAL(x,min,max) (DL32COLOR_MAXRAINBOWVALUE*(x-min)/(min+max))


//NOTA: Visual Studio no pone implicitamenteen funciones globales. Gracias Puri. Maldito Visual Studio...

inline dl32Color COLOR_FromARGB(byte A,byte R, byte G, byte B){return (A<<24) | (R<<16) | (G<<8) | B;}
inline dl32Color COLOR_FromRGB(byte R, byte G, byte B){return 0xFF000000 | (R<<16) | (G<<8) | B;}

inline dl32Color COLOR_FromKnownColor(dl32Color color, DWORD alfa){return (color & ARGBMASK_NOALFA) | (alfa << 24);}

inline dl32Color COLOR_GetAlfaColor(dl32Color color){return color & ARGBMASK_ALFAONLY;}
inline dl32Color COLOR_GetRedColor(dl32Color color){return color & ARGBMASK_REDONLY;}
inline dl32Color COLOR_GetGreenColor(dl32Color color){return color & ARGBMASK_GREENONLY;}
inline dl32Color COLOR_GetBlueColor(dl32Color color){return color & ARGBMASK_BLUEONLY;}

inline byte COLOR_GetAlfa(dl32Color color){return (byte)((color & ARGBMASK_ALFAONLY) >> 24);}
inline byte COLOR_GetRed(dl32Color color){return (byte)((color & ARGBMASK_REDONLY) >> 16);}
inline byte COLOR_GetGreen(dl32Color color){return (byte)((color & ARGBMASK_GREENONLY) >> 8);}
inline byte COLOR_GetBlue(dl32Color color){return (byte)(color & ARGBMASK_BLUEONLY);}

inline void COLOR_SetAlfa(dl32Color &color,byte A){color = (color & ARGBMASK_NOALFA) | (A << 24);}
inline void COLOR_SetRed(dl32Color &color,byte R){color = (color & ARGBMASK_NORED) | (R << 16);}
inline void COLOR_SetGreen(dl32Color &color,byte G){color = (color & ARGBMASK_NOGREEN) | (G << 8);}
inline void COLOR_SetBlue(dl32Color &color,byte B){color = (color & ARGBMASK_NOBLUE) | B;}

dl32Color COLOR_Add(dl32Color C1,dl32Color C2);
dl32Color COLOR_Sub(dl32Color C1,dl32Color C2);
dl32Color COLOR_Blend(dl32Color C1,dl32Color C2);

dl32Color COLOR_RainbowGradient(DWORD value);
inline dl32Color COLOR_RainbowGradient(DWORD value, DWORD minValue, DWORD maxValue){return COLOR_RainbowGradient(DL32COLOR_RAINBOW_CUSTOMINTERVAL(value,minValue,maxValue));}
#endif