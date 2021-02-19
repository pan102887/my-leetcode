#include <iostream>
#include <vector>
using namespace std;

template <class T>
class graph
{
private:
    int vertex;
    int edge = 0;
    vector<vector<int>> edgeTable;

public:
    graph(int n)
    {
        vertex = n;
        vertex = new T[n];
        edgeTable = 
    }
    int V()
    {
        return vertex;
    }
    int E(){
        return edge;
    }
    void addVertex(){

    }
    void addEdge(T a, T b){

    }
};