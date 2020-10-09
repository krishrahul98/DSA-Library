//stack implementation in java
import java.util.*;
class Stack_Implementation{
  private int arr[];
  private int top;
  private int capacity;

  // Creating a stack
  Stack_Implementation(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
  }

  // push elements to the top of stack
  public void push(int x) {
    if (top == capacity - 1) {
      System.out.println("Stack OverFlow");
      System.exit(1);
    }
    System.out.println("Inserting " + x);
    arr[++top] = x;
  }

  // pop elements from top of stack
  public int pop() {
    if ( top == -1 ) {
      System.out.println("STACK EMPTY");
      System.exit(1);
    }
    System.out.println("popping an element "+ arr[top]+" from stack");
    arr[top]=0;
    return arr[top--];
  }
  // display elements of stack
  public void printStack() {
    for (int i = 0; i <= top; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
  	int choice ,n,x;
  	Scanner sc=new Scanner(System.in);
  	System.out.print("Enter size of stack :");
  	n=sc.nextInt();
    Stack_Implementation stack = new Stack_Implementation(n);
    do{
    	System.out.println("____________________________________________________");
        
    	System.out.println("Enter your choice as follows:\n1. push\n2. pop\n3. exit");
    	choice=sc.nextInt();
    	switch(choice){
    		case 1:
    		     System.out.println("Enter an element :");
  	             x=sc.nextInt();
    		     stack.push(x);
    		     System.out.println("After pushing up:");
    		     stack.printStack();
    		     break;
    		case 2:
    			stack.pop();
    			System.out.println("After popping out:");
    			stack.printStack();
    			break;
        	}
       System.out.println("____________________________________________________");


    }while (choice != 3);

   
}
}