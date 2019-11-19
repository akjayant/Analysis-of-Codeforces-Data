#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define debug(x) cout << #x << " = "  << x << endl
#define pb push_back
#define mp make_pair
typedef long long tint;
int toNumber (string s)
{
	int Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}
string toString (int number)
{
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

tint ele(tint a, tint b){
	if(b==0)return 1;
	if(b%2==0){
		return ele((a*a), b/2);
	}else{
		return a*ele((a*a), b/2);
	}
}

tint mcd(tint a, tint b){
	if(a==0)return b;
	return mcd(b%a, a);
}

tint mcm(tint a, tint b){
	tint g=mcd(a, b);
	return a*b/g;
}

double d_abs(long a, long b){
	if(a>b){
		return a-b;
	}
	return b-a;
}

bool isPal(string x){
	forn(i, x.size()){
		if(x[i]!=x[x.size()-i-1])return false;
	}
	return true;
}

tint getAns(tint n){
	tint tot=0;
	forn(i, n+1){
		tot+=i*i;
	}
	return tot;
}


void solve(int caso){
	tint n, m;
	cin>>n>>m;
	vector<tint> col(max(m,n)+5);
	col[1]=2;
	col[2]=4;
	tint MOD = 1e9+7;
	forsn(i, 3, max(m,n)+3){
		col[i]=(col[i-1]+col[i-2])%MOD;
	}
	tint ans=col[n]-2;
	ans+=col[m];
	ans%=MOD;
	cout<<ans<<endl;
}



int main (){
	int T;
	T=1;
	forn(caso, T){
		solve(caso);
	}
}
