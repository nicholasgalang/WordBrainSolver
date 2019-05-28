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
void printVect(std::vector<Word*> &vector){
	for(int i=0;i<vector.size();i++){
	
			//std::cout<<vector[i];
			vector[i]->print();
		
		
	}
		std::cout<<std::endl;

}

void printSet(const std::set<std::string> &set){
	for (std::set<std::string>::iterator it=set.begin(); it!=set.end(); ++it)
	    std::cout << ' ' << *it;
	std::cout<<"\n";
}

void printSolutions( std::vector<std::vector<Word*> > solutions){
	for(int i=0;i<solutions.size();i++){
		printVect(solutions[i]);
	}

}
int countCharInString(std::string word,char letter){
	int count=0;
	for(int i=0;i<word.size();i++){
		if(word[i]==letter)
			count++;
	}
	return count;
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
std::set<std::string>& filterDictoinary(std::set<std::string> &oldDict,int length){
	std::set<std::string>* filtertedDict= new std::set<std::string>();
	for(auto word:oldDict){
		if(word.size()==length)
			filtertedDict->insert(word);
	}
	return *filtertedDict;
}
std::set<std::string>& filterDictoinaryBoard(std::set<std::string> &oldDict,std::vector< std::vector<char> > board){
	std::string letters;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){

			letters.push_back(board[i][j]);
		}
	}
	//std::cout<<letters<<std::endl;

	std::set<std::string>* filtertedDict= new std::set<std::string>();
	for(auto word:oldDict){
		bool add=true;
		for(int i=0;i<word.size();i++){
			if(countCharInString(letters,word[i])<countCharInString(word,word[i])){
				add=false;
				break;
			}
			
		}
		if(add)
		filtertedDict->insert(word);
	}
	return *filtertedDict;
}
Word firstWord(int i,int j,std::vector< std::vector<char> > &letters){
	std::vector<std::vector<int> > path;
	std::vector<int>  tuple;
	tuple.push_back(i);
	tuple.push_back(j);
	path.push_back(tuple);
	//std::string letter;
	//letter.append(letters[i][j]);
	Word emptyWord(std::string(1,letters[i][j]),path);
	return emptyWord;

}

int main () {
	std::set<std::string> dictionary;
	readDictionary("words.txt",dictionary);
	std::cout << dictionary.size()<< std::endl;

	
	

	Board board("board.txt",dictionary);

	//auto const letters=board.getLetters();
	const std::vector<int> lengths=board.getLengths();

	//print2DVect(letters);
	//printVect(lengths);
	board.print();
	dictionary=filterDictoinaryBoard(dictionary,board.getLetters());
	std::cout << dictionary.size()<< std::endl;
	// std::cout<<"Where?"<<std::endl;
	// std::vector<std::vector<int> > v;
	// std::vector<int>  tuple;
	// tuple.push_back(2);
	// tuple.push_back(1);
	// v.push_back(tuple);
	// Word emptyWord("b",v);
	// std::vector<Word> words;
	// std::cout<<"entering get Wrod"<<std::endl;
	// board.getWord(lengths[0],emptyWord,2,1,words,dictionary);
	// std::cout<<"Left get Word"<<std::endl;
 //    std::cout<<words.size()<<std::endl;
	// for(int i=0;i<words.size();i++){
	// 	words[i].printLetters();
	// }
	// board.print();
	// board.drop(words[0].getPath()).print();
	// board.print();
	//return 0;

	std::vector<Board*> boards;
	//std::vector<std::vector<std::string> > solutions;
	std::vector<std::vector<Word*> > solutions;
	int dimension=board.getDimension();

	boards.push_back(&board);
	solutions.push_back(std::vector<Word*>());



	for(int l=0;l<lengths.size();l++){
		std::cout<<l<<std::endl;
	    std::vector<Board*> tempBoards;
	   	//std::vector<std::vector<std::string> > tempSolutions;
	   	std::vector<std::vector<Word* > > tempSolutions;
	   	std::set<std::string> filteredDict=filterDictoinary(dictionary,lengths[l]);

		for(int b=0;b<boards.size();b++){
			std::vector< std::vector<char> > letters=boards[b]->getLetters();
			//std::set<std::string>  filteredDict=filterDictoinaryBoard(filteredDict2,letters);
			//std::cout<<filteredDict.size()<<std::endl;
			for(int i=0;i<dimension;i++){
				for(int j=0;j<dimension;j++){
					if(letters[i][j]!=0){
						std::vector<Word*> words;
						Word temp =firstWord(i,j,letters);
						boards[b]->getWord(lengths[l],&temp,i,j,words,filteredDict);

						for(int w=0;w<words.size();w++){
							std::vector<Word*>  tempSolution=solutions[b];
							tempSolution.push_back(words[w]);
							//boards[b].print();
							Board* droppedBoard=boards[b]->drop(words[w]->getPath());
							//droppedBoard.print();
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




