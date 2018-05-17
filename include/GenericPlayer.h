#ifndef __GENERIC_PLAYER_H__
#define __GENERIC_PLAYER_H__

#include <iostream>
#include <string> 
#include "Hand.h" 
class GenericPlayer : public Hand { 

	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer); 

public: 
	GenericPlayer(const std::string& name=""); 
	virtual ~GenericPlayer(); 

	virtual bool isHitting() const = 0; 
	
	bool isBusted() const;
	
	void bust() const; 
protected: 
	std::string m_Name;  
}; 


#endif
