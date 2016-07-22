# Leetcode题解 #
[TOC]
## 目的 ##
刷一遍leetcoude题目，增加算法了解

##23.Merge K Sorted Lists
 可以利用二分法、循环调用MergeTwoLists、将其放入prority_queue中，利用最大堆进行求解

##148.Sort List
- 利用快慢指针找到链表的中间值
- 采用归并排序
- 最后利用sortTwoList合并起来

##147.InsertionSortList
- 新建一个辅助接点，再利用插入法一个一个添加新元素进去

``` C++
while(pre->next!= nullptr && pre->next->val <= cur->val){
    pre= pre->next;
}
cur->next = pre->next; //将cur插入pre->next之前
pre->next = cur;//将cur插入pre之后
cur = pNext;//递增进入下一个
```

##22.Generate Patenthese

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

##219. Contains Duplicate I
对于寻找重复元素记得可以用map 来记录元素的索引！
``` C
map.find(nums[i] != map.end())
```