#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main(){
    int test;
    test = 1;
    while(test--){
        int n, ansl = 1, ansr = 1, ans = 0;
        char s[N];
        scanf("%d", &n);
        scanf("%s", s + 1);
        for(int l = 1; l <= n; l++){
            for(int r = l; r <= n; r++){
                swap(s[l], s[r]);
                int fail = 0, tot = 0, cnt = 0, maxi_cnt = 0, lidx = 0;
                for(int i = 1; i <= n; i++){
                    cnt += (s[i] == '(');
                    cnt -= (s[i] == ')');
                    if(maxi_cnt > cnt){
                        maxi_cnt = cnt;
                        lidx = i;
                    }
                }
                if(cnt != 0){
                    fail = 1;
                }
                if(fail == 0){
                    cnt = 0;
                    for(int i = lidx + 1; i <= n; i++){
                        cnt += (s[i] == '(');
                        cnt -= (s[i] == ')');
                        if(cnt == 0){
                            tot++;
                        }  
                    }
                    for(int i = 1; i <= lidx; i++){
                        cnt += (s[i] == '(');
                        cnt -= (s[i] == ')');
                        if(cnt == 0){
                            tot++;
                        }
                    }
                }
                swap(s[l], s[r]);
                if(fail == 0 && tot > ans){
                    ansl = l, ansr = r, ans = tot;
                }
            }
        }
        printf("%d\n", ans);
        printf("%d %d\n", ansl, ansr);
    }
    return 0;
}