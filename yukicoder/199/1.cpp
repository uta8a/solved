#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i, n) for (int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int         // 10^18
#define INF 1000000001           // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//---------------------------

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    
    string s;int i,j;cin>>s>>i>>j;
    string ans;
    for(int k=0;k<s.size();k++){
        if(k==i){
            ans+=s[j];
        }else if(k==j){
            ans+=s[i];
        }else{
            ans+=s[k];
        }
    }
    P(ans);
    return 0;
}