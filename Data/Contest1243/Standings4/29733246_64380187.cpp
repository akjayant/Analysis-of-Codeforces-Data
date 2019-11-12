#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e4+50;

int T,n;
char s1[maxn],s2[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s%s",s1,s2);
        if(!strcmp(s1,s2)){
            puts("Yes");
            continue;
        }
        int cnt=0;
        int p=-1,q;
        for(int i=0;i<n;++i){
            if(s1[i]!=s2[i]){
                ++cnt;
                if(-1==p) p=i;
                else q=i;
            }
        }
        if(cnt!=2){
            puts("No");
            continue;
        }
        if(s1[p]==s1[q] && s2[p]==s2[q]) puts("Yes");
        else puts("No");
    }
    return 0;
}