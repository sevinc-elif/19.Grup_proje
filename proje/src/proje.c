#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

static char *mevcutDizin;
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

#define UZUNLUK 80
#define PARCAUZUNLUK 256

#include "proje.h"

//prompt u ekrana yazar
void promptYaz()
{
    char hostadi[512]="";
    gethostname(hostadi,sizeof(hostadi));
	//prompt u renklendirdik ve sırasıyla hostname, mevcut dizin ve "sau >" yazdırdık
    printf(BLUE "%s@%s: " YELLOW "%s> " GREEN "sau > " RESET,getenv("LOGNAME"),hostadi,getcwd(mevcutDizin,512));
}
//built in olmayan komutları proseslerle çalıştırıyor
int komutIcra(char *prc[],int prcNo)
{
    int pid;
	pid=fork();//child id
   if(pid>0){
	   waitpid(pid, NULL, 0);
   }
   else if(pid==0){
	   
	   if (execvp(prc[0], prc) == -1)
		{
			printf("Emir bulunamadi");
			kill(getpid(), SIGTERM);
		}
		//child id döndürür
	   return getpid();
   } 
}
//showpid komutu çalışan pid i ekrana yazdırır
void showpid(int a){

	printf("%d\n",a);
		
	
}
//cd komutu dizinler arası geçiş yapar
int cdKomutu(char *prc[])
{
	if (prc[1] == NULL)
	{
		printf("%s\n",getcwd(mevcutDizin,512));
	}
	//parametreli cd komutunu çalıştırır
	else
	{
		//klasörler arası geçiş yapılmasını sağlayan fonksiyon çalıştırılır
		if (chdir(prc[1]) != 0)
		{
			perror("Kabuk");
		}
	}
	return 1;
}









