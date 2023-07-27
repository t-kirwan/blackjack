#ifndef PLAYERS_H
#define PLAYERS_H
#include "Blackjack.h"
#include <iostream>

using namespace std;

class player{
	public:
		string name;
		card hand[5];	//Maximum hand size
		int winnings;
		string display;

	public:
		void setName(string NAME){
			name = NAME;
		}

		void setHand(card DEALT, int total){
			for(int i=0; i<total; i++){
				hand[i] = DEALT;
			}
		}

		void setWinnings(int WINNINGS){
			winnings = WINNINGS;
		}

		string getName(){
			return name;
		}

		void getHand(int total){

			for(int i=0; i<total; i++){		//Loop through hand
				display = hand[i].print();	//Call print() from Blackjack.h
			}
			cout<< display <<endl;			//Print all cards in hand
		}
		
		int getWinnings(){
			return winnings;	
		}

		player(){
			cout<<"A new player is joining"<<endl;
		}

		~player(){
			cout<<"A player is leaving the table"<<endl;
		}
};

class dealer : public player{
	private:
		card down;
		string hidden;
	public:
		void setDown(card DOWN){
			down = DOWN;
		}
		
		void getDown(){
			hidden = down.print();
			cout<< hidden <<endl;
		}

		dealer(){
			cout<<"A new dealer is joining"<<endl;
		}

		~dealer(){
			cout<<"A dealer is leaving the table"<<endl;
		}

};

class user : public player{
	private:
		int choice = 0; //For the player to choose an action on their turn
	public:
		void choose(); //Make a decision on whether to hit or stand
		void hit(); //Take another card
		void stand(); //Stop taking cards and keep total
		user(){
			cout<<"A new user is joining"<<endl;
		}
		~user(){
			cout<<"A user is leaving the table"<<endl;
		}
};

class computer : public player{
        private:
		int limit = 17;//Total at which the computer stops hitting
        public:
		computer(){
			cout<<"A new computer is joining"<<endl;
		}
		~computer(){
			cout<<"A computer is leaving the table"<<endl;
		}
};

#endif
