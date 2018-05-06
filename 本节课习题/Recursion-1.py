# -*- coding: cp936 -*-
def factorial(n):
    if n == 1: return 1
    return n * factorial(n - 1)

def fibonacci(n):
    if n == 0:return 0
    if n <= 2: return 1
    return fibonacci(n-1)+fibonacci(n-2)

def bunnyEars(bunnies):
    if bunnies == 0:return 0
    return 2+bunnyEars(bunnies-1)

def bunnyEars2(bunnies):
    if bunnies == 1: return 3
    return (3 if bunnies%2 != 0 else 2)+bunnyEars2(bunnies-1)

def triangle(rows):
    if rows == 0:return 0
    if rows == 1:return 1
    return rows+triangle(rows-1)
    

def sumDigits(n):
    if n < 10:return n
    return sumDigits(n // 10) + n % 10

def count7(n):
    if n < 10:return 1 if n == 7 else 0
    return count7(n // 10) + (1 if n % 10 == 7 else 0)

'''def count8(n, count = 1):
    if n < 10:return count if n == 8 else 0
    n % 10 == 8:
    return count8(n // 10, (2*count if n %100//10 == 8 else count)) + (count if n % 10 == 8 else 0)
def count8(n, count = 1):
    if n < 10: return count if n == 8 else 0
    return count8(n // 10, count8(n%10, (2*count if )))'''
def count8(n, count = 1):
    if n < 10: return count if n == 8 else 0
    if n % 10 == 8:
        return count8(n // 10, 2*count)+count
    else:
        return count8(n // 10, 1)

def powerN(base, n):
    if n == 1:return base 
    return powerN(base, n-1)*base

def countX(str):
    if len(str) == 1:return 1 if str == 'x' else 0
    return countX(str[0])+countX(str[1:])

def countHi(str):
    if len(str) < 2:return 0
    if str[:2] == 'hi':
        return countHi(str[2:])+1
    else:return countHi(str[1:])
        
def changeXY(str):
    if len(str)== 1:return 'y' if str == 'x' else str
    return changeXY(str[0])+changeXY(str[1:])

def changePi(str):
    if len(str) < 2:return str
    if str == 'pi':return '3.14'
    if str[:2] == 'pi':return '3.14'+changePi(str[2:])
    return str[0]+changePi(str[1:])

def noX(str):
    if len(str) == 1:return str if str != 'x' else ''
    return noX(str[0])+noX(str[1:])

def array6(nums, index = None):
    if index == None:
        if len(nums) == 1:
            return True if nums[0] == 6 else False
        else:
            return array6([nums[0]]) or array6(nums[1:])
    else:
        if index == 0:#截取完成
            return array6(nums)
        else:
            return array6(nums[1:], index-1)

def array11(nums, index = None):
    if index == None:
        if len(nums) == 1:
            return 1 if nums[0] == 11 else 0
        else:
            return array11([nums[0]])+array11(nums[1:])
    else:
        if index == 0:
            return array11(nums)
        else:
            return array11(nums[1:], index-1)

def array220(nums, index = None):
    if index == None:
        if len(nums) < 2:return False
        if nums[0] * 10 == nums[1]:return True
        else: return False or array220(nums[1:])
    else:
        if index == 0:
            return array220(nums)
        else:
            return array220(nums[1:], index-1)
def allStar(str):
    if len(str) == 1:return str
    return str[0]+'*'+allStar(str[1:])

def pairStar(str):
    if len(str) == 1:return str
    return str[0] +('*' if str[0] == str[1] else '') + pairStar(str[1:])

def endX(str):
    if len(str) == 1:return str
    if str[0] == 'x':return endX(str[1:])+'x'
    else:return str[0] + endX(str[1:])

'''def countPairs(str, p = {}, l = 0):
    if l == 0:p = {}
    if len(str) == 0:#no enough space to form a pair
        return 0
    if str[0] in p:
        
        del p[str[0]]
        return countPairs(str[1:], p, l+1)+1
    else:
        
        p[str[0]] = None
        return countPairs(str[1:], p, l+1)'''
def countPairs(str):
    if len(str) <3:
        return 0
    return countPairs(str[1:])+(1 if str[0] == str[2] else 0)
    
def countAbc(str):
    if len(str) < 3:
        return 0
    if str[:3] == 'abc' or str[:3] == 'aba':
        return countAbc(str[1:])+1
    else:
        return countAbc(str[1:])
    
def count11(str):
    if len(str) < 2:
        return 0
    if str[:2] == '11':
        return count11(str[2:])+1
    else:
        return count11(str[1:])

def stringClean(str):
    
    if len(str) < 2:
        return str
    if str[0] == str[1]:
        
        return stringClean(str[1:])
    else:
        return str[0] + stringClean(str[1:])

def countHi2(str):#not done
    if (str != 'hi' and len(str) < 3) or str == 'xhi':
        return 0
    if str[:2] == 'hi':
        return countHi2(str[2:])+1
    elif str[:3] == 'xhi':
        return countHi2(str[3:])
    else:return countHi2(str[1:])

def parenBit(str):
    if str[0] != '(':
        return parenBit(str[1:])
    if str[-1] != ')':
        return parenBit(str[:-1])
    return str
def nestParen(str):
    if len(str) == 0:return True
    if str[0] != '(' or str[-1] != ')':
        return False
    return (str[0] == '(' and str[-1] == ')') and nestParen(str[1:-1])

def strCount(str, sub):
    if len(str) < len(sub):
        return 0
    if str[:len(sub)] == sub:
        return strCount(str[len(sub):], sub)+1
    else:
        return strCount(str[1:], sub)
    
def strCopies(str, sub, n = None):
    if len(str) < len(sub):
        return 0
    if str[:len(sub)] == sub:
        return (strCopies(str[len(sub):], sub)+1 >= n)
    else:
        return (strCopies(str[1:], sub) >= n)

def strDist(str, sub):
    if len(str) < len(sub)*2:#小于两倍长度，说明long中起始的两个short一定重叠
        return 0

    if not str[:len(sub)] == sub:
        return strDist(str[1:], sub)
    if not str[len(str) - len(sub):] == sub:
        return strDist(str[:-1], sub)
    return len(str)
