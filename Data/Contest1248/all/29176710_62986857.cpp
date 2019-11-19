#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100009],l1,l2;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++)l1+=a[i];
    for(int i=n/2;i<n;i++)l2+=a[i];
    cout<<l1*l1+l2*l2;
}
