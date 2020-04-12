cmake_minimum_required(VERSION 3.10)

#Replace PROJECT_NAME with project name, and _SOURCES, with sources
set(PROJECT_NAME test_folderGenLib)
add_executable(${PROJECT_NAME} src/test.cpp)

#add boost to project
if(NOT Boost_DIR)
    message(FATAL_ERROR "No Boost_DIR provided")
endif()
message("-- Boost location: " ${Boost_DIR})
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC Boost::unit_test_framework folderGen)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::unit_test_framework folderGen)


#This is for the YCM settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
  EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different  ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
ENDIF()
