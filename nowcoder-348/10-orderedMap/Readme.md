有序表(TreeMap)是一个逻辑意义上的结构：
- 可以有get, set, remove等基础方法
- key是排过序的
- 上述所有操作的时间复杂度都是O(logn)的

其他的，类似于红黑树、Size Balance Tree、跳表等都是一种具体实现






BinarySearchTree -> SelfBalancedBinarySearchTree -> AVLTree                     |
                                                |                               |      => TreeMap
                                                |-> SizeBalancedTree            |
                                                                                |
                                                                                |
SkipListMap-------------------------------------------------------------------->|