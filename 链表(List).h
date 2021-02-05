#pragma once
#include<ctime>
#include<cstdlib>

class List
{
	int data;
	List* Next;

	bool GetElem(List L, int i, int* e)//获取链表中第i个节点,并将其数据传递给e
	{
		List* ptr = L.Next;

		for (int counter = 0; counter <= i && ptr; counter++)
		{
			ptr = ptr->Next;
		}

		if (!ptr)
			return 0;
		*e = ptr->data;
		return 1;
	}

	bool NodeInsert(List L, int i, int e)//在链表第i个节点位置插入一个元素,其数据为e
	{
		List* ptr = L.Next;

		for (int counter = 0; counter <= i && ptr; counter++)
		{
			ptr = ptr->Next;
		}

		if (!ptr)
			return 0;
		List* s = new List;
		s->data = e;
		s->Next = ptr->Next;
		ptr->Next = s;
		return 1;
	}

	bool NodeDelete(List L, int i, int* e)//删除链表第i个节点,并将其数据传递给e
	{
		List* ptr = L.Next;

		for (int counter = 0; counter <= i && ptr; counter++)
		{
			ptr = ptr->Next;
		}

		if (!ptr)
			return 0;
		List* ptr_de = ptr->Next;
		ptr->Next = ptr_de->Next;
		*e = ptr_de->data;
		delete(ptr_de);
		return 1;
	}

	void CreatListHead(List* L, int n)//创建一个链表,并生成n个节点(头插法)
	{
		srand(time(0));

		L = new List;
		L->Next = nullptr;

		List* ptr;
		for (int counter = 0; counter < n; counter++)
		{
			ptr = new List;
			ptr->data = 1 + rand() % 100;
			ptr->Next = L->Next;
			L->Next = ptr;
		}
	}

	void CreatListTail(List* L, int n)//(尾插法)
	{
		srand(time(0));

		L = new List;
		L->Next = nullptr;

		List* ptr,*tptr=L;
		for (int counter = 0; counter < n; counter++)
		{
			ptr = new List;
			ptr->data = 1 + rand() % 100;
			tptr->Next = ptr;
			tptr = ptr;
		}	
		ptr->Next = nullptr;
	}

	void ClearList(List* L)
	{
		List* ptr = L->Next , * temp;
		for (; ptr;)
		{
			temp = ptr->Next;
			delete(ptr);
			ptr = temp;
		}
		L->Next = nullptr;
	}


};