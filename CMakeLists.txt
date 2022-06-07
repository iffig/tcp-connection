cmake_minimum_required (VERSION 2.8.11)
set(APP_NAME tcp)
project(${APP_NAME})

add_executable(${APP_NAME} main.c ${APP_NAME}.c)