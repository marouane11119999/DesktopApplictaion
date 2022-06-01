import java.lang.reflect.Array;
import java.util.*;


public class RmvElement {
    public static int removeElement(int[] nums, int val) {
        int c=0;
        for (int i=0;i<nums.length;i++) {
            if (nums[i] != val) {
               nums[c++]=nums[i];
            }
        }
        int N=nums.length;
        nums=Arrays.copyOfRange(nums,0,c);
        for (int i=0;i<nums.length;i++){
            System.out.println(nums[i]);
        }
        return N-c;
    }



}
