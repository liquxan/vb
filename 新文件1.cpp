#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main(int argc, char *argv[]) {
	char id[11];
	char gg;
	int i,x,x1,x2,Y;
	scanf("%s",&id);scanf("%c",&gg);
	scanf("%c",&gg);
	if(strlen(id)!=10){
		printf("FORMAT ERROR.\n");
		return (0);
	}
	else{
		if(!((id[0]>='A')) && !((id[0]<='Z'))){
		printf("FORMAT ERROR.\n");
		return (0);}
		else{
		    for(i=1;i<10;i++){
		    	if((id[i]<'0')||(id[i]>'9')){
		    	printf("FORMAT ERROR.\n");
				return(0);	
				}
			}
		}
		
	}
	
	if(!(((id[1]=='1')&&(gg=='M'))||((id[1]=='2')&&(gg=='F')))){
		printf("SEX CODE ERROR.\n");
		return 0;
	}
	else{
		switch(id[0]){
			case 'A'...'H':
			    x=id[0]-55;
			    break;
			case 'J'...'N':
				x=id[0]-56;
				break;
			case 'P'...'V':
				x=id[0]-57;
				break;
			case 'X':
				x=30;
				break;
			case 'Y':
				x=31;
				break;
			case 'W':
				x=32;
				break;
			case 'Z':
				x=33;
				break;
			case 'I':
				x=34;
				break;
			case 'O':
				x=35;
				break;
		}
				}
    x1=x/10;
    x2=x%10;
    Y=x1+9*x2;
    for(i=1;i<=8;i++){
    	Y=Y+(id[i]-'0')*(9-i);
	}
	Y=Y+(id[9]-'0');
	if(Y%10!=0){
		printf("Check sum error.\n");
	}	
	return 0;
}
