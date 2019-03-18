
def bubble(li):
    """ 使用冒泡对数组进行排序
    Param:
        li: 输入的数组
    Return:
        li：排序后的数组
    """
    # 这里填上你的程序
    for i in range(len(li)-1):
        for j in range(len(li)-1):
            if li[j] > li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
    return li



# 常用写法，注意没有缩进
li = [10,9,8,7,6,5,4]
li = bubble(li)
print(li)

# 还有一种比较正规的写法，如下
if __name__ == "__main__":
    li = [10,9,8,7,6,5,4]
    li = bubble(li)
    print(li)

    