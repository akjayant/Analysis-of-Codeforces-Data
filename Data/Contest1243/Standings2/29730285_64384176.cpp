#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int a[maxn];
char s[maxn];
char h[maxn];
vector<char>v[2];
int main()
{
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s%s",s,h);
        v[0].clear();
        v[1].clear();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=h[i])
            {
                v[0].push_back(s[i]);
                v[1].push_back(h[i]);
            }
        }

        int ok=1;
        if(v[0].size()==2&&v[1].size()==2&&v[0][0]==v[0][1]&&v[1][0]==v[1][1])
        {

        }
        else if(v[0].size()==0&&v[1].size()==0)
        {

        }
        else ok=0;
        if(ok)
            printf("Yes\n");
        else printf("No\n");
    }


    return 0;
}