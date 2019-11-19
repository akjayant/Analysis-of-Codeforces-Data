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
    ll n;
    cin>>n;
    ll N = n;
    ll x;
    ll cnt = 0;
    ll ld = -1;
    for( x = 2; x*x <= n; x++){
        if(n%x == 0){
            if(ld == -1)ld = x;
            cnt++;
            while(n%x ==0 )n /= x;
        }
    }

    if(n > 1 && n != N)cnt++;

    n = N;

    if(cnt > 1){
        cout<< 1 << endl;
    }
    else if(cnt == 0){
        cout<< n << endl;
    }
    else{
        cout<< ld << endl;
    }

}
