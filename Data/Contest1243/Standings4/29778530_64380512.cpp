//
// Created by StupidTurtle on 2019/11/6.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10005;
char s[maxn],t[maxn];
int main(){
    int _;scanf("%d",&_);
    while(_--){
        int n;scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        int tmp=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i]){
                cnt++;
                if(cnt>2) break;
                if(cnt==1) tmp=i;
                else{
                    if(!(s[i]==s[tmp]&&t[i]==t[tmp])){
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt==2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}