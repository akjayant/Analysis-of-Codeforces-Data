#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tt;
int n;
char s[55];
char t[55];
int diff[55];
int tot;
int ans[205][2];

int main(){
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%s%s",&n,s+1,t+1);
        tot = 0;
        bool flag = 0;
        for(int i=1;i<=n;i++){
            if(s[i] == t[i]) continue;
            if(i==n){
                flag = 1;
                break;
            }
            bool flag2 = 0;

            // set t[i] to s[i]

            for(int j=i+1;j<=n;j++){
                if(t[j] == s[i]) {
                    ans[tot][0] = n;
                    ans[tot][1] = j;
                    tot ++;
                    swap(s[n], t[j]);

                    ans[tot][0] = n;
                    ans[tot][1] = i;
                    tot ++;
                    swap(s[n], t[i]);

                    flag2 = 1;
                    break;
                }
            }
            if(!flag2){
                // 抢救一下
                for(int j=i+1;j<=n;j++){
                    if(s[j]==s[i]){
                        ans[tot][0] = j;
                        ans[tot][1] = i;
                        tot ++;
                        swap(s[j], t[i]);
                        flag2 = 1;
                        break;
                    }
                }
                if(!flag2){
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) {
            puts("Yes");
            printf("%d\n", tot);
            for(int i = 0; i < tot;i++){
                printf("%d %d\n", ans[i][0], ans[i][1]);
            }
        }else{
            puts("No");
        }
           
    }

    return 0;
}


