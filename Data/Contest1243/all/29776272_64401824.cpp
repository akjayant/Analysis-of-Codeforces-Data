#include <bits/stdc++.h>
using namespace std;
#define ll long long

char s[55], t[55];
ll f[50];
int main()
{
    ll k, n, m, i, cnt, j;

    scanf("%lld", &k);

    while(k--)
    {
        scanf("%lld", &n);
        scanf(" %s %s", s, t);
        memset(f, 0, sizeof(f));
        vector < pair <ll, ll> > res;
        for(i=0; i<n; i++)
        {
            f[s[i]-'a']++;
            f[t[i]-'a']++;
        }
        bool in=0;
        for(i=0; i<26; i++)
        {
            if(f[i]%2!=0)
            {
                in=1;
                break;
            }
        }

        if(!in)
        {
           for(i=0; i<n; i++)
           {
               if(s[i]==t[i]) continue;
               for(j=i+1; j<n; j++)
               {
                   if(s[i]==s[j])
                   {
                       pair <ll, ll> p;
                       p.first=j;
                       p.second=i;
                       res.push_back(p);
                       swap(s[j], t[i]);
                       break;
                   }
                   else if(s[i]==t[j])
                   {
                       pair <ll, ll> p;
                       p.first=j;
                       p.second=j;
                       swap(s[j], t[j]);
                       res.push_back(p);
                       p.second=i;
                       res.push_back(p);
                       swap(s[j], t[i]);
                       break;
                   }
               }
               if(j>=n) in=1;
           }
        }
        ll sz=res.size();
        if(!in && sz<=2*n)
        {
            printf("Yes\n");
            printf("%lld\n", sz);
            for(i=0; i<res.size(); i++) printf("%lld %lld\n", res[i].first+1, res[i].second+1);
        }
        else printf("No\n");
    }


    return 0;
}

