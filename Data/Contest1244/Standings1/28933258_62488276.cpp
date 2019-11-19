#include <iostream>
#define ll long long

using namespace std;

bool check[100001];

int main()
{
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll pmodw = p % w;
    ll v = 0;
    ll c = 0;
    while(!check[v])
    {
        if(pmodw == v)
            break;
        check[v] = true;
        c++;
        v = (v + d) % w;
    }
    if(pmodw == v)
    {
        p -= d * c;
        if(p < 0)
            cout << -1;
        else
        {
            ll wins = p / w;
            if(wins + c <= n)
                cout << wins << " " << c << " " << n-c-wins;
            else
                cout << -1;
        }
    }
    else
        cout << -1;
    return 0;
}
