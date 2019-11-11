#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define int long long int
using namespace std;

int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int q;
      cin>>q;
      while(q--){
            int n;
            cin>>n;
            int r,p,s,cnt=0;
            cin>>r>>p>>s;
            string S;
            cin>>S;
            vector<char>ans(n,'q');
            for(int i=0;i<n;i++){
                  if(S[i]=='R'&&p>0){
                        p--;
                        cnt++;
                        ans[i]='P';
                  }
                  else if(S[i]=='P'&&s>0){
                        s--;
                        cnt++;
                        ans[i]='S';
                  }
                  else if(S[i]=='S'&&r>0){
                        r--;
                        cnt++;
                        ans[i]='R';
                  }
            }
            int q=(n/2+n%2);
            if(cnt>=q){
                  cout<<"YES\n";
                  for(int i=0;i<n;i++){
                        if(ans[i]=='q'){
                              if(r>0){
                                    cout<<'R';
                                    r--;
                              }
                              else if(p>0){
                                    cout<<'P';
                                    p--;
                              }
                              else if(s>0){
                                    cout<<'S';
                                    s--;
                              }
                        }
                        else cout<<ans[i];
                  }
                  cout<<"\n";
            }
            else cout<<"NO\n";
      }
}
