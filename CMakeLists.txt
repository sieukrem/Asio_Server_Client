
CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
project(ServerClient)

set(CMAKE_CXX_STANDARD 20)

SET(GCC_COVERAGE_COMPILE_FLAGS "-DBOOST_LOG_DYN_LINK -lboost_log_setup -lboost_log -lboost_thread -lpthread -lboost_system -lboost_filesystem")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(CPM_SOURCE_CACHE ${PROJECT_SOURCE_DIR}/.cache)
set(CPM_USE_NAMED_CACHE_DIRECTORIES ON)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(tests)