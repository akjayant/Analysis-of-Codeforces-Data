#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll k, n, m;

vector<int>pozL[100002], pozC[100002];

int fndL(int linie, int val)
{
    int st = 0;
    int dr = pozL[linie].size() - 1;
    int ans = (1<<30);
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(pozL[linie][mid] < val)
            st = mid + 1;
        else
            ans = pozL[linie][mid], dr = mid - 1;
    }
    return ans;
}
int fndC(int coloana, int val)
{
    int st = 0;
    int dr = pozC[coloana].size() - 1;
    int ans = (1<<30);
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(pozC[coloana][mid] < val)
            st = mid + 1;
        else
            ans = pozC[coloana][mid], dr = mid - 1;
    }
    return ans;
}

int fndLR(int linie, int val)
{
    int st = 0;
    int dr = pozL[linie].size() - 1;
    int ans = -(1<<30);
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(pozL[linie][mid] > val)
            dr = mid - 1;
        else
            ans = pozL[linie][mid], st = mid + 1;
    }
    return ans;
}

int fndCR(int coloana, int val)
{
    int st = 0;
    int dr = pozC[coloana].size() - 1;
    int ans = -(1<<30);
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(pozC[coloana][mid] > val)
            dr = mid - 1;
        else
            ans = pozC[coloana][mid], st = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    ll puncte = 1LL * n * m - k;
    for(int i = 1; i <= k; ++i)
    {
        int a, b;
        cin >> a >> b;
        pozL[a].pb(b);
        pozC[b].pb(a);
    }
    for(int i = 1; i <= 100000; ++i)
    {
        sort(pozL[i].begin(), pozL[i].end());
        sort(pozC[i].begin(), pozC[i].end());
    }
    int minL = 1, maxL = n, minC = 1, maxC = m;
    // 1 - R, 2 - D, 3 - L, 4 - U
    int dir = 1;
    while(minL <= maxL && minC <= maxC)
    {
        if(dir == 1)
        {
            int stop = fndL(minL, minC);
            if(stop != (1<<30))
                maxC = min(maxC, stop - 1);
            puncte -= (maxC - minC + 1);
            ++minL;
            dir = 2;
        }
        else
            if(dir == 2)
            {
                int stop = fndC(maxC, minL);
                if(stop != (1<<30))
                    maxL = min(maxL, stop - 1);
                puncte -= (maxL - minL + 1);
                maxC--;
                dir = 3;
            }
            else
            {
                if(dir == 3)
                {
                    int stop = fndLR(maxL, maxC);
                    if(stop != -(1<<30))
                        minC = max(minC, stop + 1);
                    puncte -= (maxC - minC + 1);
                    --maxL;
                    dir = 4;
                }
                else
                {
                    int stop = fndCR(minC, maxL);
                    if(stop != -(1<<30))
                        minL = max(minL, stop + 1);
                    puncte -= (maxL - minL + 1);
                    minC++;
                    dir = 1;
                }
            }
    }
    if(puncte == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
