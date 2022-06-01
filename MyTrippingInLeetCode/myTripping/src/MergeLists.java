
public class MergeLists {
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
      if (list1==null && list2!=null) return list2;
      else  if (list2==null && list1!=null) return list1;
      else  if (list2==null && list1==null) return null;
      else {
          ListNode temp=list1;
          while (temp.next!=null){
              temp=temp.next;
          }
          temp.next=list2;

          //sorting
          int tm;
          ListNode current,next;
          current=list1;
          while (current!=null){
              next=current.next;
              while (next!=null){
                  if (next.val<=current.val){
                      tm=next.val;
                      next.val= current.val;
                      current.val=tm;
                  }
                  next=next.next;
              }
              current=current.next;

          }
          return list1;
      }
    }

    /*public static void main(String[] args) {
        ListNode n3= new ListNode(3);
        ListNode n2= new ListNode(2,n3);
        ListNode list1= new ListNode(1,n2);

        ListNode f3= new ListNode(5);
        ListNode f2= new ListNode(4,f3);
        ListNode list2= new ListNode(6,f2);

        ListNode result=mergeTwoLists(list1,list2);
        ListNode.traversal(result);


    }*/
}
