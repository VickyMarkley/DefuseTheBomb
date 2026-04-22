#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
// --- MODULE A: WIRE LOGIC (Vectors & Randomness) ---
bool wireModule() {
    vector<string> wires = {"red", "blue", "green", "yellow"};
    vector<string> riddles = {
        "I am the color of fire and roses.",
        "I am the color of the sky and ocean.",
        "I am the color of grass and leaves.",
        "I am the color of the sun and bananas."
    };

    int safeIndex = rand() % 4;
    string answer;
    int choice;

    cout << "\n[MODULE 1: THE WIRES]" << endl;
    cout << "Solve the riddle to find the safe wire." << endl;
    cout << "Riddle: " << riddles[safeIndex] << endl;
    cout << "Enter the color (lowercase): ";
    cin >> answer;

    if (answer != wires[safeIndex]) {
        cout << "Wrong answer! You cut the wrong wire!" << endl;
        return false;
    }

    cout << "\nWires available:" << endl;
    cout << "0: Red" << endl;
    cout << "1: Blue" << endl;
    cout << "2: Green" << endl;
    cout << "3: Yellow" << endl;
    cout << "Choose the correct wire number: ";
    cin >> choice;

    if (choice == safeIndex) {
        cout << "Correct wire cut!" << endl;
        return true;
    }

    cout << "Wrong wire!" << endl;
    return false;
}

// --- MODULE B: KEYPAD (Loops & Logic) ---
bool keypadModule() {
    int guess;

    cout << "\n[MODULE 2: KEYPAD]" << endl;
    cout << "Solve the math problems to find the 4-digit code." << endl;

    cout << "Digit 1: 2 + 3 = ";
    cin >> guess;
    if (guess != 5) {
        cout << "Wrong answer!" << endl;
        return false;
    }

    cout << "Digit 2: 9 - 5 = ";
    cin >> guess;
    if (guess != 4) {
        cout << "Wrong answer!" << endl;
        return false;
    }

    cout << "Digit 3: 3 * 2 = ";
    cin >> guess;
    if (guess != 6) {
        cout << "Wrong answer!" << endl;
        return false;
    }

    cout << "Digit 4: 8 / 2 = ";
    cin >> guess;
    if (guess != 4) {
        cout << "Wrong answer!" << endl;
        return false;
    }

    cout << "Enter full 4-digit code: ";
    cin >> guess;

    if (guess == 5464) {
        cout << "Correct keypad code!" << endl;
        return true;
    }

    cout << "Incorrect code." << endl;
    return false;
}

// --- MODULE C: CIPHER (Strings & Chars) ---
bool cipherModule() {
    string guess;

    cout << "\n[MODULE 3: WORD CIPHER]" << endl;
    cout << "Hint: This 6-letter word means to turn secret information back into a readable message." << endl;
    cout << "Enter the keyword: ";
    cin >> guess;

    if (guess == "DECODE" || guess == "decode") {
        cout << "Cipher solved!" << endl;
        return true;
    }

    cout << "Wrong keyword!" << endl;
    return false;
}

// --- MODULE D: MATH CHECK ---
bool mathModule() {
    int answer;
    int q = rand() % 4;

    cout << "\n[MODULE 4: MATH CHECK]" << endl;

    if (q == 0) {
        cout << "7 * 6 = ";
        cin >> answer;
        if (answer == 42) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else if (q == 1) {
        cout << "15 - 8 = ";
        cin >> answer;
        if (answer == 7) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else if (q == 2) {
        cout << "9 + 5 = ";
        cin >> answer;
        if (answer == 14) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    else {
        cout << "12 / 3 = ";
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
    vector<int> numbers;
    int guess;

    cout << "\n[MODULE 5: MEMORY TEST]" << endl;
    cout << "Memorize these numbers:" << endl;

    for (int i = 0; i < 4; i++) {
        numbers.push_back(rand() % 10);
    }

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
        this_thread::sleep_for(chrono::milliseconds(700));
    }

    this_thread::sleep_for(chrono::seconds(2));

    for (int i = 0; i < 40; i++) {
        cout << endl;
    }

    cout << "Now type the numbers in the same order." << endl;

    for (int i = 0; i < numbers.size(); i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> guess;

        if (guess != numbers[i]) {
            cout << "Incorrect!" << endl;
            return false;
        }

        if (i == 0) {
            for (int j = 0; j < 20; j++) {
                cout << endl;
            }
        }
    }

    cout << "Correct memory!" << endl;
    return true;
}