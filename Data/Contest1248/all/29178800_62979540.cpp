#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n+1];
    int i;
    long long ans1=0,ans2=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int c=n/2+(n%2);
    for(i=n;i>=(n-c+1);i--)
    {
        ans1+=a[i];
    }
    for(;i>=1;i--)
    {
        ans2+=a[i];
    }
    cout<<(ans1*ans1)+(ans2*ans2)<<endl;
}

