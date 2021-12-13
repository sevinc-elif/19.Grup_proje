#include <stdio.h>
#include <string.h>
#include "proje.h"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

#define UZUNLUK 80
#define PARCAUZUNLUK 256


int main()
{
	char komutSatiri[UZUNLUK];
	char *parca[PARCAUZUNLUK];
	int parcaNo;
	int pid;
	int sonIndis;
	
	//sürekli olarak kullanıcı girdisi ister
	while (1)
	{
		
		promptYaz();
		//komutSatiri nı temizler
		memset(komutSatiri, '\0', UZUNLUK);
		//kullanıcıdan komut satırını alır
		fgets(komutSatiri, UZUNLUK, stdin);
		//komut satırının boyutu sonIndise atanır
		sonIndis=strlen(komutSatiri);
		//komut başında ve sonunda boşluk olmasını kontrol ediyor
		if(komutSatiri[0]!=32 && (komutSatiri[sonIndis-2])!=32){
		
			if ((parca[0] = strtok(komutSatiri, " \n\t;")) == NULL)
				  continue;
			
			parcaNo = 1;
		
			while ((parca[parcaNo] = strtok(NULL, "\n\t")) != NULL)
			{
				parcaNo++;
			
			}
			//bir komutun boşlukla ayrılmış en fazla 10 kelimeden oluşmasını sağlar
			if(parcaNo<10){
				//eğer komut cd ise cdKomutu fonksiyonunu çağırır
				if(strcmp(parca[0],"cd")==0){
					cdKomutu(parca);
				}
				//eğer komut showpid ise showpid fonksiyonunu çağırır
				else if(strcmp(parca[0],"showpid")==0){
					showpid(pid);
				}
				//eğer komut exit ise çıkar
				else if(strcmp(parca[0],"exit")==0){
					break;
				}
				//built in olmayan komutları çalıştırır
				else{
					
					pid=komutIcra(parca,parcaNo);

				}
			}
			else{
				printf("Hatalı giriş..\n");
			}
		}
		
		else{
			printf("Hatalı giriş..\n");
		}
	}
	return 0;
}
