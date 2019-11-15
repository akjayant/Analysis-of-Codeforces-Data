                       //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back


using namespace std;

typedef long long ll;

const int MAXN = 100001;
const int mod = 1000000007;

int main(){
    inp_out_work
    testCase{
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
       /* int fq1[26], fq2[26] ;
        fill(fq1, fq1 + 26, 0);
        fill(fq2, fq2 + 26, 0);
        for(char x : s)fq1[x-'a']++;
        for(char x : t)fq2[x-'a']++;*/
        bool can = 1;
        //fr(i,26)if(fq1[i] != fq2[i])can = 0;
        int i1 = -1 , i2 = -1;
        int miss = 0;
        fr(i,n)if(s[i] != t[i]){
                if(i1 == -1)i1 = i;
                else i2 = i;
                miss++;
        }
        if(miss != 2)can = 0;
        else if(s[i1] != s[i2] || t[i1] != t[i2])can = 0;


        if(can)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
