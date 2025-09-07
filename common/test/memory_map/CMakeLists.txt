# Memory Map Tests
set(memory_map_src_dir ${COMMON_SRC_DIR}/memory_map)
file(GLOB_RECURSE memory_map_srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(memory_map_ut
    shared_memory_ut.cpp
)

target_include_directories(memory_map_ut PRIVATE
    ${memory_map_src_dir}
)

target_sources(memory_map_ut PRIVATE
    ${memory_map_srcs}
)

target_link_libraries(memory_map_ut PRIVATE
    ${TEST_LIBS}    
    pico_stdlib
    pico_sync
)

add_test(NAME memory_map_ut COMMAND memory_map_ut)