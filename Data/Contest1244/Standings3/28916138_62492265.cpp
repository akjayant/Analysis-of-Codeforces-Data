#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main()
{
    ll n , p , w , d;
    cin >> n >> p >> w >> d;
    ll x = p / w;
    ll y = (p - x*w) / d;
    ll rem = (p - x*w) % d;

    if(rem == 0)
    {
        if(x + y <= n)
            cout << x << ' ' << y << ' ' << n - x - y << endl;
        else
            cout << "-1\n";
        return 0;
    }
    for(ll i = 0 ; i < min(x , 200000LL) ; i++)
    {
        x --;
        rem += w;
        if(rem%d == 0)
        {
            y += rem / d;
            if(x + y <= n)
                cout << x << ' ' << y << ' ' << n - x - y << endl;
            else
                cout << "-1\n";
            return 0;
        }
    }
    cout << "-1\n" , 0;
    return 0;
}
