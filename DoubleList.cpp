#include <iostream>
using namespace std;
class doubleList
{
public:
    doubleList *prev;
    doubleList *next;
    int data;
    doubleList(int d)
    {
        prev = 0;
        next = 0;
        data = d;
    }
};
void insertAtHead(doubleList *&head, doubleList *&tail, int d, int &count)
{
    doubleList *node = new doubleList(d);
    if (head == 0)
    {
        head = node;
        tail = node;
        count++;
    }
    else
    {
        head->prev = node;
        node->next = head;
        head = node;
        count++;
    }
}
void insertAtTail(doubleList *&head, doubleList *&tail, int d, int &count)
{
    if (head != 0)
    {
        doubleList *node = new doubleList(d);
        node->prev = tail;
        tail->next = node;
        tail = node;
        count++;
    }
    else
    {
        insertAtHead(head, tail, d, count);
    }
}
void delAtHead(doubleList *&head, int &count)
{
    if (head != 0)
    {
        doubleList *temp = head;
        head = head->next;
        if (head != 0)
        {
            head->prev = 0;
        }
        count--;
        delete temp;
    }
    else
    {
        cout << "LinkList is empty" << endl;
    }
}
void delAtTail(doubleList *&head, doubleList *&tail, int &count)
{
    if (head != 0)
    {
        doubleList *temp = tail;
        tail = tail->prev;
        if (tail != 0)
        {
            tail->next = 0;
        }
        else
        {
            head = 0;
        }
        delete temp;
        count--;
    }
    else
    {
        cout << "LinkList is empty." << endl;
    }
}
void insertAtPos(doubleList *&head, doubleList *&tail, int pos, int d, int &count)
{
    if (pos != 1 && pos <= count + 1)
    {

        doubleList *node = new doubleList(d);
        doubleList *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node->prev = temp;
        node->next = temp->next;
        temp->next = node;
        count++;
    }
    else if (pos > count + 1)
    {
        cout << "Enter a valid position." << endl;
    }
    else
    {
        insertAtHead(head, tail, d, count);
    }
}
void delAtPos(doubleList *&head, doubleList *&tail, int &count)
{
    if (head != 0)
    {
        int pos;
        cout << "Enter the position you have first " << count << " positions :";
        cin >> pos;
        if (pos != 1 && pos < count)
        {

            doubleList *temp = head;
            doubleList *temp2;
            doubleList *temp3;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            temp3 = temp->next;
            temp->next = temp->next->next;
            if (temp->next != 0)
            {
                temp2 = temp->next;
                temp2->prev = temp;
            }
            delete temp3;
        }
        else if (pos > count)
        {
            cout << "Enter a valid position." << endl;
        }
        else
        {
            delAtHead(head, count);
        }
    }
    else
    {
        cout << "LinkList is empty." << endl;
    }
}
void displayList(doubleList *&head)
{
    if (head != 0)
    {
        doubleList *temp = head;
        while (temp != 0)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "LinkList is empty" << endl;
    }
}
int main()
{
    int again = 1, data, choice, pos, count = 0;
    doubleList *head = 0;
    doubleList *tail = 0;
    while (again)
    {
        cout << "1.Insert at head." << endl;
        cout << "2.Insert at tail." << endl;
        cout << "3.Delete at head." << endl;
        cout << "4.Delete at tail." << endl;
        cout << "5.Insert at Position." << endl;
        cout << "6.Delete at Position." << endl;
        cout << "7.Display All the values." << endl;
        cout << "Enter your choice  :";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter data :";
            cin >> data;
            insertAtHead(head, tail, data, count);
        }
        else if (choice == 2)
        {
            cout << "Enter data :";
            cin >> data;
            insertAtTail(head, tail, data, count);
        }
        else if (choice == 3)
        {
            delAtHead(head, count);
        }
        else if (choice == 4)
        {
            delAtTail(head, tail, count);
        }
        else if (choice == 5)
        {
            cout << "Enter data :";
            cin >> data;
            cout << "Enter the position you have first " << count + 1 << " positions :";
            cin >> pos;
            insertAtPos(head, tail, pos, data, count);
        }
        else if (choice == 6)
        {
            delAtPos(head, tail, count);
        }
        else if (choice == 7)
        {
            displayList(head);
        }
        cout << "Enter 1 for again,0 for end :";
        cin >> again;
        if (again)
        {
            system("cls");
        }
    }
}