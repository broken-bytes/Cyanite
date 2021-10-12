set(Engine
Engine.swift
Logger.swift
)



add_library(Engine SHARED ${Engine})
target_link_directories(Engine PUBLIC bin)
set_target_properties(Engine PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_Swift_MODULE_DIRECTORY}
  INTERFACE_LINK_DIRECTORIES $<TARGET_LINKER_FILE_DIR:Engine>)
target_link_libraries(Engine PUBLIC User32 Ole32 ComCtl32)
