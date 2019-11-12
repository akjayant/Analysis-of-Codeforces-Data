#include<bits/stdc++.h>

using namespace std;
int n;
char s[2][(int)1e4+5];
int solve(){
    scanf("%d%s%s",&n,s[0]+1,s[1]+1);
    pair<char,char> op={'#','#'};
    bool io=false;
    for(int i=1;i<=n;i++){
        if(s[0][i]!=s[1][i]){
           // printf("at n=%d %d",n,i);
            if(io){
                return !printf("No\n");
            }
            if(op.first=='#'){
                op={s[0][i],s[1][i]};
            }
            else{
                if(s[0][i]!=op.first || s[1][i]!=op.second) return !printf("No\n");
                op={'#','#'};
                io=true;
            }
        }
    }
 //   printf("%c %c %d",op.first,op.second,io);
    return op.first=='#'?!printf("Yes\n"):!printf("No\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }


}
