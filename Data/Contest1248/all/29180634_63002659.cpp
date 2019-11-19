                // never give up :))))
                #include <bits/stdc++.h>
                #define mp make_pair
                #define f1 first
                #define f2 second
                #define pb push_back
                #define pii pair<int ,int>
                #define int long long
                #define ios  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
                using namespace std;
                const int mox=1e5+9;
                int z=1e9+7;
                int dp[mox];
                main()
                {   ios
                  int n,m;
                  cin>>n>>m;
                  dp[0]=1;
                  dp[1]=1;
                  for(int i=2 ; i<=max(m,n) ; i++)
                  {
                      dp[i]=(dp[i-1]+dp[i-2])%z;
                  }
                  int ans=(dp[n]+dp[m])%z;
                  ans=(ans-1+z)%z;
                  ans=(ans*2)%z;
                    cout<<ans;

                }
