add_library(Engine CyaniteEngine.hxx CyaniteEngine.cxx)

add_subdirectory(Rendering)
target_include_directories(Engine PUBLIC src/core/engine)
target_include_directories(Engine PUBLIC src/core)
target_link_libraries(Engine PUBLIC Rendering)
