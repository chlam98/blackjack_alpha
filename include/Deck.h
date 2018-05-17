#ifndef __DECK_H__
#define __DECK_H__

#include "Hand.h" 

class GenericPlayer;  

class Deck : public Hand { 
	
public: 
	Deck(); 
	virtual ~Deck(); 

	void populate(); 
	
	void shuffle(); 
	
	void deal(Hand& aHead);  
	
	void additionalCards(GenericPlayer& aGenericPlayer); 

}; 
#endif
