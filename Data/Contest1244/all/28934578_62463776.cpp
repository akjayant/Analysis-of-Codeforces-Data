#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
    
#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pbb pair<bool, bool>
#define pb push_back
#define f first
#define s second
#define ld long double
#define vbb vector<bool>
#define vdd vector<double>
#define vpll vector<pll >
#define mp make_pair
    
#define cerr cerr1 
    
#ifdef cerr
#define endl '\n'                                                                                                        
struct shitClass 
{    
};
    
template<class T>
shitClass& operator<<(shitClass& c1, const T& ) 
{
    return c1;
};
    
shitClass cerr;
#endif   
    
#define MOD (ll)(1e9)
    
#define inf (ll)(1e17 + 10)
    
ostream& operator<< (ostream& os, const vll& a) 
{
    for (int i = 0; i < a.size(); i++)
        os << a[i] << " ";
    return os;  
}
                                                                                                                                                                                                          
ostream& operator<< (ostream& os, const pll& a) 
{
    os << a.f << " " << a.s;
    return os;
}
    
ostream& operator<< (ostream& os, const vii& a)
{
    for (int i = 0; i < a.size(); i++)
        os << a[i] << " ";
    return os;
}
    
istream& operator>> (istream& is, pll& a)
{
    is >> a.f >> a.s;    
    return is;
}

int main() 
{        
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    for(int counter = 0; counter < t; counter++)
    {
    	ll a, b, c, d, k;
    	cin >> a >> b >> c >> d >> k;

    	ll p1 = (a + c - 1) / c;
    	ll p2 = (b + d - 1) / d;

    	if(p1 + p2 > k)
    		cout << -1 << endl;
    	else
	    	cout << p1 << " " << p2 << endl;	
    }
    return 0;
}













