cmake_minimum_required(VERSION 3.16.3)
project(coordenadas_campo)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

SET(INCLUDE "include/")
SET(SRC "src/")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

FILE(GLOB SRC_CODE ${SRC}/*.cpp)




add_executable(main ${SRC_CODE})
target_compile_definitions(main PUBLIC PROJECT_ROOT="${CMAKE_HOME_DIRECTORY}")
target_link_libraries(main ${wxWidgets_LIBRARIES})
target_include_directories(main PUBLIC ${INCLUDE})
