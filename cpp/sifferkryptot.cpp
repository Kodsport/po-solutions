#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

string crypto;

ll combinations(ll i) {
  if (i == crypto.size()) {
    return 1;
  }
  if (crypto[i] == '0') {
    return 0;
  }

  ll ans = combinations(i + 1);
  if (i + 1 < crypto.size() && (crypto[i] == '1' || crypto[i] == '2')) {
    ans += combinations(i + 2);
  }

  return ans;
}

int main() {
  fast();

  cin >> crypto;
  cout << combinations(0) << endl;

  return 0;
}
