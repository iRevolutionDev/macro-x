cmake_minimum_required(VERSION 3.27)
project(MacroX LANGUAGES CXX)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

message("Fetching dependencies...")
include(scripts/sirius.cmake)

file(GLOB_RECURSE SRC_MAIN
        "${SRC_DIR}/**.hpp"
        "${SRC_DIR}/**.h"
        "${SRC_DIR}/**.cpp"
)

if (MSVC)
    add_compile_options(/bigobj)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else ()
    add_compile_options(-Wa,-mbig-obj)
endif ()

add_executable(MacroX ${SRC_MAIN})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

source_group(TREE ${SRC_DIR} PREFIX "src" FILES ${SRC_MAIN} )

target_include_directories(${PROJECT_NAME} PRIVATE
        "${SRC_DIR}"
        "${SIRIUS_INCLUDE_DIRS}"
)

target_precompile_headers(${PROJECT_NAME} PRIVATE "${SRC_DIR}/common.hpp")
target_link_libraries(${PROJECT_NAME} PRIVATE "${SIRIUS_LIBRARIES}")

set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_WARNING_AS_ERROR ON)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()