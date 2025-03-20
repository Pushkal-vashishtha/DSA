class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                int height = arr[s.top()];
                s.pop();
                int width = (s.empty()) ? i : (i - s.top() - 1);
                maxArea = max(maxArea, static_cast<long long>(height) * width);
            }
            s.push(i);
        }

        while (!s.empty()) {
            int height = arr[s.top()];
            s.pop();
            int width = (s.empty()) ? n : (n - s.top() - 1);
            maxArea = max(maxArea, static_cast<long long>(height) * width);
        }

        return maxArea;
    }
};