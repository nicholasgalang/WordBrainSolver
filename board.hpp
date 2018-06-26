#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Board {
private:
	std::vector< std::vector<char> > letters;
	std::vector<int> lengths;


public:
    Board(char* filename);
    
};