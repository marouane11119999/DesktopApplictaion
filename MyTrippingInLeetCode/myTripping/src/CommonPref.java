import java.util.*;

public class CommonPref {
    public static String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        for (String st:strs
             ) {
            if (st.length()==0) return "";
        }
        String minStr=strs[0];
        for(int i=1;i<strs.length;i++){
            if(minStr.length()>strs[i].length()) minStr=strs[i];
        }
        //System.out.println(minStr.length());
        char chartemp;
        String result="";
        for (int j=0;j<minStr.length();j++){
            chartemp=strs[0].charAt(j);
            for (String st: strs
                 ) {
                    if (chartemp != st.charAt(j)) return result;
            }
            result+=chartemp;
       }
        return result;

    }


}
