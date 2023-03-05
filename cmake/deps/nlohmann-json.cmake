include(${CMAKE_CURRENT_LIST_DIR}/../CPM.cmake)

CPMAddPackage(
    NAME nlohmann_json
    GIT_REPOSITORY git@code.siemens.com:mirror/json.git
    GIT_TAG v3.10.4
    OPTIONS
      "JSON_BuildTests OFF"
)

if(nlohmann_json_ADDED)
    message(STATUS "nlohmann_json was added")
    set(nlohmann_json_DIR ${CMAKE_CURRENT_LIST_DIR})
else()
    message(FATAL_ERROR "Failed to add nlohmann_json")
endif()
