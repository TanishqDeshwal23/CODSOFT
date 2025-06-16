#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    
    srand(time(0));

    
    int target = rand() % 201;

    int guess;
    int attempts = 0;
    int prevDifference = 1000;
    int currentDifference;

    cout << " Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 0 and 200 . Can you find it out???" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        
        if (guess < 0 || guess > 200) {
            cout << "Please enter a number between 0 and 200." << endl;
            continue;
        }

        attempts++;
        currentDifference = abs(target - guess);

        
        if (guess == target) {
            cout << " Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            break;
        }

    
        if (guess < target) {
            cout << "Too low. ";
        } else {
            cout << "Too high. ";
        }

        
        if (currentDifference == 1) {
            cout << "Super close!" << endl;
        } else if (currentDifference <= 5) {
            cout << "Very warm." << endl;
        } else if (currentDifference <= 10) {
            cout << "Warm." << endl;
        } else if (currentDifference <= 20) {
            cout << "Cool." << endl;
        } else {
            cout << "Very cold." << endl;
        }

        
        if (attempts > 1) {
            if (currentDifference < prevDifference) {
                cout << " You're getting closer!" << endl;
            } else if (currentDifference > prevDifference) {
                cout << " You're getting farther away!" << endl;
            } else {
                cout << " Same as last time." << endl;
            }
        }

        
        prevDifference = currentDifference;
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}
