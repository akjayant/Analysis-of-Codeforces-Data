#include<bits/stdc++.h>
using namespace std;
int n,pre[10009],suff[10009];
string a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
       cin>>n;
       cin>>a>>b;
       int c=  0, ind1 = -1, ind2 = -1;
       for(int i=0;i<n;i++){
           if(a[i] != b[i]){
               c++;
               if(ind1 == -1)
               ind1 = i;
               else if(ind2 == -1)
               ind2 = i;
           }
       }
        if(c == 0){
            cout<<"Yes\n";
            continue;
        }
       if(c != 2){
           cout<<"No\n";
           continue;
       }
       else{
           if(a[ind1] == a[ind2] && b[ind2] == b[ind1]){
               cout<<"Yes\n";
               continue;
           }
           
       }
       cout<<"No\n";
    }
    return 0;
}