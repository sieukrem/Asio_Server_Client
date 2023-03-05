#add_subdirectory(common)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/deps/googletest.cmake)
include(GoogleTest)

file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE UNDERTEST_SERVER_FILES CONFIGURE_DEPENDS ../Server/jsonparser.cpp ../Server/mathparser.cpp)

get_filename_component(target_name ${CMAKE_CURRENT_LIST_DIR} NAME)

add_executable(${target_name} 
  ${TEST_FILES}
  ${UNDERTEST_SERVER_FILES}
)

target_compile_options(${target_name}
  PRIVATE -Wall -Wextra -Wpedantic
)

target_link_libraries(${target_name}
  ${Boost_LOG_LIBRARY}
  -DBOOST_LOG_DYN_LINK -lboost_log_setup -lboost_log -lboost_filesystem
  gtest_main
  GTest::gmock
)
