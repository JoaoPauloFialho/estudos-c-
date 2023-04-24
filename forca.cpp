#include <iostream>
//lembrar de sempre incluir a biblioteca string quando for usar string, por ser uma boa prática
#include <string>
using namespace std;

bool existe(char chute, string palavra){
    for(char letra : palavra){
        if(chute == letra) return true;
    }
    return false;
}

int main(){
    string palavra = "melancia";

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_acertou){
        char chute;
        cout << "Digite uma letra" << endl;
        cin >> chute;

        if(existe(chute, palavra)) cout << "Voce acertou" << endl;
        else cout << "Voce errou" << endl;
    }
}