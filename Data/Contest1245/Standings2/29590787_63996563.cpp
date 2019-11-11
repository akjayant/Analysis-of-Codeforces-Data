 #pragma comment(linker, "/stack:200000000")
 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 #include<bits/stdc++.h>
 #define int long long
 using namespace std;

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

    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1)
            cout<<"Finite\n";
        else
        {
            cout<<"Infinite\n";
        }
        
    }
    
    
// -------------------------------------Code ends here------------------------------------------------------
 
     clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }