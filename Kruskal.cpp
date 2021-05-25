#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


///Vector of Edges

vector <pair<int,pair<int,int>>> Edges;








/// Union-Find algorithm
int size = 6;
int* p = new int[size]; /// Parents array
int* r = new int[size]; /// Ranks array


void makeSet(int v)
{
    p[v] = v;
    r[v] = 1;
}

/// Function Find with dynamic path compression
int find(int v)
{
    if(p[v] == v)
        return v;
    return p[v] = find(p[v]);

}

/// Union function with changed name because of code-word in C++
void unite(int v1,int v2)
{
    v1 = find(v1);
    v2 = find(v2);
    if(v1 == v2)
        return;
    if(r[v1] > r[v2])
        p[v2] = v1;
    else if(r[v1] == r[v2])
    {
        p[v1] = v2;
        r[v1]++;
    }
    else
        p[v1] = v2;
}
/// ////////////////////////////


/// Kruskal's algorithm, which returns Final weight of all edges in minimum spanning tree
int Kraskal(vector <pair<int,pair<int,int>>>::iterator it)
{
    int FinalWeight = 0;
    for(it=Edges.begin();it!=Edges.end();it++)
    {
        int firstRoot = find(it->second.first);
        int secondRoot = find(it->second.second);
        if(firstRoot != secondRoot)
        {
            unite(firstRoot,secondRoot);
            FinalWeight += it->first;
        }
    }
return FinalWeight;
}
/// ///////////////////////////////////////////////////////






int main()
{
srand(time(0));

/// Creating forest
for(int i=0;i<size;i++)
    makeSet(i);



/// Creating edges of testing graph
Edges.push_back({4,{0,1}});
Edges.push_back({1,{1,3}});
Edges.push_back({2,{0,2}});
Edges.push_back({2,{3,4}});
Edges.push_back({3,{2,4}});
Edges.push_back({12,{0,3}});
Edges.push_back({10,{0,4}});
Edges.push_back({8,{1,2}});
Edges.push_back({5,{2,3}});
sort(Edges.begin(),Edges.end());

vector <pair<int,pair<int,int>>>::iterator it;

/// Receiving a final weight of all edges
int result = Kraskal(it);


cout << result;


/// Memory clearing
delete [] p;
delete [] r;
return  0;
}
