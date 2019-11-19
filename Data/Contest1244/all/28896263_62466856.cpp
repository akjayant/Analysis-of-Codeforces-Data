#include <bits/stdc++.h>
using namespace std;
  

#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define mod 1000000007
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define dbg2(a,b) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<endl
#define dbg3(a,b,c) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<", "<<#c<<" = "<<c<<endl
#define dbg4(a,b,c,d) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<", "<<#c<<" = "<<c<<", "<<#d<<" = "<<d<<endl
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>

const int nax = 1e5+5;

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    int mi=n;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            mi=min(i,mi);
            mi=min(n-1-i,mi);
        }
    }
    cout<<max(n,2*n-2*mi)<<endl;
}
 

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(13);
    clock_t beg=clock();
    int t = 1; 
    cin>>t;
    // n = t;
    while(t--){
        // cout << "Case #" << n-t << ": ";
        solve();
    }
    //
    clock_t end=clock();
    fprintf(stderr, "%lf sec\n", (double)(end-beg)/(CLOCKS_PER_SEC));
    return 0;
}