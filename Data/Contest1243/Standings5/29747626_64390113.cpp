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

            string s, t;
            cin>>s>>t;

            //cout<<s<<" "<<t<<endl;

            char s1;
            char t1;

            int flag=0;

            REP(i,0,n){

                if(flag==0){
                    if(s[i]!=t[i]){
                        s1=s[i];
                        t1=t[i];
                        flag=1;
                        //cout<<i<<"  0"<<endl;
                    }
                }
                else if(flag==1){
                    if(s[i] != t[i]){
                        if(s[i]==s1 && t[i]==t1){
                            flag =2;
                        }

                        else{
                            flag=-2;

                        }
                        //cout<<i<<"  1"<<endl;
                    }

                }

                else if(flag==2){
                    if(s[i]!=t[i]){
                        flag=-1;
                        //cout<<i<<"  2"<<endl;
                    }

                }
            }

            //cout<<flag<<"flag"<<endl;

            if(flag==2){
                cout<<"YES"<<endl;

            }
            else{
                cout<<"NO"<<endl;
            }

      }

return 0;
}
