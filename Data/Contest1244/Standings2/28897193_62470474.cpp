#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+23;

int n,m,x,y;
int a,b,c,d,k;
int main()
{
    int t;cin >> t ;
    char s[1234];
    while(t--){
        cin >>n ;
        scanf("%s",s+1);
        vector<int> pos;
        for(int i=1;i<=n;i++) if(s[i]=='1') pos.push_back(i);
        int ans=n;
        ans=max(ans,ans+(int)pos.size());
        if(pos.size()!=0){
            int t=pos.size();
            ans=max(ans,2*pos[t-1]);
            ans=max(ans,2*(n+1-pos[0]));
        }
        printf("%d\n",ans);
    }
}
