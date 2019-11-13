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
int n;
int ara[1009];
int  main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];
    sort(ara,ara+n);
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        int d=n-i;
        ans=max(ans,min(ara[i],d));
    }
    cout<<ans<<endl;
    }
}
