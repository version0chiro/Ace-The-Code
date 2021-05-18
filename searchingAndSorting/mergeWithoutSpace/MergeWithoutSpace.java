// Java program program to merge two 
// sorted arrays with O(1) extra space.

import java.util.Arrays;

class Test
{
	static int arr1[] = new int[]{1, 5, 9, 10, 15, 20};
	static int arr2[] = new int[]{2, 3, 8, 13};
	
	static void merge(int m, int n)
	{
		// Iterate through all elements of ar2[] starting from
		// the last element
		for (int i=n-1; i>=0; i--)
		{
			/* Find the smallest element greater than ar2[i]. Move all
			elements one position ahead till the smallest greater
			element is not found */
			int j, last = arr1[m-1];
			for (j=m-2; j >= 0 && arr1[j] > arr2[i]; j--)
				arr1[j+1] = arr1[j];
	
			// If there was a greater element
			if (j != m-2 || last > arr2[i])
			{
				arr1[j+1] = arr2[i];
				arr2[i] = last;
			}
		}
	}
	
	// Driver method to test the above function
	public static void main(String[] args) 
	{
		merge(arr1.length,arr2.length);
		System.out.print("After Merging nFirst Array: ");
		System.out.println(Arrays.toString(arr1));
		System.out.print("Second Array: ");
		System.out.println(Arrays.toString(arr2));
	}
}
