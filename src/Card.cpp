#include "Card.h" 

Card::Card(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) 
{} 


int Card::getValue() const { 
	int value = 0; 
	if(m_IsFaceUp) { 
		value = m_Rank; 
		
		if(value > 10) { 

			value = 10; 
		} 
	}

	return value; 
}

void Card::flip() { 
	m_IsFaceUp = !(m_IsFaceUp); 
}
