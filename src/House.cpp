#include "House.h"  
#include "Card.h"
#include <iostream>  

using namespace std; 

House::House(const string& name) : GenericPlayer(name) 
{} 

House::~House()  
{}  

bool House::isHitting() const { 
	return (getTotal() <= 16); 
}

void House::flipFirstCard() { 
	if(!m_Cards.empty()) { 
		m_Cards[0]->flip();
	} else { 

		cout << "No card to flip!\n"; 
	}
}


