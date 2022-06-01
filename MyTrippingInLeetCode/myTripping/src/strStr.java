public class strStr {
    public static int strStr(String haystack, String needle) {
        if (haystack==null || needle==null) return 0;
        if (haystack.equals(needle)) {
            return 0;
        }
        else {
            for (int i=0;i<haystack.length();i++){
                if (haystack.charAt(i)==needle.charAt(0)){
                    String str=haystack.substring(i,i+needle.length());
                    if (str.equals(needle)) return i;
                }
            }
            return -1;
        }
    }




    public static void main(String[] args) {
        String h="a",n="";
    }
}
