// Author: Adam Steger
// Email: asteger@email.sc.edu
// Section #: 002
// Copyright 2021 Adam Steger
// Modified from template code @coleca24 GitHub
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;

const int COLS = 4;
const int ROWS = 5;

// TODO(commit 1): Commit #1 functions
void printUsers(const string data[ROWS][COLS]);
bool readUsers(string fh, string data[ROWS][COLS]);
char displayOptions();
bool validateOption(char option);
void executeOption(char option, string data[ROWS][COLS], string fh);
int searchForUser(string name, const string data[ROWS][COLS]);

// TODO(commit 2): Commit #2 functions
int findAllUsers(string title, const string data[ROWS][COLS]);
bool deleteUser(string name, string data[ROWS][COLS], string fh);
string generatePassword();
string generateEmail(string name);
int checkEmpty(const string data[ROWS][COLS]);
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh);


void printUsers(const string data[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

bool readUsers(string fh, string data[ROWS][COLS]) {
    std::ifstream in(fh);
    string line, splitLine;
    if (in.is_open()) {
        int i = 0;
        while (getline(in, line)) {
            std::stringstream string(line);
            int j = 0;
            while (getline(string, splitLine, ',')) {
                data[i][j] = splitLine;
                j++;
            }
            i++;
        }
        in.close();
        return true;
    } else {
        cout << "No File\n";
    }
    return false;
}

char displayOptions() {
    cout << "\nPlease choose one of the following options:\n";
    cout << "P(or p): Print data\n";
    cout << "S(or s): Search data by name\n";
    cout << "F(or f): Find all in data with a certain job title\n";
    cout << "A(or a): Add a new user\n";
    cout << "D(or d): Delete an existing user\n";
    cout << "E(or e): End session\n";
    char option;
    cin >> option;
    if (validateOption(option)) {
        return option;
    } else {
        return 'z';
    }
}
bool validateOption(char option) {
    if (option == 'E' || option == 'e' || option == 'P'
        || option == 'p' || option == 'S' || option == 's'
        || option == 'F' || option == 'f' || option == 'A'
        || option == 'a' || option == 'D' || option ==  'd') {
        return true;
    } else {
        return false;
    }
}

void executeOption(char option, string data[ROWS][COLS], string fh) {
    if (option == 'P' || option == 'p') {
        printUsers(data);
    } else if (option == 'S' || option == 's') {
        string firstName, lastName;
        cout << "Please enter a first name: ";
        cin >> firstName;
        cout << "Please enter a last name: ";
        cin >> lastName;
        int index = searchForUser((firstName + " " + lastName), data);
        if (index >= 0) {
            cout << "User found at index " << index << "\n";
            for (int i = 0; i < COLS; i++) {
                if (i <= 2) {
                    cout << data[index][i] << ", ";
                } else {
                    cout << data[index][i];
                }
            }
        } else {
            cout << "User was not found." << "\n";
        }
    } else if (option == 'F' || option == 'f') {
        string job;
        cout << "Please enter a job title to search for: ";
        cin >> job;
        int count = findAllUsers(job, data);
        cout << "There were " << count << " users with job title " << job;
    } else if (option == 'A' || option == 'a') {
        if (checkEmpty(data) == -1) {
            cout << "Database full (max 5 users)" << "\n";
        } else {
            string firstName, lastName, job;
            cout << "Please enter a first name: ";
            cin >> firstName;
            cout << "Please enter a last name: ";
            cin >> lastName;
            string name = firstName + " " + lastName;
            cout << "Enter Job Title: ";
            cin >> job;
            addUser(checkEmpty(data), name, job, data, fh);
        }
    } else if (option == 'D' || option == 'd') {
        string firstName, lastName;
        cout << "Please enter a first name: ";
        cin >> firstName;
        cout << "Please enter a last name: ";
        cin >> lastName;
        string name = firstName + " " + lastName;
        bool exist = deleteUser(name, data, fh);
        if (!exist) {
            cout << "User " + name + " does not exist.";
        } else {
            cout << "User " + name + " deleted." << "\n";
        }
    }
}

int searchForUser(string name, const string data[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (data[i][0].compare(name) == 0) {
            return i;
        }
    }
    return -1;
}

int findAllUsers(string title, const string data[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (data[i][3].compare(title) == 0) {
            count++;
        }
    }
    return count;
}

bool deleteUser(string name, string data[ROWS][COLS], string fh) {
    bool exist = false;
    for (int i = 0; i < ROWS; i++) {
        if (data[i][0].compare(name) == 0) {
            data[i][0] = "NULL";
            data[i][1] = "NULL";
            data[i][2] = "NULL";
            data[i][3] = "NULL";
            exist = true;
        }
    }
    std::ofstream out(fh);
    if (out.is_open()) {
        int i = 0;
        while (i < ROWS) {
            int j = 0;
            while (j < COLS) {
                if (j < 3) {
                    out << data[i][j] << ",";
                } else {
                    out << data[i][j] << "\n";
                }
                j++;
            }
            i++;
        }
    }
    out.close();
    return exist;
}

string generatePassword() {
    string password;
    int randNum = rand() % 9;
    password = std::to_string(randNum);
    // password = string(intStr);
    int capital = rand() % 25 + 65;
    char c = static_cast<char>(capital);
    password = password + c;
    for (int i = 0; i < 6; i++) {
        int ascii = rand() % 25 + 97;
        char x = static_cast<char>(ascii);
        password = password + x;
    }
    cout << password;
    return password;
}

string generateEmail(string name) {
    string email;
    size_t pos = name.find(" ");
    name.replace(pos, 1, "");
    email = name + "@email.com";
    return email;
}

int checkEmpty(const string data[ROWS][COLS]) {
    int ret = -1;
        for (int i = 0; i < ROWS; i++) {
            if (data[i][0].compare("NULL") == 0) {
                ret = i;
            }
        }
    return ret;
}

void addUser(int index, string name, string title,
                string data[ROWS][COLS], string fh) {
    cout << "Generating email..." << "\n";
    string email = generateEmail(name);
    cout << "\nEmail: " << email;
    cout << "\nGenerating password..." << "\n";
    string password = generatePassword();
    cout << "\nPassword: " << password;
    data[index][0] = name;
    data[index][1] = email;
    data[index][2] = password;
    data[index][3] = title;
    std::ofstream out(fh);
    if (out.is_open()) {
        int i = 0;
        while (i < ROWS) {
            int j = 0;
            while (j < COLS) {
                if (j < 3) {
                    out << data[i][j] << ",";
                } else {
                    out << data[i][j] << "\n";
                }
                j++;
            }
            i++;
        }
    }
    out.close();
}
#endif  // LOGIN_H_
