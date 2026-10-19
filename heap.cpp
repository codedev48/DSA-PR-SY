
#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool isMaxHeap)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        (isMaxHeap ? a[left] > a[largest]
                   : a[left] < a[largest]))
        largest = left;

    if (right < n &&
        (isMaxHeap ? a[right] > a[largest]
                   : a[right] < a[largest]))
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest, isMaxHeap);
    }
}

void heapSort(int a[], int n, bool isMaxHeap)
{
    // Build Max Heap or Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, isMaxHeap);

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0, isMaxHeap);
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int a[100], n, choice;

    cout << "Enter number of elements (1-100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of elements!" << endl;
        return 1;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    do
    {
        cout << "\n--- HEAP SORT MENU ---" << endl;
        cout << "1. Max Heap - Ascending Order" << endl;
        cout << "2. Min Heap - Descending Order" << endl;
        cout << "3. Display Elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                heapSort(a, n, true);
                cout << "Ascending Order: ";
                display(a, n);
                break;

            case 2:
                heapSort(a, n, false);

                // Reverse to get descending order
                for (int i = 0; i < n / 2; i++)
                    swap(a[i], a[n - 1 - i]);

                cout << "Descending Order: ";
                display(a, n);
                break;

            case 3:
                cout << "Current Elements: ";
                display(a, n);
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
