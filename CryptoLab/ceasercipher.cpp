#include <iostream>
#include <string>

using namespace std;

// Function to perform Caesar cipher encryption
string caesarEncrypt(const string& message, int shift) {
    string result = "";
    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encrypted_char = (ch - base + shift + 26) % 26 + base;
            result += encrypted_char;
        } else {
            result += ch;
        }
    }
    return result;
}

// Function to perform Caesar cipher decryption
string caesarDecrypt(const string& ciphertext, int shift) {
    // Decryption is the same as encryption, but with a negative shift value
    return caesarEncrypt(ciphertext, -shift);
}

int main() {
    int shift;
    string plaintext, ciphertext;

    // Input from the user
    cout << "Enter an integer value for K (shift value between +/- 26): ";
    cin >> shift;
    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Enter the plaintext message: ";
    getline(cin, plaintext);

    // Encrypt the plaintext using Caesar cipher
    ciphertext = caesarEncrypt(plaintext, shift);

    // Display the encrypted message
    cout << "Encrypted message (Ciphertext): " << ciphertext << endl;

    // Decrypt the ciphertext using Caesar cipher
    string decrypted_text = caesarDecrypt(ciphertext, shift);

    // Display the decrypted message
    cout << "Decrypted message (Original plaintext): " << decrypted_text << endl;

    return 0;
}
