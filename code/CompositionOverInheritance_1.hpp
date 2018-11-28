class GameObject
{
public:
	virtual ~GameObject() {}
	virtual void update() {}
	virtual void draw() {}
	virtual void collide(GameObject objs[]) {}
};

class Visible : public GameObject
{
public:
	void draw() override{};
};

class Solid : public GameObject
{
public:
	void collide(GameObject objs[]) override {}
};

class Movable : public GameObject
{
public:
	void update() override {}
};

// Composed classes
class Player : public Visible, public Solid, public Movable
{
	//...
};

class Building : public Visible, public Solid
{
	//...
};

class Ghost : public Visible, public Movable
{
	//...
};