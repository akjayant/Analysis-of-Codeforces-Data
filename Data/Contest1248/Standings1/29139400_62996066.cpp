#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}


int n, m;

int check(vector<vector<int>>& f){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int con = 1;
			
			for(int k = 0; k < 4; k++){
				int ny = i + (2-k)%2, nx = j + (k-1)%2;
				
				if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				
				if(f[i][j] == f[ny][nx]) con++;
			}
			
			if(con >= 3) return 0;
		}
	}
	// cout<<"<><><> "<<endl;
	// for(int i = 0; i < n; i++){
		// for(int j = 0; j < m; j++){
			// cout<<f[i][j];
		// }
		// cout<<endl;
	// }
	
	return 1;
}

int solve(int con, vector<vector<int>>& f){
	int res = 0;
	
	if(con == n*m) return check(f);
	
	f[con/m][con%m] = 1;
	res += solve(con+1, f);
	
	f[con/m][con%m] = 2;
	res += solve(con+1, f);
	
	return res;
}

int solve2(int n, int m){
	int res = 2;
	int a = 0, b = 0;
	
	for(int i = 0; i < n-1; i++){
		int c = a + b;
		c %= MOD;
		
		if(!i) c = 2;
		
		res += c;
		
		res %= MOD;
		
		a = b;
		
		b = c;
	}
	
	a = 0, b = 0;
	
	for(int i = 0; i < m-1; i++){
		int c = a + b;
		c %= MOD;
		
		if(!i){
			c = 2;
		}
		
		res += c;
		
		res %= MOD;
		
		a = b;
		
		b = c;
	}
	
	return res;
}

signed main(){
	// cin.tie(nullptr);
	// ios::sync_with_stdio(false);
	// cout<<fixed<<setprecision(10);
	
	vector<vector<int>> f;
	int x, y;

	// cin>>n>>m;

	cin>>x>>y;
	
	cout<<solve2(x,y)<<endl;
	
	return 0;
	
	for(int i = 1; i <= y; i++){
		cout<<endl;
		for(int j = 1; i*j <= 20; j++){
			f.clear();
			f.resize(i,vector<int>(j));
			n = i;
			m = j;
			cout<<"i = "<<i<<" j = "<<j<<" f = "<<solve(0, f)<<endl;
			cout<<"i = "<<i<<" j = "<<j<<" f = "<<solve2(i,j)<<endl;
		}
	}
	
	// f.resize(n,vector<int>(m));
	
	// cout<<solve(0, f)<<endl;
	
	
	return 0;
}