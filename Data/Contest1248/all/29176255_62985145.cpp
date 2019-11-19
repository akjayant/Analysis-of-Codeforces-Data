#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long v[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> v[i];
    sort(v+1,v+n+1);
    long long s1=0,s2=0;
    for (int i = 1; i<=n/2; i++)
        s1+=v[i];
    for (int i = n/2+1; i<=n; i++)
        s2+=v[i];
    cout << s1*s1+s2*s2;
}
