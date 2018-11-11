// Leetcode 772 (premium)

// we can change function by not passing end
// for that, change return type of the function to pair<int, int>
// which will return a result of the expression and index of the end
int calculateExpression(vector<char> expression, int start) {
  
    for (int i = start; i < end; i++) {
        // case 1: '(', ')'
        // case 2: '+', '*', etc
        // case 3: '1', etc
        
        // (* 1 (+ 1 1))
        // product = 2
        int sum = 0;
        int product = 1;
        bool isPlus = false;
        bool isMul = false;
        bool isStarted = false;
        char curr = expression[i];
        
        if (curr == '(') {
            if (isStarted) {
                int result = calculateExpression(expression, i, i+j);
                if (isPlus)
                sum += result;
                if (isMul)
                product *= result;
                i += j;
            }
            isStarted = true;
        }
        else if (curr == '+') {
            isPlus = true;
        }
        else if (curr == '*') {
            isMul = true;
        }
        else if ('0' <= curr && curr <= '9') {
            if (isPlus) {
                sum += curr - '0';
            }
            if (isMul) {
                product *= curr - '0';
            }
        }
        else if (curr == ')') {
            if (isPlus)
                return sum;
            if (isMul)
                return product;
        }
    }
}