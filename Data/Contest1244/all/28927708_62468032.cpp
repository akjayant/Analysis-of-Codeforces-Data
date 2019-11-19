#include<bits/stdc++.h>
using namespace std;
vector<int> *graph;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
  int a,b,c,d,k;
  cin>>a>>b>>c>>d>>k;
  int ans= (a+c-1)/c+ (b+d-1)/d;
  if(ans>k)
  cout<<-1<<"\n";
  else 
  cout<<(a+c-1)/c<<" "<<(b+d-1)/d<<"\n";
}

}