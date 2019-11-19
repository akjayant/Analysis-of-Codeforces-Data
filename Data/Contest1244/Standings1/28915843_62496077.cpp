#include<bits/stdc++.h>
#include<bits/extc++.h>
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define lb lower_bound
#define ub upped_bound
#define fbo find_by_order
#define ofk order_of_key
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
template<class T>using pq=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;
template<class T>using tr=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

char s[200005];
vector<int>a,b;
int main()
{
    ios::sync_with_stdio(false);
    int k=1,m,n;
    cin>>n>>m>>s+1;
    s[0]=s[n];
    s[n+1]=s[1];
    for(int i=1;i<=n;i++) if(s[i]!=s[i-1]&&s[i]!=s[i+1]) a.eb(i);
    if(a.size()==n)
    {
        if(m%2)
        {
            for(int i=1;i<=n;i++) if(s[i]=='B') cout<<'W';
            else cout<<'B';
        }
        else for(int i=1;i<=n;i++) cout<<s[i];
        cout<<endl;
        return 0;
    }
    while(k<=a.size()&&a[k-1]==k) k++;
    for(int i=k-1;i<a.size();i++) b.eb(a[i]);
    for(int i=0;i<k-1;i++) b.eb(a[i]);
    for(int i=0;i<b.size();i++)
    {
        int j=i+1,x,y,w;
        bool t=false;
        while(j<b.size()&&(b[j]==b[j-1]+1||b[j-1]==n&&b[j]==1)) j++;
        j--;
        x=i;
        y=j;
        w=min(m,(y-x+1)/2);
        if(m>(y-x+1)/2) t=true;
        for(int k=1;k<=w;k++)
        {
            int xx=b[x]-1,yy=b[y]+1;
            if(xx==0) xx=n;
            if(yy==n+1) yy=1;
            s[b[x]]=s[xx];
            s[b[y]]=s[yy];
            x++;
            y--;
        }
        if(w%2) for(int k=x;k<=y;k++) if(s[b[k]]=='B') s[b[k]]='W';
        else s[b[k]]='B';
        if(t&&x==y)
        {
            int xx=b[x]-1,yy=b[y]+1;
            if(xx==0) xx=n;
            if(yy==n+1) yy=1;
            if(s[xx]==s[yy]) s[b[x]]=s[xx];
        }
        i=j;
    }
    for(int i=1;i<=n;i++) cout<<s[i];
    cout<<endl;
    return 0;
}
