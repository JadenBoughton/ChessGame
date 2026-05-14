#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


#include "Piece.h"
#include "ChessGame.h"
//#include "Move.h"
#include "Subject.h"
//#include "Observer.h"
//#include "ChessBoard.instance.h"
using namespace std;


/*class IObserver {
	public:
	virtual ~IObserver() {} // Virtual destructor for proper cleanup
	virtual void update(const string& move) = 0; // Pure virtual function for update
}; // Forward declaration for Observer

class ISubject {
public:
	virtual ~ISubject() {} // Virtual destructor for proper cleanup
	virtual void attach(IObserver* observer) = 0; // Attach an observer
	virtual void detach(IObserver* observer) = 0; // Detach an observer
	virtual void notify(const string& move) = 0; // Notify observers of a move
};

class Subject : public ISubject {
	public:
		virtual ~Subject() {
			// Destructor logic if needed
		}

		// Implement the ISubject interface
		// to manage observers
		void attach(IObserver* observer) override {
			observers.push_back(observer);
		}

		void detach(IObserver* observer) override {
			observers.remove(observer);
		}

		void notify(const string& move) override {
			for (auto observer : observers) {
				observer->update(move);
			}
		}

		void createMessage(string message) {
			// Notify all observers with the message
			notify(message);
		}

		void howManyObservers() {
			std::cout << "Number of observers: " << observers.size() << std::endl;
		}

	private:
		std::list<IObserver*> observers;
		string message;
		static int observerCount; // Static variable to count observers
};

class Observer : public IObserver {
private:
	Subject& subject; // Add this member to store reference to Subject
	static int observerCount; // Static variable to count observers

public:
	Observer() = delete; // Delete default constructor
	Observer(Subject& subject) : subject(subject) {
		subject.attach(this); // Attach this observer to the subject
		cout << "Hi, I'm the observer \"" << ++Observer::observerCount << "\" and I'm observing the subject." << std::endl;
		// Constructor logic if needed
	}
	~Observer() {
		// Destructor logic if needed
	}
	void update(const string& move) override {
		// Handle the update from the subject
		std::cout << "Move updated: " << move << std::endl;
	}

	void removeMeFromTheList() {
		// Remove this observer from the subject's list
	}

	void printInfo() {
		// Print observer's information
		std::cout << "Observer info printed." << std::endl;
	}


};*/

class ChessBoard
{
private:
	vector<string> moveHistory;

	static Piece* gameBoard[8][8];

	static ChessBoard *instance;

	Piece* piece[32];

	Subject subject;
	//Observer observer;

private:
	bool swap(int* move);

protected:
    ChessBoard();

	~ChessBoard() {
		// Clean up resources if necessary
	}

public:
	ChessBoard(const ChessBoard&) = delete; // Prevent copying
 	
	ChessBoard& operator=(const ChessBoard&) = delete; // Prevent assignment

	static ChessBoard *getInstance();

	vector<string> getMoveHistory(int prevMoves);

	void updateBoard(int* move);
		
    Piece* getGameBoard(int row, int col);

	void setGameBoard(int row, int col, Piece* piece);

	void initializeBoard();
};

#endif
