class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &currRow) {

        int n = currRow.size();
        vector<int> forward(n);
        stack<int> stack;
        stack.push(-1);

        for(int i = n-1; i >= 0; i--) {

            while(stack.top() != -1 && currRow[stack.top()] >= currRow[i]) {
                stack.pop();
            } 

            if(stack.top() == -1)
                forward[i] = n;
            else
                forward[i] = stack.top();
            
            stack.push(i);

        }
        return forward;
    }

    vector<int> previousSmallerElement(vector<int> &currRow) {

        int n = currRow.size();
        vector<int> backward(n);
        stack<int> stack;
        stack.push(-1);

        for(int i = 0; i < n; i++) {

            while(stack.top() != -1 && currRow[stack.top()] >= currRow[i]) {
                stack.pop();
            } 

            
            backward[i] = stack.top();
            
            stack.push(i);

        }

        return backward;
    }

    int largestRectangleArea(vector<int> &currRow) {

        vector<int> forward = nextSmallerElement(currRow);
        vector<int> backward = previousSmallerElement(currRow);

        int maxArea = INT_MIN;
        for(int i = 0; i < currRow.size(); i++) {
            
            int width = forward[i] - backward[i] - 1;
            int newAns = currRow[i]*width;
            maxArea = max(maxArea, newAns);

        }

        return maxArea;

    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        int col = matrix[0].size();

        int maxArea = INT_MIN;
        vector<int> currRow(col,0);

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < col; j++) {
                if(matrix[i][j] != '0')
                    currRow[j]++;
                else
                    currRow[j] = 0;
            }

            int newArea = largestRectangleArea(currRow);
            maxArea = max(maxArea, newArea);

        }

        return maxArea;

    }
};