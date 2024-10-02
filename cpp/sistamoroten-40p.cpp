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

ll n, m, k;
vector<ll> sums;

void distribution(ll i, ll sum) {
  if (i == n) {
    sums[sum] += 1;
    return;
  }

  for (ll j = 1; j < m + 1; j++) {
    distribution(i + 1, sum + j);
  }
}

int main() {
  fast();

  cin >> n >> m >> k;
  sums.resize(n * m + 1);
  distribution(0, 0);
  sort(sums.rbegin(), sums.rend());

  double k_sum = 0;
  for (ll i = 0; i < k; i++) {
    k_sum += sums[i];
  }

  cout << k_sum / pow(m, n) << endl;

  return 0;
}
