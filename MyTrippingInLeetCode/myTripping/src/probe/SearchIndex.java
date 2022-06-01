package probe;

public class SearchIndex {
    public static int searchInsert(int[] nums, int target) {
        int low=0;
        int high=nums.length-1;
        if (nums==null) return -1;
            else{

                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    if (nums[mid] == target)
                        return mid;

                    if (nums[mid] < target)
                        low = mid + 1;

                    else
                        high = mid - 1;
                }
            }
            return low ;
    }
    public static void main(String[] args) {
        int[] nums = {1,3,5,6};
        int target = 5;
        System.out.println(searchInsert(nums,5));
    }
}
