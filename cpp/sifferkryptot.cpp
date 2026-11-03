#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

string crypto;

ll combinations(ll i) {
  if (i == sz(crypto)) {
    return 1;
  }
  if (crypto[i] == '0') {
    return 0;
  }

  ll ans = combinations(i + 1);
  if (i + 1 < sz(crypto) && (crypto[i] == '1' || crypto[i] == '2')) {
    ans += combinations(i + 2);
  }

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> crypto;
  cout << combinations(0) << endl;
}
