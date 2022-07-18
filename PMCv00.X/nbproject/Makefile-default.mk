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
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/3104bf12dfa9b03a4e730c000891461c3593c0d3 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/267531319c0881f75061796a86a69ea2845c05ab .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/1a1cd7015f8378f65957b7d408655f5fd5325bf7 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/fc7926ebded8d2f27ddd633ab21e4366854e8345 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/4aa750b45777e73f1e14216475a9c8d0e396e82 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/db972a5ac028401ff1d49087d32c300fa3101da7 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/b44d3f4ba46387d7d4d7b9254cc00074dbce0be7 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/a3fa4fba7e8499bda873d7cb2e43a56d1f96a45a .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/f059984ce8c08b11612deb3968d0fd8a2a244bb9 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/f1d480b55c6f384c986fba122a1f567be9f42c21 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/9056c442193ffe9f2dfae3759e93e7f5fc2a27ff .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/7626ec6f4a6d06d6b53e8de0654f7411522528e4 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/227257b35ec8c8aa2af9f724898f7e4cb291e898 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/7f53c5ed2339ba8ce38f9da6f8dcc4940895b0d8 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/196a9f34cf165e6932132ab74c4b627bc7c6b118 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/flags/default/8b4d0875e9ff242b7ed9c2c0fa0ce122b99ea29d .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/766d6325f19edd8009b83cdad2ddcd5cd930d37 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC.c  -o ${OBJECTDIR}/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/SUPERVISOR.o: SUPERVISOR.c  .generated_files/flags/default/fbfc4bcd5f6e44e5ff2bb3c47cc954d9ea1cfb3b .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o.d 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SUPERVISOR.c  -o ${OBJECTDIR}/SUPERVISOR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SUPERVISOR.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/CAN1Config.o: CAN1Config.c  .generated_files/flags/default/a175e1cf660ae6f5c936c0366599f33562c223f3 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN1Config.o.d 
	@${RM} ${OBJECTDIR}/CAN1Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN1Config.c  -o ${OBJECTDIR}/CAN1Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN1Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/CAN2Config.o: CAN2Config.c  .generated_files/flags/default/4d7fa643f7d782b96900433aae8690393d1ba40c .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CAN2Config.o.d 
	@${RM} ${OBJECTDIR}/CAN2Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CAN2Config.c  -o ${OBJECTDIR}/CAN2Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/CAN2Config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/6ddfe7bd2d09af7c7b8891e2e91abac3e06b8cf5 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/RTC.o: RTC.c  .generated_files/flags/default/79f6770754c860cae1aa469a2d3a05e7d0aebfc6 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC.o.d 
	@${RM} ${OBJECTDIR}/RTC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RTC.c  -o ${OBJECTDIR}/RTC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/RTC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/GPS.o: GPS.c  .generated_files/flags/default/88dc58c9db389994a68b306e4a743e8b52ddf8c .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPS.o.d 
	@${RM} ${OBJECTDIR}/GPS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPS.c  -o ${OBJECTDIR}/GPS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/UART1.o: UART1.c  .generated_files/flags/default/5f06f149601fefd7a7236c5564a5cb05abde7bde .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART1.o.d 
	@${RM} ${OBJECTDIR}/UART1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART1.c  -o ${OBJECTDIR}/UART1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/UART2.o: UART2.c  .generated_files/flags/default/b81c2e085dcffcd4a5e578fbd185d9c1272f9e1e .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART2.o.d 
	@${RM} ${OBJECTDIR}/UART2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART2.c  -o ${OBJECTDIR}/UART2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/PARAMETERS.o: PARAMETERS.c  .generated_files/flags/default/afcfa58acd19900e27710664b048ad244c57a060 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PARAMETERS.o.d 
	@${RM} ${OBJECTDIR}/PARAMETERS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PARAMETERS.c  -o ${OBJECTDIR}/PARAMETERS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PARAMETERS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/default/9824a4fe946ec2f684d42e19c7d58817960f1980 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SPI.c  -o ${OBJECTDIR}/SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SPI.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/MESSAGES.o: MESSAGES.c  .generated_files/flags/default/ca9e2306214d4111ef07c2664906d6e24aa59a5e .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MESSAGES.o.d 
	@${RM} ${OBJECTDIR}/MESSAGES.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MESSAGES.c  -o ${OBJECTDIR}/MESSAGES.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MESSAGES.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/GPIO.o: GPIO.c  .generated_files/flags/default/31a37bafad43f8b5458f4e7031922611ae576f55 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GPIO.o.d 
	@${RM} ${OBJECTDIR}/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  GPIO.c  -o ${OBJECTDIR}/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/4e4765f723fd2ffaae1d7298dfb58fa43c810b14 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER.c  -o ${OBJECTDIR}/TIMER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TELEMETRY.o: TELEMETRY.c  .generated_files/flags/default/fb94f76d21937ca2ccf7a5c2903707f058f1e0d8 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TELEMETRY.o.d 
	@${RM} ${OBJECTDIR}/TELEMETRY.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TELEMETRY.c  -o ${OBJECTDIR}/TELEMETRY.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TELEMETRY.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/STATEMACHINE.o: STATEMACHINE.c  .generated_files/flags/default/6601d14a59d224edf53a0ac2281eb3ea2c1d17e0 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o.d 
	@${RM} ${OBJECTDIR}/STATEMACHINE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  STATEMACHINE.c  -o ${OBJECTDIR}/STATEMACHINE.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/STATEMACHINE.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/TEMPORIZATIONS.o: TEMPORIZATIONS.c  .generated_files/flags/default/7f984b2fc74f319112876bd8a215f586468a94c2 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o.d 
	@${RM} ${OBJECTDIR}/TEMPORIZATIONS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TEMPORIZATIONS.c  -o ${OBJECTDIR}/TEMPORIZATIONS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TEMPORIZATIONS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/AS.o: AS.c  .generated_files/flags/default/b01496958c786e71ebf1e24d4bd689e7abc05421 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AS.o.d 
	@${RM} ${OBJECTDIR}/AS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  AS.c  -o ${OBJECTDIR}/AS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/AS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/3403de4b08c9f38f85af247561dcb300fc3be01e .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC.c  -o ${OBJECTDIR}/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/SUPERVISOR.o: SUPERVISOR.c  .generated_files/flags/default/9b9ca6ed9cb7cd25a5a62327215c9963294b6397 .generated_files/flags/default/6899304bb6b8543f7f4e61595f26e06fe388dcb6
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o.d 
	@${RM} ${OBJECTDIR}/SUPERVISOR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SUPERVISOR.c  -o ${OBJECTDIR}/SUPERVISOR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SUPERVISOR.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/PMCv00.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
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
