#include <string>

using namespace std;

typedef struct
{
	string name = "Alex";
	int age = 20;
	float height = 170.0;
	float weight = 180.0;
} PlayerCharacterBuilder_t;

class PlayerCharacter
{
public:
	PlayerCharacter(PlayerCharacterBuilder_t &builder)
	: m_name(builder.name)
	, m_age(builder.age)
	, m_height(builder.height)
	, m_weight(builder.weight)
	{
		// do stuff...
	}

private:
	string m_name;
	int m_age;
	float m_height;
	float m_weight;
};