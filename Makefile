all : CFS CFSnice
CFS: CFS.c
	gcc -o CFS CFS.c
	
CFSnice: CFSnice.c
	gcc -o CFSnice CFSnice.c

