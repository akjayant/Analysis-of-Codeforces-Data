#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define line cout<<"---------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
int  main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string str,str1;
    cin>>str>>str1;
    int cnt=0;
    vector<pair<char,char> > v;
    if(str==str1)
    {
        cout<<"Yes"<<endl;
        continue;
    }
    for(int i=0;i<n;i++)
    {
        if(str[i]!=str1[i]) v.pb(mp(str[i],str1[i]));
    }
    if(v.size()>2 or v.size()==1) cout<<"No"<<endl;
    else
    {
        if(v[0].first!=v[1].first or v[0].second!=v[1].second)     cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    }

}
