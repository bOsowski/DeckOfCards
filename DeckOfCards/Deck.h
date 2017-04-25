#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>    // std::random_shuffle

using namespace std;

class Deck
{
public:
	Deck(string deckName);	//The default constructor creates a brand new deck with 52 cards.
	Deck(string deckName, vector<Card*> deck);	//This constructor creates a deck from the given cards.
	Deck(string deckName, string empty); //A constructor to create an empty deck.
	~Deck();	//the destructor destroys all cards which are being held by theDeck vector of Card pointers.
	void shuffleDeck();
	void printTheDeck();
	vector<Card*> givePlayerCards(int numberOfCards);	//returns pointers to the cards to be given out.
	void addCardsToDeck(vector<Card*> cardsToAdd);	//add all the pointers given to the current deck.
	string getDeckName();
	int getDeckSize();


private:
	vector<Card*> theDeck;
	string deckName;
};
#endif

