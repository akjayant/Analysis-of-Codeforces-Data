//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>m;
        int brr[m];
        for(int i=0;i<m;i++)
            cin>>brr[i];
        int ct1[2]={};
        int ct2[2]={};
        for(int i=0;i<n;i++)
            ct1[arr[i]%2]++;
        for(int i=0;i<m;i++)
            ct2[brr[i]%2]++;
        int ans=ct1[0]*ct2[0]+ct1[1]*ct2[1];
        cout<<ans<<endl;
    }
}