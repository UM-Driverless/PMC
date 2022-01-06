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
SOURCEFILES_QUOTED_IF_SPACED=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c AS.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o ${OBJECTDIR}/AS.o
POSSIBLE_DEPFILES=${OBJECTDIR}/CAN1Config.o.d ${OBJECTDIR}/CAN2Config.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/RTC.o.d ${OBJECTDIR}/GPS.o.d ${OBJECTDIR}/UART1.o.d ${OBJECTDIR}/UART2.o.d ${OBJECTDIR}/PARAMETERS.o.d ${OBJECTDIR}/SPI.o.d ${OBJECTDIR}/MESSAGES.o.d ${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/TIMER.o.d ${OBJECTDIR}/TELEMETRY.o.d ${OBJECTDIR}/STATEMACHINE.o.d ${OBJECTDIR}/TEMPORIZATIONS.o.d ${OBJECTDIR}/AS.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o ${OBJECTDIR}/AS.o

# Source Files
SOURCEFILES=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c AS.c



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
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/11c6062ae466485280a8eaf96e9d73e4722fe59e.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/88e33e24e56c7a1ad09f97ba9b631c6a46eb9fee.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/25814450a78bf1f78c618d7421a68bd3062a41d3.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/2f8a8410f11e722210d4166fd5a2606215284317.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/ca492d9a4aff2cb762d58e8ca00814ed41ea71cd.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/962f23d699251a14826feba287f7b1c04e2105d6.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/b7c1c9e64f21939c4f92c5c158cade569b631fe5.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/9a86f71499949777cc2839924da0be55ed847cd2.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/90a5b206219af813871bd358d66c3ff8dae1caf3.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/45865c54ad6db9925439ed3353221bd82b261af4.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/b3ad3daefe19b4679121758484c37cc3a3440826.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/bf73234c35ebcd22156826a0f5ba29109cdb4e06.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/c1b6ac8f4eac6e3b750f87333723eb82bf5150c9.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/19a8ca499a48235c1a0e970a66fa460483958ec2.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/8c1a9389b120ce20cbe45a28cf1eb7ef701ad4d2.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/9ea8cc3dc79579db0bfc438fdf2a7ea490805433.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/2e6db5844f03b9b8769901293ee49dfe34a6bb8d.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/25edab23946865973851779d11c4c5b5fe9f7fe2.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/7d9dca732d93a22e6aea8047dfc236c733bed9cb.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/17483816890a2b9e9e2815d62d2f8d6463dba1b4.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/5d8d7a89f4cfaec052ba8078824a2d4e01dde89d.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/2cc701e521fc42bb54ccf4125f1c032bb1aa52c0.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/92f86d7b1730aae074b2bcb3d1720b8724f9178c.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/8e13511e03e5d9092f96bc37266e43ed15114ae5.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/cdf4fd351e5be3f2291d22d5828ede96d1682310.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/2e0c956a091843f6e9336fd8e5b85481922cefb8.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/51a3651096e89eb398bbc743c2ae15cde07315e6.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/78e7f7ba7cfde327f9578385df49eb57fe08573d.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/1d701757cd68cc3317b575ce5ceaa2e015c8be6.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/a1701e5cc2f321799713d7975eed5600ac346cb3.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/5d88b59b63507849252f220d7c070736c309913e.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/23863ce233e258b24b5440b7ccb2742dabd47e3f.flag .generated_files/2b4b8ffe1cbd523a114041026badb7013261e432.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
