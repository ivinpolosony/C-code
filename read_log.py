import sys

file_handle = open("Log.log")
#print file_handle.read()
a = []
for lines in file_handle.read().split("Time"):
    a.append(lines)
    #print lines
print len(a)
print a[1]
print a[2]
print a[3]
print a[4]
print a[5]
print a[6]

#print a[8]
