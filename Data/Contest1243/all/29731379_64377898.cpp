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
        for(int i=0; i<n; i++){cin>>a;v[tt].push_back(a);}
        sort(v[tt].begin(),v[tt].end());
        int y=0;
        for(int i=0; i<n; i++)if(v[tt][n-i-1]<i+1){cout<<i<<endl;y=1;break;}
        if(y==0)cout<<n<<endl;
    }
}
