#include<bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define int long long int
#define S second
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const int MOD = 998244353;
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp>  
//using namespace __gnu_pbds; 
//stringstream ss; string temp; ss<<str(original string) ss>>temp;

int32_t main()
{   
    boost
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--)
    {
        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        int pen = a/c;
        int cil = b/d;
        if(a%c!=0) pen++;
        if(b%d!=0) cil++;
        if(pen+cil <= k)
        {
            cout<<pen<<" "<<cil<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
} 
