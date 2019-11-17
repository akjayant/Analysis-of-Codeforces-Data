using namespace std;

int lp = 1e9+7;

int dp[100100];

int main(){
 string s; cin>>s;
 dp[0] = 1;
 for(int n=1; n<=100000; n++){
  dp[n] = dp[n-1];
  if(n>=2){
   dp[n] += dp[n-2];
  }
  dp[n] %= lp;
 }
 long long ans = 1;
 int curseq = 0;
 char t = '-';
 for(int n=0; n<s.length(); n++){
  if(s[n]=='w' || s[n]=='m'){
   cout << 0 << endl;
   return 0;
  }
  if(s[n] == t){
   curseq++;
  } else {
   if(t=='u' || t=='n'){
    ans *= dp[curseq];
    ans %= lp;
   }
   curseq = 1;
   t = s[n];
  }
 }
 if(t=='u' || t=='n'){
  ans *= dp[curseq];
 }
 ans %= lp;
 cout << ans << endl;
 return 0;
}
