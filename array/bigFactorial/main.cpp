#include <iostream>
using namespace std;

#define MAX 50000

int multiply(int x,int arr[],int arr_size);


void factorial(int n){
    int res[MAX];
    
    int res_size=1;
    
    res[0]=1;
    
    for(int x=2;x<=n;x++){
        res_size=multiply(x,res,res_size);
    }
    
    for(int n=res_size-1;n>-1;n--){
        cout<<res[n];
    }
}

int multiply(int x,int arr[],int arr_size){
    int carry =0;
    for(int i=0;i<arr_size;i++){
        int product = arr[i]*x + carry;
        arr[i] = product % 10;
        carry = product/10;
        
    }
    
    while(carry){
        arr[arr_size] = carry%10;
        carry = carry/10;
        arr_size++;
    }
    
    return arr_size;
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int input;
	    cin>>input;
        factorial(input);
	    cout<<endl;
	}

	return 0;
}