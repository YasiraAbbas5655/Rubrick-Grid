#include <stdio.h>
#include <iostream>
#include <fstream>
#include "RubiksGrid.h"
#include "GameSolver.h"


void main()
{
	
	int i;
	/*RubiksGrid final(3,3),initial(3,3);

	final.Read("final.txt");
	initial.Read("initial.txt");
	RubiksGrid *ptr = &initial;

	BlockNO b[]={A,B,C,D,A,A,B,D};
	Direction directions[]={RIGHT,LEFT,LEFT,LEFT,RIGHT,RIGHT,RIGHT,RIGHT};

	for(i=0;i<5;++i)
	{

		ptr->Print();
		ptr = ptr->Rotate(directions[i],b[i]);
		ptr->Print();
	}*/

	RubiksGrid obj1(3,3);
	RubiksGrid obj2(3,3);
	//obj1.Print();
	//obj2.Print();
	obj1.Read("Test1.txt");
	obj2.Read("Test2.txt");
	//obj1.Print();
	//obj2.Print();
	
	Game_solver gs(obj1,obj2);
	gs.make_a_graph();
	int x;
	cout<<"Press 1 to print path to goal using Stack"<<endl<<"Press 2 to print path to goal using Queue"<<endl;
	cin>>x;
	
	if (x==1)
	{
		gs.print_path_to_goal_usingStack();
	}
	if (x==2)
	{
	gs.print_path_to_goal_usingQueue();
	}
	cin >> i;

}
