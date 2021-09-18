cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Cyanite)
set(CMAKE_SUPPRESS_REGENERATION true)
set(CYANITE Cyanite)
set(NAME "Cyanite Game Engine")
set(Version 0.0.1a)
set(INFO "A cross platform game engine")
set(ID "dev.broken-bytes.cyanite.engine")
set(COPY "© 2021 - Broken Bytes")

set(SRC src/core/Globals.hxx src/core/Main.hxx src/core/Entry.hxx)

if(APPLE)
set(SRC_OSX src/core/osx/Main.mm)

add_executable(${CYANITE} MACOSX_BUNDLE ${SRC} ${SRC_OSX})
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

add_subdirectory(src/engine)
add_subdirectory(src/editor)

target_link_libraries(${CYANITE} PUBLIC Engine)
target_include_directories(${CYANITE} PUBLIC src/engine)


