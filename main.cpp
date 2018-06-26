#include <iostream>
#include <fstream>
#include "board.hpp" 
using namespace std;

void print2DVect(const std::vector< std::vector<char> >& vector){
	for(int i=0;i<vector.size();i++){
		for(int j=0;j<vector[0].size();j++){
			std::cout<<vector[i][j];
		}
		std::cout<<std::endl;

	}
}

void printVect(const std::vector<int> &vector){
	for(int i=0;i<vector.size();i++){
	
			std::cout<<vector[i];
		
	}
		std::cout<<std::endl;

}

void readDictionary();

int main () {

	Board board("board.txt");

	auto const letters=board.getLetters();
	auto const lengths=board.getLengths();

	print2DVect(letters);
	printVect(lengths);


  	return 0;
}




