#include <bits/stdc++.h>

using namespace std;
const int maxn = 200006;
typedef long long ll;
int cnt[5];
// R P S
char s[200];
char ss[200];
int main() {

    ll t;
    cin>>t;
    while (t--) {
        int ans = 0;
        int n ;
        cin>>n;
        for (int i=1;i<=3;i++) {
            cin>>cnt[i];
        }
        cin>>s;
        memset(ss,0,sizeof ss);

        for (int i=0;i<n;i++) {
            if (s[i]=='S' && cnt[1] ) {
                ss[i]='R';
                cnt[1]--;
                ans ++;
            }else if (s[i]=='R' && cnt[2] ) {
                ss[i]='P';
                cnt[2]--;
                ans++;
            }else if (s[i]=='P' && cnt[3] ) {
                ss[i]='S';
                cnt[3]--;
                ans++;
            }
        }
        if (ans * 2 >= n) {
            cout<<"YES"<<endl;
            for (int i=0;i<n;i++) {
                if (ss[i]==0) {
                    if (cnt[1]) {
                        ss[i]='R';
                        cnt[1]--;
                    } else if (cnt[2]) {
                        ss[i]='P';
                        cnt[2]--;
                    } else if (cnt[3]) {
                        ss[i]='S';
                        cnt[3]--;
                    }
                }
            }
            cout<<ss<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }


    return 0;
}
