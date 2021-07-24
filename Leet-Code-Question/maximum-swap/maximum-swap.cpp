class Solution {
public:
    int maximumSwap(int num) {
    string numString = to_string(num);
    int n = numString.length();
    vector<int> dpPosition(n, -1);
        
    int curMaxPos = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (numString[i] > numString[curMaxPos]) {
            curMaxPos = i;
        }
        dpPosition[i] = curMaxPos;
    }
        
    for (int i = 0; i < n; i++) {
        if(numString[dpPosition[i]] != numString[i]) {
            swap(numString[i], numString[dpPosition[i]]);
            break;
        }
    }
        
    return stoi(numString);
}
};