//
// Created by StupidTurtle on 2019/11/6.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10005;
typedef pair<int,int> pii;
char s[maxn],t[maxn];
vector<pii > ans;
int cnt[26];
int main(){
    int _;scanf("%d",&_);
    while(_--){
        ans.clear();
        for(int i=0;i<26;i++) cnt[i]=0;
        int n;scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        for(int i=1;i<=n;i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i]){
                for(int j=i+1;j<=n;j++){
                    if(s[j]==s[i]){
                        ans.push_back(pii(j,i));
                        swap(s[j],t[i]);
                        break;
                    }
                    if(t[j]==s[i]){
                        ans.push_back(pii(j,j));
                        ans.push_back(pii(j,i));
                        swap(s[j],t[j]);
                        swap(s[j],t[i]);
                        break;
                    }
                }
            }
        }
        int sz=(int)ans.size();
        printf("%d\n",sz);
        for(int i=0;i<sz;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}