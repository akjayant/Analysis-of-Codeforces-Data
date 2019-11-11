#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        int b[3]; b[0] = b[1] = b[2] = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            char x = s[i];
            if (x == 'R') b[0]++;
            if (x == 'P') b[1]++;
            if (x == 'S') b[2]++;
        }
        int ans = 0;
        int w[3];
        for (int i = 0; i < 3; i++){
            w[i] = min(a[(i+1)%3],b[i]);
            b[i] -= w[i];
            a[(i+1)%3] -= w[i];
            ans += w[i];
        }
        if (ans < (n-1)/2 + 1) {
            printf("NO\n");
        }
        else{
            printf("YES\n");
            char ans[n];
            fill(ans,ans+n,'@');
            for (int i = 0; i < n; i++){
                if (s[i] == 'R' && w[0]){
                    w[0]--;
                    ans[i] = 'P';
                }
                if (s[i] == 'P' && w[1]){
                    w[1]--;
                    ans[i] = 'S';
                }
                if (s[i] == 'S' && w[2]){
                    w[2]--;
                    ans[i] = 'R';
                }
            }
            for (int i = 0; i < n; i++){
                if (ans[i] == '@'){
                    if (a[0]){
                        a[0]--;
                        ans[i] = 'R';
                    }
                    else if (a[1]){
                        a[1]--;
                        ans[i] = 'P';
                    }
                    else if (a[2]){
                        a[2]--;
                        ans[i] = 'S';
                    }
                }
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
}
