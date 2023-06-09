#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include<windows.h>
#include<MMsystem.h>

int abs(int k){
	if (k>=0){
		return k;
	}
	return -k;
	
}


int pos(char c[50]){
	int i=0;
	if(c[i]=='\0'){
		return i;
	}
	do{
		i++;
	}while(c[i]!='\0');
	return i;
}







int strass(char c[50],char a[50]){
	int i=pos(c);
	int k=0;
	do{
		c[i]=a[k];
		i++;
		k++;
	}while(a[k]!='\0');
	c[i]='\0';
}



int length(char c[50]){
	int i=-1;
	do{
		
		i++;
	}while(c[i]!='\0');
	return i;
}



int deletestr(char c[50],int p,int n){
	for(int i=0;i<n;i++){
	for(int j=0;j<length(c)-n-p;j++){
		c[p+n+j-1-i]=c[p+n+j-i];
	
	}
		
	}
	c[length(c)-n]='\0';	
}



int timexe(char c[50],char d[50]){
	time_t i;
	time(&i);
	c=ctime(&i);
	deletestr(c,0,11);
	deletestr(c,9,length(c)-9);
	d[0]='\0';
	strass(d,c);
	puts("/-----------Clock------------\\ \n");
	printf("|         %s          |\n",c);
	puts("\\----------------------------/\n");
}


	
	





int conversion(char c[50],int *p){
	int k=1;
	*p=0;
	for(int i=0;i<length(c);i++){
		*p+=((int)c[length(c)-i-1]-(int)'0')*k;
		if(c[length(c)-i-1]=='-'){
			*p-=((int)'-'-(int)'0')*k;
			*p*=-1;
		}
		k*=10;
	}}
	



int main(){
char aux[50],tm[50],hr[10],min[10];
int h=0,m=0,ch,cm;
do{
	puts("give the hour");
	scanf("%d",&h);
	puts("give the minute");
	scanf("%d",&m);
}while(h<0||h>23||m<0||m>59);
timexe(aux,tm);
puts(tm);

if(h==0){
	h=24;
}
hr[0]=tm[0];
hr[1]=tm[1];
hr[3]='\0';
min[0]=tm[3];
min[1]=tm[4];
min[3]='\0';
conversion(hr,&ch);
conversion(min,&cm);

if(h==ch&&m<cm){
printf("%d hours and %d minutes until the alarm goes off ",23,60-cm+m);
goto exit;
	
}
if(h>=ch){

if(m<cm){

printf("%d hours and %d minutes until the alarm goes off ",abs(h-ch)-1,60-cm+m);}
else{
printf("%d hours and %d minutes until the alarm goes off ",abs(h-ch),abs(m-cm));
}}
else{
	
if(m<cm){

printf("%d hours and %d minutes until the alarm goes off ",24-abs(h-ch)-1,60-cm+m);}
else{
printf("%d hours and %d minutes until the alarm goes off ",24-abs(h-ch),abs(m-cm));
}
}
exit:
sleep(2);
int ok=0;
do{
	sleep(1);
system("\cls");
;timexe(aux,tm);
hr[0]=tm[0];
hr[1]=tm[1];
hr[3]='\0';
min[0]=tm[3];
min[1]=tm[4];
min[3]='\0';
conversion(hr,&ch);
conversion(min,&cm);
	if(h==ch&&m==cm){
		puts("wake up!");
		ok=1;
	}
}while(ok==0);
PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\1643555323zlu.wav"),NULL,SND_SYNC) ;

}
