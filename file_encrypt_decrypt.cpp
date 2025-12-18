#include <iostream>
#include <fstream>
using namespace std;

void encryptFile() {
    string inputFile, outputFile;
    char ch;
    int key;

    cout << "\nEnter Input File Name: ";
    cin >> inputFile;
    cout << "Enter Output File Name: ";
    cin >> outputFile;
    cout << "Enter Encryption Key (number): ";
    cin >> key;

    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out) {
        cout << "\nError opening file!\n";
        return;
    }

    while (in.get(ch)) {
        ch = ch + key;
        out.put(ch);
    }

    in.close();
    out.close();

    cout << "\nFile Encrypted Successfully!\n";
}

void decryptFile() {
    string inputFile, outputFile;
    char ch;
    int key;

    cout << "\nEnter Encrypted File Name: ";
    cin >> inputFile;
    cout << "Enter Output File Name: ";
    cin >> outputFile;
    cout << "Enter Decryption Key (same as encryption): ";
    cin >> key;

    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out) {
        cout << "\nError opening file!\n";
        return;
    }

    while (in.get(ch)) {
        ch = ch - key;
        out.put(ch);
    }

    in.close();
    out.close();

    cout << "\nFile Decrypted Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== FILE ENCRYPTION TOOL ======";
        cout << "\n1. Encrypt File";
        cout << "\n2. Decrypt File";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            encryptFile();
            break;
        case 2:
            decryptFile();
            break;
        case 3:
            cout << "\nExiting Program...\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }
    } while (choice != 3);

    return 0;
}
