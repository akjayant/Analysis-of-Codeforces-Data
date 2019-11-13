#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

char s[100], t[100];

vector <ll> X, Y;

ll freq[27];

set <ll> NextX[27], NextY[27];

int main()
{
  //  freopen("input.txt", "r", stdin);

    ll n, i, j, k, x, y, z, ts;

    sl(ts);

    while(ts--)
    {
        sl(n);
        ss(s);
        ss(t);

        memset(freq, 0, sizeof(freq));

        X.clear();
        Y.clear();

        for (i = 0; i < 26; i++)
        {
            NextX[i].clear();
            NextY[i].clear();
        }

        for (i = 0; i < n; i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']++;

            NextX[s[i]-'a'].insert(i);
            NextY[t[i]-'a'].insert(i);
        }

        bool yes = 1;

        for (i = 0; i < 26; i++)
        {
            if (freq[i]&1) yes = 0;
        }

        if (yes)
        {
            for (i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                {
                    int ch = s[i]-'a';

                    while(NextY[ch].size() && *NextY[ch].begin() <= i)
                        NextY[ch].erase(NextY[ch].begin());

                    if (NextY[ch].size())
                    {
                        z = *NextY[ch].begin();
                        X.pb(z);
                        Y.pb(z);
                        NextX[s[z]-'a'].erase(z);
                        NextY[t[z]-'a'].erase(z);
                        swap(s[z], t[z]);
                        NextX[s[z]-'a'].insert(z);
                        NextY[t[z]-'a'].insert(z);

                        X.pb(z);
                        Y.pb(i);
                        NextX[s[z]-'a'].erase(z);
                        NextY[t[i]-'a'].erase(i);
                        swap(s[z], t[i]);
                        NextX[s[z]-'a'].insert(z);
                        NextY[t[i]-'a'].insert(i);
                    }
                    else
                    {
                        while(NextX[ch].size() && *NextX[ch].begin() <= i)
                            NextX[ch].erase(NextX[ch].begin());
                        if (NextX[ch].size() == 0)
                        {
                            printf("No\n");
                            break;
                        }
                        z = *NextX[ch].begin();
                        X.pb(z);
                        Y.pb(i);
                        NextX[s[z]-'a'].erase(z);
                        NextY[t[i]-'a'].erase(i);
                        swap(s[z], t[i]);
                        NextX[s[z]-'a'].insert(z);
                        NextY[t[i]-'a'].insert(i);
                    }
                }
            }

            if (i == n)
            {
                printf("Yes\n");
                printf("%d\n", X.size());

                for (i = 0; i < X.size(); i++)
                {
                    printf("%lld %lld\n", X[i]+1, Y[i]+1);
                }
            }
        }
        else printf("No\n");
    }
    return 0;
}
