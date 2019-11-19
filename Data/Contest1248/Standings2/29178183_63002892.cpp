#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < (_n); ++i)
#define FJ(_n) for(int j = 0; j < (_n); ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

struct Cmp
{
    bool operator () (const ll& a, const ll& b)
    {
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int n;
    cin >> n;
    ll p;
    cin >> p;
    vector<ll> a(n);
    vector<ll> ans(n);
    FI(n)
        cin >> a[i];
    multiset<pair<ll,int>> ev1;
    multiset<ll> ev2;
    FI(n)
        ev1.insert(mp(a[i], i));
    ev2.insert(0);
    set<int, Cmp> free_pos;
    set<int> wait;
    queue<pair<int, ll>> q;
    while (ev1.size() || ev2.size())
    {
        bool doEv1 = ev1.size() && (!ev2.size() || ev1.begin()->first <= *ev2.begin());
        bool doEv2 = ev2.size() && (!ev1.size() || *ev2.begin() <= ev1.begin()->first);

        bool doSkip = false;

        if (doEv2)
        {
            ll ctime = *ev2.begin();
            ev2.erase(ev2.begin());
            if (q.size())
            {
                int id = q.front().first;
                ll time = q.front().second;
                q.pop();
                free_pos.erase(id);
                ans[id] = time;
//                cerr << id << ' ' << time << endl;
                if (ev1.size() && ev1.begin()->first <= ctime
                    && free_pos.upper_bound(ev1.begin()->second) == free_pos.end() && (!wait.size() || ev1.begin()->second < *wait.begin()))
                {
                    doSkip = true;
                    id = ev1.begin()->second;
                    ev1.erase(ev1.begin());
                    ll exitTime = ctime + p * (q.size() + 1);
                    q.push(mp(id, exitTime));
                    ev2.insert(exitTime);
                    free_pos.insert(id);
                }
                else if (wait.size())
                {
                    int id = *wait.begin();
                    if (free_pos.upper_bound(id) == free_pos.end())
                    {
                        ll exitTime = ctime + p * (q.size() + 1);
                        q.push(mp(id, exitTime));
                        ev2.insert(exitTime);
                        free_pos.insert(id);
                        wait.erase(wait.begin());
                    }
                }
            }
        }

        if (doEv1 && !doSkip)
        {
            ll ctime = ev1.begin()->first;
            int id = ev1.begin()->second;
            ev1.erase(ev1.begin());
            if (free_pos.upper_bound(id) == free_pos.end())
            {
                ll exitTime = ctime + p;
                if (q.size())
                    exitTime = q.back().second + p;
                ev2.insert(exitTime);
                q.push(mp(id, exitTime));
                free_pos.insert(id);
            }
            else
                wait.insert(id);
        }
    }
    for (auto it : ans)
        cout << it << ' ';
    return 0;
}
