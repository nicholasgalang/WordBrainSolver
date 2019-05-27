#include "board.hpp"



const std::vector< std::vector<char> > &Board::getLetters() const{
	return letters;
}

std::set<std::string> &Board::possibleWords(std::string &start,std::set<std::string> &filteredDictionary){

  std::set<std::string> *newDict=new  std::set<std::string>();
  //std::cout<<"Filtering Dictionary"<<std::endl;
    //std::cout<<filteredDictionary.size()<<std::endl;
  // for (std::set<std::string>::iterator it=filteredDictionary.begin(); it!=filteredDictionary.end(); ++it){
  //   if(start.compare(it->substr(0,start.size()))==0){
  //     //std::cout<<"Possilbe word: "<<*it<<std::endl;
  //     newDict->insert(*it);  
  //   }

  // }
  for(auto word:filteredDictionary){
    if(word.substr(0,start.size())==start)
       newDict->insert(word);  
  }
   //std::cout<<3<<std::endl;

  return *newDict;

   

}

const std::vector<int> &Board::getLengths() const{
  return lengths;
}
const int Board::getDimension() const{
  return dimension;
}

const bool Board::inbounds(int x,int y){
  if(x<0 || y<0 || x>=dimension || y>=dimension )
    return false;
  return true;
}

Board Board::drop(std::vector<std::vector<int> > path){

  std::vector< std::vector<char> > newLetters=letters;
  std::vector<int> newLengths=lengths;
  for(int i=0;i<path.size();i++){
    newLetters[path[i][0]][path[i][1]]=0;
  }

//std::cout<<newLetters[0][1]<<std::endl;
  for(int i=0;i<newLetters.size();i++){
    for(int j=0;j<newLetters[i].size();j++){
      if(newLetters[i][j]==0){
        int temp=i;
        //std::cout<<2<<std::endl;
        while(temp-1>-1 && newLetters[temp-1][j]!=0){
          //std::cout<<2<<std::endl;
          newLetters[temp][j]=newLetters[temp-1][j];
          newLetters[temp-1][j]=0;
          temp-=1;
        }

      }
    }
  }

  //std::cout<<newLetters[0][1]<<std::endl;
  return *(new Board(newLetters,newLengths,dictionary,dimension));

} 


void Board::getWord(int length,Word& word,int x,int y,std::vector<Word> &words,std::set<std::string> &filteredDictionary){
  //std::cout<<word.getLetters()<<std::endl;
  //word.print();
  //exit(0);
  if(length==word.getLetters().size()){
    if(filteredDictionary.count(word.getLetters())>0){
     // std::cout<<"Found a word"<<std::endl;
      //std::vector<Word> temp=*(new std::vector<Word>);
      //temp.push_back(word);
      //word.printLetters();

      words.push_back(word);

      return;
      
    }
    else{
      //return *(new std::vector<Word>());
      return;
      
    }

  }


  //std::vector<Word> output=*(new std::vector<Word>);

  //plan to add filter
  for(int i=-1;i<2;i++){
    for(int j=-1;j<2;j++){
      if(!(i==0&&j==0) &&inbounds(x+i,y+j)&&letters[x+i][y+j]!=0&&!word.inPath(x+i,y+j)){
        //std::cout<<"adding a letter to the path"<<std::endl;
        Word newWord=word.addLetter(x+i,y+j,letters[x+i][y+j]);
       
        //filteredDictionary;
     
        std::set<std::string> &newDictionary=possibleWords(newWord.getLetters(),filteredDictionary);
       // std::cout<<"Restricted the dictionary for new path"<<std::endl;
        //std::cout<<"Restricted dictionary size: "<<newDictionary.size()<<std::endl;
        //std::vector<Word> temp=
        if(newDictionary.size()>0)
        getWord(length,newWord,x+i,y+j,words,newDictionary);

        //output.insert(output.end(),temp.begin(),temp.end());




      }
    }
  }

 //return output;

}

Board::Board(std::vector< std::vector<char> > &newLetters,std::vector<int> &newLengths,std::set<std::string> &newDictionary,int newdDimension){
  letters=newLetters;
  lengths=newLengths;
  dictionary=newDictionary;
  dimension=newdDimension;
}
void Board::print(){
  for(int i=0;i<letters.size();i++){
    std::cout<<endl;
    for(int j=0;j<letters.size();j++){

      std::cout<<letters[i][j];
      if(letters[i][j]==0)
        std::cout<<"0";
    }
  }
   std::cout<<endl;
   for(int i=0;i<lengths.size();i++)
    std::cout<<lengths[i];
     std::cout<<endl;
}

Board::Board (std::string filename,std::set<std::string> &dictionary1) {
  dictionary=dictionary1;
 ifstream myfile;
  myfile.open (filename);
  char line[9][9];
  int counter=0;
  while(myfile >> line[counter]){
  	counter++;
  	
  }
   myfile.close();
  counter=0;
  for(int i=0;i<9;i++){

  	bool empty= (line[0][i]=='\0');
  	if(empty){
  		dimension=counter;
  		break;
  	}
  	counter++;
  }

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