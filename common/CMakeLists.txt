#set variables used for library build
file(GLOB_RECURSE COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(COMMON_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

# create common library
add_library(common STATIC
    ${COMMON_SOURCES}
)

target_include_directories(common PUBLIC
    ${COMMON_SRC_DIR}
    ${COMMON_SRC_DIR}/data
    ${COMMON_SRC_DIR}/memory_map
    ${COMMON_SRC_DIR}/utils
)

target_link_libraries(common PUBLIC
    pico_stdlib
    pico_sync
)

