/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 200005

int a[5], cnt[5], rest[5];
char c[] = {'0', 'R', 'P', 'S'};

void Print()
{
    FOR(j, 1, 3)
        while(rest[j] > 0)
        {
            cout << c[j];
            rest[j]--;
            return;
        }
}

int main()
{
    _io
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cin >> a[1] >> a[2] >> a[3];
        string s; cin >> s;
        cnt[1] = cnt[2] = cnt[3] = 0;
        REP(i, 0, s.size())
        {
            if(s[i] == 'R') cnt[2]++;
            if(s[i] == 'P') cnt[3]++;
            if(s[i] == 'S') cnt[1]++;
        }
        int sum = 0;
        FOR(i, 1, 3)
        {
            cnt[i] = min(cnt[i], a[i]);
            rest[i] = max(0, a[i] - cnt[i]);
            sum += cnt[i];
        }
        if(sum >= (n+1)/2)
        {
            cout << "YES" << '\n';
            REP(i, 0, s.size())
            {
                if(s[i] == 'R')
                {
                    if(cnt[2] > 0)
                    {
                        cout << 'P';
                        cnt[2]--;
                    }else Print();
                }
                if(s[i] == 'P')
                {
                    if(cnt[3] > 0)
                    {
                        cout << 'S';
                        cnt[3]--;
                    }else Print();
                }
                if(s[i] == 'S')
                {
                    if(cnt[1] > 0)
                    {
                        cout << 'R';
                        cnt[1]--;
                    }else Print();
                }
            }
            cout << '\n';
        }else cout << "NO" << '\n';
    }
}
