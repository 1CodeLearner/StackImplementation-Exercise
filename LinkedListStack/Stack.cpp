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
	else
	{
		int valueReturn = 0;
		Container* point = head;
		Container* prevPoint = point;

		while (point->next != nullptr)
		{
			point = point->next;
		}

		valueReturn = point->value;
		delete point;

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
