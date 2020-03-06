// Number: 35
// Name: Search Insert Position
// Tags: array, binary search

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle = (left + right) / 2;
    while (left <= right) {
    if (nums[middle] == target) {
      return middle;
    }
    if (nums[middle] < target) {
      if (middle != nums.size() - 1) {
        if (nums[middle + 1] > target) return middle + 1;
      }
      else return middle + 1;
      left = middle + 1;
    }
    else if (nums[middle] > target) {
      if (middle > 0) {
        if (nums[middle - 1] < target) return middle;
      }
      else return 0;
      right = middle - 1;
    }
    middle = (left + right) / 2;
    }
    return -1;
}
