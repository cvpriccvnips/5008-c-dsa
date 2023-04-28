int findKthLargest(int* nums, int numsSize, int k) {
    int pivot = nums[0];
    int* left = malloc(sizeof(int) * numsSize);
    int* equal = malloc(sizeof(int) * numsSize);
    int* right = malloc(sizeof(int) * numsSize);
    int leftSize = 0;
    int equalSize = 0;
    int rightSize = 0;
    // Partition elements based on their relation to pivot
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            left[leftSize] = nums[i];
            leftSize++;
        } else if (nums[i] == pivot) {
            equal[equalSize] = nums[i];
            equalSize++;
        } else {
            right[rightSize] = nums[i];
            rightSize++;
        }
    }
    // If there are k or more elements greater than pivot, the kth largest element is in the right list
    if (rightSize >= k) { 
        return findKthLargest(right, rightSize, k);
    // 如果在所有大于或等于 pivot 的元素中，数量大于或等于 k 个，
    // 则说明第 k 大的元素就是 pivot，也就是 equal 列表中的第一个元素。因为 equal 列表中的元素都等于 pivot
    } else if (rightSize + equalSize >= k) { 
        return equal[0];
    // 否则，需要在 left 列表中查找第 (k - len(right) - len(equal)) 大的元素。
    } else { 
        return findKthLargest(left, leftSize, k - rightSize - equalSize);
    }
}