// Copyright 2021 <Your name here>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::string;
using std::ifstream;

void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end);

int main(int argc, char **argv) {
  string puzzleFileName;
  string wordsFileName;
  vector<vector<char>> puzzle;
  vector<string> words;
  if (argc != 3) {
    cout << "Usage: ./sub2 puzzle.txt words.txt\n";
    exit(0);
  }
  puzzleFileName = argv[1];
  wordsFileName = argv[2];
  readPuzzle(puzzle, puzzleFileName);
  readWords(words, wordsFileName);
  printPuzzle(puzzle);
  printWords(words);

  for (auto word : words) {
    vector<int> start;
    vector<int> end;
    bool found;
    found = findWord(puzzle, word, start, end);
    printLocation(word, start, end, found);
    end.clear();
    start.clear();
  }
  return 0;
}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
  ifstream in(filename);
  string line, splitLine;
  puzzle.resize(3);
  if (in.is_open()) {
    int i = 0;
    while (getline(in, line)) {
      std::stringstream string(line);
      int j = 0;
      puzzle[i].resize(4);
      while (getline(string, splitLine, '\t')) {
        puzzle[i][j] = splitLine[0];
        j++;
      }
      i++;
    }
  }
  in.close();
}

void readWords(vector<string> &words, string filename) {
    return;
}

void printPuzzle(const vector<vector<char>> &puzzle) {
  for (vector<char> vect : puzzle) {
    for (char i : vect) {
      cout << i << " ";
    }
    cout << "\n";
  }
}

void printWords(const vector<string> &words) {
    return;
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
    return;
}

bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
    return false;
}
