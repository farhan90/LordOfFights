#include <iostream>
#include <cstdlib>
#include "RPGCharacter.h"
using namespace std;


void help(){
	cout<<"This is a simple RPG game I designed to practice\n";
	cout<<"C++ and OOP\n";

}

RPGCharacter* generate_opponent(){

	int level=rand()%10 +1;
	int opt=rand()%3+1;
	std::string char_class;
	switch(opt){
                case 1:
                        char_class="RANGER";
                        break;
                case 2:
                        char_class="MAGE";
                        break;
                case 3:
                        char_class="WARRIOR";
                        break;
                default:
                        cout<< "Unknown option selected \n";
        }


	cout<<"Your opponent is "<<char_class<<endl;
	RPGCharacter *opp=new RPGCharacter("Computer",char_class,level);
	return opp; 
}

void play_game(std::string name, std::string char_class){

	RPGCharacter *player=new RPGCharacter(name,char_class,1);
	while(player->getHp()>0){
		RPGCharacter *comp=generate_opponent();
		while(player->getHp()>0 && comp->getHp()>0){
			
			player->attack(comp);
			comp->attack(player);

			cout<<"The player hp is "<<player->getHp()<<endl;
			cout<< "The comp hp is "<<comp->getHp()<<endl;	
 		}
		player->updateXp(comp->getXp());
		player->changeHp(10);

	}

}


void setup_game(){

	std::string char_class;
	std::string name;
	int opt;
	cout<<"Please enter your name ";
	cin>>name;
	cout<< "Please choose the type of character\n";
	cout<<"\t 1) RANGER\n";
	cout<<"\t 2) MAGE\n";
	cout<<"\t 3) WARRIOR\n";
	cin>>opt;

	switch(opt){
		case 1:
			char_class="RANGER";
			break;
		case 2:
			char_class="MAGE";
			break;
		case 3:
			char_class="WARRIOR";
			break;
		default: 
			cout<< "Unknown option selected \n";
			return;
	}

	cout<<"You have chosen "<<char_class<<endl;
	play_game(name, char_class);
}

void options(int opt){
	switch(opt){
	 case 1: 
		cout<< "You have opted to play\n";
		setup_game();
		break;
	 case 2:
		cout<< "You need help?\n";
		help();
		break;
	 case 3:
		cout<<"Goodbye!";
		exit(0);
	
         default:
		cout << "Unknown option \n"; 
	}
}

int main(){
	int opt=0;

	cout<<"Hello World \n";
	cout<< "Welcome to my program\n";
      
	while(1){
		cout<<"\t 1) Play\n";
		cout <<"\t 2) Help\n";
		cout << "\t 3) Quit\n";
        	cin>>opt;
		options(opt);
	}
}




