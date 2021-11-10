cmake_minimum_required(VERSION 3.14)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
endif()
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /await")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /await")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Cyanite)
set(CMAKE_SUPPRESS_REGENERATION true)
set(CYANITE Cyanite)
set(NAME "Cyanite Game Engine")
set(Version 0.0.1a)
set(INFO "A cross platform game engine")
set(ID "dev.broken-bytes.cyanite.engine")
set(COPY "© 2021 - Broken Bytes")

set(SRC src/core/Main.hxx)


if(APPLE)
add_executable(${CYANITE} ${SRC})

set(SRC_OSX src/core/osx/Main.mm)
target_sources(${CYANITE}  PUBLIC ${SRC_OSX})
find_library(COCOA_LIBRARY Cocoa)
set_target_properties(
    ${CYANITE}
    PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST
    resources/plist.in
)
set(MACOSX_BUNDLE_BUNDLE_VERSION ${VERSION})
set(MACOSX_BUNDLE_COPYRIGHT $COPY)
set(MACOSX_BUNDLE_INFO_STRING ${INFO})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${ID})
endif()

if(WIN32)
add_executable(${CYANITE} WIN32 ${SRC})

set(SRC_WIN src/core/Main.cxx)
target_sources(${CYANITE} PUBLIC ${SRC_WIN})
endif()


target_compile_definitions(${CYANITE} PUBLIC -Dawait)
target_include_directories(${CYANITE} PUBLIC src)
target_include_directories(${CYANITE} PUBLIC external/sdl/include)
target_include_directories(${CYANITE} PUBLIC src/engine/)
target_include_directories(${CYANITE} PUBLIC src/engine/Events)

add_subdirectory(external/sdl)
add_subdirectory(src/engine)
target_link_libraries(${CYANITE} PUBLIC SDL2)
target_link_libraries(${CYANITE} PUBLIC SDL2main)


