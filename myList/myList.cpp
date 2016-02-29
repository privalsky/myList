// myList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using std::string;

template <typename T> class List;

template <typename T> struct Node
{
private:
	Node(const T& value) : iValue(value), iNext(0) {}
	T iValue;
	Node * iNext;

	friend class List<T>;
};

template <typename T> class List
{
public:
	List() :iHead(0), iTail(0) {}

	void push(T& newValue)
	{
		if (iHead == 0) {
			iHead = new Node<T>(newValue);
			//iHead->iValue = newValue;
			//iHead->iNext = 0;
			iTail = iHead;
			return;
		}

		Node<T> *newNode = new Node<T>(newValue);
		//newNode->iValue = newValue;
		//newNode->iNext = 0;

		/*Node<T> *oldiTail = iTail;
		oldiTail->iNext = newNode;
		iTail = newNode;*/

		iTail->iNext = newNode;
		iTail = newNode;

		return;		
	}


	void reverse()
	{
		
		
		if (iHead == iTail) return;

		Node<T> *temp1 = iHead;
		Node<T> *temp2 = temp1->iNext;
		temp1->iNext = 0;

		while (temp2) {
			Node<T> *temp3 = temp2->iNext;
			temp2->iNext = temp1;
			temp1 = temp2;
			temp2 = temp3;
		}
		iTail = iHead;
		iHead = temp1;
		
	}

	void coupledReverse()
	{
		if (iHead == iTail) return;

		Node<T> *temp1 = iHead;
		Node<T> *temp2 = temp1->iNext;
		Node<T> *temp4 = 0;

		iHead = temp2;

		do
		{
			Node<T> *temp3 = temp2->iNext;
			

			temp2->iNext = temp1;
			temp1->iNext = temp3;
			temp1 = temp3;

			if (temp4) temp4->iNext = temp2;
			temp4 = temp2->iNext;
			
			
			if (!temp3) return;
			if(!(temp2 = temp3->iNext)) return;
			

		} while (temp2);

		iTail = temp1;
		return;
	}

private:
	Node<T> *iHead;
	Node<T> *iTail;
};


template<typename T> void f(T arg)
{
	printf("general call\n");

}

template<>
void f(long arg)
{
	printf("explicit call\n");

}

template<typename T> class ChildList;

template<typename T> void f1(T* arg)
{
	printf("general call\n");
	
}

template<>
void f1(ChildList<int>* arg)
{
	printf("explicit call\n");
	
}

template <typename T> class ChildList:public List<T> {};


int _tmain(int argc, _TCHAR* argv[])
{

	int i = 0;
	f(i);
	ChildList<int>* myChildList=0;
	f1(myChildList);


	

	//Node<string> myNode1,myNode2;
	List<string> myList;
	string myString1 = "HZ1", myString2 = "HZ2", myString3 = "HZ3", myString4 = "HZ4";
	myList.push(myString1);
	myList.push(myString2);
	myList.push(myString3);
	//myList.push(myString4);

	myList.reverse();

	List<int> myListInt;
	for (int i = 0; i < 5;)
	myListInt.push(++i);

	myListInt.coupledReverse();

	//myNode1.iValue = "first";
	//myNode2.iValue = "second";
	//myNode1.iNext = &myNode2;
	//myNode2.iNext = 0;

	for (int a = 1; a <= 1; a++) { std::cout << a++; std::cout << a; }

	return 0;
}

