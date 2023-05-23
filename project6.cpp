// Project 6
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <string> // for storing string
#include <fstream> // for reading a file again and again
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Hash function
int hashFunction(const string& str) {
    int hash = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        hash = (hash * 31 + str[i]) % 10007;
    }
    return hash;
}

// Display map
void displayMap(const map<int, vector<string> >& m) {
    for (map<int, vector<string> >::const_iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": ";
        for (vector<string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
            cout << *jt << " ";
        }
        cout << endl;
    }
}

// Display unordered map
void displayUnorderedMap(const unordered_map<int, vector<string> >& um) {
    for (unordered_map<int, vector<string> >::const_iterator it = um.begin(); it != um.end(); ++it) {
        cout << it->first << ": ";
        for (vector<string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
            cout << *jt << " ";
        }
        cout << endl;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    string fileName; // to read in the name of the fileInput from redirected input

    cin >> fileName;
    cout << "Name of fileInput: " << fileName << endl;


    // MAP
    map <int, vector<string> > m1;
    // open a fileName in read mode
    ifstream fI;
    fI.open(fileName);

    char option;
    string temp;
    
    // reading and performing operations
    // start timer
    clock_t start1 = clock();

    while(fI >> option)
    {
        fI >> temp;
        int hash = hashFunction(temp);
        // create the structure - map - m1
        if (option == 'I') {
            m1[hash].push_back(temp);
        }
        if (option == 'R') {
            vector<string>::iterator it = find(m1[hash].begin(), m1[hash].end(), temp);
            if (it != m1[hash].end()) {
                m1[hash].erase(it);
            }
        }
    }
    // stop timer
    clock_t end1 = clock();

    // Display map
    displayMap(m1);

    // close the opened file
    fI.close();

    cout << endl;

    // UNORDERED MAP
    unordered_map<int, vector<string> > m2;
    // open a file again in read mode
    fI.open(fileName);

    // start timer
    clock_t start2 = clock();

    while(fI >> option)
    {
        fI >> temp;
        int hash = hashFunction(temp);
        // create the structure - unordered map - m2
        if (option == 'I') {
            m2[hash].push_back(temp);
        }
        if (option == 'R') {
            vector<string>::iterator it = find(m2[hash].begin(), m2[hash].end(), temp);
            if (it != m2[hash].end()) {
                m2[hash].erase(it);
            }
        }
    }
    // stop timer
    clock_t end2 = clock();

    // Display unordered map
    displayUnorderedMap(m2);

    cout << '\n' << end1 << '\n' << end2 <<"\n\n" << end2 - end1 << endl;

    // close the opened file
    fI.close();

    return 0;
}
