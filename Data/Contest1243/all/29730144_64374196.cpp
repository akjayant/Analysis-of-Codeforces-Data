#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
using namespace std;

//global here

//function here

//main here
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		vi v;
		int tmp;
		for (int i = 0; i < n; ++i)
		{
			cin>>tmp;
			v.pb(tmp);
		}
		sort(v.begin(), v.end());
		int counter = 0;
		for (int i = v.size()-1; i >=0; --i)
		{
			if(v[i] >= counter+1){
				counter++;
			}
			else{
				break;
			}
		}
		cout<<counter<<endl;
	}

	return 0;
}
