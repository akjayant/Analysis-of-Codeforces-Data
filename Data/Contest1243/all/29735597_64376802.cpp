#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,mx=0;
        cin>>n;
        vector<int>v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(i=0;i<n;i++)
        {
            int t=min(v[i],i+1);
            mx=max(mx,t);
        }
        cout<<mx<<endl;
    }
}
