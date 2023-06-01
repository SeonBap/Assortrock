#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

// 1. Push_front를 만들어보세요.
// 2. leak 잡으세요

using DataType = int;

class HList
{
private:
	class ListNode
	{
	public:
		DataType Value{};
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};

public:
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}

		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	~HList()
	{
		iterator EraseIter = this->begin();

		while (EraseIter != this->EndNode)
		{
			EraseIter = (*this).erase(EraseIter);
		}

		if (nullptr != StartNode)
		{
			delete StartNode;
		}
		if (nullptr != EndNode)
		{
			delete EndNode;
		}
	}

	// void Push_front를 만들어보세요.
	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* NextNode = StartNode->Next;

		NextNode->Prev = NewNode;
		StartNode->Next = NewNode;

		NewNode->Next = NextNode;
		NewNode->Prev = StartNode;
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	iterator erase(const iterator& _Iter)
	{
		ListNode* Node = _Iter.CurNode;

		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}

		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != Node)
		{
			delete Node;
		}

		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}

private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		std::vector<int> Test;
		std::list<int> NewList;

		for (size_t i = 0; i < 10; i++)
		{
			NewList.push_back(i);
		}

		std::list<int>::iterator StartIter = NewList.begin();
		std::list<int>::iterator EndIter = NewList.end();

		StartIter = NewList.erase(StartIter);

		for (; StartIter.operator!=(EndIter); ++StartIter)
		{
			 std::cout << (*StartIter) << std::endl;
		}
	}

	{
		HList NewList;

		for (int i = 0; i < 10; i++)
		{
			NewList.push_back(i);
		}

		for (int i = 0; i < 10; i++)
		{
			NewList.push_front(i);
		}

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		HList::iterator EraseIter = NewList.begin();

		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;

		EraseIter = NewList.erase(EraseIter);

		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << (*StartIter) << std::endl;

		}
	}
}