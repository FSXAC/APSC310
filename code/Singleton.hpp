// i.e. we want to have an achievement tracker, but the entire game should only have one
class AchievementTracker
{
public:
	// public static method getter
	static AchievementTracker *getInstance()
	{
		// Lazy initialization
		if (!m_instance)
		{
			m_instance = new AchievementTracker();
		}

		return m_instance;
	}

	// Other stuff
	void reset() { m_counter = 0; }
	void increment(int value) { m_counter += value; }
	bool getAchievementUnlocked() { return m_counter >= 5; }

private:
	// Private constructor
	AchievementTracker()
	{
		m_counter = 0;
	}

private:
	// Private static member to hold the single instance
	static AchievementTracker *m_instance;
	int m_counter;
};