#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int comparisons; // number of comparisons for particular partition subroutine

int partition1(vector<int>& nums, int start, int end);
int partition2(vector<int>& nums, int start, int end);
int partition3(vector<int>& nums, int start, int end);

void quickSort(vector<int>& nums, int start, int end) {
    if (start >= end)
        return;
    
    int pivotIndex = partition3(nums, start, end);

    quickSort(nums, start, pivotIndex-1);
    quickSort(nums, pivotIndex+1, end);
}

int partition1(vector<int>& nums, int start, int end) {
    // choose first element as pivot
    int pivot = nums[start];
    int pivotIndex = start+1;

    comparisons += end-start; // n-1-0 = n-1 elements

    for (int i = start+1; i <= end; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(nums[start], nums[pivotIndex-1]); // swap pivot with last of left/less subarray

    return pivotIndex-1;
}

int partition2(vector<int>& nums, int start, int end) {
    // choose final/last element as pivot
    swap(nums[end], nums[start]);
    int pivot = nums[start];
    int pivotIndex = start+1;

    comparisons += end-start; // n-1-0 = n-1 elements

    for (int i = start+1; i <= end; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(nums[start], nums[pivotIndex-1]); // swap pivot with last of left/less subarray

    return pivotIndex-1;
}

int medianPivot(vector<int>& nums, int start, int end) {
    int size = end-start+1;
    int mid;
    if (size % 2 == 0) // even
        mid = size/2-1;
    else
        mid = size/2;

    // correct for right half
    mid += start; // case 4 5

    // for (int i = 0; i < size; i++)
    //     cout << i << " ";
    // cout << endl;
    // cout << "MID INDEX: " << mid << endl << endl;

    int first = nums[start];
    int second = nums[mid];
    int third = nums[end];

    int idx;

    // checking for the first
    if ((second <= first && first <= third) || 
        (third <= first && first <= second))
        idx = start;
    // checking for the second
    else if ((first <= second && second <= third) ||
            (third <= second && second <= first))
        idx = mid;
    else
        idx = end;

    // cout << first << " " << second << " " << third << endl;
    // cout << nums[idx] << " at index " << idx << endl;

    return idx;
}

int partition3(vector<int>& nums, int start, int end) {
    // choose pivot as median of three (start, mid, end)
    int customPivot = medianPivot(nums, start, end);
    swap(nums[customPivot], nums[start]); // exchange with first element
    int pivot = nums[start];
    int pivotIndex = start+1;
    
    int size = end-start+1;
    comparisons += size-1; // n-1-0 = n-1 elements
    // cout << "COMPARISONS: " << size-1 << "for start = " << start << " end = " << end << endl << endl;

    for (int i = start+1; i <= end; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(nums[start], nums[pivotIndex-1]); // swap pivot with last of left/less subarray

    return pivotIndex-1;
}



int main() {

    // read input array from file
    int x;
    ifstream f;
    f.open("QuickSort.txt");

    if (!f) {
        cout << "Unable to open a file." << endl;
        exit(1);
    }

    vector<int> nums; // numbers array
    while (f >> x) {
        nums.push_back(x);
    }

    f.close();

    quickSort(nums, 0, nums.size()-1);
    for (int i = 0; i < 20; i++)
        cout << nums[i] << " ";
    cout << endl;

    // vector<int> nums {4, 1, 3, 6, 2, 5};
    // // medianPivot(temp5, 0, temp5.size()-1);

    // quickSort(nums, 0, nums.size()-1);

    // for (int i = 0; i < nums.size(); i++)
    //     cout << nums[i] << " ";
    // cout << endl;

    cout << "COUNT: " << comparisons << endl;

    



    // vector<int> temp{ 8, 2, 4, 5, 7, 1 };
    // vector<int> temp4{4,5,6,7};

    // medianPivot(temp, 0, temp.size()-1);
    // medianPivot(temp4, 0, temp4.size()-1);

    // quickSort(temp, 0, temp.size()-1);
    // quickSort(temp4, 0, temp4.size()-1);



    // vector<int> temp1{2, 4, 1, 3, 5};
    // vector<int> temp2{10, 20, 30};
    // vector<int> temp3{ 1, 20, 6, 4, 5 };

    // quickSort(temp1, 0, temp1.size()-1);
    // quickSort(temp2, 0, temp2.size()-1);
    // quickSort(temp3, 0, temp3.size()-1);

    // for (int num : temp1)
    //     cout << num << " ";
    // cout << endl;

    // for (int num : temp2)
    //     cout << num << " ";
    // cout << endl;

    // for (int num : temp3)
    //     cout << num << " ";
    // cout << endl;

    return 0;
}