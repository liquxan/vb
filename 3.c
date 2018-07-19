#include <stdio.h>
#include <stdlib.h>
int gg(int ,int ,char ,int ,int);
int gcd(int ,int );

int main(int argc, char *argv[]) {
	FILE *fi;
	fi=fopen("math.txt","r");
	int a,b,x,y;
	char o;
	while(fscanf(fi,"%d %d %c %d %d",&a,&b,&o,&x,&y)!=EOF){
		gg(a,b,o,x,y);
		switch (o){
		case '+':
			a=(a*y+b*x);
			b=b*y;
			break;
		case '-':
			a=(a*y-b*x);
			b=b*y;
			break;
		case '*':
			a=a*x;
			b=b*y;
			break;
		case '/':
			a=a*y;
			b=b*x;
			break;
	}
	gcd(a,b);
	}
	fclose(fi);
	system("PAUSE");
	return 0;
}

int gg(int a,int b,char o,int x,int y){
	printf("%2d/%2d %c %2d/%2d =",a,b,o,x,y);
}

int gcd(int a, int b) {
	int i,x=0,temp,to,a1,b1;
	a1=a;b1=b;
	if((a==0)||(b==0)){
		printf("%2d",x);
	}else{
		if(a<b){
			to=a;
			a=b;
			b=to;
		}
	while(a%b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	}
	if(b==1){
		printf("%2d/%2d",a,b);
	}else{
		a=a1/b;
		b=b1/b;
		printf("%2d/%2d",a,b);
	}
}
