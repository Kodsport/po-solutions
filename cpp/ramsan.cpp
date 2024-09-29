#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high - 1; i >= 0; i--)
#define perr(i, high, low) for (int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  fast();

  ll words, n;
  cin >> words >> n;

  vector<ll> people(n);
  for (ll i = 0; i < n; i++) {
    people[i] = i + 1;
  }

  ll position = 0;
  for (ll i = 0; i < n - 1; i++) {
    position = (position + words - 1) % sz(people);
    people.erase(people.begin() + position);
  }

  cout << people[0] << endl;

  return 0;
}
