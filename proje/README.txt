İşletim Sistemleri 2020-2021 Güz Dönemi Proje Ödevi 
19.Grup

Grup Üyeleri
Elif Sevinç 		G191210026 2B
Esra Yılmaz 		G181210044 2B
Zeynep Betül Kalkanlı 	G191210044 2B
Sümeyra Yücer 		B191210404 1B
Satı İlayda Şahin	G191210059 2B

bin
main.exe : çalışan program

doc

include
proje.h : fonksiyonların başlık dosyası

lib
proje.o
main.o

src
proje.c : tüm fonksiyonları içeren c kodu
main.c : main fonksiyonunu içeren c kodu

makefile : derle ve çalıştır işlemini yapan dosya

Derleme Talimatları
Programın bulunduğu ana dizinde wsl çalıştırıldıktan sonra make yazarak programımızı çalıştırıyoruz.

Çalıştırma Talimatları
Linux üzerinde çalışan komutları giriyor ve sonucu alıyoruz. Built-in komutların çalıştırılması da aynı şekilde oluyor.
	cd : bulunduğun dizini gösterir.
	cd .. : bulunduğun dizinden bir önceki dizine gider.
	cd lib : bulunduğun dizinde lib klasörü var ise ona gider.
	
	exit : programdan çıkar.
	showpid : halihazırda çalışan processlerin id bilgilerini ekrana yazar.
İşlenmesini istediğimiz komutu yazarken önüne boşluk, en sonuna boşluk, parametreleri arasına birden fazla boşluk koyduğumuz takdirde hata alırız. Programı kapatmak için 'exit' komutunu girer ve programdan çıkarız.

Geliştirme Sırasında Karşılaştığımız Zorluklar
1. Built-in olmayan komutların çalıştırılmasını kendi yöntemlerimizle yapacağımızı zannettiğimiz için bu konuda oldukça vakit harcadık.
2. showpid komutunu nasıl yapacağımızı anlayamadık, komutlar çalıştırıldıktan sonra process'ler oluşuyor fakat komut icrası tamamlanınca process de öldüğü için showpid komutunda ya ölü process'lerin id'lerini ya da yalnızca ana process'in id'sini gösterebilirdik. Bundan dolayı o an var olan tek process'in id'sini gösterecek şekilde kodlama yaptık.
3. cd komutunda ana dizine dönme kısmını yaparken zorlandık. Ama daha sonra sorunu çözdük ve komutu çalışır hale getirdik.

Yardım Aldığımız Kaynaklar
https://www.youtube.com/watch?v=z4LEuxMGGs8
https://www.youtube.com/watch?v=k6TTj4C0LF0
https://brennan.io/2015/01/16/write-a-shell-in-c/
https://www.geeksforgeeks.org/introduction-linux-shell-shell-scripting/
https://www.geeksforgeeks.org/making-linux-shell-c/?ref=lbp