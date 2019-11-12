#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,n,m,q,a,b,c,d,l,r;
    cin>>t;
    vector<vector<int> >v(t);
    for(int tt=0; tt<t; tt++)
    {
        cin>>n;
        string S,T;
        cin>>S>>T;
        int k=0;
        for(int i=0; i<n; i++)if(S[i]!=T[i]){k++;v[tt].push_back(i);}
        if(k!=0&&k!=2)cout<<"NO"<<endl;
        else
        {
            if(k==0)cout<<"YES"<<endl;
            else
            {
                if(S[v[tt][0]]==S[v[tt][1]]&&T[v[tt][0]]==T[v[tt][1]])cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
}
