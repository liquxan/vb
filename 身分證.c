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
					printf("�j����:%d\n",car[i]);
					break;
				case 1:
					printf("������:%d\n",car[i]);
					break;
				case 2:
					printf("�p����:%d\n",car[i]);
					break;
				case 3:
					printf("���Ȩ�:%d\n",car[i]);
					break;
				
			}
		}
}


int main(int argc, char *argv[]) {
	FILE *fi;
	fi=fopen("car.txt","r");
    int x,i,j,n,f[]={0,1,2,3},q,w,e,r;
	char day[20];
	
	printf("�п�ܥH�̨�������(1)�Ψ̬P���O(2)���:\n");
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
		printf("�P���@:%d\n",to[0]);
		printf("�P���G:%d\n",to[1]);
		printf("�P���T:%d\n",to[2]);
		printf("�P���|:%d\n",to[3]);
		printf("�P����:%d\n",to[4]);
		printf("�P����:%d\n",to[5]);
		printf("�P����:%d\n",to[6]);
	}
	fclose(fi);
	system("pause");
	return 0;
}
