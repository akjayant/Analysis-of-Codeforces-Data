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
    	ll n;
    	cin >> n;
    	string st;
    	cin >> st;

    	ll fir = inf, lst = -1;

    	for(ll i = 0; i < n; i++)
    	{
    		if(st[i] == '1')
    		{
    			fir = min(fir, i);
    			lst = max(lst, i);
    		}
    	}

    	if(fir == inf)
    	{
    		cout << n << endl;
    		continue;	
    	}
    	
    	fir++;
    	lst++;
    	
    	ll lstAnsw = lst + max(lst, n - lst + 1);
    	ll firAnsw = n - fir + 1 + max(fir, n - fir + 1);

    	cout << max(n, max(lstAnsw, firAnsw)) << endl; 
    }
    return 0;
}













