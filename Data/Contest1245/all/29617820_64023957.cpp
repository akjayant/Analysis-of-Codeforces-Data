#include <bits/stdc++.h>
using namespace std;
char str[1005];
char ans[1005];
void work(){
	int n,a1,b1,c1;scanf("%d%d%d%d",&n,&a1,&b1,&c1);
    scanf("%s",str+1);
    int beat=0;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        if(str[i]=='R'&&b1) b1--,beat++,ans[i]='P';
        if(str[i]=='P'&&c1) c1--,beat++,ans[i]='S';
        if(str[i]=='S'&&a1) a1--,beat++,ans[i]='R';
    }
    if(beat<(n+1)/2){
        puts("NO");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]) {
            if(a1) a1--,ans[i]='R';
            else if(b1) b1--,ans[i]='P';
            else if(c1) c1--,ans[i]='S';
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) putchar(ans[i]);
    putchar('\n');
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
