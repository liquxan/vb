#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int sorting(int car[]){
	int i,j,n,g[]={0,1,2,3};
	for(i=3;i>0;i--){
			for(j=0;j<i;j++){
				if(car[j]>car[j+1]){
					n=car[j];
					car[j]=car[j+1];
					car[j+1]=n;
					n=g[j];
					g[j]=g[j+1];
					g[j+1]=n;
				}
			}
		}
		
		for(i=0;i<4;i++){
			switch(g[i]){
				case 0:
					printf("大型車:%d\n",car[i]);
					break;
				case 1:
					printf("中型車:%d\n",car[i]);
					break;
				case 2:
					printf("小型車:%d\n",car[i]);
					break;
				case 3:
					printf("公務車:%d\n",car[i]);
					break;
				
			}
		}
}


int main(int argc, char *argv[]) {
	FILE *fi;
	fi=fopen("car.txt","r");
    int x,i,j,n,f[]={0,1,2,3},q,w,e,r;
	char day[20];
	
	printf("請選擇以依車輛種類(1)或依星期別(2)顯示:\n");
	scanf("%d",&x);
	if(x==1){
	    int car[4];
		while(fscanf(fi,"%s %d %d %d %d",day,&q,&w,&e,&r)!=EOF){
			car[0]+=q;
			car[1]+=w;
			car[2]+=e;
			car[3]+=r; 
		}
		sorting(car);
	}
	else if(x==2){
		int to[]={0,0,0,0,0,0,0};
		while(fscanf(fi,"%s %d %d %d %d",day,&q,&w,&e,&r)!=EOF){
		if(day[0]=='M')
			to[0]+=q+w+e+r;
		else if(day[0]=='T'){
			if(day[1]=='H')
			      to[3]+=q+w+e+r;
			else
			      to[1]+=q+w+e+r;
		}
		else if(day[0]=='W')
		    to[2]+=q+w+e+r;
		else if(day[0]=='F')
		    to[4]+=q+w+e+r;
		
		else if(day[0]=='S'){
			if(day[1]=='A')
			to[5]+=q+w+e+r;
			else
			to[6]+=q+w+e+r;
		}
		}
		printf("星期一:%d\n",to[0]);
		printf("星期二:%d\n",to[1]);
		printf("星期三:%d\n",to[2]);
		printf("星期四:%d\n",to[3]);
		printf("星期五:%d\n",to[4]);
		printf("星期六:%d\n",to[5]);
		printf("星期日:%d\n",to[6]);
	}
	fclose(fi);
	system("pause");
	return 0;
}
