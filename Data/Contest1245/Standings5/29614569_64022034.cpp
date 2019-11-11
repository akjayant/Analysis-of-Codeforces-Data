#include <bits/stdc++.h>
using namespace std;

using ll = long long;



int main() {
  
  
	
  string s;
  cin >> s;
  
  
  vector<ll> asd(100001);
  asd[0]=1;
  asd[1]=1;
  asd[2]=2;
  asd[3]=3;
  asd[4]=5;
  for(int i = 5; i < 100001; i++){
    asd[i]=asd[i-1]+asd[i-2];
    asd[i]%=1000000007;
  }
  
  
  int n = s.size();
  
  ll ans=1;
  
  int a = 0;
  int b = 0;
    
  for(int i = 0; i < n; i++){
    if(s[i]=='m' || s[i]=='w'){cout << 0;return 0;}
    
    if(s[i]!='u' && s[i]!='n'){
      ans*=asd[b];
      ans%=1000000007;
      ans *= asd[a];
      
      a=0;
      b=0;
    }
    else if(s[i]=='u'){
      a++;
      
      
      ans*=asd[b];
      
      b=0;
    }
    else if(s[i]=='n'){
      b++;
      
      ans *= asd[a];
      a=0;
    }
    //cout<<s[i] << ": " << a <<" " <<b << " " <<ans <<endl;
    ans%=1000000007;
  }
  ans*=asd[a];
  ans%=1000000007;
      ans *= asd[b];
  ans%=1000000007;
  
  cout <<ans;
  
}
