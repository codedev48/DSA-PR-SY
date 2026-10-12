
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;


// Insert node at the end
void insert(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Go to the last node
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect last node to new node
    temp->next = newNode;
}


// Delete the first node
void deleteNode()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    cout << "First node deleted.\n";
}


// Recursive traversal
void display(Node* temp)
{
    // Stop when we reach NULL
    if (temp == NULL)
    {
        return;
    }

    cout << temp->data << " ";

    // Recursively go to next node
    display(temp->next);
}


// Search for a node
void search(int value)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << value << " found in the list.\n";
            return;
        }

        temp = temp->next;
    }

    cout << value << " not found in the list.\n";
}


int main()
{
    int choice;
    int value;

    do
    {
        cout << "\n----- Singly Linked List -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete First Node\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                insert(value);
                cout << "Node inserted.\n";
                break;


            case 2:
                deleteNode();
                break;


            case 3:
                if (head == NULL)
                {
                    cout << "List is empty!\n";
                }
                else
                {
                    cout << "Linked List: ";
                    display(head);
                    cout << endl;
                }
                break;


            case 4:
                cout << "Enter value to search: ";
                cin >> value;

                search(value);
                break;


            case 5:
                cout << "Exiting...\n";
                break;


            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);


    return 0;
}
