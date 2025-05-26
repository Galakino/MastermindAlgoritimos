#include <iostream>
#include <time.h>
using namespace std;


int main()
{  
    int opcoes, dificuldade;
    string temp;

    opcoes = 0;
    dificuldade = 2;
   
    while(opcoes != 4){
        system("clear");
        cout << "===== MASTERMIND =====\n";
        cout << "1. Jogar\n";
        cout << "2. Dificuldade\n";
        cout << "3. Sobre\n";
        cout << "4. Fim\n";
        cout << "Escolha uma opcao: ";
        cin>> opcoes;
       
        system("clear");
       
        if(opcoes == 1){
        int tamanho = 4; //Dificuldade Média
        int tentativas = 10;

            if (dificuldade == 1) {
                tamanho = 3; //Dificuldade Facil
                tentativas = 8;
                 
            } else if (dificuldade == 3) {
                tamanho = 5; //Difuculdade dificil
                tentativas = 12;
            }

            // Código secreto
            int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
            srand(time(NULL));

            int valido = 0; //Enquanto o código aleatório estiver com algum numero igual ao outro ele continuara em looping
            while (valido == 0) { //LOOPING DE VERIFICAÇÃO
                c1 = (rand() % 6) + 1;
                c2 = (rand() % 6) + 1; //Gera um número aleatório muito grande e tira o resto da divisão dele por 6 (0 a 5)
                c3 = (rand() % 6) + 1; // Soma mais 1 pra ficar (0 a 6)
                c4 = (rand() % 6) + 1;
                c5 = (rand() % 6) + 1;

                if (tamanho == 3) { //Verificação difuculdade fácil
                    if (c1 != c2 && c1 != c3 && c2 != c3) { //Verificaçõo para que não haja nenhum dígito igual
                        valido = 1; //Quando a variavel valido obtem 1, automaticamente sai do looping
                    }
                } else if (tamanho == 4) {//Verificação difuculdade media
                    if (c1 != c2 && c1 != c3 && c1 != c4 &&
                        c2 != c3 && c2 != c4 &&
                        c3 != c4) {
                        valido = 1;
                    }
                } else if (tamanho == 5) { //Verificação difuculdade dificil
                    if (c1 != c2 && c1 != c3 && c1 != c4 && c1 != c5 &&
                        c2 != c3 && c2 != c4 && c2 != c5 &&
                        c3 != c4 && c3 != c5 &&
                        c4 != c5) {
                        valido = 1;
                    }
                }
            }

            int venceu = 0;
            while (tentativas > 0 && venceu == 0) {
                int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0; //numeros que o usuario irá digitar
               
                int certoLugar = 0; //números digitados que estão corretos e estão na posição correta.
                int certoErrado = 0; //números digitados que estão corretos mas estão no lugar errado.

                cout << "Tentativas restantes: " << tentativas << endl;
                cout << "Digite seu palpite (numeros de 1 a 6):\n";

                cout << "1: ";
                cin >> n1;
               
                cout << "2: ";
                cin >> n2;
               
                if (tamanho >= 3) {
                    cout << "3: ";
                    cin >> n3;
                }
                if (tamanho >= 4) { //Verificação para dar opção ao usuario a partir do valor da variavel tamanho
                    cout << "4: ";
                    cin >> n4;
                }
                if (tamanho == 5) {
                    cout << "5: ";
                    cin >> n5;
                }

                // Verifica posição certa
                if (n1 == c1) certoLugar++; //certoLugar = certoLugar + 1;
                if (n2 == c2) certoLugar++;
                if (tamanho >= 3 && n3 == c3) certoLugar++;
                if (tamanho >= 4 && n4 == c4) certoLugar++;
                if (tamanho == 5 && n5 == c5) certoLugar++;


                // Verifica número certo no lugar errado (sem contar posição certa)
                if (n1 != c1) {
                    if (n1 == c2 && n2 != c2) certoErrado++; //certoErrado = certoErrado + 1;
                    else if (n1 == c3 && (tamanho >= 3 && n3 != c3)) certoErrado++;
                    else if (n1 == c4 && (tamanho >= 4 && n4 != c4)) certoErrado++;
                    else if (tamanho == 5 && n1 == c5 && n5 != c5) certoErrado++;
                }
               

                if (n2 != c2) {
                    if (n2 == c1 && n1 != c1) certoErrado++;
                    else if (n2 == c3 && (tamanho >= 3 && n3 != c3)) certoErrado++;
                    else if (n2 == c4 && (tamanho >= 4 && n4 != c4)) certoErrado++;
                    else if (tamanho == 5 && n2 == c5 && n5 != c5) certoErrado++;
                }
               

                if (tamanho >= 3 && n3 != c3) {
                    if (n3 == c1 && n1 != c1) certoErrado++;
                    else if (n3 == c2 && n2 != c2) certoErrado++;
                    else if (n3 == c4 && (tamanho >= 4 && n4 != c4)); //Tirei o certoErrado porque não faz sentido, estaremos nos sabotando.
                    else if (tamanho == 5 && n3 == c5 && n5 != c5);
                }

                if (tamanho >= 4 && n4 != c4) {
                    if (n4 == c1 && n1 != c1) certoErrado++;
                    else if (n4 == c2 && n2 != c2) certoErrado++;
                    else if (n4 == c3 && n3 != c3) certoErrado++;
                    else if (tamanho == 5 && n4 == c5 && n5 != c5); //Tirei o certoErrado porque não faz sentido, estaremos nos sabotando.
                }

                if (tamanho == 5 && n5 != c5) {
                    if (n5 == c1 && n1 != c1) certoErrado++;
                    else if (n5 == c2 && n2 != c2) certoErrado++;
                    else if (n5 == c3 && n3 != c3) certoErrado++;
                    else if (n5 == c4 && n4 != c4) certoErrado++;
                }

                cout << "Numeros certos no lugar certo: " << certoLugar << endl;
                cout << "Numeros certos no lugar errado: " << certoErrado << endl;
               
                if (certoLugar == tamanho) {
                    venceu = 1;
                    cout << "\nParabens, voce descobriu o codigo secreto!\n";
                    cout << "Digite qualquer tecla para voltar ao menu principal.\n ";
                    cin>>temp;
                } else {
                    tentativas = tentativas - 1;
                }
            }
               
            if (venceu == 0) {
                cout << "Você perdeu! O código era: ";
                cout << c1 << " ";
                if (tamanho >= 2) cout << c2 << " ";
                if (tamanho >= 3) cout << c3 << " ";
                if (tamanho >= 4) cout << c4 << " ";
                if (tamanho == 5) cout << c5 << " ";
                cout << "\n";
                system("pause");
            }
       
       
       
        } else if(opcoes == 2){
          cout << "Escolha a dificuldade:\n";
            cout << "1 - Facil (3 digitos, 8 tentativas)\n";
            cout << "2 - Medio (4 digitos, 10 tentativas)\n";
            cout << "3 - Dificil (5 digitos, 12 tentativas)\n";
            cin >> dificuldade;

            if (dificuldade < 1 || dificuldade > 3) { //Caso o jogador coloque um número que não seja 1, 2 ou 3.
                dificuldade = 2;
            }
            cout << "Dificuldade alterada!\n";
            system("pause");
         
         
        } else if(opcoes == 3){
         cout<<"Desenvolvedores: Davi Lorenzo Martins Duarte, Gabriel de Barros e Lucas Cavalcante Leandro \nMaio_2025 \nProfessor: Thiago Felski Pereira \nDisciplina: Algoritmos e Programação\n\n";
         cout<<"Clique qualquer tecla para voltar ao menu principal.\n";
         cin>>temp;
         
        } else if(opcoes == 4){
         cout<<"Até mais :) ";
         
        }
        else{
            cout<<"Opção não encontrada\n\n";
            
            cout<<"Clique qualquer tecla para voltar ao menu principal.\n";
            cin>>temp;
        }
    }
    return 0;
}
