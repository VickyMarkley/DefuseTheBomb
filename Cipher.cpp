#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// --- MODULE A: WIRE LOGIC (Vectors & Randomness) ---
bool wireModule() {
    vector<string> wires = {"Red", "Blue", "Green", "Yellow"};
    srand(time(0));
    int explosiveIndex = rand() % 4;
    int choice;

    cout << "\n[MODULE 1: THE WIRES]" << endl;
    cout << "Wires available: 0:Red, 1:Blue, 2:Green, 3:Yellow" << endl;
    cout << "Selection: ";
    cin >> choice;

    if (choice < 0 || choice > 3 || choice == explosiveIndex) return false;
    return true;
}

// --- MODULE B: KEYPAD (Loops & Logic) ---
bool keypadModule() {
    int code = 1234;
    int guess;
    cout << "\n[MODULE 2: KEYPAD]" << endl;

    for (int i = 3; i > 0; i--) {
        cout << "Enter 4-digit code (" << i << " attempts left): ";
        cin >> guess;
        if (guess == code) return true;
    }
    return false;
}

// --- MODULE C: CIPHER (Strings & Chars) ---
bool cipherModule() {
    string key = "DECODE";
    string guess;
    cout << "\n[MODULE 3: WORD CIPHER]" << endl;
    cout << "Decipher the keyword (Hint: It starts with 'D'): ";
    cin >> guess;
    return (guess == key);
}

// --- MODULE D: MATH CHECK ---
bool mathModule() {
    int answer;
    int question = rand() % 4;

    cout << "\n[MODULE 4: MATH CHECK]" << endl;

    if (question == 0) {
        cout << "Solve this problem: 7 * 6 = ";
        cin >> answer;
        if (answer == 42) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else if (question == 1) {
        cout << "Solve this problem: 15 - 8 = ";
        cin >> answer;
        if (answer == 7) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else if (question == 2) {
        cout << "Solve this problem: 9 + 5 = ";
        cin >> answer;
        if (answer == 14) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else if (question == 3) {
        cout << "Solve this problem: 12 / 3 = ";
        cin >> answer;
        if (answer == 4) {
            cout << "Correct!" << endl;
            return true;
        }
    }

    cout << "Wrong answer!" << endl;
    return false;
}

// --- MODULE E: MEMORY TEST ---
bool memoryModule() {
    int guess;

    cout << "\n[MODULE 5: MEMORY TEST]" << endl;
    cout << "Remember this number: 5821" << endl;
    cout << "Enter the number: ";
    cin >> guess;

    if (guess == 5821) {
        cout << "Correct memory!" << endl;
        return true;
    }

    cout << "Incorrect!" << endl;
    return false;
}