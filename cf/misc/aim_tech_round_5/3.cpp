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
struct rect {
  long long x1,y1,x2,y2;
};
rect cross(rect a, rect b) {
  rect ans;
  ans.x1 = max(a.x1, b.x1);
  ans.x2 = min(a.x2, b.x2);
  ans.y1 = max(a.y1, b.y1);
  ans.y2 = min(a.y2, b.y2);
  return ans;
}
bool common(rect a) {
  if(a.x1 <= a.x2 && a.y1 <= a.y2)return true;
  return false;
}
int n;
rect a[200000];
rect b[200000];
rect pls[200000];// プラス方向の累積cross
rect mis[200000];//マイナス方向の累積cross
rect skp[200000];//一個スキップしたときのcross
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  cin>>n;
  int i;
  for(i=1;i<=n;i++){
    cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
  }
  pls[0].x1 = -LINF;
  pls[0].y1 = -LINF;
  pls[0].x2 = LINF;
  pls[0].y2 = LINF;
  mis[n+1].x1 = -LINF;
  mis[n+1].y1 = -LINF;
  mis[n+1].x2 = LINF;
  mis[n+1].y2 = LINF;

  for(i=1;i<=n;i++){
    pls[i]=cross(pls[i-1], a[i]);
  }

  for(i=n;i>=1;i--){
    mis[i]=cross(mis[i+1], a[i]);
  }
  for(i=1;i<=n;i++){
    skp[i]=cross(pls[i-1], mis[i+1]);
    if(common(skp[i])){
      cout<<skp[i].x1<<" "<<skp[i].y1<<endl;
      return 0;
    }
  }
  return 0;
}
// https://codeforces.com/contest/1028/submission/42161280
