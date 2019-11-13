#include<bits/stdc++.h>
using namespace std;const int N=57;typedef pair<int,int>pa;
char s[N],t[N];int n,i,j,cnt[27],T_T;vector<pa>d;
int main(){
    for(scanf("%d",&T_T);T_T--;memset(cnt,0,sizeof(cnt))){
        for(scanf("%d%s%s",&n,s+1,t+1),i=1;i<=n;++i)cnt[s[i]-'a']++,cnt[t[i]-'a']++;
        for(i=j=0;i<26;++i)if(cnt[i]%2==1)j=1;
        if(j)puts("No");
        else{
            puts("Yes");
            for(i=1;i<=n;++i)if(s[i]!=t[i]){
                for(j=i+1;j<=n;++j)if(s[j]==s[i])break;
                if(j==n+1){
                    for(j=i+1;j<=n;++j)if(t[j]==s[i])break;
                    swap(t[j],s[j]);
                    swap(s[j],t[i]);
                    d.push_back(pa(j,j));
                    d.push_back(pa(j,i));
                }else{
                    d.push_back(pa(j,i));
                    swap(s[j],t[i]);
                }
            }printf("%d\n",(int)d.size());
            for(auto&x:d)printf("%d %d\n",x.first,x.second);d.clear();
        }
    }
}
