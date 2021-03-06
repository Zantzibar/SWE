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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Cocktailmixer.o \
	${OBJECTDIR}/Dosierer.o \
	${OBJECTDIR}/Geraet.o \
	${OBJECTDIR}/MischbaresRezepteBuch.o \
	${OBJECTDIR}/Mischbehaelter.o \
	${OBJECTDIR}/Mischer.o \
	${OBJECTDIR}/RezepturProzessor.o \
	${OBJECTDIR}/Stampfer.o \
	${OBJECTDIR}/Subject.o \
	${OBJECTDIR}/Timer.o \
	${OBJECTDIR}/Waage.o \
	${OBJECTDIR}/Zutatenliste.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=RezeptbuchBinaries/Rezeptbuch_g++_CASE_Ubuntu.o

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nb_cocktailpro

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nb_cocktailpro: RezeptbuchBinaries/Rezeptbuch_g++_CASE_Ubuntu.o

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nb_cocktailpro: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nb_cocktailpro ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Cocktailmixer.o: Cocktailmixer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cocktailmixer.o Cocktailmixer.cpp

${OBJECTDIR}/Dosierer.o: Dosierer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dosierer.o Dosierer.cpp

${OBJECTDIR}/Geraet.o: Geraet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Geraet.o Geraet.cpp

${OBJECTDIR}/MischbaresRezepteBuch.o: MischbaresRezepteBuch.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MischbaresRezepteBuch.o MischbaresRezepteBuch.cpp

${OBJECTDIR}/Mischbehaelter.o: Mischbehaelter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mischbehaelter.o Mischbehaelter.cpp

${OBJECTDIR}/Mischer.o: Mischer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mischer.o Mischer.cpp

${OBJECTDIR}/RezepturProzessor.o: RezepturProzessor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RezepturProzessor.o RezepturProzessor.cpp

${OBJECTDIR}/Stampfer.o: Stampfer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Stampfer.o Stampfer.cpp

${OBJECTDIR}/Subject.o: Subject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Subject.o Subject.cpp

${OBJECTDIR}/Timer.o: Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Timer.o Timer.cpp

${OBJECTDIR}/Waage.o: Waage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Waage.o Waage.cpp

${OBJECTDIR}/Zutatenliste.o: Zutatenliste.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Zutatenliste.o Zutatenliste.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nb_cocktailpro

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
