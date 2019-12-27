

all:
	antlr -gt example1.g
	dlg parser.dlg scan.c
	g++ -o example1 example1.c scan.c err.c -I/usr/local/include/pccts -ggdb


