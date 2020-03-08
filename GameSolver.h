#include <iostream>
#include "stacks.h"
#include "rubiksgrid.h"
#include <queue>


class myNode
{
public:
	
	myNode()
	{
		current=new RubiksGrid(3,3);
		for(int i=0;i<8;i++)
		{
			
			child[i]=nullptr;
		}

	}
	myNode(RubiksGrid temp)
	{
		current=new RubiksGrid(3,3);
		*current =temp;
		current->parent=temp.parent;
		current->dirn=temp.dirn;
		current->blk=temp.blk;
		for(int i=0;i<8;i++)
		{
			
			child[i]=nullptr;
		}

	}
private:
	int node_num;
	RubiksGrid * current;
	myNode * child[8];
	friend class Game_solver;

};


class Game_solver
{
public:
	Game_solver()
	{
		curr_node_no=0;
		index=-1;
		initial=nullptr;
		final_=nullptr;
	}
	Game_solver(RubiksGrid item1,RubiksGrid item2)
	{
		curr_node_no=0;
		index=-1;
		initial=new myNode(item2);
		//initial->current->Print();
		final_=new myNode(item1);
		//final_->current->Print();
	}
	void make_a_graph()
	{
		if (initial->current==final_->current)
		{
			return;
		}
		add_visited(*(initial->current));
		myNode * temp=initial;
		temp->node_num=curr_node_no;
		RubiksGrid * curr=new RubiksGrid(3,3);
		bool visited;
		BlockNO b[]={A,A,B,B,C,C,D,D};
		Direction directions[]={RIGHT,LEFT,RIGHT,LEFT,RIGHT,LEFT,RIGHT,LEFT};
		for (int i=0;i<8;i++)
		{
			curr=temp->current->Rotate(directions[i],b[i]);
			if (*(curr)==*(final_->current))
			{
				temp->child[i]=new myNode(*(curr));
				curr_node_no++;
				//cout<<curr_node_no;
				temp->child[i]->node_num=curr_node_no;
				return;
			}
			//curr->Print();
			visited=search(*(curr));
			if (!visited)
			{
				add_visited(*(curr));
				temp->child[i]=new myNode(*(curr));
				curr_node_no++;
				temp->child[i]->node_num=curr_node_no;
			}
		}
		int j=1;
		while (*(curr)!=*(final_->current))
		{
			temp=find(j);
			
			if (temp==nullptr)
			{
				j++;

			}
			
			else
			{
				//temp->current->Print();
				for (int i=0;i<8;i++)
				{
					curr=temp->current->Rotate(directions[i],b[i]);
					//curr->Print();
					if (*(curr)==*(final_->current))
					{
						temp->child[i]=new myNode(*(curr));
						curr_node_no++;
						//cout<<curr_node_no;
						temp->child[i]->node_num=curr_node_no;
						return;
					}
					//curr->Print();
					visited=search(*(curr));
					if (!visited)
					{
						add_visited(*(curr));
						temp->child[i]=new myNode(*(curr));
						curr_node_no++;
						//cout<<curr_node_no;
						temp->child[i]->node_num=curr_node_no;
					}
				}
			}
			j++;
		}
	}
	bool insert_at_node(int num)
	{
		myNode *temp=find(num);

		return true;
	}
	myNode * find(int num)
	{
		queue<myNode*> q;
		if (initial)
		{
		q.push(initial);
		}
		while ( ! q.empty() )
		{
			myNode* v = q.front();
			if (v->node_num==num)
			{
				return v;
			}
			if ( v->child[0] != nullptr )
				q.push(v->child[0]);
			if ( v->child[1] != nullptr )
				q.push(v->child[1]);
			if ( v->child[2] != nullptr )
				q.push(v->child[2]);
			if ( v->child[3] != nullptr )
				q.push(v->child[3]);
			if ( v->child[4] != nullptr )
				q.push(v->child[4]);
			if ( v->child[5] != nullptr )
				q.push(v->child[5]);
			if ( v->child[6] != nullptr )
				q.push(v->child[6]);
			if ( v->child[7] != nullptr )
				q.push(v->child[7]);
			q.pop();

		}




	}
	myNode * find_Node(RubiksGrid temp)
	{
		queue<myNode*> q;
		if (initial)
		{
		q.push(initial);
		}
		while ( ! q.empty() )
		{
			myNode* v = q.front();
			if (*(v->current)==temp)
			{
				return v;
			}
			if ( v->child[0] != nullptr )
				q.push(v->child[0]);
			if ( v->child[1] != nullptr )
				q.push(v->child[1]);
			if ( v->child[2] != nullptr )
				q.push(v->child[2]);
			if ( v->child[3] != nullptr )
				q.push(v->child[3]);
			if ( v->child[4] != nullptr )
				q.push(v->child[4]);
			if ( v->child[5] != nullptr )
				q.push(v->child[5]);
			if ( v->child[6] != nullptr )
				q.push(v->child[6]);
			if ( v->child[7] != nullptr )
				q.push(v->child[7]);
			q.pop();

		}




	}
	void add_visited(RubiksGrid item)
	{
		index++;
		visitedArray[index]=new RubiksGrid(3,3);
		*(visitedArray[index])=item;
	}
	bool search(RubiksGrid item)
	{
		for (int i=0;i<index;i++)
		{
			if (*(visitedArray[i])==item)
			{
				return true;
			}
		}
		return false;
	}
	void print_path_to_goal_usingStack()
	{
		stack<RubiksGrid*> parentStack;
		myNode * temp=find(curr_node_no);
		while (temp->current!=initial->current)
		{
			//temp->current->Print();
			parentStack.push((temp->current));
			temp->current=temp->current->parent;
			
		}
		RubiksGrid * temp4;
		int j=parentStack.getIndex();
		for (int i=0;i<j;i++)
		{
			parentStack.pop(temp4);
			cout<<i <<") "<<"Rotate Block NO ";
			temp4->printBlock();
			cout<<" in direction ";
			temp4->printDirn();
			cout<<endl;
		}
	}
	void print_path_to_goal_usingQueue()
	{
		queue<RubiksGrid*> parentStack;
		myNode * temp=find(curr_node_no);
		while (temp->current!=initial->current)
		{
			//temp->current->Print();
			parentStack.push((temp->current));
			temp->current=temp->current->parent;
		}
		RubiksGrid * temp4;
		int j=parentStack.size();
		for (int i=0;i<j;i++)
		{
			temp4=parentStack.front();
			parentStack.pop();
			cout<<i <<") "<<"Rotate Block NO ";
			temp4->printBlock();
			cout<<" in direction ";
			temp4->printDirn();
			cout<<endl;
		}

	}
private:
	int curr_node_no;
	int index;
	myNode * initial;
	myNode * final_;
	RubiksGrid * visitedArray[50000];

};