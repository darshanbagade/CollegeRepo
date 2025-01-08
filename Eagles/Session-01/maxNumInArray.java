public class maxNumInArray{
    public static void main(String[] args) {
        int[] nums = { 11, 5, 0,3, 6 };
        int max = nums[0];

        for(int i= 0 ;i<nums.length ; i++ ){
            if(nums[i]>max){
                max=nums[i];
            }
        }

        System.out.println("Max element : " + max);
    }
}