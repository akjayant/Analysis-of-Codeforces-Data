#include<bits/stdc++.h>
#define m_p make_pair
#define ss second
#define ff first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e5+5;
set<int> st;
int k=0;
map<pair<int, int>, bool> mp;

void dfs(int v)
{
    vector<int> vec;
    for(auto to:st)
    {
        int x = to, y = v;
        if (x > y) swap(x, y);
        if (mp[m_p(x, y)]) continue;
        vec.pb(to);
    }
    for (int i=0; i<vec.size(); ++i)
        st.erase(vec[i]);
    for (int i=0; i<vec.size(); ++i)
        dfs(vec[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i=0;i<m; ++i)
    {
        cin >> x >> y;
        if (x > y) swap(x, y);
        mp[m_p(x, y)]=1;
    }
    for (int i=1; i<=n; ++i)
        st.insert(i);
    while(st.size()!=0)
    {
        int v = *st.begin();
        st.erase(st.begin());
        k++;
        dfs(v);
    }
    cout << k-1;



}
