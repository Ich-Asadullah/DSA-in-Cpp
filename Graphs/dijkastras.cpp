#include <iostream>
#include <climits>
using namespace std;

// Number of vertices in the graph
#define V 3

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool foundSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (foundSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int src) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << src << " -> "<< i << " = " << dist[i] << endl;
    }
}

// Function to implement Dijkstra's algorithm for a graph represented as an adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool foundSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        foundSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, foundSet);
        foundSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!foundSet[v] && graph[u][v] && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printSolution(dist, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0},
        {4, 0, 0},
        {0, 8, 0},
    };

    dijkstra(graph, 1);
    return 0;
}
