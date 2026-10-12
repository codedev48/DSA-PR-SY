#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;
    int choice, value;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Inorder";
        cout << "\n3. Preorder";
        cout << "\n4. Postorder";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 5);

    return 0;
}
