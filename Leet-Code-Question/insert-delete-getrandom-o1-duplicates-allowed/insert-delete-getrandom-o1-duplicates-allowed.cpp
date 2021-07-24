class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> dataSet;
        unordered_map<int,int> check;
        int length=0;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(check.find(val)==check.end() || check[val]==0){
                 dataSet.push_back(val);
        check[val]++;
        length++;
        return true;   
        }else{
                      dataSet.push_back(val);
        check[val]++;
        length++;
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(check.find(val)!=check.end() &&  check[val]!=0){
            auto it = std::find(dataSet.begin(),dataSet.end(),val);
            if (it != dataSet.end()) {
                dataSet.erase(it);
            }
            cout<<dataSet.size();
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
        int randIndex = rand() % dataSet.size();
        return dataSet[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */