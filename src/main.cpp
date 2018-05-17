
#include <iostream>
#include <string>

#include "Game.h" 
#include "Card.h"
 
using namespace std; 

ostream& operator<<(ostream& os, const Card& aCard); 

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer); 

int main() { 
	cout << "\t\tWelcome to Blackjack!\n\n"; 

	int numPlayers = 0; 
	
	while(numPlayers < 1 || numPlayers > 7) { 
		cout << "How many players? (1 - 7): "; 
		cin >> numPlayers; 
	}

	vector<string> names; 
	
	string name; 
	
	for(int i = 0;  i < numPlayers; ++i) { 
		cout << "Enter player name: "; 
		cin >> name; 
		names.push_back(name); 
	}	

	cout << endl; 
	
	Game aGame(names); 
	char again = 'y'; 
	while( again  != 'n' && again != 'N') { 
		aGame.play(); 
		cout << "\nDo you want to play again? (Y/N): "; 
		cin >> again; 
	}
	return 0; 
} 

ostream& operator <<(ostream& os, const Card& aCard) { 

    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", 
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
} 

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) { 
	os << aGenericPlayer.m_Name << ":\t"; 
	
	vector<Card*>::const_iterator pCard; 
	if(!aGenericPlayer.m_Cards.empty()) { 
		for(pCard = aGenericPlayer.m_Cards.begin(); 
			pCard != aGenericPlayer.m_Cards.end(); ++pCard) { 
			os << *(*pCard) << "\t"; 
		}

		if(aGenericPlayer.getTotal() != 0) { 
			cout << "(" << aGenericPlayer.getTotal() << ")"; 
		}
		
	} else { 
		os << "<empty>"; 
	}

	return os; 
}
