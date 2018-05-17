#include "Deck.h"  
#include "Card.h"
#include "House.h" 
#include "GenericPlayer.h"

#include <iostream>
#include <algorithm>  

using namespace std; 

Deck::Deck() { 
	m_Cards.reserve(52); 
	populate(); 
}

Deck::~Deck()  
{} 

void Deck::populate() { 
	clear(); 

	for(int s = Card::CLUBS; s <= Card::SPADES; ++s) { 
		for(int r = Card::ACE;  r <= Card::KING; ++r) { 
			add(new Card(static_cast<Card::rank>(r), 
				static_cast<Card::suit>(s)));
		}
	}
}

void Deck::shuffle() { 
	random_shuffle(m_Cards.begin(), m_Cards.end()); 
}

void Deck::deal(Hand& aHand) { 
	if(!m_Cards.empty()) { 
		aHand.add(m_Cards.back()); 
		m_Cards.pop_back(); 
	}else { 
		cout << "Out of cards. Unable to deal."; 
	}
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer) { 
	cout << endl; 
		
	while(!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting()) { 
		deal(aGenericPlayer); 
		cout << aGenericPlayer << endl; 

		if(aGenericPlayer.isBusted()) { 
			aGenericPlayer.bust(); 
		} 
	}
}
