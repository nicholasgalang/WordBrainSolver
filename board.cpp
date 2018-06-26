#include "board.hpp"



Board::Board (char* filename) {
	ifstream myfile;
  myfile.open (filename);
  char line[9][9];
  int counter=0;
  while(myfile >> line[counter]){
  	counter++;
  	
  }
   myfile.close();
  counter=0;
  int dimension;
  for(int i=0;i<9;i++){

  	bool empty= (line[0][i]=='\0');
  	if(empty){
  		dimension=counter;
  		break;
  	}
  	counter++;
  }


  //letters=new char[dimension][dimension];
  letters.resize(dimension, std::vector<char>(dimension, 'a'));


  for(int i=0;i<dimension;i++){
  	for(int j=0;j<dimension;j++){
  		letters[i][j]=line[i][j];
  		std::cout<<letters[i][j];
  	}
  	  std::cout<<std::endl;
  }

  int numOfWords=0;
  while(line[dimension][numOfWords]!='\0')
  	numOfWords++;


   for(int i=0;i<numOfWords;i++){
   	lengths.push_back(line[dimension][i]-'0');
   	std::cout<<lengths[i];
   }
    std::cout<<std::endl;
 
}