#ifndef __HAND_H__
#define __HAND_H__
#include <vector>

class Card;
class Hand { 
public: 
	 Hand(); 
	 virtual ~Hand(); 
	
	void add(Card* pCard); 
	void clear(); 

	int getTotal() const; 

protected: 
	std::vector<Card*> m_Cards; 

}; 

#endif
