# ASSEMBLER/CMakeLists.txt

# Define the assembler library
add_library(assembler
    src/assemble.cpp
)

# Include directories for the assembler library
target_include_directories(assembler PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
