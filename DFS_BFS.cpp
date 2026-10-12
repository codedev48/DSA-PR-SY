#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

// ---------------- DFS ----------------
void DFS(int start)
{
    int stack[10];
    int top = -1;

    // Push starting vertex into stack
    stack[++top] = start;

    while (top != -1)
    {
        // Pop vertex from stack
        int vertex = stack[top--];

        // Visit only if not already visited
        if (visited[vertex] == 0)
        {
            cout << vertex << " ";
            visited[vertex] = 1;

            // Push all adjacent vertices
            for (int i = n - 1; i >= 0; i--)
            {
                if (graph[vertex][i] == 1 && visited[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

// ---------------- BFS ----------------
void BFS(int start)
{
    int queue[10];
    int front = 0;
    int rear = 0;

    // Enqueue starting vertex
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        // Dequeue vertex
        int vertex = queue[front++];

        cout << vertex << " ";

        // Enqueue all adjacent vertices
        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// ---------------- MAIN ----------------
int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    // Reset visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}
