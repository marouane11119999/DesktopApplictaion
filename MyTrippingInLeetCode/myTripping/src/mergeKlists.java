public class mergeKlists {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null) return null;
        else{
            ListNode list=null;
            int n=0;
            while (n<lists.length){
                list=MergeLists.mergeTwoLists(lists[n],lists[n+1]);
                n++;
            }
            return list;
        }

    }


}
