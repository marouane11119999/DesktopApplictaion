import java.util.*;
public class Roman {

    public int romanToInt(String s) {
        Map<String,Integer> Defined=new LinkedHashMap<String,Integer>();
        Defined.put("I",1);
        Defined.put("V",5);
        Defined.put("X",10);
        Defined.put("L",50);
        Defined.put("C",100);
        Defined.put("D",500);
        Defined.put("M",1000);

        int converted=0,i=0;
        int  b=0,c=0;
        if (s.length()==1) converted+=Defined.get(String.valueOf(s.charAt(0)));
        for(i=0;i<s.length()-1;i++){
            if((s.charAt(i)=='I' && s.charAt(i+1)=='V') || (s.charAt(i)=='I' && s.charAt(i+1)=='X') || (s.charAt(i)=='X' && s.charAt(i+1)=='L') || (s.charAt(i)=='X' && s.charAt(i+1)=='C')
                    || (s.charAt(i)=='C' && s.charAt(i+1)=='D') || (s.charAt(i)=='C' && s.charAt(i+1)=='M')){

                converted=converted+Defined.get(String.valueOf(s.charAt(i+1)))-Defined.get(String.valueOf(s.charAt(i)));
                i++;
                b=1;
            }
            else{

                converted+=Defined.get(String.valueOf(s.charAt(i)));
                b=0;
                c=1;

            }
        }


        if((i==s.length()-1 && b==1) || (i==s.length()-1 && b==0 && c==1)) converted+=Defined.get(String.valueOf(s.charAt(s.length()-1)));



        return converted;
    }
}
