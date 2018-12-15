import os
from Queue import *
q = Queue()
rootpath = 'D:\projects\scrapers'
q.put(rootpath)
level = 0
print 'rootpath: ', rootpath
while (q.empty() == False):
	if(rootpath is not None):
		x = os.listdir(rootpath)
		popitem = q.get()
		for files in x:
			q.put(rootpath+'\\'+files)	
	item = q.get()
	if (os.path.isdir(item)):	
		rootpath = item
		print rootpath
	else:
		rootpath = None
		print item