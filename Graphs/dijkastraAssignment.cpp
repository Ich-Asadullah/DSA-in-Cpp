#include <iostream>
#include <climits>
using namespace std;
#define V 5

void printSolution(int dist[], int startVertex, string vertices[]){
    cout << "Distance from "<<vertices[startVertex] << endl;
    for (int i = 0; i < V; i++)
        cout << vertices[i] << " --> " << dist[i] << endl;
}

int mindistance(int distances[],bool visited[]){
    int min = INT_MAX;
    int minindex;
    for (int i = 0; i<V; i++){
        if (distances[i]<=min && visited[i]==false){
            min=distances[i];
            minindex=i;
        }
    }
    return minindex;
}

void djikstraAlgo(int graph[V][V], int startVertex, string vertices[]){
    bool visited[V];
    int distances[V];
    for (int i=0;i<V;i++){
        visited[i]=false;
        distances[i]=INT_MAX;
    }

    distances[startVertex]=0;

    for (int count=0; count< V-1; count++){
        int u = mindistance(distances,visited);
        
        visited[u] = true;

        //u is shortest and v is indexes in loop
        for (int v = 0 ;v < V;v++){
            if (visited[v] != true && distances[u]!=INT_MAX && graph[u][v]  
            && distances[u]+graph[u][v] < distances[v]) {
                distances[v] = distances[u]+graph[u][v];
            }
        }
    }
    printSolution(distances, startVertex, vertices);
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

void displaygraph(int graph[V][V]){
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
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

    // displaygraph(graph);


    djikstraAlgo(graph,3, vertices);

    return 0;
}