#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "./Cipher.cpp"
#include "./Files.cpp"

using namespace std;

// --- FUNCTION PROTOTYPES ---
int main() {
    string teamName;
    double timeLeft = 120.0; // Starting time in seconds
    bool bombExploded = false;

    cout << "=== BOMB DEFUSAL SIMULATOR 2026 ===" << endl;
    cout << "Enter your Team Name: ";
    getline(cin, teamName);

    // Requirement: Streams (Reading from a file)
    showManual();

    cout << "\nTHE TIMER IS TICKING! 120 SECONDS REMAINING." << endl;

    // Requirement: Decision Structures & Functional Decomposition
    if (!wireModule()) bombExploded = true;

    if (!bombExploded && !keypadModule()) bombExploded = true;

    if (!bombExploded && !cipherModule()) bombExploded = true;

    // Final Outcome
    if (bombExploded) {
        cout << "\n*** BOOM! ***\nThe bomb detonated. Mission failed." << endl;
    } else {
        cout << "\n*** SUCCESS! ***\nYou defused the bomb with time to spare!" << endl;
        // Requirement: Streams (Writing to a file)
        saveScore(teamName, timeLeft);
    }

    return 0;
}
