/*8	Write a program which accepts undirected graph and a starting node, 
 determine the lengths of the shortest paths from the starting node to all other nodes in the graph.
 If a node is unreachable, its distance is -1. Nodes will be numbered consecutively from 1 to n, 
 and edges will have varying distances or lengths.
 Find the sub tree using Dijikstra algorithm.	*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int n, int start);

int main() {
    int n, e;
    int graph[MAX][MAX];
    int u, v, w, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
int i,j;
    // Initialize graph with INF (no edge)
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter each edge as: node1 node2 weight\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // because graph is undirected
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX], parent[MAX];
    
    // Initialize arrays
    for ( i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;
int v,count;
    // Dijkstra's main loop
    for ( count = 1; count <= n - 1; count++) {
        int minDist = INF, u = -1;

        // Find unvisited node with smallest distance
        for ( v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1)
            break; // No reachable nodes remain

        visited[u] = 1;

        // Update neighbors
        for ( v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;  // keep track of path
            }
        }
    }

    // Print results
    printf("\nShortest distances from node %d:\n", start);
    for ( i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("Node %d: Distance = -1 (Unreachable)\n", i);
        else
            printf("Node %d: Distance = %d\n", i, dist[i]);
    }

    // Print shortest path tree (subtree)
    printf("\nShortest Path Tree (Parent relationships):\n");
    for ( i = 1; i <= n; i++) {
        if (i != start && parent[i] != -1)
            printf("%d <-- %d (edge weight = %d)\n", i, parent[i], graph[i][parent[i]]);
    }
}
