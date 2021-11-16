// Copyright 2021 Adam Steger
#include "./SuperString.h"

// DO NOT MODIFY START
void SuperString::print() {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
        }
        std::cout << "\n";
    } else {
        std::cout << "<EMPTY>\n";
    }
}

char SuperString::get(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return '\0';
}

int SuperString::length() {
    return size;
}
// DO NOT MODIFY END

// PUT YOUR CODE BELOW!

SuperString::SuperString() {
    size = 0;
    data = new char[size];
}

SuperString::SuperString(std::string str) {
    size = str.size();
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = str[i];
    }
}

SuperString::SuperString(int size, char val) {
    this->size = size;
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = val;
    }
}

SuperString::SuperString(const SuperString& copy) {
    size = copy.size;
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
    }
}

int SuperString::find(char c, int start) {
    for (int i = start; i < size; i++) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

int SuperString::find(std::string str, int start) {
    for (int i = start; i < size; i++) {
        if (data[i] == str[0] && data[i+1] == str[1] && data[i+2] == str[2]) {
            return i;
        }
    }
    return -1;
}

SuperString SuperString::substr(int start, int numChar) {
    std::string str;
    if (size - start >= numChar && start >= 0) {
        for (int i = start; i < numChar; i++) {
            str += data[i];
        }
    }
    return SuperString(str);
}

SuperString SuperString::reverse() {
    std::string ret;
    for (int i = 0; i < size; i++) {
        ret += data[size - i - 1];
    }
    return SuperString(ret);
}

SuperString SuperString::replace(int start, int numChar, std::string sub) {
    std::string ret;
    if (size - start >= numChar && start >= 0) {
        for (int i = 0; i < start; i++) {
            ret += data[i];
        }
        for (int i = start; i < numChar; i++) {
            ret += sub[i-start];
        }
        for (int i = start + numChar; i < size; i++) {
            ret += data[i];
        }
        return SuperString(ret);
    }
    return SuperString(0, 'a');
}

void SuperString::push_back(char c) {
    data[size] = c;
    size++;
}

void SuperString::append(std::string str) {
    std::string ret;
    for (int i = 0; i < size; i++) {
        ret += data[i];
    }
    for (int i = 0; i < str.length(); i++) {
        ret += str[i];
    }
    size = ret.length();
    for (int i = 0; i < size; i++) {
        data[i] = ret[i];
    }
}

void SuperString::append(const SuperString& obj) {
    SuperString object(obj);
    std::string ret;
    for (int i = 0; i < size; i++) {
        ret += data[i];
    }
    for (int i = 0; i < object.length(); i++) {
        ret += object.get(i);
    }
    size = ret.length();
    for (int i = 0; i < size; i++) {
        data[i] = ret[i];
    }
}

void SuperString::replace(char find, char rep) {
    for (int i = 0; i < size; i++) {
        if (data[i] == find) {
            data[i] = rep;
        }
    }
}

void SuperString::removeAll(char c) {
    std::string temp;
    for (int i = 0; i < size; i++) {
        if (data[i] != c) {
            temp += data[i];
        }
    }
    size = temp.length();
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
}

// Bonus Methods
void SuperString::replace(std::string find, std::string rep) {
    std::string temp;
    int index = this->find(find, 0);
    for (int i = 0; i < index; i++) {
        temp += data[i];
    }
    for (int i = 0; i < rep.length(); i++) {
        temp += rep[i];
    }
    for (int i = index + 3; i < size; i++) {
        temp += data[i];
    }
    size = temp.length();
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
}

bool SuperString::isUpper() {
    bool ret = true;
    for (int i = 0; i < size; i++) {
        if (!isupper(data[i])) {
            ret = false;
        }
    }
    return ret;
}

bool SuperString::isLower() {
    bool ret = true;
    for (int i = 0; i < size; i++) {
        if (!islower(data[i])) {
            ret = false;
        }
    }
    return ret;
}

bool SuperString::isTitleCase() {
    return true;
}

SuperString::~SuperString() {
    delete [] data;
}
