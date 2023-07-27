#include <iostream>
#include "Blackjack.h"
#include "players.h"

int main(){
	string userName, dealerName, compName;
	int cardCount = 0;
	int choice = 0;

	cout<<endl<<"WHO'S READY TO PLAY BLACKJACK??"<<endl<<endl;

	cout<<"Enter your name to play"<<endl;
	getline(cin, userName);
//	cout<<"Enter the Dealer's name"<<endl;
//	getline(cin, dealerName);
	cout<<"Enter a name for the computer"<<endl;
	getline(cin, compName);

	player playerA;		//Declare player, dealer, and computer
	dealer dealerA;
	player computerA;

	playerA.setName(userName);
	playerA.getName();
	playerA.setWinnings(100);	//Start with $100
	computerA.setName(compName);
	computerA.getName();
	computerA.setWinnings(100);	//Start with $100

	card currentCard;	//Declare a card element
	deckOfCards deck;	//declare a deck
	
	deck.shuffle();	//shuffle the deck that you just initalized

//-----------------------------------------------------------------------------DEAL INITIAL CARDS-----------------------------------------------------------------------	
//THIS LOOP DEALS INITIAL CARDS TO THE PLAYER'S HAND
	cout<<userName<<"'s Hand: "<<endl;
	int userTotal = 0;
	for(int i = 0; i < 2; i++){			//determine how many cards you want to print out to the user
							//right now it is two because we decided that each player will get two cards when they start
		currentCard = deck.dealCard();		//set current card equal to deck.dealcard
							//the return value will replace it
		playerA.setHand(currentCard, i);	//Assign the card to player
		playerA.getHand(i+1);			//print player's hand
		userTotal += currentCard.getValue();
		cout<< "Total: " << userTotal;
		cout<<endl;
	}
//DEALS INITIAL CARDS TO COMPUTER'S HAND
	cout<<endl<<compName<<"'s Hand: "<<endl;
	for(int i = 0; i < 2; i++){			//determine how many cards you want to print out to the user
							//right now it is two because we decided that each player will get two cards when they start
		currentCard = deck.dealCard();		//set current card equal to deck.dealcard
							//the return value will replace it
		computerA.setHand(currentCard, i);	//Assign the card to player
		computerA.getHand(i+1);			//print player's hand
	}
//DEALS INITIAL CARDS TO DEALER
	cout<<endl<<"Dealer's Visible Card is: "<<endl;
	for(int i=0; i < 1; i++){
		currentCard = deck.dealCard();
		dealerA.setDown(currentCard);

		currentCard = deck.dealCard();
		dealerA.setHand(currentCard, i);
		dealerA.getHand(i+1);
	}
	cout<<"Dealer's Down Card:"<<endl;	//FOR TESTING PURPOSES ONLY
	dealerA.getDown();			//FOR TESTING PURPOSES ONLY
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	int k = 1;

	while(1){
		if(userTotal == 21){
			cout<<"You win.\n";
			break;
		}
		if(userTotal > 21){
			cout<<"Bust.\n";
			break;
		}
		cout<<"What would you like to do next? \n 1 to HIT \n 2 to STAY \n 3 to LEAVE TABLE"<<endl;

		cin>>choice;

		switch(choice){
			case 1:	k = k+1;
				currentCard = deck.dealCard();		//HIT FUNCTION
				playerA.hand[k] = currentCard;
				cout<<userName<<"'s New Hand: "<<endl;
				for(int i=0; i <= k; i++){
					playerA.getHand(i+1);
				}
				userTotal += currentCard.getValue();
                		cout<< "Total: " << userTotal;
                		cout<<endl;
				break;
			case 2:	for(int i=0; i <= k; i++){
					playerA.getHand(i+1);			//STAY FUNCTION
				}
				break;
							//AFTER STAYING, MOVE TO NEXT PLAYER
			case 3: break;	//EXIT
			default: cout<<"Invalid Choice"<<endl; break;
		}
		if (choice==3){
			break;
		}
	}
return 0;
}
