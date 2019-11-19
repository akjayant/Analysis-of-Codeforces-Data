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

ll n;
vector<vll > price;

vector<vll > nodes;

vll color;
bool flag;

void dfs(ll cur, ll prev, ll curColor)
{
	color[cur] = curColor;
	
	ll newColor;
	if(curColor + color[prev] == 1)
		newColor = 2;
	else if(curColor + color[prev] == 2)
		newColor = 1;
	else
		newColor = 0;
		
	for(int i = 0; i < nodes[cur].size(); i++)
	{
		ll to = nodes[cur][i];

		if(to == prev)
			continue;

		if(color[to] == newColor)
			continue;

		if(color[to] != -1)
		{
			flag = 1;
			continue;
		}

		dfs(to, cur, newColor);			
	}
}

int main() 
{        
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	price.resize(3, vll(n));
	nodes.resize(n);
	color.resize(n, -1);
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> price[i][j];
	}
	
	vll in(n);
	
	for(int i = 0; i < n - 1; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		nodes[a].pb(b);
		nodes[b].pb(a);	
		
		in[a]++;
		in[b]++;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(in[i] > 2)
		{
			cout << -1 << endl;
			return 0;	
		}	
	}
	
	ll ind = -1;
	for(int i = 0; i < n; i++)
	{
		if(in[i] == 1)
		{
			ind = i;
			break;	
		}
	}
	
	vpll combos = { {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1} };
	
	ll answ = inf;
	
	vll answerArr;
	
	for(int i = 0; i < combos.size(); i++)
	{
		color.resize(0);
		color.resize(n, -1);
		color[ind] = combos[i].f;

		cerr << "ind = " << ind << " " << color[ind] << endl;
		
		flag = 0;
		dfs(nodes[ind][0], ind, combos[i].s);

		if(flag == 0)
		{
			ll curAnswer = 0;
			for(int j = 0; j < color.size(); j++)
			{
				curAnswer += price[color[j]][j];
			}
			
			
			if(curAnswer < answ)
			{
				cerr << "updating answ " << i << endl;
				cerr << "color " << color << endl;
				
				answ = curAnswer;	
				answerArr = color;
			}
		}	
	}
	if(answ == inf)
	{
		cout << -1 << endl;
		return 0;	
	}
	
	cout << answ << endl;
	for(int i = 0; i < answerArr.size(); i++)
		cout << answerArr[i] + 1 << " ";
	cout << endl;
	
    return 0;
}













