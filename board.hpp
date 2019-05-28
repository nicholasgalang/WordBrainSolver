#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <tuple>
#include "word.hpp"

using namespace std;
class Board {
private:
	std::vector< std::vector<char> > letters;
	std::vector<int> lengths;
	std::set<std::string*> dictionary;
	int dimension;


public:
    Board(std::string filename,std::set<std::string*> &dictionary1);
    Board(std::vector< std::vector<char> > &newLetters,std::vector<int> &newLengths,std::set<std::string*> &newDictionary,int newdDimension);
    void print();
   const std::vector< std::vector<char> >& getLetters() const;
   const std::vector<int> &getLengths() const;
   const bool inbounds(int x,int y);
   const int getDimension() const;
   std::set<std::string*> &possibleWords(std::string& start,std::set<std::string*> &filteredDictionary);
   void getWord(int length,Word* word,int x,int y,std::vector<Word*> &words,std::set<std::string*> &filteredDictionary);
   Board* drop(std::vector<std::vector<int> >& path);
   bool InSet(std::string& canidate,std::set<std::string*> &filteredDictionary);
    
};