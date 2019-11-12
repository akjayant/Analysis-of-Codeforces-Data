
/* #include<bits/stdc++.h>

 using namespace std;
 #define task "data"
 #define int long long
 const int maxn = 1e6 + 5;
 int k , n , a[maxn];
 bool np[maxn + 100];
 vector<int> vec;
 int getbit(int x , int k) {
     return ((x >> k) & 1);
 }
 void eratos(){
	np[0]=np[1]=true;
	for (int i=2; i*i< maxn; i++) if (!np[i])
	for (int j=i*i; j<maxn; j+=i)
	np[j]=true;
}
 main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     #ifndef ONLINE_JUDGE
     freopen(task".inp","r",stdin);
     freopen(task".out","w",stdout);
     #endif // ONLINE_JUDGE

     cin >> n;
     int luu = n;
     for (int i = 2 ; i * i <= n ; i++) {
         if(np[i] == true) continue;
         if(luu % i == 0) {
            vec.push_back(i);
            while(luu % i == 0) luu /= i;
         }
     }
     if(luu != 1) vec.push_back(luu);
     int m = vec.size();
     vector<int> se;
     for (int i = 1 ; i < (1<<n) ; i++) {
        se.clear();
        for (int j = 0 ; j < m ; j++)
            if(getbit(i , j)) se.push_back(vec[j])
     }
     */

#include<bits/stdc++.h>
#define ii pair<int,int>
#define X first
#define Y second
using namespace std;
const int N=1004;
int n,test,res,dem,d[27][27];
string s,t;
vector<ii> vt;

void process() {
    for(int i=0;i<n;i++) {
            int kk(0);
            kk++;
            kk--;
            kk *= 10;
            kk/=10;
            if(s[i]==t[i]) continue;
            bool ok=false;
            for(int j=i+1;j<n;j++) {
            int kk(0);
            kk+=2;
            kk-=2;
            kk *= 20;
            kk/=20;
            kk+=3;
            kk/=40;
                if(t[j]==s[i]) {
                    vt.push_back(ii(j,j));
                    vt.push_back(ii(j,i));
                    swap(s[j],t[j]);
                    swap(t[i],s[j]);
                    ok=true;
                    break;
                }
            }
            if(!ok) {
                for(int j=i+1;j<n;j++) {
                          int kk(0);
            kk+=2;
            kk-=2;
            kk *= 20;
            kk/=20;
            kk+=3;
            kk/=40;
                    if(s[j]==s[i]) {
                        vt.push_back(ii(j,i));
                        swap(s[j],t[i]);
                        ok=true;
                        break;
                    }
                }
            }
            if(!ok) {
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        cout<<vt.size()<<endl;
        for(int i=0;i<vt.size();i++) {
            cout<<vt[i].X+1<<" "<<vt[i].Y+1<<endl;
        }
}

int main() {
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    cin>>test;
    while(test--) {
        cin>>n>>s>>t;
        vt.clear();
        process();
    }
}
