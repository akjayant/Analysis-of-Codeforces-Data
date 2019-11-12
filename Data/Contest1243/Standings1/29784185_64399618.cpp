#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[11111],t[11111];
int main(){
	int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        string a="",b="";
        scanf("%s",s+1);scanf("%s",t+1);
        vector<pair<int,int>>ans;
        bool flag=1;
        for (int i=1;i<=n;i++)
            if (s[i]!=t[i]){
                bool f=0;
                for (int j=i+1;j<=n;j++)
                    if (t[j]==t[i]){
                        swap(s[i],t[j]);
                        ans.push_back({i,j});
                        f=1;break;
                    }
                if (!f)for (int j=i+1;j<=n;j++)
                    if (s[j]==t[i]){
                        swap(s[j],t[n]);
                        swap(s[i],t[n]);
                        ans.push_back({j,n});
                        ans.push_back({i,n});
                        f=1;break;
                    }
                if (!f){
                    flag=0;break;
                }
                
            }
        if (flag){
            puts("Yes");
            printf("%d\n",ans.size());
            for (auto i:ans)printf("%d %d\n",i.first,i.second);
        } else puts("No");
    }
}
