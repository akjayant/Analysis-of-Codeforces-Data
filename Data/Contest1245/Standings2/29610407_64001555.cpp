//Æ­·Ö²»¹æ·¶£¬±¬ÁãÁ½ÐÐÀá
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define endl '\n'
#define rep(i,n) for(register int i=0;i<(n);++i)
#define For(i,x,y) for(register int i=(x);i<=(y);++i)
#define pii pair<int,int>
using namespace std;
#define mod_int quick_num
long long md=1000000007;
struct quick_num{
	long long num;
	inline void read(){cin>>num;}
	inline void write(){cout<<num;}
	inline void _write(){cout<<num<<' ';}
	inline void print(){cout<<num<<endl;}
};
inline void read(quick_num&x){cin>>x.num;}
inline void write(quick_num x){cout<<x.num;}
inline void _write(quick_num x){cout<<x.num<<' ';}
inline void print(quick_num x){cout<<x.num<<endl;}
inline long long qp(long long x,long long y){
	long long rt=1;
	for(;y;y>>=1,(x*=x)%=md)if(y&1)(rt*=x)%=md;
	return rt;
}
inline long long inv(long long x){return qp(x,md-2);}
inline quick_num operator +(quick_num a,quick_num b){
	quick_num c;c.num=a.num+b.num;
	if(c.num>=md)c.num-=md;
	return c;
}
inline quick_num operator -(quick_num a,quick_num b){
	quick_num c;c.num=a.num-b.num;
	if(c.num<0)c.num+=md;
	return c;
}
inline quick_num operator *(quick_num a,quick_num b){
	quick_num c;c.num=a.num*b.num;
	c.num%=md;
	return c;
}
inline quick_num operator /(quick_num a,quick_num b){
	quick_num c;c.num=a.num*inv(b.num)%md;
	return c;
}
inline quick_num operator %(quick_num a,quick_num b){
	quick_num c;c.num=a.num%b.num;
	return c;
}
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char(){
    if(S==T){
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}

inline int read(){
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0' or c>'9';c=Get_Char())if(c=='-')f=1;
    for(;c>='0' and c<='9';)re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    if(f)return -re;
    return re;
}

inline void read(int&x){
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0' or c>'9';c=Get_Char())if(c=='-')f=1;
    for(;c>='0' and c<='9';)re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    if(f)x=-re;
    else x=re;
}
const int mxn=100005;
string s;
ll dp[mxn];
signed main(){
	ios_base::sync_with_stdio(false);
	cin>>s;s=" "+s;
	for(int i=1;i<s.size();++i)if(s[i]=='w' or s[i]=='m'){
		cout<<0<<endl;
		return 0;
	}
	dp[0]=1,dp[1]=1;
	for(int i=2;i<s.size();++i){
		dp[i]=dp[i-1];
		if(s[i]=='u' and s[i-1]=='u')dp[i]+=dp[i-2];
		if(dp[i]>=md)dp[i]-=md;
		if(s[i]=='n' and s[i-1]=='n')dp[i]+=dp[i-2];
		if(dp[i]>=md)dp[i]-=md;
dp[i]%=md;
	}
	cout<<dp[s.size()-1]%md<<endl;
}