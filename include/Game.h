#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <string>

#include "Deck.h" 
#include "House.h" 
#include "Player.h" 

class Game{ 
public: 
	Game(const std::vector<std::string>& names); 
	~Game(); 
	void play(); 

private: 
	Deck m_Deck; 
	House m_House; 
	std::vector<Player> m_Players; 

};
#endif
