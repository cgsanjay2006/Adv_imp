#include <iostream>
using namespace std;

class Element
{
public:
    int value;
    Element* link;

    Element(int val)
    {
        value = val;
        link = NULL;
    }
};

class List
{
private:
    Element* start;

public:
    List()
    {
        start = NULL;
    }

    void addFront(int val)
    {
        Element* newElem = new Element(val);
        newElem->link = start;
        start = newElem;
    }

    void addBack(int val)
    {
        Element* newElem = new Element(val);

        if (start == NULL)
        {
            start = newElem;
            return;
        }

        Element* ptr = start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newElem;
    }

    void addAtPos(int val, int pos)
    {
        Element* newElem = new Element(val);

        if (pos == 1)
        {
            newElem->link = start;
            start = newElem;
            return;
        }

        Element* ptr = start;
        for (int i = 1; i < pos - 1 && ptr->link != NULL; i++)
        {
            ptr = ptr->link;
        }

        newElem->link = ptr->link;
        ptr->link = newElem;
    }

    void removeFront()
    {
        if (start == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Element* temp = start;
        start = start->link;
        delete temp;
    }

    void removeBack()
    {
        if (start == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (start->link == NULL)
        {
            delete start;
            start = NULL;
            return;
        }

        Element* ptr = start;
        while (ptr->link->link != NULL)
        {
            ptr = ptr->link;
        }

        delete ptr->link;
        ptr->link = NULL;
    }

    void removeAtPos(int pos)
    {
        if (start == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (pos == 1)
        {
            Element* temp = start;
            start = start->link;
            delete temp;
            return;
        }

        Element* ptr = start;
        for (int i = 1; i < pos - 1 && ptr->link != NULL; i++)
        {
            ptr = ptr->link;
        }

        if (ptr->link == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Element* delNode = ptr->link;
        ptr->link = delNode->link;
        delete delNode;
    }

    void show()
    {
        if (start == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Element* ptr = start;
        while (ptr != NULL)
        {
            cout << ptr->value << "->";
            ptr = ptr->link;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List myList;
    int choice, num, position;

    do
    {
        cout << "1. Add at front" << endl;
        cout << "2. Add at back" << endl;
        cout << "3. Add at position" << endl;
        cout << "4. Remove from front" << endl;
        cout << "5. Remove from back" << endl;
        cout << "6. Remove from position" << endl;
        cout << "7. Show list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> num;
            myList.addFront(num);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> num;
            myList.addBack(num);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> num;
            cout << "Enter position: ";
            cin >> position;
            myList.addAtPos(num, position);
            break;

        case 4:
            myList.removeFront();
            break;

        case 5:
            myList.removeBack();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;
            myList.removeAtPos(position);
            break;

        case 7:
            myList.show();
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 8);

    return 0;
}