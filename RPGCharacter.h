#ifndef RPGCHARACTER_H
#define RPGCHARACTER_H

#define MAX_ARMOR_MAGE 35
#define MAX_ARMOR_RANGER 60
#define MAX_ARMOR_WARRIOR 90

class RPGCharacter{

	private:
		std::string name;
		std::string char_class;
		int level;
		int armor;
		int hp;
		int damage;
		int xp;
		

	public:
		RPGCharacter(std::string name, std::string pclass);
		RPGCharacter(std::string name,std::string pclass, int level);
		void setup_char(int level,std::string pclass);
		void setup_mage(int level);
		void setup_warrior(int level);
		void setup_ranger(int level);
		void changeHp(int val);
		int getHp();
		void attack(RPGCharacter *opp);		
		void updateXp(int val);
		int getXp();
};

#endif
