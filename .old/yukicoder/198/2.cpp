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
  bool FirstFlag=true;
  /*
  x=1 or y=1: コーナーケース
  残りは最初のp,pを除いてあげて
  残りは開始地点が偶数か奇数か(終端の素数は奇数になるので)を見てやればOK
  （コーナーケースを除いた）今の座標がどちらも3以上の場合
  (偶数,偶数) ⇛ 動くとどちらかが奇数になるため負ける可能性がある。
  (奇数,偶数) , (偶数,奇数) ⇛ （偶数、偶数）に移動できるため、負けることはない。
  (奇数,奇数) ⇛ どちらか偶数に移動できるため負ける可能性がない。
  tip: 表で考える、偶奇に着目する、丁寧にコーナーケースを処理する(2次元なので4通りとかになる)
  */


  // まずはx<=2 or y<=2 の場合を処理していく
  if(x<=2 && y>2) {
    // 2のときは右に進むと3が素数でひっかかり、上に進むと2が素数でひっかかる
    if(x==2){
      FirstFlag = false;
    }else{
      FirstFlag = y%2==0 ? false:true;
    }
  }else if(x>2 && y<=2){
    if(y==2){
      FirstFlag = false;
    }else{
      FirstFlag = x%2==0 ? false:true;
    }
  }else if(x<=2 && y<=2){
    FirstFlag = false;
  }else{
    if(x%2==0){
      if(y%2==0){
        FirstFlag=false;
      }else{
        FirstFlag=true;
      }
    }else{
      if(y%2==0){
        FirstFlag=true;
      }else{
        FirstFlag=false;
      }
    }
  }
  if(FirstFlag){
    P("First");
  }else{
    P("Second");
  }

  return 0;
}
