#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MASTER.c SSP.c LCDM.c oscm.c usartm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MASTER.p1 ${OBJECTDIR}/SSP.p1 ${OBJECTDIR}/LCDM.p1 ${OBJECTDIR}/oscm.p1 ${OBJECTDIR}/usartm.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/MASTER.p1.d ${OBJECTDIR}/SSP.p1.d ${OBJECTDIR}/LCDM.p1.d ${OBJECTDIR}/oscm.p1.d ${OBJECTDIR}/usartm.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MASTER.p1 ${OBJECTDIR}/SSP.p1 ${OBJECTDIR}/LCDM.p1 ${OBJECTDIR}/oscm.p1 ${OBJECTDIR}/usartm.p1

# Source Files
SOURCEFILES=MASTER.c SSP.c LCDM.c oscm.c usartm.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F887
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MASTER.p1: MASTER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MASTER.p1.d 
	@${RM} ${OBJECTDIR}/MASTER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MASTER.p1 MASTER.c 
	@${FIXDEPS} ${OBJECTDIR}/MASTER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SSP.p1: SSP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SSP.p1.d 
	@${RM} ${OBJECTDIR}/SSP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SSP.p1 SSP.c 
	@${FIXDEPS} ${OBJECTDIR}/SSP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDM.p1: LCDM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDM.p1.d 
	@${RM} ${OBJECTDIR}/LCDM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDM.p1 LCDM.c 
	@${FIXDEPS} ${OBJECTDIR}/LCDM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/oscm.p1: oscm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/oscm.p1.d 
	@${RM} ${OBJECTDIR}/oscm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/oscm.p1 oscm.c 
	@${FIXDEPS} ${OBJECTDIR}/oscm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usartm.p1: usartm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usartm.p1.d 
	@${RM} ${OBJECTDIR}/usartm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/usartm.p1 usartm.c 
	@${FIXDEPS} ${OBJECTDIR}/usartm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/MASTER.p1: MASTER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MASTER.p1.d 
	@${RM} ${OBJECTDIR}/MASTER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MASTER.p1 MASTER.c 
	@${FIXDEPS} ${OBJECTDIR}/MASTER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SSP.p1: SSP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SSP.p1.d 
	@${RM} ${OBJECTDIR}/SSP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/SSP.p1 SSP.c 
	@${FIXDEPS} ${OBJECTDIR}/SSP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCDM.p1: LCDM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDM.p1.d 
	@${RM} ${OBJECTDIR}/LCDM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/LCDM.p1 LCDM.c 
	@${FIXDEPS} ${OBJECTDIR}/LCDM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/oscm.p1: oscm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/oscm.p1.d 
	@${RM} ${OBJECTDIR}/oscm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/oscm.p1 oscm.c 
	@${FIXDEPS} ${OBJECTDIR}/oscm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/usartm.p1: usartm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usartm.p1.d 
	@${RM} ${OBJECTDIR}/usartm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/usartm.p1 usartm.c 
	@${FIXDEPS} ${OBJECTDIR}/usartm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PROYECTODM.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
