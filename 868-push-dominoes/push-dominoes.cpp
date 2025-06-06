class Solution {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.size();
		string ans = string(n, '.');
		int first_r = -1;
		int last_l = -1;
		int j = 0;
		// debug(ans)
		while (j < n and dominoes[j] != 'R')
			j++;
		if (j < n) {
			first_r = j;
		}
		j = n - 1;
		while (j >= 0 and dominoes[j] != 'L')
			j--;
		if (j > -1) {
			last_l = j;
		}
		// debug(first_r)
		// debug(last_l)
		if (first_r != -1) {
			j = first_r - 1;
			while (j >= 0 and dominoes[j] != 'L')
				j--;
			if (j > -1) {
				for (int i = j; i >= 0; i--)
					ans[i] = 'L';
			}
		}
		if (last_l != -1) {
			j = last_l + 1;
			while (j < n and dominoes[j] != 'R')
				j++;
			if (j < n) {
				for (int i = j; i < n; i++) {
					ans[i] = 'R';
				}
			}
		}
		if (first_r == -1 and last_l != -1) {
			for (int i = last_l; i >= 0; i--) {
				ans[i] = 'L';
			}
		}
		else if (last_l == -1 and first_r != -1) {
			for (int i = first_r; i < n; i++) {
				ans[i] = 'R';
			}
		}
		else if (last_l != -1 and first_r != -1) {
			vector<int> idr, idl;
			for (int i =  last_l; i >= 0; i--) {
				if (dominoes[i] == 'R')
					idr.push_back(i);
			}
			for (int i =  last_l; i >= first_r; i--) {
				if (dominoes[i] == 'L')
					idl.push_back(i);
			}
			// debug(idr)
			// debug(idl)
			if (first_r > last_l) {
				for (int i = first_r; i < n; i++) {
					ans[i] = 'R';
				}
				for (int i = last_l; i >= 0; i--)
					ans[i] = 'L';
				return ans;
			}
			int l = -1;
			for (int i = first_r; i <= last_l; i++) {
				// debug(idr)
				// debug(idl)
				// debug(i)
				if (dominoes[i] == 'R') {
					// debug(i)
					idr.pop_back();
					l = i;
					if (!idr.empty() and !idl.empty()) {
						if (idr.back() < idl.back())
						{
							ans[i] = 'R';

						}
						else {
							int m = idl.back() - i + 1;
							// if(m&1){
							for (int k = 0; k < (m) / 2; k++) {
								ans[i + k] = 'R';
								ans[i + m - k - 1] = 'L';
							}
							// }
							// else{
							// for (int k = 0; k < (m) / 2; k++) {
							// 	ans[i + k] = 'R';
							// 	ans[i + m - k - 1] = 'L';
							// }
							// }
							i = idl.back();
							idl.pop_back();
							l = -1;
						}
					}
					else if (idr.empty() and !idl.empty()) {
						int m = idl.back() - i + 1;
						// if(m&1){
						// for (int k = 0; k < (m) / 2; k++) {
						// 	ans[i + k] = 'R';
						// 	ans[i + m - k - 1] = 'L';
						// }
						// }
						// else{
						for (int k = 0; k < (m) / 2; k++) {
							ans[i + k] = 'R';
							ans[i + m - k - 1] = 'L';
						}
						// }
						i = idl.back();
						idl.pop_back();
						l = -1;
					}
				}
				else if (dominoes[i] == '.')
				{

					if (l != -1 and l < i) {
						ans[i] = 'R';
					}
					else if (!idr.empty() and !idl.empty() and idl.back() < idr.back())
						ans[i] = 'L';
                    else if(idr.empty())
                        ans[i] = 'L';
				}
				else if (dominoes[i] == 'L') {
					if (i == idl.back())
					{
						ans[i] = 'L';
						idl.pop_back();
					}
				}
			}
		}
		return ans;
	}
};