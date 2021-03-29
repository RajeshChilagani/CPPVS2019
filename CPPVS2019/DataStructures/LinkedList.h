#pragma once
#include <iostream>
struct Node
{
	int m_Data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList() = default;
	void AddNode(int Data)
	{
		Node* NewNode = new Node{Data,nullptr};
		if (!Head)
		{
			Head = NewNode;
			return;
		}
		Head->next = NewNode;
	}
	void ShowNode()
	{
		if (!IsCircular())
		{
			Node* Temp = Head;
			while (Temp)
			{
				std::cout << Temp->m_Data;
				Temp->next ? printf("->") : 1;
				Temp = Temp->next;
			}
		}
	}

	bool IsCircular()
	{
		if (!Head)
			return false;
		Node* Temp = Head->next;
		while (Temp && Temp!=Head)
		{
			Temp = Temp->next;
		}

		return Temp == Head;
	}

	void MakeCR()
	{
		Node* Temp = Head;
		while (Temp)
		{
			if (!Temp->next)
			{
				Temp->next = Head;
				break;
			}
			Temp = Temp->next;
		}
	}

	~LinkedList()
	{
		while (Head)
		{
			Node* Temp = Head;
			Head = Head->next;
			delete Temp;
		}
	}
	Node* Head;
private:
};

static void  ReverseLL(Node* & Head)
{
	if (!Head)
		return;
	Node* Prev = nullptr;
	Node* Cur = Head;
	Node* Next = Head->next;
	while (Next)
	{
		Cur->next = Prev;
		Prev = Cur;
		Cur = Next;
		Next = Next->next;
	}
	if (Cur)
	{
		Cur->next = Prev;
	}
	Head = Cur;
}

static void TestLinkedlist()
{
	LinkedList LL;
	LL.AddNode(1);
	LL.AddNode(4);
	LL.AddNode(6);
	LL.ShowNode();
	std::cout << LL.IsCircular() << std::endl;;
	ReverseLL(LL.Head);
	LL.ShowNode();
}