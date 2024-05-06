#include <iostream>
#include <string>
using namespace std;

// Function to prepare the message for encryption
string prepareMessage(string message) {
    string preparedMessage = "";
    // Remove spaces and convert to uppercase
    for (char &c : message) {
        if (isalpha(c)) {
            preparedMessage += toupper(c);
        }
    }
    // Replace 'J' with 'I'
    for (char &c : preparedMessage) {
        if (c == 'J') {
            c = 'I';
        }
    }
    // Adjust the message length if it's odd by adding an 'X' at the end
    if (preparedMessage.length() % 2 != 0) {
        preparedMessage += 'X';
    }
    return preparedMessage;
}

// Function to encrypt the message using the Playfair cipher
string encrypt(string message, string key) {
    // Prepare the message
    message = prepareMessage(message);
    // Create the Playfair matrix
    string matrix = key + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    // Encrypt pairs of letters
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i += 2) {
        char first = message[i];
        char second = message[i + 1];
        int firstPos = matrix.find(first);
        int secondPos = matrix.find(second);
        int firstRow = firstPos / 5;
        int firstCol = firstPos % 5;
        int secondRow = secondPos / 5;
        int secondCol = secondPos % 5;
        if (firstRow == secondRow) {
            firstCol = (firstCol + 1) % 5;
            secondCol = (secondCol + 1) % 5;
        } else if (firstCol == secondCol) {
            firstRow = (firstRow + 1) % 5;
            secondRow = (secondRow + 1) % 5;
        } else {
            swap(firstCol, secondCol);
        }
        encryptedMessage += matrix[firstRow * 5 + firstCol];
        encryptedMessage += matrix[secondRow * 5 + secondCol];
    }
    return encryptedMessage;
}

int main() {
    string message, key;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the key: ";
    getline(cin, key);
    string encryptedMessage = encrypt(message, key);
    cout << "Encrypted message: " << encryptedMessage << endl;
    return 0;
} 
