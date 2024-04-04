#include "Pawn.h"
#include <iostream>
#include <exception>
#include <string>
using namespace std;
class Board{
	private:
		Pawn *pawn_places[3][3];

	public:
		Board();
		~Board();
		bool placePawn(int row, int col, Pawn* pawn);
		bool  checkTicTacToe(char p);
		void printBoard();
};

//constructor
Board::Board(){
	for(int i=0;i<=2;i++)
		for(int j=0; j<=2;j++)
			pawn_places[i][j]=NULL;	
}
Board::~Board(){}
/*
	returns true if legal move
	false otherwise
*/
bool Board::placePawn(int row, int col, Pawn* pawn){
	if(row>2 || col>2)
		return false;	//do nothing
	else{
//		cout<<(pawn_places[row][col]==NULL)<<"Eeee";
		if((this->pawn_places[row][col])==NULL){
			pawn_places[row][col]=pawn;		
			return true;
		}
		return false;
	}
}

/*
	returns true if we have a win
	false otherwise
*/
bool Board::checkTicTacToe(char pawntype){
	//0-2 rows
	for(int r=0; r<=2; r++)
		if( pawn_places[r][0] && pawn_places[r][1] && pawn_places[r][2] )
			if(pawn_places[r][0]->getPawnType()==pawntype && 
				pawn_places[r][1]->getPawnType()==pawntype &&
				pawn_places[r][2]->getPawnType()==pawntype 
				)
				return true;
	//1st diagonal
	if( pawn_places[0][0] && pawn_places[1][1] && pawn_places[2][2] )
		if(pawn_places[0][0]->getPawnType()==pawntype &&
		pawn_places[1][1]->getPawnType()==pawntype &&
		pawn_places[2][2]->getPawnType()==pawntype 
		)
		return true;
	//2nd diagonal
	if( pawn_places[0][2] && pawn_places[1][1] && pawn_places[2][0] )
		if(pawn_places[0][2]->getPawnType()==pawntype &&
		pawn_places[1][1]->getPawnType()==pawntype &&
		pawn_places[2][0]->getPawnType()==pawntype 
		)
		return true;

	return false;
}


void Board::printBoard(){

	if (pawn_places[0][0] )
		cout<<"\t"<<(pawn_places[0][0]->getPawnType());
	else
		cout<<"\tA";
	if (pawn_places[0][1] )
		cout<<"\t"<<(pawn_places[0][1]->getPawnType());
	else
		cout<<"\tB";
	if (pawn_places[0][2] )
		cout<<"\t"<<(pawn_places[0][2]->getPawnType())<<std::endl;
	else
		cout<<"\tC"<<std::endl;
		

	if (pawn_places[1][0] )
		cout<<"\t"<<(pawn_places[1][0]->getPawnType());
	else
		cout<<"\tD";
	if (pawn_places[1][1] )
		cout<<"\t"<<(pawn_places[1][1]->getPawnType());
	else
		cout<<"\tE";
	if (pawn_places[1][2] )
		cout<<"\t"<<(pawn_places[1][2]->getPawnType())<<std::endl;
	else
		cout<<"\tF"<<std::endl;


	if (pawn_places[2][0] )
		cout<<"\t"<<(pawn_places[2][0]->getPawnType());
	else
		cout<<"\tG";
	if (pawn_places[2][1] )
		cout<<"\t"<<(pawn_places[2][1]->getPawnType());
	else
		cout<<"\tH";
	if (pawn_places[2][2] )
		cout<<"\t"<<(pawn_places[2][2]->getPawnType())<<std::endl;
	else
		cout<<"\tI"<<std::endl;



}
