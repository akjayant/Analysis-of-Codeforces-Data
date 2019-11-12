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

            string s,t;
            cin>>s>>t;

            vector <pair<ll,ll> > swaps;
            ll nswaps=0;

            int flag=0;
            int flag1=0;
            REP(i,0,n){

                flag=0;
                  if(s[i]!=t[i]){
                        REP(j,i+1,n){
                            if(s[j]==s[i]){
                                swaps.PB(MP(j,i));
                                nswaps++;
                                flag=1;
                                char temp=s[j];
                                s[j]=t[i];
                                t[i]=temp;
                                //cout<<j<<" "<<s[j]<<i<<t[i]<<endl;
                                break;
                            }

                        }
                        if(flag==0){
                            REP(j,i+1,n){
                                if(t[j]==s[i]){
                                    swaps.PB(MP(i+1,j));
                                    swaps.PB(MP(i+1,i));
                                    nswaps+=2;
                                    flag=1;
                                    char temp=t[j];
                                    t[j]=s[i+1];
                                    s[i+1]=t[i];
                                    t[i]=temp;
                                    break;
                                }

                            }


                        }

                        if(flag==0){
                            cout<<"NO"<<endl;
                            //cout<<s[i]<<" "<<t[i]<<endl;
                            flag1=1;
                            break;
                        }
                  }
            }

            if(flag1==0){
                cout<<"YES"<<endl;
                cout<<nswaps<<endl;
                REP(i,0,swaps.size()){
                    cout<<swaps[i].first+1<<" "<<swaps[i].second+1<<endl;
                }

            }

      }

return 0;
}
