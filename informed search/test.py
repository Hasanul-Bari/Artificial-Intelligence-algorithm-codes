import heapdict

thisdict = heapdict.heapdict()

thisdict[1]=5
thisdict[2]=1
thisdict[4]=3
print(thisdict[1])
print(list(thisdict.items()))

#thisdict[1]=(3,2)
x=thisdict.popitem()
print(x)
print(list(thisdict.items()))
#print(thisdict[3])