#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;
int n;
char s[105], t[105];

int cnt[128];
set<int> accs[128];
set<int> acct[128];

vector<pair<int, int> > op;

int main() {
#ifdef Yinku
    freopen("Yinku.in", "r", stdin);
#endif // Yinku
    scanf("%d", &k);
    while(k--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        for(int c = 'a'; c <= 'z'; ++c) {
            accs[c].clear();
            acct[c].clear();
        }
        for(int i = 1; i <= n; ++i) {
            ++cnt[s[i]];
            ++cnt[t[i]];
            accs[s[i]].insert(i);
            acct[t[i]].insert(i);
        }
        bool suc = 1;
        for(int c = 'a'; c <= 'z'; ++c) {
            if(cnt[c] & 1) {
                suc = 0;
                break;
            }
        }
        if(suc) {
            puts("Yes");
            op.clear();
            for(int i = 1; i <= n; ++i) {
                //cout<<(s+1)<<" "<<(t+1)<<endl;
                //固定si
                accs[s[i]].erase(i);
                if(s[i] == t[i]) {
                    //固定ti
                    acct[t[i]].erase(i);
                    continue;
                } else {
                    if(accs[s[i]].size()) {
                        //cout<<"from s"<<endl;
                        //从没有固定的si中找一个补到ti
                        int id = *accs[s[i]].begin();
                        accs[s[id]].erase(id);
                        accs[t[i]].insert(id);
                        acct[t[i]].erase(i);
                        acct[s[id]].insert(i);
                        op.push_back({id, i});
                        swap(t[i], s[id]);
                    } else {
                        //cout<<"from t"<<endl;
                        //从没有固定的ti中换两次过去
                        int id = *acct[s[i]].begin();
                        accs[s[n]].erase(n);
                        accs[t[id]].insert(n);
                        acct[t[id]].erase(id);
                        acct[s[n]].insert(id);
                        op.push_back({n, id});
                        swap(t[id], s[n]);
                        //cout<<(s+1)<<" "<<(t+1)<<endl;

                        //从没有固定的si中找一个补到ti
                        id = *accs[s[i]].begin();
                        accs[s[id]].erase(id);
                        accs[t[i]].insert(id);
                        acct[t[i]].erase(i);
                        acct[s[id]].insert(i);
                        op.push_back({id, i});
                        swap(t[i], s[id]);
                    }

                    acct[t[i]].erase(i);
                }
            }

            printf("%d\n", (int)op.size());
            for(auto i : op) {
                printf("%d %d\n", i.first, i.second);
            }
        } else {
            puts("No");
        }
    }
}
