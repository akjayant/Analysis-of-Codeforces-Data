#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int main( )
{

    int n;
    cin>>n;
    int x[n];
    for(int i = 0 ; i < n; i ++)
        cin>>x[i];
    sort(x,x+n);
    ll X=0,Y=0;
    for(int i = 0 ; i < n; i++)
    {
        if(i<n/2)
            X+=x[i];
        else
            Y+=x[i];
    }
    cout<<fixed<<setprecision(0)<<(X*X)+ (Y*Y)<<endl;


}


