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
      //cin>>q;
      while(q--)
      {
            ll n;
            cin>>n;

            ll flag=0;

            ll sq = sqrt(n);

           // cout<<sq<<endl;

           ll hf=n;

            REP(i, 2, (sq+1)){

               // cout<<i<<endl;

                if((n%i)==0){
                    //cout<<i<<endl;
                    hf = __gcd(i,hf);
                    hf = __gcd((n/i), hf);
                    flag=1;
                    //cout<<i<<" I"<<endl;
                }



            }

            {
                cout<<hf<<endl;
            }


      }

return 0;
}
