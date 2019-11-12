#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
int t,n;
char s1[maxn],s2[maxn];
struct sa
{
    char a,b;
}p[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s1>>s2;
        int k=0;
        for(int i=0;i<n;i++)
            if(s1[i]!=s2[i])
            {
                k++;
                p[k].a=s1[i],p[k].b=s2[i];
            }
        if(k!=2)cout<<"NO"<<endl;
        else
        {
            if(p[1].a==p[2].a&&p[1].b==p[2].b)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
