#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void apresentacao(){
	printf("********* VAMOS BRINCAR DE FORCA *********\n\n");
	printf(" Escolha a palavra secreta (1, 2, 3 ou 4):\n ");
}

int level(char* palavrasecreta){
	system("cls");
	int i, j;
	int erro = 1;
	int resultado = strlen(palavrasecreta);
	char chute;
	char forca[10];
	sprintf(forca, "__________");
	forca[strlen(palavrasecreta)]='\0';
	for(i=0; i<5; i++){
		system("cls");
		printf(" %s\n", forca);
		printf(" Insira seu chute:\n ");
		scanf(" %c", &chute);
		for(j=0; j<strlen(palavrasecreta); j++){
			if(chute == palavrasecreta[j]){
				forca[j] = chute;
				erro = 0;
				resultado--;
			}
		}
		if(erro == 0){
			system("cls");
			printf(" Voce acertou\n");
			printf(" %s\n", forca);
			Sleep(1000);
			system("cls");
			i--;
		}
		else{
			system("cls");
			printf(" Voce errou\n");
			printf(" %s\n", forca);
			Sleep(1000);
			system("cls");
		}
		erro = 1;
		if(resultado == 0){
			return resultado;
		}
	}
	resultado = 1;
	return resultado;
}

void jogo(int resultado){
	int fase;
	char palavrasecreta[10];
	do{
		scanf("%d", &fase);
		switch(fase){
			case 1:
				sprintf(palavrasecreta, "melancia\0");
				resultado = level(palavrasecreta);
				break;
			case 2:
				sprintf(palavrasecreta, "camisa\0");
				resultado = level(palavrasecreta);
				break;
			case 3:
				sprintf(palavrasecreta, "zoologico\0");
				resultado =level(palavrasecreta);
				break;
			case 4:
				sprintf(palavrasecreta, "caneta\0");
				resultado = level(palavrasecreta);
				break;
			default:
				printf(" Opcao invalida!\n");
				Sleep(1000);
				system("cls");
				apresentacao();
				continue;
		}
	}while(fase > 4 || fase <1);
	system("cls");
}

int main(){
	int resultado;
	apresentacao();
	jogo(resultado);
	system("cls");
	if(!resultado){
		printf(" Que Pena\n Voce perdeu!");
	}else{
		printf(" Parabens\n Voce venceu!");
	}
	Sleep(3000);
}