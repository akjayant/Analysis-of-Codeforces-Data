#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
using namespace std;
const int maxn=1e4+7;
char s[maxn],t[maxn];
set<int>se1[30],se2[30];
vector<pii>ans;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,fla=1;
        scanf("%d",&n);
        scanf("%s %s",s+1,t+1);
        for(int i=1;i<=n;i++){
            se1[s[i]-'a'].insert(i);
            se2[t[i]-'a'].insert(i);
        }
        for(int i=1;i<=n;i++){
            se1[s[i]-'a'].erase(i);
            se2[t[i]-'a'].erase(i);
            if(s[i]!=t[i]){
                int a=s[i]-'a';
                int b=t[i]-'a';
                if(se2[b].size()){
                     int zz=*se2[b].begin();
                     se2[b].erase(zz);
                     se2[a].insert(zz);
                     swap(s[i],t[zz]);
                     ans.push_back({i,zz});
                }else if(se1[b].size()){
                     int zz=*se1[b].begin();
                   //  cout<<b<<" "<<zz<<endl;
                     ans.push_back({zz,zz});
                     ans.push_back({i,zz});
                     int c=t[zz]-'a';
                     swap(s[zz],t[zz]);
                     swap(s[i],t[zz]);
                     se1[b].erase(zz);
                     se2[c].erase(zz);
                     se1[c].insert(zz);
                     se2[a].insert(zz);
                }else {
                    fla=0;
                    break;
                }
            }
        }
        if(fla==0)printf("No\n");
        else {
            printf("Yes\n");
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }
        ans.clear();
        for(int i=0;i<26;i++)se1[i].clear(),se2[i].clear();
    }
    return 0;
}
