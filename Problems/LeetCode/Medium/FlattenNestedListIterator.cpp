// https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<NestedInteger> st;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = n-1; i >= 0; i--)
            st.push(nestedList[i]);
    }

    int next() {
        if (hasNext()) {
            NestedInteger top = st.top();
            st.pop();
            
            return top.getInteger();
        }
        return -1;
    }

    bool hasNext() {
        if (!st.empty()) {
            while (!st.empty() && !st.top().isInteger()) { // while top is not integer
                NestedInteger top = st.top();
                st.pop();

                vector<NestedInteger> temp = top.getList();
                for (int i = temp.size()-1; i >= 0; i--)
                    st.push(temp[i]);
            }
        }
        
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */