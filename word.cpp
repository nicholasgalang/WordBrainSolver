#include "word.hpp"

Word::Word(std::string letters1,std::vector<std::vector<int> > path1){
	letters=letters1;
	path=path1;
}

const std::string &Word::getLetters() const{
	return letters;
}
const std::vector<std::vector<int> > &Word::getPath() const{
	return path;
}
bool Word::inPath(int x,int y){
	for(int i=0;i<path.size();i++){
		if(path[i][0]==x && path[i][1]==y)
			return true;
	}
	return false;
}

//make it copy
Word Word::addLetter(int x,int y,char letter){
	std::string tempLetters=letters;
	std::vector<std::vector<int> > tempPath=path;
	tempLetters.push_back(letter);

	std::vector<int> v;
	v.push_back(x);
	v.push_back(y);
	tempPath.push_back(v);
	return Word(tempLetters,tempPath);
}

void Word::printLetters(){
	std::cout<<letters<<std::endl;
}