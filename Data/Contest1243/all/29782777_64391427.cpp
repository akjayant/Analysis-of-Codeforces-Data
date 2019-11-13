#include<bits/stdc++.h>
using namespace std;
int n;
char a[10007],b[10007];
int nn[26];
int aa[20007],bb[20007];
int tot;
void solve(int x){
    for(int i=x+1;i<n;i++){
        if(a[i]!=b[i]&&(a[x]==a[i]||a[x]==b[i])){
            if(a[x]==a[i]){
                aa[tot]=i;
                bb[tot]=x;
                swap(a[i],b[x]);
                tot++;
                return;
            }
            else{
                aa[tot]=i;
                bb[tot]=i;
                swap(a[i],b[i]);
                tot++;
                aa[tot]=i;
                bb[tot]=x;
                swap(a[i],b[x]);
                tot++;
                return;
            }
        }
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(nn,0,sizeof nn);
        tot=0;
        scanf("%d%s%s",&n,a,b);
        for(int i=0;i<n;i++){
            nn[a[i]-'a']++;
            nn[b[i]-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(nn[i]&1)flag=1;
        }
        if(flag){
            puts("No");
            continue;
        }
        else{
            puts("Yes");
        }
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                solve(i);
            }
        }
        printf("%d\n",tot);
        for(int i=0;i<tot;i++){
            printf("%d %d\n",aa[i]+1,bb[i]+1);
        }
//        printf("----%s\n----%s\n",a,b);
    }
}