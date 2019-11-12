#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int f1[27], f2[27] ;
vector < pair < int ,int> >v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
       cin>>n;
       cin>>a>>b;
        int flag = 0;  
        for(int i=0;i<26;i++){
            f2[i] = f1[i] = 0;
        }
        v.clear();
       for(int i=0;i<n;i++){
           f1[a[i] - 'a']++;
           f2[b[i] - 'a']++;
       }
       for(int i=0;i<26;i++){
           if((f1[i] + f2[i])%2){
               flag = 1;
               break;
           }
       }
       if(flag){
           cout<<"No\n";
           continue;
       }
       
       for(int i=0;i<n;i++){
           if(a[i] == b[i])
           continue;
           int fla= 0;
           for(int j=i+1;j<n;j++){
               if(b[j] == a[i]){
                   b[j] = a[i+1];
                   v.push_back({i+2,j+1});
                   a[i+1] = b[i];
                   b[i] = a[i];
                   v.push_back({i+2,i+1});
                   fla= 1;
                   break;
               }
           }
           if(!fla){
             //  cout<<"safdsfd"<<" "<<i<<endl;
               for(int j=i+1;j<n;j++){
                   if(a[j] == a[i]){
                       a[j] = b[i];
                       v.push_back({j+1,i+1});
                       break;
                   }
               }
           }
       }
       cout<<"Yes\n";
       cout<<v.size()<<"\n";
       for(int i=0;i<v.size();i++){
           cout<<v[i].first<<" "<<v[i].second<<"\n";
       }
    }
    return 0;
}