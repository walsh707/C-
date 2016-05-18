// Word Jumble

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string guess;

	int wordpoints;
    char another;

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const int MAX_GUESSES = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"astronaut", "They fly into space"},
        {"star", "The sun is one of them."},
        {"anime", "Japanese cartoons"},
        {"sword", "It's dangerous to go alone take this"},
        {"dragon", "They breath fire."}
    };

  	srand(time(0));
	int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  // word to guess
    string theHint = WORDS[choice][HINT];  // hint for word

    string jumble = theWord;  // jumbled version of word
    int length = jumble.size();
    for (int i=0; i<length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Solve the mixed up word.\n";
    cout << "Enter 'hint' for a hint. Note: You will lose one point.\n";
    cout << "Enter 'quit' to quit the game.\n\n";


    bool done = false;


    do
    {
        int points = 0;
        choice = (rand() % NUM_WORDS);
        theWord = WORDS[choice][WORD]; // word to guess
        theHint = WORDS[choice][HINT]; // hint for word
        jumble = theWord; // jumbled version of word
        length = jumble.size();

            for (int i = 0; i < length; ++i)
        {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
        }


        cout << "The jumble is: " << jumble;

        bool match = false;

        for(int nIndex = 0; (nIndex < MAX_GUESSES) && !match ; nIndex++)
        {
            cout << "\n\nGuess " << nIndex+1 << ": ";
            cin >> guess;

            if (guess == "hint")
            {
                cout << theHint;
                points--; //subtract 1 point
            }//end if
            else if (guess == "quit")
            {
                 cout << "\nGood bye!\n";
                 break;
            }
            else if (guess == theWord)
            {
                cout << "\nWell done!\n";
                wordpoints = guess.size();
				points += wordpoints; //points = # of letters in word
				cout << "Number Points for this word is " << wordpoints << endl;
				match = true;
            }//end else if
            else
            {
                cout << "Sorry, that is incorrect.";

            }//end else
        }//end for
        cout << "\n\nYour Total Points Are: " << points;
        cout << "\n\n\nWould You Like To Play Again? (y/n): ";
        cin  >> another;
        system("cls");
        if (another == 'n')
        {
           done = true;
        }
    } while(!done);


    cout << "Thanks for playing!"<< endl;
    system("pause");
    return 0;
}//end main
