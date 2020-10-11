import java.util.Scanner;

class JumpSearch
{
    static int find_element(int[] array, int element) {
        int jump_step,prev = 0;
        int n = array.length;
        /* Create a suitable jump step */
        jump_step = (int) Math.floor(Math.sqrt(n));
        
        /* Finding block in which element lies, if it is present */
        while(array[prev] < element)
        {
           if(array[jump_step] > element || jump_step >= n)
           {
                break;
           }
           else
           {
                prev = jump_step;
                jump_step += Math.floor(Math.sqrt(n));
           }
        }
        
        /*Finding the element in the identified block */
        while(array[prev] < element)
        {
            prev++;
        }
        
        if(array[prev] == element)
        {
            return (prev + 1);
        }
        else
        {
            return -1;
        }
    }
    
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
		int i,element,result;
        System.out.println("Enter the number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements of array: ");
        int[] array = new int[n];
        for(i=0;i<n;i++)
        {
            array[i] = sc.nextInt();
        }
        System.out.println("\nEnter the element you want to search: ");
        element = sc.nextInt();
        sc.close();
        result = find_element(array, element);
        if(result==-1)
        {
            System.out.println("Element is not found in the array !\n");
        }
        else
        {
            System.out.println("Element " + element + " is present at position " + result);
        }
    }
}
