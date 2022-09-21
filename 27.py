# 移除重复元素的python解法，leetcode网站测试通过
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        size = len(nums)
        i = 0
        while i < size:
            if nums[i] == val:
                j = i + 1
                while j < size:
                    nums[j-1] = nums[j]
                    j += 1
                i -= 1
                size -= 1
            i += 1
        return size


# 注意：使用range的for循环还是有点问题的，这样无法控制i的索引位置
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        size = len(nums)
        list_i = list(range(size))
        for i in list_i:
            if nums[i] == val:
                j = i + 1
                list_j = list(range(j, size))
                for j in list_j:
                    nums[j-1] = nums[j]
                i -= 1   # 这里就出问题了
                size -= 1
                list_i.pop()
        return size        


if __name__ == '__main__':
    my_list = list([1, 3, 5, 3, 2, 3, 4])
    print(my_list)
    sol = Solution()
    size = sol.removeElement(my_list, 3)
    print("size = ", size)


