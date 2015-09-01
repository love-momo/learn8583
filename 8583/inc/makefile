objPath=./obj
srcPath=./src
incPath=./inc
binPath=./bin

all=test

${binPath}/test :${objPath}/test.o 
	gcc -o -I${incPath} ${binPath}/test ${objPath}/test.o
${objPath}/test.o:${srcPath}/test.c
	gcc -o -I${incPath} ${srcPath}/test.c ${objPath}/test.o
clean :
	rm -f $(objPath)/*.o
