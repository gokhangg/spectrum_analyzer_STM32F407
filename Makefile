
TARGET_NAME := SpectrumAnalyzer
ROOT_DIRECTORY=.

ALL_FOUND := $(subst ./,,$(shell find))

CSOURCES   := $(filter %.c,$(ALL_FOUND))
CPPSOURCES := $(filter %.cpp,$(ALL_FOUND))
ASMSOURCES := $(filter %.S,$(ALL_FOUND))

INCLUDE_DIRS := $(sort $(dir $(filter %.h %.hxx,$(ALL_FOUND))))

CD       := @cd
CP       := @cp
ECHO     := @echo
MKDIR    := @mkdir -p
RM       := @rm -rf

CC      := @arm-none-eabi-gcc
CCPP    := @arm-none-eabi-g++
LD      := @arm-none-eabi-g++
OBJCOPY := @arm-none-eabi-objcopy
OBJDUMP := @arm-none-eabi-objdump
SIZE    := @arm-none-eabi-size

ARC_FLAGS := -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
C_BUILD_FLAGS := $(ARC_FLAGS) -Wl,--gc-sections \
				-Wall -Wextra -fsigned-char -std=c11 \
				-MMD -fdata-sections -ffunction-sections
CPP_BUILD_FLAGS := $(ARC_FLAGS) -Wl,--gc-sections -Wall \
				-Wextra -fsigned-char -MMD \
				-fdata-sections -ffunction-sections \
				-std=c++20 -fabi-version=0 \
				-fno-exceptions -fno-rtti \
				-fno-use-cxa-atexit -fno-threadsafe-statics \
				-MMD

DEFINES := 	ARM_MATH_CM4 \
			USE_FULL_ASSERT \
			STM32F407VG \
			STM32F4XX \
			__FPU_USED \
			__FPU_PRESENT \

ifeq ($(MODE),debug)
	TARGET := Debug
	C_BUILD_FLAGS += -Og -g3
	CPP_BUILD_FLAGS += -Og -g3
	DEFINES += _DEBUG
else
	TARGET := Release
	C_BUILD_FLAGS += -Os
	CPP_BUILD_FLAGS += -Os
	DEFINES += NDEBUG
endif

LDFLAGS := $(ARC_FLAGS) \
           -Wl,--gc-sections \
           -Wl,--cref \
           -Xlinker -Map=$(TARGET)/$(TARGET_NAME).map \
           -specs=nano.specs -u _printf_float -specs=nosys.specs -nostartfiles  \
           -T 3rdParties/linker_script/STM32F4xx.ld


BIN_FILE  := $(TARGET_NAME).bin
ELF_FILE  := $(TARGET_NAME).elf

OBJECTS := $(patsubst %,$(TARGET)/%,$(patsubst %.c,%.o,$(CSOURCES)) $(patsubst %.cpp,%.o,$(CPPSOURCES)) $(patsubst %.S,%.o,$(ASMSOURCES)))
BUILD_DIR := $(sort $(dir $(OBJECTS)))

ELF := $(TARGET_NAME).elf

_INCLUDE_DIRS := $(patsubst %,-I%,$(subst ./,,$(INCLUDE_DIRS)))
_DEFINES      := $(patsubst %,-D%,$(DEFINES))

.PHONY : all clean

all: 
	$(MAKE) mkdir
	$(MAKE) build



build: $(OBJECTS)
	$(ECHO) 
	$(ECHO) Linking
	$(LD) $(LDFLAGS) $(OBJECTS) -Wl,--print-memory-usage -o $(TARGET)/$(ELF_FILE)
	$(ECHO) 
	$(ECHO) Binary generation
	$(OBJCOPY) -S -O binary $(TARGET)/$(ELF_FILE) $(TARGET)/$(BIN_FILE)

$(TARGET)/%.o: %.S
	$(ECHO) 
	$(ECHO) Compiling: $<
	$(CC) $(C_BUILD_FLAGS) -x assembler-with-cpp  $(_DEFINES) -c $< -o $@

$(TARGET)/%.o: %.c
	$(ECHO) 
	$(ECHO) Compiling: $<
	$(CC) $(C_BUILD_FLAGS) $(_INCLUDE_DIRS) $(_DEFINES) -c $< -o $@

$(TARGET)/%.o: %.cpp
	$(ECHO) 
	$(ECHO) Compiling: $<
	$(CCPP) $(CPP_BUILD_FLAGS) $(_INCLUDE_DIRS) $(_DEFINES) -c $< -o $@

mkdir:
	$(MKDIR) $(dir $(OBJECTS))

clean:
	$(RM) $(TARGET)

