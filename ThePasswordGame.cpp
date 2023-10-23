#include <iostream>
#include <time.h>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

string generateRandomPassword(int length)
{
    static const string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // characters allowed
    string password;

    for (int i = 0; i < length; i++)
    {
        password += charset[rand() % charset.size()];
    }
    return password; // Return the generated password
}

int main()
{
    srand((unsigned)time(0)); // will allow random numbers

    constexpr int kPlayMenu = 1;
    constexpr int kQuitMenu = 2;

    cout << "-------- Welcome to the password game. --------" << endl;
    cout << " You have 3 times to enter the correct password. " << endl;
    cout << " 1) Play Now" << endl;
    cout << " 2) Quit" << endl;
    cout << "Press 1 or 2: ";

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

        string correctPassword = generateRandomPassword(8 + rand() % 3); // Generates a password of 8 to 10 characters

        bool passwordGuessed = false;

        for (int attempt = 1; attempt <= 3; attempt++)
        {
            string guess; // Change the data type of guess to string

            cout << "Password Attempt #" << attempt << ": Alright " << name << ", please enter the password: ";
            cin >> guess;

            if (guess == correctPassword) // Compare against the correctPassword string
            {
                cout << "You are correct!!!" << endl;
                passwordGuessed = true;
                break; // Break out of the loop if the password is guessed
            }
            else
            {
                cout << "That's not the correct password. Try again!" << endl;
            }
        }

        if (!passwordGuessed)
        {
            cout << "You've exhausted all attempts. The correct password is " << correctPassword << endl;
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
        break;
    }
    }
}
