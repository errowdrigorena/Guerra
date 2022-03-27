add_subdirectory(Commands)

target_sources(Src PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/View.cc"
	"${CMAKE_CURRENT_SOURCE_DIR}/LoopManagement.cc"
	"${CMAKE_CURRENT_SOURCE_DIR}/InterfaceOperations.cc")