#include "Board.h"
#include <iostream>
using namespace std;

class Player{
	public:
		Board *board;
		virtual bool makeMove(char sq)=0; //returns 1 if success move else 0
		virtual bool haveTriple()=0;
		virtual ostream& printMe()=0;
		friend ostream& operator<<(ostream& out, Player& p);
};






class XPlayer: public Player{
	public:
		XPlayer(Board* board);
		bool makeMove(char sq);
		bool haveTriple();	
		ostream& printMe(){
			return(cout<<"X");
		}
		friend ostream& operator<<(ostream& out,Player& p){
			return(p.printMe());
			
		}

	};

XPlayer::XPlayer(Board* board){
	this->board=board;
}

bool XPlayer::haveTriple(){
	return this->board->checkTicTacToe('X');
}




bool XPlayer::makeMove(char sq){
	Pawn *xpawn = new XPawn();
	int row, col;
	switch(sq) {
  		case 'A':
		  	{row=0; col=0;}  
			break;
	  	case 'B':
   			{row=0; col=1;}  
 			break;
  		case 'C':
  			{row=0; col=2;}  
			break;
	  	case 'D':
   			{row=1; col=0;  }
 			break;
  		case 'E':
  			{row=1; col=1;  }
			break;
	  	case 'F':
   			{row=1; col=2;  }
 			break;
  		case 'G':
  			{row=2; col=0;  }
			break;
	  	case 'H':
   			{row=2; col=1;  }
 			break;
  		case 'I':
  			{row=2; col=2;  }
			break;
	  	default:
    		return false;
}
	return(board->placePawn(row, col, xpawn));		//returns true if success else false	
}






class OPlayer: public Player{
	public:
		OPlayer(Board* board);
		bool makeMove(char sq);
		bool haveTriple();	
		ostream& printMe(){
			return cout<<"O";
		}

};


OPlayer::OPlayer(Board* board){
	this->board=board;
}

bool OPlayer::haveTriple(){
	return this->board->checkTicTacToe('O');
}




bool OPlayer::makeMove(char sq){
	Pawn *opawn = new OPawn();
	int row, col;
	switch(sq) {
  		case 'A':
		  	{row=0; col=0;}  
			break;
	  	case 'B':
   			{row=0; col=1;}  
 			break;
  		case 'C':
  			{row=0; col=2;}  
			break;
	  	case 'D':
   			{row=1; col=0;  }
 			break;
  		case 'E':
  			{row=1; col=1;  }
			break;
	  	case 'F':
   			{row=1; col=2;  }
 			break;
  		case 'G':
  			{row=2; col=0;  }
			break;
	  	case 'H':
   			{row=2; col=1;  }
 			break;
  		case 'I':
  			{row=2; col=2;  }
			break;
	  	default:
    		return false;
}
	return(board->placePawn(row, col, opawn));		//returns true if success else false	
}


