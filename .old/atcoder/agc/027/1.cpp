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
ll a[111];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int n;ll x;cin>>n>>x;
  REP(i,n){
    cin>>a[i];
  }
  sort(a,a+n);
  ll sm=0;
  REP(i,n){
    sm+=a[i];
    if(sm>x){
      cout<<i<<endl;
      return 0;
    }
  }
  if(sm==x){
    P(n);
  }else{
    P(n-1);
  }
  return 0;
}
