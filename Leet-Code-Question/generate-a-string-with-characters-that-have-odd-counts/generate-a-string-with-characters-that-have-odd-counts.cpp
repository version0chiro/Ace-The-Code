class Solution {
public:
    string generateTheString(int n) {
         return "b" + string(n - 1, 'a' + n % 2);
    }
};