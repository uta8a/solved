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
int64_t N,M,i;

vector<int64_t> ediv(int64_t n){
  vector<int64_t> ret;
  for(i=1;i*i<=n;i++){
    if(n%i == 0){
      ret.push_back(i);
      if(i!=1 && i*i!=n){
        ret.push_back(n/i);
      }
    }
  }
  ret.push_back(n);
  return ret;
}
int64_t mn=LINF;
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  cin>>N>>M;
  for(auto i: ediv(M)){
    if(i>=N){
      mn=min(mn, i);
    }
  }
  cout<<M/mn<<endl;
  return 0;
}
