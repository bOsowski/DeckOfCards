#include "stdafx.h"
#include "Deck.h"


Deck::Deck(string deckName)
{
	Deck::deckName = deckName;
	//creating 10 black clubs
	for (int i = 1; i <= 10; i++) {
		theDeck.push_back(new Card(i,"black", "Clubs"));
	}
	//creating 10 red diamonds
	for (int i = 1; i <= 10; i++) {
		theDeck.push_back(new Card(i, "red", "Diamonds"));
	}
	//creating 10 red hearts
	for (int i = 1; i <= 10; i++) {
		theDeck.push_back(new Card(i, "red", "Hearts"));
	}
	//creating 10 black spades
	for (int i = 1; i <= 10; i++) {
		theDeck.push_back(new Card(i, "black", "Spades"));
	}

	//creating jacks
	theDeck.push_back(new Card("Jack", "black", "Clubs"));
	theDeck.push_back(new Card("Jack", "red", "Diamonds"));
	theDeck.push_back(new Card("Jack", "red", "Hearts"));
	theDeck.push_back(new Card("Jack", "black", "Spades"));

	//creating queens
	theDeck.push_back(new Card("Queen", "black", "Clubs"));
	theDeck.push_back(new Card("Queen", "red", "Diamonds"));
	theDeck.push_back(new Card("Queen", "red", "Hearts"));
	theDeck.push_back(new Card("Queen", "black", "Spades"));

	//creating kings
	theDeck.push_back(new Card("King", "black", "Clubs"));
	theDeck.push_back(new Card("King", "red", "Diamonds"));
	theDeck.push_back(new Card("King", "red", "Hearts"));
	theDeck.push_back(new Card("King", "black", "Spades"));

	cout << "The deck has been created.\n";
}

Deck::Deck(string deckName, vector<Card*> deck)
{
	Deck::deckName = deckName;
	cout << "Creating a new deck. Size of deck = " << deck.size()<<endl<<endl;
	theDeck = deck;
}

Deck::Deck(string deckName, string empty)
{
	Deck::deckName = deckName;
	cout << "Creating a new empty deck." << endl << endl;
}


Deck::~Deck()
{	
	cout << "Destructor for the deck called. Deleting items inside the deck and the deck itself.\n";
	for (unsigned int i = 0; i < theDeck.size(); i++) {
		delete theDeck.at(i);
	}
}

void Deck::shuffleDeck()
{
	std::srand(unsigned(std::time(0)));
	// using built-in random generator:
	random_shuffle(theDeck.begin(), theDeck.end());
}

void Deck::printTheDeck()
{
	// print out content:
	cout << "The deck from the bottom to the top:\n\n";
	for (unsigned int i = 0; i < theDeck.size(); i++) {
			cout << "Card#" << i << " "<<*theDeck.at(i)<<endl;
	}
}

vector<Card*> Deck::givePlayerCards(int numberOfCards)
{
	if (theDeck.size() < numberOfCards) {
		cout << " there aren't that many cards in the deck!";
		return vector<Card*>();
	}
	vector<Card*> playerCards;
	Card* tempCardPointer;
	for (int i = 0; i < numberOfCards; i++) {
		tempCardPointer = theDeck.at(theDeck.size()-1);

		theDeck.pop_back();
		playerCards.push_back(tempCardPointer);
	}
	return playerCards;
}

void Deck::addCardsToDeck(vector<Card*> cardsToAdd)
{
	for (int i = 0; i < cardsToAdd.size(); i++) {
		theDeck.push_back(cardsToAdd.at(i));
	}
}

string Deck::getDeckName()
{
	return deckName;
}

int Deck::getDeckSize()
{
	return theDeck.size();
}
