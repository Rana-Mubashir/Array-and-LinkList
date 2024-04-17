#include <iostream>
#include <stdlib.h>
using namespace std;
class SingleList
{
public:
    int data;
    SingleList *next;
    SingleList(int d)
    {
        data = d;
        next = 0;
    }
};
bool isEmpty(SingleList *&head)
{
    return head == 0;
}
void insertAtHead(SingleList *&head, SingleList *&tail, int d, int &count)
{
    SingleList *node = new SingleList(d);
    node->next = head;
    head = node;
    if (tail == 0)
    {
        tail = node;
    }
    count++;
}
void insertAtTail(SingleList *&tail, SingleList *&head, int d, int &count)
{
    if (!isEmpty(head))
    {
        SingleList *node = new SingleList(d);
        tail->next = node;
        tail = node;
        count++;
    }
    else
    {
        insertAtHead(head, tail, d, count);
    }
}
void insertAtPos(SingleList *&head, SingleList *&tail, int pos, int d, int &count)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d, count);
    }
    else if (pos <= count + 1)
    {
        SingleList *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        SingleList *node = new SingleList(d);
        node->next = temp->next;
        temp->next = node;
        count++;
    }
    else
    {
        cout << "Enter a valid position." << endl;
    }
}
void delAtHead(SingleList *&head, int &count)
{
    if (!isEmpty(head))
    {
        SingleList *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    else
    {
        cout << "LinkList is empty." << endl;
    }
}
void delAtTail(SingleList *&head, SingleList *&tail, int &count)
{
    if (count == 1)
    {
        delAtHead(head, count);
    }
    else
    {

        SingleList *temp = head;
        SingleList *temp2;
        if (!isEmpty(head))
        {
            for (int i = 1; i < count - 1; i++)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = 0;
            tail = temp;
            delete temp2;
            count--;
        }
        else
        {
            cout << "LinkList is empty." << endl;
        }
    }
}
void delAtPos(SingleList *&head, SingleList *&tail, int &count)
{
    if (!isEmpty(head))
    {
        int pos;
        cout << "Enter the position,you have first " << count << " positions :";
        cin >> pos;
        if (pos == 1)
        {
            delAtHead(head, count);
        }
        else if (pos < count)
        {
            SingleList *temp = head;
            SingleList *temp2;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = temp2->next;
            count--;
            delete temp2;
        }
        else if (pos == count)
        {
            delAtTail(head, tail, count);
        }
    }
    else
    {
        cout << "LinkList is empty" << endl;
    }
}
void displayList(SingleList *&head)
{
    if (!isEmpty(head))
    {
        SingleList *temp = head;
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
    int again = 1, data, choice, count, pos;
    SingleList *head = 0;
    SingleList *tail = 0;
    while (again)
    {
        cout << "1.Insert at head." << endl;
        cout << "2.Insert at tail." << endl;
        cout << "3.Delete at head." << endl;
        cout << "4.Insert at Position." << endl;
        cout << "5.Delete at Position." << endl;
        cout << "6.Delete at tail." << endl;
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
            insertAtTail(tail, head, data, count);
        }
        else if (choice == 3)
        {
            delAtHead(head, count);
        }
        else if (choice == 4)
        {
            cout << "Enter data :";
            cin >> data;
            cout << "Enter the position,you have first " << count + 1 << " positions :";
            cin >> pos;
            insertAtPos(head, tail, pos, data, count);
        }
        else if (choice == 5)
        {
            delAtPos(head, tail, count);
        }
        else if (choice == 6)
        {
            delAtTail(head, tail, count);
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
