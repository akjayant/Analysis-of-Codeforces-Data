#include<bits/stdc++.h>
using namespace std;
map <int,int> mp, visited;
map <int, set<int>> v;

int main(){

    int n, m, a, b, cmp;
    cin>>n>>m;

    for(int i = 0; i < m;i++){
        cin>>a>>b;
        v[a].insert(b);
        v[b].insert(a);
    }
    set <int>st;
    for(int i=1;i<=n;i++){
		st.insert(i);
	}
    vector<int>ans;
    while(st.size())
    {
        cmp = 0;
        queue <int>q;
        q.push(*st.begin());
        st.erase(st.begin());
        while(q.size()){
            int p = q.front(); q.pop();
            auto it = st.begin();
            while(it != st.end())
            {
                if(v[p].find(*it)!=v[p].end())++it;
                else{
                    q.push(*it);
                    cmp++;
                    it=st.erase(it);
                }
            }
        }
        ans.push_back(cmp);
    }
   
    cout<<ans.size()-1;
    return 0;
}
