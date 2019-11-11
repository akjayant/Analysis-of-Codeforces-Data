                // in the name of allah
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
                {
                     ios
                     string s;
                     cin>>s;
                     if(s[0]!='w'&&s[0]!='m')
                        dp[0]=1;
                        int n=s.size();
                        dp[-1]=1;
                     for(int i=1 ; i<n ; i++)
                     {
                         if(s[i]!='w'&&s[i]!='m')
                           {
                               if(s[i]!='u'&&s[i]!='n')
                               {
                                   dp[i]=dp[i-1];
                               }
                               else
                               {
                                   if(s[i]==s[i-1])
                                   {
                                       dp[i]=(dp[i-1]+dp[i-2])%z;
                                   }
                                   else
                                     dp[i]=dp[i-1];
                               }
                           }
                     }
                     cout<<dp[n-1];

                }
