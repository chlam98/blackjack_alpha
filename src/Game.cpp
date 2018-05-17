#include "Game.h" 
#include "Deck.h"  
#include "House.h" 
#include "Player.h"  
#include "GenericPlayer.h"
#include "Hand.h"
#include "Card.h"

#include <vector>
#include <ctime>
#include <iostream>
#include <string>  
#include <algorithm>

using namespace std;  

Game::Game(const vector<string>& names) { 
	vector<string>::const_iterator pName; 

	for(pName = names.begin(); pName != names.end(); ++pName) { 
		m_Players.push_back(Player(*pName)); 
	}	

	srand(static_cast<unsigned int>(time(0))); 

	m_Deck.populate(); 
	m_Deck.shuffle(); 
}

Game::~Game()  
{} 


void Game::play() { 
	vector<Player>::iterator pPlayer; 

	//deal initial 2 cards to everyone
	for(int i = 0; i < 2; ++i) { 
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 
			m_Deck.deal(*pPlayer); 
		}
		m_Deck.deal(m_House); 
	}

	//hide house's first card
	m_House.flipFirstCard(); 

	//display everyone's hand
	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 

		cout << *pPlayer << endl; 
	}

	cout << m_House << endl; 
	 

	//deal additional cards to players 
	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 
		m_Deck.additionalCards(*pPlayer); 
	}

	m_House.flipFirstCard(); 
	cout << endl << m_House; 
	
	//deal additional cards to house
	m_Deck.additionalCards(m_House); 

	if(m_House.isBusted()) { 
		//everyone still playing wins. 
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 
			if(!(pPlayer->isBusted())) { 
				pPlayer->win(); 
			}

		} 
	} else { 
		//compare each player still playing to house 
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 
			if(!(pPlayer->isBusted())) { 
				if(pPlayer->getTotal() > m_House.getTotal()) { 
					pPlayer->win();
				} else if(pPlayer->getTotal() < m_House.getTotal()) { 
					pPlayer->lose(); 
				} else { 
					pPlayer->push(); 
				}
		
			}
		} 
	}
	 

	//remove everyone's cards 

	for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) { 
		pPlayer->clear(); 
	
	}
	m_House.clear(); 

}
