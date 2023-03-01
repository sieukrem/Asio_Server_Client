cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(server)

#set(CMAKE_CXX_FLAGS "-lboost_program_options")

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Boost_USE_STATIC_LIBS        ON)  
set(Boost_USE_DEBUG_LIBS        OFF)  
set(Boost_USE_RELEASE_LIBS       ON)  
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

set(SOURCE 
          server.cpp
          tcp_connect.cpp
          tcp_server.cpp
          mathparser.cpp
          jsonparser.cpp
          include/tcp_connect.h
          include/tcp_server.h
          include/mathparser.h
          include/jsonparser.h
   )

find_package(Boost 1.75.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} ${SOURCE})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

