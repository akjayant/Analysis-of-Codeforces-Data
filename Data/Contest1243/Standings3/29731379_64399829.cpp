#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,n,m,q,b,c,d,l,r;
    cin>>t;
    vector<vector<pair<int,int> > >v(t);
    for(int tt=0; tt<t; tt++)
    {
        cin>>n;
        string S,T;
        cin>>S>>T;
        int u=0;
        for(int i=0; i<n; i++)
        {
            if(S[i]!=T[i])
            {
                int o=0;
                for(int j=i+1; j<n; j++)
                {
                    pair<int,int>p;
                    if(S[j]==S[i]){swap(S[j],T[i]);p.first=j;p.second=i;v[tt].push_back(p);o=1;break;}
                    else
                    {
                        if(T[j]==S[i]){swap(S[j],T[j]);p.first=j;p.second=j;v[tt].push_back(p);swap(S[j],T[i]);p.first=j;p.second=i;v[tt].push_back(p);o=1;break;}
                    }
                }
                if(o==0)u=1;
            }
        }
        if(u==1)cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<" "<<v[tt].size()<<endl;
            for(int i=0; i<v[tt].size(); i++)cout<<v[tt][i].first+1<<" "<<v[tt][i].second+1<<endl;
        }
    }
}
