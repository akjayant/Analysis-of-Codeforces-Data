#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<" --> "<<(a)<<endl;
#define fastInput ios_base::sync_with_stdio(false);cin.tie(0)
#define INPUT freopen("input.txt","r",stdin)
#define OUTPUT freopen("output.txt","w",stdout)
#define mod  1000000007
#define error  1e-7
const int N = 1005;


void Solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt =0;
    string ans = "Yes";
    vector<int>pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            cnt++;
            pos.push_back(i);
        }
    }
    if(cnt==1|| cnt >2)
    {
        ans="No";
        cout<<ans<<endl;
        return ;
    }
    int x= pos[0], y= pos[1];
    swap(s[x],t[y]);
    if(s==t)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main()
{
    //fastInput;
    //cout.tie(0);
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        Solve();
    }
    return 0;
}
/*




 */
