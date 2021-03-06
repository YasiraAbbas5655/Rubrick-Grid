#ifndef STACKS_H
#define STACKS_H

const int MAXSIZE = 500;

template <class typeName>
class stack
{
public:
	stack(){index = 0;}
	bool push(typeName item);
	bool pop(typeName &item);
	bool peak(typeName &item);
	bool pop();
	bool empty();  //make the stack empty
	bool full();
	bool search(typeName data);
	void initialize(){index=0;};
	int getIndex()
	{
		return index;
	}
private:
	typeName arr[MAXSIZE];
	int index;
};

template <class typeName>
bool stack<typeName>::empty()
{
	if (index==0)
	{
		return true;
	}
	return false;
}

template <class typeName>
bool stack<typeName>::full()
{
	if (index==MAXSIZE)
	{
		return true;
	}
	return false;
}

template <class typeName>
bool stack<typeName>::push(typeName item)
{
	if (full())
	{
		return false;
	}
	arr[index]=item;
	index++;
	return true;
}

template <class typeName>
bool stack<typeName>::pop(typeName &item)
{
	if(empty())
	{
		return false;
	}
	index--;
	item=arr[index];
	return true;
}

template <class typeName>
bool stack<typeName>::peak(typeName &item)
{
	if(empty())
	{
		return false;
	}
	item=arr[index-1];
}


template <class typeName>
bool stack<typeName>::pop()
{
	if(empty())
	{
		return false;
	}
	index--;
}

template <class typeName>
bool stack<typeName>::search(typeName data)
{

	for (int i=0;i<index;i++)
	{
		if (arr[i]==data)
		{
			return true;

		}
		
	}
	return false;
}

#endif