/*
	Calcula a raiz quadrada de um valor, com uma determinada
	precisao. Retorna esse valor, ou -1 quando:
	
	* a < 0
	* epsilon <= 0
	* epsilon >= 1
	
	Parametro:
		a - valor cuja raiz quadrada sera calculada
		epsilon - precisao do calculo
*/

#include <stdio.h>

double raizQuadrada(double a, double epsilon) {
	
//representa a primeira operaçao para realização do cálculo, o "X0" proposto na equação de Newton.
double contaInicial;

//representa a primeira operaçao "Xi+1" na equaçao newtoniana.
double contaPrimaria;

//representa as operaçoes "Xi" subsquentes ("Xi+1") na proposta por Newton.
double contaSecundaria;

//atribui o valor necessario para a primeira operaçao necessaria na conta proposta por Newton.
contaInicial = (a*0.5);

//valor da primeira operaçao "Xi" na operaçao proposta por Newton.
contaPrimaria = (0.5)*(contaInicial + (a / contaInicial));

//Valor da operaçao |"Xi+1" - "Xi"|
double valorModulo;

	//verifiação das condiçoes necessarias para realizaçao da operaçao
	if (a < 0 || epsilon <= 0 || epsilon >= 1){
		contaSecundaria = -1;
	}
	else {
		
		//atribuiçao de um primeiro valor para o valorModulo
		if ((contaPrimaria - contaInicial) >= 0){
			valorModulo = (contaPrimaria - contaInicial);
		} else {
			valorModulo = (contaInicial - contaPrimaria);
		}

		//verificaçao de condiçao para continuidade das operaçoes
		while ((valorModulo) >= epsilon){
			
			contaSecundaria = (0.5)*(contaPrimaria + (a / contaPrimaria));
			
			//nova atribuiçao de valor para "valorModulo", analisando se ha ou nao possibilidades de continuar com a operaçao.
			if ((contaSecundaria - contaPrimaria) >= 0){
				valorModulo = (contaSecundaria - contaPrimaria);
				contaPrimaria = contaSecundaria;
			}
			else {
				valorModulo = (contaPrimaria - contaSecundaria);
				contaPrimaria = contaSecundaria;
			}
		}
	}

	return contaSecundaria; 
}


int main() {

	printf ("Qual e raiz de ");
	double valor;
	scanf("%lf", &valor);
	double precisao = 0.001;
	printf("Raiz aproximada de %lf = %lf\n", valor, raizQuadrada(valor, precisao));

	return 0;
}
