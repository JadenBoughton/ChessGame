#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ChessGame.h"
#include "Human.h" // Add this include for the Human class
#include "Computer.h" // Add this include for the Computer class
using namespace std;


void ChessGame::main()
{
    // This is the main function for the ChessGame class
    // You can implement the game logic here, such as initializing the board,
    // handling player input, and managing the game state.

    //Player setup
    if (!setup()) {
        cout << "Exiting..." << endl;
        return;
    }

    // Example of how to set up pieces (you would need to implement this)
    // board->initializeBoard();
    
    // Start the game loop
    int currentPlayerIndex = 0; // Start with the white player
    cout << "Game started! White player goes first." << endl;
    while (true) {
        // Get player input for moves
        int* move = player[currentPlayerIndex]->getMove();
        if (move == nullptr) {
            cout << "Invalid move. Please try again." << endl;
            continue; // Skip to the next iteration if the move is invalid
        }

        if(move == 0000) {
            cout << "Exiting the game." << endl;
            break; // Exit the game if the player inputs 0000
        }

        //ChessBoard* board = ChessBoard::getInstance();
        chessBoard->updateBoard(move);
        cout << "Player " << (currentPlayerIndex == 0 ? "White" : "Black") << " made a move." << endl;
        currentPlayerIndex = (currentPlayerIndex + 1) % 2; // Switch players
        // Process the move (you would need to implement this)
        // board->updateBoard(move);
        
        // Check for game over conditions, checkmate, etc.
        // if (gameOver) break;
    }

    cout << "Game over!" << endl;
}

bool ChessGame::setup(){

    player[0] = new Human('w'); // White player

    cout << "Welcome to Chess!" << endl;

    cout << "Initializing the chess board..." << endl;
    // Initialize the chess board
    chessBoard = ChessBoard::getInstance();

    cout << "Chess board initialized." << endl;

    cout << "Do you want to play against another player or against the computer? (p/c): ";
    cout << "Enter 'e' or 'E' to exit the game." << endl;
    char choice;
    cin >> choice;

    if (choice == 'p' || choice == 'P') {
        cout << "You chose to play against another player." << endl;
        player[1] = new Human('b'); // Black player
    } else if (choice == 'c' || choice == 'C') {
        cout << "You chose to play against the computer." << endl;
        player[1] = new Computer('b'); // Assuming you have a Computer class
    } else if (choice == 'e' || choice == 'E') {
        cout << "Exiting the game." << endl;
        return; // Exit the game if the user chooses to exit
    } else {
        cout << "Invalid choice. Please try again or exit." << endl;
         // Exit if the choice is invalid
    }
}

