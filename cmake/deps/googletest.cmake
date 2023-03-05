include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage(
    NAME googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG  v1.12.0
)

if(googletest_ADDED)
    message(STATUS "googletest was added")
else()
    message(FATAL_ERROR "Failed to add googletest")
endif()