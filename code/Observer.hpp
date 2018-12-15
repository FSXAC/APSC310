
#include <iostream>
#include <string>
#include <vector>

class ObserverBase;
class Subject
{
public:
	Subject() : m_data(0) { }
	void setData(int data)
	{
		if (m_data == data)
			return;

		m_data = data;
		sendEvent(m_data);
	}

	// Getter could be for when observers want to pull data
	int getData() const { return m_data; }

	// Register/unregister observers
	void registerObserver(ObserverBase* observer) { m_observers.push_back(observer); }
	bool unregisterObserver(ObserverBase* observer)
	{
		for (auto observerIter = m_observers.begin();
		observerIter != m_observers.end(); observerIter++)
		{
			if (*observerIter == observer)
			{
				m_observers.erase(observerIter);
				return true;
			}
		}
		return false;
	}

protected:
	void sendEvent(int data) const
	{
		for (auto observer : m_observers)
		{
			observer->handleEvent(data);
		}
	}
	
private:
	int m_data;
	std::vector<ObserverBase*> m_observers;
};

class ObserverBase
{
public:
	// Constructor
	ObserverBase(Subject *subject)
	{
		m_subject = subject;
		m_subject->registerObserver(this);
	}
	
	// Unregister observer from subject to avoid invalid memory access
	~ObserverBase() { m_subject->unregisterObserver(this); }

	virtual void handleEvent(int data) = 0;

protected:
	const Subject* getSubject() { return m_subject; }
private:
	Subject* m_subject;
};

class ZeroObserver : public ObserverBase
{
public:
	ZeroObserver(Subject* subject) : ObserverBase(subject) { }
	void handleEvent(int data) override
	{
		if (data == 0)
			std::cout << "Subject received data=0\n";
	}
};

class EvenNumberObserver : public ObserverBase
{
public:
	EvenNumberObserver(Subject* subject) : ObserverBase(subject) { }
	void handleEvent(int data) override
	{
		if (data % 2 == 0)
			std::cout << "Subject received data divisible by 2\n";
	}
};

class NegativeObserver : public ObserverBase
{
public:
	NegativeObserver(Subject* subject) : ObserverBase(subject) { }
	void handleEvent(int data) override
	{
		if (data < 0)
		{
			const int subjectData = getSubject()->getData();
			std::cout << "Subject received negative data: " << subjectData << "\n";
		}
	}
};

// Usage
void example()
{
	// Subject
	Subject* subject = new Subject();

	// Observers
	ZeroObserver zObs(subject);
	EvenNumberObserver evenObs(subject);
	NegativeObserver negObs(subject);

	// Only negative observer should print
	subject->setData(-1);

	// Only even number and zero observer should print
	subject->setData(0);

	// Only even number and negative observer should print
	subject->setData(-4);
}