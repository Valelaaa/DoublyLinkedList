#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;
struct Product
{
	string name = "" ;
	string country = "";
	string fabricator = "";
	string articul = "";
	float cost = 0;
	
	void Print()
	{
		cout << "| " << setw(25) << left << name;
		cout << "  " << setw(17) << left << country;
		cout << "  " << setw(16) << left << fabricator;
		cout << "  " << setw(11) << left << articul;
		cout << "  " << setw(14) << left << cost<< "|\n";
	}
};
struct Node 
{
	Product pro;
	Node* next;
	Node* prev;
};
//Всякие менюшки и визуал
int Menu(int num);
void loading(int n, double f);
int maining(Node &head,Node *tail,int num);
int Finding();
int Redact();
int Sorting();
int Inserting();
int Adding();
int FileReading();
int FileRead();
int Push_back(Node *tail);
void Enter(Node *&node);
void Printf(Node& head);
void TooManyWords(Node &head);
int Push_front(Node& head);
int NodeLen(Node& head);
int NodeFind(Node&head,string str,int op);
int NodeFind(Node& head,float cost);
void NodePrint(Node& head, int numb);
int FileReading();
int Fileadding(Node& head, Node* tail);
int FileAddFirst(Node& head);
int FileAddLast(Node* tail);
int FileFirstUntillN(Node&head);
int FileFirstUntillEnd(Node& head);
int FileBackUntillN(Node* tail);
int FileBackUntillEnd(Node* tail);
void FileRecord(Node& head,string str);
void Rec(Node& head);
int Insert(Node& head, Node* tail,int abs);
int PushFrontUntill(Node& head);
int PushBackUntill(Node* tail);
int NodeEdit(Node& head);
int EditElement(Node& head,int num,int action);
int EditElement(Node& head, int num);
void NodeDelete(Node& head, Node* tail);
int DeleteList(Node& head,Node *tail);
int Swap(Node& head, Node* tail,int n1 = 0, int n2 = 0);
int SortAll(Node& head, Node* tail);
int Sort(Node& head, Node* tail,int iter,int order);
int Barrier(Node& head, Node* tail, Node& barrier, Node* bail);
int MainMenu();
int HereAndThere(Node& head, Node* tail, Node& nead, Node* nail);
int NodeTogether(Node& head, Node* tail, Node& nead, Node* nail);