// Copyright 2021 Adam Steger
#include "./ArrayList.h"

template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    os << "[";
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "]";
    return os;
}

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}

template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    setSize(copy.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] data;
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// Start of new functions

template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & rhs) const {
    bool ret = true;
    if (rhs.size != this->size) {
        ret = true;
    } else {
        for (int i = 0; i < size; i++) {
            if (data[i] == rhs[i]) {
                ret = false;
            }
        }
    }
    return ret;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T val) const {
    ArrayList<T> ret(*this);
    for (int i = 0; i < size; i++) {
        ret[i] = data[i] + val;
    }
    return ret;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(const ArrayList<T> & rhs) const {
    if (size == rhs.size) {
        ArrayList<T> ret(*this);
        for (int i = 0; i < size; i++) {
            ret[i] = data[i] + rhs[i];
        }
        return ret;
    }
    return *this;
}

template <class T>
ArrayList<T> & ArrayList<T>::operator--() {
    if (size > 0) {
        ArrayList<T> temp(*this);
        size--;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = temp[i];
        }
    }
    return *this;
}

template <class T>
ArrayList<T> ArrayList<T>::operator--(int) {
    ArrayList<T> temp(*this);
    if (size > 0) {
        size--;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = temp[i];
        }
    }
    return temp;
}

template <class T>
void ArrayList<T>::operator+=(T val) {
    ArrayList<T> temp(*this);
    data = new T[size+1];
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
    data[size] = val;
    size++;
}

template <class T>
void ArrayList<T>::operator+=(const ArrayList<T> & rhs) {
    ArrayList<T> temp(size + rhs.size);
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    for (int i = 0; i < rhs.size; i++) {
        temp[i+size] = rhs[i];
    }
    size += rhs.size;
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
}

template <class T>
ArrayList<T> ArrayList<T>::operator*(int val) const {
    ArrayList<T> temp(size*val);
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    int count = 2;
    int index = size;
    while (count <= val) {
        for (int i = index; i < size*2; i++) {
            temp[i] = data[i-size*(count-1)];
        }
        count++;
        index += size;
    }
    return temp;
}

template <class T>
ArrayList<T> ArrayList<T>::operator/(int val) const {
    ArrayList<T> temp(*this);
    int count = 2;
    while (count <= val) {
        temp.size = temp.size/2;
        count++;
    }
    return temp;
}
