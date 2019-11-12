#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define forn(i,o,n) for(int i=o;i<n;i++)
#define int long long
#define endl "\n"
#define mod 1000000007
#define double long double
#define pb push_back
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
bool isPrime(int n){
    if(n < 2)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0 or n % 3 == 0)
        return 0;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 or n % (i+2) == 0)
            return 0;
    return 1;
}
int modexpo(int x,int p){
    int res = 1;
    x = x%mod;
    while(p){
        if(p%2)
            res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}
int32_t main(){
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string t;
        cin>>t;
        stack<int> c1[26]={};
        stack<int> c2[26]={};
        for (int i = 0; i < n; ++i)
        {
        	c1[s[i]-'a'].push(i);
        	c2[t[i]-'a'].push(i);
        }
        int f=0;
        for (int i = 0; i < 26; ++i)
        {
        	if((c1[i].size()+c2[i].size())%2){
        		cout<<"No"<<endl;
        		f=1;
        		break;
        	}
        }
        if(f){
        	continue;
        }
        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i)
        {
        	if(s[i]!=t[i]){
        		int x=-1,y=-1;
        		for (int j = i+1; j < n; ++j)
        		{
        			if(t[j]==t[i]){
        				x=j;
        				break;
        			}
        		}
        		if(x!=-1){
        			v.pb({i+1,x+1});
        			swap(s[i],t[x]);
        			continue;
        		}
        		else{
        			for (int j = i+1; j < n; ++j)
	        		{
	        			if(s[j]==t[i]){
	        				x=j;
	        				break;
	        			}
	        		}
	        		v.pb({x+1,i+2});
	        		swap(s[x],t[i+1]);
	        		v.pb({i+1,i+2});
	        		swap(s[i],t[i+1]);
        		}
        	}
        }
        if(v.size()<=2*n){
        	cout<<"Yes"<<endl;
        	cout<<v.size()<<endl;
        	for (int i = 0; i < v.size(); ++i)
        	{
        		cout<<v[i].first<<" "<<v[i].second<<endl;
        	}
        }
        else{
        	cout<<"No"<<endl;
        }
        cout<<endl;
    }
}