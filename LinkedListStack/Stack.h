#pragma once

class Stack
{
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	class Container
	{
	public:
		Container(const int in_value)
			: value(in_value)
		{

		}
		~Container()
		{
			delete next;
		}
		int value;
		Container* next = nullptr;
	};
private:
	Container* head = nullptr;
};