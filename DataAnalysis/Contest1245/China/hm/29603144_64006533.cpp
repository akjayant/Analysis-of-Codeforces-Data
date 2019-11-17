using namespace std;

int N;
string s;

long long f[300005];

int main(){

 ios::sync_with_stdio(0);
 int NN = 1e5;
 f[1] = 1; f[2] = 2;
 for(int i=3;i<=NN;i++){
  f[i] = (f[i-1] + f[i-2]) % int(1e9 + 7);
 }

 cin>>s;
 N = s.length();
 s = "%" + s;

 long long ans = 1;
 for(int i=1;i<=N;i++){
  char c = s[i];
  if(c=='w' || c=='m'){
   cout<<"0"<<endl;
   return 0;
  }
  if(c!='n' && c!='u') continue;

  int n = 1;
  while(i+1<=N && s[i+1]==c){
   ++n;
   ++i;
  }

  ans = (ans * f[n]) % int(1e9 + 7);
 }

 cout<<ans<<endl;


 return 0;
}
