// FirstGame.cpp
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned)time(0)); //will allow random numbers

    constexpr int kPlayMenu = 1;
    constexpr int kQuitMenu = 2;

    constexpr int kMaleGender = 1;
    constexpr int kFemaleGender = 2;
    constexpr int kOtherGender = 3;

    //display welcome message
    cout << "-------- Welcome to the Amazing number guessing game. --------" << endl;
    cout << " You have 2 guesses to correctly guess the number between 1 and 20: " << endl;
    cout << " 1) Play Now" << endl;
    cout << " 2) Quit" << endl;
    cout << "press 1 or 2: ";

    int input;
    cin >> input;

    switch (input)
    {
        case kPlayMenu:
        {
            cout << "What is your name: " << endl;
            string name;
            cin >> name;

            cout << "Welcome " << name << "!" << endl << endl;
            cout << "What is your gender?: " << endl;
            cout << " 1) Male" << endl;
            cout << " 2) Female" << endl;
            cout << " 3) Other" << endl;
            cout << " press 1, 2 or 3: ";

            int gender;
            cin >> gender;

            if (gender >= kMaleGender && gender <= kOtherGender)
            {
                cout << "How old are you?: ";
                int age;
                cin >> age;

                string nickname;
                if (gender == kMaleGender)
                {
                    if (age > 60)
                    {
                        nickname = "old man";
                    }
                    else if (age < 10)
                    {
                        nickname = "little man";
                    }
                    else
                    {
                        nickname = "bud";
                    }
                }
                else if (gender == kFemaleGender)
                {
                    if (age > 60)
                    {
                        nickname = "old lady";
                    }
                    else if (age < 10)
                    {
                        nickname = "little lady";
                    }
                    else
                    {
                        nickname = "ma'am";
                    }
                }
                else
                {
                    nickname = "friend";
                }
                
                int randomNumber = 1 + rand() % 20;
                //cout << randomNumber << endl; will display the number you need to guess
                cout << "Guess 1: " << "Alright " << nickname << " please guess the number: ";
                int guess;
                cin >> guess;

                if (guess == randomNumber)
                {
                    cout << "You are correct!!!" << endl;
                }
                else
                {
                    if (guess > randomNumber)
                    {
                        cout << "Your guess is too high. Try again!" << endl;
                    }
                    else
                    {
                        cout << "Your guess is too low. Try again!" << endl;
                    }

                    cout << "Guess 2: " << "Alright " << nickname << " please guess the number: ";
                    cin >> guess;

                    if (guess == randomNumber)
                    {
                        cout << "You are correct!!!" << endl;
                    }
                    else
                    {
                        if (guess > randomNumber)
                        {
                            cout << "Your guess is too high." << endl;
                        }
                        else
                        {
                            cout << "Your guess is too low." << endl;
                        }

                        cout << "Better luck next time. Goodbye!" << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid gender. Goodbye!" << endl;
            }

            break;
        }
        case kQuitMenu:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid input. Goodbye!" << endl;
        }
    }
}

