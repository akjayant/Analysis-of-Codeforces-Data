#include <bits/stdc++.h>
#include <set>
#define ll long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MAXX  200005
#define MAX 1000000000
using namespace std;
 
long int n;
set<long int> s1;
set<long int> s2[MAXX];
vector<long> v;
 
void bfs(int i)
{
    long int count=0;
    queue<long int> q;
    q.push(i);
    s1.erase(i);
    while(!q.empty())
    {
        vector<long int> aux;
        long int v = q.front();
        q.pop();
        count++;
        for (auto it = s1.begin() ; it != s1.end() ; it++)
        {
            long int u = *it;
            if (s2[v].find(u) == s2[v].end())
            {
                //count++;
                aux.push_back(u);
                //cout << i << " " << u << endl;
                q.push(u);
            }
        }
        for (int z = 0 ; z < aux.size() ; z++)
            s1.erase(s1.find(aux[z]));
    }
    v.push_back(count);
    //cout << i << " " << count << endl;
}
int main() 
{
    long int m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        s1.insert(i);
    for (int i = 1 ; i <= m ; i++)
    {
        ll l,r;
        cin >> l >> r;
        s2[l].insert(r);
        s2[r].insert(l);
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (s1.find(i) != s1.end())
            bfs(i);
    }
    sort(v.begin() , v.end());
    cout << v.size() - 1 << endl;
    return 0;
}