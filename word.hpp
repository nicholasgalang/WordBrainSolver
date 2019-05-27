#include <vector>
#include <string>
#include <iostream>


using namespace std;
class Word {
private:
	std::string letters;
	std::vector<std::vector<int> > path;


public:
   Word(std::string letters1,std::vector<std::vector<int> > path1);
   std::string& getLetters();
   std::vector<std::vector<int> > &getPath();
   bool inPath(int x,int y);
   Word addLetter(int x, int y, char letter);
   void printLetters();
   void print();
    
};