using namespace std;

typedef long long i64;
const i64 NUM = 1000000007LL;

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  i64 n = int((s).size()), i;

  if(s[0] == 'm' || s[0] == 'w') {
    cout << 0 << endl;
    return 0;
  }
  else {
    i64 a0 = 1, a1 = 1;
    for(i=(1); i < (n); ++i) {
      switch(s[i]) {
      case 'm':
      case 'w':
 cout << 0 << endl;
 return 0;
      case 'n':
 if(s[i-1] == 'n') {
   i64 a2 = (a1 + a0) % NUM;
   a0 = a1;
   a1 = a2;
 }
 else {
   a0 = a1;
 }
 break;
      case 'u':
 if(s[i-1] == 'u') {
   i64 a2 = (a1 + a0) % NUM;
   a0 = a1;
   a1 = a2;
 }
 else {
   a0 = a1;
 }
 break;
      default:
 a0 = a1;
 break;
      }
    }
    cout << a1 << endl;
  }

  return 0;
}
