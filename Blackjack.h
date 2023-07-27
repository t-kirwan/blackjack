#ifndef FINAL_PROJ
#define FINAL_PROJ
#include <iostream>
#include <cstdlib>	//random number generator
#include <ctime>	//random number generator
#include <string>

using namespace std;

#define SIZE 52		//Initilize constant variables

class card{
	private:
		string face;	//create two card variables face and suit
		string suit;
	public:

		string print(){
			return(face + " of " + suit);
		}

		int getValue(){
                        if(face == "King" || face == "Queen" || face == "Jack")
				return 10;
                        else if(face == "Ace"){
				cout<<"Ace worth 1 or 11?: ";
				int ace = 0;
				cin >> ace;
				while(ace != 1 && ace != 11){
					cout << "Enter 1 or 11." << endl;
					cin >> ace;
				}
				return ace;
			}
			else{
				return atoi(face.c_str());
                	}
		}

		card(){						//default constructer
		}

		card(string cardFace, string cardSuit){		//assigns the paraments above to the two variables face and suit
			face = cardFace;
			suit = cardSuit;
		}

		~card(){		//Destructor
		}
};


class deckOfCards{
	private:			//variable card with a pointer to deck
		card deck[SIZE]; 	// an array of cards of size SIZE
		int currentCard;	//keep track of what card you are dealing with
	public:
		void shuffle(){
			currentCard = 0;					//start at current card
			for(int first = 0; first < SIZE; first++){		//create a for loop so all 52 cards will be shuffled
				int second = (rand() + time(0)) % SIZE;		//create an int called second and set it equal to the random operator
				card temp = deck[first];			//create an int called temp and set it equal to the deck at the first postiion
				deck[first] = deck[second];			//swap deck at first and second postion
				deck[second] = temp;				//swap deck and temp
			}
		}

		card dealCard(){
			if(currentCard >= SIZE){		//if we are out of cards
				shuffle();			//shuffle
			}
			if( currentCard < SIZE){		//if we are not out of cards
				return (deck[currentCard++]);	//return deck at that current card and then increment
			}
			return (deck[0]);			//return the first card in the deck that we just found
		}

		deckOfCards(){		//Constructor
			string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};	//put all the face values in an array as strings
			string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};		//put all the suit values in an array as strings
			//deck = new card[SIZE];						//initilize deck from the card class to a new array using the word "new"
							//(REMOVED FROM ORIGINAL)
			currentCard = 0;							//current card is equal to zero
			for(int count = 0; count < SIZE; count++){				//create a for loop to  place each card into the new array
				deck[count] = card(faces[count % 13], suits[count / 13]);	//deck at postion count will be equal to card, each with a different face and suit
			}
		}

		~deckOfCards(){		//Destructor
		}
};
#endif
