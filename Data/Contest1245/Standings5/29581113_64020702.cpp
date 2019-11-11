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

#define MAX_VAL 210000

long long fac[MAX_VAL], mmi[MAX_VAL];

void factorial_mod(){
	 fac[0]=fac[1]=1;
	for(long long i = 2; i < MAX_VAL; fac[i]%=MOD,i++)
		fac[i] = fac[i-1]*(i%MOD);
}

long long power_mod(long long x, long long n){
	long long ans = 1;
	for(;n;n>>=1,x*=x,ans%=MOD,x%=MOD)
		if(n&1)ans*=x;
	return ans%MOD;
}

void exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y -= a/b * x;
}

void modular_multiplicatibe_inverse(){
	int x, y;  
	exgcd(fac[MAX_VAL-1],MOD,x,y);
	mmi[MAX_VAL-1] = x;
	for(long long i = MAX_VAL-2; i >= 0; mmi[i]%=MOD,i--)
		mmi[i] = mmi[i+1]*((i+1)%MOD);
}

long long combination(long long n, long long r){
	return n < r ? 0 :fac[n]*(mmi[r]*mmi[n-r]%MOD)%MOD;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	bool flag = false;
	int ans = 1;
	string s;
	
	cin>>s;
	
	if(count(s.begin(), s.end(), 'm') || count(s.begin(), s.end(), 'w')){
		cout<<0<<endl;
		return 0;
	}
	
	
	factorial_mod();
	modular_multiplicatibe_inverse();
	
	for(int i = 0, con = 1; i < s.size(); i++){
		if(!i){
			
		} else {
			if(s[i] == s[i-1]){
				con++;
			} else {
				
				if(s[i-1] == 'u' || s[i-1] == 'n'){
					int hoge = 0;
					// cout<<con<<endl;
					for(int j =  0; j <= con; j++){
						if(con-j<j) break;
						hoge += combination(con-j,j);
						hoge %= MOD;
					}
					ans *= hoge;
					ans %= MOD;
				}
				con = 1;
			}
		}
		// cout<<con<<endl;
		if(i == s.size()-1){
			if(con >= 2) {
				if(s[i] == 'u' || s[i] == 'n'){
					int hoge = 0;
					// cout<<con<<endl;
					for(int j =  0; j <= con; j++){
						if(con-j<j) break;
						hoge += combination(con-j,j);
						hoge %= MOD;
					}
					
					ans *= hoge;
					ans %= MOD;
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}