cmake_minimum_required(VERSION 3.9)
project(lem_in)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

file(GLOB INC_LIB ./libft/includes/*.h)
file(GLOB INC_PROJ ./includes/*.h)
file(GLOB C_SRC *.c)
file(GLOB SOURCES_LIBC ./libft/srcs/*.c)
set(INC ${INC_LIB} ${INC_PROJ})
set(LIBFT ${SOURCES_LIBC} ${SOURCES_PRINTF})

include_directories("./libft/includes" "./includes")
add_executable(lem_in ${INC} ${LIBFT} ${C_SRC})
