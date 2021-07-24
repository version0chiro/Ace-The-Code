class Node:
    def __init__(self, l, r, val, left, right):
        self.l = l
        self.r = r
        self.val = val
        self.left = left
        self.right = right
        
class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        if not nums:
            self.root = None
        else:
            self.root = self.construct(0, len(nums)-1)
    
    def construct(self, l, r):
        if l == r:
            return Node(l, r, self.nums[l], None, None)
        mid = (l+r)//2
        left = self.construct(l, mid)
        right = self.construct(mid+1, r)
        return Node(l, r, left.val+right.val, left, right)
            
    def update(self, i: int, val: int) -> None:
        self.stUpdate(self.root, i, val)
        
    def stUpdate(self, node, i, val):
        if node.l == node.r == i:
            node.val = val
            return
        mid = (node.l+node.r)//2
        if i <= mid:
            self.stUpdate(node.left, i, val)
        else:
            self.stUpdate(node.right, i, val)
        node.val = node.left.val + node.right.val
                        
    def sumRange(self, i: int, j: int) -> int:
        return self.stQuery(self.root, i, j)
        
    def stQuery(self, node, i, j):
        if node.l == i and node.r == j:
            return node.val
        mid = (node.l+node.r)//2
        if j <= mid:
            return self.stQuery(node.left, i, j)
        elif i > mid:
            return self.stQuery(node.right, i, j)
        else:
            return self.stQuery(node.left, i, mid) + self.stQuery(node.right, mid+1, j)