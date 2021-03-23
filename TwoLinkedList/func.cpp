#include "header.h"
int maining(Node &head,Node *tail,int num) 
{
	
	do {
		system("cls");
		switch (Menu(num))
		{
		case 1: //������� ��������
		{	system("cls");
		switch (Adding())
		{
		case 1:
		{//������� � ������
			if (Push_front(head))
			{
				cout << "���� �������� ������� !" << endl;
				cout << "���������� ������� ������ " << sizeof(Node) * NodeLen(head) << " ����" << endl; loading(4, 0.4);
			}
			else
				cout << "���� �� ��� ��������!" << endl; loading(3, 0.4);
			break;
		}
		case 2:
		{//������� � �����
			if (Push_back(tail))
			{
				cout << "���� �������� ������� !" << endl;
				cout << "���������� ������� ������ " << sizeof(Node) * NodeLen(head) << " ����" << endl; loading(4, 0.4);
			}
			else
				cout << "���� �� ��� ��������!";
			break;
		}
		case 3:
		{//������� ���������
			system("cls");
			int i = Inserting();
			if (i <= 0 || i > 2)
				break;
				if (Insert(head, tail,i-1)) {
					cout << "���� �������� ������� !" << endl;
					cout << "���������� ������� ������ " << sizeof(Node) * NodeLen(head) << " ����" << endl; loading(4, 0.4);
				}
				else
					cout << "���� �� ��� ��������!";
				break;
		}
		case 4:
		{//��������� ��������� � ������ 
			if (PushFrontUntill(head))
			{

				cout << "������ ������� �������!" << endl;
				cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
				break;
			}
			else
				cout << "������ ��������� �� ����! " << endl; loading(3, 0.4);
			break;
		}
		case 5:
		{//��������� ��������� � �����
			if (PushBackUntill) 
			{
				cout << "������ ������� �������!" << endl;
				cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
				break;
			}
			else
				cout << "������ ��������� �� ����! " << endl; loading(3, 0.4);
			break;
		}
		default: //� �� � ��� �����?
			break;
		}
		break;
		}
		case 2: //������ �� �����
		{
			Fileadding(head, tail);
			break;
		}
		case 3: //������ �� �����
		{
			if (NodeLen(head)<1) 
			{
				cout << "������ ����!" << endl; loading(3, 0.4);
				break;
			}
			TooManyWords(head);
			system("pause");
			break;
		}
		case 4: //������ � ����
		{
			Rec(head);
			break;
		}
		case 5: //�������������� ����
		{
			NodeEdit(head);
			break;
		}
		case 6: //�������� ����
		{
			if (!NodeLen(head))
			{
				cout << "��� ������� ��?" << endl << "������ ����!"; loading(4, 0.4);
				break;
			}
			NodeDelete(head, tail);
			break;
		}
		case 7: //����� ����
		{	
			if (NodeLen(head) < 1)
			{
				cout << "������ 92! ������ �� ����������!" << endl;
				return(92);
			}
			system("cls");
			int g;
			switch (g = Finding()) 
			{
			case 1:
			case 2:
			case 3:
			case 4:
			{
				string staar;
				cin.get();
				cout << "�����: " << endl << ">>> "; getline(cin, staar);
				int cont=NodeFind(head, staar, g);
				cout << "������ ������� ���������� � " << cont<< "-�� ����"<<endl;
				int ch;
				cout << "����������� ������� ?" << endl << "1. - ��" << endl << "2. - ���" << endl;
				cout << ">>> "; if (cin >> ch, !cin.good()) {
					cout << "������, ������� �����!"; loading(4, 0.4); break;
				}
				if (ch == 1)
					NodePrint(head, cont);
				system("pause");
				break;
			}
			case 5:
			{
				float fin;
				cout << "�����: " << endl << "������� �����?" << endl << ">>> ";  assert(cin >> fin);
				int cont = NodeFind(head,fin);
				cout << "������ ������� ���������� � " << cont << "-�� ����";
				int ch;
				cout << "����������� ������� ?" << endl << "1. - ��" << endl << "2. - ���" << endl;
				cout << ">>> "; if (cin >> ch, !cin.good()) {
					cout << "������, ������� �����!"; loading(4, 0.4); break;
				}
				if (ch == 1)
					NodePrint(head, cont);
				system("pause");
				break;
			}
			default: 
				break;
			}
			break;
		}
		case 8: //����� ���� �����
		{
			Swap(head, tail) ? cout << "����� ����� ��������� �������" : cout << "����� ����� �� ���������"; loading(3, 0.5);
			break;
		}
		case 9: //���������� �����
		{
			SortAll(head, tail);
			break;
		}
		case 10: //������� 2][ �������
		{ 
			return(10);
			break;
		}
		case 11: //���������� ������ �� ���
		{
			return(13);
			break;
		}
		case 12: //������������ ������
		{
			DeleteList(head,tail) ? cout << "������ �������!" : cout << "������ �� ���� �������"; loading(4, 0.3);
			break;
		}
		case 13:  //������� � ������� ����
		{
			return(1);
			break;
		}
		default: 
		{
			cout << "����� �� ���� ����� ?"<<endl<<"������ ���"; loading(4, 0.4);
			return(64);
			break;
		}
		}
	} while (true);
	return(0);//��� �� ���� ������ �����?
}

void loading(int n, double f)
{	//�������� �������� � n ����� � f ������ �������
	for (int i = 0; i < n; i++)
	{
		cout << "."; Sleep(1000 * f);;
	}
	return;
}
int Menu(int num)
{
	int choise;
	cout << "-----------------------------------------" << endl;
	cout << "|     ������ " << num << "                          | " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| 1  - ������� ����                     |" << endl
		<< "| 2  - ��������� �� �����               |" << endl
		<< "| 3  - ������ �� �����                  |" << endl
		<< "| 4  - ������ � ����                    |" << endl
		<< "| 5  - ������������� ����               |" << endl
		<< "| 6  - ������� ����                     |" << endl
		<< "| 7  - ����� ����                       |" << endl
		<< "| 8  - ����� ���� �����                 |" << endl
		<< "| 9  - ���������� �����                 |" << endl
		<< "| 10 - ������� ���� �������             |" << endl
		<< "| 11 - ���������� ������ �� ���         |" << endl
		<< "| 12 - ������������ ������              |" << endl
		<< "| 13 - ������� ����                     |" << endl;
	cout << "-----------------------------------------" << endl << endl;
	cout << ">>> "; if (cin >> choise, !cin.good()) 
	{
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Finding()
{
	int choise;
	cout << "�������������������������������������" << endl;
	cout << "|   �������� �������� ������:       |" << endl;
	cout << "�������������������������������������" << endl;
	cout << "| 1. - ����� �� ����� ������        |" << endl;
	cout << "| 2. - ����� �� ������ ������������ |" << endl;
	cout << "| 3. - ����� �� �������������       |" << endl;
	cout << "| 4. - ����� �� ��������            |" << endl;
	cout << "| 5. - ����� �� ��������� ������    |" << endl
		<< "| 6. - ��������� �����              |" << endl;
	cout << "�������������������������������������" << endl;
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Redact()
{//� ������� ��������� ������� ������ �������, ������� ���������� ��������������� 
	int var;
	cout << "�������������������������������������" << endl;
	cout << "|   ��� ���������� ������������� ?  |" << endl;
	cout << "�������������������������������������" << endl;
	cout << "| 1. - ������������� ���� �����     |" << endl;
	cout << "| 2. - ������������� ��������       |" << endl;
	cout << "| 3. - ������������� ������         |" << endl;
	cout << "| 4. - ������������� �������������  |" << endl;
	cout << "| 5. - �������������� ��������      |" << endl;
	cout << "| 6. - �������������� ���������     |" << endl;
	cout << "| 7. - ��������� �����              |" << endl;
	cout << "�������������������������������������" << endl;
	cout << ">>> "; if (cin >> var, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return var;
}
int Sorting()
{
	int var;
	cout << "�������������������������������������" << endl;
	cout << "|   ��� ���������� ������������� ?  |" << endl;
	cout << "�������������������������������������" << endl;
	cout << "| 1. - ���������� �� ��������       |" << endl;
	cout << "| 2. - ���������� �� ������         |" << endl;
	cout << "| 3. - ���������� �� �������������  |" << endl;
	cout << "| 4. - ���������� �� ��������       |" << endl;
	cout << "| 5. - ���������� �� ���������      |" << endl;
	cout << "| 6. - ��������� �����              |" << endl;
	cout << "�������������������������������������" << endl;
	cout << ">>> ";
	if (cin >> var, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return(var);
}
int Inserting()
{
	int choise;
	cout << "�������������������������������������" << endl
		<< "|   ��� ���������� ��������      ?  |" << endl
		<< "�������������������������������������" << endl
		<< "| 1. - ������� ����� ��������       |" << endl
		<< "| 2. - ������� ����� ���������      |" << endl
		<< "| 3. - ��������� �����              |" << endl
		<< "�������������������������������������" << endl;
	//������� ����� ��������/����� ��������� 
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Adding() {
	int choise;
	cout << "���������������������������������������������������" << endl
		<< "|   ��� ���������� ��������       ?               |" << endl
		<< "���������������������������������������������������" << endl
		<< "| 1  - ���������� �������� � ������               |" << endl
		<< "| 2  - ���������� �������� � �����                |" << endl
		<< "| 3  - ������� ��������                           |" << endl
		<< "| 4  - ���������� ���������� ���������  � ������  |" << endl
		<< "| 5  - ���������� ���������� ���������  � �����   |" << endl
		<< "| 6  - ��������� �����                            |" << endl
		<< "���������������������������������������������������" << endl;
	//������� ����� ��������/����� ��������� 
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int FileReading()
{
	int choise;
	cout << "���������������������������������������������������" << endl
		<< "|   ��� ���������� ��������       ?               |" << endl
		<< "���������������������������������������������������" << endl
		<< "| 1  - ���������� �������� � ������               |" << endl
		<< "| 2  - ���������� �������� � �����                |" << endl
		<< "| 3  - ������� �������� � ������                  |" << endl
		<< "| 4  - ������� ���������� ��������� � ������      |" << endl
		<< "| 5  - ���������� ���������� ���������  � ������  |" << endl
		<< "| 6  - ���������� ���������� ���������  � �����   |" << endl
		<< "| 7  - ��������� �����                            |" << endl
		<< "���������������������������������������������������" << endl
		<< ">>> "; if (cin >> choise, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int FileRead()
{
	int choise;
	cout << "����������������������������������������������������������������" << endl
		<< "|  ������� ��������� ���������� ��������       ?               |" << endl
		<< "����������������������������������������������������������������" << endl
		<< "| 1  - ���������� ���������� ����������� ���������             |" << endl
		<< "| 2  - ���������� ���� ��������� �� �����                      |" << endl
		<< "����������������������������������������������������������������" << endl
		<< ">>> "; if (cin >> choise, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int MainMenu() {
	int var;
	cout << "�������������������������������������" << endl;
	cout << "|           ������� ����            |" << endl;
	cout << "�������������������������������������" << endl;
	cout << "| 1. - ������ ������                |" << endl;
	cout << "| 2. - ������ ������                |" << endl;
	cout << "| 3. - ���������� ���������         |" << endl;
	cout << "�������������������������������������" << endl;
	cout << ">>> "; if (cin >> var, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	return(var);
}

int Push_back(Node *tail) 
{
	Node* node;
	node = new Node();
	node->prev = tail->prev;
	tail->prev->next = node;
	tail->prev = node;
	node->next = tail;
	cout << "���� ����:" << endl;
	cin.get();
	Enter(node);
	return(1);
}
int Push_front(Node& head) 
{
	Node* node;
	node = new Node();
	head.next->prev = node;
	node->next = head.next;
	head.next = node;
	node->prev = &head;
	cout << "���� ����:" << endl;
	cin.get();
	Enter(node);
	return(1);
}
void Enter(Node *&node) 
{
	cout << "��������: "; getline(cin,node->pro.name);
	cout << "������: "; getline(cin, node->pro.country);
	cout << "�������������: "; getline(cin, node->pro.fabricator);
	cout << "��������: "; getline(cin, node->pro.articul);
	cout << "���������: "; assert(cin >> node->pro.cost && "����� ������ ���� ���� �����");
}
void Printf(Node& head) 
{
	Node *node;
	node = head.next;
	while (node->next)
	{
		node->pro.Print();
		node = node->next; 
	} 
}
void TooManyWords(Node &head) {
	cout << "|�����������������������������������������������";
	cout << "���������������������������������������������|\n";
	cout << "|" << setw(53) << right << "Count of products : ";
	cout << setw(3) << left << NodeLen(head);
	cout << "                                    |\n";
	cout << "|�����������������������������������������������";
	cout << "���������������������������������������������|\n";
	cout << "| Name                     | Country          |";
	cout << " Fabricator      | Articul    | Cost          |\n";
	cout << "|����������������������������������������������";
	cout << "����������������������������������������������|\n";
	Printf(head);
	cout << "|����������������������������������������������";
	cout << "����������������������������������������������|\n";
}

int NodeLen(Node& head) 
{
	if (head.next == NULL)
		return(0);
	Node* node;
	int count=0;
	node = head.next;
	while (node->next) 
	{
		count++;
		node = node->next;
	}
	return(count);
}
int NodeFind(Node& head,string str,int op) 
{
	if (op < 1 && op > 5) 
	{
		cout << "����� �������� ���";
		return(0);
	}
	Node* node = head.next;
	int count=0;
	if (op == 1) 
	{
		while (node->next) 
		{
			count++;
			if (node->pro.name == str)
				return count;
			node = node->next;
		}
		cout << "������ �������� ���"; loading(3, 0.4); return(0);
	}
	else if (op == 2) 
	{
		while (node->next)
		{
			count++;
			if (node->pro.country == str)
				return count;
			node = node->next;
		}
		cout << "����� ������ ���"; loading(3, 0.4); return(0);
	}
	else if (op == 3) 
	{
		while (node->next)
		{
			count++;
			if (node->pro.fabricator == str)
				return count;
			node = node->next;
		}
		cout << "������ ������������� ���"; loading(3, 0.4); return(0);
	}
	else 
	{
		while (node->next)
		{
			count++;
			if (node->pro.articul == str)
				return count;
			node = node->next;
		}
		cout << "������ ������� ���"; loading(3, 0.4); return(0);
	}
}
int NodeFind(Node&head,float cost) 
{
	int count = 0;
	Node* node=head.next;
	while (node) 
	{
		count++;
		if (node->pro.cost == cost)
			return(count);
		node = node->next;
	}
	cout << "����� ��������� ���!"; loading(3, 0.4); return(0);
}
void NodePrint(Node& head, int numb)
{
	Node* p;
	p = head.next;
	int num = 0;
	cout << "|�����������������������������������������������";
	cout << "���������������������������������������������|\n";
	while (p)
	{
		num++;
		if (num == numb)
		{
			p->pro.Print();
		}
		p = p->next;
	}
	cout << "|�����������������������������������������������";
	cout << "���������������������������������������������|\n";
	return;
}
int Fileadding(Node& head, Node* tail) 
{
	system("cls");
	switch (FileReading())
	{
	case 1://������ ������ �� �����
	{
		if (!FileAddFirst(head))
			break;
		cout << "�������� ��������� �������" << endl;
		cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
		break;
	}
	case 2://������ ��������� �������
	{
		if (!FileAddLast(tail))
			break;
		cout << "�������� ��������� �������" << endl;
		cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
		break;
	}
	case 5:
	{

		system("cls");
		switch (FileRead())
		{
		case 1:
		{
			if (!FileFirstUntillN(head))
				break;
			cout << "������ ������� �������!" << endl;
			cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
			return(1);
		}
		case 2:
		{
			if (!FileFirstUntillEnd(head))
				break;
			cout << "������ ������� �������!" << endl;
			cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
			return(1);
		}
		default:
		{
			cout << "������ �������� �� ����!"; loading(3, 0.4);
			break;
		}
		}
		case 6:
		{
			system("cls");
			switch (FileRead())
			{
			case 1:
			{
				if (!FileBackUntillN(tail))
					break;
				cout << "������ ������� �������!" << endl;
				cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
				return(1);
			}
			case 2:
			{
				if (!FileBackUntillEnd(tail))
					break;
				cout << "������ ������� �������!" << endl;
				cout << "����� ����������� ������ ���������� " << NodeLen(head) * sizeof(Node) << " ����"; loading(4, 0.4);
				
				return(1);
			}
			default:
			{
				cout << "������ �������� �� ����!"; loading(4, 0.4);
				break;
			}
			break;
			}
			break;
		}
	case 7:
		break;
	}
	}
	return(0);
}
int FileAddFirst(Node& head)
{
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	Node* node;
	node = new Node();
	getline(file, node->pro.name);
	getline(file, node->pro.country);
	getline(file, node->pro.fabricator);
	getline(file, node->pro.articul);
	(file >> node->pro.cost).get();
	string space;
	getline(file, space); 
	head.next->prev = node;
	node->next = head.next;
	head.next = node;
	node->prev = &head;
	file.close();									//��������� ����
	return 1;
}
int FileAddLast(Node*tail) 
{
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	Node* node;
	node = new Node();
	getline(file, node->pro.name);
	getline(file, node->pro.country);
	getline(file, node->pro.fabricator);
	getline(file, node->pro.articul);
	(file >> node->pro.cost).get();
	string space;
	getline(file, space);
	node->prev = tail->prev;
	tail->prev->next = node;
	tail->prev = node;
	node->next = tail;
	file.close();									//��������� ����
	return 1;
}
int FileFirstUntillN(Node& head) 
{
	int n = 0;
	cout << "������� ��������� ���������� ���������? " << endl << ">>> "; if (cin >> n, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	if (n < 1) {
		cout << "������! ����������� ��������� ������ ���� ������ 0" << endl;
		return(0);
	}
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	for (int i = 0; i < n && file; i++)
	{
		Node* node;
		node = new Node();
		getline(file, node->pro.name);
		getline(file, node->pro.country);
		getline(file, node->pro.fabricator);
		getline(file, node->pro.articul);
		(file >> node->pro.cost).get();
		string space;
		getline(file, space);
		head.next->prev = node;
		node->next = head.next;
		head.next = node;
		node->prev = &head;
	}
	file.close();
	return 1;
}
int FileFirstUntillEnd(Node &head) 
{
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	while(file){
		Node* node;
		node = new Node();
		getline(file, node->pro.name);
		getline(file, node->pro.country);
		getline(file, node->pro.fabricator);
		getline(file, node->pro.articul);
		(file >> node->pro.cost).get();
		string space;
		getline(file, space);
		head.next->prev = node;
		node->next = head.next;
		head.next = node;
		node->prev = &head;
	}
	file.close();
	return 1;
}
int FileBackUntillN(Node* tail) 
{
	int n = 0;
	cout << "������� ��������� ���������� ���������? " << endl << ">>> "; if (cin >> n, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return NULL;
	}
	if (n < 1) {
		cout << "������! ����������� ��������� ������ ���� ������ 0" << endl;
		return(0);
	}
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	for (int i = 0; i < n && file; i++)
	{
		Node* node;
		node = new Node();
		getline(file, node->pro.name);
		getline(file, node->pro.country);
		getline(file, node->pro.fabricator);
		getline(file, node->pro.articul);
		(file >> node->pro.cost).get();
		string space;
		getline(file, space);
		tail->prev->next = node;
		node->prev = tail->prev;
		tail->prev = node;
		node->next = tail;
	}
	file.close();
	return 1;
}
int FileBackUntillEnd(Node* tail) 
{
	int sn;
	string sin;
	cout << endl << "� ������ ����� ���������� ����?" << endl;
	cout << "1. - ���� �� ��������� Input.txt" << endl;
	cout << "2. - ���� �� ��������� Input1.txt" << endl;
	cout << "3. - ��������� ���� (������� ���� � �����������) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "���������� ������ �����!"; return(0);
	}
	if (sn == 1) sin = "Input.txt";
	else if (sn == 2) sin = "Input1.txt";
	else {
		cin.ignore();
		getline(cin, sin);
	}
	ifstream file(sin);
	if (!file.is_open())
	{
		cout << "������! ���� �� ������!" << endl;
		return 0;
	}
	while (file)
	{
		Node* node;
		node = new Node();
		getline(file, node->pro.name);
		getline(file, node->pro.country);
		getline(file, node->pro.fabricator);
		getline(file, node->pro.articul);
		(file >> node->pro.cost).get();
		string space;
		getline(file, space);
		tail->prev->next = node;
		node->prev = tail->prev;
		tail->prev = node;
		node->next = tail;
	}
	file.close();
	return 1;
}
void FileRecord(Node& head, string str)
{
	ofstream fout;								//��������� ���� ��� ������
	fout.open(str);								//...��������� ���� ...
	if (!fout.is_open())
	{						//���� ���� �� ������, ��������� ���������
		cout << "������ �������� �����" << endl;
		exit(223);
	}
	fout << "|�����������������������������������������������";
	fout << "���������������������������������������������|\n";
	fout << "|" << setw(53) << right << "Count of products : ";
	fout << setw(3) << left << NodeLen(head);
	fout << "                                    |\n";
	fout << "|�����������������������������������������������";
	fout << "���������������������������������������������|\n";
	fout << "| Name                     | Country          |";
	fout << " Fabricator      | Articul    | Cost          |\n";
	fout << "|�����������������������������������������������";
	fout << "���������������������������������������������|\n";
	Node* node;
	node = head.next;
	while (node->next) {
		fout << "| " << setw(25) << left << node->pro.name;
		fout << "| " << setw(17) << left << node->pro.country;
		fout << "| " << setw(16) << left << node->pro.fabricator;
		fout << "| " << setw(11) << left << node->pro.articul;
		fout << "| " << setw(14) << left << fixed << setprecision(0) << node->pro.cost << "|\n";
		node = node->next;
	}

	fout << "|�����������������������������������������������";
	fout << "���������������������������������������������|\n";
	fout.close();
	return;
}
void Rec(Node &head) {
	if (NodeLen(head) < 1)
	{
		cout << "������! ������ �� ����������!"; loading(3, 0.6);
		return;
	}
	int h;
	cout << "�������� ���� ������ �����: " << endl;
	cout << "1 - ��������� � ���� Output.txt" << endl;
	cout << "2 - ������� ������ ���� ����� (��� ������� � � �����������)" << endl;
	cout << ">>> ";
	if (cin >> h, !cin.good()) {
		cout << "������, ������� �����!"; loading(4, 0.4); return;
	}
	if (h <= 0 || h > 2) return;
	if (h == 2)
	{
		cin.get();
		string strt;
		cout << "������� ���� �����:"; getline(cin, strt);
		FileRecord(head, strt);
		cout << "���������� ������ �����"; loading(5, 0.6);
		return;
	}
	else		//���� �� ����� ����������
	{
		FileRecord(head, "Output.txt");
		cout << "���������� ������ �����"; loading(5, 0.6);
		return;
	}
	return;
}
int Insert(Node& head, Node* tail,int abs) 
{
	string name;
	cin.get();
	!abs ? cout << "����� ����� ��������� " : cout << "����� ������ �������� ";
	cout <<"���������� ������?" << endl << ">>> "; getline(cin, name);
	int to;
		if (!abs)
			to = NodeFind(head,name, 1);
		else
			to = NodeFind(head,name, 1)+1;
	if (!to) {
		cout << "������ �������� ���" << endl; loading(4, 0.3);
		return(0);
	}
	Node* node; 
		int count = 0;
		node = head.next;
		while (node->next) {
			count++;
			if (count == to)
				break;
			node = node->next;
		}
		Node* New = new Node(), * temp;
		cout << "���� ����:" << endl;
		Enter(New);
		temp = node->prev;
		node->prev = New;
		New->prev = temp;
		temp->next = New;
		New->next = node;
		return(1);
	return(0);
}
int PushFrontUntill(Node& head) 
{
	system("cls");
	int n;
	cout << "������� ����� ���������� ������?" << endl << ">>> ";
	if (cin >> n, n>0 && !cin.good()) {
		cout << "��� ������ ���� ������ ������ ����!";
		return(0);
	}
	for (int i = 0; i < n; i++) {
		Node* node;
		node = new Node();
		head.next->prev = node;
		node->next = head.next;
		head.next = node;
		node->prev = &head;
		cout << "���� ���� "<<i<<": " << endl;
		cin.get();
		Enter(node);
		cout << endl;
	}
	return(1);
}
int PushBackUntill(Node* tail) {
	system("cls");
	int n;
	cout << "������� ����� ���������� ������?" << endl << ">>> ";
	if (cin >> n, n > 0 && !cin.good()) {
		cout << "��� ������ ���� ������ ������ ����!";
		return(0);
	}
	for (int i = 0; i < n; i++) {
		Node* node;
		node = new Node();
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
		node->next = tail;
		cout << "���� ����:" << endl;
		cin.get();
		Enter(node);
		cout << endl;
	}
	return(1);
}
int NodeEdit(Node&head) 
{
	Node* node;
	node = head.next;
	if (NodeLen(head) <1) {
		cout << "������ ����"; loading(3, 0.4);
		return(0);
	}
	int nam;    //����� ������� �����������
	string namae;
	cin.get();
	cout << "����� ������� �������������?" << endl << ">>> "; getline(cin, namae);
	if (!(nam = NodeFind(head, namae, 1)+1))
		return(0);
	system("cls");
	int var;    //������� ��� ������ ��������
	var = Redact();
	switch (var)
	{
	case 1:
	{
		EditElement(head, nam);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 2:
	{
		EditElement(head, nam, var);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 3:
	{
		EditElement(head, nam, var);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 4:
	{
		EditElement(head, nam, var);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 5:
	{

		EditElement(head, nam, var);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 6:
	{

		EditElement(head, nam, var);
		cout << "������� ��������������"; loading(3, 0.4);
		break;
	}
	case 7:
		break;
	default:
	{
		cout << "������ ��������� �� ����"; loading(3, 0.4);
		break; }
	}
	return(0);
}
int EditElement(Node& head, int num)
{
	Node* node;
	node = &head;
	int coutn = 0;
	while (node)
	{
		coutn++;
		if (coutn == num)
		{
			cin.get();
			Enter(node);
			return(1);
		}
		node = node->next;
	}
	return(0);
}
int EditElement(Node& head, int num, int action)
{
	if (action < 1 || action>6)
	{
		cout << "������ �������� �� ����������";
		return(0);
	}
	int cot = 0;
	Node* node;
	node = &head;
	cin.get();
	if (action == 2)
	{
		while (node)
		{
			cot++;
			if (cot == num) {
				cout << "��������: ";  getline(cin, node->pro.name);
			}
			node = node->next;
		}
		return(1);
	}
	else if (action == 3)
	{
		while (node)
		{
			cot++;
			if (cot == num) {
				cout << "������: ";  getline(cin, node->pro.country);
			}
			node = node->next;
		}
		return(1);
	}
	else if (action == 4)
	{
		while (node)
		{
			cot++;
			if (cot == num) {
				cout << "�������������: ";  getline(cin, node->pro.fabricator);
			}
			node = node->next;
		}
		return(1);
	}
	else if (action == 5)
	{
		while (node)
		{
			cot++;
			if (cot == num) {
				cout << "�������: ";  getline(cin, node->pro.articul);
			}
			node = node->next;
		}
		return(1);
	}
	else
	{
		while (node)
		{
			cot++;
			if (cot == num) {
				cout << "���������: ";  cin >> node->pro.cost;
			}
			node = node->next;
		}
		return(1);
	}
	return(0);
}
void NodeDelete(Node& head, Node* tail)
{
	string str;
	cin.get();
	cout << "����� ������� ���������� �������?" << endl << ">>> "; getline(cin, str);
	int n = NodeFind(head, str, 1);
	int count=0;
	Node* node;
	node = head.next;
	while (node->next) 
	{
		count++;
		if (count == n)
			break;
		node = node->next;
	}
	if (count == 0) 
	{
		node = head.next;
		head.next = node->next; // ������� ������ �������
		if (head.next)
			head.prev = NULL;
		else tail = NULL; // ������� ������������ �������
	}
	else 
	{
		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		else tail = NULL; // ������� ��������� �������
	}
	delete node;
	cout << "���� ������� ������"; loading(4, 0.3);
}
int DeleteList(Node& head,Node *tail)
{
	Node* node;
	while (head.next)
	{
		node = &head;
		while (node->next->next)
			node = node->next;
		free(node->next);
		node->next = NULL;
	}
	head.next = tail;
	if (head.next)
		return 0;
	return 1;
}
int Swap(Node& head, Node* tail, int n1, int n2)
{
	if (NodeLen(head) < 1)
	{
		cout << "������ �� ����������!"; loading(3, 0.4);
		return(0);
	}
	if (!n1 && !n2) {
		string first, second;
		cin.get();
		cout << "������ �������: " << endl << ">>> "; getline(cin, first);
		n1 = NodeFind(head, first, 1);
		cout << "������ �������: " << endl << ">>> "; getline(cin, second);
		n2 = NodeFind(head, second, 1);
		if (n1 == n2)
		{
			cout << "������, ��� ���� � ��� �� ������� !"; loading(4, 0.3); return 0;
		}
		if (n2 < n1)
		{
			int tmp = n2;
			n2 = n1;
			n1 = tmp;
		}
	}
	Node* a, * b;
	int max = NodeLen(head);
	Node* node;
	node = head.next;
	if (n2 == n1 + 1)
	{
		int coutn1 = 0;
		a = head.next;
		while (a->next) {
			coutn1++;
			if (coutn1 == n1)
				break;
			a = a->next;
		}
		b = head.next;
		coutn1 = 0;
		while (b->next) {
			coutn1++;
			if (coutn1 == n2)
				break;
			b = b->next;
		}
		b->next->prev = a;
		a->prev->next = b;
		b->prev = a->prev;
		a->next = b->next;
		a->prev = b;
		b->next = a;
		return 1;
	}
	else
	{
		int coutn1 = 0;
		a = head.next;
		while (a->next) {
			coutn1++;
			if (coutn1 == n1)
				break;
			a = a->next;
		}
		b = head.next;
		coutn1 = 0;
		while (b->next) {
			coutn1++;
			if (coutn1 == n2)
				break;
			b = b->next;
		}
		a->next->prev = b;
		b->next->prev = a;
		a->prev->next = b;
		b->prev->next = a;
		Node* temp = a->next;
		a->next = b->next;
		b->next = temp;
		temp = a->prev;
		a->prev = b->prev;
		b->prev = temp;
		return 1;
	}

	return 0;
}
int SortAll(Node& head, Node* tail) 
{
	if (!NodeLen(head))
	{
		cout << "������ ����!" << endl << "��� ������ ����������� !"; loading(5, 0.4);
		return(0);
	}
	system("cls");
	int choice;
	switch (choice = Sorting() )
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			int crt;
			cout << "��� ���������� �����������?" << endl << " 1 - �� �����������" << endl
				<< " 2 - �� ��������" << endl << ">>> "; if (cin >> crt, !cin.good())
			{
				cout << "���������� ������ �����!"<<endl; loading(4, 0.4); break;
			}
			if (crt < 1 || crt > 2) {
				cout << "������ �������� ���������� �� ����!"<<endl; loading(4, 0.4);
				break;
			}
			if (crt == 1)
				Sort(head,tail,choice,1);
			else
			    Sort(head,tail, choice,2);
			cout << "������ ������� ������������"; loading(4, 0.4);
			break;
		}
	}
}
int Sort(Node& head, Node* tail, int iter, int order) 
{
	int n = NodeLen(head);
	if (order == 1)
	{
		if (iter == 1) //�� �������� �� �����������
		{
			for (int i = 0; i < n ; i++)
			for (int i = 1; i < n ; i++)
			{
				Node* node1 = head.next, * node2 = head.next->next;
				for (int j = 1; j <= n && node2->next; j++)
				{
					if (node1->pro.name > node2->pro.name)
					{
						Swap(head, tail, j, j + 1);
					}
					node1 = node1->next;
					node2 = node2->next;
				}
			}
			return 1;
		}
		if (iter == 2)// �� ������ �� �����������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j <= n && node2->next; j++)
					{
						if (node1->pro.country > node2->pro.country)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 3)//�� ������������� �� �����������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j <= n && node2->next; j++)
					{
						if (node1->pro.fabricator > node2->pro.fabricator)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 4) //�� ������� �� �����������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j <= n && node2->next; j++)
					{
						if (node1->pro.articul > node2->pro.articul)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 5)//�� ���� �� �����������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j <= n && node2->next; j++)
					{
						if (node1->pro.cost > node2->pro.cost)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
	}
	else
	{
		if (iter == 1) // �� ����� �� ��������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j < n && node2->next; j++)
					{
						if (node1->pro.name < node2->pro.name)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 2) //�� ������ �� ��������
		{

			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j < n && node2->next; j++)
					{
						if (node1->pro.country < node2->pro.country)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 3)//�� ������������� �� ��������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j < n && node2->next; j++)
					{
						if (node1->pro.fabricator < node2->pro.fabricator)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 4) //�� ������� �� ��������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j < n && node2->next; j++)
					{
						if (node1->pro.articul < node2->pro.articul)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
			return 1;
		}
		if (iter == 5) //�� ���� �� ��������
		{
			for (int i = 0; i < n; i++)
				for (int i = 1; i < n; i++)
				{
					Node* node1 = head.next, * node2 = head.next->next;
					for (int j = 1; j < n && node2->next; j++)
					{
						if (node1->pro.cost < node2->pro.cost)
						{
							Swap(head, tail, j, j + 1);
						}
						node1 = node1->next;
						node2 = node2->next;
					}
				}
		}
		return 1;
	}
	return(0);
}
int Barrier(Node& head,Node*tail, Node& barrier,Node *bail) 
{
	int n;
	string str;
	cin.get();
	cout << "������� ������, � �������� �������� ������ ������: " << endl << ">>> ";
	getline(cin, str);
	n = NodeFind(head, str, 1);
	Node* node;
	Node* bar;
	int count = 0;
	node = head.next;
	bar = barrier.next;
	while (node->next) 
	{
		count++;
		if (count >= n) 
		{
			node->prev->next = tail;
			tail->prev = node->prev;
			Node* temp = bar->prev->next;
			bar->prev->next = node;
			node->prev = temp;
			return(1);
		}
		node = node->next;
	}
	return(0);
}
int HereAndThere(Node& head, Node* tail, Node& nead, Node* nail) 
{
	int n = NodeLen(head);
	for (int i = 0; i < n / 2; i++) {
		Node* node = head.next;
		Node* here = head.next;
		Node* there = nead.next;
		int Annie = 1;
		while (node->next)
		{
			Annie = -Annie;
			if (Annie > 0)
			{
				here = node;
				Node* temp = here;
				here->next->prev = here->prev;
				here->prev->next = here->next;
				temp->prev = nail->prev;
				nail->prev->next = temp;
				nail->prev = temp;
				temp->next = nail;
				continue;
			}
			node = node->next;
		}
	}
	return(1);
}
int NodeTogether(Node& head, Node* tail, Node& nead, Node* nail)
{
	Node* hode=head.next;
	Node* node=nead.next;
	if ((node->pro.name < node->next->pro.name) && (hode->pro.name < hode->next->pro.name))
	{
		while (node->next) 
		{
			if (hode->pro.name > node->pro.name) {
				nead.next->next->prev = &nead;
				nead.next = nead.next->next;
				node->next = hode;
				node->prev = hode->prev;
				hode->prev->next = node;
				hode->prev = node;
				node = nead.next;
				continue;
			}
			else 
			{
				hode = hode->next;
				node = nead.next;
			}
		}
	}
	else if ((node->pro.name > node->next->pro.name) && (hode->pro.name < hode->next->pro.name))
	{
		node = nail->prev;
		while (node->prev)
		{
			if (hode->pro.name > node->pro.name) {
				nail->prev->prev->next = nail;
				nail->prev = nail->prev->prev;
				node->next = hode;
				node->prev = hode->prev;
				hode->prev->next = node;
				hode->prev = node;
				node = nail->prev;
				continue;
			}
			else
			{
				hode = hode->next;
				node = nail->prev;
			}
		}
	}
	else if ((node->pro.name < node->next->pro.name) && (hode->pro.name > hode->next->pro.name))
	{
		hode = tail->prev;
		node = nail->prev;
		while (node->prev)
		{
			if (hode->pro.name < node->pro.name) {
				nail->prev->prev->next = nail;
				nail->prev = nail->prev->prev;
				node->prev = hode;
				node->next = hode->prev;
				hode->next->prev = node;
				hode->next = node;
				node = nail->prev;
				continue;
			}
			else
			{
				hode = hode->prev;
				node = nail->prev;
			}
		}
	}
	else if ((node->pro.name > node->next->pro.name) && (hode->pro.name > hode->next->pro.name))
	{
		while (node->next)
		{
			if (hode->pro.name < node->pro.name) {
				nead.next->next->prev = &nead;
				nead.next = nead.next->next;
				node->next = hode;
				node->prev = hode->next;
				hode->prev->next = node;
				hode->prev = node;
				node = nead.next;
				continue;
			}
			else
			{
				hode = hode->next;
				node = nead.next;
			}
		}
	}
	return(1);
}