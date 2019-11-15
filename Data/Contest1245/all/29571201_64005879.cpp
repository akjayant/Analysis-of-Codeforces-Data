#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
char str[110], kk[110];
int main()
{
    int r, p, s, n, t;
    cin>>t;
    while(t--){
        r = p = s = 0;
        scanf("%d", &n);
        scanf("%d%d%d", &r, &p, &s);
        scanf("%s", str + 1);
        for (int i = 1; i <= n; ++i){
            if (str[i] == 'R') {
                if (p) p--, str[i] = 'P';
                else str[i] = '.';
            } else if (str[i] == 'P') {
                if (s) s--, str[i] = 'S';
                else str[i] = '.';
            } else {
                if (r) r--, str[i] = 'R';
                else str[i] = '.';
            }
        }
        int ans = n - p - s - r;
        // cout<<ans<<endl;
        if (ans >= (n + 1) / 2) {
            printf("YES\n");
            for (int i = 1; i <= n; ++i){
                if (str[i] == '.'){
                    if (p) p--, str[i] = 'P';
                    else if (r) r--, str[i] = 'R';
                    else s--, str[i] = 'S';
                }
            }
            printf("%s\n", str + 1);
        } else printf("NO\n");
    }    
    // system("pause");
}