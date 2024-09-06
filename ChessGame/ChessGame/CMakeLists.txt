cmake_minimum_required(VERSION 3.26)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessGame main.cpp
        GamePiecesLogic.cpp
        PawnLogic.cpp
        GamePiecesLogic.h
        PawnLogic.h
        MainBoard.h
        MainBoard.h
        MainBoard.cpp
        KnightLogic.h
        KnightLogic.cpp
        KingLogic.h
        KingLogic.h
        KingLogic.cpp
        RookLogic.cpp
        RookLogic.h
        BishopLogic.h
        BishopLogic.cpp
        QueenLogic.h
        QueenLogic.cpp)
