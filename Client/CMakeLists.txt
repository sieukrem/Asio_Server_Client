cmake_minimum_required(VERSION 3.6 FATAL_ERROR)


set(Boost_USE_STATIC_LIBS        ON)  
set(Boost_USE_DEBUG_LIBS        OFF)  
set(Boost_USE_RELEASE_LIBS       ON)  
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)


find_package(Boost 1.66.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(client Client.cpp)
  target_link_libraries(client ${Boost_LIBRARIES})
endif()