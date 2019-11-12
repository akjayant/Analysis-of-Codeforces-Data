#include <bits/stdc++.h>
#define ll long long
#define read1(a) scanf("%d",&a)
#define read2(a,b) scanf("%d%d",&a,&b)
#define read3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write(a) printf("%d",a)
#define writen(a) printf("%d\n",a)
#define ff first
#define ss second
#define pll pair<long long ,long long>
#define pii pair<int ,int>
#define ull unsigned long long int
using namespace std;

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        int n;
        string s,t;
        vector<pii> ans;
        cin >> n;
        cin >> s >> t;
        bool ansb=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            if(i==n-1)
            {
                ansb=1;
                break;
            }

            bool ind=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    swap(s[j],t[i]);
                    ans.push_back({j,i});
                    ind=1;
                    break;
                }
            }
            if(ind==0)
               for(int j=i+1;j<n;j++)
               {
                   if(s[i]==t[j])
                   {
                       swap(t[j],s[i+1]);
                       swap(t[i],s[i+1]);
                       ans.push_back({i+1,j});
                       ans.push_back({i+1,i});
                       ind=1;
                       break;
                   }

               }
            if(ind==0)
            {
                ansb=1;
                break;
            }

        }
        if(ansb) cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(int i=0;i<ans.size();i++)
                cout << ans[i].ff+1 << " " << ans[i].ss+1 << endl;
        }

    }
}
