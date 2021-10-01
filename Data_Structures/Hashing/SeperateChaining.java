import java.util.Scanner;

class SeperateChaining {

    public static void main(String[] args) {
        final int SIZE = 10;
        Scanner scn = new Scanner(System.in);

        Node[] hash_table = new Node[SIZE];
        for(int i=0; i<SIZE; i++){
            hash_table[i] = null;
        }
        // Used to clear the screen
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
        while(true){
            for(int i=0; i<SIZE; i++){
                Node current = hash_table[i];
                System.out.print("[ " + i + " ]--> ");
                if(current!=null){
                    current.print_chain();
                } 
                System.out.println();
            }

            System.out.print("Enter new node : ");
            String given = scn.nextLine();
            if("exit".equals(given)) break;
            int input = Integer.parseInt(given);
            Node newNode = new Node(input);
            if(hash_table[input%10] == null){
                hash_table[input%10] = newNode;
            } 
            else{
                Node last = hash_table[input%10];
                while(last.next != null) {
                    last = last.next;
                }
                last.next = newNode;
            }
        }
        scn.close();
    }
}
