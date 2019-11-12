#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

ll power(ll x,ll y)
{
      ll res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)%HOLE;

        // n must be even now
        y = y >> 1; // y = y/2
        x = (x * x)%HOLE; // Change x to x^2
    }
    return res;
}

int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      ll q=1;
      cin>>q;
      while(q--)
      {
            ll n;
            cin>>n;

            ll a[n];


            int flag=0;
            REP(i,0,n)
            {
                  cin>>a[i];
            }

            sort(a,a+n);

            ll csize=n;
            ll msize=0;

            for(ll i=n-1; i>=0; i--){

                csize=min(n-i, a[i]);
                if(csize<msize){
                    break;
                }
                else{
                    msize=csize;
                }

            }

            cout<<msize<<endl;

      }

return 0;
}
