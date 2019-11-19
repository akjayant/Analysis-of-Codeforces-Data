/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
ll n, k;
string s;

string st2;
void solve(int L, int R, ll mx)
{
    ll op = 0;
    char aa = st2[L-1];
    char bb;
    if(R == n-1)
        bb = st2[0];
    else
        bb = st2[R+1];
   // cout << L << " " << R << " " << aa << " " << bb << '\n';
    while(op <= mx && L <= R)
    {
        if(op % 2 == 0)
        {
            while(L <= R && st2[L] == aa)
                st2[L] = aa, ++L;
            while(L <= R && st2[R] == bb)
                st2[R] = bb, --R;
        }
        else
        {
            while(L <= R && st2[L] != aa)
                st2[L] = aa, ++L;
            while(L <= R && st2[R] != bb)
                st2[R] = bb, --R;
        }
        ++op;
    }
    for(int i = L; i <= R; ++i)
        if(mx % 2 == 1)
        {
            if(st2[i] == 'B')
                st2[i] = 'W';
            else
                st2[i] = 'B';
        }
}
int main()
{
    please followmeoninsta
    cin >> n >> k;
    cin >> s;
    bool s2 = 0;
    int st = -1;
    for(int i = 0; i < n; ++i)
    {
        if(i+1 != n)
        {
            if(s[i] == s[i+1])
            {
                s2 = 1, st = i;
                break;
            }
        }
        else
        {
            if(s[i] == s[0])
            {
                s2 = 1;
                st = i;
                break;
            }
        }
    }
    if(!s2)
    {
        if(k % 2 == 0)
            cout << s << '\n';
        else
        {
            for(int i = 0; i < n; ++i)
                if(s[i] == 'B')
                    cout << "W";
                else
                    cout << "B";
        }
        return 0;
    }
    int poz = st;
    do
    {
        st2 += s[poz];
        ++poz;
        if(poz == n)
            poz = 0;
    }
    while(poz != st);
   // cout << st2 << '\n';
    for(int i = 0; i < n; ++i)
    {
        if(st2[i] != st2[i+1])
        {
            int starto = i+1;
            int finito = i+1;
            while(1)
            {
                if(st2[finito] == st2[finito + 1])
                    break;
                else
                    if(finito == n-1)
                        break;
                    else
                        ++finito;
            }
            i = finito;
            if(finito == n-1 && st2[n-1] != st2[0])
                solve(starto, finito, k);
            else
                solve(starto, finito - 1, k);
        }
    }
    /// tre sa afisezi de la pozitia 1, nu de la st
    int rpos = 0;
    int tpos = st;
    while(tpos != 0)
    {
        ++tpos;
        ++rpos;
        if(tpos == n)
            tpos = 0;
    }
   // cout << st2 << '\n';
    for(int i = rpos; i < st2.size(); ++i)
        cout << st2[i];
    for(int i = 0; i < rpos; ++i)
        cout << st2[i];
    return 0;
}
