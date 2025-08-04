class Nodes():
    def __init__(self,x):
        self.data=x
        self.llink=None
        self.rlink=None

class BTree():
    def __init__(self):
        self.root=None
    def insert(self,root,a):
        new=Nodes(a)
        cur=root
        par=root
        if(root==None):
           print("Creating Root node")
           self.root=new
           return new      
        else:
            while(cur!=None):
                par=cur
                if(a>cur.data):
                    cur=cur.rlink
                elif(a<cur.data):
                    cur=cur.llink
                else:
                    print("Duplicate key")
                    return root
            if(par.data>a):
                par.llink=new
            else:
                par.rlink=new
        return root
    def in_order(self,root):
        if(root!=None):
            self.in_order(root.llink)
            print(root.data,end=" ")
            self.in_order(root.rlink)
b=BTree()
print("Enter 1 for inserting,2 for inorder")
choice=int(input())
root=None
while choice>0 and choice<3:
    if choice==1:
        value=int(input("Enter value"))
        root=b.insert(root,value)
    elif choice==2:
        b.in_order(root)
        print()
    else:
        break
    choice=int(input())





                