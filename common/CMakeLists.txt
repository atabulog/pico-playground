file(GLOB_RECURSE COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_library(shared_memory STATIC
    ${COMMON_SOURCES}
)

message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("COMMON_SOURCES: ${COMMON_SOURCES}")
target_include_directories(shared_memory PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/data
    ${CMAKE_CURRENT_LIST_DIR}/memory_map
    ${CMAKE_CURRENT_LIST_DIR}/utils
)

target_link_libraries(shared_memory PUBLIC
    pico_stdlib
    pico_sync
)