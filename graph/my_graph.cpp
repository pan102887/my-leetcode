#include <iostream>
#include <vector>
using namespace std;

class MyGraph
{
private:
    int vertex_count = 0;
    int edge_count = 0;
    vector<vector<int>> adjacent_table;

public:
    MyGraph(int n)
    {
        vertex_count = n;
        adjacent_table.resize(n, vector<int>(0));
    }
    int V()
    {
        return vertex_count;
    }
    int E()
    {
        return edge_count;
    }
    void add_edge(int v);
};

int main(int argc, char *[])
{
    return 0;
}