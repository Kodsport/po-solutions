#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

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
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> t;

  buildings.resize(n);
  rep(i, 0, n) {
    cin >> buildings[i].first >> buildings[i].second;
  }

  rec(0, buildings[0].first, 0);
  cout << best_time << endl;
}
