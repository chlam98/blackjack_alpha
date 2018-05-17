#include "Hand.h"  
#include "Card.h"
#include <vector>  
#include <algorithm>

using namespace std; 
 
Hand::Hand() { 
	m_Cards.reserve(7); 
}

Hand::~Hand() { 
	clear(); 
}	

void Hand::add(Card* pCard) { 
	m_Cards.push_back(pCard); 
}

 
void Hand::clear() { 
	vector<Card*>::iterator iter = m_Cards.begin(); 

	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) { 
		delete *iter; 
		*iter  = 0; 
	}

	m_Cards.clear(); 
	
}

//What if there are more than ONE ACE in a hand? 

int Hand::getTotal() const { 
	if(m_Cards.empty()) { 
		return 0; 
	}
	//if a first card has value of 0, then card is face down; return 0
 	if(m_Cards[0]->getValue() == 0) { 
		return 0; 
	}

	 
	int total = 0; 
	
	vector<Card*>::const_iterator iter; 
	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) { 
		total += (*iter)->getValue(); 
	}		

	bool containsAce = false; 
	
	for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) { 

		if((*iter)->getValue() == Card::ACE) { 
			containsAce = true; 
		}
	}
		

	if(containsAce && total <= 11) { 
		total += 10; 
	}

	return total; 
}
