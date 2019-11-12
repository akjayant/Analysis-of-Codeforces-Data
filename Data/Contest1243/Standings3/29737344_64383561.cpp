#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, i,j;
    cin>>n;
    string a, b;
    cin>>a>>b;
    string aa = "", bb = "";
    ll eq = 0;
    for(i=0; i<n;i++)
    {
        if (a[i] == b[i]) eq++;
        else
        {
            aa.push_back(a[i]);
            bb.push_back(b[i]);
        }
    }

    if (aa.size() > 2)
    {
        cout<<"No"<<endl;
        return;
    }

/*    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    if (aa == bb)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
*/
//cout<<aa<<" "<<bb<<endl;
    for(i=0; i<aa.size(); i++)
    {
        for(j=0; j<bb.size(); j++)
        {
            string aaa = aa, bbb = bb;
            char q = aaa[i];
            aaa[i] = bbb[j];
            bbb[j] = q;
            if (aaa == bbb)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
        solve();
    return 0;
}
