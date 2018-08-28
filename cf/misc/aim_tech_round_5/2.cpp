#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int // 10^18
#define INF 1000000001 // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//---------------------------
int func(int n, int a) {
    // a=10
    // 計算量log_10 n < 2230
    int res = 0;
    while (n > 0) {
        res += n%a;
        n /= a;
    }
    return res;
}
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int n,m;cin>>n>>m;
  int i;
  for(i=0;i<2000;i++){
    cout<<5;
  }
  cout<<" ";
  for(i=0;i<1999;i++){
    cout<<4;
  }
  cout<<5;
  cout<<"\n";
  return 0;
}
