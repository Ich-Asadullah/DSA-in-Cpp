#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V], string vertices[]) {
    for (int i = 1; i < V; i++)
        cout << vertices[parent[i]] << " - " << vertices[i] << " --> " << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V], string vertices[]) {
    int parent[V]; // Array to results
    int key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent found points

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                {parent[v] = u;
                key[v] = graph[u][v];}
    }

    printMST(parent, graph, vertices);
}

void addDistances(int graph[V][V], string vertices[V], string source, string destination, int distance) {
    int sourceIndex = -1;
    int destinationIndex = -1;
    for (int i = 0; i < V; i++) {
        if (vertices[i] == source) sourceIndex = i;
        if (vertices[i] == destination) destinationIndex = i;
    }

    if (sourceIndex != -1 && destinationIndex != -1) {
        graph[sourceIndex][destinationIndex] = distance;
        graph[destinationIndex][sourceIndex] = distance; // Since the graph is undirected
    }
}


int main() {

    string vertices[V] = {"lahore","islamabad","faisalabad","multan","karachi"};
    // string source = "lahore";  

    int graph[V][V] ;
    addDistances(graph,vertices,"lahore","islamabad",300);
    addDistances(graph,vertices,"lahore","multan",314);
    addDistances(graph,vertices,"lahore","faisalabad",160);
    addDistances(graph,vertices,"lahore","karachi",1120);

    addDistances(graph,vertices,"multan","faisalabad",260);
    addDistances(graph,vertices,"multan","islamabad",620);
    addDistances(graph,vertices,"multan","karachi",870);
    addDistances(graph,vertices,"multan","lahore",314);

    addDistances(graph,vertices,"karachi","faisalabad",1000);
    addDistances(graph,vertices,"karachi","lahore",1120);
    addDistances(graph,vertices,"karachi","islamabad",1420);
    addDistances(graph,vertices,"karachi","multan",870);

    primMST(graph, vertices);

    return 0;
}
