//Verificador de meta em KM para caminhadas
#include <stdio.h>
#include <locale.h>

//Função para contar se a meta foi atingida ou não.
void verificarMeta(float meta, float voltas[20], int numVoltas){
	float totaldistancia = 0, i, falta;
	
	for (int i=0; i<numVoltas; i++){
		totaldistancia += voltas[i];
	}
	
	printf("Você percorreu um total de %.2f KM. \n", totaldistancia);
	
	if(totaldistancia>=meta){
		printf("Parabéns! Você atingiu a meta de %.2f KM.\n", meta);
	}
	else {
		falta = meta-totaldistancia;
		printf("Você aina não atingiu a meta de %.2f KM\nFaltam %.2f KM.\n", meta, falta);
	}
}

int main() {
    float meta, voltas[20];
    int numVoltas, i, resp;
    setlocale(LC_ALL, "Portuguese");
    
    //Definir qual a meta de quilômetros.
    do{
    printf("Qual a meta de KM que você quer caminhar hoje? ");
    scanf("%f", &meta);
	
	//Verificar se ultrapassou do limite de voltas.
    do {
        printf("Quantas voltas você percorreu hoje? (Máximo de 20 voltas) ");
        scanf("%d", &numVoltas);

        if (numVoltas > 20) {
            printf("Número de voltas ultrapassou o limite.\n");
        }
    } while (numVoltas > 20);
    
    //Contagem das voltas.
    printf("Digite a distância das voltas: \n");
    for(int i =0; i<numVoltas; i++){
    	printf("Distância da volta %d: ", i+1);
    	scanf("%f", &voltas[i]);
	}
	
	//Chamada da função.
	verificarMeta(meta, voltas, numVoltas);
	
	//Opção de refazer a contagem.
	printf("Deseja iniciar uma nova contagem? (1 para sim, 0 para não.) ");
	scanf("%d", &resp);
	
	}while (resp==1);
	
	if(resp==0){
		printf("Obrigado por utilizar nosso serviço!");
	}
	return 0;
}
