#pragma once
#pragma once

#include <iostream>

class Stack
{
	class Iterator;
	class Container;
public:
	Stack() = default;
	Stack(const Stack& other)
	{
		*this = other;
	}
	void operator= (const Stack& other)
	{
		if (this != &other)
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
	}
	~Stack()
	{
		delete head;
	}

	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;
	Iterator begin();
	Iterator end();

private:
	class Iterator
	{
	public:
		Iterator(Container* temp)
			: ptr(temp)
		{}

		Container& operator*() const
		{
			return *ptr;
		}
		Iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		bool operator!=(const Iterator& other) const
		{
			return ptr != other.ptr;
		}

	private:
		Container* ptr;
	};

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

		Container& operator*=(const int other)
		{
			value *= other;
			return *this;
		}

		friend std::ostream& operator<< (std::ostream& os, const Container& self)
		{
			os << self.value;
			return os;
		}

		int value;
		Container* next = nullptr;
	};
	Container* head = nullptr;
};