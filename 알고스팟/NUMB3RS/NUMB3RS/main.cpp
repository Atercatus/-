#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAX_SIZE_TOWNS 51
#define MAX_SIZE_DAYS 101
int num_of_towns;
int target;
int max_days;

double cache[MAX_SIZE_TOWNS][MAX_SIZE_DAYS];
//int towns[MAX_SIZE_TOWNS];
bool connected[MAX_SIZE_TOWNS][MAX_SIZE_TOWNS];
int deg[MAX_SIZE_TOWNS];

double find_dunibal(int town, int days) {
	if (days == max_days) {
		return town == target ? 1.0 : 0.0;
	}

	double &ret = cache[town][days];

	if (ret > -1) {
		return ret;
	}

	ret = 0.0;

	for (int next = 0; next < num_of_towns; next++) {
		if (connected[town][next]) {
			ret += find_dunibal(next, days + 1) / deg[town];
		}
	}

	return ret;
}

int main() {
	int prison;
	int num_of_cases;
	vector<vector<double>> ret;
	int num_of_targets;

	cin >> num_of_cases;

	for (int i = 0; i < num_of_cases; i++) {
		cin >> num_of_towns >> max_days >> prison;
		for (int j = 0; j < num_of_towns; j++) {
			deg[j] = 0;
			for (int k = 0; k < num_of_towns; k++) {
				cin >> connected[j][k];
				if (connected[j][k]) {
					deg[j]++;
				}
			}
		}

		cin >> num_of_targets;
		vector<double> temp;

		for (int j = 0; j < num_of_targets; j++) {
			for (int k = 0; k < MAX_SIZE_TOWNS; k++) {
				for (int l = 0; l < MAX_SIZE_DAYS; l++) {
					cache[k][l] = -1.0;
				}
			}
			cin >> target;
			temp.push_back(find_dunibal(prison, 0));
		}
		ret.push_back(temp);
	}

	for (int y = 0; y < ret.size(); y++) {
		for (int x = 0; x < ret[y].size(); x++) {
			cout << setprecision(8) << ret[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}
