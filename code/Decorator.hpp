#pragma once
#include <iostream>

class IWidget
{
public:
	virtual void draw() = 0;
}

class TextFieldWidget : public IWidget
{
public:
	TextFieldWidget(int w, int h)
	: m_width(w)
	, m_height(h)
	, m_text("")
	{
	}

	void draw() override
	{
		std::cout << "Draws textfield: " << m_text << "\n";
	}

	void setText(const std::string& text) { m_text = text; }

protected:
	int m_width;
	int m_height;
	std::string m_text;
};

class DecoratorBase : public IWidget
{
public:
	DecoratorBase(IWidget *w) : m_widget(w) { }
	void draw() override { m_widget->draw(); }
protected:
	IWidget *m_widget;
};

class BorderDecorator : public DecoratorBase
{
public:
	BorderDecorator(IWidget *w) : DecoratorBase(w) { }
	void draw() override
	{
		// Call parent
		DecoratorBase::draw();

		// Does own functionalities (extra decorator responsiblities)
		std::cout << "Draws border\n";
	}
};

class ScrollbarDecorator : public DecoratorBase
{
public:
	ScrollbarDecorator(IWidget *w) : DecoratorBase(w) { }
	void draw() override
	{
		DecoratorBase::draw();
		std::cout << "Draws scroll bar\n";
	}
};

int main(void)
{
	// Core widget
	IWidget* textfield = new TextFieldWidget(200, 50);
	textfield.setText("Hello APSC!");

	// Decorators that wrap it in a "chain" of wrappers
	IWidget* wrappedTextfield = new BorderDecorator(
		new ScrollbarDecorator(textfield)
	);

	// Interact with wrapped widget with added functinoalities
	wrappedTextfield->draw();

	return 0;
}