/* Java code for searching an element in a sorted rotated array

Author: AnkitaM84
video link to understand the solution: https://www.youtube.com/watch?v=QdVrY3stDD4
*/

package hacktober;

import java.util.Scanner;

public class search_in_sorted_rotated_array {


  /* return the index at which element is found.
     returns -1 if element not found */ 
	public static int search(int[] nums, int target) {
        if(nums == null || nums.length == 0) {
            return -1;
        }
        int si = 0, ei = nums.length-1;
        while(si < ei) {
            int mid = (si+ei)/2;
            if(nums[mid] > nums[ei]) {
                si = mid+1;
            } else {
                ei = mid;
            }
        }
        int temp = si;
        si = 0;
        ei = nums.length-1;
        if(target >= nums[temp] && target <= nums[ei]) {
            si = temp;
        } else {
            ei = temp;
        }
        int ans = -1;
        while(si <= ei) {
            int mid = (si+ei)/2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            } else if(nums[mid] < target) {
                si = mid+1;
            } else {
                ei = mid-1;
            }
        }
        return ans;
    }
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter size: ");
		int n = s.nextInt();
		System.out.print("Enter sorted rotated array: ");
		int arr[] = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		System.out.print("enter element to be searched: ");
		int k = s.nextInt();
		System.out.println("Element found at index: " + search(arr, k));
		
	}

}
