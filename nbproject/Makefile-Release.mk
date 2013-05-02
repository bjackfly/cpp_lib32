#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include dx_lib32_makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/code/source/dl32Color.o \
	${OBJECTDIR}/code/source/dl32Events.o \
	${OBJECTDIR}/code/source/dl32Math.o \
	${OBJECTDIR}/code/source/dl32Window.o \
	${OBJECTDIR}/code/source/utils/dl32Config.o \
	${OBJECTDIR}/code/source/utils/dl32Memory.o \
	${OBJECTDIR}/code/source/utils/dl32Timing.o \
	${OBJECTDIR}/code/tests/refactoring/Redesigned_event_system_test.o \
	${OBJECTDIR}/code/tests/refactoring/typing_test.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dx_lib32.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dx_lib32.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dx_lib32 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/code/source/dl32Color.o: code/source/dl32Color.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/dl32Color.o code/source/dl32Color.cpp

${OBJECTDIR}/code/source/dl32Events.o: code/source/dl32Events.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/dl32Events.o code/source/dl32Events.cpp

${OBJECTDIR}/code/source/dl32Math.o: code/source/dl32Math.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/dl32Math.o code/source/dl32Math.cpp

${OBJECTDIR}/code/source/dl32Window.o: code/source/dl32Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/dl32Window.o code/source/dl32Window.cpp

${OBJECTDIR}/code/source/utils/dl32Config.o: code/source/utils/dl32Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source/utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/utils/dl32Config.o code/source/utils/dl32Config.cpp

${OBJECTDIR}/code/source/utils/dl32Memory.o: code/source/utils/dl32Memory.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source/utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/utils/dl32Memory.o code/source/utils/dl32Memory.cpp

${OBJECTDIR}/code/source/utils/dl32Timing.o: code/source/utils/dl32Timing.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/source/utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/source/utils/dl32Timing.o code/source/utils/dl32Timing.cpp

${OBJECTDIR}/code/tests/refactoring/Redesigned_event_system_test.o: code/tests/refactoring/Redesigned_event_system_test.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/tests/refactoring
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/tests/refactoring/Redesigned_event_system_test.o code/tests/refactoring/Redesigned_event_system_test.cpp

${OBJECTDIR}/code/tests/refactoring/typing_test.o: code/tests/refactoring/typing_test.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/tests/refactoring
	${RM} $@.d
	$(COMPILE.cc) -O2 -Icode/headers -Icode/headers/utils -Icode/source -Icode/source/utils -Icode/tests -Icode/tests/general\ tests -Icode/tests/isometric\ tilemap -Icode/tests/mandlebrot -Icode/tests/particle\ engine -Icode/tests/polyline -Icode/tests/pong -MMD -MP -MF $@.d -o ${OBJECTDIR}/code/tests/refactoring/typing_test.o code/tests/refactoring/typing_test.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dx_lib32.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc