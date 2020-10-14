add_library(soundtrack-plugin SHARED)

target_sources(soundtrack-plugin PRIVATE
  src/SoundtrackSource.cpp
  src/SoundtrackPlugin.cpp
  include/Util.h
  include/LockFreeList.h
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(buildbits "64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(buildbits "32")
endif()

target_link_libraries(soundtrack-plugin PUBLIC
  Ws2_32.lib
  iphlpapi.lib
  psapi.lib
  userenv.lib
  ${CMAKE_CURRENT_BINARY_DIR}/../libsoundtrackutil/twitch-native-ipc/libuv/RelWithDebInfo/uv_a.lib
  ${CMAKE_CURRENT_BINARY_DIR}/../libsoundtrackutil/twitch-native-ipc/libnativeipc/RelWithDebInfo/nativeipc.lib
  ${CMAKE_CURRENT_BINARY_DIR}/../libsoundtrackutil/libsoundtrackutil/RelWithDebInfo/libsoundtrackutil.lib
  ${CMAKE_CURRENT_BINARY_DIR}/../obs/packed_build/bin/${buildbits}bit/obs.lib
  ${CMAKE_CURRENT_BINARY_DIR}/../obs/packed_build/bin/${buildbits}bit/w32-pthreads.lib
)

target_include_directories(soundtrack-plugin PUBLIC
  include
  ${CMAKE_CURRENT_BINARY_DIR}/../obs/packed_build/include/
  ${CMAKE_CURRENT_BINARY_DIR}/../deps/
  ${PROJECT_SOURCE_DIR}/libsoundtrackutil/libsoundtrackutil/include
  ${PROJECT_SOURCE_DIR}/libsoundtrackutil/GSL/include
  ${PROJECT_SOURCE_DIR}/libsoundtrackutil/twitch-native-ipc/libnativeipc/include
  ${PROJECT_SOURCE_DIR}/libsoundtrackutil/twitch-native-ipc/libuv/include
)

if(MSVC)
  target_compile_options(soundtrack-plugin PRIVATE /MT)
endif()

target_compile_features(soundtrack-plugin PRIVATE cxx_std_17)

set_target_properties(soundtrack-plugin PROPERTIES OUTPUT_NAME soundtrack-plugin-${buildbits})
