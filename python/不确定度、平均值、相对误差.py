#基本测量（数据处理）

import math

i = input("是否要进行平均值计算（回车退出，其他正常计算）：")   #用变量i来控制是否计算平均数
while i != "":
    num = eval(input("请输入计算平均值的数据个数："))
    b =0    #用b来计算数据总数，最后除以数据个数
    c =0    #用c来迭代与平均值的差的平方
    a = []
    for i in range(num):   
        a.append(eval(input("请输入要处理的数据：")))
        b += a[i]
    for i in range(num):
        c += pow(a[i]-b/num,2)
    amax=max(a)
    amin=min(a)
    t_095_num=[None,None,None,2.48,1.59,1.204,1.05,0.926,0.843,0.770,0.715] #t0.95/pow(num,2)的数据列表
    A=t_095_num[num]*pow(c/(num-1),0.5)
    B=eval(input("请输入B类不确定度："))
    
    print("average:",b/num,"A类不确定度：",A,"总不确定度为：",pow(A*A+B*B,0.5),"相对误差为：",(amax-amin)/(2*(b/num)))
    i = input("是否要进行平均值计算（回车退出，其他正常计算）：")
