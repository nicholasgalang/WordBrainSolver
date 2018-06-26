#include <iostream>
#include <fstream>
#include "board.hpp" 
using namespace std;
int main () {
  // ifstream myfile;
  // myfile.open ("board.txt");
  // char line[9][9];
  // int counter=0;
  // while(myfile >> line[counter]){
  // 	counter++;
  	
  // }
  //  myfile.close();
  // counter=0;
  // int length;
  // for(int i=0;i<9;i++){

  // 	bool empty= (line[0][i]=='\0');
  // 	if(empty){
  // 		length=counter;
  // 		break;
  // 	}
  // 	counter++;
  // }


  // char board[length][length];

  // for(int i=0;i<length;i++){
  // 	for(int j=0;j<length;j++){
  // 		board[i][j]=line[i][j];
  // 		std::cout<<board[i][j];
  // 	}
  // 	  std::cout<<std::endl;
  // }

  // counter=0;
  // while(line[length][counter]!='\0')
  // 	counter++;

  //  int lengths[counter];

  //  for(int i=0;i<counter;i++){
  //  	lengths[i]=line[length][i]-'0';
  //  	std::cout<<lengths[i];
  //  }
  //   std::cout<<std::endl;

 Board board("board.txt");



 


  // std::cout << "Exit"<<std::endl;


  return 0;
}

//void readBoard(&)

