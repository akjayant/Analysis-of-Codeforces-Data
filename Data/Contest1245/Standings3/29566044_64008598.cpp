#include<bits/stdc++.h>
using  namespace std;

typedef  pair<int,int> pii;
char s[105],p[105];
void solve(){
    int n,a[3],b[3]={0,0,0},c[3]={0,0,0},sum=0;
    scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        p[i]='#';
        if(s[i]=='R')
        {
            if(a[1] > 0) sum++,a[1]--,p[i]='P';
        }
        else if(s[i]=='P'){ if(a[2] >0) sum++,a[2]--,p[i]='S';
        }
        else if(a[0] > 0) {sum++,a[0]--,p[i]='R';
        }
    }
    if(sum < (n/2) + (n%2)) printf("NO\n");
    else {
        printf("YES\n");
        for(int i=0;i<n;i++){
            if(p[i]=='#'){
                if(a[0] > 0) p[i]='R',a[0]--;
                else if(a[1] > 0) p[i]='P',a[1]--;
                else p[i]='S',a[2]--;
            }
        }
        p[n]='\0';
        printf("%s\n",p);
    }
    return;


}
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }

}
