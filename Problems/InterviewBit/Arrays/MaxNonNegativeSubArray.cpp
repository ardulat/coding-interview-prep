// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    // Kadane's algorithm
    long max_so_far = LONG_MIN, max_ending_here = 0;
    vector<int> candidate_array, max_array;
    int starting_index = -1, candidate_starting_index = -1;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= 0) {
            if (candidate_starting_index == -1)
                candidate_starting_index = i;
            max_ending_here += A[i];
            candidate_array.push_back(A[i]);
            if (max_ending_here < 0){
                max_ending_here = 0;
                candidate_array.clear();
                candidate_starting_index = -1;
            }
            if (max_so_far < max_ending_here){
                max_so_far = max_ending_here;
                max_array = candidate_array;
                starting_index = candidate_starting_index;
            } else if (max_so_far == max_ending_here) {
                if (max_array.size() < candidate_array.size()){
                    max_array = candidate_array;
                    starting_index = candidate_starting_index;
                }
                else if (max_array.size() == candidate_array.size()) {
                    if (starting_index < candidate_starting_index)
                        continue; // do not change max_array
                    else {
                        max_array = candidate_array;
                        starting_index = candidate_starting_index;
                    }
                }
            }
        } else{
            max_ending_here = 0;
            candidate_array.clear();
            candidate_starting_index = -1;
        }
    }
    // cout << max_so_far << endl;
    return max_array;
}

// Edge case of the year A : [ 1967513926, 1540383426, -1303455736, -521595368 ], which overfills INT
