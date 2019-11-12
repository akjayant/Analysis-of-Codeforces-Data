#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;
int n;
char s[10005], t[10005];

int main() {
#ifdef Yinku
    freopen("Yinku.in", "r", stdin);
#endif // Yinku
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        vector<int> dif;
        for(int i = 1; i <= n; ++i) {
            if(s[i] != t[i])
                dif.push_back(i);
        }
        if(dif.size() == 1 || dif.size() >= 3) {
            puts("No");
        } else {
            if(dif.size() == 0)
                puts("Yes");
            else {
                swap(s[dif[0]], t[dif[1]]);
                if(strcmp(s + 1, t + 1) == 0)
                    puts("Yes");
                else
                    puts("No");
            }
        }
    }
}
