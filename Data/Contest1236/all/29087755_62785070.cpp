#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define debug(P) cout<<#P<<' '<<P<<endl
#define mod 1000000007
#define MAXN 1001

using namespace std;

int main(){
    inp_out_work
    testCase{
        int a, b, c;
        cin>>a>>b>>c;
        int ans = 0;
        for(int x = 0; x <= a && 2*x <= b; x++){
            int rb = b -2*x;
            for(int y = 0; y <= rb && 2*y <= c; y++){
                ans = max(ans, 3*(x+y));
            }
        }
        cout<< ans << endl;
    }
}
