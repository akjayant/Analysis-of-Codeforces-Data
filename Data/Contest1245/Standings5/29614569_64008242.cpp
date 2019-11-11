#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
  
  int t = 0;
  cin >> t;
  for(int k = 0; k < t; k++){
    
    int n;
    cin >> n;
    
    int a,b,c;
    cin >>a >> b >> c;
    
    string s;
    cin >> s;
    
    vector<char> win(n,'X');
    int won = 0;
    
    int x=0,y=0,z=0;
    
    for(int i = 0; i < n; i++){
      if(s[i]=='R')x++;
      else if(s[i]=='P')y++;
      else if(s[i]=='S')z++;
    }
    
    won+=min(a,z);
    won+=min(b,x);
    won+=min(c,y);
    
    int wa = min(a,z);
    int wb = min(b,x);
    int wc = min(c,y);
    
    if(won>=((1+n)/2)){
      cout << "YES\n";
      
      int a2 = a;
      int b2 = b;
      int c2 = c;
      
      int x2 = 0;
      int y2 = 0;
      int z2 = 0;
      
      for(int i = 0; i < n; i++){
        if(s[i]=='R'){
          b2--;
          if(b2>=0){win[i]='P';y2++;}
          
        }
      }
      for(int i = 0; i < n; i++){
        if(s[i]=='P'){
          c2--;
          if(c2>=0){win[i]='S';z2++;}
          
        }
      }
      for(int i = 0; i < n; i++){
        if(s[i]=='S'){
          a2--;
          if(a2>=0){win[i]='R';x2++;}
          
        }
      }
      
      for(int i = 0; i < n; i++){
        if(win[i]!='X'){
          cout << win[i];
        }
        else {
          if(x2<a){
            cout << 'R';x2++;
          }
          else if(y2<b){
            cout << 'P';y2++;         
          }else if(z2<c){
            cout << 'S'; z2++;
          }
        }
      }
      cout << endl;
      
    }
    else cout << "NO\n";
    
    
    
    
    
  }
  
  
}
