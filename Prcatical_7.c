/*7	 Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: 
Start searching at node 1, and break ties for exploring the next node based on lower numerical order 
(i.e. add nodes to a queue low to high, add nodes to a stack high to low).
 (a) In what order are nodes marked as explored by BFS? 
 (b) In what order are nodes marked as explored by DFS?
*/
#include <stdio.h>
#include <stdlib.h>

#define N 9   // Number of nodes in the graph

// -----------------------------
// Graph adjacency matrix
// -----------------------------
int graph[N + 1][N + 1] = {
    {0},
    // 1  2  3  4  5  6  7  8  9
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}, // 1 -> 2, 4
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, // 2 -> 1, 3, 5
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, // 3 -> 2, 6
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, // 4 -> 1, 5, 7
    {0, 0, 1, 0, 1, 0, 1, 0, 1, 0}, // 5 -> 2, 4, 6, 8
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, // 6 -> 3, 5, 9
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // 7 -> 4, 8
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1}, // 8 -> 5, 7, 9
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}  // 9 -> 6, 8
};

// -----------------------------
// Function Declarations
// -----------------------------
void bfs(int start);
void dfs(int start);

// -----------------------------
// Main Function
// -----------------------------
int main() {
    int start = 1;

    printf("BFS traversal starting from node %d:\n", start);
    bfs(start);

    printf("\nDFS traversal starting from node %d:\n", start);
    dfs(start);

    return 0;
}

// -----------------------------
// BFS Function
// -----------------------------
void bfs(int start) {
    int visited[N + 1] = {0};
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        // Add neighbors in increasing order (low → high)
        for (int i = 1; i <= N; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// -----------------------------
// DFS Function
// -----------------------------
void dfs(int start) {
    int visited[N + 1] = {0};
    int stack[100];
    int top = -1;

    stack[++top] = start;

    while (top >= 0) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);

            // Push neighbors in decreasing order (high → low)
            for (int i = N; i >= 1; i--) {
                if (graph[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}
