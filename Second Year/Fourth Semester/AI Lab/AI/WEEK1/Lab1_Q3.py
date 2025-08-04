import math
list1=[2,1,10,9,6]
list2=[6,13,27,20,9]
list3=[]
def eucform():
    sum=0
    for i in range (len(list1)):
      dist=math.pow(list1[i]-list2[i],2)
      sum+=dist
      dist1=math.sqrt(dist)
      list3.append(dist1)
    return math.sqrt(sum)
def bubblesort():
    for n in range(len(list3) - 1, 0, -1):
        
        
        swapped = False  

        
        for i in range(n):
            if list3[i] > list3[i + 1]:
              
                list3[i], list3[i + 1] = list3[i + 1], list3[i]
                
                swapped = True
        
        
        if not swapped:
            break
print(eucform())
bubblesort()
print(list3)    
    