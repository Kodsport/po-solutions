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

int main() {
  fast();

  ll n, x, y;
  cin >> n >> x >> y;

  vector<ll> lamps(n);
  for (ll i = 0; i < n; i++)
    cin >> lamps[i];

  sort(lamps.begin(), lamps.end());

  ll acc = 0;
  ll count = 0;
  for (ll i = 0; i < n; i++) {
    acc += x * lamps[i];
    count += 1;

    if (y < (acc + count - 1) / count) {
      count -= 1;
      break;
    }
  }

  cout << count;

  return 0;
}
