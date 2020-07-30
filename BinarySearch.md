

[Notes copied from the Reference](https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie)
整理了一些容易忘记，需要注意的点

# 二分搜寻 Binary Search

- 英文的index -> 索引

- 一般二分搜寻问题就是在一个**排好序**的数组里找某个值 -> 从中间开始找 -> 比大小判断去左右哪边，更新left right(区间的边界值)

- 技巧：

  + 不写else 而是 else if 把所有情况写清楚
  
  + 防止溢出问题: mid = left + (fight-left)/2 会比 (left+right)/2 要更好些，防止left和right都太大，相加的话直接溢出
  
  + while 之后在返回之前处理一下right和left变量越界情况
  
## 问题一: 二分法搜寻一个数

- 找到了就返回这个值在数组中的索引，否则-1
  
- 当每次进行搜索的区间 [left,right] 是闭合区间 -> 就得注意:

  + right=nums.length-1 且 while(left<=right) 这里是<= 且 left = mid + 1 和 right = mid - 1
  
  + 上条说的while的条件while <= 是因为 当闭合区间[left,right]为空区间得是 left>right 才不会找漏
  
  + 下面的例子会有出现while < 那在left=right的时候就退出了 漏掉了一个 得判断 nums[left]是不是target再返回left 或 -1

## 问题二: 找target的target的左侧边界

这个问题存在于，当数组里有重复的**target** 比如 nums=[1,2,2,2,3] 二分法能很快找到**target**且返回index 2，但是如果我想要知道**target**的*左边边界* 即*return 1*，就可以知道在这个数组里，比**target**小的数，一共有多少个。如果我想要知道**target***右边边界* 即*return 3*，就可以知道在这个数组里，小于等于**target**的数有多少个。

那当target比所有的数都小，应该返回0，相反target比所有的数都大，应该返回 nums.length --> 所以left变量的值会有可能是[0,nums.length]，那么当数组里没有target这个数我们需要返回-1而不是0或nums.length的话，就得在return 前做一些处理。
  
```c++
int left_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意 对应

    while (left < right) { // 注意 对应
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;            //找到target不是返回索引而是标记为right 去找最左边的边界
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意 这里没有mid-1因为是 [) 右边是开区间
        }
    }
    //不是直接return left;

    // target 比所有数都大
    if (left == nums.length) return -1;
    // 类似之前算法的处理方式
    return nums[left] == target ? left : -1;
    }

```
  
   + 当每次进行搜索的区间是 [left,right) 是闭合开区间 -> while(left<right) 没有= 且 left = mid + 1 和 right = mid -> 解决相邻两个数找漏右边的问题 (其实也可以用闭合区间 改一改 结合两种 代码如下)
   
```c++
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
```
  
## 问题三: 找target的target的右侧边界

跟上面例子差不多

- 区别:

```c++
if (nums[mid] == target) {
    left = mid + 1;
```
要返回的话有点差别
```c++
while (left < right) {
    // ...
}
if (left == 0) return -1;
return nums[left-1] == target ? (left-1) : -1;
```

最后的处理无论如何left=mid+1都变多了1。




