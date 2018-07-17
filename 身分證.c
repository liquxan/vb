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
	system("pause");
	return 0;
}

int gg(int a,int b,char o,int x,int y){
	printf("%2d/%2d %c %2d/%2d =",a,b,o,x,y);
}

int gcd(int a, int b) {
	int i,j,x=0;
	if(a>b)
	    i=a;
    else
        i=b;
    for(;i>=1;i--){
    	if(a%i==0&&b%i==0){
    		a=a/i;
    		b=b/i;
		}
		if(b==1){
			printf("%2d\n",a);
			x=1;
			braek;
		}
	}
	if(x!=1){
		printf("%2d/%2d\n",a,b);
	}
}
