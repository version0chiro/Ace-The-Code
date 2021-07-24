class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool possible=true;
        while(possible){            
            size_t found = s.find(part);
        
            if (found != string::npos)
                s.erase(found,part.size());
            else
                break;
        }
        return s;
    }
};