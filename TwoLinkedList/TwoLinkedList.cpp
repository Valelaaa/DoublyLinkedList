// TwoLinkedList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "header.h"

int main()
{
    system("chcp 1251");
    Node head,nead,*tail,*nail;
    head.prev = NULL;
    nead.prev = NULL;
    tail = new Node();
    nail = new Node();
    head.next = tail;
    nead.next = nail;
    tail->prev = &head;
    nail->prev = &nead;
    tail->next = NULL;
    nail->next = NULL;
    int n;
    int who;
    while (true) 
    {
        system("cls");
        switch (n=MainMenu()) 
        {
        case 1:
        {
            who = maining(head, tail, n);
            break;
        }
        case 2:
        {
            who = maining(nead, nail, n);
            break;
        }
        default: 
        {
            cout << "Выход из программы"; loading(3, 0.4);
            return(0);
        }
        }
        if (who == 13) 
        {
            system("cls");
            cout << "Как необходимо разделить ?" << endl << "1. - Разделение барьером" << endl << "2. - Тудым Сюдым"<<endl<<"3. - Назад" << endl << ">>> ";
            int f;
            if (cin >> f, !cin.good()) {
                cout << "Это должна была быть цифра!";
                break;
            }
            switch (f) 
            {
            case 1:
            {
                if (Barrier(head, tail, nead, nail)){
                    cout << "Список успешно разделен"; loading(3, 0.3); }
                else {
                    cout << "Список не был разделен"; loading(3, 0.3);
                }
                break;
            }
            case 2: 
            {
                if (HereAndThere(head, tail, nead, nail)) 
                {
                    cout << "Список успешно разделен"; loading(3, 0.3);
                }
                else 
                {
                    cout << "Список не был разделен"; loading(3, 0.3);
                }
            break;
            }
            case 3: 
            {
                break;
            }
            default: 
            {
                cout << "Такого варианта не было! "; loading(4, 0.4);
                break;
            }
            }
            
        }
        else if (who == 10) 
        {
            NodeTogether(head, tail, nead, nail);
        }
    }
    return(0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
