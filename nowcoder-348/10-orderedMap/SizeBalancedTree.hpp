/**
 * SB树：任何叔叔节点的size，不能小于侄子节点的size
 * 1. 在调整LL、LR、RL、RR型违规的时候，递归调整
 * 2。可以在删除节点的时候不作调整，只在加节点的时候调整
*/

#include "SelfBalancedBinarySearchTree.hpp"

template<typename K, typename V>
class SizeBalancedTree : public SelfBalancedBinarySearchTree<K, V> {
private:
public:

};