#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    
    // Initialize variables
    int guess;
    int attempts = 0;
    
    // Game loop
    while (true) {
        // Ask the user to guess the number
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> guess;
        
        // Increment attempts counter
        attempts++;
        
        // Check if the guess is correct
        if (guess == randomNumber) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
            break;
        } else if (guess < randomNumber) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Too high. Try again." << std::endl;
        }
    }
    
    return 0;
}
