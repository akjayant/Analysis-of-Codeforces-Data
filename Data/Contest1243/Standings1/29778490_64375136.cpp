#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("testcases.txt", "r", stdin);

    int t;
    scanf("%d",&t);

    while(t--) {
        int n;
        scanf("%d",&n);

        vector<int>v;

        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int ans=0;

        for(int i=0;i<n;i++) {
            int x=i+1;
            int y=v[i];
            ans=max(ans,min(x,y));
        }

        printf("%d\n",ans);
    }



 
    return 0;
}