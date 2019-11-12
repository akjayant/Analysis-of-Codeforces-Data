/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    multiset<char> ms1,ms2;

    for(int i=0;i<n;++i)
        ms1.ins(s[i]);

    for(int i=0;i<n;++i)
        ms2.ins(t[i]);

    vector<pair<int,int>> ans;
    for(int i=0;i<n;++i)
    {
        if(s[i]==t[i])
        {
            ms1.erase(ms1.find(s[i]));
            ms2.erase(ms2.find(t[i]));
            continue;
        }

        //cout<<s[i]<<" "<<t[i]<<"\n";

        if(ms2.find(s[i])!=ms2.end())
        {
            //cout<<i<<" here2\n";
            ans.pb({i,i});

            ms1.erase(ms1.find(s[i]));
            ms2.ins(s[i]);
            ms2.erase(ms2.find(t[i]));
            ms1.ins(t[i]);

            swap(s[i],t[i]);

            ms2.erase(ms2.find(t[i]));

            for(int j=i+1;j<n;++j)
            {
                if(t[j]==t[i])
                {
                    ans.pb({i,j});

                    ms1.erase(ms1.find(s[i]));
                    ms2.ins(s[i]);
                    ms2.erase(ms2.find(t[j]));
                    //ms1.ins(t[j]);

                    swap(s[i],t[j]);

                    break;
                }
            }
        }
        else
        {
            ms1.erase(ms1.find(s[i]));

            if(ms1.find(s[i])!=ms1.end())
            {
                //cout<<i<<" "<<"here\n";
                for(int j=i+1;j<n;++j)
                {
                    if(s[i]==s[j])
                    {
                        ans.pb({j,i});

                        ms1.erase(ms1.find(s[j]));
                        //ms2.ins(s[j]);
                        ms2.erase(ms2.find(t[i]));
                        ms1.ins(t[i]);

                        swap(s[j],t[i]);

                        break;
                    }
                }
            }
            else
            {
                cout<<"No\n";
                return;
            }
        }

        /*for(auto c:ms1)
            cout<<c<<" ";
        cout<<"\n";
        for(auto c:ms2)
            cout<<c<<" ";
        cout<<"\n";*/

        //cout<<s<<" "<<t<<"\n";

    }


    if(s==t && ans.size()<=2ll*n)
    {
        cout<<"Yes\n";
        cout<<ans.size()<<"\n";
        for(auto c:ans)
            cout<<c.F+1<<" "<<c.S+1<<"\n";
    }
    else
        cout<<"NO\n";
}

int32_t main()
{
    fast();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

