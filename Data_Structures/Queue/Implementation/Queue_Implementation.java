import java.util.*;

class Queue_Implementation {

    Scanner sc=new Scanner(System.in);
    int items[];
    int i, front = 0, rear = 0, noOfItems, item, count = 0;

    void getdata() {
        try {
            System.out.println("Enter the Limit :");
            noOfItems = sc.nextInt();
            items = new int[noOfItems];
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    void enqueue() {
        try {
            if (count < noOfItems) {
                System.out.println("Enter Queue Element :");
                item = sc.nextInt();
                items[rear] = item;
                rear++;
                count++;
            } else {
                System.out.println("Queue Is Full");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    void dequeue() {
        if (count != 0) {
            System.out.println("Deleted Item :" + items[front]);
            front++;
            count--;
        } else {
            System.out.println("Queue IS Empty");
        }
        if (rear == noOfItems) {
            rear = 0;
        }
    }

    void display() {
        int m = 0;
        if (count == 0) {
            System.out.println("Queue IS Empty");
        } else {
            for (i = front; m < count; i++, m++) {
                System.out.print(" " + items[i]);
            }
        }
    }




    public static void main(String arg[]) {
        Scanner sc=new Scanner(System.in);
        int choice;
        Queue_Implementation queue = new Queue_Implementation();
        queue.getdata();
        System.out.println("Queue\n\n");
        try {
            do {
                System.out.println("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
                System.out.println("Enter the Choice : ");
                choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        queue.enqueue();
                        break;
                    case 2:
                        queue.dequeue();
                        break;
                    case 3:
                        queue.display();
                        break;
                }
            } while (choice != 4);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    
}
}