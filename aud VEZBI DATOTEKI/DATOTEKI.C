/*
 * DATOTEKI.C
 *
 *  Created on: 11.1.2022
 *      Author: User
 */
// PROBUVAM SAMA
/*1.�� �� ������ �������� ��� �� ������ ���������� ��������, ��� ��� �� ������� ����
�������� �� �������� �����, �� �� ���� ���� ������ ��� ����� ����� �� 10 ���� ����� � ��
����� �������� (��� ��� ���� ���� �� ������� ���� �������� �� �������� �����) �� ��
�������� ������� ������ �� ������� ������. �� ��� �� ������� �������� �� �� �������� �
�������� ��� �� ������ ��� ����� ����� �� 10 ���� �����.
���������� ����� �� ������� ���� ���������� ���� ������ � ������� �������� (�������
���� ������� ������� ������ �� ������).*/
// da ja napramavam obrabotkata na redot pa da go resetiram brojacot
/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX
int main(int argc, char **argv){
	FILE *vlezna,*izlezna;
	char c;
	int brmali=0,brred=0,red=1; //brred mi e broj na redovi koi go ispolnuvaat uslovot , a red mi e redniot broj na redot

	if(argc!=3){
		printf("Programata se povikuva so iminja na dve datoreki.\n");
		return -1;
	}

	if((vlezna=fopen(argv[1],"r"))==NULL){
		printf("Datotekata ne moze da se otvori.\n");
		return -1;
	}

	if((izlezna=fopen(argv[2],"w"))==NULL){
		printf("Nepravilno e otvorena izleznata datoteka.\n");
		return -1;
	}

	brmali=0;
	red=1;
	while((c=fgetc(vlezna)) != EOF){

		if(isalpha(c) && islower(c)){
			brmali++;
		}else{
			if(c=='\n'){ //ako sme dosle do nov red ne proveruvaj tuku ispecati mi, potoa premini na nov red
				if(brmali>=10){
					fprintf(vlezna,"%d",red);
					brred++;
				}
			}
			brmali=0;
			red++; // koga odime na sleden red resetiraj broj na mali bukvi i zgolemi go redniot broj na redot za 1
		}
	}
	// moze da se sluci posledniot red da ne zavrsuva so \n ,zatoa pravime uste edna proverka samo za posledniot red
	if(brmali>=10){
		fprintf(vlezna,"%d",red);
		brred++;
	}

	fprintf(vlezna,"Vo datotekata se pronajdeni %d takvi redovi.\n",brred);

	fclose(vlezna);
	fclose(izlezna);
	return 0;
} */



/*2.�� �� ������ �������� ��� �� �� ������� ���������� �� ���� �������
�������� �� ������������ �������� "matrica1.txt". �� ��������� �� ���������� �� ��������
����� �� ������ � ������ �� ���������. ���� ������� � ������ ��� ������� �� �������
��� �� ����������. ����� ��������� ����� �� �� ����������� � �� �� ������ �� ����
�������� "matrica2.txt" �� ������ �����.*/
/*#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

#define MAX 11
int main(int argc,char **argv){
	FILE *vlezna,*izlezna;
	float mat[MAX][MAX];
	float mat2[MAX][MAX];
	int m,n,i,j;

	if((vlezna=fopen("matrica1.txt","r"))==NULL){
		printf("Datotekata ne moze da se otvri za citanje.\n");
		return -1;
	}

	if((izlezna=fopen("matrica2.txt","w"))==NULL){
		printf("Datotekata ne moze da se otvori za zapisuvanje.\n");
		return -1;
	}
	//�� ��������� �� ���������� �� ��������
	//����� �� ������ � ������ �� ���������.

	fscanf(vlezna,"%d%d",&m,&n); //OTCITUVAME

	if(m>MAX || n>MAX){
		printf("Matricata e so pogolemi dimenzii.\n");
		return -1;
	}

	for(i=0;i<m && !feof(vlezna);i++){
		for(j=0;j<n && !feof(vlezna);j++){
			fscanf(vlezna,"%f",&mat[i][j]);
		}
	}

	if(i!=m || j!=n){
		printf("Falat elementi vo matricata.\n");
		return -1;
	}
	fclose(vlezna);

	fprintf(izlezna,"%d%d",n,m); // GI PECATIME VO VTORATA OBRATNO.
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			fprintf(izlezna,"%f\n",mat2[i][j]); // mozi mat da si ostani ne mora nova
		}
	}
	fclose(izlezna);

return 0;
}*/

/*3.�� �� ������ �������� ��� ���� ��������� �� �� ����� ����� �� ����� �������� �
�� �� �������� ����� �� ������ �� ��� ��� �� ������� ����� �������. ��������� ��
��������� ���� �� �����. �� ���� ��� ��� ������� 80 �����.*/
// BROENJE NA ZBOROVI VO RED, so niza
/*#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 81
// BROJ NA ZBOROVI !
// FGETS KOGA CITAME CEL RED
// NIZATA JA VNESUVAM SO CHAR
int main( int argc, char **argv){
	FILE *datoteka;
	char nizaRed[MAX];
	char c;
	int inword, words=0;;
	int line=0;
	int dol,i;

	if(argc!=0){
		printf("Upotreba na programata: %s ime_na_datoteka_za_citanje\n",argv[0]);
		return -1;
	}

	if((datoteka=fopen((argv[1]),"r"))==NULL){
		printf("Ne moze da se otvori datotekata za citanje.\n");
		return -1;
	}

	while((fgets(nizaRed,MAX,datoteka))!= NULL){
		// MI TREBA DOLZINATA NA NIZATA !!!
		dol=strlen(nizaRed);
		words=0;
		inword=0;
		for(i=0;i<dol;i++){ // KARAKTER PO KARAKTER.
			c=nizaRed[i]; // VO C KJE GO STAVIME MOMENTALNIOT ZNAk NA POZICIJA I
			if(isalpha(c)){
				if(!inword){
					inword=1;
					words++;

				}else if(inword){
					inword=0;
				}
			}
		}
		 if(words>10){
			 line++;
		 }
	}
	printf("Vo %d redovi ima povekje od 10 zborovi.\n",line);
	fclose(datoteka);

return 0;
}*/

/*4.�� �� ������ �������� ��� �� ������ ����� �������� �� �� �������� ���� ������� ��
��� �� �������� ����� �� ��� ���� ����� (���� ��� ����� �� ������ ��� ��� ����� ����). ��
�� �� ����� ������� ����� ������ � ���� �����. �� ����� �� �� �������� ����� �����
������� ���� ���������. ��������� �� ��������� ���� �� �����, � �������� �� ��������
�� ������� ���� ��������� ����, ����� ��� ������. �� ����� ���� �� ������� ���� �������
������� �� 20 �����. ����� �� ���������� �� ������ �� �������� �����. (�� ��. ������,
�������, ���������, ���������, ����������, ����������).*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 21

int main(int argc ,char ** argv[]){
	FILE *vlezna;
	char zbor[MAX], c;
	int inword=0;
	int words=0;
	int k=0;//BROJ NA BUKVI VO ZBOROT
	int i,j,brpojavile=0;

	if(argc!=2){
		printf("Upotreba: %s ime_na_datoteka\n");
		return -1;
	}
	if((vlezna= fopen(argv[1],"r"))== NULL){
		printf("Datotekata ne moze da se otvori za citanje.\n");
		return -1;
	}

	// zborov sega ni e niza no PRVO PROVERI, DALI SI VO ZBOR
	while((c=fgetc(vlezna))!= EOF){
		if(isalpha(c)){ //sum vo zbor
		if(!inword){
			inword=1;


			zbor[k]=c; // PAMTI GO OVA!!!
			k++; //kolku bukvi ima vo zborot, a  koga kje vlezeme vo nov red ova treba da go resetirame na 0

		}else if(inword){
			// STOM SME NA KRAJ OD ZBOR
			zbor[k]='\0'; // treba da go terminirame

			//BITNO!!!!!!!! OBRABOTKA NA ZBOR

			for(i=0;i<k;i++){
			 brpojavile=1;
				for(j=i+1;j<k;j++){
					if(tolower(zbor[i]) == tolower(zbor[j])){
						brpojavile++;
					}
				}
				if(brpojavile>=3){
				words++;
				break;
			}
		}
			k=0; // za da pocneme za nov zbor
			inword=0;
	}

  }
}
if(k!=0){ // posledniot zbor ne e obraboten , bidejkji rabotime so fgetc
zbor[k]='\0';
for(i=0;i<k;i++){
    brpojavile=1;
	for(j=i+1;j<k;j++){
			if(tolower(zbor[i]) == tolower(zbor[j])){
			brpojavile++;
		}
	}
	if(brpojavile>=3){
	words++;
	break;
   }
 }
}
fclose(vlezna);
printf("Vo datotekata imalo %d takvi zborovi.\n",words);

	return 0;
}*/

/*5.�� ������ ��������,��� ��� ��� �� ������ �� �������� �����, �� �� ��������
�������� ��� �� ������� ��� ��������� � ���������� �� ���� �����. �� �� �������
���� ����� �� ���������� � �������� ����� �������� �����.*/


/*6. UBAAA �� �� ������ �������� ��� �� ������ ���������� �������� �� ������ ����� ������� ������� �� 3
����� ��������� � ���������� �� ���� �����. �� �� � ����� ������� ��� ������ � ���� �����.
��������� �� ��������� �� ���������� ��� �� �����, � �������� �� �������� �� ������� ����
��������� ����, ����� ��� ������. ����� �� �������� �������� �� ������ �� �������� �����, �
������� �� � �������� �� ���� �� ������������ ����.*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv){
	FILE *datoteka;
	char c,prva,posledna;
	int inword=0;
	int words=0,bukvi=0;

	if(argc!=2){
		printf("Upotreba: %s ime_na_datoteka.\n",argv[0]);
		return -1;
	}
	if((datoteka=fopen(argv[1],"r"))==NULL){
		printf("Problem so citanje na datotekata.\n");
		datoteka=stdin;
	}

	while((c=fgetc(datoteka))!=NULL){
		if(isalpha(c)){
			if(!inword){
				inword=1;
				prva=c;
			}
			bukvi++;
			posledna=c;
		} else
			if (inword)
			{
				inword=0;
				if(bukvi>=3 && toupper(prva)==toupper(posledna)) words++;
				bukvi=0;
			}
		c++; // sleden znak.
	}

if(inword){ // PROVERUVAM ZA POSLEDNIOT ZNAK
  if(bukvi>=3 && toupper(prva)==toupper(posledna)) words++;
}

printf("Pronajdeni se %d,takvi zborovi.\n",words);

return 0;
}*/

/*7.�� ������ ��������, ��� ��� ��� �� ������ �� �������� ����� �� �� �������� �������� ��� ��
������� �� ���� ��� ��� ��������� � ���������� �� ���� �����. �� �� ������� ���� ����� ��
���������� � �������� ����� �������� �����.*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *datoteka;
	char c,prva,posledna;
	int inword=0,words=0;
	int red;

	if(argc!=0){
		printf("Problem pri otvoranje na programata.\n");
		return -1;
	}

	if((datoteka=fopen(argv[1]),"r")==NULL){
		printf("Datotekata ne moze da se otvori za citanje. Vnesi validna.\n");
		return -1;
	}

	while((c=fgetc(datoteka))!= EOF){
		if(c!='\n'){//ako ne e nov red
			red=1;
			if(isalpha(c)){
				if(!inword){
					inword=1;
					prva=c;
				}
				posledna=c;
			}
				else if(inword){
					inword=0;
					if(toupper(prva)==toupper(posledna)) words++;
				}
			}else{
				if(c=='\n'){
					printf("red:%d\n br.na zborovi:%d\n",red,words);
					red++;
					words=0;
					inword=0;
				}
			}
		}
	if(inword){
		inword=0;
		if(toupper(prva)==toupper(posledna)) words++;
		printf("red:%d\n br.na zborovi:%d\n",red,words);
	}
	return 0;
}*/

/*8.�� �� ������ �������� ��� �� �������� ��� ��� �� ������� ����� �������� ����� �� ������
����� ������� ��� �� ���� ���. ��������� �� ��������� �� ������������� ����� � �������� ��
�������� �� ������ ��� �������������� ����. ��� ����� �� ���������� �� � �������� �����
�������� ����� �� �� ������� �� ������������ ����, � ������� �� ������ ����� ��������� �� ��
����������� ������ ��� ���������� �� ��������.*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char argv[]){
	FILE *datoteka;
	char c;
	int inword=0, words=0,red=0;

	if(argc==1){
		printf("Greska");
		datoteka=stdin;
	}
	if(argc>2){
		printf("Vneseni se premnogu argumenti.\n");
		return -1;
	}

	if((datoteka=fopen(argv[1]),"r")==NULL){
		printf("Datotekata ne moze da se otvori za citanje.\n");
	}

	while((c=fgetc(datoteka))!=EOF){
		if(c!='\n'){
			red=1;
			if(isalnum(c)){
				if(!inword){
				inword=1;
			}else if(inword){
				inword=0;
				words++;
			}
		}
	}else if(c=='\n'){
	    inword=0;
		printf("Red:%d, br. na zborovi vo toj red:%d\n",red,words);
		red++;
		words=0;
	}
}
	if(inword){
		words++;
		printf("Red:%d, br. na zborovi vo toj red:%d\n",red,words);
	}

return 0;
}*/

/*9.�� �� ������ �������� ��� �� ������ ���������� �������� �� ������ � �������� ������� �������
�� ������ ����� ��� ��������� � ���������� �� ����������. �� �� �� ����� ������� ��� ������ �
���� �����. ��������� �� ��������� ���� �� �����, � �������� �� ������� �� ������� ����
�������� ����, ����� ��� ������ �����. ����� �� �������� �������� �� ������ �� ��������
�����, � ������� �� � �������� �� �� �������� ����� �� �������� �� ����������. �� ����������
���� ������� ������� �� 15 �����.*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 16

int samoglaska(char c){
	switch(c){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': return 1;
	default: return 0;
	}
}
int main (int argc,char *argv[]){
	FILE *datoteka;

	char nizaZb[MAX],c,prva,posledna;
	int inword=0,word=0;
	int k=0, i=0;

	if(argc==1){
		printf("Imeto na datotekata ne e zadadeno preku komandna linija.\n");
		return -1;
	}

	if(argc!=2){
		printf("Problem pri otvaranje na programata.\n");
		return -1;
	}

	if((datoteka=fopen(argv[1]),"r")==NULL){
		printf("Datotekata ne moze da se otvori za ciitanje.\n");
		return -1;
	}

	while((c=fgetc(datoteka))!= EOF){
		// ne mi e bitno vo koj red sum nitu kolku redovi ima
		if(isalpha(c)){
			if(!inword){
				inword=1;
				nizaZb[k]=c;
				k++;

				prva=c;
			}
			posledna=c;
		}else if(inword){
			inword=0;
			nizaZb[k]='\0'; // OVA GO ZABORAVAM.
			if(k>4 && (!samoglaska(prva)) && (!samoglaska(posledna))) word++;
			for(i=0;i<k;i++){
				printf("Zborot e :%s",nizaZb[k]);
			}
		}
	}
	if(inword){
		nizaZb[k]='\0';
		if(k>4 &&(!samoglaska(prva))==(!samoglaska(posledna))) word++;
			for(i=0;i<k;i++){
			printf("Zborot e :%s",nizaZb[k]);
		}
	}

	fclose(datoteka);
	printf("Vkupno takvi zborovi se pronajdeni: %d\n",word);

return 0;
}*/

/*10.�� �� ������ �������� ��� �� ������ ���������� �������� �� ����� �� �� �������� ������� ������
�� �������� � ���������� �� �������� �� ���������� ��� ����� ����� �� 20 �����. ����� ��
���������� �� ������ ���� ��������� �� �������� �����. �� �������� ���� ����� �� 80 �����.*/

/*11.�� �� ������ �������� ��� �� ������ ���������� �������� �� �� ������ � �������� ���������
������� �� 5 ����� ��� ����� ������� ��� �����, ����������� �� ����������, � ��������� ��
��������. �� �� �� ����� ������� ��� ������ � ���� �����. ��������� �� ��������� ���� �� �����,
� �������� �� ������� �� ������� ���� ���������� ����, ����� ��� ������ ����. ����� ��
�����a�� �������� �� ������ �� �������� �����, � ������� �� � �������� �� �� �������� ����� �a
�������� �� ����������. �� ���������a ���� ������� ������� �� 15 �����.*/ // 17 VO ZBIRKATA




// DAVID
/*4.�� �� ������ �������� ��� �� ������ ����� �������� �� �� �������� ���� ������� ��
��� �� �������� ����� �� ��� ���� ����� (���� ��� ����� �� ������ ��� ��� ����� ����). ��
�� �� ����� ������� ����� ������ � ���� �����. �� ����� �� �� �������� ����� �����
������� ���� ���������. ��������� �� ��������� ���� �� �����, � �������� �� ��������
�� ������� ���� ��������� ����, ����� ��� ������. �� ����� ���� �� ������� ���� �������
������� �� 20 �����. ����� �� ���������� �� ������ �� �������� �����. (�� ��. ������,
�������, ���������, ���������, ����������, ����������).*/
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 21
int main(int argc,char **argv){
	FILE *datoteka;
	char c;
	int inword,dol=0,i,isti=0,j;
	char bukva[MAX];


	if(argc!=2){
		printf("GRESKA.\n");
		return -1;
	}


	if((datoteka=fopen(argv[1],"r"))==NULL){
			printf("Datotekata ne moze da se otvori za ciitanje.\n");
			return -1;
	}

	while((c=fgetc(datoteka)) != EOF){
			if(isalpha(c)){
				if(!inword){
					inword=1;
					bukva[dol]=c;
					dol++;
				}else if(inword){
					inword=0;
					bukva[dol]='\0';
					for(i=0;i<dol;i++){
						isti=1;
						for(j=i+1;j<dol;j++){
							if(toupper(bukva[i])==toupper(bukva[j])){
								isti++;
						}
					}
						if(isti>=3){
						printf("Takvi zborovi se :%s",bukva);
						break;
				}
			}

		}

	}

}

if(dol!=0){
	bukva[dol]='\n';
	for(i=0;i<dol;i++){
	isti=1;
	for(j=i+1;j<dol;j++){
	if(toupper(bukva[i])==toupper(bukva[j])){
	isti++;
	}
	}
	if(isti>=3){
	printf("Takvi zborovi se :%s",bukva);

	}
  }
}

fclose(datoteka);

	return 0;
}*/

/*3.�� �� ������ �������� ��� ���� ��������� �� �� ����� ����� �� ����� �������� �
�� �� �������� ����� �� ������ �� ��� ��� �� ������� ����� �������. ��������� ��
��������� ���� �� �����. �� ���� ��� ��� ������� 80 �����.*/
/*#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 81

int main( int argc, char *argv[]){
	FILE *datoteka;
	char c;
	int inword=0,words=0,line++;


	if(argc!=2){
			printf("GRESKA.\n");
			return -1;
		}


		if((datoteka=fopen(argv[1],"r"))==NULL){
				printf("Datotekata ne moze da se otvori za ciitanje.\n");
				return -1;
		}

	while((c=fgetc(datoteka))!=EOF){

		if(c!='\n'){
			words=0;
			if(isalpha(c)){
				if(!inword){
				inword=1;
			 }else if(inword){
					inword=0;
					words++;
					}
		  }
		}else if(c=='\n'){
			if(words>=10){
				line++;
			}
		}
	}
	printf("%d redovi go ispolnuvaat uslovot.\n",line);
	flose(datoteka);

return 0;
}*/


/*�� �� ������ �������� ��� �� �������� ����� ������ ���� �� ���� ������ � ����
������� ��������. ���������� ����� �� �� ������ �������� �������� � �� ���� ��� �� �� ����
����� �� ������ ����� � ����� �� ����������. ������, �� ��������� �������� �� ��
�������� ���� ������ �� ��� ��� ����� ������ ����� �� ����������. �� ��� �� ���������
�������� �� �� ��������� ����� �� ������ ����� � ����� �� ���������� ��� �� ������� ��
������ ��������. ���� ����, �� �� ������� ���� �������� �� ������� ����������, ��� ��, ��
�� ���� �������� �� ��������. ������� �� ���������� ����� ������� 250 �����.*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 251

int samoglaska(char c){
	switch(c){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': return 1;
	default:  return 0;
	}
}

int main(int argc, char *argv[]){
	FILE *vlezna,*izlezna;
	char c;
	int red=1,golemi,samoglaski;
	int globals=0,globalg=0;


	if(argc!=3){
			printf("Programata se povikuva so iminja na dve datoreki.\n");
			return -1;
		}

		if((vlezna=fopen(argv[1],"r"))==NULL){
			printf("Datotekata ne moze da se otvori.\n");
			return -1;
		}

		if((izlezna=fopen(argv[2],"w"))==NULL){
			printf("Nepravilno e otvorena izleznata datoteka.\n");
			return -1;
		}

		while((c=fopen(vlezna)) != EOF ){
			if(isalpha(c)){
				if(isupper(c)) globalg++;
				if(samoglaska(c)) globals++;
			}

			if(c!='\n'){
				golemi=0;
				samoglaski=0;
				if(isalpha(c)){
					if(isupper(c)) golemi++;
					if(samoglaska(c)) samoglaski++;
				}
			}else if(c=='\n'){
				if(golemi>samoglaski){
					fprintf(izlezna,"%d",red);
				}
			}
			red++;
		}

		fprintf(izlezna,"%d %d",globals,globalg);
		fclose(vlezna);
		fclose(izlezna);


	return 0;
}











