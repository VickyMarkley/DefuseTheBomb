#include <fstream>
#include <iosfwd>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
// --- FILE I/O FUNCTIONS ---
void showManual() { // if manual does not pop up then physically move the manual.txt into cmake-build-debug
    ifstream inFile("manual.txt");
    cout << "\n--- EMERGENCY MANUAL ---" << endl;
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) cout << line << endl;
        inFile.close();
    } else {
        cout << "Manual not found! You're on your own!" << endl;
    }
}

void saveScore(string name, double time) {
    ofstream outFile("leaderboard.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Team: " << name << " | Time: " << time << "s" << endl;
        outFile.close();
        cout << "Score saved to leaderboard.txt" << endl;
    }
}
