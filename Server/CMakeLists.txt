CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
project(server)
#FIND_PACKAGE(Boost 1.75 COMPONENTS log REQUIRED)
#FIND_PACKAGE(Threads)
#INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ADD_EXECUTABLE(${PROJECT_NAME} server.cpp 
                      include/jsonparser.h 
                      include/mathparser.h 
                      include/tcp_connect.h 
                      include/tcp_server.h
                      include/logging.h                                          
                      jsonparser.cpp
                      mathparser.cpp
                      tcp_connect.cpp
                      tcp_server.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
