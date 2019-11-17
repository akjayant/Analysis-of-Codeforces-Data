using namespace std;

const int N=1e5+5;
const long long base=1e9+7;

long long fibo[N];

int n;
string s;
long long ans;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cin>>s;
 n=s.length();
 for (char &c: s)
 if (c=='m' || c=='w'){
     cout<<0;
     return 0;
 }
 ans=1;
 fibo[0]=1;
 fibo[1]=1;
 for (int i=2; i<=n; ++i)
     fibo[i]=(fibo[i-1]+fibo[i-2])%base;
 for (int i=0,j; i<n; i=j+1){
     j=i;
     while(j+1<n && s[j+1]==s[i]) ++j;
     if (j>i)
     if (s[i]=='n' || s[i]=='u')
         ans=ans*fibo[j-i+1]%base;
 }
 cout<<ans;
}
