#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001],b[100001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
           // b[i]=min(a[i],n-i+1);
        }
        sort(a+1,a+n+1);
        int res=INT_MIN;
        for(int i=1;i<=n;i++)
        res=max(res,min(n-i+1,a[i]));
        cout<<res<<endl;
    }
}
