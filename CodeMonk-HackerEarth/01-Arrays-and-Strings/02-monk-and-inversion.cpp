#include <iostream>
#include <vector>

using namespace std;

void count_and_print_inversions(int* nums, int n) {

}


int main() {
	int num;
	cin >> num;
	
	for (int t=0; t < num; t++) {
		int n = 0;
		cin >> n;

		int* nums = (int*)malloc(n * sizeof(int));

		vector<pair<int, int>> m, l;

		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				m.push_back(make_pair(i, j));
				l.push_back(make_pair(i, j));
				int x = 0;
				cin >> x;
				nums[i][j] = x;
			}
		}

		count_and_print_inversions(nums, n);
	}
}
