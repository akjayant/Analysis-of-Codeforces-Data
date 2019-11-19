#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int da[maxn];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>da[i];
    }
    sort(da,da+n);
    long long a = 0,b = 0;
    for(int i =0;i<n/2;i++){
        a += da[i];
    }
    for(int i = n/2;i<n;i++){
        b += da[i];
    }
    cout<<a*a+b*b<<endl;
    return 0;
}
