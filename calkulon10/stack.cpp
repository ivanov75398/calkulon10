#include "stack.h"

stack::stack(int _Size)
{
	Size = _Size;
	mem = new int[Size];
	Index = -1;
}

stack::stack(const stack &b)
{
	Size = b.Size;
	mem = new int[Size];
	Index = b.Index;
	for (int i = 0; i < Index; i++)
	{
		mem[i] = b.mem[i];
	}
}

void stack:: push(int val)
{
	if (Index == Size - 1) { throw - 1; }
	Index++;
	mem[Index] = val;
}

int stack:: pop()
{
	if (Index == -1) { throw - 2; }
	Index--;
	return mem[Index + 1];
}

bool stack:: stackFULL()
{
	return (Index == (Size - 1));
}

bool stack:: stackEMPTY()
{
	return (Index == -1);
}

stack &stack:: operator=(const stack &b)
{
	if (this == &b) return *this;
	Size = b.Size;
	Index = b.Index;
	delete[]mem;
	mem = new int[Size];
	for (int i = 0; i < Index; i++)
	{
		mem[i] = b.mem[i];
	}
	return *this;
}