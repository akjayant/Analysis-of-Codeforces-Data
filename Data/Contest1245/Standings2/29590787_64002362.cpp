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
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        int mm[4]={0};
        mm[1]=a;
        mm[2]=b;
        mm[3]=c;
        string s;
        cin>>s;
        char ans[n];
        fill_n(ans,n,'z');
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R'&&mm[2]>0)
            {
                ans[i]='P';
                mm[2]--;
            }
            else if(s[i]=='P'&&mm[3]>0)
            {
                ans[i]='S';
                mm[3]--;
            }
            else if(s[i]=='S'&&mm[1]>0)
            {
                ans[i]='R';
                mm[1]--;
            }
        } 
        bool flag=true;
        if(n-(mm[1]+mm[2]+mm[3])<(n+1)/2)
        {
            flag=false;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]=='z')
            {
                if(mm[1]>0)
                {
                    ans[i]='R';
                    mm[1]--;
                }
                else if(mm[2]>0)
                {
                    ans[i]='P';
                    mm[2]--;
                }
                 else if(mm[3]>0)
                {
                    ans[i]='S';
                    mm[3]--;
                }
            }
        }
        if(flag)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
                cout<<ans[i];
                cout<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
        

    }
    
    
// -------------------------------------Code ends here------------------------------------------------------
 
     clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }