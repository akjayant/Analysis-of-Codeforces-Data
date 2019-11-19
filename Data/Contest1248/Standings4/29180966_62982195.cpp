#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],x,y;
int main() 
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0; i<n/2; i++)
    {
        x+=a[n-i-1];
        y+=a[i];
    }
    if (n%2==1)
        x+=a[n/2];
    cout<<x*x+y*y<<endl;
    return 0;
}