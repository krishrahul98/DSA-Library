public class Node {
    public int number;
    public Node next;

    public Node(int number){
        this.number = number;
        this.next = null;
    }
    public void print_chain(){
        System.out.print("( " + this.number + " )");
        Node temp = this.next;
        while(temp!=null){
            System.out.print("( " + temp.number + " )");
            temp = temp.next;
        }
    }
}
