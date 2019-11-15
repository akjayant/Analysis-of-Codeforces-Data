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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);

  int t,n;
  cin>>t;
  while(t--){
  cin>>n;
  vii ans;
  string a,b;
  char temp;
  cin>>a>>b;
  int c=0,p,q;
  loop(i,0,n){
    if(a[i]!=b[i]){
        c=0;
        loop(j,i+1,n){
          if(a[j]!=b[j] && b[j]==b[i]){
            ans.pb(mp(i+1,j+1));
            c=1;
            temp=b[j];
            b[j]=a[i];
            a[i]=temp;
            break;
          }
        }
        if(!c){
        loop(j,i+1,n){
          if(a[j]!=b[j] && a[j]==b[i]){
            ans.pb(mp(j+1,j+1));

            temp=b[j];
            b[j]=a[j];
            a[j]=temp;
            ans.pb(mp(i+1,j+1));

            temp=b[j];
            b[j]=a[i];
            a[i]=temp;
            break;
          }
        }
        }
    }
  }
  int l=ans.size();
  if(a!=b || l>2*n) cout<<"No"<<endl;
  else{
  cout<<"Yes"<<endl;

  cout<<l<<endl;
  loop(i,0,ans.size())
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
  }
  return 0;
}
