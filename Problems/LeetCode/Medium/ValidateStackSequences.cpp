// https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    /*
    Algorithm 1:
    - simulate the operations on the stack with two pointers
    
    pushed = [1,2,3,4,5]
    popped = [4,5,3,2,1]
    
    st = [1,2,3,4]
    st.top() == popped[j]
        st.pop(); j++;
    st = [1,2,3]
    st.top() != popped[j]
        st.push(pushed[i]); i++?
    st = [1,2,3,5]
    st.top() == popped[j]
        st.pop(); j++;
    st = [1,2,3]
    st.top() == popped[j]
        st.pop(); j++;
    st = [1,2]
    ...
    
    Run loop until:
    - stack is not empty
    - i < pushed.size()
    */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty())
            return true;
        int i = 0, j = 0; // two pointers
        stack<int> st;
        st.push(pushed[i]);
        i++;
        while (i <= pushed.size()) {
            
            if (st.empty() || st.top() != popped[j]) {
                if (i < pushed.size())
                    st.push(pushed[i]);
                i++;
            } else if (st.top() == popped[j]) {
                    st.pop(); j++;
            }
        }
        return st.empty();
    }
};
