#include <bits/stdc++.h>

using namespace std;
long long n,a[100100],x,y;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)
        x+=a[i];
    for(int i=n/2+1;i<=n;i++)
        y+=a[i];
    cout<<x*x+y*y;
    return 0;
}
