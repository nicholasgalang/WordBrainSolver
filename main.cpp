#include <iostream>
#include <fstream>
#include <set>
#include <string>
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
void printVect(const std::vector<std::string> &vector){
	for(int i=0;i<vector.size();i++){
	
			std::cout<<vector[i];
			std::cout<<",";
		
	}
		std::cout<<std::endl;

}

void printSet(const std::set<std::string> &set){
	for (std::set<std::string>::iterator it=set.begin(); it!=set.end(); ++it)
	    std::cout << ' ' << *it;
	std::cout<<"\n";
}

void printSolutions(const std::vector<std::vector<std::string> > solutions){
	for(int i=0;i<solutions.size();i++){
		printVect(solutions[i]);
	}

}

void readDictionary(std::string filename, std::set<std::string> &words){
	ifstream myfile;
	std::string line;

	myfile.open(filename);
	while(myfile >> line){
  		words.insert(line);
  	}
 
  	
  
    myfile.close();


}
Word firstWord(int i,int j,std::vector< std::vector<char> > &letters){
	std::vector<std::vector<int> > path;
	std::vector<int>  tuple;
	tuple.push_back(i);
	tuple.push_back(j);
	path.push_back(tuple);
	//std::string letter;
	//letter.append(letters[i][j]);
	Word emptyWord(&letters[i][j],path);
	return emptyWord;

}

int main () {
	std::set<std::string> dictionary;
	readDictionary("dictionary.txt",dictionary);
	std::cout << dictionary.size()<< std::endl;

	
	

	Board board("board.txt",dictionary);

	//auto const letters=board.getLetters();
	const std::vector<int> lengths=board.getLengths();

	//print2DVect(letters);
	//printVect(lengths);
	board.print();

	std::vector<std::vector<int> > v;
	std::vector<int>  tuple;
	tuple.push_back(2);
	tuple.push_back(1);
	v.push_back(tuple);
	Word emptyWord("b",v);
	std::vector<Word> words;
	board.getWord(lengths[0],emptyWord,2,1,words);
    std::cout<<words.size()<<std::endl;
	words[0].printLetters();
	board.print();
	board.drop(words[0].getPath()).print();
	board.print();

	std::vector<Board> boards;
	std::vector<std::vector<std::string> > solutions;
	int dimension=board.getDimension();

	boards.push_back(board);
	solutions.push_back(std::vector<std::string>());

	for(int l=0;l<lengths.size();l++){
	    std::vector<Board> tempBoards;
	   	std::vector<std::vector<std::string> > tempSolutions;
		for(int b=0;b<boards.size();b++){
			std::vector< std::vector<char> > letters=boards[b].getLetters();
			
			for(int i=0;i<dimension;i++){
				for(int j=0;j<dimension;j++){
					if(letters[i][j]!=0){
						std::vector<Word> words;
						
						boards[b].getWord(lengths[l],firstWord(i,j,letters),i,j,words);

						for(int w=0;w<words.size();w++){
							std::vector<std::string>  tempSolution=solutions[b];
							tempSolution.push_back(words[w].getLetters());
							Board droppedBoard=boards[b].drop(words[w].getPath());
							tempBoards.push_back(droppedBoard);
							tempSolutions.push_back(tempSolution);


						}
					}


				}
			}


		}
		boards=tempBoards;
		solutions=tempSolutions;


	}
	std::cout<<solutions.size()<<std::endl;
	printSolutions(solutions);


  	return 0;
}




