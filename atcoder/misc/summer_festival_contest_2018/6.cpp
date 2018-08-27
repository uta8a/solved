// https://beta.atcoder.jp/contests/summerfes2018-div1/submissions/3071681
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

map<ll, int> prime_factor(ll n) {
  // whileでnからiがなくなるまで割っているので、res[i]は素数iの指数の値を示す。
    map<ll, int> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    // nが素数のとき、上の過程で取り除かれないのでそれをチェック
    if (n != 1) res[n] = 1;
    return res;
}

ll euler(ll mod) {
  // トーシェント関数
  // 一つ目のforの中ではp^e-1(p - 1)をかけている
    map<ll, int> pf = prime_factor(mod);
    ll res = 1;
    for (auto& p : pf) {
        ll tmp = 1;
        for (int i = 0; i < p.second - 1; i++) {
            tmp *= p.first;
        }
        res *= tmp * (p.first - 1);
    }
    return res;
}

ll modpow(ll x, ll n, ll mod) {
  // 繰り返し二乗法による
    if (x == 0) return 0;
    ll res = 1;
    while (n > 0) {
      // 奇数ならn&1==1になる。ここで奇数の一個分を掛ける処理をする
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1; //1bitシフトして1/2にする
    }
    return res;
}

ll solve(ll x, ll n, ll mod) {
  // x↑↑n modの値(テトレーションの剰余)
    if (mod == 1) return 0;
    if (n == 0) return 1;
    ll n2 = solve(x, n - 1, euler(mod));
    return modpow(x % mod, (n2 == 0 ? mod : n2), mod);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, m, k;
    cin >> a >> m >> k;

    ll ans = 0;
    for (ll i = 0; i < min(64LL, k - 1); i++) {
        (ans += solve(a, i, m)) %= m;
    }

    (ans += max(k - 1 - 64, 0LL) % m * solve(a, 63, m) % m) %= m;
    cout << ans << endl;
    return 0;
}
