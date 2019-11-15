#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
int main()
{
	int w;
	cin >> w;
	while(w--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> vec;
		for(int i=0; i<n; i++) 
		{
			if(s[i] != t[i]) vec.push_back(i);	
		}
		if(!vec.size()) cout << "Yes" << endl;
		else if(vec.size() == 2)
		{
			swap(s[vec[0]], t[vec[1]]);
			if(s == t) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
}