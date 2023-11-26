#pragma once
#pragma once

class Stack
{
public:
	Stack() = default;
	Stack(const Stack& other)
	{
		*this = other;
	}
	void operator= (const Stack& other)
	{
		delete head;
		head = nullptr;
		Container* otherTemp = other.head;
		Container* currentPoint = head;

		for (int i = 0; i < other.Size(); i++)
		{
			auto newPoint = new Container(otherTemp->value);
			if (currentPoint == nullptr)
			{
				head = newPoint;
				currentPoint = head;
			}
			else
			{
				currentPoint->next = newPoint;
				currentPoint = newPoint;
				otherTemp = otherTemp->next;
			}
		}
	}
	~Stack()
	{
		delete head;
	}
public:
	void Push(int val);
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