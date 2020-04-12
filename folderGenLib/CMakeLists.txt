cmake_minimum_required(VERSION 3.10)

#Replace PROJECT_NAME with project name, and _SOURCES, with sources
set(PROJECT_NAME folderGen)
project(${PROJECT_NAME})
add_library(${PROJECT_NAME} src/genFolders.cpp)

#setup includes for include directory
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#add boost to project
if(NOT Boost_DIR)
    message(FATAL_ERROR "No Boost_DIR provided")
endif()
message("-- Boost location: " ${Boost_DIR})
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS filesystem REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC Boost::filesystem)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::filesystem)

#add test
add_subdirectory(./test)


#This is for the YCM settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
  EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different  ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
ENDIF()
