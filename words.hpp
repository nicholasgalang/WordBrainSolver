#include <vector>
#include <string>


using namespace std;
class Word {
private:
	std::string letters;
	std::vector<std::vector<int>> tiles;


public:
   Word(std::string letters1,std::vector<std::vector<int>> tiles1);
   const std::string& getLetters() const;
   const std::vector<std::vector<int>> &getTiles() const;
    
};