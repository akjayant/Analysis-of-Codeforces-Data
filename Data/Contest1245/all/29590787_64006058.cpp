 #pragma comment(linker, "/stack:200000000")
 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 #include<bits/stdc++.h>
 #define int long long
 using namespace std;

int dp[100005][2];
int mod=1e9+7;

signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
 #ifndef ONLINE_JUDGE
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
 #endif
 
     clock_t clk;
 	clk = clock();
 
// -------------------------------------Code starts here--------------------------------------------------------------------- 

    dp[1][0]=1;
    for(int i=2;i<=100000;i++)
    {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=dp[i-1][0];
    }

    string s;
    cin>>s;
    int n=s.length();
    int ans=1;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='u')
        {
            int cnt=0;
            while (s[i]=='u')
            {
                cnt++;
                i++;
                if(i==n)
                    break;
            }
            i--;
            ans=(ans*(dp[cnt][0]+dp[cnt][1]))%mod;
        }
        else if(s[i]=='n')
        {
            int cnt=0;
            while (s[i]=='n')
            {
                cnt++;
                i++;
                if(i==n)
                    break;
            }
            i--;
            ans=(ans*(dp[cnt][0]+dp[cnt][1]))%mod;
        }
        else if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
    }

    cout<<ans;
// -------------------------------------Code ends here------------------------------------------------------
 
     clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }