#include <stdio.h>
#include <string.h>
#include <mysql.h>


void error(MYSQL *connection, char *frase) {
	if (mysql_query(connection, frase)) {
		printf("%s\n", mysql_error(connection));
		exit(1);
	}

	return;
}


void imprimir(MYSQL_RES *res, MYSQL_ROW row, MYSQL *connection, char *frase, int num) {
	res = mysql_use_result(connection);
	printf("\n%s\n", frase);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s\n", row[0]);
	}
	
	printf("\nDigite 0 para prosseguir\n");
	scanf("%d", &num);
	while(num != 0) {
		scanf("%d", &num);
	}
	system("clear");

	return;
}


void imprimir8(MYSQL_RES *res, MYSQL_ROW row, MYSQL *connection, char *frase, int num) {
	printf("%s\n", frase);
	res = mysql_use_result(connection);
	printf("cpfCliente       valorGasto\n");
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%5s ", row[0]);
		printf("%20s ", row[1]);
		printf("\n");
	}
	
	printf("\nDigite 0 para prosseguir\n");
	scanf("%d", &num);
	while(num != 0) {
		scanf("%d", &num);
	}
	system("clear");

	return;
}


int main() {
	char comando[2000];

	char nomeSetor[100];
	char placa[10], nomeCarro[100], modelo[100], ano[20], valor[20], codSetor[20];
	char cpfFuncionario[10], nomeFuncionario[100], enderecoFuncionario[100], salario[20];
	char cpfCliente[10], nomeCliente[100], telefone[100], enderecoCliente[100];
	char data[10], placaTroca[10];
	char data1[10], data2[10];
	double valorMaior, valorMenor;

	MYSQL *connection;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user   = "root";
	char *password = "password";
	char *database = "agencia";
	
	connection = mysql_init(NULL);
	
	// Conecta a database
	if (!mysql_real_connect(connection, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(connection));
		exit(1);
	}

	int operatorMaster = 0;
	int operator = 0;

	while(operatorMaster != 3) {
		system("clear");
		printf("-------------------------------------------------------------------\n");
		printf("Digite 1 para realizar Cadastros, Vendas/Trocas/Revisões na agência\n");
		printf("Digite 2 para extrair Informacões da agência                       \n");
		printf("Digite 3 para Sair                                                 \n");
		printf("-------------------------------------------------------------------\n");
		scanf("%d", &operatorMaster);
		system("clear");


		if(operatorMaster == 1) {
			operator = 0;
			while(operator != 8) {
				printf("--------------------------------------------------------------\n");
				printf("Digite 1 para cadastrar um Setor da agência                   \n");
				printf("Digite 2 para cadastrar um Carro na agência                   \n");
				printf("Digite 3 para cadastrar um Funcionário na agência             \n");
				printf("Digite 4 para cadastrar um Cliente na agência                 \n");
				printf("Digite 5 para registrar uma Venda de carro na agência         \n");
				printf("Digite 6 para registrar uma Troca de carro na agência         \n");
				printf("Digite 7 para registrar uma Manutencão de carro na agência    \n");
				printf("Digite 8 para Voltar                                          \n");
				printf("--------------------------------------------------------------\n");
				scanf("%d", &operator);
				system("clear");


				// Setor
				if(operator == 1) {
					printf("Digite o nome do Setor que será cadastrado:\n");
					scanf(" %s", nomeSetor);
					
					sprintf(comando, "insert into setor(nomeSetor) values(\"%s\");", nomeSetor);
					mysql_query(connection, comando);
					system("clear");
			
				// Carro
				} else if(operator == 2) {
					printf("Digite a Placa do carro:\n");
					scanf(" %s", placa);
					printf("Digite o Nome do carro:\n");
					scanf(" %[^\n]", nomeCarro);
					printf("Digite o Modelo do carro:\n");
					scanf(" %[^\n]", modelo);
					printf("Digite o Ano do carro:\n");
					scanf(" %s", ano);
					printf("Digite o Valor do carro:\n");
					scanf(" %s", valor);
					printf("Digite o Número do Setor a que este carro pertence:\n");
					scanf(" %s", codSetor);

					sprintf(comando, "insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values(\"%s\", \"%s\", \"%s\", %s, %s, %s);", placa, nomeCarro, modelo, ano, valor, codSetor);
					error(connection, comando);
					system("clear");

				// Funcionario
				} else if(operator == 3) {
					printf("Digite o CPF do funcionário:\n");
					scanf(" %s", cpfFuncionario);
					printf("Digite o Nome do funcionário:\n");
					scanf(" %[^\n]", nomeFuncionario);
					printf("Digite o Endereco do funcionário:\n");
					scanf(" %[^\n]", enderecoFuncionario);
					printf("Digite o Salário do funcionário:\n");
					scanf(" %[^\n]", salario);
					printf("Digite o Código do Setor do funcionário:\n");
					scanf(" %s", codSetor);

					sprintf(comando, "insert into funcionario(cpfFuncionario, nomeFuncionario, enderecoFuncionario, salario, codSetor) values(\"%s\", \"%s\", \"%s\", %s, %s);", cpfFuncionario, nomeFuncionario, enderecoFuncionario, salario, codSetor);
					error(connection, comando);
					system("clear");
					
				// Cliente	
				} else if(operator == 4) {
					printf("Digite o CPF do cliente:\n");
					scanf(" %s", cpfCliente);
					printf("Digite o Nome do cliente:\n");
					scanf(" %[^\n]", nomeCliente);
					printf("Digite o Telefone do cliente:\n");
					scanf(" %s", telefone);
					printf("Digite o Endereco do cliente:\n");
					scanf(" %[^\n]", enderecoCliente);
					printf("Digite a Placa do carro do cliente:\n");
					scanf(" %s", placa);
					printf("Digite o CPF do funcionário que atende o cliente:\n");
					scanf(" %s", cpfFuncionario);

					sprintf(comando, "insert into cliente(cpfCliente, nomeCliente, telefone, enderecoCliente, placa, cpfFuncionario) values(\"%s\", \"%s\", %s, \"%s\", \"%s\", \"%s\");", cpfCliente, nomeCliente, telefone, enderecoCliente, placa, cpfFuncionario);
					error(connection, comando);
					system("clear");

				// Venda
				} else if(operator == 5) {
					printf("Digite o CPF do funcionário:\n");
					scanf(" %s", cpfFuncionario);
					printf("Digite o CPF do cliente:\n");
					scanf(" %s", cpfCliente);
					printf("Digite a Placa do carro que será comprado:\n");
					scanf(" %s", placa);
					printf("Digite o Valor do carro:\n");
					scanf(" %s", valor);
					printf("Digite a Data da venda:\n");
					scanf(" %s", data);

					sprintf(comando, "insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values (\"%s\", \"%s\", \"%s\", 2, %s, %s);", cpfFuncionario, cpfCliente, placa, data, valor);
					mysql_query(connection, comando);

					sprintf(comando, "update carro set situacao = \"vendido\" where placa = \"%s\";", placa);
					mysql_query(connection, comando);

					sprintf(comando, "update cliente set placa = \"%s\" where cpfCliente = \"%s\";", placa, cpfCliente);
					mysql_query(connection, comando);

					system("clear");					

				// Troca
				} else if(operator == 6) {
					printf("Digite o CPF do funcionário:\n");
					scanf(" %s", cpfFuncionario);
					printf("Digite o CPF do cliente:\n");
					scanf(" %s", cpfCliente);
					printf("Digite a Placa do carro que será Comprado:\n");
					scanf(" %s", placa);
					printf("Digite o Valor do carro que será Comprado:\n");
					scanf(" %lf", &valorMaior);
					printf("Digite a Placa do carro que será Trocado:\n");
					scanf(" %s", placaTroca);
					printf("Digite o Valor do carro que será Trocado:\n");
					scanf(" %lf", &valorMenor);
					printf("Digite a Data da troca:\n");
					scanf(" %s", data);

					sprintf(comando, "insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, placaTroca, valorOperacao) values (\"%s\", \"%s\", \"%s\", 3, %s, \"%s\", %lf);", cpfFuncionario, cpfCliente, placa, data, placaTroca, valorMaior-valorMenor);
					mysql_query(connection, comando);

					sprintf(comando, "select placa from carro where placa = \"%s\";", placaTroca);
					if (mysql_query(connection, comando)) {
						fprintf(stderr, "%s\n", mysql_error(connection));
						exit(1);
					}

					res = mysql_use_result(connection);

					if((row = mysql_fetch_row(res)) == NULL) {
						printf("\nVamos cadastrar o Antigo carro do cliente!\n");

						printf("Digite o Nome do carro:\n");
						scanf(" %[^\n]", nomeCarro);
						printf("Digite o Modelo do carro:\n");
						scanf(" %[^\n]", modelo);
						printf("Digite o Ano do carro:\n");
						scanf(" %s", ano);

						mysql_free_result(res);

						sprintf(comando, "insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values(\"%s\", \"%s\", \"%s\", %s, %lf, 2);", placaTroca, nomeCarro, modelo, ano, valorMenor);
						error(connection, comando);				

						sprintf(comando, "update carro set situacao = \"disponivel\" where placa = \"%s\";", placaTroca);
						error(connection, comando);

						sprintf(comando, "update cliente set placa = \"%s\" where cpfCliente = \"%s\";", placa, cpfCliente);
						error(connection, comando);

					} else {
						mysql_free_result(res);
						sprintf(comando, "update cliente set placa = \"%s\" where cpfCliente = \"%s\";", placa, cpfCliente);
						error(connection, comando);	
					}
					system("clear");

				// Revisão
				} else if(operator == 7) {
					printf("Digite as Informacões do carro que será revisado!\n");
					printf("Digite a Placa do carro:\n");
					scanf(" %s", placa);
					printf("Digite o Nome do carro:\n");
					scanf(" %[^\n]", nomeCarro);
					printf("Digite o Modelo do carro:\n");
					scanf(" %[^\n]", modelo);
					printf("Digite o Ano do carro:\n");
					scanf(" %s", ano);
					printf("Digite o Valor do carro:\n");
					scanf(" %s", valor);

					sprintf(comando, "insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor, situacao) values(\"%s\", \"%s\", \"%s\", %s, %s, 4, \"revisão\");", placa, nomeCarro, modelo, ano, valor);
					mysql_query(connection, comando);
					system("clear");


					printf("\nDigite o CPF do funcionário:\n");
					scanf(" %s", cpfFuncionario);
					printf("Digite o CPF do cliente:\n");
					scanf(" %s", cpfCliente);
					printf("Digite a Data da revisao:\n");
					scanf(" %s", data);

					sprintf(comando, "insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values (\"%s\", \"%s\", \"%s\", 4, %s, 200);", cpfFuncionario, cpfCliente, placa, data);
					mysql_query(connection, comando);
					system("clear");

				}
			}
		} 
		else if(operatorMaster == 2) {
			operator = 0;
			while(operator != 16) {
				printf("-------------------------------------------------------------------------------------------------------------------------\n");
				printf("Digite 1  para descobrir Qual o modelo de carro mais vendido no ultimo ano (ou em um determinado intervalo de tempo)\n");
				printf("Digite 2  para descobrir Qual o carro mais vendido de todos os tempos\n");
				printf("Digite 3  para descobrir Quanto a agência lucrou com a venda/troca dentro de um determinado intervalo de tempo\n");
				printf("Digite 4  para descobrir Quais clientes que já trocaram de carro mais de uma vez em menos de 1 ano\n");
				printf("Digite 5  para descobrir Quanto é a folha de pagamento mensal da agência\n");
				printf("Digite 6  para descobrir Quantos funcionários há em cada setor, e qual é o custo para manter esse setor\n");
				printf("Digite 7  para Obter os clientes que estão com revisão atrasadas (última revisão feita há mais de 1 ano atrás)\n");
				printf("Digite 8  para Obter o gasto total por cliente na minha agência, com compra/troca de carro ou manutencões\n");
				printf("Digite 9  para Determinar quantos carros (por modelo), e o valor total destes, estão armazenados na agência\n");
				printf("Digite 10 para Obter a lista de clientes que trocaram de carro há mais de 3 anos\n");
				printf("Digite 11 para Descobrir quais funcionários são mais e menos eficientes (em venda de carros)\n");
				printf("Digite 12 para Aumentar o salário do funcionário do mês (entregou maior lucro para a agência no mês) em 6 por cento\n");
				printf("Digite 13 para Demitir o funcionário com pior rendimento até um determinado momento\n");
				printf("Digite 14 para Obter a lista de todos clientes, ordenados pelo gasto total que estes já tiverem na agência\n");
				printf("Digite 15 para Apagar os registros dos clientes que não efetuam negócio (troca de carro ou manutencão) há mais de 10 anos\n");
				printf("Digite 16 para Voltar\n");
				printf("-------------------------------------------------------------------------------------------------------------------------\n");
				scanf("%d", &operator);
				system("clear");
				
				int num = 1;

				if(operator == 1) {
					printf("Informe o intervalo de tempo:\n");
					printf("OBS: Digite as datas em ano, mês e dia(yyyymmdd)\n\n");
					printf("Digite a primeira data (a maior)\n");
					scanf(" %s", data1);
					printf("Digite a segunda data (a menor)\n");
					scanf(" %s", data2);

					sprintf(comando, "select modelo from (select max(qnt) maximo from (select count(modelo) qnt from carro natural join comando where comando.codSetor = 2 and dataOperacao < %s and dataOperacao > %s group by modelo) a) b join (select modelo, count(modelo) qnt2 from carro natural join comando where codSetor = 2 group by modelo) c on maximo = qnt2;", data1, data2);
					mysql_query(connection, comando);
					
					imprimir(res, row, connection, "O modelo mais vendido foi:", num);

				} else if(operator == 2) {
					sprintf(comando, "select nomeCarro from (select max(qnt) maximo from (select count(nomeCarro) qnt from carro where situacao = \"vendido\" group by nomeCarro) a) b join (select nomeCarro, count(nomeCarro) qnt2 from carro where situacao = \"vendido\" group by nomeCarro) c on maximo = qnt2;");
					mysql_query(connection, comando);

					imprimir(res, row, connection, "O carro mais vendido de todos os tempo eh:", num);

				} else if(operator == 3) {
					printf("Informe o intervalo de tempo:\n");
					printf("OBS: Digite as datas em ano, mês e dia(yyyymmdd)\n\n");
					printf("Digite a primeira data (a maior)\n");
					scanf(" %s", data1);
					printf("Digite a segunda data (a menor)\n");
					scanf(" %s", data2);

					sprintf(comando, "select sum(valorOperacao) from comando where codSetor = 2 and dataOperacao > %s and dataOperacao < %s;", data2, data1);
					error(connection, comando);

					imprimir(res, row, connection, "A valor que a agência lucrou com as vendas foi:", num);

					sprintf(comando, "select sum(valorOperacao) from comando where codSetor = 3 and dataOperacao > %s and dataOperacao < %s;", data2, data1);
					error(connection, comando);

					imprimir(res, row, connection, "A valor que a agência lucrou com as trocas foi:", num);

				} else if(operator == 4) {
					sprintf(comando, "select cpfCliente from (select cpfCliente, count(cpfCliente) qnt from comando where codSetor = 3 and dataOperacao < 20110101 and dataOperacao > 20100101 group by cpfCliente) a where qnt > 1;");
					mysql_query(connection, comando);

					imprimir(res, row, connection, "Os seguintes clientes ja trocaram de carro mais de uma vez em menos de 1 ano:", num);

				} else if(operator == 5) {
					sprintf(comando, "select sum(salario) from funcionario;");
					mysql_query(connection, comando);
					
					imprimir(res, row, connection, "A folha de pagamento mensal da agência, em reais, eh:", num);

				} else if(operator == 6) {
					sprintf(comando, "select cod1, qntFuncionarios, sal from (select codSetor cod1, count(cpfFuncionario) qntFuncionarios from funcionario group by codSetor) a join (select codSetor cod2, sum(salario) sal from funcionario group by codSetor) b on cod1 = cod2;");
					mysql_query(connection, comando);

					res = mysql_use_result(connection);
					printf("\nA quantidade de funcionarios em cada setor, e o custo para manter cada setor eh:\n");
					printf("codSetor     qntFuncionarios     custoTotal\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%5s ", row[0]);
						printf("%15s ", row[1]);
						printf("%20s ", row[2]);
						printf("\n");
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					mysql_free_result(res);

				} else if(operator == 7) {
					sprintf(comando, "select nomeCliente, cpfCliente from cliente natural join comando where codSetor = 4 and dataOperacao < 20200101;");
					mysql_query(connection, comando);

					printf("Os clientes que estao com revisão atrasada são:\n");

					res = mysql_use_result(connection);
					printf("nomeCliente      cpfCliente\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%s ", row[0]);
						printf("%10s ", row[1]);
						printf("\n");
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					mysql_free_result(res);

				} else if(operator == 8) {
					sprintf(comando, "select cpfCliente, sum(valorOperacao) valorGasto from comando where codSetor = 2 group by cpfCliente;");
					mysql_query(connection, comando);
					imprimir8(res, row, connection, "O valor gasto com vendas eh:", num);

					sprintf(comando, "select cpfCliente, sum(valorOperacao) valorGasto from comando where codSetor = 3 group by cpfCliente;");
					mysql_query(connection, comando);
					imprimir8(res, row, connection, "O valor gasto com trocas eh:", num);

					sprintf(comando, "select cpfCliente, sum(valorOperacao) valorGasto from comando where codSetor = 4 group by cpfCliente;");
					mysql_query(connection, comando);
					imprimir8(res, row, connection, "O valor gasto com revisões eh:", num);

				} else if(operator == 9) {
					sprintf(comando, "select modelo, count(modelo), sum(valor) from carro where situacao = \"disponivel\" group by modelo;");
					mysql_query(connection, comando);
					
					res = mysql_use_result(connection);
					printf("modelo      qntPorModelo     valorTotal\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%10s ", row[0]);
						printf("%10s ", row[1]);
						printf("%17s ", row[2]);
						printf("\n");
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					mysql_free_result(res);

				} else if(operator == 10) {
					sprintf(comando, "select nomeCliente, comando.cpfCliente from cliente natural join comando where dataOperacao < 20170101 and codSetor = 3 group by cpfCliente;");
					mysql_query(connection, comando);
					
					res = mysql_use_result(connection);
					printf("   nomeCliente         cpfCliente\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%s ", row[0]);
						printf("%10s ", row[1]);
						printf("\n");
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					mysql_free_result(res);

				} else if(operator == 11) {
					sprintf(comando, "select nomeFuncionario, cpfFuncionario, count(cpfFuncionario) vendeu from funcionario natural join comando where codSetor = 2 group by cpfFuncionario;");
					mysql_query(connection, comando);

					res = mysql_use_result(connection);
					printf("nomeFuncionario    cpfFuncionario     qntVendas\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%15s ", row[0]);
						printf("%10s ", row[1]);
						printf("%15s ", row[2]);
						printf("\n");
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					mysql_free_result(res);
					
				} else if(operator == 12) {
					sprintf(comando, "select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario order by vendeu desc;");
					mysql_query(connection, comando);

					res = mysql_use_result(connection);
					if ((row = mysql_fetch_row(res)) != NULL) {
						printf("O cpf do funcionario eh: %s\n", row[1]);
						sprintf(comando, "update funcionario set salario = salario*(1.06) where cpfFuncionario = \"%s\";", row[1]);
						mysql_free_result(res);
						
						error(connection, comando);					
					}
					
					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					
				} else if(operator == 13) {
					sprintf(comando, "select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario order by vendeu;");
					mysql_query(connection, comando);

					res = mysql_use_result(connection);
					printf("O funcionario com o pior rendimento eh:\n");
					char cpy[10];
					char del[10];
					int ver = 0;
					while ((row = mysql_fetch_row(res)) != NULL) {
						if(ver == 2)
							break;
						printf("%15s ", row[0]);
						++ver;
						if((ver == 1))
							strcpy(del, row[1]);
						printf("%10s ", row[1]);
						printf("\n");
						strcpy(cpy, row[1]);
					}

					sprintf(comando, "update cliente set cpfFuncionario = \"%s\" where cpfFuncionario = \"%s\";", cpy, del);					
					mysql_free_result(res);
					error(connection, comando);

					sprintf(comando, "update comando set cpfFuncionario = \"%s\" where cpfFuncionario = \"%s\";", cpy, del);					
					error(connection, comando);

					sprintf(comando, "delete from funcionario where cpfFuncionario = \"%s\";", del);
					error(connection, comando);

					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
					
					

				} else if(operator == 14) {
					sprintf(comando, "select cpfCliente, sum(valorOperacao) valorGasto from comando group by cpfCliente order by valorGasto;");
					mysql_query(connection, comando);
					
					imprimir8(res, row, connection, "O valor total gasto por cada cliente eh:", num);

				} else if(operator == 15) {
					sprintf(comando, "select cpfCliente from (select cpfCliente, sum(valorOperacao) valorGasto from comando where dataOperacao < 20110101 group by cpfCliente) a where valorGasto is null;");
					mysql_query(connection, comando);
					
					res = mysql_use_result(connection);
					printf("O Cliente que não faz nenhum negócio a mais de 10 anos são:\n");
					while ((row = mysql_fetch_row(res)) != NULL) {
						printf("%5s ", row[0]);
						sprintf(comando, "delete from cliente where cpfCliente = \"%s\";", row[0]);
						mysql_free_result(res);
						error(connection, comando);
						printf("\n");
					}

					printf("\nDigite 0 para prosseguir\n");
					scanf("%d", &num);
					while(num != 0) {
						scanf("%d", &num);
					}
					system("clear");
				}
			}
		}
	}

	mysql_close(connection);

	return 0;
}

