add_subdirectory(DeckView)
add_subdirectory(GameView)
add_subdirectory(StartView)

target_sources(Src PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/CommandFactory.cc")