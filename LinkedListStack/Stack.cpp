#include "Stack.h"


void Stack::Push(int value)
{
	auto* temp = new Container(value);
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		Container* point = head;
		while (point->next != nullptr)
		{
			point = point->next;
		}
		point->next = temp;
	}
}

int Stack::Pop()
{
	if (Empty())
	{
		return -1;
	}

	int valueReturn = 0;
	Container* point = head;
	Container* prevPoint = point;

	if (Size() == 1)
	{
		valueReturn = point->value;
		delete point;
		head = nullptr;
		return valueReturn;
	}

	point = point->next;

	while (point->next != nullptr)
	{
		Container* const temp = point;
		point = point->next;
		prevPoint = temp;
	}

	valueReturn = point->value;
	delete point;

	point = nullptr;

	if (point == head)
	{
		head = nullptr;
	}
	else
	{
		prevPoint->next = nullptr;
	}
	return valueReturn;
}

int Stack::Size() const
{
	if (Empty())
	{
		return 0;
	}

	int temp = 1;
	const Container* point = head;
	while (point->next != nullptr)
	{
		point = point->next;
		temp += 1;
	}
	return temp;
}

bool Stack::Empty() const
{
	return head == nullptr;
}

Stack::Iterator Stack::begin()
{
	return Iterator{ head };
}

Stack::Iterator Stack::end()
{
	Container* temp = head;
	while (temp)
	{
		temp = temp->next;
	}
	return Iterator{ temp };
}

Stack::ConstIterator Stack::begin() const
{
	return ConstIterator{ head };
}

Stack::ConstIterator  Stack::end() const
{
	Container* temp = head;
	while (temp)
	{
		temp = temp->next;
	}
	return ConstIterator{ temp };
}
