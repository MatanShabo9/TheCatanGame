TheCatanGame 

A command-line based implementation of the popular board game Catan, written in C++.

-- Features --

Full object-oriented design using C++ classes

Supports players, resources, roads, settlements, and development cards

Turn-based gameplay with dice rolling and resource allocation

Clean separation between game logic and board representation

-- Technologies Used --

C++17 standard

STL containers and algorithms: vector, map, unordered_map, shuffle

Console-based interface (no GUI)

-- How to Run --

Open the solution in Visual Studio 2022 or later

Right-click the project name (not a .cpp file) → Properties

Under C/C++ → Language, set C++ Language Standard to /std:c++17

Exclude the test_catan.cpp file to avoid duplicate main() definitions

Press Ctrl + F5 to build and run the game

-- Folder Structure --

├── Board.cpp / .hpp
├── Corner.cpp / .hpp
├── DevelopmentCardDeck.cpp / .hpp
├── Edge.cpp / .hpp
├── HexTile.cpp / .hpp
├── Player.cpp / .hpp
├── ResourceType.cpp / .hpp
├── Main.cpp
├── test_catan.cpp (optional for testing)

-- Author --

The project was done by Matan Shabo.

-- Notes --

Useful for demonstrating object-oriented design and game logic handling.

-- License --

This project is intended for educational and portfolio purposes only.

Feel free to fork, explore, and suggest improvements!
