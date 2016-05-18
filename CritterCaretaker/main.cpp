// Critter Caretaker
// Simulates caring for a virtual pet

#include<iostream>

using namespace std;

class Critter
{
public:
	Critter(int Hunger = 0, int Boredom = 0 );
	void Talk();
	void Eat(int food = 4);
	void Play(int food = 4);
	void ShowHungerBoredom();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);
};

Critter::Critter( int hunger, int boredom ):
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime( int time )
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout << "\n I'm a critter and i feel ";

	int mood = GetMood();
	if (mood > 21)
	{
		cout << "mad.\n";

	}
	else if (mood > 16)
	{
		cout << "frustrated.\n";

	}
	else if (mood > 7)
	{
		cout << "okay.\n";

	}
	else
	{
		cout << "happy.\n";

	}

	ShowHungerBoredom();
	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brrupppp.\n";
	m_Hunger -= food;

	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	ShowHungerBoredom();
	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheeeee!\n";
	m_Boredom -=fun;

	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	ShowHungerBoredom();
	PassTime();
}

void Critter::ShowHungerBoredom()
{
	if ((m_Hunger <= 3) && (m_Boredom <= 3))
	{
		cout <<  "I'm Not hungry nor bored.\n";
		cout << "\n\n";
	}
	else if ((m_Hunger <= 3) && ((m_Boredom > 3 && m_Boredom <= 11)))
	{
		cout <<  "I'm Not hungry, but i'm a little bored.\n";
		cout << "\n\n";
	}
	else if ((m_Hunger <= 3) && (m_Boredom >= 11))
	{
		cout << "I'm Not hungry, but i'm really Bored.\n";
		cout << "\n\n";
	}
	else if ((m_Boredom <= 3) && ((m_Hunger > 3 && m_Hunger < 11)))
	{
		cout << "I'm a little hungry but not bored.\n";
		cout << "\n\n";
	}
	else if (((m_Boredom > 3 && m_Boredom < 11)) && ((m_Hunger > 3 && m_Hunger < 11)))
	{
		cout << "I'm a little hungry and bored.\n";
		cout << "\n\n";
	}
	else if ((m_Boredom >= 11) && ((m_Hunger > 3 && m_Hunger < 11)))
	{
		cout << "I'm a little hungry, but really bored.\n";
		cout << "\n\n";
	}
	else if ((m_Hunger >= 11) && (m_Boredom <= 3))
	{
		cout << "I'm really hungry, but not bored.\n";
		cout << "\n\n";
	}
	else if ((m_Hunger >= 11) && ((m_Boredom > 3 && m_Boredom < 11)))
	{
		cout << "I'm really hungry and a little bored.\n";
		cout << "\n\n";
	}
	else if ((m_Hunger >= 11) && (m_Boredom >= 11))
	{
		cout << "I'm really hungry and really bored.\n";
		cout << "\n\n";
	}
}

int main()
{
	Critter crit;
	crit.Talk();
    int fun;
    int food;
	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with critter\n";

		cout << "Choice: ";
		cin >> choice;

		if (choice == 0)
		{
			cout << "Good-bye" << endl;
		}
		else if (choice == 1)
		{
			crit.Talk();
		}
		else if (choice == 2)
		{
			cout << "how much do you want to feed your pet? (enter:1-4):" << endl;
			cin >> food;
			crit.Eat();

		}
		else if (choice == 3)
		{
			cout << "how long do you want to play with your pet?(enter:1-4):" << endl;
			cin >> fun;
            crit.Play();
		}

		else
		{
			cout << "Sorry, but" << choice << "is not a valid choice" << endl;
		}



	}while (choice != 0);

	return 0;
}


