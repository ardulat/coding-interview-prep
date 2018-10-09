// https://www.interviewbit.com/problems/min-stack/

stack<int> s, mins;
int topElement;
int minElement;

MinStack::MinStack() {
    stack<int> emptyStack1;
    std::swap(s, emptyStack1);
    stack<int> emptyStack2;
    std::swap(mins, emptyStack2);
    topElement = -1;
    minElement = INT_MAX;
}

void MinStack::push(int x) {
    s.push(x);
    topElement = s.top();
    if (topElement <= minElement)
        minElement = topElement;
    mins.push(minElement);
}

void MinStack::pop() {
    if (!s.empty()) {
        s.pop();
        mins.pop();
        if (!s.empty()) {
            topElement = s.top();
            minElement = mins.top();
        }
        else {
            topElement = -1;
            minElement = INT_MAX;
        }
    }
}

int MinStack::top() {
    return topElement;
}

int MinStack::getMin() {
    if (minElement == INT_MAX)
        return -1;
    return minElement;
}

