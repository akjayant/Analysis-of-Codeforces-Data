#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
int k,n;
string a,b;
vector <int> ans;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("contests599.inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>k;
    while(k--)
    {
        ans.clear();
        cin>>n;
        cin>>a;
        cin>>b;
        for(int i=0; i<=a.size(); i++)
            if(a[i]!=b[i])
                ans.push_back(i);
        if(ans.size()!=2)
            cout<<"No"<<endl;
        else
        {
            if(a[ans[0]]==a[ans[1]]&&b[ans[0]]==b[ans[1]])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
