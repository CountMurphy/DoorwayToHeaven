INCLUDE(CMakeForceCompiler)

# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

# DEBUG LINK FILE
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -T KSDK_1.2.0/platform/devices/MKL27Z4/linker/gcc/MKL27Z256xxx4_flash.ld  -static")

# RELEASE LINK FILE
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -T KSDK_1.2.0/platform/devices/MKL27Z4/linker/gcc/MKL27Z256xxx4_flash.ld  -static")

# DEBUG ASM FLAGS
SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g  -mcpu=cortex-m0plus  -mthumb  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99")

# DEBUG C FLAGS
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g  -mcpu=cortex-m0plus  -mthumb  -MMD  -MP  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99")

# DEBUG LD FLAGS
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g  --specs=nano.specs  -lm  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mthumb  -mapcs  -Xlinker --gc-sections  -Xlinker -static  -Xlinker -z  -Xlinker muldefs  -Xlinker --defsym=__stack_size__=0x300  -Xlinker --defsym=__heap_size__=0x200 -u _printf_float")

# RELEASE ASM FLAGS
SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mcpu=cortex-m0plus  -mthumb  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99")

# RELEASE C FLAGS
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mcpu=cortex-m0plus  -mthumb  -MMD  -MP  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mapcs  -std=gnu99")

# RELEASE LD FLAGS
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nano.specs  -lm  -Wall  -fno-common  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -Os  -mthumb  -mapcs  -Xlinker --gc-sections  -Xlinker -static  -Xlinker -z  -Xlinker muldefs  -Xlinker --defsym=__stack_size__=0x300  -Xlinker --defsym=__heap_size__=0x200 -u _printf_float")

# ASM MACRO
SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG}  -DDEBUG")

# C MACRO
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}  -DDEBUG")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}  -DCPU_MKL27Z256VLH4")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}  -DFRDM_KL27Z")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}  -DFREEDOM")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}  -DNDEBUG")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}  -DCPU_MKL27Z256VLH4")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}  -DFRDM_KL27Z")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}  -DFREEDOM")

# CXX MACRO

# INCLUDE_DIRECTORIES
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/osa/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/utilities/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/CMSIS/Include)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/include)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/startup)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/hal/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/drivers/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/system/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/utilities/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/.)
ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/osa/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/utilities/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/CMSIS/Include)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/include)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/startup)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/hal/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/drivers/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/system/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/KSDK_1.2.0/platform/utilities/inc)
    INCLUDE_DIRECTORIES(${ProjDirPath}/.)
ENDIF()

# ADD_EXECUTABLE
ADD_EXECUTABLE(Stargate 
    "${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/startup/gcc/startup_MKL27Z4.S"
    "${ProjDirPath}/KSDK_1.2.0/platform/devices/MKL27Z4/startup/system_MKL27Z4.c"
    "${ProjDirPath}/KSDK_1.2.0/platform/devices/startup.c"
    "${ProjDirPath}/KSDK_1.2.0/platform/devices/startup.h"
    "${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/dma/fsl_dma_irq.c"
    "${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/lptmr/fsl_lptmr_irq.c"
    #"${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/uart/fsl_uart_irq.c"
    "${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/gpio/fsl_gpio_irq.c"
    "${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/spi/fsl_spi_irq.c"
    #"${ProjDirPath}/KSDK_1.2.0/platform/drivers/src/i2c/fsl_i2c_irq.c"
    "${ProjDirPath}/main.c"
    "${ProjDirPath}/pins.c"
    "${ProjDirPath}/ring.c"
)
SET_TARGET_PROPERTIES(Stargate PROPERTIES OUTPUT_NAME "Stargate.elf")

TARGET_LINK_LIBRARIES(Stargate -Wl,--start-group)
# LIBRARIES
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    TARGET_LINK_LIBRARIES(Stargate ${ProjDirPath}/KSDK_1.2.0/lib/ksdk_platform_lib/armgcc/KL27Z4/debug/libksdk_platform.a)
ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
    TARGET_LINK_LIBRARIES(Stargate ${ProjDirPath}/KSDK_1.2.0/lib/ksdk_platform_lib/armgcc/KL27Z4/release/libksdk_platform.a)
ENDIF()

# SYSTEM LIBRARIES
TARGET_LINK_LIBRARIES(Stargate m)
TARGET_LINK_LIBRARIES(Stargate c)
TARGET_LINK_LIBRARIES(Stargate gcc)
TARGET_LINK_LIBRARIES(Stargate nosys)
TARGET_LINK_LIBRARIES(Stargate -Wl,--end-group)

# MAP FILE
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG}  -Xlinker -Map=debug/Stargate.map")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}  -Xlinker -Map=release/Stargate.map")

# BIN AND HEX
ADD_CUSTOM_COMMAND(TARGET Stargate POST_BUILD COMMAND ${CMAKE_OBJCOPY} -Oihex ${EXECUTABLE_OUTPUT_PATH}/Stargate.elf ${EXECUTABLE_OUTPUT_PATH}/Stargate.hex)
ADD_CUSTOM_COMMAND(TARGET Stargate POST_BUILD COMMAND ${CMAKE_OBJCOPY} -Obinary ${EXECUTABLE_OUTPUT_PATH}/Stargate.elf ${EXECUTABLE_OUTPUT_PATH}/Stargate.bin)
