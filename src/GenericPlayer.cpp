#include "GenericPlayer.h"  

using namespace std;

GenericPlayer::GenericPlayer(const string& name) : m_Name(name)
{}
 
GenericPlayer::~GenericPlayer() 
{}

bool GenericPlayer::isBusted() const { 
	return (getTotal() > 21); 
}

void GenericPlayer::bust() const { 
	cout << m_Name << " busts.\n"; 
}
 

