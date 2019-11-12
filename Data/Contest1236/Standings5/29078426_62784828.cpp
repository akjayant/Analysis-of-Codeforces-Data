#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define T int t;cin>>t;while(t--)
#define vi vector<int>
#define ff first
#define ss second
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    T{
        int a,b,c;
        cin>>a>>b>>c;
        int t = min(c/2,b);
        int ans = 3*t;
        b-=t;
        ans+= 3*min(b/2,a);
        cout<<ans<<endl;

        
    }
	return 0;
}