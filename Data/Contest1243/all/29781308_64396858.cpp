#include<bits/stdc++.h>
using namespace std;
const int N = 100;
typedef long long ll;
typedef pair<int, int> pii;
int k;
int n;
char s[N], t[N];
vector<pii> ve;
int main() {
    scanf("%d", &k);
    while(k--) {
        ve.clear();
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        char tmp;
        int ind = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == t[i]) continue;
            int fl = 0;
            for(int j = i + 1; j <= n; j++) {
                if(s[j] == s[i]) {
                    ve.push_back(pii(j, i));
                    tmp = s[j];
                    s[j] = t[i];
                    t[i] = tmp;
                    fl = 1;
                    break;
                }
            }
            if(fl == 0) {
                for(int j = i + 1; j <= n; j++) {
                    if(t[j] == t[i]) {
                        ve.push_back(pii(i, j));
                        tmp = s[i];
                        t[j] = s[i];
                        s[i] = tmp;
                        fl = 1;
                        break;
                    }
                }
            }
            if(fl == 0) {
                for(int j = i + 1; j <= n; j++) {
                    if(t[j] == s[i]) {
                        ve.push_back(pii(j, j));
                        ve.push_back(pii(j, i));
                        tmp = s[j];
                        s[j] = t[j];
                        t[j] = tmp;
                        tmp = s[j];
                        s[j] = t[i];
                        t[i] = tmp;
                        fl = 1;
                        break;
                    }
                }
            }
            if(fl == 0) {
                for(int j = i + 1; j <= n; j++) {
                    if(s[j] == t[i]) {
                        ve.push_back(pii(j, j));
                        ve.push_back(pii(i, j));
                        tmp = s[j];
                        s[j] = t[j];
                        t[j] = tmp;
                        tmp = s[i];
                        s[i] = t[j];
                        t[j] = tmp;
                        fl = 1;
                        break;
                    }
                }
            }
//            printf("%s\n%s\n", s + 1, t + 1);
            if(fl == 0) {
                ind = 1;
//                printf("%d\n", i);
                break;
            }
        }
        if(ind == 1) {
            printf("No\n");
        }
        else {
            printf("Yes\n%d\n", ve.size());
            for(int i = 0; i < ve.size(); i++) {
                printf("%d %d\n", ve[i].first, ve[i].second);
            }
        }
    }
    return 0;
}
