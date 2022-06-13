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
FINAL_IMAGE=${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c AS.c ADC.c SUPERVISOR.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o ${OBJECTDIR}/AS.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/SUPERVISOR.o
POSSIBLE_DEPFILES=${OBJECTDIR}/CAN1Config.o.d ${OBJECTDIR}/CAN2Config.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/RTC.o.d ${OBJECTDIR}/GPS.o.d ${OBJECTDIR}/UART1.o.d ${OBJECTDIR}/UART2.o.d ${OBJECTDIR}/PARAMETERS.o.d ${OBJECTDIR}/SPI.o.d ${OBJECTDIR}/MESSAGES.o.d ${OBJECTDIR}/GPIO.o.d ${OBJECTDIR}/TIMER.o.d ${OBJECTDIR}/TELEMETRY.o.d ${OBJECTDIR}/STATEMACHINE.o.d ${OBJECTDIR}/TEMPORIZATIONS.o.d ${OBJECTDIR}/AS.o.d ${OBJECTDIR}/ADC.o.d ${OBJECTDIR}/SUPERVISOR.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/CAN1Config.o ${OBJECTDIR}/CAN2Config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/RTC.o ${OBJECTDIR}/GPS.o ${OBJECTDIR}/UART1.o ${OBJECTDIR}/UART2.o ${OBJECTDIR}/PARAMETERS.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/MESSAGES.o ${OBJECTDIR}/GPIO.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/TELEMETRY.o ${OBJECTDIR}/STATEMACHINE.o ${OBJECTDIR}/TEMPORIZATIONS.o ${OBJECTDIR}/AS.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/SUPERVISOR.o

# Source Files
SOURCEFILES=CAN1Config.c CAN2Config.c main.c RTC.c GPS.c UART1.c UART2.c PARAMETERS.c SPI.c MESSAGES.c GPIO.c TIMER.c TELEMETRY.c STATEMACHINE.c TEMPORIZATIONS.c AS.c ADC.c SUPERVISOR.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128GP706A
MP_LINKER_FILE_OPTION=,--script=p33FJ128GP706A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/2ee48a0de736b3c308158e87bbdd89a27881a59d .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/ef3d97361f5d913f41cfcddb105b3c8b2678497f .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/6154c5b9d606925eab7cf46480302f6221848328 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/56cee378f32ee3fa9ab4e6c17524976ab46b526b .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/f69421f15b40d32240e618fcdd61c3073cd466f4 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/bb8bdefaab38ff233ee4ff60f200aeaa80e1a7dd .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/8e5feeb4ac1bd4be9c7f970b452327fdd8c7ce37 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/8ea810be01be7868a70a65ad4c46ca4986e0380e .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/4656a92b024074439f650d308f9964036836515 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/98489db8248adb15def823b637d065c80a5042e4 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/9ac3f6d1590a6d6e6a435087d929992257407ad2 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/ac34c757c7a3d92c2bf82571b5cc41ac3c10362a .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/1170381b9006e00c3591bcd5d3d857a2d9f337ad .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/adba9d3dff9f96b70f49b108627c089d2392e19e .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/99b0050123fb269b5175c1d385290542fa4efb .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/flags/default/118ab8ec008f776c3ea699e574f965163cb709e5 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/61d403109ad11a41083628e5594cccbebbe5c80c .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC.c  -o ${OBJECTDIR}/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SUPERVISOR.o: SUPERVISOR.c  .generated_files/flags/default/ce82b05a95a2d90948484d0e199d53390d7593fd .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o.d 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SUPERVISOR.c  -o ${OBJECTDIR}/SUPERVISOR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SUPERVISOR.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/b2495039cdba31c11e05d1f2b8a9c1385dc04ffb .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/3727c46d06296d92b7f9db94f010843179de54e9 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a6991ae05f8bb37e3d8c85ae4320fdab4f3b1a53 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/f707cde714a7cb6709fc6c5a17fbb453c3a3c8a4 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/8f7d890c5710633a3e0d5e6dd543d4f1d37bce22 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/44486c6a4a1b8b0ed097f995a62ef5496a002531 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/19a0dc4d9fd817fc39b04d0e86fb4f805dc3ac6a .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/144c3be33d0741fbc35a9b5b54203ce95b37b5c5 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/137989460f926ef9ad970cc3cb0474a4daeb2fb7 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/c32af83402f1efcffe7deb6113b84824d023289d .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/2ce789666c384de7793862af8be132d746bcb7a7 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/4ddaa7eab8cddf9c034435404d767191cc0f2f50 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/ed1214128c5f9f2926c1cad544548d8a882756a9 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/eae4e16e0acd79b0c75671b4a26c505a69109f0a .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/a1ab8bf89bdb4c18734baa90e54db92154e306d2 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/flags/default/c9517f097df762ceaac4cbcd8714ab3e61fedcd6 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/b19a10f2d52f4dd39f663cdf4393e518d132d9db .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC.c  -o ${OBJECTDIR}/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SUPERVISOR.o: SUPERVISOR.c  .generated_files/flags/default/9c91ad47d4050e617367156f9529cb47420f25e4 .generated_files/flags/default/1329bc02737d408f61b9c22ee41a5658bc776961
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o.d 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SUPERVISOR.c  -o ${OBJECTDIR}/SUPERVISOR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SUPERVISOR.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
