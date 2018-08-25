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
bool is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  ll y,x;cin>>y>>x;
  string ans;
  ll cnt=0LL;
  // 1,2のコーナーケース処理
  /*
  x=1 or y=1: コーナーケース
  残りは最初のp,pを除いてあげて
  残りは開始地点が偶数か奇数か(終端の素数は奇数になるので)を見てやればOK
  */
  if(y<=2 || x<=2){
    ans="Second";
    //どうがんばってもFirstは素数マスに動かさざるを得ない
  }else if(is_prime(x) && is_prime(y)){
    ans="Second";
  }else{
    while(is_prime(x)){
      cnt++;
      x++;
    }
    while(is_prime(y)){
      cnt++;
      y++;
    }
    if(cnt%2==0){
      ans="Second";
    }else{
      ans="First";
    }
  }
  P(ans);
  return 0;
}
