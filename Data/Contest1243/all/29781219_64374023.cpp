#include <bits/stdc++.h>
using namespace std;
int a[10002];
int main ()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=1;i<=n;i++)
            if(a[n-i]<i)
                break;
        cout<<i-1<<"\n";
    }
    return 0;
}