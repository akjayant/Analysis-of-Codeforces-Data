#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn=100000+10;

char s[110],ans[110];
int main()
{
    int t,n,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R'){
                if(b!=0){
                    ans[i]='P';
                    b--;
                    cnt++;
                }
                else ans[i]='c';
            }
            if(s[i]=='P'){
                if(c!=0){
                    ans[i]='S';
                    c--;
                    cnt++;
                }
                else ans[i]='c';
            }
            if(s[i]=='S'){
                if(a!=0){
                    ans[i]='R';
                    a--;
                    cnt++;
                }
                else ans[i]='c';
            }
        }
        if(cnt<(n+1)/2) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                if(ans[i]!='c') cout<<ans[i];
                else{
                    if(a!=0) cout<<"R",a--;
                    else if(b!=0) cout<<"P",b--;
                    else if(c!=0) cout<<"S",c--;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
