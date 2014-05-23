#include <iostream>
#include <string>
#include "RPGCharacter.h"


RPGCharacter::RPGCharacter(std::string player_name, std::string pchar){

	name=player_name;
	char_class=pchar;
	setup_char(1,char_class);

}

RPGCharacter::RPGCharacter(std::string player_name,std::string pchar, int player_level){

	name=player_name;
	char_class=pchar;
	setup_char(player_level,char_class);

}

void RPGCharacter::setup_char(int plevel,std::string pchar){

	if(pchar.compare("RANGER")==0){
		setup_ranger(plevel);

	}
	else if(pchar.compare("WARRIOR")==0){
		setup_warrior(plevel);

	}	
	else if(pchar.compare("MAGE")==0){
		setup_mage(plevel);

	}
}


void RPGCharacter::setup_ranger(int plevel){
 	level=plevel;
	xp=0;
	damage=level*4+xp;
	armor=level*3;
	hp=100;	
	

}

void RPGCharacter::setup_warrior(int plevel){
        level=plevel;
        xp=0;
        damage=level*3+xp;
        armor=level*4;
        hp=100; 


}

void RPGCharacter::setup_mage(int plevel){
        level=plevel;
        xp=20;
        damage=level*2+xp;
        armor=level*3;
        hp=100; 


}

void RPGCharacter::changeHp(int val){
	hp=hp-val;

}

int RPGCharacter::getHp(){
	return hp;
}

void RPGCharacter::attack(RPGCharacter *opp){
	//std::cout<<"Opp has hp "<<opp->getHp()<<std::endl;
	opp->changeHp(this->damage);
      	//std::cout<<"After attack opp has hp "<<opp->getHp()<<std::endl;

}

void RPGCharacter::updateXp(int val){
	xp=xp+val;
	damage=damage+xp;
	level++;
	
}

int RPGCharacter::getXp(){
	return xp;
}

