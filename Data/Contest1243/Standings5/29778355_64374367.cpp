                       //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back


using namespace std;

typedef long long ll;

const int MAXN = 100001;
const int mod = 1000000007;

int main(){
    inp_out_work
    testCase{
        int n;
        cin>>n;
        int a[n];
        fr(i,n)cin>>a[i];
        int ans =0;
        for(int i = 1; i <= n; i++){
            int l = 0;
            fr(j,n)if(a[j] >= i)l++;
            if(l >= i)ans = i;
        }
        cout<< ans << endl;
    }
}
