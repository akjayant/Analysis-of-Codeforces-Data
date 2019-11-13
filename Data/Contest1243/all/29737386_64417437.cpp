#include<bits/stdc++.h>
#define int long long int
#define ul unsigned int
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL) ,cout.tie(NULL)
#define srt(v) sort(v.begin(),v.end());
using namespace std;

const int mod=1e9+7;
const int maxi=1e18;



int power(int a,int b,int p){
    if(a==0)
        return 0;
    if(b==0)
        return 1;

    int y;
    if(b%2==0){
        y=power(a,b/2,p);
        y=(y*y)%p;

    }
    else{
        y=a%p;
        y=(y*power(a,b-1,p)%p)%p;


    }

    return (y+p)%p;

}


int modInverse(int n,int p){
    power(n,p-2,p);
}

int ncrmod(int n,int r,int p){

    if(r==0)return 1;

    int fact[r+1];
    fact[0]=1;

    for(int i=1;i<=n;i++){

        fact[i]=(fact[i-1]*i)%p;
    }
    return (fact[n]*modInverse(fact[r],p)%p * modInverse(fact[n-r],p)%p)%p;

}
int test(){
    int te;
    cin>>te;
    return te;
}
signed main(){
    fast;

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;

        map<char,int>mp;
        int flag=0;
        rep(i,n){
            mp[a[i]]++;
        }

        rep(i,n){
            mp[b[i]]++;
        }

        rep(i,n){
            if(mp[a[i]]%2!=0){
                flag=1;
                //cout<<mp[a[i]]<<" "<<a[i]<<endl;
                break;
            }
            if(mp[b[i]]%2!=0){
                flag=1;
               // cout<<mp[b[i]]<<" "<<b[i]<<endl;
                break;
            }
        }


        if(flag==1){
            cout<<"No"<<endl;

        }
        else{
           vector<pair<int,int>> v;
            for(int i=0;i<n;i++){

                int check=0;
                int indx=0;
                for(int j=i+1;j<n;j++){

                    if(b[j]==a[i])
                    {
                        swap(a[j],b[j]);
                        v.push_back({j+1,j+1});
                        swap(b[i],a[j]);
                        v.push_back({j+1,i+1});
                        //1cout<<i<<" "<<j<<endl;
                        check=1;
                        break;
                    }
                }

                if(check==0){

                    for(int j=i+1;j<n;j++){

                        if(a[i]==a[j]){
                            swap(a[j],b[i]);
                            v.push_back({j+1,i+1});
                            break;
                        }
                    }

                }


            }
            cout<<"Yes"<<endl;
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i].first<<" "<<v[i].second<<endl;
            }


        }


    }

    


}
