using namespace std;
typedef vector<long long> vei;
const long long maxn=500005;
const long long mod=1e9+7;

string s;
long long l;
long long f[maxn];
vei u,n;

signed main(){
 ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
 f[0]=1;
 f[1]=1,f[2]=2;
 for(long long i=3;i<=1e5;++i){
  f[i]=(f[i-1]+f[i-2])%mod;
 }
 cin>>s;
 l=s.length();
 s='#'+s;
 for(long long i=1;i<=l;++i){
  if(s[i]=='m'||s[i]=='w'){
   cout<<0;
   return 0;
  }
 }
 long long ans=1;
 long long cnt=0;
 for(long long i=1;i<=l;++i){
  if(s[i]=='u') cnt++;
  else u.push_back(cnt),cnt=0;
 }
 u.push_back(cnt),cnt=0;
 for(long long i=1;i<=l;++i){
  if(s[i]=='n') cnt++;
  else n.push_back(cnt),cnt=0;
 }
 n.push_back(cnt),cnt=0;
 for(long long i=0;i<u.size();++i){
  ans=(ans*f[u[i]])%mod;
 }
 for(long long i=0;i<n.size();++i){
  ans=(ans*f[n[i]])%mod;
 }
 cout<<ans;
 return 0;
}
