#include <stdio.h>
#include <vector>
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

} 

int main() {
    // Vector list where <FROM <TO, WEIGHT>
    vector<vector<Edge>> weighted_traffic_graph = {
        {{2,1}, {11,1}}, // Vertex 1
        { {3,1}, {21,1}, {1,1}}, //Vertex 2
        { {4,1}, {8,2}, {2,1} }, //Vertex 3
        { {3,1}, {5,1} }, //Vertex 4
        { {4,1}, {6,2}, {7,1}, {22,1} }, //Vertex 5
        { {5,2}, {7,1} }, //Vertex 6
        { {5,1}, {6,1}, {8,1} }, //Vertex 7
        { {3,2}, {7,1}, {9,2} }, //Vertex 8
        { {8,2}, {10,1}, {19,2} }, //Vertex 9
        { {9,1}, {11,1} }, //Vertex 10
        { {10,1}, {1,1}, {12,2} }, //Vertex 11
        { {11,2}, {13,2} }, //Vertex 12
        { {12,2}, {14,2}, {21,1} }, //Vertex 13
        { {13,2}, {15,1}, {16,1}, {20,1} }, //Vertex 14
        { {14,1} }, //Vertex 15
        { {14,1}, {17,2} }, //Vertex 16
        { {16,2}, {18,2} }, //Vertex 17
        { {17,2}, {19,2} }, //Vertex 18
        { {18,2}, {9,2} }, //Vertex 19
        { {14,1}, {21,2}, {22,1} }, //Vertex 20
        { {2,1}, {13,1}, {20,2}, {22,2} }, //Vertex 21
        { {5,1}, {20,1}, {21,2} }, //Vertex 22
    };
    vector<int> destinations_to_check = {6,8,9,15,16,22}; 
    return 0; 
}