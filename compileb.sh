bison -y -d bisonas.y
flex flexxer.l
gcc -c y.tab.c lex.yy.c
gcc y.tab.o lex.yy.o -o Compiler