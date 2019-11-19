#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define point pair<double,double>
#define segment pair<point,point>
#define circle pair<point,double> //titik pusat, radius
#define line pair<double,double> //m,c
#define ins insert
#define er erase
 
#define FORU(a,b,c) for(int a=b; a<=c; a++)
#define FORD(a,b,c) for(int a=b; a>=c; a--)
#define FOR(a,b) for(int a=1; a<=b; a++)
#define FORA(a,b) for(auto (a) : (b))
 
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
 
#define yu using
#define don namespace
#define sei std
 
yu don sei;
 
//const int nPrime=100000;
//bool isprime[nPrime];
//vector<int>prime;
//
//void pre()
//{
//  memset(isprime,1,sizeof(isprime));
//  isprime[1]=0;
//  for(int i=2;i*i<=nPrime;i++)
//  {
//      for(int j=i*i;j<nPrime;j+=i)
//      {
//          isprime[j]=0;
//      }
//  }
//  for(int i=2;i<nPrime;i++)
//  {
//      if(isprime[i])prime.pb(i);
//  }
//}
 
// ll pwr(ll b,ll e)
// {
//  if(e==0)return 1;
//  if(e==1)return b;
//  ll temp=pwr(b,e/2);
//  if(e%2==0)
//  {
//      return (temp*temp);
//  }
//  else
//  {
//      return (temp*temp*b);
//  }
// }
 
// ll modpow(ll b,ll e)
// {
//  b%=MOD;
//  if(e==0)return 1;
//  if(e==1)return b%MOD;
//  ll temp=modpow(b,e/2);
//  if(e%2==0)
//  {
//      return (temp*temp) %MOD;
//  }
//  else
//  {
//      return ((temp*temp %MOD )*b)%MOD;
//  }
// }
 
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
 
//int n,m;
 
//bool valid(int x,int y)
//{
//  if(x<0)return 0;
//  if(y<0)return 0;
//  if(x>=n)return 0;
//  if(y>=m)return 0;
//  return 1;
//}
 
//int p[]={-1,0,1,0};
//int q[]={0,1,0,-1};
 
//int p[]={-1,-1,-1,0,0,1,1,1};
//int q[]={-1,0,1,-1,1,-1,0,1};
 
point add(point a,point b)
{
    return {a.fi+b.fi,a.se+b.se};
}
 
point sub(point a,point b)
{
    return {a.fi-b.fi,a.se-b.se};
}
 
//double dist(point a,point b)
//{
//    return ((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
//}
 
double dist(point a,point b)
{
    return sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}
 
//double distPS(point a,segment b)//heron formula, extreemely prone to precison error
//{
//    double AB=rdist(a,b.fi);
//    double AC=rdist(a,b.se);
//    double BC=rdist(b.fi,b.se);
//    double s=AB+AC+BC;
//    s/=2.0;
//    return 2*sqrt(s*(s-AB)*(s-BC)*(s-AC))/BC;
//}
 
double dabs(double a)
{
    if(a+EPS>0)return a;
    return -a;
}
 
double dotProduct(point a,point b)
{
    return a.fi*b.fi + a.se*b.se;
}
 
double crossProduct(point a,point b)
{
    return a.fi*b.se - a.se*b.fi;
}
 
int ccw(point a,point b,point c)// -1 CCW 0 COL 1 CW
{
    double tmp=crossProduct(sub(b,a),sub(c,a));
    if(tmp>EPS)
    {
        return -1;
    }
    else if(tmp<-EPS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
point intLiLi(point a,point b,point c,point d)
{
    return mp(((a.fi*b.se-b.fi*a.se)*(c.fi-d.fi) - (a.fi-b.fi)*(c.fi*d.se-d.fi*c.se))/((a.fi-b.fi)*(c.se-d.se) - (a.se-b.se)*(c.fi-d.fi) ),
            ((a.fi*b.se-b.fi*a.se)*(c.se-d.se)-(a.se-b.se)*(c.fi*d.se-d.fi*c.se))/((a.fi-b.fi)*(c.se-d.se) - (a.se-b.se)*(c.fi-d.fi) ));
}
 
int main()
{
    int n;
    cin>>n;
    vector<int>A(n,0);
    for(auto &a:A)cin>>a;
    sort(A.begin(), A.end());
    ll a=0,b=0;
    for(int i=0;i<n/2;i++)
    {
        a+=A[i];
    }
    for(int i=n-1;i>=n/2;i--)
    {
        b+=A[i];
    }
    // cout<<a<<" "<<b<<endl;
    cout<<a*a + b*b<<endl;
    return 0;
}