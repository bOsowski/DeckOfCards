#include "stdafx.h"
#include "Card.h"

Card::Card(short number, string colour, string symbol)
{
	cout << "A " << number << " " << colour << " " << symbol << " card has been created." << endl;
	Card::number = number;
	Card::colour = colour;
	Card::symbol = symbol;
	Card::isNum = true;
}

Card::Card(string person, string colour, string symbol){
	cout << "A " << person<<" " << colour << " " << symbol << " card has been created." << endl;
	Card::person = person;
	Card::colour = colour;
	Card::symbol = symbol;
	Card::isNum = false;
}


Card::~Card()
{
	cout << "Destructor called for " << *this << endl;
}


bool Card::isNumber()
{
	return isNum;
}

string Card::getColour()
{
	return colour;
}

string Card::getSymbol()
{
	return symbol;
}

short Card::getNumber()
{
	return number;
}

string Card::getPerson()
{
	return person;
}

ostream& operator <<(ostream &stream, Card &card)
{
	if (card.isNumber()) {
		return stream << "Card(" << *(&card.number) << " " << *(&card.colour) << " of " << *(&card.symbol) << ")";
	}
	else {
		return stream << "Card(" << *(&card.person) << " " << *(&card.colour) << " of " << *(&card.symbol) << ")";
	}
}
