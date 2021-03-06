/*
 * File: card.cpp
 * Name: Johee Chung
 * Due: February 16, 2016
 * Assignment: Homework 2 / Modeling a deck of cards
 * Class: COMP 15
 *
 * Class for representing cards in a standard 52-card deck.  Each
 * card's state is given by  the card's Rank and Suit, e.g., three of
 * diamonds.
 *
 * We supply enumerations for usual four suits (Clubs, Diamonds,
 * Hearts, and Spades) and for the usual ranks (2 -- 10 and the four
 * face cards).
 *
 * The default card (the one you get from the default constructor) is
 * the ace of clubs.
 *
 * Cards are mutable:  their suit and rank are separately settable.
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "card.h"

using namespace std;

Card::Card()
{
	// default values
	suit = CLUB;
	rank = ACE;
}

Card::Card(char r, char s)
{
	switch(s) {
	case 'C' :
		suit = CLUB;
		break;

	case 'H' :
		suit = HEART;
		break;

	case 'D' :
		suit = DIAMOND;
		break;

	case 'S' :
		suit = SPADE;
		break;
	}

	switch(r) {
	case 'T':
		rank = TEN;
		break;
	case 'J':
		rank = JACK;
		break;
	case 'Q':
		rank = QUEEN;
		break;
	case 'K':
		rank = KING;
		break;
	case 'A':
		rank = ACE;
		break;
	default:
		rank = (Rank)((int)r-'0'-2);
	}
}

Card::~Card()
{
	// nothing to do
}

void Card::print_card()
{
	string suit_str,rank_str;
	ostringstream ss;

	switch (suit) {
	case CLUB:
		suit_str = "C";
		break;
	case HEART:
		suit_str = "H";
		break;
	case DIAMOND:
		suit_str = "D";
		break;
	case SPADE:
		suit_str = "S";
		break;
	}
	switch (rank) {
	case TEN:
		rank_str = "T";
		break;
	case JACK:
		rank_str = "J";
		break;
	case QUEEN:
		rank_str = "Q";
		break;
	case KING:
		rank_str = "K";
		break;
	case ACE:
		rank_str = "A";
		break;
	default:
		ss << ((int)rank+2);
		rank_str = ss.str();
	}
	cout << rank_str << suit_str;
}

void Card::print_card_int()
{
	cout << card_int();
}

Suit Card::get_suit()
{
        return suit;
}

void Card::set_suit(Suit s)
{
        suit = s;
}

Rank Card::get_rank()
{
        return rank;
}

void Card::set_rank(Rank r)
{
        rank = r;
}

bool Card::same_card(Card c)
{
	return (rank == c.rank && suit == c.suit);
}

int Card::card_int()
{
	return (int)rank + (int)suit * 13;
}
