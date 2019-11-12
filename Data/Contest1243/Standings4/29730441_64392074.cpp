

#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
int a[maxn];
int n;

bool check(int pos){
    for(int i = 1; i <= n - pos + 1; i++) if(a[i] >= pos) return true;
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i = 1; i <= n; i++)
         cin>>a[i];
        sort(a + 1, a + 1 + n);
        int l = 1, r = n;
        int ans;
        if(a[1] == a[n])
        {
            cout<<a[1]<<endl;
            continue;
        }
        while(l < r)
        {
            int mid = (l + r)/2;
            if(check(mid))
                ans = mid, l = mid + 1;
            else r = mid;
        }
        cout<<ans<<endl;
    }
    return 0;
}


/*#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std ;

vector <int> V1 , V2 ;

int n ;
char s[10004] , t[10005] ;
int cnts[27] , cntt[27] ;
int main ()
{
    int dasdsadaslfssafasfafadfsdlgsfgsdaggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsdagsag = 6;
    int T ;
    scanf ("%d" , &T) ;
    while (T--)
    {
        int dasdsadaslfssafasfafadfsdlgsfgsdaggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsdagsagdasdsadaslfssafasfafadfsdlgsfgsdaggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsdagsagdasdsadaslfssafasfafadfsdlgsfgsdaggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsdagsagdasdsadaslfssafasfafadfsdlgsfgsdaggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsdagsag = 5;
        V1.clear() ;
        V2.clear() ;
        int dsasdadasfadfkfhasjdhfjkasdhkfjhaskjdfhkjasdhfjkasdhjkfhjkadhffkjashdfkjhzsdkjfhajksdhfjkadshfkjasdhfkjahsdkjfhasjkdhfkasjdhfjkasdhkjffhasjkhfkjasdhfkjasdhh = 444;
        s[0] = '+' ;
        scanf ("%d" , &n) ;
        scanf ("%s" , s + 1) ;
        scanf ("%s" , t + 1) ;
        for (int i = 1 ; i <= n ; ++i)
        {
            int aslfjalkdsjflkasdjgjadslkgjaslkddjglkasjlgkjalksjdlkfjaslkgjlkasjgksajglkjaslkgjaksl= 6;
            if (s[i] == t[i])
                continue ;
            int dasklflkasjflkajflksjdlkgjasdlkddgjlkasdjglksjglkasjlkgjlkasjglkasjgklasjdlkgjsdlkjflkasdjdlkgjaslkglkasjglkasjglkasdjglkasjlkgjaslkjglkasjgklajs = 6;
            bool flag = true ;
            for (int j = i + 1 ; j <= n ; ++j)
            {
                if (s[j] == t[i])
                {
                    V1.push_back(j) ;
                    V2.push_back(j) ;
                    swap(s[j] , t[j]) ;
                }
                int adklalkdfjlkasdjflkasdjflkasjdlkfjaslkdjflkasjdlkfjasdlkfjlksdajdflkasjdkfjasdkfjalskdjflkadsjflkasdjlkasjdlkfjasdlkgjglkasjglkasddjflkfasdlkfmsdlkafmlak = 9;
                if (t[j] == t[i])
                {
                    V1.push_back(i) ;
                    V2.push_back(j) ;
                    swap(s[i] , t[j]) ;
                    flag = false ;
                    break ;
                }
            }
            if (flag)
            {
                s[0] = '-' ;
                break ;
            }
//            printf ("s : %s\n" , s + 1) ;
//            printf ("t : %s\n" , t + 1) ;
        }
        if (s[0] == '-')
        {
            printf ("No\n") ;
            continue ;
        }
        int daslkfjsaklfjlkasjflkajdkgjasdlkdjflkadjflkadjglkjasdlkgjjaslkjglkasjglkasjlkgjaslkgjlakfjglkasdjglkjaslkjgjlkasjgalk = 6;
        printf ("Yes\n") ;
        printf ("%d\n" , V1.size()) ;
        for (int i = 0 ; i < V1.size() ; ++i)
        {
            printf ("%d %d\n" , V1[i] , V2[i]) ;
        }
        int asdaslkfjlaksjflkasdjlkgjadlkjglkadsjflkjadslkfjlkasdjfjlkasdjflkasjdlkfjasdlkfjelkjflkasdjflkmadlkfmlkawemfklamkldfmldamflkadmsflk = 9;
    }
}
*/


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
//
