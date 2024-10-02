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

ll n, t;
ll best_time = 1e7;
vector<pair<ll, ll>> buildings;

void rec(ll pickles, ll pps, ll time) {
  pickles += pps;
  time += 1;
  if (best_time <= time) {
    return;
  }
  if (t <= pickles) {
    best_time = time;
    return;
  }

  rec(pickles, pps, time);

  for (pair<ll, ll> building : buildings) {
    if (building.second <= pickles) {
      rec(pickles - building.second, pps + building.first, time);
    }
  }
}

int main() {
  fast();

  cin >> n >> t;

  buildings.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> buildings[i].first >> buildings[i].second;
  }

  rec(0, buildings[0].first, 0);
  cout << best_time << endl;

  return 0;
}
