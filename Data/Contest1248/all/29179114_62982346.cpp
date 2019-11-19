#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

ll a[200010];

int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

           int n;
           cin>>n;
           for(int i=0;i<n;i++){
            cin>>a[i];
           }
           sort(a,a+n);
           ll x=0,y=0;
           for(int i=0;i<n;i++){
            if(i<n/2)x+=a[i];
            else y+=a[i];
           }
           ll res=x*x + y*y;
           cout<<res<<endl;

            return 0;
}








