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

using namespace std ;
vector <int> V1 , V2 ;
char s[10004] , t[10005] ;
int T, n;

void solve(){
    scanf ("%d" , &T) ;
    while (T--){
        int sdbfkdshjbfksdhjbfjhdsbfhujdsb = 1;
        V1.clear() ;V2.clear() ;s[0] = '+' ;
        scanf ("%d" , &n) ;scanf ("%s" , s + 1) ;scanf ("%s" , t + 1) ;
        for (int i = 1 ; i <= n ; ++i){
            if (s[i] == t[i])continue ;
            bool flag = true ;
            int asdjfhbksdjfghbdskjhgfdsjhfgdsuhjigfdsjhgf = 1;
            for (int j = i + 1 ; j <= n ; ++j){
                if (s[j] == t[i]){V1.push_back(j) ;V2.push_back(j) ;swap(s[j] , t[j]) ;}
                if (t[j] == t[i]){V1.push_back(i) ;V2.push_back(j) ;swap(s[i] , t[j]) ;flag = false ;break ;}
                int dsfhbksdjhbfdksjhfbdskjhgfbdsk = 1;
            }
            if (flag){s[0] = '-' ;break ;}
            int sdkjhfdskjhfdskjhfdskhsjf = 1;
        }
        if (s[0] == '-'){printf ("No\n") ;continue ;}
        printf ("Yes\n") ; printf ("%d\n" , V1.size()) ;
        for (int i = 0 ; i < V1.size() ; ++i) printf ("%d %d\n" , V1[i] , V2[i]) ;
    }
}

int main (){
    solve();
    return 0;
}


