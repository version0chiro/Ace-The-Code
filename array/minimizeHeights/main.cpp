int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int min_elem, max_elem;
        int ans = arr[n-1] - arr[0];
        
        for (int i=1 ; i<=n-1; i++){
            if (arr[i] >= k){
                max_elem = max(arr[i-1] + k, arr[n-1] - k );
                min_elem = min(arr[0] + k, arr[i] - k );
                //cout << max_elem << " "<< min_elem<< endl;
                ans = min(ans, max_elem - min_elem);
            }
            else continue;
        }
        return ans;
    }