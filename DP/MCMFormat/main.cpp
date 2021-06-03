int solve(int arr[],int i,int j){
    if(i>j){
        return 0;
    }

    for(int k=i;k<j;k++){
        temp = solve(arr,i,k) + solve(arr,k+1,j);

        //calculate ans using this temp ans 
    }
}

