#include <bits/stdc++.h>
#include<bits/algorithmfwd.h>
#define int long long
using namespace std;
typedef pair<int,int> pi;
int Test,n,k;
string s,t;
/*sfdsfsdfsdfsdf
sdf
sdf
ds
fsd
f
sdf
can you hack my code
*/
 main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>Test;
    while(Test--)
    {
        cin >>n>>s>>t;
        vector<pi> lkjhlh;
        lkjhlh.clear();
        for (int dsfsdfs=0;dsfsdfs<n;dsfsdfs++)
            if (s[dsfsdfs]!=t[dsfsdfs])
            {
                for (int sdfsdfsdf=dsfsdfs+1;sdfsdfsdf<n;sdfsdfsdf++)
                    if (t[dsfsdfs]==t[sdfsdfsdf])
                    {
                        lkjhlh.push_back(pi(dsfsdfs,sdfsdfsdf));swap(s[dsfsdfs],t[sdfsdfsdf]);break;
                    }
                    else if (s[sdfsdfsdf] == t[dsfsdfs])
                    {
                        lkjhlh.push_back(pi(dsfsdfs, dsfsdfs));
                        swap(s[dsfsdfs],t[dsfsdfs]);
                        lkjhlh.push_back(pi(sdfsdfsdf, dsfsdfs));
                        swap(s[sdfsdfsdf],t[dsfsdfs]);
                        break;
                    }
                    else if(s[dsfsdfs]==t[sdfsdfsdf]){lkjhlh.push_back(pi(dsfsdfs, dsfsdfs));swap(s[dsfsdfs],t[dsfsdfs]);lkjhlh.push_back(pi(dsfsdfs, sdfsdfsdf));swap(s[dsfsdfs], t[sdfsdfsdf]);break;}
            }
        if(s==t)
        {
            cout<<"Yes\n"<<lkjhlh.size()<<"\n";
            for(int dsfsdfs=0;dsfsdfs<lkjhlh.size();dsfsdfs++)cout<< lkjhlh[dsfsdfs].first+1<<" "<<lkjhlh[dsfsdfs].second+1<<'\n';
        }
        else cout<<"No\n";
    }
    return 0;
}
