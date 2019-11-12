#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
int ans[100][2],ac=0;
int cnt[26];
int main() {
    ll k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ll n;
        cin >> n;
        string a, b;
        ac=0;
        cin >> a >> b;
        for (int j = 0; j < 26; ++j) {
            cnt[j]=0;
        }
        for (int j = 0; j < n; ++j) {
            cnt[a[j]-'a']++;
            cnt[b[j]-'a']++;
        }
        for (int j = 0; j < 26; ++j) {
            if(cnt[j]%2!=0){
                cout <<"No\n";
                goto end;
            }
        }
        for (int j = 0; j < n; ++j) {
            if(a[j] == b[j])
                continue;
            for (int l = 0; l < n; ++l) {
                if(a[l] == b[l] or l==j)
                    continue;
                if(a[j]==a[l] || a[j]==b[l]){
                    if(a[j]==b[l])
                    {
                        ans[ac][0]=l+1;
                        ans[ac++][1]=l+1;
                        swap(a[l],b[l]);
                    }
                    if(b[l]!=b[j]){
                        for (int kk = 0; kk < n; ++kk) {
                            if(a[kk] == b[kk] or kk==l or kk==j)
                                continue;
                            if(b[j]==a[kk]){
                                ans[ac][0]=kk+1;
                                ans[ac++][1]=l+1;
                                swap(a[kk],b[l]);
                                break;
                            }
                            if(b[j]==b[kk]){
                                ans[ac][0]=kk+1;
                                ans[ac++][1]=kk+1;
                                swap(a[kk],b[kk]);
                                ans[ac][0]=kk+1;
                                ans[ac++][1]=l+1;
                                swap(a[kk],b[l]);
                                break;
                            }

                        }
                    }
                    ans[ac][0]=l+1;
                    ans[ac++][1]=j+1;
                    swap(a[l],b[j]);
                    break;
                }
            }

        }
        cout <<"Yes\n";
        cout << ac << endl;
        for (int m = 0; m < ac; ++m) {
            cout << ans[m][0] << " " << ans[m][1] << endl;
        }
        end:;
    }
}