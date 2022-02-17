cmake_minimum_required (VERSION 2.6)

project (Guerra)

set(CMAKE_CXX_STANDARD 17)

add_executable(Guerra ./src/Guerra.cpp
	./src/Common/Types.h  
	./src/Common/Command.h
	./src/Common/Paths.h
	./src/Controllers/DeckDesignController.h 
	./src/Controllers/DeckDesignController.cc
	./src/Controllers/TableController.h
	./src/Controllers/TableController.cc
	./src/JSON/JSONOperations.h 
	./src/JSON/JSONOperations.cc
	./src/Deck/DeckModel.h 
	./src/Deck/DeckModel.cc
	./src/Table/Table.h
	./src/Table/Table.cc
	./src/View/InterfaceOperations.h 
	./src/View/InterfaceOperations.cc
	./src/View/View.h
	./src/View/View.cc
	./src/View/LoopManagement.h
	./src/View/LoopManagement.cc
	./src/View/Commands/StartView/DeckDesignerStarter.h 	
	./src/View/Commands/StartView/DeckDesignerStarter.cc
	./src/View/Commands/StartView/GameStarter.h 	
	./src/View/Commands/StartView/GameStarter.cc
	./src/View/Commands/DeckView/CreateDeck.h 
	./src/View/Commands/DeckView/CreateDeck.cc
	./src/View/Commands/DeckView/EraseDeck.h 
	./src/View/Commands/DeckView/EraseDeck.cc
	./src/View/Commands/CommandFactory.h
	./src/View/Commands/CommandFactory.cc
	./src/View/Commands/GameView/NewGame.h
	./src/View/Commands/GameView/NewGame.cc
	./src/View/Commands/GameView/LoadGame.h
	./src/View/Commands/GameView/LoadGame.cc)
