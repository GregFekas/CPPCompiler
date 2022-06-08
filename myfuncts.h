//Chrysi Metallidou 678 && Grhgorhs Fekas 1045

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int BitConverter(char *str);
int HexConverter(char *str);
int ToInt(char *str);
int checkHexBin(char *str);
int StringToInt(char *str);
char CaseBackslash(char *str);



//checks if cconst is in case of like '\n'
char CaseBackslash(char *str){
  int len=strlen(str);
  
  if(len==4){
    if(str[2]=='\\'){
      switch (str[3]){
	case 'n': return '\n';
	case 't': return '\t';
	case 'f': return '\f';
	case 'r': return '\r';
	case 'b': return '\b';
	case 'v': return '\v';
	case '"': return '\"';
	case '\\':return '\\';
	default : return '\0';
	}
      } 
    }
    return '\0';
  }
  
 //checks in which form iconst is 
 
int checkHexBin(char *str){
  int result=0;			// 0 an einai dekadikos
  if(str[0]=='0' && str[1]=='B'){
    result=1; 			// 1 an einai Binary
  }
  if (str[0]=='0' && str[1]=='H'){
    result=2;			// 2 an einai Hex
  }
  return result;
}

//convert Binary to Dec

int BitConverter(char *str){
  int len=strlen(str);
  int temp=len;
  int i,j,addition;
  int result=0;
  
  for (i=0;i<len;i++){
    temp=temp-1;
    if(str[i]=='1'){
      addition=1;
      for(j=0;j<temp;j++){
	addition=addition<<1;
      }
      result=result+addition;
    }
  }
  
  return result;
}

//convert Hec to Dec

int HexConverter(char *str){
  int len=strlen(str);
  char *binaryform=(char*)malloc((sizeof(char))*((len+1)*4));
  int i;
  int j=0;
  int result=0;
  for (i=0; i<len;i++){
    switch (str[i]){
        case '0':binaryform[j]='0';j++; binaryform[j]='0'; j++;binaryform[j]='0'; j++;binaryform[j]='0';j++; break;
	case '1':binaryform[j]='0';j++; binaryform[j]='0'; j++;binaryform[j]='0'; j++;binaryform[j]='1';j++; break;
	case '2':binaryform[j]='0';j++; binaryform[j]='0'; j++;binaryform[j]='1'; j++;binaryform[j]='0';j++; break;
	case '3':binaryform[j]='0';j++; binaryform[j]='0'; j++;binaryform[j]='1'; j++;binaryform[j]='1';j++; break;
	case '4':binaryform[j]='0';j++; binaryform[j]='1'; j++;binaryform[j]='0'; j++;binaryform[j]='0';j++; break;
	case '5':binaryform[j]='0';j++; binaryform[j]='1'; j++;binaryform[j]='0'; j++;binaryform[j]='1';j++; break;
	case '6':binaryform[j]='0';j++; binaryform[j]='1'; j++;binaryform[j]='1'; j++;binaryform[j]='0';j++; break;
	case '7':binaryform[j]='0';j++; binaryform[j]='1'; j++;binaryform[j]='1'; j++;binaryform[j]='1';j++; break;
	case '8':binaryform[j]='1';j++; binaryform[j]='0'; j++;binaryform[j]='0'; j++;binaryform[j]='0';j++; break;
	case '9':binaryform[j]='1';j++; binaryform[j]='0'; j++;binaryform[j]='0'; j++;binaryform[j]='1';j++; break;
	case 'A':binaryform[j]='1';j++; binaryform[j]='0'; j++;binaryform[j]='1'; j++;binaryform[j]='0';j++; break;
	case 'B':binaryform[j]='1';j++; binaryform[j]='0'; j++;binaryform[j]='1'; j++;binaryform[j]='1';j++; break;
	case 'C':binaryform[j]='1';j++; binaryform[j]='1'; j++;binaryform[j]='0'; j++;binaryform[j]='0';j++; break;
	case 'D':binaryform[j]='1';j++; binaryform[j]='1'; j++;binaryform[j]='0'; j++;binaryform[j]='1';j++; break;
	case 'E':binaryform[j]='1';j++; binaryform[j]='1'; j++;binaryform[j]='1'; j++;binaryform[j]='0';j++; break;
	default: binaryform[j]='1';j++; binaryform[j]='1'; j++;binaryform[j]='1'; j++;binaryform[j]='1';j++; break;
    }
  }
  result=BitConverter(binaryform);
  
  return result;
}


//Metatrepei to Bin H to Hex se Dec.
int ToInt(char *str){
  int result=0;
  int i;
  int len=strlen(str);
  char *a=(char*)malloc(sizeof(char)*(len-2));
  
  if(str[0]=='0'){
    if(str[1]=='H'){
      
      for(i=2;i<len;i++){
	a[i-2]=str[i];
      }
      result=HexConverter(a);
      
    }
      if(str[1]=='B'){
	
	for(i=2;i<=len;i++){
	a[i-2]=str[i];
      }
      result=BitConverter(a);
      }
  }
  
  return result;
}

/*mia prospa8eia na metatrepsw to BIN iconst se float 
float BitConverterFloat(char *str){
  float result=0.0;
  int len=strlen(str);
  int i;
  int akeraio=0;
  for(i=0;i<len;i++){
    if(str[i]='.'){
      break;
    }
    else{
      akeraio++;
    }
  }
  printf("ok\n");
    char *intpart=(char*) malloc(sizeof(char)*akeraio);
    strncpy(intpart,str,akeraio);
    result=BitConverter(intpart);
    printf("%f",result);
    int power=-1;
    float dekadiko=0.0;
    for(i=akeraio+1;i<len;i++){
      if(str[i]=='\0'){break;}
      
      else{
      dekadiko=dekadiko+ (1/(pow(2,power)));
      power=power-1;
      }
    }
    result=result+dekadiko;
    
    return result;
}
*/

/*
 //Auth h sunarthsh einai gia epeidhksh!!!! mou katastrefei ta panta!!!! GIATI???
int StringToInt(char *str){
  int i,j;
  int result=0;
  int multiple=1;
  int len=strlen(str);
  
  for(i=0;i<len;i++){
    switch(str[i]){
      case '1':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+multiple; multiple=1; break;
      case '2':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*2); multiple=1; break;
      case '3':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*3); multiple=1; break;
      case '4':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*4); multiple=1; break;
      case '5':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*5); multiple=1; break;
      case '6':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*6); multiple=1; break;
      case '7':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*7); multiple=1; break;
      case '8':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*8); multiple=1; break;
      case '9':for(j=0;j<len-i-1;j++){multiple=multiple*10;} result=result+(multiple*9); multiple=1; break;
      default: break;
      }
  }
*/