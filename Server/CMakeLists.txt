CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
project(server)


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

TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT}

-DBOOST_LOG_DYN_LINK -lboost_log_setup -lboost_log -lboost_thread -lpthread -lboost_system -lboost_filesystem

)
