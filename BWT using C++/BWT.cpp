#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct RotationIndex {
    int index;
    string rotation;
};

bool compareSuffix(const RotationIndex& a, const RotationIndex& b) {
    return a.rotation < b.rotation;
}

string burrowsWheelerTransform(const string& text) {
    int n = text.size();
    vector<RotationIndex> rotations(n);

    // Generate indices of cyclic rotations
    for (int i = 0; i < n; ++i) {
        rotations[i].index = i;
        rotations[i].rotation = text.substr(i) + text.substr(0, i);
    }

    // Sort the indices based on the corresponding cyclic rotations using Suffix Array
    sort(rotations.begin(), rotations.end(), compareSuffix);

    // Extract the last characters of each rotation
    string transformedText;
    for (int i = 0; i < n; ++i) {
        transformedText.push_back(rotations[i].rotation[n - 1]);
    }

    return transformedText;
}

int main() {
    int choice;
    cout << "Choose input option:" << endl;
    cout << "1. Enter text manually" << endl;
    cout << "2. Input text from file" << endl;
    cin >> choice;
    string text;
    if (choice == 1) {
        cout << "Enter the text: ";
        cin.ignore(); // Ignore the newline character left by previous cin
        getline(cin, text);
    } else if (choice == 2) {
        string filename;
        cout << "Enter the filename containing the text: ";
        cin >> filename;
        ifstream file(filename.c_str());
        if (!file) {
            cerr << "Error: Unable to open file." << endl;
            return 1;
        }
        string line;
        while (getline(file, line)) {
            text += line;
        }
    } else {
        cerr << "Invalid choice." << endl;
        return 1;
    }
    string bwt = burrowsWheelerTransform(text);
    cout << "Burrows-Wheeler Transform: " << bwt << endl;
    return 0;
}
