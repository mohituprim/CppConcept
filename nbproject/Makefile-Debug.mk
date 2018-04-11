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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/Algorithms.o \
	${OBJECTDIR}/BitAlgo.o \
	${OBJECTDIR}/Creational/BoostDI.o \
	${OBJECTDIR}/Creational/ISP.o \
	${OBJECTDIR}/Creational/LSP.o \
	${OBJECTDIR}/Creational/OCP.o \
	${OBJECTDIR}/Creational/SRP.o \
	${OBJECTDIR}/DynamicAlgo.o \
	${OBJECTDIR}/FunctionOverloading.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/MutableExample.o \
	${OBJECTDIR}/ObjectRelated.o \
	${OBJECTDIR}/OperatorOverloading.o \
	${OBJECTDIR}/STLExample.o \
	${OBJECTDIR}/StructLinkedList.o \
	${OBJECTDIR}/StructStack.o \
	${OBJECTDIR}/Tree.o \
	${OBJECTDIR}/lambda.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppconcepttest

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppconcepttest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppconcepttest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Algorithms.o: Algorithms.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms.o Algorithms.cpp

${OBJECTDIR}/BitAlgo.o: BitAlgo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BitAlgo.o BitAlgo.cpp

${OBJECTDIR}/Creational/BoostDI.o: Creational/BoostDI.cpp
	${MKDIR} -p ${OBJECTDIR}/Creational
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Creational/BoostDI.o Creational/BoostDI.cpp

${OBJECTDIR}/Creational/ISP.o: Creational/ISP.cpp
	${MKDIR} -p ${OBJECTDIR}/Creational
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Creational/ISP.o Creational/ISP.cpp

${OBJECTDIR}/Creational/LSP.o: Creational/LSP.cpp
	${MKDIR} -p ${OBJECTDIR}/Creational
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Creational/LSP.o Creational/LSP.cpp

${OBJECTDIR}/Creational/OCP.o: Creational/OCP.cpp
	${MKDIR} -p ${OBJECTDIR}/Creational
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Creational/OCP.o Creational/OCP.cpp

${OBJECTDIR}/Creational/SRP.o: Creational/SRP.cpp
	${MKDIR} -p ${OBJECTDIR}/Creational
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Creational/SRP.o Creational/SRP.cpp

${OBJECTDIR}/DynamicAlgo.o: DynamicAlgo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DynamicAlgo.o DynamicAlgo.cpp

${OBJECTDIR}/FunctionOverloading.o: FunctionOverloading.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FunctionOverloading.o FunctionOverloading.cpp

${OBJECTDIR}/Graph.o: Graph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/MutableExample.o: MutableExample.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MutableExample.o MutableExample.cpp

${OBJECTDIR}/ObjectRelated.o: ObjectRelated.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ObjectRelated.o ObjectRelated.cpp

${OBJECTDIR}/OperatorOverloading.o: OperatorOverloading.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperatorOverloading.o OperatorOverloading.cpp

${OBJECTDIR}/STLExample.o: STLExample.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/STLExample.o STLExample.cpp

${OBJECTDIR}/StructLinkedList.o: StructLinkedList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StructLinkedList.o StructLinkedList.cpp

${OBJECTDIR}/StructStack.o: StructStack.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StructStack.o StructStack.cpp

${OBJECTDIR}/Tree.o: Tree.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree.o Tree.cpp

${OBJECTDIR}/lambda.o: lambda.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lambda.o lambda.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
