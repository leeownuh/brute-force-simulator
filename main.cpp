#include <iostream>
#include <string>

using namespace std;

void generatePasswords(const string &characterSet, string currentPassword, const string &targetPassword, int &attemptCount, int maxLength, bool &found);

int main() {
    string targetPassword;
    string characterSet;
    int maxLength;

    cout << "Enter the password to be brute-forced: ";
    cin >> targetPassword;

    cout << "Enter the maximum length for the brute-force attempt: ";
    cin >> maxLength;

    cout << "Choose character set for brute-force attack:" << endl;
    cout << "1. Lowercase letters (a-z)" << endl;
    cout << "2. Lowercase and Uppercase letters (a-z, A-Z)" << endl;
    cout << "3. Letters and digits (a-z, A-Z, 0-9)" << endl;
    cout << "4. Letters, digits, and special characters" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            characterSet = "abcdefghijklmnopqrstuvwxyz";
            break;
        case 2:
            characterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 3:
            characterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            break;
        case 4:
            characterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
            break;
        default:
            cout << "Invalid choice. Using lowercase letters by default." << endl;
            characterSet = "abcdefghijklmnopqrstuvwxyz";
            break;
    }

    // Start brute-force attack
    int attemptCount = 0;
    bool found = false; // Flag to indicate if the password has been found
    generatePasswords(characterSet, "", targetPassword, attemptCount, maxLength, found);

    return 0;
}

void generatePasswords(const string &characterSet, string currentPassword, const string &targetPassword, int &attemptCount, int maxLength, bool &found) {
    // If the current password length exceeds maxLength or password is already found, stop the recursion
    if (currentPassword.length() > maxLength || found) {
        return;
    }

    // Increment the attempt count
    attemptCount++;

    // Check if the generated password matches the target password
    if (currentPassword == targetPassword) {
        cout << "Password found: " << currentPassword << " in " << attemptCount << " attempts!" << endl;
        found = true; // Set the found flag to true
        return;
    }

    // Display the current attempt
    cout << "Attempt #" << attemptCount << ": " << currentPassword << endl;

    // Generate further passwords by appending each character from the character set
    for (char c : characterSet) {
        generatePasswords(characterSet, currentPassword + c, targetPassword, attemptCount, maxLength, found);
    }
}
