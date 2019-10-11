#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long countInversions(vector<int>& nums) {
    long long count = 0;

    if (nums.size() > 1) {
        // step 1: divide into two subarrays
        int mid = nums.size()/2;
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());

        // step 2: count number of inversions in subarrays
        count += countInversions(left);
        count += countInversions(right);

        cout << "left: " << endl;
        for (int num : left)
            cout << num << " ";
        cout << endl;
        cout << "right: " << endl;
        for (int num : right)
            cout << num << " ";
        cout << endl;

        // step 3: count number of split inversions
        int i = 0, j = 0;
        int k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            }
            else {
                cout << "INVERSION: " << left[i] << " " << right[j] << endl;
                nums[k] = right[j];
                j++;
                count += left.size()-i; // inversion
            }
            k++;
        }

        while (i < left.size() || j < right.size()) {
            if (i < left.size()) {
                nums[k] = left[i];
                i++;
            }
            if (j < right.size()) {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
    }

    cout << endl;

    return count;
}

int main() {

    // read input array from file
    int x;
    ifstream f;
    f.open("IntegerArray.txt");

    if (!f) {
        cout << "Unable to open a file." << endl;
        exit(1);
    }

    vector<int> nums; // numbers array
    while (f >> x) {
        nums.push_back(x);
    }

    f.close();

    vector<int> temp1{2, 4, 1, 3, 5};
    vector<int> temp2{10, 20, 30};
    vector<int> temp3{ 1, 20, 6, 4, 5 };

    // count number of inversions in the array
    long long res = countInversions(nums);

    cout << "NUMBER OF INVERSIONS: " << res << endl;

    return 0;
}