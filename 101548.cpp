#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include<unistd.h>
//les procedures
void welcome();
void Ajouter();
void New();
void SearchIM();
void IM();
void SearchNP();
void searchfacon();
void NP();
void ListMoy();
void Registre();
void Moyenne();
void ListDecr();
void Decr();
void menu();
void menuquit();
//les structures
struct Module{
	char NomMod[10];
	double NoteCours;
	double NoteTD;
	double NoteTP;
	double Coef;
	double MoyMod;
};
struct Etudiant{
	int im;
	char nom[15];
	char prenom[20];
	int jour;
	char mois[20];
	int an;
	double moytot;
};
struct tout{
	struct Module mod;
	struct Etudiant edt;
};
struct tout tt[50000];
struct triSelect{	
	struct Module mod;
	struct Etudiant edt;	
};
struct triSelect tri[20000];
int nbMod;
int i;
int nbEleve;
FILE*Doc;
//---------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y; 
 //fixer position du curseur
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//-----------------------------------------------------------------------------------------------------------
void Ajouter(){
		
	sleep(1);
	int newmatr,nouveaumatr;
	nouveaumatr=0;	
	printf("\nAjout d'un nouveau etudiant...\n\n");	
	Doc=fopen("Document.txt","a+");
	//Info sur l'etudiant
	sleep(1);
	printf("Matricule : ");
	scanf("%d",&newmatr);
	//----------
	while(!feof(Doc)){
		fscanf(Doc,"Matricule : %d\n",&tt[1].edt.im);
		fscanf(Doc,"Nom : %s\n",&tt[2].edt.nom);
		fscanf(Doc,"Prenom : %s\n",&tt[3].edt.prenom);
		fscanf(Doc,"Date de naissance : %d / %s / %d\n\n",&tt[4].edt.jour,&tt[5].edt.mois,&tt[6].edt.an);
		int y=7;
		for(i=1;i<=nbMod;i++){
			fscanf(Doc,"Nom du module : %s\n",&tt[y].mod.NomMod);			
			y++;
			fscanf(Doc,"Note du cours : %lf\n",&tt[y].mod.NoteCours);						
			y++;
			fscanf(Doc,"Note TD : %lf\n",&tt[y].mod.NoteTD);						
			y++;
			fscanf(Doc,"Note TP : %lf\n",&tt[y].mod.NoteTP);
			fscanf(Doc,"Coefficient du module : %lf\n",&tt[y].mod.Coef);						
			y++;
			fscanf(Doc,"Moyenne du module = %lf\n",&tt[y].mod.MoyMod);			
			y++;			
		}
		fscanf(Doc,"Moyenne generale = %lf\n\n",&tt[y].edt.moytot);		
		if(newmatr==tt[1].edt.im){
			nouveaumatr=nouveaumatr+1;
		}
	}
	if(nouveaumatr==0){
		tt[1].edt.im=newmatr;
		fprintf(Doc,"Matricule : %d\n",tt[1].edt.im);
		printf("Nom : ");
		scanf("%s",&tt[2].edt.nom);
		fprintf(Doc,"Nom : %s\n",tt[2].edt.nom);	
		printf("Prenom : ");
		scanf("%s",&tt[3].edt.prenom);
		fprintf(Doc,"Prenom : %s\n",tt[3].edt.prenom);	
		printf("Date de naissance :\n");
		printf("	Jour : ");
		scanf("%d",&tt[4].edt.jour);
		printf("	Mois : ");
		scanf("%s",&tt[5].edt.mois);
		printf("	Annee : ");
		scanf("%d",&tt[6].edt.an);
		fprintf(Doc,"Date de naissance : %d / %s / %d\n\n",tt[4].edt.jour,tt[5].edt.mois,tt[6].edt.an);
		printf("\n");
		//Info sur les notes
		int y=7;
		int RepTD;
		double mm;
		mm=0;
		double cc;
		cc=0;
			for(i=1;i<=nbMod;i++){		
				printf("Nom du module : ");
				scanf("%s",&tt[y].mod.NomMod);
				fprintf(Doc,"Nom du module : %s\n",tt[y].mod.NomMod);		
				y++;
				printf("Note du cours : ");
				scanf("%lf",&tt[y].mod.NoteCours);
				fprintf(Doc,"Note du cours : %lf\n",tt[y].mod.NoteCours);
				double NoteCours;
				NoteCours=tt[y].mod.NoteCours+0;		
				y++;
				printf("Note TD : ");
				scanf("%lf",&tt[y].mod.NoteTD);
				fprintf(Doc,"Note TD : %lf\n",tt[y].mod.NoteTD);
				double NoteTD;
				NoteTD=tt[y].mod.NoteTD+0;		
				y++;
				int RepTP;
				printf("Existe-t-il une note pour TP ?\n	[1]	oui		[0]	non\n	Reponse : ");
				scanf("%d",&RepTP);
				if(RepTP==1){
					printf("Note TP : ");
					scanf("%lf",&tt[y].mod.NoteTP);
					fprintf(Doc,"Note TP : %lf\n",tt[y].mod.NoteTP);						
				}
				else{
					tt[y].mod.NoteTP=0;
					fprintf(Doc,"Note TP : %lf\n",tt[y].mod.NoteTP);			
				}
				double NoteTP;
				NoteTP=tt[y].mod.NoteTP+0;	
				y++;
				printf("Coefficient du module : ");
				scanf("%lf",&tt[y].mod.Coef);
				fprintf(Doc,"Coefficient du module : %lf\n",tt[y].mod.Coef);
				double Cocof;
				Cocof=tt[y].mod.Coef+0;
				y++;
				//Moyenne du module
				if(RepTP==1){			
					tt[y].mod.MoyMod=NoteCours*0.6+((NoteTD+NoteTP)/2)*0.4;
					fprintf(Doc,"Moyenne du module = %lf\n",tt[y].mod.MoyMod);		
				}
				else{			
					tt[y].mod.MoyMod=NoteCours*0.6+NoteTD*0.4;
					fprintf(Doc,"Moyenne du module = %lf\n",tt[y].mod.MoyMod);			
				}		
				// Moyenne generale
				mm=tt[y].mod.MoyMod*Cocof+mm;
				cc=Cocof+cc;	
				y++;
			}//Fin Boucle
		tt[y].edt.moytot=mm/cc;
		fprintf(Doc,"Moyenne generale = %lf\n\n",tt[y].edt.moytot);	
		system("cls");		
		sleep(1);
		printf("\n\n\n\n\t\t...Etudiant ajoute avec succes !!!");
	}
	else{
		printf("\n\tDesole, cette matricule existe deja dans la base de donnees...\n");
	}
	fclose(Doc);	
	sleep(2);
	system("cls");
}
//-----------------
void New(){
	int Ajoutn;
	printf("\n\n");
	printf("[1]	Ajouter un autre etudiant	[2]	Retour au menu principal\n Reponse : ");
	scanf("%d",&Ajoutn);
	system("cls");
	if(Ajoutn==1){
		Ajouter();
		New();		
	}
	else if(Ajoutn==2){
		menu();
	}
	else{
		printf("\n\n");
		printf("	!!!Veuillez choisir seulement un de ces chiffres.\n\n");
		New();
	}
}
//----------------------------------------------------------------------------------------------------------
	// Rechercher avec IM
void SearchIM(){
	int existe;
	existe=0;
	sleep(1);
	gotoxy(7,10);		
	printf("Entrer la matricule a rechercher : ");
	int matricule;
	scanf("%d",&matricule);
	system("cls");
	sleep(1);
	Doc=fopen("Document.txt","r");
	gotoxy(1,3);
	do{	
	//	info sur l'etudiant
		fscanf(Doc,"Matricule : %d\n",&tt[1].edt.im);
		fscanf(Doc,"Nom : %s\n",&tt[2].edt.nom);
		fscanf(Doc,"Prenom : %s\n",&tt[3].edt.prenom);
		fscanf(Doc,"Date de naissance : %d / %s / %d\n\n",&tt[4].edt.jour,&tt[5].edt.mois,&tt[6].edt.an);
		if(matricule==tt[1].edt.im){
			printf("\n\tMatricule : %d\n",tt[1].edt.im);
			printf("\n\tNom : %s\n",tt[2].edt.nom);
			printf("\n\tPrenom : %s\n",tt[3].edt.prenom);
			printf("\n\tDate de naissance : %d / %s / %d\n\n\n",tt[4].edt.jour,tt[5].edt.mois,tt[6].edt.an);
			printf("--------------------------------------------------------------------------------\n");			
		}	
	// infos sur les notes	
		int y=7;
		for(i=1;i<=nbMod;i++){						
			fscanf(Doc,"Nom du module : %s\n",&tt[y].mod.NomMod);
			if(matricule==tt[1].edt.im){
				printf(" %s :\n",tt[y].mod.NomMod);
			}			
			y++;
			fscanf(Doc,"Note du cours : %lf\n",&tt[y].mod.NoteCours);
			if(matricule==tt[1].edt.im){
				printf("	N cours : %.2lf   ",tt[y].mod.NoteCours);
			}						
			y++;
			fscanf(Doc,"Note TD : %lf\n",&tt[y].mod.NoteTD);
			if(matricule==tt[1].edt.im){
				printf("N TD : %.2lf   ",tt[y].mod.NoteTD);
			}						
			y++;
			fscanf(Doc,"Note TP : %lf\n",&tt[y].mod.NoteTP);
			if(matricule==tt[1].edt.im){
				printf("N TP : %.2lf   ",tt[y].mod.NoteTP);
			}						
			y++;
			fscanf(Doc,"Coefficient du module : %lf\n",&tt[y].mod.Coef);
			if(matricule==tt[1].edt.im){
				printf("Coef : %.0lf   ",tt[y].mod.Coef);
			}						
			y++;
			fscanf(Doc,"Moyenne du module = %lf\n",&tt[y].mod.MoyMod);
			if(matricule==tt[1].edt.im){
				printf("Note = %.2lf   \n\n",tt[y].mod.MoyMod);
			}			
			y++;
		}		
	fscanf(Doc,"Moyenne generale = %lf\n\n",&tt[y].edt.moytot);
		if(matricule==tt[1].edt.im){
			existe=existe+1;
				printf("	Moyenne generale = %.2lf",tt[y].edt.moytot);
				if(tt[y].edt.moytot>=10){
					printf("		Semestre : REUSSI\n\n");
				}
				else{
					printf("		Semestre : ECHOUE\n\n");
				}
				printf("--------------------------------------------------------------------------------\n\n\n");
			}						
	}while(!feof(Doc));	
	if(existe==0){
		printf("\n\tDesole, cette matricule n'existe pas dans notre base de donnees...\n");
	}	
	fclose(Doc);
	sleep(2);
}
//---------------------------
void IM(){	
	printf("\n\n");
	printf("	[1]	Continuer avec matricule\n	[2]	Continuer avec nom et prenom\n	[3]	Retour au menu principal\n	Reponse : ");
						int x;
						scanf("%d",&x);
						system("cls");
						if(x==1){
							SearchIM();
							IM();
						}
						else if(x==2){
							SearchNP();
							NP();
						}
						else if(x==3){
							menu();
						}
						else{
							printf("\n\n");
							printf("	!!!Veuillez choisir seulement un de ces chiffres.\n\n");
							IM();
						}
}
//-----------------------------------------------------------------------------------------------------------
	//Rechercher avec nom et prenom
void SearchNP(){
	int existe;
	existe=0;
	sleep(1);
	gotoxy(7,10);	
	char name[20];
	char forename[30];
	printf("Entrez le nom et prenom a rechercher :\n\n\nNom : ");
	scanf("%s",&name);
	printf("\nPrenom : ");
	scanf("%s",&forename);
	system("cls");
	Doc=fopen("Document.txt","r");
	sleep(1);	
	do{		
	//	info sur l'etudiant
		fscanf(Doc,"Matricule : %d\n",&tt[1].edt.im);
		fscanf(Doc,"Nom : %s\n",&tt[2].edt.nom);
		fscanf(Doc,"Prenom : %s\n",&tt[3].edt.prenom);
		fscanf(Doc,"Date de naissance : %d / %s / %d\n\n",&tt[4].edt.jour,&tt[5].edt.mois,&tt[6].edt.an);		
		if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){		
			printf("\n\n\n\tMatricule : %d\n",tt[1].edt.im);
			printf("\n\tNom : %s\n",tt[2].edt.nom);
			printf("\n\tPrenom : %s\n",tt[3].edt.prenom);
			printf("\n\tDate de naissance : %d / %s / %d\n\n",tt[4].edt.jour,tt[5].edt.mois,tt[6].edt.an);
			printf("--------------------------------------------------------------------------------\n");
		}			
	// infos sur les notes	
		int y=7;
		for(i=1;i<=nbMod;i++){			
			fscanf(Doc,"Nom du module : %s\n",&tt[y].mod.NomMod);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){			
				printf(" %s :\n",tt[y].mod.NomMod);
			}			
			y++;
			fscanf(Doc,"Note du cours : %lf\n",&tt[y].mod.NoteCours);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("	N cours : %.2lf   ",tt[y].mod.NoteCours);
			}						
			y++;
			fscanf(Doc,"Note TD : %lf\n",&tt[y].mod.NoteTD);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("N TD : %.2lf   ",tt[y].mod.NoteTD);
			}			
			y++;
			fscanf(Doc,"Note TP : %lf\n",&tt[y].mod.NoteTP);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("N TP : %.2lf  ",tt[y].mod.NoteTP);					
			}
			y++;
			fscanf(Doc,"Coefficient du module : %lf\n",&tt[y].mod.Coef);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("Coef : %.0lf   ",tt[y].mod.Coef);						
			}			
			y++;
			fscanf(Doc,"Moyenne du module = %lf\n",&tt[y].mod.MoyMod);
			if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("Note = %.2lf   \n\n",tt[y].mod.MoyMod);
			}			
			y++;
		}	//Fin boucle			
		fscanf(Doc,"Moyenne generale = %lf\n\n",&tt[y].edt.moytot);
		if(strcmp(name,tt[2].edt.nom)==0 && strcmp(forename,tt[3].edt.prenom)==0){
				printf("	Moyenne generale = %.2lf",tt[y].edt.moytot);
				existe=existe+1;
				if(tt[y].edt.moytot>=10){
					printf("		Semestre : REUSSI\n\n");
				}
				else{
					printf("		Semestre : ECHOUE\n\n");
				}				
				printf("--------------------------------------------------------------------------------\n\n\n");
		}			
	}while(!feof(Doc));	
	if(existe==0){
		printf("\n\n\tDesole, ce nom et prenom n'existent pas dans notre base de donnees...\n\n\n");
	}
	fclose(Doc);
	sleep(2);	
}
//------------------
void NP(){
	printf("	[1]	Continuer avec nom et prenom\n	[2]	Continuer avec matricule\n	[3]	Retour au menu principal\n	Reponse : ");
						int b;
						scanf("%d",&b);
						system("cls");
						if(b==1){
							SearchNP();
							NP();
						}
						else if(b==2){
							SearchIM();
							IM();
						}
						else if(b==3){
							menu();
						}
						else{
							printf("\n\n");
							printf("	!!!Veuillez choisir seulement un de ces chiffres.\n\n");
							NP();
						}	
}
//-----------------------------------------------------------------------------------------------------------
void ListMoy(){
	sleep(1);
	int nbedtmoy,t,j;
	int tempmoy,tempim;
	char tempnom[20],temprenom[30];
	nbedtmoy=0;
	t=1;
	gotoxy(0,4);
	printf("--------------------------------------------------------------------------------\n");
	printf("\nLa liste des etudiants ayant la moyenne generale superieure et egale a 10 :\n\n");
	Doc=fopen("Document.txt","r");
		do{
			//	info sur l'etudiant			
			fscanf(Doc,"Matricule : %d\n",&tt[1].edt.im);
			fscanf(Doc,"Nom : %s\n",&tt[2].edt.nom);
			fscanf(Doc,"Prenom : %s\n",&tt[3].edt.prenom);
			fscanf(Doc,"Date de naissance : %d / %s / %d\n\n",&tt[4].edt.jour,&tt[5].edt.mois,&tt[6].edt.an);			
			// infos sur les notes
			int y=7;
			for(i=1;i<=nbMod;i++){
				fscanf(Doc,"Nom du module : %s\n",&tt[y].mod.NomMod);
				y++;
				fscanf(Doc,"Note du cours : %lf\n",&tt[y].mod.NoteCours);
				y++;
				fscanf(Doc,"Note TD : %lf\n",&tt[y].mod.NoteTD);
				y++;
				fscanf(Doc,"Note TP : %lf\n",&tt[y].mod.NoteTP);
				y++;
				fscanf(Doc,"Coefficient du module : %lf\n",&tt[y].mod.Coef);
				y++;
				fscanf(Doc,"Moyenne du module = %lf\n",&tt[y].mod.MoyMod);
				y++;
			}
			fscanf(Doc,"Moyenne generale = %lf\n\n",&tt[y].edt.moytot);
			//--------------------------------------
			if(tt[y].edt.moytot>=10){
				nbedtmoy=nbedtmoy+1;
				tri[t].edt.im=tt[1].edt.im;				
				strcpy(tri[t].edt.nom,tt[2].edt.nom);
				strcpy(tri[t].edt.prenom,tt[3].edt.prenom);
				tri[t].edt.moytot=tt[y].edt.moytot;
				t++;
			}			
		}while(!feof(Doc));	
	fclose(Doc);
	//-----------------------------------------
	for(j=1;j<=nbedtmoy;j++){
		for(t=0;t<=nbedtmoy-1;t++){
			if(tri[t].edt.im>tri[t+1].edt.im){
				
				tempmoy=tri[t].edt.moytot;
				tri[t].edt.moytot=tri[t+1].edt.moytot;
				tri[t+1].edt.moytot=tempmoy;
								
				tempim=tri[t].edt.im;
				tri[t].edt.im=tri[t+1].edt.im;
				tri[t+1].edt.im=tempim;	
							
				strcpy(tempnom,tri[t].edt.nom);
				strcpy(tri[t].edt.nom,tri[t+1].edt.nom);
				strcpy(tri[t+1].edt.nom,tempnom);
								
				strcpy(temprenom,tri[t].edt.prenom);
				strcpy(tri[t].edt.prenom,tri[t+1].edt.prenom);
				strcpy(tri[t+1].edt.prenom,temprenom);				
			}
		}
	}
	for(t=1;t<=nbedtmoy;t++){
		printf("\n 	IM : %d		Moyenne : %.2lf 	%s %s\n",tri[t].edt.im,tri[t].edt.moytot,tri[t].edt.nom,tri[t].edt.prenom);
	}		
	//-----------------------------------------
		printf("\n\n--------------------------------------------------------------------------------\n");
		printf("Nombre d'etudiant ayant la moyenne generale superieure et egale a 10 : %d\n\n",nbedtmoy);
		printf("--------------------------------------------------------------------------------\n");	
	sleep(1);	
}
//----------------------------
void Moyenne(){
	int Moyen;
	printf("\n\n\n\n\n\n\n");
	printf("[1]	Liste de tous les etudiants en fonction de la moyenne generale par ordre decroissante\n\n");
	printf("[2]	Retour au menu principal\n\n	Reponse : ");
	scanf("%d",&Moyen);
	system("cls");
	if(Moyen==1){
		ListDecr();
		Decr();		
	}
	else if(Moyen==2){
		menu();
	}
	else{
		printf("\n\n	!!!Veuillez choisir seulement un de ces chiffres.\n\n");
		Moyenne();
	}	
}
//-----------------------------------------------------------------------------------------------------------------
void ListDecr(){
	sleep(1);
	nbEleve=0;
	int t;
	t=1;	
	Doc=fopen("Document.txt","r");
		do{
			//	info sur l'etudiant			
			fscanf(Doc,"Matricule : %d\n",&tt[1].edt.im);
			tri[t].edt.im=tt[1].edt.im;							//	IM			
			fscanf(Doc,"Nom : %s\n",&tt[2].edt.nom);
			strcpy(tri[t].edt.nom,tt[2].edt.nom);							//	Nom			
			fscanf(Doc,"Prenom : %s\n",&tt[3].edt.prenom);
			strcpy(tri[t].edt.prenom,tt[3].edt.prenom);							//	Prenom			
			fscanf(Doc,"Date de naissance : %d / %s / %d\n\n",&tt[4].edt.jour,&tt[5].edt.mois,&tt[6].edt.an);			
			// infos sur les notes
			int y=7;
			for(i=1;i<=nbMod;i++){
				fscanf(Doc,"Nom du module : %s\n",&tt[y].mod.NomMod);
				y++;
				fscanf(Doc,"Note du cours : %lf\n",&tt[y].mod.NoteCours);
				y++;
				fscanf(Doc,"Note TD : %lf\n",&tt[y].mod.NoteTD);
				y++;
				fscanf(Doc,"Note TP : %lf\n",&tt[y].mod.NoteTP);
				y++;
				fscanf(Doc,"Coefficient du module : %lf\n",&tt[y].mod.Coef);
				y++;
				fscanf(Doc,"Moyenne du module = %lf\n",&tt[y].mod.MoyMod);
				y++;
			}
			fscanf(Doc,"Moyenne generale = %lf\n\n",&tt[y].edt.moytot);
			tri[t].edt.moytot=tt[y].edt.moytot;			
			t++;
			nbEleve=nbEleve+1;					
		}while(!feof(Doc));
	fclose(Doc);
	int j,tempmoy,tempim;
	char tempnom[50],temprenom[60];
	printf("\n\n\n\n--------------------------------------------------------------------------------\n");
	printf("\n	La liste des etudiants en fonction de la moyenne : \n");	
	for(j=1;j<=nbEleve;j++){
		for(t=0;t<=nbEleve-1;t++){
			if(tri[t].edt.moytot>tri[t+1].edt.moytot){
				
				tempmoy=tri[t].edt.moytot;
				tri[t].edt.moytot=tri[t+1].edt.moytot;
				tri[t+1].edt.moytot=tempmoy;
								
				tempim=tri[t].edt.im;
				tri[t].edt.im=tri[t+1].edt.im;
				tri[t+1].edt.im=tempim;	
							
				strcpy(tempnom,tri[t].edt.nom);
				strcpy(tri[t].edt.nom,tri[t+1].edt.nom);
				strcpy(tri[t+1].edt.nom,tempnom);
								
				strcpy(temprenom,tri[t].edt.prenom);
				strcpy(tri[t].edt.prenom,tri[t+1].edt.prenom);
				strcpy(tri[t+1].edt.prenom,temprenom);				
			}
		}
	}
	int rang;
	rang=1;
	for(t=nbEleve;t>=1;t--){
		if(tri[t].edt.moytot>=10){
			printf("\nRang : %d   REUSSI	Moyenne : %.2lf		IM : %d		%s %s\n",rang,tri[t].edt.moytot,tri[t].edt.im,tri[t].edt.nom,tri[t].edt.prenom);
		}
		else{
			printf("\nRang : %d   ECHOUE	Moyenne : %.2lf		IM : %d		%s %s\n",rang,tri[t].edt.moytot,tri[t].edt.im,tri[t].edt.nom,tri[t].edt.prenom);	
		}					
		rang++;
	}
	printf("\n\n--------------------------------------------------------------------------------\n");
	sleep(1);
}
//---------------------------
void Decr(){	
	int decro;
	printf("\n\n\n\n");
	printf("[1]	Liste des etudiants ayant la moyenne generale superieure et egale a 10\n\n");
	printf("[2]	Retour au menu principal\n\n	Reponse : ");
	scanf("%d",&decro);
	system("cls");
	if(decro==1){
		ListMoy();
		Moyenne();
	}
	else if(decro==2){
		menu();
	}
	else{
		printf("\n\n");
		printf("\t\t!!!Veuillez choisir seulement un de ces chiffres.\n\n");
		Decr();
	}		
}
//------------------------------------------------------------------------------------------------------------------------------
															//Les menus
void menuquit(){	
	int out;	
	sleep(1);
	gotoxy(17,10);				
				printf("	Voudriez-vous vraiment quitter ?\n\n\n\n\t	[1]	Valider			[2]	Annuler\n\n\n");				
				printf("\n\t\t\t\tReponse : ");
				scanf("%d",&out);
				sleep(1);
				system("cls");
				if(out==1){
					sleep(1);
					gotoxy(30,27);
					printf("by <P.A.P.A.R.I.S.S/>");
					gotoxy(0,60);
					printf("");
					sleep(1);
				}
				else if(out==2){
					menu();
				}
				else{
					printf("\n\n");
					printf("\t\t!!!Veuillez choisir seulement un de ces chiffres.\n\n");
					menuquit();
				}	
}
//-------------------------------------------------------------------------------------------------------------------------------
void searchfacon(){	
		sleep(1);
		int search;			
				printf("\n\n[3]	Retour\n\n	De quelle facon voudriez-vous effectuer votre recherche ?\n\n");
				printf("		[1]	Matricule		[2]	Nom et prenom\n		Reponse : ");
				scanf("%d",&search);
				system("cls");				
					if(search==1){		//IM
						SearchIM();
						IM();					
					}					
					else if(search==2){			//Nom et prenom
						SearchNP();
						NP();						
					}					
					else if(search==3){			//Retour
						menu();
					}
					else{
						printf("\n\n");
						printf("\t\t!!!Veuillez choisir seulement un de ces chiffres.\n\n");
						searchfacon();
					}	
}
//---------------------------------------------------------------------------------------------------------------------------------
void Registre(){
		sleep(1);	
		int nblist;		
				printf("\n\n[3]	Retour\n\n	Lister :\n\n");
				printf("	[1]	les etudiants ayant la moyenne générale superieure et egale a 10\n\n");
				printf("	[2]	tous les etudiants en fonction de la moyenne generale par ordre decroissante\n\n\n		Reponse : ");
				scanf("%d",&nblist);
				system("cls");				
				if(nblist==1){
					ListMoy();
					Moyenne();
				}
				else if(nblist==2){
					ListDecr();
					Decr();
				}
				else if(nblist==3){
					menu();
				}
				else{
					printf("\n\n");
					printf("\t\t!!!Veuillez choisir seulement un de ces chiffres.\n\n");
					Registre();
				}	
}
//---------------------------------------------------------------------------------------------------------------------------------
void menu(){
	int mn;
	sleep(1);
		gotoxy(7,10);	
		printf("Menus du programme :\n\n\n\n	[1].Ajouter	[2].Rechercher	  [3].Lister	 [4].Quitter\n\n\n\n");
		printf("	Menu numero : ");
		scanf("%d",&mn);		
		system("cls");		
		if(mn==1){
			Ajouter();
			New();				
		}		
		else if(mn==2){		//Rechercher
			searchfacon();				
		}		
		else if(mn==3){
			Registre();		
		}		
		else if(mn==4){		//Quitter			
			menuquit();	
		}
		else{
			printf("\n\n");
			printf("\t\t!!!Veuillez choisir seulement un de ces chiffres.\n\n");
			menu();
		}							
}
//----------------------------------------------------------------------------------------------------------------------------------
void welcome(){
	sleep(5);
	gotoxy(30,15);
	printf("Bonjour !!!!!!!!");
	sleep(1);
	gotoxy(27,25);
	printf("Bienvenu dans ce programme");
	sleep(2);
	system("cls");	
	gotoxy(17,15);
	printf("LA");
	gotoxy(17,19);
	printf("GESTION");
	gotoxy(17,23);
	printf("DES");
	gotoxy(17,27);
	printf("ETUDIANTS");
	sleep(3);
	system("cls");
	gotoxy(7,7);
	printf("Ce programme consiste a gerer des etudiants en fonction de leurs notes.\n\n");
	gotoxy(7,12);
	printf("Il a ete concu pour faciliter la tache des responsables.\n\n");
	gotoxy(7,16);
	printf("Ainsi, cher utilisateur, profitez-en bien !!!");
	sleep(8);
	system("cls");		
}
//----------------------------------------------------------------------------------------------
int main(){		
	welcome();
	gotoxy(10,10);
	printf("Avant tout autre, veuillez entrer le nombre de module : ");
	scanf("%d",&nbMod);
	system("cls");	
	menu();	
}