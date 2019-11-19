#include<bits/stdc++.h>
using namespace std;
typedef std::string                         str;
typedef long long int                       ll;
typedef std::pair<int,int>                  pii;
typedef std::pair<double,double>            pdd;
typedef std::pair<str,int>                  psi;
typedef std::pair<str,str>                  pss;
typedef std::pair<int,std::vector<int> >    pivi;
typedef std::vector<int>                    vi;
typedef std::vector<double>                 vd;
typedef std::vector<long long int>          vll;
typedef std::vector<std::string>            vs;
typedef std::vector<char>                   vc;
typedef std::vector<bool>                   vb;
typedef std::vector<pii >                   vpii;
typedef std::vector<pdd >                   vpdd;
typedef std::vector<psi >                   vpsi;
typedef std::vector<std::vector<int> >      vvi;
typedef std::vector<std::vector<ll> >       vvll;
typedef std::vector<std::vector<char> >     vvc;
typedef std::vector<std::vector<pii> >      vvpii;
typedef std::set<char>                      sc;
typedef std::set<int>                       si;
typedef std::set<long>                      sl;
typedef std::set<pii>                       spii;
typedef std::set<std::string>               ss;
typedef std::map<int, int>                  mii;
typedef std::map<int, char>                 mic;
typedef std::map<ll, ll>                    mll;
typedef std::map<char, bool>                mcb;
typedef std::map<char, char>                mcc;
typedef std::map<char, int>                 mci;
typedef std::map<int, vi>                   mivi;
typedef std::map<int, si>                   misi;
typedef std::map<int, pii>                  mipii;
typedef std::map<std::string, bool>         msb;
typedef std::map<std::string, int>          msi;
typedef std::map<std::string, std::string>  mss;
typedef std::deque<int>                     di;
#define fastio              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define incontainer(v)      for(size_t iai=0; iai<v.size(); iai++){std::cin >> v[iai];}
#define inmatrix(v)         for(size_t iai=0; iai<v.size(); iai++){for (size_t jaj = 0; jaj < v[iai].size() ; jaj++){std::cin >> v[iai][jaj];}}
#define outcontainer(v)     for(auto it : v){std::cout << it << ' ';}std::cout << std::endl;
#define outmatrix(v)         for(size_t iai=0; iai<v.size(); iai++){for (size_t jaj = 0; jaj <v[iai].size() ; jaj++){std::cout << v[iai][jaj] << ' ';} std::cout << std::endl;}
#define srt(a)              std::sort(a.begin(),a.end())
#define rev(a)              std::reverse(a.begin(),a.end())
#define bitcount(i)         __builtin_popcount(i)
#define gcdi(m,n)           __gcd(m,n)
#define forstl(i,v)         for(auto &i:v)
#define forn(i,n)           for(int i=0;i<n;++i)
#define forsn(i,e,n)        for(int i=e;i<n;++i)
#define rforn(i,e)          for(int i=e;i>=0;--i)
#define rforsn(i,e,n)       for(int i=e;i>=n;--i)
#define nl                  std::endl
#define out(x)              std::cout << x << std::flush
#define out2(a,b)           std::cout << a << ' ' << b << std::flush
#define out3(a,b,c)         std::cout << a << ' ' << b << ' ' << c << std::flush
#define out4(a,b,c,d)       std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::flush
#define out5(a,b,c,d,e)     std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << std::flush
#define out6(a,b,c,d,e,f)   std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << std::flush
#define outn(x)             std::cout << x << nl
#define outs(x)             std::cout << x << ' ' << std::flush
#define in(x)               std::cin >> x
#define in2(x,y)            std::cin >> x >> y
#define in3(x,y,z)          std::cin >> x >> y >> z
#define in4(w,x,y,z)        std::cin >> w >> x >> y >> z
#define in5(v,w,x,y,z)      std::cin >> v >> w >> x >> y >> z
#define in6(u,v,w,x,y,z)    std::cin >> u >> v >> w >> x >> y >> z
#define big_prime           1000000007
/*
void fastinput(int &x)
{
  bool neg = false;
  register int c;
  c = getchar();
  x = 0;
  if(c=='-')
  {
    neg = true;
    c= getchar();
  }
  for (; (c>47 && c<58); c = getchar())
  {
    x = (x<<1) + (x<<3) + c - 48;
  }
  if(neg)
  {
    x *= -1;
  }
}
*/
/*
vb primes(9000000,true);
void ps()
{
  for(int i = 2; i < sqrt(9000000) + 10 ; i++)
  {
    if(primes[i] == false)
    {
      continue;
    }
    for(int j = (2*i); j < 9000000; j+=i)
    {
      primes[j] = false;
    }
  }
}
void prime_setter()
{
  primes[0] = false;
  primes[1] = false;
  ps();
}
bool is_prime(ll n)
{
  if (n <= 1)
  {
    return false;
  }
  if (n <= 3)
  {
    return true;
  }
  if (n%2 == 0 || n%3 == 0)
  {
    return false;
  }
  for (ll i=5; i*i<=n; i=i+6)
  {
    if (n%i == 0 || n%(i+2) == 0)
    {
      return false;
    }
  }
  return true;
}
*/
int main()
{
  int T = 1;
  //in(T);
  while(T--)
  {
    int n;
    cin >> n;
    vi a(n);
    incontainer(a);
    srt(a);
    long long int x = 0;
    long long int y = 0;
    int i = 0;
    int j = n-1;
    //cout << a[0] << a[1] << a[2] << endl;
    while(i < j)
    {
      x += a[i];
      y += a[j];
      //cout << i << ' ' << j << ' ' << x << ' ' << y << endl;
      i++;
      j--;
    }
    //ll x1,x2,y1,y2;
    if(i == j)
    {
      y += a[j];
      j--;
    }
    //cout << x << ' ' << y << endl;
    ll z = x;
    z *= x;
    z += (y  * y);
    cout << z << endl;
  }
  return 0;
}
