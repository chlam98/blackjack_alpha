#ifndef __PLAYER_H__
#define __PLAYER_H__
 
#include <string>  
 
#include "GenericPlayer.h"

class Player : public GenericPlayer { 
public: 
	Player(const std::string& name = ""); 
	virtual ~Player(); 

	virtual bool isHitting() const; 
		
	void win() const; 
	
	void lose() const; 
	
	void push() const; 


}; 

#endif
