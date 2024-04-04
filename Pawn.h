class Pawn{ //abstract class
	protected:
		char pawntype;
	public:
		virtual char getPawnType()=0;
};





class XPawn: public Pawn{
	public:
		XPawn();
		char getPawnType();
};


XPawn::XPawn(){
	this->pawntype='X';
}

char XPawn::getPawnType(){
	return this->pawntype;
}





class OPawn: public Pawn{
	public:
		OPawn();
		char getPawnType();
};


OPawn::OPawn(){
	this->pawntype='O';
}

char OPawn::getPawnType(){
	return this->pawntype;
}
