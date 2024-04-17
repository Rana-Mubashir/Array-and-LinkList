#include <iostream>
using namespace std;
class List
{
public:
    int data;
    List *next;
    List(int d)
    {
        data = d;
        next = 0;
    }
};
bool isEmpty(List *&head)
{
    return head == 0;
}
void insertAtHead(List *&head, List *&tail, int data, int &count)
{
    List *node = new List(data);
    if (head == 0)
    {
        head = node;
        tail = node;
        node->next = head;
        count++;
    }
    else
    {
        node->next = head;
        head = node;
        tail->next = node;
        count++;
    }
}
void insertAtTail(List *&head, List *&tail, int data, int &count)
{
    List *node = new List(data);
    if (head == 0)
    {
        insertAtHead(head, tail, data, count);
    }
    else
    {
        tail->next = node;
        tail = node;
        tail->next = head;
        count++;
    }
}
void delAtHead(List *&head, List *&tail, int &count)
{
    if (!isEmpty(head))
    {
        if (count != 1)
        {
            List *temp = head;
            head = head->next;
            tail->next = head;
            count--;
            delete temp;
        }
        else
        {
            List *temp = head;
            head = 0;
            tail = 0;
            count--;
            delete temp;
        }
    }
    else
    {
        cout << "List is empty." << endl;
    }
}
void delAtTail(List *&head, List *&tail, int &count)
{
    if (!isEmpty(head))
    {
        if (count != 1)
        {
            List *temp = head;
            for (int i = 1; i < count - 1; i++)
            {
                temp = temp->next;
            }
            List *temp2 = tail;
            tail = temp;
            temp->next = head;
            delete temp2;
            count--;
        }
        else
        {
            delAtHead(head, tail, count);
        }
    }
    else
    {
        cout << "List is empty." << endl;
    }
}
void display(List *&head)
{
    if (!isEmpty(head))
    {
        List *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        cout << "List is empty." << endl;
    }
}
int main()
{
    int again = 1, choice, data, count = 0;
    List *head = 0;
    List *tail = 0;
    while (again)
    {
        cout << "1.Insert at head." << endl;
        cout << "2.Insert at tail." << endl;
        cout << "3.Delete at head." << endl;
        cout << "4.Delete at tail." << endl;
        cout << "5.Display all the values." << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter data =";
            cin >> data;
            insertAtHead(head, tail, data, count);
        }
        else if (choice == 2)
        {
            cout << "Enter data =";
            cin >> data;
            insertAtTail(head, tail, data, count);
        }
        else if (choice == 3)
        {
            delAtHead(head, tail, count);
        }
        else if (choice == 4)
        {
            delAtTail(head, tail, count);
        }
        else if (choice == 5)
        {
            display(head);
        }
        cout << "Enter 0 for end,1 for again :";
        cin >> again;
    }
}