#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
#ifdef _DEBUG
    const int N=1e3+10;
#else
    const int N=1e6+10;
#endif
int m,n,t;
int a[N];
char s1[N],s2[N];
vector<int>pos;
vector<pair<int,int>>ans;

int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);int ok=1;
        scanf("%s%s",s1+1,s2+1);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)a[s1[i]-'a'+1]++,a[s2[i]-'a'+1]++;
        for(int i=1;i<=26;i++)if(a[i]%2)ok=0;
        if(!ok){puts("NO");continue;}
        puts("YES");pos.clear();ans.clear();
        for(int i=1;i<=n;i++)if(s1[i]!=s2[i])pos.push_back(i);
        for(int i=0;i< pos.size();i++)
        {
            if(s1[pos[i]]==s2[pos[i]])continue;
            int ok=0;
            for(int j=i+1;j< pos.size();j++)if(s1[pos[i]]==s1[pos[j]])
            {
                ok=1;
                ans.push_back(mp(pos[j],pos[i]));
                swap(s1[pos[j]],s2[pos[i]]);
                break;
            }
            if(ok)continue;
            for(int j=i+1;j< pos.size();j++)if(s1[pos[i]]==s2[pos[j]])
            {
                ok=1;
                ans.push_back(mp(pos[i+1],pos[j]));
                ans.push_back(mp(pos[i+1],pos[i]));
                swap(s1[pos[i+1]],s2[pos[j]]);
                swap(s1[pos[i+1]],s2[pos[i]]);
                break;
            }
        }
        printf("%d\n",(int)ans.size());
        for(int i=0;i< ans.size();i++)printf("%d %d\n",ans[i].x,ans[i].y);
    }
}
