
// Sample code to perform I/O:

#include <iostream>
#include <list>

using namespace std;

void rotate_and_print(list<int> nums, int k) {
	for (int l=0; l < k; l++) {
		int temp = nums.back();
		nums.pop_back();
		nums.push_front(temp);
	}

	for (int x: nums) {
		cout << x << " ";
	}
	cout << endl;
}


int main() {
	int num;
	cin >> num;
	
	for (int i=0; i < num; i++) {
		int n = 0, k = 0;
		cin >> n >> k;

		list<int> nums;

		for(int j=0; j < n; j++) {
			int x = 0;
			cin >> x;
			nums.push_back(x); 
		}

		rotate_and_print(nums, k);
	}
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

