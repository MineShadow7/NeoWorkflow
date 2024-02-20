cmake_minimum_required(VERSION 3.12)

include(cmake/configure.cmake)

project(ProjectCpp)

# Main executable for UNIX programm.
if(UNIX)
    add_executable(runmain src/Labworks.cpp src/Labworks.h src/cMain.h src/cMain.cpp)
    include_directories(${PROJECT_SOURCE_DIR}/submodule)
    add_subdirectory(submodules/wxWidgets)
    set(wxBUILD_SHARED OFF)
    target_link_libraries(runmain wx::net wx::core wx::base)
endif(UNIX)

# Main executable for Windows programm.
if(MSVC)
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
     if(wxWidgets_USE_FILE) # not defined in CONFIG mode
        include(${wxWidgets_USE_FILE})
     endif(wxWidgets_USE_FILE)
    add_executable(runmain src/Labworks.cpp src/cMain.h src/cMain.cpp)
    target_link_libraries(runmain ${wxWidgets_LIBRARIES})
endif(MSVC)
# Set property for c++
set_property(TARGET runmain PROPERTY CXX_STANDARD 20)

# Add main libraries for programm.
add_library(i_datastructure src/libraries/lib_i_datastructure/data_structure.cpp src/libraries/lib_i_datastructure/data_structure.h)
add_library(i_table src/libraries/lib_i_table/table.cpp src/libraries/lib_i_table/table.h)
add_library(list src/libraries/lib_list/list.cpp src/libraries/lib_list/list.h)
add_library(polynomial src/libraries/lib_polynomial/polynomial.cpp src/libraries/lib_polynomial/polynomial.h)
add_library(stack src/libraries/lib_stack/stack.cpp src/libraries/lib_stack/stack.h)
add_library(table_hash_list src/libraries/lib_table_hash_list/hash_list.cpp src/libraries/lib_table_hash_list/hash_list.h)
add_library(table_hash_vector src/libraries/lib_table_hash_vector/hash_vector.cpp src/libraries/lib_table_hash_vector/hash_vector.h)
add_library(table_linear_array src/libraries/lib_table_linear_array/linear_array.cpp src/libraries/lib_table_linear_array/linear_array.h)
add_library(table_linear_list src/libraries/lib_table_linear_list/linear_list.cpp src/libraries/lib_table_linear_list/linear_list.h)
add_library(table_ordered_array src/libraries/lib_table_ordered_array/ordered_array.cpp src/libraries/lib_table_ordered_array/ordered_array.h)
add_library(table_tree src/libraries/lib_table_tree/tree.cpp src/libraries/lib_table_tree/tree.h)
