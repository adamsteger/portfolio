// Copyright 2021 <Your name here>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>


using std::vector;
using std::cout;
using std::string;
using std::ifstream;

void readData(vector<string> &data, string filename);
void printData(const vector<string> &data);
vector<int> findMinHamming(const vector<string> & data, string test);
void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min);

int main(int argc, char **argv) {
  string filename;
  vector<string> data;
  if (argc != 2) {
    cout << "Usage: ./sub1 data.txt\n";
    exit(0);
  }
  filename = argv[1];
  readData(data, filename);
  printData(data);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
  ifstream indata;
  indata.open(filename);
  string val;
  while (!indata.eof()) {
    indata >> val;
    data.push_back(val);
  }
  indata.close();
}

void printData(const vector<string> &data) {
  for (auto i : data) {
    cout << i << "\n";
  }
}

int getHamming(string dataString, string testString) {
  int i = 0, count = 0;
  if (testString.length() > dataString.length()) {
    while (i < testString.length()) {
      if (dataString[i] != testString[i]) {
        count++;
      }
      i++;
    }
  } else {
    while (i < dataString.length()) {
      if (dataString[i] != testString[i]) {
        count++;
      }
      i++;
    }
  }
  return count;
}

vector<int> findMinHamming(const vector<string> & data, string test) {
  vector<int> ret;
  int minHam = 100;
  int index = 0;
  for (int i = 0; i < data.size(); i++) {
    int ham = getHamming(data[i], test);
    if (ham < minHam && ham != 0) {
      minHam = ham;
      index = i;
    }
  }
  ret.push_back(index);
  ret.push_back(minHam);
  return ret;
}

void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {
  cout << "The minimum hamming distance for " << word << " is " << min[1]
      << " (matching word: " << data[min[0]] << ")\n";
}


