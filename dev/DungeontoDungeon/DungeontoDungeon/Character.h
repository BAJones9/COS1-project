#include <string>

class Character
{
public:
	//constructor
	Character();




	//getters
	std::string Name() const;
	int Health() const;
	int AttackPow() const;
	int Initiative() const;

	//setters
	void SetName(const std::string& _name);
	void SetHealth(const int _health);
	void SetAttackPow(const int _attackPow);
	void SetInitiative(const int _initiative);


private:
	std::string name;
	int health;
	int attackPow;
	int initiative;
	//std::vector<Item> Inventory
};