#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mp make_pair
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, a, b) for(int i = (a); i > (b); --i)

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <ll> vl;

const int mod = 1e9+7;
const ll inf = 2e18+5;

vl p;
void primeFactors(ll n)
{
    if(n%2==0) p.pb(2);
    while (n % 2 == 0)
    {

        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0) p.pb(i);
        while (n % i == 0)
        {

            n = n/i;
        }
    }


    if (n > 2)
      p.pb(n);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);

  ll n;
  cin>>n;
  primeFactors(n);
  int l = p.size();

  if(l==1 && p[0]==n){
  cout<<n<<endl; return 0;
  }
  if(l==1)
  {
  cout<<p[0]<<endl; return 0;
  }
  if(l>1 && p[0]==2){
    cout<<1<<endl; return 0;
  }
  cout<<1<<endl;
  return 0;
}
