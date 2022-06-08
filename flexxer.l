%{
/*Grigoris Fekas (AEM=1045)  &&  Xrysh Metallidou (AEM=678)*/
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//#include "defines.h"
#include "myfuncts.h"


int buffer;
int code;
int line=1;
int caseof;
%}


LETTER [A-Za-z]
NUM [0-9]
IDSYMP "_"
STRH ("0")("H")
STRB ("0")("B")
ZERO "0"
ONE "1"
NONZERO [1-9]
NONZEROH [1-9A-F]
SPACE " "
HEX [0-9A-F]
BIN [0-1]

%x STRING_CASE


%%

<STRING_CASE>[\\]("n")		{yylval.string[buffer]='\n';buffer++;}
<STRING_CASE>[\\]("t")		{yylval.string[buffer]='\t';buffer++;}
<STRING_CASE>[\\]("f")		{yylval.string[buffer]='\f';buffer++;}
<STRING_CASE>[\\]("v")		{yylval.string[buffer]='\v';buffer++;}
<STRING_CASE>[\\]("b")		{yylval.string[buffer]='\b';buffer++;}
<STRING_CASE>[\\]("r")		{yylval.string[buffer]='\r';buffer++;}
<STRING_CASE>[\\][\\]		{yylval.string[buffer]='\\';buffer++;}
<STRING_CASE>[\\][\"]		{yylval.string[buffer]='\"';buffer++;}
<STRING_CASE>[\\]("\n")		{}
<STRING_CASE>("\"")		{BEGIN(INITIAL); return STRING;}
<STRING_CASE>[\040-\174]	{yylval.string[buffer]=yytext[0];}

("\"")	{yylval.string[0]='"';buffer=1; printf("STRING ");BEGIN(STRING_CASE);}



("|")("|") {printf("OROP ");return OROP;}

("&")("&") {printf("ANDOP ");return ANDOP;}

(("=")("="))|(("!")("=")) {printf("EQUOP ");return EQUOP;}

((">")("="))|(("<")("="))|(">")|("<") {printf("RELOP ");return RELOP;}

("+")|("-") {printf("ADDOP ");return ADDOP;}

("*")|("/")|("%") {printf("MULOP ");return MULOP;}

("!") {printf("NOTOP ");return NOTOP;}

(("+")("+"))|(("-")("-")) {printf("INCDEC ");return INCDEC;}



(("S")|("s"))(("I")|("i"))(("z")|("Z"))(("E")|("e"))(("O")|("o"))(("F")|("f")) {printf("SIZEOP ");return SIZEOP;}


("T"|"t")("Y"|"y")("P"|"p")("E"|"e")("D"|"d")("E"|"e")("F"|"f") {printf("TYPEDEF ");return TYPEDEF;}

("C"|"c")("H"|"h")("A"|"a")("R"|"r") {printf("CHAR ");return CHAR;}

("I"|"i")("N"|"n")("T"|"t") {printf("INT ");return INT;}

("F"|"f")("L"|"l")("O"|"o")("A"|"a")("T"|"t") {printf("FLOAT ");return FLOAT;}

("C"|"c")("O"|"o")("N"|"n")("S"|"s")("T"|"t") {printf("CONST ");return CONST;}

("U"|"u")("N"|"n")("I"|"i")("O"|"o")("N"|"n") {printf("UNION ");return UNION;}

("C"|"c")("L"|"l")("A"|"a")("S"|"s")("S"|"s") {printf("CLASS ");return CLASS;}

("P"|"p")("R"|"r")("I"|"i")("V"|"v")("A"|"a")("T"|"t")("E"|"e") {printf("PRIVATE ");return PRIVATE;}

("P"|"p")("R"|"r")("O"|"o")("T"|"t")("E"|"e")("C"|"c")("T"|"t")("E"|"e")("D"|"d") {printf("PROTECTED ");return PROTECTED;}

("P"|"p")("U"|"u")("B"|"b")("L"|"l")("I"|"i")("C"|"c") {printf("PUBLIC ");return PUBLIC;}

("S"|"s")("T"|"t")("A"|"a")("T"|"t")("I"|"i")("C"|"c") {printf("STATIC ");return STATIC;}

("V"|"v")("O"|"o")("I"|"i")("D"|"d") {printf("STATIC ");return VOID;}

("L"|"l")("I"|"i")("S"|"s")("T"|"t") {printf("LIST ");return LIST;}

("C"|"c")("O"|"o")("N"|"n")("T"|"t")("I"|"i")("N"|"n")("U"|"u")("E"|"e") {printf("CONTINUE ");return CONTINUE;}

("B"|"b")("R"|"r")("E"|"e")("A"|"a")("K"|"k") {printf("BREAK ");return BREAK;}

("T"|"t")("H"|"h")("I"|"i")("S"|"s") {printf("THIS ");return THIS;}

("I"|"i")("F"|"f") {printf("IF ");return IF;}

("E"|"e")("L"|"l")("S"|"s")("E"|"e") {printf("ELSE ");return ELSE;}

("W"|"w")("H"|"h")("I"|"i")("L"|"l")("E"|"e") {printf("WHILE ");return WHILE;}

("F"|"f")("O"|"o")("R"|"r") {printf("FOR ");return FOR;}

("R"|"r")("E"|"e")("T"|"t")("U"|"u")("R"|"r")("N"|"n") {printf("RETURN ");return RETURN;}

("L"|"l")("E"|"e")("N"|"n")("G"|"g")("T"|"t")("H"|"h") {printf("LENGTH ");return LENGTH;}

("N"|"n")("E"|"e")("W"|"w") {printf("NEW ");return NEW;}

("C"|"c")("I"|"i")("N"|"n") {printf("CIN ");return CIN;}

("C"|"c")("O"|"o")("U"|"u")("T"|"t") {printf("COUT ");return COUT;}

("M"|"m")("A"|"a")("I"|"i")("N"|"n") {printf("MAIN ");return MAIN;}



("(") {printf("LPAREN ");return LPAREN;}

(")") {printf("RPAREN ");return RPAREN;}

(";") {printf("SEMI ");return SEMI;}

(".") {printf("DOT ");return DOT;}

(",") {printf("COMMA ");return COMMA;}

("=") {printf("ASSIGN ");return ASSIGN;}

(":") {printf("COLON ");return COLON;}

("[") {printf("LBRACK ");return LBRACK;}

("]") {printf("RBRACK ");return RBRACK;}

("&") {printf("REFER ");return REFER;}

("{") {printf("LBRACE ");return LBRACE;}

("}") {printf("RBRACE ");return RBRACE;}

(":")(":") {printf("METH ");return METH;}

(">")(">") {printf("INP ");return INP;}

("<")("<") {printf("OUT ");return OUT;}

({NONZERO}{NUM}*)|{STRB}{ONE}{BIN}*|{STRH}{NONZEROH}{HEX}* {
							    if(yytext[1]=='B'||yytext[1]=='H'){
							      yylval.iconst=ToInt(yytext);
							    } 
							    else{
								yylval.iconst=atoi(yytext);
							    } 
							    printf("ICONST ");
							    return  ICONST;}

{NONZERO}{NUM}*(".")({ZERO}|{NONZERO}+{NUM}*)|{NONZERO}{NUM}*("E")((("-")|("+"))*{NUM}+)*|{STRB}{ONE}{BIN}*("."){BIN}+|{STRB}("."){BIN}+|{STRH}{NONZEROH}{HEX}*("."){HEX}+|{STRH}("."){HEX}+|(".")({NONZERO}{NUM}*|{ZERO}+{NUM}+)|("0")(".")("0")|("."){NUM}*("E")(("+")|("-"))*({NONZERO}{NUM}*)* {
							  yylval.fconst=(char*)malloc(sizeof(char)*strlen(yytext));
							  strcpy(yylval.fconst,yytext);							  
							  printf("FCONST ");
							  return  FCONST;
							  }
(("'")[\040-\176]("'"))|("'")("\\")([ntfrbv"])("'") {

						    if(CaseBackslash(yytext)=='\0'){
							yylval.cconst=yytext[1];
						    }else{yylval.cconst=CaseBackslash(yytext);
						    }    printf("CCONST ");
						    return  CCONST;}


(("C")|("c"))(((("A")|("a"))(("D")|("d"))*)|(("D")|("d"))+)(("R")|("r")) {
						  yylval.listfunc=(char*)malloc(sizeof(char)*strlen(yytext));
						  strcpy(yylval.listfunc,yytext);
						  printf("LISTFUNC ");
						  return  LISTFUNC;
						  }

(("/")("/")((.)*)("\n"))|((("/")("*"))(((.)*)(("\n")*))+(("*")("/"))) {
				int i; int len=strlen(yytext);
				for(i=0;i<len;i++){
				  if(yytext[i]=='\n'){
				      line++; printf("\n%d:",line);
				  }
				}
				printf("COMMENT ");
			      }

((({IDSYMP}{IDSYMP}+)|({LETTER}+))((({LETTER}|{NUM}))+{IDSYMP}({LETTER}|{NUM})+)+)|(({LETTER}|{NUM})+) {
					yylval.id=(char*)malloc(sizeof(char)*strlen(yytext)); 
					strcpy(yylval.id,yytext);
					printf("ID ");
					return ID;
					}

("\n")	{line++; printf("\n%d:",line);}
<<EOF>> {return 0;}
[\t]
" "	//IGNORE WHITESCACE
.	{printf("Character:rejected by flex in line :%d",line);}


%%


/*
int main (int argc,char *argv[]){
  FILE *f;
  int lcl=-1;
  char *str= (char *) malloc(sizeof(char));
  
  if(argc!=2){printf("Invalid number of arguments\n"); return 0;}
  yyin=fopen(argv[1], "r");					//pairnw arxeio eisodou apo thn grammh entolwn
  
  
do{
lcl=yylex();
if (lcl!=-2){
printf("in line :%d token=%d\n",line,lcl);
printf(" ==>*token=%s, code=%d*\n",yytext,lcl);
}
else{printf("Unrecongized Character :%s in Line :%d\n",yytext,line);}

}while(lcl!=0);
return 0;
}*/

   int yywrap(void) {
    return 1;
}