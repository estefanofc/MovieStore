cmake_minimum_required(VERSION 3.5)
project(moviestore)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

# need to load data files from current directory as cpp files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(moviestore.exe main.cpp store_test.cpp MovieStore.cpp MovieStore.h MovieFactory.cpp MovieFactory.h Comedy.cpp Comedy.h Classic.cpp Classic.h Command.cpp Command.h Customer.cpp Customer.h Movie.cpp Movie.h CommandFactory.cpp CommandFactory.h Drama.cpp Drama.h Borrow.cpp Borrow.h HashMap.cpp HashMap.h Inventory.cpp Inventory.h History.cpp History.h Return.cpp Return.h)