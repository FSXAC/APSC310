// Suppose the rectangle that comes in the library is defined as:
class Rectangle
{
public:
	Rectangle(int x, int y, int w, int h)
	{
		// ...
	}
};

// An adapted rectangle class to fit client need
class Rect : public Rectangle
{
public:
	Rect(int x1, int y1, int x2, int y2)
	: Rectangle(x1, y1, x2 - x1, y2-y1)
	{
		// Legacy rectangle created; constructor interfacing correctly
	}
};