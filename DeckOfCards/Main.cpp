// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Deck.h"

using namespace std;

inline void printAllDecks(vector<Deck*>& decks) {
	for (int i = 0; i < decks.size(); i++) {
		cout << i << ") " << decks.at(i)->getDeckName() << ". Deck size = " << decks.at(i)->getDeckSize() << endl;
	}
}

//The main function holds a vector which holds all the decks that are on the heap.
//The player is able to create new decks, move cards from one to another, shuffle cards, delete decks, view decks etc.
int main()
{
	vector<Deck*> decks;
	while (1) {
		cout << "1) Create a new deck.\n"
			<< "2) Give a player cards from the deck.\n"
			<< "3) Delete a deck.\n"
			<< "4) Shuffle a deck.\n"
			<< "5) View decks.\n"
			<< "6) View a deck.\n"
			<< "7) EXIT.\n"
			<< ">>";

		int choice;
		cin >> choice;

		switch (choice) {
			case 1:
			{
				cout << "How would you like to call the new deck? >>";
				string deckName = "";
				cin >> deckName;
				cout << "Do you want to create \n1)an empty deck to be then filled or \n2)a full deck of 52 cards?\n>> ";
				int choice;
				cin >> choice;
				cout << endl;
				if (choice == 1) {
					decks.push_back(new Deck(deckName, ""));
				}
				else if (choice == 2) {
					decks.push_back(new Deck(deckName));
				}
				else {
					cout << "Wrong input, no deck was created\n\n";
				}
				cout << "\nA new deck '" << deckName << "' has been creeated.\n\n";
				break;
			}
			case 2:
			{
				cout << "What deck number do you want to take cards from? >>\n";
				printAllDecks(decks);
				int deckToMoveFrom;
				cin >> deckToMoveFrom;
				cout << endl;
				cout << "How many cards to you want to move? (max = " << decks.at(deckToMoveFrom)->getDeckSize() << ") >>";
				int cardsToMove;
				cin >> cardsToMove;
				cout << endl;
				cout << "What deck number do you want to move the " << cardsToMove << " cards to? >>\n";
				printAllDecks(decks);
				int deckToMoveTo;
				cin >> deckToMoveTo;
				cout << endl;
				decks.at(deckToMoveTo)->addCardsToDeck(decks.at(deckToMoveFrom)->givePlayerCards(cardsToMove));
				break;
			}
			case 3:
			{
				cout << "Which deck do you want to delete? >>\n";
				printAllDecks(decks);
				int choice;
				cin >> choice;
				cout << endl;
				delete decks.at(choice);
				decks.erase(decks.begin() + choice);
				cout << "deck number " << choice << " has been deleted.\n\n";
				break;
			}
			case 4:
			{
				cout << "Which deck do you want to shuffle? >>\n";
				printAllDecks(decks);
				int choice;
				cin >> choice;
				cout << endl;
				decks.at(choice)->shuffleDeck();
				cout << "The deck has been shuffled.\n\n";
				break;
			}
			case 5:
			{
				printAllDecks(decks);
				cout << endl << endl;
				break;
			}
			case 6:
			{
				cout << "Which deck do you wish to view? >>\n";
				printAllDecks(decks);
				int choice;
				cin >> choice;
				decks.at(choice)->printTheDeck();
				break;
			}
			default:
			{
				return 0;
			}
		}
		cin.ignore();
	}
    return 0;
}

