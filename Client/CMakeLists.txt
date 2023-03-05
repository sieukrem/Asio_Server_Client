CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
project(client)

ADD_EXECUTABLE(${PROJECT_NAME}
                              client.cpp
                              jsonparser.cpp
                              tcp_client.cpp
                              include/jsonparser.h
                              include/tcp_client.h)
                              
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  ${Boost_LOG_LIBRARY}
  ${CMAKE_THREAD_LIBS_INIT}
  -lpthread
  -DBOOST_LOG_DYN_LINK -lboost_log_setup -lboost_log -lboost_thread -lpthread -lboost_system -lboost_filesystem

)




