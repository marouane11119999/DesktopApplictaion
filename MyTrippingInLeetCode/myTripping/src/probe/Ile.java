package probe;

public class Ile {
    private int value;
    private Ile next;

    Ile(int value,Ile next){
        this.value=value;
        this.next=next;
    }

    Ile(int value){
        this.value=value;
    }



    int getValue(){
        return this.value;
    }

    Ile getNext(){
        return this.next;
    }

}
