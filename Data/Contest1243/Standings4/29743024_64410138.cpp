#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;

int a[MAXN],num[500];
char s[MAXN],t[MAXN];

int num1[500],num2[500];
vector<pii> ans;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        memset(num,0,sizeof(num));
        memset(num1,0,sizeof(num));
        memset(num2,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            num[s[i]]++;
            num[t[i]]++;
        }
        bool f=0;
        for(int i=0;i<=300;i++)
            if(num[i]&1)f=1;
        if(f)
        {
            puts("No");
            continue;
        }
        puts("Yes");
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=t[i])
            {
                bool f=0;
                for(int j=i+1;j<=n;j++)
                {
                    if(s[j]==s[i])
                    {
                        ans.push_back({j,i});
                        swap(s[j],t[i]);
                        f=1;
                        break;
                    }
                }
                if(f)continue;
                for(int j=i+1;j<=n;j++)
                {
                    if(t[j]==s[i]&&t[j]!=s[j])
                    {
                        ans.push_back({n,j});
                        ans.push_back({n,i});
                        swap(t[j],s[n]);
                        swap(t[i],s[n]);
                        break;
                    }
                }

            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
