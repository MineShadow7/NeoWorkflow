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
    include_directories(${PROJECT_SOURCE_DIR}/submodule)
    set(wxBUILD_SHARED OFF)
    add_subdirectory(submodules/wxWidgets)
    add_executable(runmain src/Labworks.cpp src/Labworks.h src/cMain.h src/cMain.cpp)
    target_link_libraries(runmain wx::net wx::core wx::base)
endif(MSVC)
# Set property for c++
set_property(TARGET runmain PROPERTY CXX_STANDARD 20)

# Добавляем пути к исходным файлам
set(SOURCES
    src/libraries/lib_i_datastructure/data_structure.cpp
    src/libraries/lib_i_table/table.cpp
    src/libraries/lib_list/list.cpp
    src/libraries/lib_polynomial/polynomial.cpp
    src/libraries/lib_stack/stack.cpp
    src/libraries/lib_table_hash_list/hash_list.cpp
    src/libraries/lib_table_hash_vector/hash_vector.cpp
    src/libraries/lib_table_linear_array/linear_array.cpp
    src/libraries/lib_table_linear_list/linear_list.cpp
    src/libraries/lib_table_ordered_array/ordered_array.cpp
    src/libraries/lib_table_tree/tree.cpp
    # Другие исходные файлы .cpp
)

set(HEADERS
    src/libraries/lib_i_datastructure/data_structure.h
    src/libraries/lib_i_table/table.h
    src/libraries/lib_list/list.h
    src/libraries/lib_polynomial/polynomial.h
    src/libraries/lib_stack/stack.h
    src/libraries/lib_table_hash_list/hash_list.h
    src/libraries/lib_table_hash_vector/hash_vector.h
    src/libraries/lib_table_linear_array/linear_array.h
    src/libraries/lib_table_linear_list/linear_list.h
    src/libraries/lib_table_ordered_array/ordered_array.h
    src/libraries/lib_table_tree/tree.h
    # Другие исходные файлы .h
)

# Создаем директорию для собранных библиотек
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib_dynamic)

# Добавляем рекурсивную функцию для компиляции файлов .cpp
function(add_recursive_sources DIR)
    file(GLOB_RECURSE SOURCES_TMP "${DIR}/*.cpp")
    list(APPEND SOURCES ${SOURCES_TMP})
endfunction()

# Добавляем рекурсивную функцию для компиляции файлов .h
function(add_recursive_headers DIR)
    file(GLOB_RECURSE HEADERS_TMP "${DIR}/*.h")
    list(APPEND HEADERS ${HEADERS_TMP})
endfunction()

# Вызываем рекурсивные функции для добавления файлов .cpp и .h
add_recursive_sources(src/libraries)
add_recursive_headers(src/libraries)

# Создаем библиотеку с исходными файлами
add_library(dynamic_libs SHARED ${SOURCES} ${HEADERS})

# Указываем папки с заголовочными файлами
target_include_directories(dynamic_libs PUBLIC src)

# Указываем язык программирования для библиотек
set_target_properties(dynamic_libs  PROPERTIES LINKER_LANGUAGE CXX)
set_property(TARGET dynamic_libs PROPERTY CXX_STANDARD 20)

# Указываем путь к собранным библиотекам
set_target_properties(dynamic_libs PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

install(TARGETS runmain RUNTIME DESTINATION bin)
include(CPack)
