#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAX_TOWN_SIZE 51
#define MAX_DAYS_SIZE 101

double cache[MAX_TOWN_SIZE][MAX_DAYS_SIZE];
bool connected[MAX_TOWN_SIZE][MAX_TOWN_SIZE];
int deg[MAX_TOWN_SIZE];
int target;
int num_of_towns;

double find_dunibal(int town, int days) {
	if (days == 0) {
		return town == target ? 1.0 : 0.0;
	}

	double &ret = cache[town][days];

	if (ret > -1.0)
		return ret;

	ret = 0.0;

	for (int before = 0; before < num_of_towns; before++) {
		if (connected[town][before]) {
			ret += find_dunibal(before, days - 1) / deg[town];
		}
	}

	return ret;
}

int main() {
	int num_of_cases;
	cin >> num_of_cases;

	int max_days;
	int prison;
	int num_of_targets;
	vector<vector<double>> ret;

	for (int c = 0; c < num_of_cases; c++) {
		cin >> num_of_towns >> max_days >> prison;

		for (int y = 0; y < num_of_towns; y++) {
			deg[y] = 0;
			for (int x = 0; x < num_of_towns; x++) {
				cin >> connected[y][x];
				if (connected[y][x]) {
					deg[y]++;
				}
			}
		}

		cin >> num_of_targets;
		vector<double> temp;

		for (int i = 0; i < num_of_targets; i++) {
			for (int y = 0; y < MAX_TOWN_SIZE; y++) {
				for (int x = 0; x < MAX_DAYS_SIZE; x++) {
					cache[y][x] = -1.0;
				}
			}
			cin >> target;
			temp.push_back(find_dunibal(prison, max_days));
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