import os
import sys
from Queue import *
q = Queue()

def process_single_dir(dir, fout):
	q.put(dir)
	while (q.empty() == False):	
		popitem = q.get()
		if(os.path.isdir(popitem)):
			keystr = popitem
			path, key = keystr.split(':\\')
			fout.write(key+' : ')
			print popitem
			x = os.listdir(popitem)			
			for files in x:
				q.put(popitem+'\\'+files)				
				fout.write(files+',')
			fout.seek(-1, 1)
			fout.write('\n')

def process_all_dirs(ipfile, opfile):
	fin = open(ipfile, 'r')
	fout = open(opfile, 'w+')
	for line in fin:
		line = line.strip();
		process_single_dir(line, fout)
	fin.close()
	fout.close()

process_all_dirs('sample.txt', 'sampleOut.yml')