cmake_minimum_required (VERSION 2.8.11)
set(APP_NAME tcp)
project(${APP_NAME})

# add_executable (server server.c tcp.c)
# add_executable (client client.c tcp.c)

add_executable(tcp main.c tcp.c)