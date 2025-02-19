cmake_minimum_required(VERSION 3.26)
project(ee C)

set(CMAKE_C_STANDARD 11)
set(DEFAULT_INSTALL_PREFIX "/usr/local")

if(WIN32)
    set(CMAKE_INSTALL_PREFIX "$ENV{APPDATA}/${PROJECT_NAME}")
else()
    set(CMAKE_INSTALL_PREFIX ${DEFAULT_INSTALL_PREFIX})
endif()

include_directories(include)

add_executable(
        ee
        src/buffer.c
        src/parser.c
        src/operator.c
        src/token.c
        src/result.c
        src/tensor.c
        src/main.c
)
target_link_libraries(ee m)

install(TARGETS ee DESTINATION bin)
