cmake_minimum_required(VERSION 3.17)
enable_testing()

set(CMAKE_C_STANDARD 99)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(isDebug TRUE)
else()
  set(isDebug FALSE)
endif()

if(isDebug)
  message("Debug build detected")
  add_compile_definitions(CONFIGURATION_DEBUG TYRAN_CONFIGURATION_DEBUG)
  set(CONFIGURATION_DEBUG 1)
endif()

add_executable(room_serialize_test main.c test.c)

add_test(NAME room_serialize_test COMMAND room_serialize_test)

if(WIN32)
  target_link_libraries(room_serialize_test conclave-room-serialize )
else()
  target_link_libraries(room_serialize_test conclave-room-serialize  m)
endif(WIN32)
