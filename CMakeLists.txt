cmake_minimum_required(VERSION 3.12)

set(MSVC_DYNAMIC_RUNTIME OFF CACHE BOOL "" FORCE)
mark_as_advanced(MSVC_DYNAMIC_RUNTIME)

message(STATUS "Build libsoundtrackutil")
add_subdirectory(libsoundtrackutil)
message(STATUS "Build soundtrack")
add_subdirectory(soundtrack)

if(BUILD_TESTING)
  add_subdirectory()
endif()
