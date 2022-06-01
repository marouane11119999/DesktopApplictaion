package probe;

public class RemoveDuplicates {
    public static int removeDuplicates(int[] nums) {

        int count = 0;

        for (int i = 0; i < nums.length; i++) {

            if (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                continue;
            }

            nums[count] = nums[i];
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        int[] nums={1,2,2,2,3,3,3,4,5};
        //System.out.println(removeDuplicates(nums));
        removeDuplicates(nums);
        for (int x:nums) {
            System.out.println(x);
        }

    }
}
