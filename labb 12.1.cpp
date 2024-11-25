#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new file
void CreateFile(const string& fileName) {
    ofstream file(fileName, ios::trunc);
    if (!file) {
        cerr << "Error: Unable to create file \"" << fileName << "\".\n";
        return;
    }

    string input;
    double number;

    cout << "Enter numbers to add to the file (type 'end' to stop):\n";
    while (true) {
        cout << "Number: ";
        cin >> input;
        if (input == "end") break;
        number = stod(input);  // Convert the input string to double
        file << number << " ";
    }
    file.close();
}

// Function to find the minimum and maximum numbers in a file
void FindMinMax(const string& fileName, double& minVal, double& maxVal) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Unable to open file \"" << fileName << "\".\n";
        return;
    }

    string line;
    double number;

    // Initialize minVal and maxVal with arbitrary large values
    minVal = 1e9;   // large positive number
    maxVal = -1e9;  // large negative number

    while (file >> number) {
        if (number < minVal) minVal = number;
        if (number > maxVal) maxVal = number;
    }
    file.close();
}

// Function to write the min and max values to a new file
void WriteMinMaxToFile(const string& outputFileName, double minVal, double maxVal) {
    ofstream file(outputFileName, ios::trunc);
    if (!file) {
        cerr << "Error: Unable to create file \"" << outputFileName << "\".\n";
        return;
    }

    file << "Minimum: " << minVal << "\n";
    file << "Maximum: " << maxVal << "\n";
    file.close();
}

// Function to display the content of a file
void DisplayFile(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Unable to open file \"" << fileName << "\".\n";
        return;
    }

    string line;
    cout << "\nContents of \"" << fileName << "\":\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Main function
int main() {
    string inputFileName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    CreateFile(inputFileName);

    double minVal, maxVal;
    FindMinMax(inputFileName, minVal, maxVal);

    WriteMinMaxToFile(outputFileName, minVal, maxVal);

    DisplayFile(outputFileName);

    return 0;
}
