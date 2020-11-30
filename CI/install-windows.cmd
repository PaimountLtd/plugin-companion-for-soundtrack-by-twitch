mkdir build && mkdir dist
cd build

set OBS_VERSION=26.0.6
set OBS_PACKAGED=libobs-windows64-release-%OBS_VERSION%
set W32_PTHREADS=w32-pthreads-%OBS_VERSION%
set W32_PTHREADS_URL=https://s3-us-west-2.amazonaws.com/obsstudios3.streamlabs.com/%W32_PTHREADS%.7z
set OBS_URL=https://s3-us-west-2.amazonaws.com/obsstudios3.streamlabs.com/%OBS_PACKAGED%.7z

if exist %OBS_PACKAGED%.7z (curl -kLO %OBS_URL% -f --retry 5 -z %OBS_URL%.zip) else (curl -kLO %OBS_URL% -f --retry 5 -C -)
if exist %W32_PTHREADS%.7z (curl -kLO %W32_PTHREADS_URL% -f --retry 5 -z %W32_PTHREADS_URL%.zip) else (curl -kLO %W32_PTHREADS_URL% -f --retry 5 -C -)

7z x %OBS_PACKAGED%.7z -oobs
7z x %W32_PTHREADS%.7z -oobs/packed_build/deps

cmake -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE="RelWithDebInfo" ..

cd ..
cmake --build build --config RelWithDebInfo