class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size(), s2Size = s2.size();
        if (s1Size > s2.size()) {
            return false;
        }
        unordered_map<char, int> counts;
        for (char c : s1) {
            counts[c]++;
        }
        for (int i = 0; i < s2Size; i++) {
            // Possible substring match
            if (counts.find(s2[i]) != counts.end()) {
                // Check valid substring
                bool found = true;
                unordered_map<char, int> substrMap;
                for (int k = s1Size, s2Idx = i; k > 0; k--, s2Idx++) {
                    if (counts.find(s2[s2Idx]) == counts.end()) {
                        i = s2Idx;
                        found = false;
                        break;
                    }
                    substrMap[s2[s2Idx]]++;
                }
                // Check if valid substring found
                if (found && counts == substrMap) {
                    return true;
                }
            }
        }
        return false;
    }
};