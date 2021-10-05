set(Input
Input.swift
)



add_library(Input SHARED ${Input})
set_target_properties(Input PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_Swift_MODULE_DIRECTORY}
  INTERFACE_LINK_DIRECTORIES $<TARGET_LINKER_FILE_DIR:Input>)
