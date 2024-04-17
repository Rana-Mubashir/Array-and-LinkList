#include <iostream>
#include <stdlib.h>
using namespace std;
class ArrayOper
{
    int *ptr;
    int size;
    int capacity;

public:
    ArrayOper(int cap)
    {
        capacity = cap;
        size = 0;
        ptr = new int[capacity];
    }
    bool checkAccessibility()
    {
        if (size < capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertAtLast()
    {
        if (checkAccessibility())
        {
            cout << "Enter value you want to insert at last =";
            cin >> ptr[size];
            size++;
        }
        else
        {
            cout << "Array is full." << endl;
        }
    }
    void insertAtHead()
    {
        if (size == 0)
        {
            cout << "Enter value you want to insert at head =";
            cin >> ptr[0];
            size++;
        }
        else if (size > 0)
        {
            insertAtPos(0);
        }
    }
    void insertAtPos(int pos)
    {
        if (checkAccessibility())
        {
            if (pos == 0 && size == 0)
            {
                insertAtHead();
            }
            else if (pos == size)
            {
                insertAtLast();
            }
            else if (pos < size)
            {
                int temp;
                for (temp = size; temp > pos; temp--)
                {
                    ptr[temp] = ptr[temp - 1];
                }
                cout << "Enter value =";
                cin >> ptr[temp];
                size++;
            }
            else
            {
                cout << "Enter a valid position." << endl;
            }
        }
        else
        {
            cout << "Array is full." << endl;
        }
    }
    void delAtLast()
    {
        if (size == 0)
        {
            cout << "Array is empty." << endl;
        }
        else
        {
            size--;
        }
    }
    void delAtPos(int pos)
    {
        if (size > 0 && pos < size)
        {
            int temp;
            for (temp = pos; temp < size; temp++)
            {
                ptr[temp] = ptr[temp + 1];
            }
            size--;
        }
        else
        {
            cout << "Enter a valid position." << endl;
        }
    }
    void delValue(int val)
    {
        int pos = 0;
        bool flag = false;
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (ptr[i] == val)
                {
                    flag = true;
                    delAtPos(pos);
                    break;
                }
                pos++;
            }
            if (!flag)
            {
                cout << "Value is not available in array." << endl;
            }
        }
        else
        {
            cout << "Array is empty." << endl;
        }
    }
    void updateValue(int val)
    {
        int pos = 0;
        bool flag = false;
        int newVal;
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (ptr[i] == val)
                {
                    flag = true;
                    cout << "Value is available at position " << i << " ,Enter new value for this position =";
                    cin >> newVal;
                    ptr[i] = newVal;
                    break;
                }
                pos++;
            }
            if (!flag)
            {
                cout << "Value is not available in array." << endl;
            }
        }
        else
        {
            cout << "Array is empty." << endl;
        }
    }
    void displayArray()
    {
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                cout << ptr[i] << endl;
            }
        }
        else
        {
            cout << "Array is empty." << endl;
        }
    }
    ~ArrayOper()
    {
        delete ptr;
    }
};
int main()
{
    int again, choice, pos, value;
    ;
    ArrayOper obj(5);
    while (again)
    {
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at any position " << endl;
        cout << "4. Delete at tail" << endl;
        cout << "5. Delete at any position " << endl;
        cout << "6. Delete by value" << endl;
        cout << "7. Update a value" << endl;
        cout << "8. Display all the value" << endl;
        cin >> choice;
        if (choice == 1)
        {
            obj.insertAtHead();
        }
        else if (choice == 2)
        {
            obj.insertAtLast();
        }
        else if (choice == 3)
        {
            cout << "Enter postion for insertion,starts from 0 =";
            cin >> pos;
            obj.insertAtPos(pos);
        }
        else if (choice == 4)
        {
            obj.delAtLast();
        }
        else if (choice == 5)
        {
            cout << "Enter postion for deletion,starts from 0 =";
            cin >> pos;
            obj.delAtPos(pos);
        }
        else if (choice == 6)
        {
            cout << "Enter value you want to delete =";
            cin >> value;
            obj.delValue(value);
        }
        else if (choice == 7)
        {
            cout << "Enter value you want to update =";
            cin >> value;
            obj.updateValue(value);
        }
        else if (choice == 8)
        {
            obj.displayArray();
        }
        cout << "Enter 1 for again and 0 for end =";
        cin >> again;
        if (again)
        {
            system("cls");
        }
    }
}