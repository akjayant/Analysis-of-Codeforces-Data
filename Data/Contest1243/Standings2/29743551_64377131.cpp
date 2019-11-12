#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        sort(a+1,a+1+n);
        int mx=0;
        for(int i=n; i>=1; i--) mx=max(mx,min(n-i+1,a[i]));
        cout<<mx<<endl;
    }
}
