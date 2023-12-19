//Verificador de meta em KM para caminhadas
#include <stdio.h>
#include <locale.h>

//Fun��o para contar se a meta foi atingida ou n�o.
void verificarMeta(float meta, float voltas[20], int numVoltas){
	float totaldistancia = 0, i, falta;
	
	for (int i=0; i<numVoltas; i++){
		totaldistancia += voltas[i];
	}
	
	printf("Voc� percorreu um total de %.2f KM. \n", totaldistancia);
	
	if(totaldistancia>=meta){
		printf("Parab�ns! Voc� atingiu a meta de %.2f KM.\n", meta);
	}
	else {
		falta = meta-totaldistancia;
		printf("Voc� aina n�o atingiu a meta de %.2f KM\nFaltam %.2f KM.\n", meta, falta);
	}
}

int main() {
    float meta, voltas[20];
    int numVoltas, i, resp;
    setlocale(LC_ALL, "Portuguese");
    
    //Definir qual a meta de quil�metros.
    do{
    printf("Qual a meta de KM que voc� quer caminhar hoje? ");
    scanf("%f", &meta);
	
	//Verificar se ultrapassou do limite de voltas.
    do {
        printf("Quantas voltas voc� percorreu hoje? (M�ximo de 20 voltas) ");
        scanf("%d", &numVoltas);

        if (numVoltas > 20) {
            printf("N�mero de voltas ultrapassou o limite.\n");
        }
    } while (numVoltas > 20);
    
    //Contagem das voltas.
    printf("Digite a dist�ncia das voltas: \n");
    for(int i =0; i<numVoltas; i++){
    	printf("Dist�ncia da volta %d: ", i+1);
    	scanf("%f", &voltas[i]);
	}
	
	//Chamada da fun��o.
	verificarMeta(meta, voltas, numVoltas);
	
	//Op��o de refazer a contagem.
	printf("Deseja iniciar uma nova contagem? (1 para sim, 0 para n�o.) ");
	scanf("%d", &resp);
	
	}while (resp==1);
	
	if(resp==0){
		printf("Obrigado por utilizar nosso servi�o!");
	}
	return 0;
}
