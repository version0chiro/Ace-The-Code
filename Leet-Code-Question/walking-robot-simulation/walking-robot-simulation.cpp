class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        set<pair<int,int>> s;
        for(int i=0; i<obstacles.size(); i++)
            s.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        
        int arr[2];
        arr[0]=0;
        arr[1]=0;
        

        int dirIndex=0;
        
        int x_y_index=1;
        
        for(auto a:commands){
            if(a==-1 || a==-2){
                if(a==-1){
                    dirIndex+=1;
                }else{
                    dirIndex-=1;
                }
                if(dirIndex<0){
                    dirIndex=3;
                }else if(dirIndex>3){
                    dirIndex=0;
                }
                x_y_index=!x_y_index;
                
            }else{
                int numSteps=a;
                if(dirIndex==0){
                    while(numSteps--){
                        arr[1]++;
                        
                        if(s.find({arr[0],arr[1]})!=s.end()){
                            arr[1]--;
                            break;
                        }
                        
                    }
                    
                    ans=max(ans,arr[0]*arr[0]+arr[1]*arr[1]);
                    
                }else if(dirIndex==1){
                    while(numSteps--){
                        arr[0]++;
                        
                        if(s.find({arr[0],arr[1]})!=s.end()){
                            arr[0]--;
                            break;
                        }
                        
                    }
                    
                    ans=max(ans,arr[0]*arr[0]+arr[1]*arr[1]);
                    
                }else if(dirIndex==2){
                    while(numSteps--){
                        arr[1]--;
                        
                        if(s.find({arr[0],arr[1]})!=s.end()){
                            arr[1]++;
                            break;
                        }
                        
                    }
                    
                    ans=max(ans,arr[0]*arr[0]+arr[1]*arr[1]);
                    
                }else{
                        while(numSteps--){
                        arr[0]--;
                        
                        if(s.find({arr[0],arr[1]})!=s.end()){
                            arr[0]++;
                            break;
                        }
                        
                    }
                    
                    ans=max(ans,arr[0]*arr[0]+arr[1]*arr[1]);
                    
                }
        }}
        
        
        
        return ans;
    }
};