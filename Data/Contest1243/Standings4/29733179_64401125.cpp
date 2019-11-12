#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using pii=pair<int,int>;
int n,dp[30];
char s[2][60],c;
int solve(){
    scanf("%d",&n);
    scanf("%s%s",s[0]+1,s[1]+1);
    for(int i=0;i<=26;i++){
        dp[i]=0;
    }
    //printf("//%s//%s\n",s[0]+1,s[1]+1);
    for(int i=1;i<=n;i++){
        dp[s[0][i]-'a']++;
        dp[s[1][i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(dp[i]%2) return !printf("No\n");
    }
    printf("Yes\n");
    queue<pii> print;
    for(int i=1;i<=n;i++){
        if(s[0][i]==s[1][i]) continue;
        for(int j=i+1;j<=n;j++){
            if(s[0][i]==s[0][j]){
                print.push({j,i});
                c=s[1][i];
                s[1][i]=s[0][j];
                s[0][j]=c;
                break;
            }
            if(s[0][i]==s[1][j]){
                print.push({i+1,j});
                print.push({i+1,i});
                c=s[0][i+1];
                s[0][i+1]=s[1][i];
                s[1][j]=c;
                s[1][i]=s[0][i];
                break;
            }
        }
    }
    printf("%d\n",(int)print.size());
    while(!print.empty()){
        printf("%d %d\n",print.front().st,print.front().nd);
        print.pop();
    }
    return 0;


}
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        solve();
    }

}
