cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(bgfx bgfx)
set(bx bx)
set(bimg bimg)
set(astcodec astcodec)

add_library(${bx} STATIC ${CMAKE_SOURCE_DIR}/external/bx/src/amalgamated.cpp)
add_library(${bgfx} STATIC ${CMAKE_SOURCE_DIR}/external/bgfx/src/amalgamated.mm)
add_library(${bimg}
    STATIC
    ${CMAKE_SOURCE_DIR}/external/bimg/src/bimg_p.h
    ${CMAKE_SOURCE_DIR}/external/bimg/src/image.cpp
    ${CMAKE_SOURCE_DIR}/external/bimg/src/image_cubemap_filter.cpp
    ${CMAKE_SOURCE_DIR}/external/bimg/src/image_decode.cpp
    ${CMAKE_SOURCE_DIR}/external/bimg/src/image_encode.cpp
    ${CMAKE_SOURCE_DIR}/external/bimg/src/image_gnf.cpp
    )


add_library(${astcodec}
STATIC
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/astc_file.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/codec.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/endpoint_codec.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/footprint.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/integer_sequence_codec.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/intermediate_astc_block.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/logical_astc_block.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/partition.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/physical_astc_block.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/quantization.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/types.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/decoder/weight_infill.cc
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/bit_stream.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/bottom_n.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/math_utils.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/optional.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/string_utils.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/type_traits.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/uint128.h
${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/src/base/utils.h

)
target_include_directories(${astcodec}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec
    )



target_include_directories(${bx}
    PUBLIC
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/malloc
    ${CMAKE_SOURCE_DIR}/external/bx/include
    ${CMAKE_SOURCE_DIR}/external/bx/3rdparty
    )


target_include_directories(${bgfx}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
    ${CMAKE_SOURCE_DIR}/external/bgfx/3rdparty/khronos
    ${CMAKE_SOURCE_DIR}/external/bx/include
    ${CMAKE_SOURCE_DIR}/external/bimg/include
    )

target_include_directories(${bimg}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/external/bimg/include
    ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/
    ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/astc-codec/include
    ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/iqa/include
    ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/tinyexr
    ${CMAKE_SOURCE_DIR}/external/bimg/3rdparty/tinyexr/deps/miniz
    ${CMAKE_SOURCE_DIR}/external/bx/include
    )

target_link_libraries(${bimg} PUBLIC ${astcodec})


add_library(Rendering Renderer.hxx Renderer.cxx)
target_include_directories(Rendering
    PUBLIC
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
    ${CMAKE_SOURCE_DIR}/src/core
    )
    

find_library(METAL_LIB Metal)
find_library(COCOA_LIB Cocoa)
find_library(QUARTZ_LIB Quartz)


target_link_libraries(${bgfx} PUBLIC ${bx})
target_link_libraries(${bgfx} PUBLIC ${bimg})
target_link_libraries(${bgfx} PUBLIC ${METAL_LIB})
target_link_libraries(${bgfx} PUBLIC ${COCOA_LIB})
target_link_libraries(${bgfx} PUBLIC ${QUARTZ_LIB})

target_link_libraries(Rendering PUBLIC ${bgfx})
target_link_libraries(${bgfx} PUBLIC ${METAL_LIB})
