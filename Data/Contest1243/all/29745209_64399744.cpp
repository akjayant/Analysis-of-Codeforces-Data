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

bool check(string &s,string &t)
{
    int cnt[26]= {0};
    for(int i=0; i<s.size(); i++)
    {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']++;
    }
    for(int i=0; i<25; i++)
    {
        if(cnt[i]%2)
        {
            return false;
        }
    }
    return true;
}
void Solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    if(check(s,t)==false)
    {
        cout<<"No"<<endl;
        return;
    }
    vector< pair<int,int> >ans;
    for(int i=0; i<n; i++)
    {
        if(s[i]!= t[i])
        {
            char c1 =s[i], c2= t[i];
            bool flag = false;
            for(int j=i+1; j<n; j++)
            {
                if(s[j]==c1 & s[j]!= t[j])
                {
                    flag= true;
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    break;
                }
            }
            if(!flag)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(t[j]==c1 & s[j]!= t[j])
                    {
                        flag= true;
                        swap(s[j],t[j]);
                        swap(s[j],t[i]);
                        ans.push_back({j,j});
                        ans.push_back({j,i});
                        break;
                    }
                }
            }

        }
    }
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        cout<<it.first+1<<" "<<it.second+1<<endl;
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
