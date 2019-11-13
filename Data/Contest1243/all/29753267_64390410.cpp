#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5;
int cnt[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        int n;
        cin>>n;
        cin>>s>>t;
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<n;i++)
            cnt[t[i]-'a']++;
        bool ok=1;
        for(int i=0;i<26;i++)
            if(cnt[i]%2)
                ok=0;
        if(!ok)
        {
            cout<<"No"<<'\n';
            continue;
        }
        vector< pair<int,int> >v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i]) continue;
            bool done=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    done=1;
                    swap(s[j],t[i]);
                    v.push_back({j,i});
                    break;
                }
            }
            if(done) continue;
            for(int j=i+1;j<n;j++)
                if(s[i]==t[j])
                {
                    swap(s[j],t[j]);
                    v.push_back({j,j});
                    break;
                }
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    done=1;
                    swap(s[j],t[i]);
                    v.push_back({j,i});
                    break;
                }
            }
        }
        if(s!=t) assert(0);
        cout<<"Yes"<<'\n';
        cout<<(int)v.size()<<'\n';
        for(auto p:v)
            cout<<p.first+1<<" "<<p.second+1<<'\n';
    }
    return 0;
}
