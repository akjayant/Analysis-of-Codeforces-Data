#include<bits/stdc++.h>
using namespace std;

int ntest;
int n;
string st;
int ns,np,nr;
string res;
int s,p,r;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>ntest;
    for(int nt=1;nt<=ntest;nt++){
        cin>>n;
        cin>>nr>>np>>ns;
        cin>>st;
        res="";for(int i=1;i<=n;i++) res=res+' ';
        s=p=r=0;int kq=0;
        for(int i=0;i<n;i++){
            if (st[i]=='S' && nr>0){
                kq++;res[i]='R';nr--;
            }
            if (st[i]=='P' && ns>0){
                kq++;res[i]='S';ns--;
            }
            if (st[i]=='R' && np>0){
                kq++;res[i]='P';np--;
            }
        }
        for(int i=0;i<n;i++){
            if (res[i]==' '){
                if (nr>0){
                    nr--;res[i]='R';
                }
            }
            if (res[i]==' '){
                if (ns>0){
                    ns--;res[i]='S';
                }
            }
            if (res[i]==' '){
                if (np>0){
                    np--;res[i]='P';
                }
            }
        }
        int nz=(n+1)/2;
        if (kq>=nz) cout<<"YES\n"<<res<<endl;
        else cout<<"NO\n";
    }
}
