cmake_minimum_required(VERSION 3.10)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем файлы: заголовочный, реализация и main
add_executable(Lab2_Executable 
    main.cpp 
    tasks.cpp 
    tasks.h
)

# Поддержка UTF-8 для корректного вывода кириллицы в Windows
if(MSVC)
    add_compile_options(/utf-8)
endif()
