class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int arr[] = {0,0};
        
        int remainFuel = 0;
        
        for(int i=1;i<cost.size();i++){
            remainFuel+=gas[i-1]-cost[i-1];
            if(remainFuel<arr[0]){
                arr[1]=i;
                arr[0]=remainFuel;
            }
        }
        
        
        
        int start = arr[1];
        int i = start;
        int net_fuel = 0;
        while(true){
            net_fuel = net_fuel + gas[i] - cost[i];
            i += 1;
            if(i == gas.size()) i = 0;
            if(i == start) return net_fuel >= 0 ? start : -1;
        }
            
        
        
        
        
        return -1;        
    }
};