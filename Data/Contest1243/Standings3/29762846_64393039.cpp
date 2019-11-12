#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
char a[10010],b[10010];
int cnt[400];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        vector<pair<int,int>>ans;
        ans.clear();
        int len;
        scanf("%d",&len);
        scanf("%s",a);
        scanf("%s",b);
        for(int i=0;i<len;i++){
            cnt[a[i]-'a']++;
            cnt[b[i]-'a']++;
        }
        bool chk=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                chk=1;
                break;
            }
        }
        if(chk){
            puts("No");
            continue;
        }
        else{
            puts("Yes");
        }
        chk=0;
        for(int i=0;i<len;i++){
            if(a[i]==b[i])continue;
            for(int j=i+1;j<len;j++){
                if(a[i]==b[j]){
                    swap(b[j],a[i+1]);
                    swap(a[i+1],b[i]);
                    ans.push_back({i+1,j});
                    ans.push_back({i+1,i});
                    break;
                }
                if(a[i]==a[j]){
                    swap(b[i],a[j]);
                    ans.push_back({j,i});
                    break;
                }
            }
        }
        printf("%d\n",ans.size());
        for(auto&ii:ans){
            printf("%d %d\n",ii.fi+1,ii.se+1);
        }
    }
}
