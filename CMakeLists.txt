cmake_minimum_required(VERSION 3.12)

set(MSVC_DYNAMIC_RUNTIME OFF CACHE BOOL "" FORCE)
mark_as_advanced(MSVC_DYNAMIC_RUNTIME)

add_subdirectory(libsoundtrackutil)
add_subdirectory(soundtrack)

if(BUILD_TESTING)
  add_subdirectory()
endif()
