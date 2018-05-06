# -*- coding: cp936 -*-
'''def groupSum(start = None, nums, target, p = []):
    if start == None:
        if p != []:
            
            if p[-1] != 0:
                p[-1] = 1
                return groupSum(None, nums, target, p)
    else:
        if start == 0:
            returngroupSum(None, nums, target, len(nums) * [0])
        else:
            return groupSum(start - 1, nums[1:], target)'''


'''def groupSum(start, nums, target, c1 = None, c2 = None):
    if start == None:
        if c1 == c2 == 0:#完成一次子循环
            if len(nums) == 1:
                return False#最后的子循环失败了，所有的组合都不满足
            else:
                #新一轮尝试
                return groupSum(None, nums[1:], target, c1 = 0, c2 = len(nums) - 1)
        else:#子循环未完成
            print c2-c1, nums[c1:c2]
            if sum(nums[c1:c2]) == target:#找到了！
                return True
            else:
                return groupSum(None, nums, target, c1, c2 - 1)
    else:
        if start == 0:
            return groupSum(None, nums, target, 0, len(nums))
        else:
            return groupSum(start - 1, nums[1:], target)'''
        
def groupSum(start, nums, target, ptrs = [], lp = None):
    if start == None:
        #print ptrs, lp
        if 0 not in ptrs[:lp]:#完成一次子循环
            if 0 not in ptrs:
                return False#最后的子循环失败了，所有的组合都不满足
            else:
                #新一轮尝试
                print 'err', ptrs, nums, lp
                ptrs[-1] = nums[-1]
                return groupSum(None, nums[1:], target, ptrs[:], lp = len(nums) - 1)
        else:#子循环未完成
            print 'e', ptrs, nums, lp
            if sum(ptrs) == target:#找到了！
                return True
            else:
                print 'e2', ptrs, nums, lp
                ptrs[lp - 1] = nums[lp - 1]
                ptrs[lp] = 0
                print 'e2', ptrs, nums, lp
                return groupSum(None, nums, target, ptrs[:], lp - 1)
    else:
        if start == 0:
            if target in nums or (target == 0 and (nums == [] or 0 in nums)):return True
            return groupSum(None, nums, target, len(nums)*[0], lp = len(nums)-1)
        else:
            return groupSum(start - 1, nums[1:], target)
