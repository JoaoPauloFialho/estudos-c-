#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhação! *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha seu nivel de dificuldade" << endl;
    cout << "Facil (F), Medio (M), Dificil (D)" << endl;
    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F') numero_de_tentativas = 15;
    else if(dificuldade == 'M') numero_de_tentativas = 10;
    else numero_de_tentativas = 5;

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool acertou = false;
    int tentativas = 0;
    double pontuacao = 1000.0;

    for(int i = 1; i <= numero_de_tentativas; i++){
        tentativas++;

        int chute;
        cout << "Qual o seu chute? ";
        cin >> chute;

        if(chute < NUMERO_SECRETO) cout << "O numero secreto eh maior" << endl;
        else if(chute > NUMERO_SECRETO) cout << "O numero secreto eh menor" << endl;

        pontuacao = pontuacao - abs(chute-NUMERO_SECRETO)/2.0;
        bool menor = chute < NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        acertou = chute == NUMERO_SECRETO;

        if (acertou){
            cout << "Parabens voce acertou !!!" << endl;
            break;
        } else if (menor){
            cout << "Seu chute eh menor que o numero secreto" << endl;
        } else if (maior)
        {
            cout << "Seu chute eh maior que o numero secreto" << endl;
        }
    }
    cout << "Numero de tentativas " << tentativas << endl;
    if(numero_de_tentativas <= tentativas) cout << "Você perdeu" << endl;
    else {
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi " << pontuacao;
    }

    return 1;
}