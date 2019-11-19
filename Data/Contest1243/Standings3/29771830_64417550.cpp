#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>

using ll = long long;

using namespace std;

unordered_map<int, vector<int>> noes;
unordered_set<int> base;
bool visited[100001];
int n;

void DFSUtil(int v)
{
    // Mark the current node as visited and print it 
    visited[v] = true;

    // Recur for aint the vertices 
    // adjacent to this vertex 

    auto basecopy = base;
    if (noes.find(v) != noes.end())
        for (const auto& j : noes.at(v))
            basecopy.erase(j);

    for (auto it = basecopy.begin(); it != basecopy.end(); ++it)
        if (!visited[*it])
            DFSUtil(*it);
}

int connectedComponents(int n)
{
    int count = 0;

    for (int v = 1; v <= n; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v);
            ++count;
        }
    }

    return count;
}

int main()
{
    int m;
    cin >> n >> m;
    
    unordered_set<int> maxbase;

    for (auto i = 1; i <= n; ++i)
    {
        visited[i] = true;
        maxbase.emplace(i);
    }

    for (auto i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        noes[a].emplace_back(b);
        noes[b].emplace_back(a);
    }

    auto minIndex = -1;
    auto minCount = 100001;
    for (auto i = 1; i<=n; ++i)
    {
        if (noes[i].size() < minCount)
        {
            minIndex = i;
            minCount = noes[i].size();
        }
    }

    for (const auto& no : noes[minIndex])
    {
        visited[no] = false;
        base.emplace(no);
        maxbase.erase(no);
    }

    for (const auto& yes : maxbase)
        DFSUtil(yes);

    auto count = connectedComponents(n);
    cout << count;
}
