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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o
POSSIBLE_DEPFILES=${OBJECTDIR}/CAN1Config.o.d ${OBJECTDIR}/CAN2Config.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/RTC.o.d ${OBJECTDIR}/GPS.o.d ${OBJECTDIR}/UART1.o.d ${OBJECTDIR}/UART2.o.d ${OBJECTDIR}/PARAMETERS.o.d ${OBJECTDIR}/SPI.o.d ${OBJECTDIR}/MESSAGES.o.d ${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/TIMER.o.d ${OBJECTDIR}/TELEMETRY.o.d ${OBJECTDIR}/STATEMACHINE.o.d ${OBJECTDIR}/TEMPORIZATIONS.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o

# Source Files
SOURCEFILES=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128GP706A
MP_LINKER_FILE_OPTION=,--script=p33FJ128GP706A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/fdad2b6c6ec012f39f70b274be0ecd59b1563919 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/8f71e9860538485f6732a973f58775e082c70962 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/20f5a55d1acd856ca938eb10f1801ad1b71feea9 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/b586c5644816e614a8d7c5458bee1504ec56ac68 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/5360f55ba81b627f5b58bfceda89366bacd2e783 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/eac03bdec4128b0a661f892d9ca73b1d349be167 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/41371ab3cee8e45705f6570eb17c409f5d29d51a .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/b6ee6cf557bfbd4882ef165460fd7ae9b5bbfd4c .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/3f8fc8d5f00043d79797390eaa1ba10d28bb96bc .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/8817703814d0a48d2f1f0552b23526d843ebe176 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/1c39b025e347bc2dddbe48b458e79d6d71398603 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/5aa20cbb1867169fcb25fbb163c47c5cda4547a8 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/53acda5a92dffc21e28e55832175f58c3a167cf6 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/65b4594570d02edc3fcc28dda03168ace99ae136 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/d241eaa5e442da3f76abde5b3964eb4bf3d49ec6 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/d557ced9765be24369a3f75787d07783c45ec3f4 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/77b489febef61e27047bd1297bd9102a5a96e43 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/d433dd0d6caf048c11dc47690be890c58a74f2e9 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/e85139a56ba58c0289ca3dea5f1d777d323d1f2b .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/f0b76689b8431feb899059b9c4364536272ca657 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/778bfaae23415c5a0f0f5890b5eefab9cd76c721 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/56c61820d1035246c62eccede53bde70640e9d7 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/c677394569273cfa253d3d504a761a7d4e375d77 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/60c8e331cd601c7b85bb785cb803e23cb61f99fe .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/39f91416f6996d0c16f6582d41e3bf323c596817 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/ed11f67bc60d749fdbc213d52b81c7ca63625610 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/dd3da6adbe94a49df6ee3d8fbfb6029a3a2af5f8 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/d5a76d882532756adfb21f4468c5a887e00e5e73 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/e3437703c20c877097cd79a31a5021b66d4af748 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/30bf187bc17805ae6c781377e0f74cbf6ffd8723 .generated_files/flags/default/d346cc6f7ef1fcd8a3362cbad301b52a0945d9c7
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
