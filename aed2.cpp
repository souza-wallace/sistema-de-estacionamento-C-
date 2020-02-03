#include <iostream>
#include <fstream>
#include <locale>
#include <stdlib.h>

using namespace std;


struct cadastro
{
	string marca,modelo,ano,categoria,preco,motor, quilometragem,status,codigo,valor;
};

void cadastrov(cadastro*veiculo)//fun��o de cadastro
{
	  bool registro = false;
	  for(int i = 0; i < 50; i++)
 	 {
 		if(veiculo[i].marca == "")
	 	 {
			cout << "Marca: ";
			cin >> veiculo[i].marca;
			cout << "Modelo: ";
			cin >> veiculo[i].modelo;
			cout << "Ano: ";
			cin >> veiculo[i].ano;
			cout << "Categoria (economico, intermediario ou luxo): ";
			cin >> veiculo[i].categoria;
			cout << "Pre�o $: ";
			cin >> veiculo[i].preco;
			cout << "Motor: ";
			cin >> veiculo[i].motor;
			cout << "Quilometragem: ";
			cin >> veiculo[i].quilometragem;
			cout << "Status: ";
			cin >> veiculo[i].status;
			cout << "C�digo do ve�culo: ";
			cin >> veiculo[i].codigo;
			registro = true;
			break;
			
		 }
	 	   if(registro == false)
			{
		        cout << "Sem espa�o para registro de novos ve�culos!";
		        system("PAUSE"); //interrompe a execu��o do programa para analise da sa�da
    		}
    system("CLS");//limpa a tela de sa�da de programa
}}
	 
void editcadastro(cadastro *veiculo) //fun�ao para editar o cadastro
{
    int opcao;
    for(int i = 0; i < 50; i++)
	{
        if(veiculo[i].marca != "")
		{
            cout << i+1 << "\nMarca: " << veiculo[i].marca << "\nModelo: " << veiculo[i].modelo <<
			 "\nCodigo: " << veiculo[i].codigo << "\n\n";
        }
    }
    cout << "O cadastro de qual veiculo deseja alterar? ";
    cin >> opcao;
    opcao--;
    if(veiculo[opcao].marca != "")
	{
        cout << "Digite a marca: ";
        cin >> veiculo[opcao].marca;
        cout << "Digite o modelo: ";
        cin >> veiculo[opcao].modelo;
        cout << "Digite a categoria (economico, intermediario ou luxo): ";
        cin >> veiculo[opcao].categoria;
        cout << "Digite o c�digo: ";
        cin >> veiculo[opcao].codigo;
        cout << "Digite o motor: ";
        cin >> veiculo[opcao].motor;
        cout << "Digite o ano: ";
        cin >> veiculo[opcao].ano;
        cout << "Digite a quilometragem: ";
        cin >> veiculo[opcao].quilometragem;
        cout << "Digite o valor: ";
        cin >> veiculo[opcao].valor;
        system("CLS");
    }
    else
	{
        cout << "Ve�culo sem cadastro!";
        system("PAUSE");
        system("CLS");
    }
}

struct locacao
{
	string nome, codigo, locacoes, carrolocado;
};

void locacaov(locacao*locacoes, cadastro *veiculo) //fun��o para  loca��o de veiculos
{
    string codigo = "";
    for(int i = 0; i < 50; i++){
        if(veiculo[i].marca != ""){
            cout << i+1 << "\nMarca: " << veiculo[i].marca << "\nModelo: " << veiculo[i].modelo <<
			 "\nC�digo: " << veiculo[i].codigo << "\n\n";
        }
    }
    cout << "C�digo do ve�culo a ser locado ";
    cin >> codigo;
    for(int i = 0; i < 50; i++){
        if(codigo == veiculo[i].codigo && veiculo[i].status == "disponivel"){
            for(int j = 0; j < 50; j++){
                if(locacoes[j].nome == ""){
                    cout << "Digite o nome do locat�rio: ";
                    cin.ignore();
                    getline(cin, locacoes[j].nome);
                    locacoes[j].codigo = codigo;
                    veiculo[i].status = "locado";
                    cout << "Aluguel concluido!" << endl;
                }
                system("PAUSE");
                system("CLS");
                break;
            }
            }
        }
    }

void devolucao(locacao *locacoes, cadastro *veiculo) //fun��o para  devolu��o de veiculos
{
    string codigo = "";
    for(int i = 0; i < 50; i++)
	{
        if(locacoes[i].nome != "")
		{
            cout << "Nome do locat�rio: " << locacoes[i].nome << "\nC�digo do ve�culo: " << locacoes[i].codigo << "\n\n";
        }
    }
    cout << "C�digo do ve�culo a ser devolvido: ";
    cin >> codigo;
    for(int i = 0; i < 50; i++)
	{
        if(codigo == locacoes[i].codigo)
		{
            locacoes[i].nome = "";
            locacoes[i].codigo = "";
            for(int j = 0; j < 50; j++)
			{
                if(codigo == veiculo[j].codigo)
				{
                    veiculo[j].status = "dispon�vel";
                }
            }
            system("CLS");
            cout << "Devolu��o conclu�da!" << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
    }
}
void consulta(cadastro *veiculo)//fun��o para consultar os veiculos
{
    int opcao = 0;
    cout << "Digite a op��o de consulta que deseja:\n1: Todos\n2: Marca\n3: Motor\n5: Categoria\n5: Status:\n ";
    cin >> opcao;
    switch (opcao)
	{
         case 1: 
		{
            system("CLS");
            for(int i = 0; i < 50; i++)
			{
                if(veiculo[i].marca != "")
				{
                    cout << "Marca: " << veiculo[i].marca << "\n";
                    cout << "Modelo: " << veiculo[i].modelo << "\n";
                    cout << "Categoria: " << veiculo[i].categoria << "\n";
                    cout << "Status: " << veiculo[i].status << "\n";
                    cout << "C�digo: " << veiculo[i].codigo << "\n";
                    cout << "Motor: " << veiculo[i].motor << "\n";
                    cout << "Ano: " << veiculo[i].ano << "\n";
                    cout << "Quilometragem: " << veiculo[i].quilometragem << "\n";
                    cout << "Valor: " << veiculo[i].valor << "\n\n";
                }
            }
            system("PAUSE");
            system("CLS");
        break;}
    
	    case 2: 
		{
            system("CLS");
            string opcaomarca;
            cout << "Marca desejada: ";
            cin >> opcaomarca;
            for(int i = 0; i < 50; i++)
			{
                if(opcaomarca == veiculo[i].marca)
				{
                    cout << "Marca: " << veiculo[i].marca << "\n";
                    cout << "Modelo: " << veiculo[i].modelo << "\n";
                    cout << "Categoria: " << veiculo[i].categoria << "\n";
                    cout << "Status: " << veiculo[i].status << "\n";
                    cout << "C�digo: " << veiculo[i].codigo << "\n";
                    cout << "Motor: " << veiculo[i].motor << "\n";
                    cout << "Ano: " << veiculo[i].ano << "\n";
                    cout << "Quilometragem: " << veiculo[i].quilometragem << "\n";
                    cout << "Valor: " << veiculo[i].valor << "\n\n";
                }
            }
            system("PAUSE");
            system("CLS");
        break;
		}
        case 3: 
		{
            system("CLS");
            string opcaomotor;
            cout << "Motor desejado: ";
            cin >> opcaomotor;
            for(int i = 0; i < 50; i++){
                if(opcaomotor == veiculo[i].motor){
                    cout << "Marca: " << veiculo[i].marca << "\n";
                    cout << "Modelo: " << veiculo[i].modelo << "\n";
                    cout << "Categoria: " << veiculo[i].categoria << "\n";
                    cout << "Status: " << veiculo[i].status << "\n";
                    cout << "C�digo: " << veiculo[i].codigo << "\n";
                    cout << "Motor: " << veiculo[i].motor << "\n";
                    cout << "Ano: " << veiculo[i].ano << "\n";
                    cout << "Quilometragem: " << veiculo[i].quilometragem << "\n";
                    cout << "Valor: " << veiculo[i].valor << "\n\n";
                }
            }
            system("PAUSE");
            system("CLS");
        break;
		}
        case 4:
		{
            system("CLS");
            string opcaocat;
            cout << "Categoria desejada(economico, intermediario ou luxo): ";
            cin >> opcaocat;
            for(int i = 0; i < 50; i++)
			{
                if(opcaocat == veiculo[i].categoria){
                    cout << "Marca: " << veiculo[i].marca << "\n";
                    cout << "Modelo: " << veiculo[i].modelo << "\n";
                    cout << "Categoria: " << veiculo[i].categoria << "\n";
                    cout << "Status: " << veiculo[i].status << "\n";
                    cout << "C�digo: " << veiculo[i].codigo << "\n";
                    cout << "Motor: " << veiculo[i].motor << "\n";
                    cout << "Ano: " << veiculo[i].ano << "\n";
                    cout << "Quilometragem: " << veiculo[i].quilometragem << "\n";
                    cout << "Valor: " << veiculo[i].valor << "\n\n";
                }
            }
            system("PAUSE");
            system("CLS");
        break;
		}
        case 5: {
            system("CLS");
            string opcaostatus;
            cout << "Digite por qual status de ve�culo que deseja pesquisar (disponivel, locado, manuten��o): ";
            cin >> opcaostatus;
            cin.ignore();
            for(int i = 0; i < 50; i++){
                if(opcaostatus == veiculo[i].status){
                    cout << "Marca: " << veiculo[i].marca << "\n";
                    cout << "Modelo: " << veiculo[i].modelo << "\n";
                    cout << "Categoria: " << veiculo[i].categoria << "\n";
                    cout << "Status: " << veiculo[i].status << "\n";
                    cout << "C�digo: " << veiculo[i].codigo << "\n";
                    cout << "Motor: " << veiculo[i].motor << "\n";
                    cout << "Ano: " << veiculo[i].ano << "\n";
                    cout << "Quilometragem: " << veiculo[i].quilometragem << "\n";
                    cout << "Valor: " << veiculo[i].valor << "\n\n";
                }
            }
            system("PAUSE");
            system("CLS");
        break;
		}
      
        default: 
		{
            cout << "Op��o inv�lida!";
            system("PAUSE");
        break;
		}

    }
}
void conslocacao(locacao *locacoes)//fun��o para consultar os veiculos locados
{
    for(int i = 0; i < 50; i++){
        if(locacoes[i].nome != ""){
            cout << "Nome do locat�rio: " << locacoes[i].nome << "\n";
            cout << "C�digo do carro a ser alugado: " << locacoes[i].codigo << "\n\n";
        }
    }
    system("PAUSE");
    system("CLS");
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    bool saida = false;
    int escolha = 0, x = 0, y = 0;
    locacao locacoes[50];
    cadastro veiculo[50];
    fstream arq;
    fstream arq2;

    arq.open("dados.txt",ios_base::in);
    if(!arq)
	{
        cout << "Criando o arquivo";
        arq.open("dados.txt",ios_base::out);
        arq.close();
        system("CLS");
    }
    else
	{
        while(!arq.eof())
		{
            getline(arq,veiculo[x].marca);
            getline(arq,veiculo[x].modelo);
            getline(arq,veiculo[x].categoria);
            getline(arq,veiculo[x].status);
            getline(arq,veiculo[x].codigo);
            getline(arq,veiculo[x].motor);
            getline(arq,veiculo[x].ano);
            getline(arq,veiculo[x].quilometragem);
            getline(arq,veiculo[x].valor);
            x++;
        }
        arq.close();
    }

    arq2.open("locacao.txt",ios_base::in);
    if(!arq2)
	{
        cout << "Criando o arquivo";
        arq2.open("locacao.txt",ios_base::out);
        arq2.close();
        system("CLS");
    }
    else
	{
        while(!arq2.eof())
		{
            getline(arq2,locacoes[y].nome);
            getline(arq2,locacoes[y].codigo);
            y++;
        }
        arq2.close();
    }

    while (saida == false)
	{
        cout << "\nDigite a op��o da opera��o desejada! \n\n1: Cadastrar ve�culos\n2: Editar cadastros\n3: Registrar loca��o\n4: Registrar devolu��o\n5: Consultar disponibilidade de ve�culos\n6: Consultar veiculos locados\n7: Sair\n\n Op��o desejada: ";
        cin >> escolha;
        system("CLS");

        switch (escolha)
		{
            case 1:{
                cadastrov(veiculo);
            break;}
            case 2:{
                editcadastro(veiculo);
            break;}
            case 3:{
                locacaov(locacoes, veiculo);
            break;}
            case 4:{
                devolucao(locacoes, veiculo);
            break;}
            case 5:{
                consulta(veiculo);
            break;}
            case 6:{
                conslocacao(locacoes);
            break;}
            case 7:{
                arq.open("dados.txt", ios_base::out);
                for(int i = 0; i < 50; i++){
                    if(veiculo[i].marca != ""){
                        arq << veiculo[i].marca << endl;
                        arq << veiculo[i].modelo << endl;
                        arq << veiculo[i].categoria << endl;
                        arq << veiculo[i].status << endl;
                        arq << veiculo[i].codigo << endl;
                        arq << veiculo[i].motor << endl;
                        arq << veiculo[i].ano << endl;
                        arq << veiculo[i].quilometragem << endl;
                        arq << veiculo[i].valor << endl;
                    }
                }
                arq.close();

                arq2.open("locacao.txt", ios_base::out);
                for(int i = 0; i < 50; i++)
				{
                    if(locacoes[i].nome != "")
					{
                        arq2 << locacoes[i].nome << endl;
                        arq2 << locacoes[i].codigo << endl;
                    }
                }
                arq2.close();

                saida = true;
            break;}
            default:
			{
                cout << "Inv�lido!\n";
            	break;
			}
        }
    }
return 0;
}

