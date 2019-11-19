#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll modpow(ll a, ll b){

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int sm = 0;

    for(int i = 0; i < n; i++) {
        sm += ((s[i] == '(') ? 1 : -1);
    }

    if(sm != 0) {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }

    int mxans = -1;
    int si, sj;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if((s[i] == s[j]) && (i != 0)) continue;
            
            swap(s[i], s[j]);

            vector<int> cnt(2*n + 5, 0);

            cnt[0] = (s[0] == '(') ? 1 : -1;

            for(int k = 1; k < n; k++) {
                cnt[k] = cnt[k-1] + ((s[k] == '(') ? 1 : -1);
            }

            for(int k = n; k < 2*n; k++) {
                cnt[k] = cnt[k-n];
            }

            vector<int> freq(1010, 0);

            for(int k = 0; k < n; k++) {
                freq[cnt[k]+505]++;
            }

            int ans = 0;

            if(freq[-1+505] == 0) {
                ans++;
            }

            for(int k = n; k < 2*n - 1; k++) {

                if(ans + 2*n - 1 - k < mxans) break;

                freq[cnt[k]+505]++;
                freq[cnt[k-n]+505]--;
                if(freq[cnt[k-n]-1+505] == 0) {
                    ans++;
                }
            }

            if(ans > mxans) {
                mxans = ans;
                si = i;
                sj = j;
            }

            swap(s[i], s[j]);

            if(mxans == n/2) break;
        }

        if(mxans == n/2) break;
    }

    cout<<mxans<<endl;
    cout<<si+1<<" "<<sj+1<<endl;

}
