class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> dataSet;
        unordered_map<int,int> check;
        int length=0;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(check.find(val)==check.end() || check[val]==0){
                 dataSet.push_back(val);
        check[val]++;
        length++;
        return true;   
        }else{
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(check.find(val)!=check.end() &&  check[val]!=0){
            dataSet.erase(std::remove(dataSet.begin(), dataSet.end(), val), dataSet.end());
            check[val]--;
            length--;
            return true;
        }
        else{
            return false;
        }

    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIndex = rand() % length;
        return dataSet[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */