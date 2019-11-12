//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1000 + 10;
//int a[maxn];
//int n;
//
//bool check(int pos){
//    for(int i = 1; i <= n - pos + 1; i++) if(a[i] >= pos) return true;
//    return false;
//}
//
//int main(){
//    int T;
//    cin>>T;
//    while(T--){
//        cin>>n;
//        for(int i = 1; i <= n; i++) cin>>a[i];
//        sort(a + 1, a + 1 + n);
//        int l = 1, r = n;
//        int ans;
//        if(a[1] == a[n]){
//            cout<<a[1]<<endl;
//            continue;
//        }
//        while(l < r){
//            int mid = (l + r) >> 1;
//            if(check(mid)) ans = mid, l = mid + 1;
//            else r = mid;
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const double esp = 1e-6 ;
int sdghbfdajkdladsfhdsijkfhgdskjsfhdkjsh = 1;
string a ,b ;
vector<int>q;
int main()
{
    int t ;
    cin >> t ;
    int sdsjhbfgdskjjfgbsdkjfbdskjbf = 1;
    while(t--)
    {
        int sdnfkjdshnfikjgsdhuifygdjfndskjfdhsbnfikjdhsif = 1;
        q.clear();
        int n ;
        cin>>n>>a>>b;
        int asdhfnksdjhfiufdsyfhiusdhnfidsj = 1;
        for(int i = 0 ; i < a.size() ; i++){
            int dafjlsdkhjfdslkjfsdifjdpskjfgoihj  = 1;
            if(a[i]!=b[i]){q.push_back(a[i]-'a');q.push_back(b[i]-'a');}
            int adhnfkjdshfnkdsjfhnbksdjfdslkf = 1;
        }
        if(q.size()==0){int dfjdslkfjsdoihcvzxkfjsdoh = 1;cout << "Yes"<<endl;continue;}
        if(q.size()!=4) cout << "No" <<endl;
        else{
            if(q[0]==q[2]&&q[1]==q[3]) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }
    }
}

