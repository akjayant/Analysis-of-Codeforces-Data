#include<bits/stdc++.h>
using namespace std;

auto clk=clock();
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define Mod 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define all(x) x.begin(),x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;
        int ans=min(b,c/2);
        b-=ans;
        ans=ans*3;
        ans+=3*min(a,b/2);
        cout<<ans<<"\n";
    }
    cerr<<"\n"<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<"\n";
    return 0;
}
