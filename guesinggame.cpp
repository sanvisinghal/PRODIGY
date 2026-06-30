#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    char playAgain;

    cout << "=====================================\n";
    cout << "      WELCOME TO GUESSING GAME\n";
    cout << "=====================================\n";

    do {
        srand(time(0));

        int secretNumber = rand() % 100 + 1;
        int guess, attempts = 0;

        cout << "\nI have selected a number between 1 and 100." << endl;
        cout << "Can you guess it?\n";

        while (true) {
            cout << "\nEnter your guess: ";
            cin >> guess;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }
            attempts++;
            if (guess < secretNumber) {
                cout << "Too Low! Try Again." << endl;
            }
            else if (guess > secretNumber) {
                cout << "Too High! Try Again." << endl;
            }
            else {
                cout << "\nCongratulations!" << endl;
                cout << "You guessed the correct number: " << secretNumber << endl;
                cout << "Number of attempts: " << attempts << endl;

                if (attempts <= 5)
                    cout << "Excellent Performance!" << endl;
                else if (attempts <= 10)
                    cout << "Good Job!" << endl;
                else
                    cout << "You finally got it!" << endl;

                break;
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing the Guessing Game!" << endl;

    return 0;
}