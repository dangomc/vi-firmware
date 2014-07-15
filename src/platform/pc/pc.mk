GCC_BIN = /usr/bin/

OPENOCD_CONF_BASE = ../conf/openocd
INCLUDE_PATHS +=

CC = $(GCC_BIN)gcc
CPP = $(GCC_BIN)g++
AS_FLAGS = -c --defsym RAM_MODE=0

CC_FLAGS = -c 
ONLY_C_FLAGS += -std=gnu99
ONLY_CPP_FLAGS += -std=gnu++0x
CC_SYMBOLS += 

AS = $(GCC_BIN)as
LD = $(GCC_BIN)g++
LD_FLAGS = 
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lpthread

OBJCOPY = $(GCC_BIN)objcopy


C_SRCS = $(CROSSPLATFORM_C_SRCS) $(wildcard platform/pc/*.c)
LIB_C_SRCS +=
CPP_SRCS = $(CROSSPLATFORM_CPP_SRCS) $(wildcard platform/pc/*.cpp)
OBJ_FILES = $(C_SRCS:.c=.o) $(CPP_SRCS:.cpp=.o) $(LIB_C_SRCS:.c=.o)
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(OBJ_FILES))

TARGET_BIN = $(OBJDIR)/$(TARGET)

ifeq ($(DEBUG), 1)
CC_FLAGS += -g -ggdb
else
CC_FLAGS += -Os -Wno-uninitialized
endif


all: $(TARGET_BIN)

gdb: all
	@openocd -f $(OPENOCD_CONF_BASE)/gdb.cfg

.s.o:
	$(AS) $(AS_FLAGS) -o $@ $<

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(CC_SYMBOLS) $(ONLY_C_FLAGS) $(INCLUDE_PATHS) -o $@ $<

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CC_FLAGS) $(CC_SYMBOLS) $(ONLY_CPP_FLAGS) $(INCLUDE_PATHS) -o $@ $<

$(TARGET_BIN): $(OBJECTS)
	$(LD) $(LD_FLAGS) -o $@ $^ $(LD_SYS_LIBS)

clean::
	rm -rf $(OBJDIR_ROOT)/*
