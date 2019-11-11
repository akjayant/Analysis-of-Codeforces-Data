#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string s;
ll MA = 1000000007;
ll ans=1;
ll A[100001];
int cnt = 0;
void f(int a){
    cnt++;
    ans*=A[a];
    ans%=MA;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>s;
    A[1]=1;
    A[2]=2;
    for(int i=3 ; i<=s.size() ; i++){
        A[i] = A[i-1]+A[i-2];
        A[i]%=MA;
    }
    char pre=s[0];
    int a = 1;
    if(s[0]=='m'||s[0]=='w'){
        cout<<"0";
        return 0;
    }
    for(int i=1 ; i<s.size() ; i++){
        if(s[i]=='m'){
            cout<<"0";
            return 0;
        }
        if(s[i]=='w'){
            cout<<"0";
            return 0;
        }
        if(s[i]==pre&&(pre=='u'||pre=='n')){
            a++;
        }
        else{
            if(a!=1){
                f(a);
            }
            a=1;
        }
        pre = s[i];
    }
    if(a!=1){
        f(a);
    }
    cout<<ans;
}