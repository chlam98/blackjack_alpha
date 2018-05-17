#include "Player.h"  
#include <iostream> 

using namespace std; 
Player::Player(const string& name) : GenericPlayer(name) 
{} 
 

Player::~Player()  
{}

bool Player::isHitting() const { 
	cout << m_Name << ", do want a hit? (Y/N): "; 
	char response; 
	cin >> response; 
	return (response == 'y' || response == 'Y'); 
}
 
void Player::win() const  { 
	cout << m_Name << " wins.\n"; 
}

void Player::lose() const { 
	cout << m_Name << " loses.\n"; 
}

void Player::push() const { 
	cout << m_Name << " pushes.\n"; 
}

