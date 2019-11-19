          #include <bits/stdc++.h>
          using namespace std;
          #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
          #define M_PI 3.14159265358979323846
          #define data data_
          #define ff first
          #define ss second
          long long const mod = 1e9+7;

          long long mod_power(long long base,long long n,long long mod)
          {
               long long res=1;
               base%=mod;
               while(n>0)
               {
               if(n&1)res=(res*base)%mod;
               base=(base*base)%mod;
               n/=2;
               }
               return res%mod;
          }

          int main()
          {
          clock_t begin = clock();
          #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
          #endif
          tani_nachi_ke  

          int n,m;
          cin >> n >> m;
          long long dp[100009][4];
          memset(dp,0,sizeof(dp));
          for(int i = 0; i < 4; i++)
               dp[2][i] = 1;

          for(int i = 3; i <= max(n,m); i++)
          {
               dp[i][0] = dp[i-1][2];
               dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
               dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
               dp[i][3] = dp[i-1][1];
          }
          if(n > m)
               swap(n,m);
          long long ans = 0;
          for(int i = 0; i < 4; i++)
               ans = (ans + dp[m][i])%mod;
          if(n==1)
          {
               if(m==1)
                    cout << 2 << endl;
               else
                    cout << ans << endl;
          }
          else
          {
              long long cur = 0;
              for(int i = 0; i < 4; i++)
               cur = (cur + dp[n][i])%mod;
               cout << (cur + ans - 2 + mod)%mod << endl;
          }


          #ifndef ONLINE_JUDGE 
          clock_t end = clock();
          cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
          #endif 
          return 0;
          }