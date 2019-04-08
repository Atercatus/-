class Solution {
public:
	string countAndSay(int n) {
		string term = "1";

		for (int i = 1; i < n; i++) {
			string tmp = "";
			int cnt = 0;

			for (int j = 0; j < term.length(); j++) {
				cnt++;
				if (term[j] != term[j + 1]) {
					tmp += to_string(cnt);
					tmp += term[j];
					cnt = 0;
				}
			}

			term = tmp;
		}

		return term;
	}
};