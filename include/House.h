#ifndef __HOUSE_H__
#define __HOUSE_H__
 
#include <string> 
#include "GenericPlayer.h"

class House : public GenericPlayer { 

public: 
	House(const std::string& name = "House"); 
	virtual ~House(); 

	virtual bool isHitting() const; 
		
	void flipFirstCard(); 

}; 
#endif
