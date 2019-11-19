#include <bits/stdc++.h>
#define ll long long
#define forin for(int i=0;i<n;i++)
#define forim for(int i=0;i<m;i++)
#define forjn for(int j=0;j<n;j++)
#define forjm for(int j=0;j<m;j++)
using namespace std;

int main()
{
    ll n,sum1=0,sum2=0;
    cin>>n;
    vector<int>a(n);
    forin{
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n/2;i++){
        sum1+=a[i];
    }
    for(int i=n/2;i<n;i++){
        sum2+=a[i];
    }
    cout<<sum1*sum1+sum2*sum2;
    return 0;
}
