/// SIMPLE FACTORY

// Base class
class Shape
{
public:
	virtual float getArea();
	void setId(int id) { m_id = id; }
protected:
	float m_width;
	float m_height;
	float m_id = 0;
};

// Derived classes
class Rectangle : public Shape
{
public:
	Rectangle(float w, float h)
	{
		m_width = w;
		m_height = h;
	}

	float getArea() override { return m_width * m_height; }
};

class Triangle : public Shape
{
public:
	Triangle(float w, float h)
	{
		m_width = w;
		m_height = h;
	}

	float getArea() override { return 0.5 * m_width * m_height; }
};

// Factory
class SimpleShapeFactory
{
public:
	static Shape* makeRect(float w, float h)
	{
		Shape* newRect = new Rectangle(w, h);
		newRect->setId(m_idCount++);
		return newRect;
	}

	static Shape* makeTri(float w, float h)
	{
		Shape* newTri = new Triangle(w, h);
		newTri->setId(m_idCount++);
		return newTri;
	}
private:
	static int m_idCount;
};

// Example
void BeforeSimpleFactory()
{
	Shape* shapes[] = { new Rectangle(5, 4), new Triangle(3, 1) };

	// Then we need to apply any applicable instantiation logic to each one
	for (int i = 0; i < 2; i++)
	{
		shapes[i]->setId(i);
	}
}

void AfterSimpleFactory()
{
	Shape* shapes[] = { SimpleShapeFactory::makeRect(5, 4), SimpleShapeFactory::makeTri(3, 1) };
}

/// Abstract factory: useful for platform specific things with different concrete implementations
class Button
{
public:
	virtual void draw() = 0;
};

// Derived platform specific
class KeyboardButton : public Button
{
public:
	void draw() override { /* draws a key */ }
};

class ControllerButton : public Button
{
public:
	void draw() override { /* draws a controller button */ }
};

// The abstract factory to create all related objects
class ButtonAbstractFactory
{
public:
	virtual Button* makeButton();
};

// Concrete factory to create concrete objects in the type of abstract
class KeyboardButtonFactory : public ButtonAbstractFactory
{
public:
	Button* makeButton() override { return new KeyboardButton(); }
};

class ControllerButtonFactory : public ButtonAbstractFactory
{
public:
	Button* makeButton() override { return new ControllerButton(); }
}
