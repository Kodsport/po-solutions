#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  ll ans = 0;
  rep(a, 1, n + 1) {
    // Notera att vi börjar från a, vi vill inte dubbelräkna
    rep(b, a, n + 1) {
      double c = sqrt(a * a + b * b - a * b);
      // ceil(c) == floor(c) testar om talet är ett heltal
      if (ceil(c) == floor(c) && 1 <= c && c <= n) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
