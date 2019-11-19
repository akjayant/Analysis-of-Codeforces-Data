#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
#define s    second
#define ll   long long
#define vi vector< int >
#define vl vector< ll >
#define rep(i,j,n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define all(v) v.begin(), v.end()
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define Max  INT_MAX
#define Min  INT_MIN
#define T() int tt; cin>>tt; while(tt--)
#define mod  1000000007
#define N 1000099
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	T(){
		ll n; cin>>n;
		ll pe=0, po=0, qe=0, qo=0, p, q;
		for(int i=0;i<n;i++){
			cin>>p;
			if(p%2) po++;
			else	pe++;
		}
		ll m ;cin>>m;
		for(int i=0;i<m;i++){
			cin>>q;
			if(q%2) qo++;
			else	qe++;
		}
		ll ans = pe*qe + po*qo;
		cout<< ans <<"\n";
	}
}


