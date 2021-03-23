#include "header.h"
int maining(Node &head,Node *tail,int num) 
{
	
	do {
		system("cls");
		switch (Menu(num))
		{
		case 1: //Вставка элемента
		{	system("cls");
		switch (Adding())
		{
		case 1:
		{//Элемент в начало
			if (Push_front(head))
			{
				cout << "Узел добавлен успешно !" << endl;
				cout << "Занимаемая списком память " << sizeof(Node) * NodeLen(head) << " Байт" << endl; loading(4, 0.4);
			}
			else
				cout << "Узел не был добавлен!" << endl; loading(3, 0.4);
			break;
		}
		case 2:
		{//Элемент в конец
			if (Push_back(tail))
			{
				cout << "Узел добавлен успешно !" << endl;
				cout << "Занимаемая списком память " << sizeof(Node) * NodeLen(head) << " Байт" << endl; loading(4, 0.4);
			}
			else
				cout << "Узел не был добавлен!";
			break;
		}
		case 3:
		{//Вставка элементва
			system("cls");
			int i = Inserting();
			if (i <= 0 || i > 2)
				break;
				if (Insert(head, tail,i-1)) {
					cout << "Узел добавлен успешно !" << endl;
					cout << "Занимаемая списком память " << sizeof(Node) * NodeLen(head) << " Байт" << endl; loading(4, 0.4);
				}
				else
					cout << "Узел не был добавлен!";
				break;
		}
		case 4:
		{//Несколько элементов в начало 
			if (PushFrontUntill(head))
			{

				cout << "Данные введены успешно!" << endl;
				cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
				break;
			}
			else
				cout << "Данные добавлены не были! " << endl; loading(3, 0.4);
			break;
		}
		case 5:
		{//Несколько элементов в конец
			if (PushBackUntill) 
			{
				cout << "Данные введены успешно!" << endl;
				cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
				break;
			}
			else
				cout << "Данные добавлены не были! " << endl; loading(3, 0.4);
			break;
		}
		default: //А шо я тут забыл?
			break;
		}
		break;
		}
		case 2: //Читаем из файла
		{
			Fileadding(head, tail);
			break;
		}
		case 3: //Печать на экран
		{
			if (NodeLen(head)<1) 
			{
				cout << "Список пуст!" << endl; loading(3, 0.4);
				break;
			}
			TooManyWords(head);
			system("pause");
			break;
		}
		case 4: //Запись в файл
		{
			Rec(head);
			break;
		}
		case 5: //Редактирование узла
		{
			NodeEdit(head);
			break;
		}
		case 6: //Удаление узла
		{
			if (!NodeLen(head))
			{
				cout << "Что удалить то?" << endl << "Список пуст!"; loading(4, 0.4);
				break;
			}
			NodeDelete(head, tail);
			break;
		}
		case 7: //Поиск узла
		{	
			if (NodeLen(head) < 1)
			{
				cout << "Ошибка 92! Списка не существует!" << endl;
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
				cout << "Поиск: " << endl << ">>> "; getline(cin, staar);
				int cont=NodeFind(head, staar, g);
				cout << "Данный элемент содержится в " << cont<< "-ом узле"<<endl;
				int ch;
				cout << "Распечатать элемент ?" << endl << "1. - Да" << endl << "2. - Нет" << endl;
				cout << ">>> "; if (cin >> ch, !cin.good()) {
					cout << "Ошибка, введите цифру!"; loading(4, 0.4); break;
				}
				if (ch == 1)
					NodePrint(head, cont);
				system("pause");
				break;
			}
			case 5:
			{
				float fin;
				cout << "Поиск: " << endl << "Сколько стоит?" << endl << ">>> ";  assert(cin >> fin);
				int cont = NodeFind(head,fin);
				cout << "Данный элемент содержится в " << cont << "-ом узле";
				int ch;
				cout << "Распечатать элемент ?" << endl << "1. - Да" << endl << "2. - Нет" << endl;
				cout << ">>> "; if (cin >> ch, !cin.good()) {
					cout << "Ошибка, введите цифру!"; loading(4, 0.4); break;
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
		case 8: //Обмен двух узлов
		{
			Swap(head, tail) ? cout << "Обмен узлов произошел успешно" : cout << "Обмен узлов не произошел"; loading(3, 0.5);
			break;
		}
		case 9: //Сортировка узлов
		{
			SortAll(head, tail);
			break;
		}
		case 10: //Слияние 2][ списков
		{ 
			return(10);
			break;
		}
		case 11: //Разделение списка на два
		{
			return(13);
			break;
		}
		case 12: //Освобождение памяти
		{
			DeleteList(head,tail) ? cout << "Память очищена!" : cout << "Память не была очищена"; loading(4, 0.3);
			break;
		}
		case 13:  //Переход в главное меню
		{
			return(1);
			break;
		}
		default: 
		{
			cout << "Зачем ты сюда нажал ?"<<endl<<"Теперь жди"; loading(4, 0.4);
			return(64);
			break;
		}
		}
	} while (true);
	return(0);//Как ты сюда вообще попал?
}

void loading(int n, double f)
{	//Печатает загрузку в n точек и f единиц времени
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
	cout << "|     Список " << num << "                          | " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| 1  - Вставка узла                     |" << endl
		<< "| 2  - Прочитать из файла               |" << endl
		<< "| 3  - Печать на экран                  |" << endl
		<< "| 4  - Запись в файл                    |" << endl
		<< "| 5  - Редактировать узел               |" << endl
		<< "| 6  - Удалить узел                     |" << endl
		<< "| 7  - Поиск узел                       |" << endl
		<< "| 8  - Обмен двух узлов                 |" << endl
		<< "| 9  - Сортировка узлов                 |" << endl
		<< "| 10 - Слияние двух списков             |" << endl
		<< "| 11 - Разделение списка на два         |" << endl
		<< "| 12 - Освобождение памяти              |" << endl
		<< "| 13 - Главное меню                     |" << endl;
	cout << "-----------------------------------------" << endl << endl;
	cout << ">>> "; if (cin >> choise, !cin.good()) 
	{
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Finding()
{
	int choise;
	cout << "—————————————————————————————————————" << endl;
	cout << "|   Выберите параметр поиска:       |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << "| 1. - Поиск по имени товара        |" << endl;
	cout << "| 2. - Поиск по стране производства |" << endl;
	cout << "| 3. - Поиск по производителю       |" << endl;
	cout << "| 4. - Поиск по артикулю            |" << endl;
	cout << "| 5. - Поиск по стоимости товара    |" << endl
		<< "| 6. - Вернуться назад              |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Redact()
{//в главной программе сначала задаем элемент, который необходимо отредактировать 
	int var;
	cout << "—————————————————————————————————————" << endl;
	cout << "|   Что необходимо редактировать ?  |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << "| 1. - Редактировать весь товар     |" << endl;
	cout << "| 2. - Редактировать название       |" << endl;
	cout << "| 3. - Редактировать страну         |" << endl;
	cout << "| 4. - Редактировать производителя  |" << endl;
	cout << "| 5. - Редактирование артикула      |" << endl;
	cout << "| 6. - Редактирование стоимости     |" << endl;
	cout << "| 7. - Вернуться назад              |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << ">>> "; if (cin >> var, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return var;
}
int Sorting()
{
	int var;
	cout << "—————————————————————————————————————" << endl;
	cout << "|   Как необходимо отсортировать ?  |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << "| 1. - Сортировка по названию       |" << endl;
	cout << "| 2. - Сортировка по стране         |" << endl;
	cout << "| 3. - Сортировка по производителю  |" << endl;
	cout << "| 4. - Сортировка по артикулу       |" << endl;
	cout << "| 5. - Сортировка по стоимости      |" << endl;
	cout << "| 6. - Вернуться назад              |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << ">>> ";
	if (cin >> var, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return(var);
}
int Inserting()
{
	int choise;
	cout << "—————————————————————————————————————" << endl
		<< "|   Как необходимо вставить      ?  |" << endl
		<< "—————————————————————————————————————" << endl
		<< "| 1. - Вставка перед заданным       |" << endl
		<< "| 2. - Вставка после заданного      |" << endl
		<< "| 3. - Вернуться назад              |" << endl
		<< "—————————————————————————————————————" << endl;
	//вставка перед заданным/после заданного 
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int Adding() {
	int choise;
	cout << "———————————————————————————————————————————————————" << endl
		<< "|   Как необходимо добавить       ?               |" << endl
		<< "———————————————————————————————————————————————————" << endl
		<< "| 1  - Добавление элемента в начало               |" << endl
		<< "| 2  - Добавление элемента в конец                |" << endl
		<< "| 3  - Вставка элемента                           |" << endl
		<< "| 4  - Добавление нескольких элементов  в начало  |" << endl
		<< "| 5  - Добавление нескольких элементов  в конец   |" << endl
		<< "| 6  - Вернуться назад                            |" << endl
		<< "———————————————————————————————————————————————————" << endl;
	//вставка перед заданным/после заданного 
	cout << ">>> "; if (cin >> choise, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int FileReading()
{
	int choise;
	cout << "———————————————————————————————————————————————————" << endl
		<< "|   Как необходимо добавить       ?               |" << endl
		<< "———————————————————————————————————————————————————" << endl
		<< "| 1  - Добавление элемента в начало               |" << endl
		<< "| 2  - Добавление элемента в конец                |" << endl
		<< "| 3  - Вставка элемента в список                  |" << endl
		<< "| 4  - Вставка нескольких элементов в список      |" << endl
		<< "| 5  - Добавление нескольких элементов  в начало  |" << endl
		<< "| 6  - Добавление нескольких элементов  в конец   |" << endl
		<< "| 7  - Вернуться назад                            |" << endl
		<< "———————————————————————————————————————————————————" << endl
		<< ">>> "; if (cin >> choise, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int FileRead()
{
	int choise;
	cout << "————————————————————————————————————————————————————————————————" << endl
		<< "|  Сколько элементов необходимо добавить       ?               |" << endl
		<< "————————————————————————————————————————————————————————————————" << endl
		<< "| 1  - Добавление введенного колличества элементов             |" << endl
		<< "| 2  - Добавление всех элементов из файла                      |" << endl
		<< "————————————————————————————————————————————————————————————————" << endl
		<< ">>> "; if (cin >> choise, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	return choise;
}
int MainMenu() {
	int var;
	cout << "—————————————————————————————————————" << endl;
	cout << "|           Главное меню            |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << "| 1. - Первый список                |" << endl;
	cout << "| 2. - Второй список                |" << endl;
	cout << "| 3. - Завершение программы         |" << endl;
	cout << "—————————————————————————————————————" << endl;
	cout << ">>> "; if (cin >> var, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
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
	cout << "Ввод узла:" << endl;
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
	cout << "Ввод узла:" << endl;
	cin.get();
	Enter(node);
	return(1);
}
void Enter(Node *&node) 
{
	cout << "Название: "; getline(cin,node->pro.name);
	cout << "Страна: "; getline(cin, node->pro.country);
	cout << "Производитель: "; getline(cin, node->pro.fabricator);
	cout << "Артикуль: "; getline(cin, node->pro.articul);
	cout << "Стоимость: "; assert(cin >> node->pro.cost && "Здесь должно было быть число");
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
	cout << "|———————————————————————————————————————————————";
	cout << "—————————————————————————————————————————————|\n";
	cout << "|" << setw(53) << right << "Count of products : ";
	cout << setw(3) << left << NodeLen(head);
	cout << "                                    |\n";
	cout << "|———————————————————————————————————————————————";
	cout << "—————————————————————————————————————————————|\n";
	cout << "| Name                     | Country          |";
	cout << " Fabricator      | Articul    | Cost          |\n";
	cout << "|——————————————————————————————————————————————";
	cout << "——————————————————————————————————————————————|\n";
	Printf(head);
	cout << "|——————————————————————————————————————————————";
	cout << "——————————————————————————————————————————————|\n";
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
		cout << "Такой операции нет";
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
		cout << "Такого названия нет"; loading(3, 0.4); return(0);
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
		cout << "Такой страны нет"; loading(3, 0.4); return(0);
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
		cout << "Такого производителя нет"; loading(3, 0.4); return(0);
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
		cout << "Такого индекса нет"; loading(3, 0.4); return(0);
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
	cout << "Такой стоимости нет!"; loading(3, 0.4); return(0);
}
void NodePrint(Node& head, int numb)
{
	Node* p;
	p = head.next;
	int num = 0;
	cout << "|———————————————————————————————————————————————";
	cout << "—————————————————————————————————————————————|\n";
	while (p)
	{
		num++;
		if (num == numb)
		{
			p->pro.Print();
		}
		p = p->next;
	}
	cout << "|———————————————————————————————————————————————";
	cout << "—————————————————————————————————————————————|\n";
	return;
}
int Fileadding(Node& head, Node* tail) 
{
	system("cls");
	switch (FileReading())
	{
	case 1://Ввести первый из файла
	{
		if (!FileAddFirst(head))
			break;
		cout << "Значение прочитано успешно" << endl;
		cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
		break;
	}
	case 2://Ввести последний элемент
	{
		if (!FileAddLast(tail))
			break;
		cout << "Значение прочитано успешно" << endl;
		cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
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
			cout << "Данные введены успешно!" << endl;
			cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
			return(1);
		}
		case 2:
		{
			if (!FileFirstUntillEnd(head))
				break;
			cout << "Данные введены успешно!" << endl;
			cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
			return(1);
		}
		default:
		{
			cout << "Такого варианта не было!"; loading(3, 0.4);
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
				cout << "Данные введены успешно!" << endl;
				cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
				return(1);
			}
			case 2:
			{
				if (!FileBackUntillEnd(tail))
					break;
				cout << "Данные введены успешно!" << endl;
				cout << "Общая затраченная память составляет " << NodeLen(head) * sizeof(Node) << " байт"; loading(4, 0.4);
				
				return(1);
			}
			default:
			{
				cout << "Такого варианта не было!"; loading(4, 0.4);
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
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	file.close();									//Закрываем файл
	return 1;
}
int FileAddLast(Node*tail) 
{
	int sn;
	string sin;
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	file.close();									//Закрываем файл
	return 1;
}
int FileFirstUntillN(Node& head) 
{
	int n = 0;
	cout << "Сколько элементов необходимо прочитать? " << endl << ">>> "; if (cin >> n, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	if (n < 1) {
		cout << "Ошибка! Колличество элементов должно быть больше 0" << endl;
		return(0);
	}
	int sn;
	string sin;
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	cout << "Сколько элементов необходимо прочитать? " << endl << ">>> "; if (cin >> n, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return NULL;
	}
	if (n < 1) {
		cout << "Ошибка! Колличество элементов должно быть больше 0" << endl;
		return(0);
	}
	int sn;
	string sin;
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	cout << endl << "С какого файла произвести ввод?" << endl;
	cout << "1. - Файл по умолчанию Input.txt" << endl;
	cout << "2. - Файл по умолчанию Input1.txt" << endl;
	cout << "3. - Кастомный файл (указать путь с расширением) " << endl;
	cout << ">>> "; if (cin >> sn, !cin.good())
	{
		cout << "Необходимо ввести цифру!"; return(0);
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
		cout << "Ошибка! Файл не найден!" << endl;
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
	ofstream fout;								//Открываем файл для записи
	fout.open(str);								//...Открываем файл ...
	if (!fout.is_open())
	{						//Если файл не найден, выключаем программу
		cout << "Ошибка открытия файла" << endl;
		exit(223);
	}
	fout << "|———————————————————————————————————————————————";
	fout << "—————————————————————————————————————————————|\n";
	fout << "|" << setw(53) << right << "Count of products : ";
	fout << setw(3) << left << NodeLen(head);
	fout << "                                    |\n";
	fout << "|———————————————————————————————————————————————";
	fout << "—————————————————————————————————————————————|\n";
	fout << "| Name                     | Country          |";
	fout << " Fabricator      | Articul    | Cost          |\n";
	fout << "|———————————————————————————————————————————————";
	fout << "—————————————————————————————————————————————|\n";
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

	fout << "|———————————————————————————————————————————————";
	fout << "—————————————————————————————————————————————|\n";
	fout.close();
	return;
}
void Rec(Node &head) {
	if (NodeLen(head) < 1)
	{
		cout << "Ошибка! Списка не существует!"; loading(3, 0.6);
		return;
	}
	int h;
	cout << "Выберите путь записи файла: " << endl;
	cout << "1 - Сохранить в файл Output.txt" << endl;
	cout << "2 - Указать другой путь файла (Без ковычек и с расширением)" << endl;
	cout << ">>> ";
	if (cin >> h, !cin.good()) {
		cout << "Ошибка, введите цифру!"; loading(4, 0.4); return;
	}
	if (h <= 0 || h > 2) return;
	if (h == 2)
	{
		cin.get();
		string strt;
		cout << "Введите путь файла:"; getline(cin, strt);
		FileRecord(head, strt);
		cout << "Происходит запись файла"; loading(5, 0.6);
		return;
	}
	else		//Едем по моему навигатору
	{
		FileRecord(head, "Output.txt");
		cout << "Происходит запись файла"; loading(5, 0.6);
		return;
	}
	return;
}
int Insert(Node& head, Node* tail,int abs) 
{
	string name;
	cin.get();
	!abs ? cout << "Перед каким элементом " : cout << "После какого элемента ";
	cout <<"необходимо ввести?" << endl << ">>> "; getline(cin, name);
	int to;
		if (!abs)
			to = NodeFind(head,name, 1);
		else
			to = NodeFind(head,name, 1)+1;
	if (!to) {
		cout << "Такого элемента нет" << endl; loading(4, 0.3);
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
		cout << "Ввод узла:" << endl;
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
	cout << "Сколько узлов необходимо ввести?" << endl << ">>> ";
	if (cin >> n, n>0 && !cin.good()) {
		cout << "Это должно быть ЦИФРОЙ больше нуля!";
		return(0);
	}
	for (int i = 0; i < n; i++) {
		Node* node;
		node = new Node();
		head.next->prev = node;
		node->next = head.next;
		head.next = node;
		node->prev = &head;
		cout << "Ввод узла "<<i<<": " << endl;
		cin.get();
		Enter(node);
		cout << endl;
	}
	return(1);
}
int PushBackUntill(Node* tail) {
	system("cls");
	int n;
	cout << "Сколько узлов необходимо ввести?" << endl << ">>> ";
	if (cin >> n, n > 0 && !cin.good()) {
		cout << "Это должно быть ЦИФРОЙ больше нуля!";
		return(0);
	}
	for (int i = 0; i < n; i++) {
		Node* node;
		node = new Node();
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
		node->next = tail;
		cout << "Ввод узла:" << endl;
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
		cout << "Список пуст"; loading(3, 0.4);
		return(0);
	}
	int nam;    //какой элемент сортировать
	string namae;
	cin.get();
	cout << "Какой элемент редактировать?" << endl << ">>> "; getline(cin, namae);
	if (!(nam = NodeFind(head, namae, 1)+1))
		return(0);
	system("cls");
	int var;    //Вариант для выбора действий
	var = Redact();
	switch (var)
	{
	case 1:
	{
		EditElement(head, nam);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 2:
	{
		EditElement(head, nam, var);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 3:
	{
		EditElement(head, nam, var);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 4:
	{
		EditElement(head, nam, var);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 5:
	{

		EditElement(head, nam, var);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 6:
	{

		EditElement(head, nam, var);
		cout << "Элемент отредактирован"; loading(3, 0.4);
		break;
	}
	case 7:
		break;
	default:
	{
		cout << "Других вариантов не дано"; loading(3, 0.4);
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
		cout << "Такого критерия не существует";
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
				cout << "Название: ";  getline(cin, node->pro.name);
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
				cout << "Страна: ";  getline(cin, node->pro.country);
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
				cout << "Производитель: ";  getline(cin, node->pro.fabricator);
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
				cout << "Артикул: ";  getline(cin, node->pro.articul);
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
				cout << "Стоимость: ";  cin >> node->pro.cost;
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
	cout << "Какой элемент необходимо удалить?" << endl << ">>> "; getline(cin, str);
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
		head.next = node->next; // удаляем первый элемент
		if (head.next)
			head.prev = NULL;
		else tail = NULL; // удалили единственный элемент
	}
	else 
	{
		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		else tail = NULL; // удалили последний элемент
	}
	delete node;
	cout << "Узел успешно удален"; loading(4, 0.3);
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
		cout << "Списка не существует!"; loading(3, 0.4);
		return(0);
	}
	if (!n1 && !n2) {
		string first, second;
		cin.get();
		cout << "Первый предмет: " << endl << ">>> "; getline(cin, first);
		n1 = NodeFind(head, first, 1);
		cout << "Второй предмет: " << endl << ">>> "; getline(cin, second);
		n2 = NodeFind(head, second, 1);
		if (n1 == n2)
		{
			cout << "Ошибка, Это один и тот же предмет !"; loading(4, 0.3); return 0;
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
		cout << "Список пуст!" << endl << "Тут нечего сортировать !"; loading(5, 0.4);
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
			cout << "Как необходимо сортировать?" << endl << " 1 - По возрастанию" << endl
				<< " 2 - По убыванию" << endl << ">>> "; if (cin >> crt, !cin.good())
			{
				cout << "Необходимо писать цифру!"<<endl; loading(4, 0.4); break;
			}
			if (crt < 1 || crt > 2) {
				cout << "Такого варианта предложено не было!"<<endl; loading(4, 0.4);
				break;
			}
			if (crt == 1)
				Sort(head,tail,choice,1);
			else
			    Sort(head,tail, choice,2);
			cout << "Список успешно отсортирован"; loading(4, 0.4);
			break;
		}
	}
}
int Sort(Node& head, Node* tail, int iter, int order) 
{
	int n = NodeLen(head);
	if (order == 1)
	{
		if (iter == 1) //По названию по возрастанию
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
		if (iter == 2)// по стране по возрастанию
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
		if (iter == 3)//По производителю по возрастанию
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
		if (iter == 4) //По артиклю по возрастанию
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
		if (iter == 5)//По цене по возрастанию
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
		if (iter == 1) // По имени по убыванию
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
		if (iter == 2) //По стране по убыванию
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
		if (iter == 3)//По производителю по убыванию
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
		if (iter == 4) //По Артиклю по убыванию
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
		if (iter == 5) //По цене по убыванию
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
	cout << "Введите барьер, с которого начнется второй список: " << endl << ">>> ";
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