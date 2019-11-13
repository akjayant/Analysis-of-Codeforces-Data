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
		string a,b;
		cin>>a>>b;
		string dia="";
		string dib="";
		int counter = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if(a[i] != b[i]){
				counter++;
				dia+=a[i];
				dib+=b[i];
			}
		}
		if(counter != 2){
			cout<<"No"<<endl;
		}
		else if(counter == 2){
			if(dia[0] == dia[1] and dib[0] == dib[1]){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}

	return 0;
}
