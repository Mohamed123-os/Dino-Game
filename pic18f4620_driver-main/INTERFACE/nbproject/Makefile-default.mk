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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=ECU/7_SEGMENT/_7_segment.c ECU/DC_motor/dc_motor.c ECU/KEYPAD/keypad.c ECU/LCD/lcd.c ECU/LED/led.c ECU/RELAY/relay.c MCAL/GPIO/gpio.c MCAL/INTERRUPT/external_interrupt.c MCAL/INTERRUPT/internal_interrupt.c MCAL/INTERRUPT/interrupt_manager.c MCAL/device_config.c main.c MCAL/temp_timer1/timer1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU/LCD/lcd.p1 ${OBJECTDIR}/ECU/LED/led.p1 ${OBJECTDIR}/ECU/RELAY/relay.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d ${OBJECTDIR}/ECU/LCD/lcd.p1.d ${OBJECTDIR}/ECU/LED/led.p1.d ${OBJECTDIR}/ECU/RELAY/relay.p1.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d ${OBJECTDIR}/MCAL/device_config.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU/LCD/lcd.p1 ${OBJECTDIR}/ECU/LED/led.p1 ${OBJECTDIR}/ECU/RELAY/relay.p1 ${OBJECTDIR}/MCAL/GPIO/gpio.p1 ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1

# Source Files
SOURCEFILES=ECU/7_SEGMENT/_7_segment.c ECU/DC_motor/dc_motor.c ECU/KEYPAD/keypad.c ECU/LCD/lcd.c ECU/LED/led.c ECU/RELAY/relay.c MCAL/GPIO/gpio.c MCAL/INTERRUPT/external_interrupt.c MCAL/INTERRUPT/internal_interrupt.c MCAL/INTERRUPT/interrupt_manager.c MCAL/device_config.c main.c MCAL/temp_timer1/timer1.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1: ECU/7_SEGMENT/_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 ECU/7_SEGMENT/_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.d ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_motor/dc_motor.p1: ECU/DC_motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 ECU/DC_motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_motor/dc_motor.d ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEYPAD/keypad.p1: ECU/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 ECU/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU/KEYPAD/keypad.d ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/lcd.p1: ECU/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/lcd.p1 ECU/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/lcd.d ${OBJECTDIR}/ECU/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/led.p1: ECU/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/led.p1 ECU/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/led.d ${OBJECTDIR}/ECU/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/relay.p1: ECU/RELAY/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/relay.p1 ECU/RELAY/relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/relay.d ${OBJECTDIR}/ECU/RELAY/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1: MCAL/INTERRUPT/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 MCAL/INTERRUPT/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1: MCAL/INTERRUPT/internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 MCAL/INTERRUPT/internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1: MCAL/INTERRUPT/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 MCAL/INTERRUPT/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/temp_timer1/timer1.p1: MCAL/temp_timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/temp_timer1" 
	@${RM} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1 MCAL/temp_timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/temp_timer1/timer1.d ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1: ECU/7_SEGMENT/_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1 ECU/7_SEGMENT/_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.d ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_SEGMENT/_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_motor/dc_motor.p1: ECU/DC_motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1 ECU/DC_motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_motor/dc_motor.d ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEYPAD/keypad.p1: ECU/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEYPAD/keypad.p1 ECU/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU/KEYPAD/keypad.d ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/lcd.p1: ECU/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/lcd.p1 ECU/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/lcd.d ${OBJECTDIR}/ECU/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/led.p1: ECU/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/led.p1 ECU/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/led.d ${OBJECTDIR}/ECU/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/relay.p1: ECU/RELAY/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/relay.p1 ECU/RELAY/relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/relay.d ${OBJECTDIR}/ECU/RELAY/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/gpio.p1: MCAL/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/gpio.p1 MCAL/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/gpio.d ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1: MCAL/INTERRUPT/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1 MCAL/INTERRUPT/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1: MCAL/INTERRUPT/internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1 MCAL/INTERRUPT/internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.d ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1: MCAL/INTERRUPT/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1 MCAL/INTERRUPT/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/temp_timer1/timer1.p1: MCAL/temp_timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/temp_timer1" 
	@${RM} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1 MCAL/temp_timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/temp_timer1/timer1.d ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/temp_timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/INTERFACE.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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
