#include <iostream>
#include <vector>

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
