#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;
class Card
{
public:
	Card(short number, string colour, string symbol);	//constructor for numerical cards
	Card(string person, string colour, string symbol);	//constructor for non-numerical cards, eg. king, queen etc.
	~Card();	//basically the default destructor but prining a message upon destruction.
	bool isNumber();	//a boolean determining if the card is numerical or not.

	//getters
	string getColour();
	string getSymbol();
	short getNumber();
	string getPerson();


//private variables
private:
	friend ostream& operator <<(ostream &stream, Card &card);
	bool isNum;
	short number;
	string person;
	string symbol;
	string colour;
};
#endif

