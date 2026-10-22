/*
*number guessing game
*/
#include <iostream>
#include <random>

using namespace std;
int generateRandomNumbers(int min, int max){
    random_device rd; // Obtains random seed from the hardware
    mt19937 gen(rd()); // Initialize the standard mersen_twister_engine with the seed
    uniform_int_distribution<int> distr(min, max); //Define the inclusive range
    int generated_value = distr(gen); //Generate random values
    return generated_value;
}

int main(){
    int random_value = generateRandomNumbers(1,10);
    auto guess_value = 0;
    auto  attempts = 0;

    
    cout << "====WELCOME TO THE RANDOM NUMBER GUESSING GAME====\n";
    cout << "I have picked a random number between 1 and 10\n\n";

    while(1){
        cout <<"Enter your guess: ";
        cin >> guess_value;
         
        if(cin.fail()){
            cout <<"invalid input!, Enter a Number\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        attempts++;

        if(guess_value == random_value){
            cout << "Correct guess! " <<attempts<< " attempts!";
            break; //to exit the loop
        }else if(guess_value < random_value){
            cout << "Too Low\n";
        }else if(guess_value > random_value){
            cout << "Too high\n";
        }
    }

    return 0;
}