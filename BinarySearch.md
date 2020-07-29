

[Reference](https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie)

# 二分搜寻 Binary Search

- 英文的index -> 索引

- 一般二分搜寻问题就是在一个**排好序**的数组里找某个值 -> 从中间开始找 -> 比大小判断去左右哪边，更新left right(区间的边界值)

- 技巧：

  + 不写else 而是 else if 把所有情况写清楚
  
  + 防止溢出问题: mid = left + (fight-left)/2 会比 (left+right)/2 要更好些，防止left和right都太大，相加的话直接溢出
  
  + 问题：当找到了就返回这个值在数组中的索引，否则-1
  
      + 当每次进行搜索的区间 [left,right] 是闭合区间 -> 就得注意while(left<=right) 这里是<= (有=) 且 left = mid + 1 和 right = mid - 1
  
  + 问题：可以知道在这个数组里 比 这个**要搜寻的这个值** 小的数 一共有多少个
  
      + 当每次进行搜索的区间是 [left,right) 是闭合开区间 -> while(left<right) 没有= 且 left = mid + 1 和 right = mid -> 解决相邻两个数找漏右边的问题
  
      + 最后返回 先判断一下 left 是不是target这个值 去看返回 left 还是-1
      
 - 最后代码：
 
 int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}

