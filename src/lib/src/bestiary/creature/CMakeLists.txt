add_subdirectory(capabilities)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/creature.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/creaturegenerator.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/creatureinstance.cpp
   PARENT_SCOPE
)