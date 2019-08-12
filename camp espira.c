#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//camp magnetic creat per una espira en un pla 

int main(){
	
	int i,j,k;
	double a,y,z,m,h,fun,fun2,teta,E,K,sum,sum2,fa,fa2,fb,fb2; 
	 double mu,I,By,Bz,u;
	 FILE *bybz;
	 
	a=4.5; //radi espira
	I=25;
	mu=1;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
		
		y=-9+j;
		z=9-i;
		
		m=(4*a*y)/(pow(a,2)+pow(z,2)+pow(y,2)+2*a*y);
		
		sum=0;
		sum2=0;
		//calcular E i K
		for(k=0;k<998;k++){
			
			h=3.14159/2000;
		    teta=h+k*h;
	     	
			fun=sqrt(1-m*sin(teta)*sin(teta));
	     	fun2=1/(sqrt(1-m*sin(teta)*sin(teta)));
	     	
			 sum=sum+fun;
			 sum2=sum2+fun2;
		}
		
		    fa=1;
	     	fb=sqrt(1-m*sin(1.5707)*sin(1.5707));
		
			fa2=1;
			fb2=1/(sqrt(1-m*sin(1.5707)*sin(1.5707)));
		
			E=(h/2)*(fa+fb+2*sum);			
			K=(h/2)*(fa2+fb2+2*sum2);
	
			if(y>=0){
				
			if(y==0){
				By=0;
				Bz=(mu*I*pow(a,2))/(2*(pow(a*a+z*z,1.5)));
			}
			
			
			else if(y>0){
				
			By=((mu*I*a*z)/(2*3.1415926*pow(2*a*y,1.5)))*(-K*sqrt(2*m)+((2-m)/(2-2*m))*E*sqrt(2*m));
			Bz=((mu*I*a)/(2*3.1415926*pow(2*a*y,1.5)))*((a*m*E*pow(2*m,0.5)/(2-2*m))+y*K*pow(2*m,0.5)-y*(2-m)*E*pow(2*m,0.5)/(2-2*m));
		
	}
		printf("%lf, %lf, %lf, %lf",y,z,By,Bz);	
		printf("\n");
		
		bybz=fopen("%bybz.txt","a");//aixi es crea un fitxer amb la solucio
		fprintf(bybz,"%lf\t%lf\t%lf\t%lf\n%lf\t%lf\t%lf\t%lf\n",y,z,By,Bz,-y,z,-By,Bz);
		fclose(bybz);}
	}
	

}
system("pause");
return 0;

}
