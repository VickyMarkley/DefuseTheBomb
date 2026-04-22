#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "./Cipher.cpp"
#include "./Files.cpp"

using namespace std;

// --- FUNCTION PROTOTYPES ---
bool wireModule();
bool keypadModule();
bool cipherModule();
bool mathModule();
bool memoryModule();

void showManual();
void saveScore(string name, double time);

int main() {
    string teamName;
    bool bombExploded = false;

    srand(time(0));
    time_t startTime = time(0);

    cout << "=== BOMB DEFUSAL SIMULATOR 2026 ===" << endl;
    cout << "Enter your Team Name: ";
    getline(cin, teamName);

    // Requirement: Streams (Reading from a file)
    showManual();

    cout << "\nTHE TIMER IS TICKING! 60 SECONDS REMAINING." << endl;

    // Requirement: Decision Structures & Functional Decomposition
    if (!wireModule()) bombExploded = true;
    if (difftime(time(0), startTime) > 60) bombExploded = true;

    if (!bombExploded && !keypadModule()) bombExploded = true;
    if (difftime(time(0), startTime) > 60) bombExploded = true;

    if (!bombExploded && !cipherModule()) bombExploded = true;
    if (difftime(time(0), startTime) > 60) bombExploded = true;

    if (!bombExploded && !mathModule()) bombExploded = true;
    if (difftime(time(0), startTime) > 60) bombExploded = true;

    if (!bombExploded && !memoryModule()) bombExploded = true;
    if (difftime(time(0), startTime) > 60) bombExploded = true;

    if (difftime(time(0), startTime) > 60) {
        cout << "\n*** TIME'S UP! ***" << endl;
        cout << "The bomb exploded because 60 seconds ran out." << endl;
        bombExploded = true;
    }

    // Final Outcome
    if (bombExploded) {
        cout << "\n*** BOOM! ***" << endl;
        cout << "\n*** BOOM! ***\nThe bomb detonated. Mission failed." << endl;
    }
    else {
        time_t endTime = time(0);
        double timeTaken = difftime(endTime, startTime);

        cout << "\n*** SUCCESS! ***" << endl;
        cout << "You defused the bomb!" << endl;
        cout << "Time taken: " << timeTaken << " seconds" << endl;

        saveScore(teamName, timeTaken);;
        return 0;

    }

    return 0;
}
