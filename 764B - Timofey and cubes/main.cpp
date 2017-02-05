#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> cubes;

	while (n > 0) {
		ll cube;
		cin >> cube;
		cubes.push_back(cube);
		--n;
	}

	int i, j;
	if (cubes.size() % 2 == 0) {
		i = cubes.size() / 2 - 1;
		j = i + 1;
	} else {
		i = cubes.size() / 2;
		j = i;
	}

	while (i >= 0 && j < cubes.size()) {
		if (i == j) {
			--i;
			++j;
			continue;
		}

		reverse(begin(cubes) + i, begin(cubes) + j + 1);
		
		--i;
		++j;
	}

	for (int k = 0; k < cubes.size(); ++k) {
		cout << cubes[k];
		if (k != cubes.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}
