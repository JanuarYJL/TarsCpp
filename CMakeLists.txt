cmake_minimum_required(VERSION 3.2)

project(tars-cpp)

#-------------------------------------------------------------------

if("${TARS_CPP_COMMON}" STREQUAL "")

    set(TARS_CPP_COMMON "1")

    include("${PROJECT_SOURCE_DIR}/cmake/GenVersion.cmake")

    include("${PROJECT_SOURCE_DIR}/cmake/Common.cmake")

    include("${PROJECT_SOURCE_DIR}/cmake/BuildTarsCpp.cmake")

    include("${PROJECT_SOURCE_DIR}/cmake/Thirdparty.cmake")

    include("${PROJECT_SOURCE_DIR}/cmake/ParseAsm.cmake")

endif()

if(WIN32)
    # 设置静态使用MFC及MT MTd模式
    set(CMAKE_MFC_FLAG 1)    # It should be set to 1 for the static MFC library, and 2 for the shared MFC library.
    add_definitions(/Zi)    # /Zi 用来生成程序数据库格式的调试信息
    set(CMAKE_CXX_FLAGS_RELEASE "-MT -O2")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-MT -O2")
    set(CMAKE_CXX_FLAGS_DEBUG "-MTd -Od")
    set(CMAKE_GENERATOR_TOOLSET "v142")
    set(CMAKE_VS_PLATFORM_TOOLSET "v142")
endif(WIN32)
add_definitions(-DTARS_VERSION="${TARS_VERSION}")
message("TARS_VERSION:              ${TARS_VERSION}")

# if(WIN32)
# option(ENABLE_MT "option for /MT" ON)
# include(${PROJECT_SOURCE_DIR}/cmake/compiler_flags_overrides.cmake)
# message("ENABLE_MT:                 ${ENABLE_MT}")
# endif(WIN32)

set(CLEAR_INCLUDE "clear-install.cmake")
FILE(WRITE ${CLEAR_INCLUDE} "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_PREFIX}/include)\n")
install(SCRIPT ${CLEAR_INCLUDE})

#-------------------------------------------------------------------

include_directories(${PROJECT_SOURCE_DIR}/util/include)

include_directories(${PROJECT_SOURCE_DIR}/servant)
include_directories(${PROJECT_SOURCE_DIR}/servant/protocol)

IF(WIN32)
include_directories(${PROJECT_SOURCE_DIR}/util/src/epoll_windows)
ENDIF()

add_subdirectory(util)
add_subdirectory(tools)
add_subdirectory(servant)
add_subdirectory(mock)

IF (NOT ${ONLY_LIB})
add_subdirectory(examples)
add_subdirectory(unit-test)
ENDIF()


