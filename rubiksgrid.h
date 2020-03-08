#ifndef RUBIKSRubiksGrid_H
#define RUBIKSRubiksGrid_H
#include "stacks.h"
#include <queue>
using namespace std;
enum Direction{LEFT,RIGHT};
enum BlockNO{A,B,C,D};

class RubiksGrid
{
public:
	//write the destructor
	RubiksGrid()
	{
		parent=nullptr;
	}
	/*~RubiksGrid()
	{
		parent=nullptr;
		for (int i=0;i<3;i++)
			delete RubiksGridArray[i];
		delete RubiksGridArray;


	}*/
	RubiksGrid(int Rows,int Cols);
	int TotalColumns(){return cols;}
	int TotalRows(){return rows;}
	void Rotate(Direction direction,int CornerRowIndex,int CornerColIndex);
	RubiksGrid* Rotate(Direction direction,BlockNO) ;
	void Read(char *FileName);
	void Print();
	bool operator == (const RubiksGrid &g);
	bool operator != (const RubiksGrid &g);
	const RubiksGrid & operator = (const RubiksGrid &g);
	RubiksGrid *getParent(){return parent;}
	BlockNO blk;
	Direction dirn;
	void printBlock();
	void printDirn();
private:

	void RotateLeft(int rowIndex,int colIndex);
	void RotateRight(int rowIndex,int colIndex);


	int rows, cols;
	int **RubiksGridArray;
	RubiksGrid *parent;
	friend class Game_solver;
	friend class myNode;
};

class corner
{
public:
	corner(int X,int Y){x = X;y=Y;}
	int x,y;
};



#endif 