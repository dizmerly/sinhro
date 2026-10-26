#include <functional>
#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;
#define INF 99999999
struct Edge{
    int to; 
    int weight; 
};
// returns vector of <destination, shortest distance cost>
vector<Edge> Dijkstras(vector<vector<Edge>> weighted_traffic_graph, vector<int> destinations_to_check) {
    vector<Edge> results = {}; 
    // init dijkstra
    vector<int> dist(weighted_traffic_graph.size(), INF); 
    vector<int> prev(weighted_traffic_graph.size(), -1); 
    // Initialize source vertex 1
    dist[0] = 0; 
    // pair - {distance, vertex}
    priority_queue<pair<int, int>,
                vector<pair<int, int>>, 
                greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        // u = extract min
        int u = pq.top().second;
        int u_weight = pq.top().first; 
        pq.pop(); 
        if(u_weight != dist[u]) {
            continue; 
        }
        // Relax the edges
        for(const Edge& edge : weighted_traffic_graph[u]) {
            int v = edge.to - 1; /* avoid off by 1 error */
            int weight = edge.weight; 
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                prev[v] = u; 
                pq.push(make_pair(dist[v], v));      
            }
        }
    }
    for(const int& destination : destinations_to_check){
        Edge res = {destination, dist[destination - 1]};
        results.push_back(res);
    }
    return results; 
}
int main() {
    // Vector list where <FROM <TO, WEIGHT>
    vector<vector<Edge>> weighted_traffic_graph = {
        /*1*/  {{2,1},{11,1}},          /*2*/  {{3,1},{21,1},{1,1}},
        /*3*/  {{4,1},{8,2},{2,1}},      /*4*/  {{3,1},{5,1}},
        /*5*/  {{4,1},{6,2},{7,1},{22,1}},/*6*/  {{5,2},{7,1}},
        /*7*/  {{5,1},{6,1},{8,1}},      /*8*/  {{3,2},{7,1},{9,2}},
        /*9*/  {{8,2},{10,1},{19,2}},    /*10*/ {{9,1},{11,1}},
        /*11*/ {{10,1},{1,1},{12,2}},    /*12*/ {{11,2},{13,2}},
        /*13*/ {{12,2},{14,2},{21,1}},   /*14*/ {{13,2},{15,1},{16,1},{20,1}},
        /*15*/ {{14,1}},                /*16*/ {{14,1},{17,2}},
        /*17*/ {{16,2},{18,2}},          /*18*/ {{17,2},{19,2}},
        /*19*/ {{18,2},{9,2}},           /*20*/ {{14,1},{21,2},{22,1}},
        /*21*/ {{2,1},{13,1},{20,2},{22,2}},
        /*22*/ {{5,1},{20,1},{21,2}}
    };
    vector<int> destinations_to_check = {6,8,9,15,16,22}; 
    vector<Edge> results = Dijkstras(weighted_traffic_graph, destinations_to_check);
    for(const Edge& result : results){
        cout << "Destination " << result.to << ", distance = " << result.weight << ", ";
    }
    return 0; 
}