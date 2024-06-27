#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class GuessingGame {
private:
    int number;
    int userInput;
    int attempt;
public:
    GuessingGame() {
        srand(time(nullptr));
        number = rand() % 100 + 1;
        attempt = 0;
    }
    void takeUserInput() {
        cout << "Guess the number: ";
        cin >> userInput;
        attempt++;
    }
    bool isCorrect() {
        if (userInput == number) {
            cout << "Congratulations! You guessed it right in attempt number " << attempt << ".\n";
            return true;
        } 
        else if (userInput < number) {
            cout << "Too low. Try again.\n";
        } 
        else {
            cout << "Too high. Try again.\n";
        }
        return false;
    }
};

int main() {
    GuessingGame game;
    bool correct = false;
    while (!correct) {
        game.takeUserInput();
        correct = game.isCorrect();
    }
    return 0;
}
