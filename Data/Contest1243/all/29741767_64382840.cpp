#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1005];
char s[10005], t[10005];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d %s %s", &n, s, t);
        vector<int> v;
        bool flag = true;
        for(int i = 0; i < n; ++i) {
            if(s[i] != t[i]) {
                v.push_back(i);
                if(v.size() > 2) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) {
            printf("No\n");
            continue;
        }
        if(v.size() == 1) printf("No\n");
        else if(v.size() == 0) printf("Yes\n");
        else {
            char temp = t[v[1]];
            t[v[1]] = s[v[0]];
            s[v[0]] = temp;
            if(s[v[0]] == t[v[0]] && s[v[1]] == t[v[1]])
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}