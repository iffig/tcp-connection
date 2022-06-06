cmake_minimum_required (VERSION 2.8.11)
set(APP_NAME tcp)
project(${APP_NAME})

add_executable (server server.c)
add_executable (client client.c)

