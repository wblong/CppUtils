cmake_minimum_required(VERSION 3.15)
# Project Propertise
project(CppUtils)

add_executable(CppUtils "")

set_target_properties(CppUtils PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_compile_definitions(
    CppUtils
    PRIVATE
        Main_DATA_DIR=\"${PROJECT_SOURCE_DIR}/test\"
)

function(glob_files out_var_name regexes)
    set(files "")
    foreach(arg ${ARGV})
        list(APPEND regexes_only "${arg}")
    endforeach()
    list(POP_FRONT regexes_only)
    if (GLOB_USE_CONFIGURE_DEPENDS)
        file(GLOB_RECURSE files CONFIGURE_DEPENDS ${regexes_only})
    else()
        file(GLOB files ${regexes_only})
    endif()
    set(${ARGV0} "${files}" PARENT_SCOPE)
endfunction()

glob_files(CppUtils_HEADERS include/utils/*.h)
glob_files(CppUtils_SOURCES test/*.cpp src/*.c)

target_sources(
    CppUtils
    PRIVATE
        ${CppUtils_SOURCES}
        ${CppUtils_HEADERS}
)

target_include_directories(
    CppUtils
    SYSTEM PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)