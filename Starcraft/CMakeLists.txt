cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(starcraft)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/Vector.h
        ${INC_DIR}/BattleField.h
        ${INC_DIR}/TerranShips.h
        ${INC_DIR}/ProtossShips.h
        ${INC_DIR}/input.h
        ${INC_DIR}/battleCruser.h
        ${INC_DIR}/carrier.h
        ${INC_DIR}/phoenix.h
        ${INC_DIR}/viking.h

        
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Vector.c
        ${SRC_DIR}/BattleField.c
        ${SRC_DIR}/TerranShips.c
        ${SRC_DIR}/ProtossShips.c
        ${SRC_DIR}/input.c
        ${SRC_DIR}/battleCruser.c
        ${SRC_DIR}/carrier.c
        ${SRC_DIR}/phoenix.c
        ${SRC_DIR}/viking.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
