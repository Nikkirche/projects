cmake_minimum_required(VERSION 3.7)

project("LLVM Frontend")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be at least 17
set(CMAKE_CXX_STANDARD 17)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})
include_directories('antlr4-runtime')
include_directories('/build/antlr4_runtime/src/antlr4_runtime/runtime/Cpp/runtime/src ')

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/tools/antlr-4.13.0-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)
find_package(SDL2 REQUIRED)

find_package(LLVM  REQUIRED CONFIG PATHS /usr/lib/llvm14/lib/cmake/llvm/)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(LanguageGrammarParser Language.g4 VISITOR OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/)

# add our project source directories
include_directories(${PROJECT_SOURCE_DIR}
					 ${PROJECT_SOURCE_DIR}/libs/
  )

find_package (SFML 2.6 COMPONENTS graphics  REQUIRED)

add_executable(llvm-frontend antlr.cpp sim.cpp #LLVMVisitor.cpp
               ${ANTLR_LanguageGrammarParser_CXX_OUTPUTS})

# link required libraries
target_link_libraries(llvm-frontend antlr4_static ${SYSTEM_LIBS} LLVM SDL2 sfml-graphics sfml-system )

# copy the input file next to the generated executable
add_custom_command(TARGET llvm-frontend POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/main.prog"
  $<TARGET_FILE_DIR:llvm-frontend>)


