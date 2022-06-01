public class Binary {
    public static String addBinary(String a, String b) {
        StringBuilder s1=new StringBuilder(a);
        StringBuilder s2=new StringBuilder(b);
        int l1=0,l2=0;
        char carry='0';
        StringBuilder result=new StringBuilder();
        String reverseda=s1.reverse().toString();
        String reversedb=s2.reverse().toString();
        while (l1<reverseda.length() || l2<reversedb.length()){
            if (reverseda.charAt(l1)>reversedb.charAt(l2) && carry=='0') result.append('1');
            else if (reverseda.charAt(l1)>reversedb.charAt(l2) && carry=='1'){
                result.append('0'); carry='1';
            }
            if (reverseda.charAt(l1)<reversedb.charAt(l2) && carry=='0') result.append('1');
            else if (reverseda.charAt(l1)<reversedb.charAt(l2) && carry=='1'){
                result.append('0');
                carry='1';
            }
            if (reverseda.charAt(l1)==reversedb.charAt(l2) &&reversedb.charAt(l2)=='0' && carry=='0'){
                result.append('0');
                carry='0';
            }
            else if (reverseda.charAt(l1)==reversedb.charAt(l2) &&reversedb.charAt(l2)=='1' && carry=='0'){
                result.append('0');
                carry='1';
            }
        }
    }


    public static void main(String[] args) {
        System.out.println('1'>'0');
    }
}
