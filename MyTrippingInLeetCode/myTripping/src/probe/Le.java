package probe;

public class Le {
    Ile head;

    Le(Ile head){
        this.head=head;
    }
    boolean isEmpty(){
        if (this.head==null) return true;
        else return false;
    }

    void prepend(int value){
        if (this.isEmpty()==true){
            this.head=new Ile(value);
        }
        else{
            Ile newHead=new Ile(value,this.head);
            this.head=newHead;
        }
    }

    int indexOf(int value){
        if (this.isEmpty()==true) return -1;
        else{
            Ile current=this.head;
            int x=0;
            while (current!=null){
                if (current.getValue()==value) {
                    return x;
                }
                x++;
                current=current.getNext();
            }
            return -1;
        }
    }

    public static void main(String[] args) {
        Ile n3= new Ile(3);
        Ile n2= new Ile(2,n3);
        Ile n1= new Ile(1,n2);
        Le h=new Le(n1);
        h.prepend(4);

        System.out.println(h.indexOf(3));
    }
}
