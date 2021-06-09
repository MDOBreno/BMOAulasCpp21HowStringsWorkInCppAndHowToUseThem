//
//  main.cpp
//  BMOAulasCpp21HowStringsWorkInCppAndHowToUseThem
//
//  Created by Breno Medeiros on 08/06/21.
//

#include <iostream>
#include <string>

//Relembrando: Somente quando se criar um array com 'new' é que se pode deleta-lo com 'delete'
//Ensinando: String(texto) nada mais é do que um array de caracteres(char)


//Sempre que quiser fazer um metodo como o abaixo, coloque o 'const' e o '&', pois se voce apenas quer dar um Print no
// console seria um custo computacional muito alto ficar copiando toda a string todas, para logo em seguida ja jogar fora(apagar)
void PrintString(const std::string& string) {
    std::cout << string << std::endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Como escrevemos(usammos) string em C:
    // Repare que definimos o 'const' abaixo porque,como vimos na aula 'array', uma vez instanciado,
    // seu tamanho n pode mudar, sendo necessario nesse caso deletar/apagar o antigo pra criar um novo:
    const char* nome = "Breno"; //Obs1: Escrever o conteudo todo entre "" significa que isso é um PonteiroDeCaracteres.
    //nome[2]='a'; //Descomentar essa linha da erro, pois pra mudar um dos caracteres deve-se declarar sem 'const', assim:
    char nomeNaoConstante[] = "Breno";
    nomeNaoConstante[2]='a';
    
    std::cout << nome << std::endl;
    //Obs2: Escrever o conteudo todo entre ''(como fizemos na linha abaixo) significa que isso é um ArrayDeCaracteres:
    char nomeArray[6] = { 'B', 'r', 'e', 'n', 'o', '\0'}; //Sempre q usar esta forma coloque um '\0', senao tudo a frente
    // ...sera cosiderado string de forma imprevisivel, ate que o std::cout encontre algum '\0'(ou 0) na memoria.
    // ...Por exemplo, em meus testes(antes de adicionar o '\0') eu obtive "BrenoBrano".
    std::cout << nomeArray << std::endl;
    
    //Daqui para baixo o conteudo usado é graças ao "#include <string>" que fizemos no comeco desse arquivo.
    std::string stringNome = "StringBreno"; //O "Breno" é a mesma coisa que "const char[6]", na qual o sexto digito é o '\0'
    std::cout << stringNome << " " << stringNome.size() << std::endl; //Existem varias informacoes uteis dentro de "std::string"
    // Para fazer o equivalente a linha acima em C, no teriamos que fazer o seguinte abaixo:
    std::cout << nome << " " << strlen(nome) << std::endl;
    
    //Concatenar Strings:
    std::string stringConcatenada = "StringBreno"; // +"Hello!";    não funciona, porem o seguinte funciona:
    stringConcatenada += "Hello!";
    std::cout << stringConcatenada << std::endl;   // Ou entao se quiser mesmo tudo em uma unica linha:
    std::string stringConcatenada2 = std::string("StringBreno") +"Hello!";
    std::cout << stringConcatenada2 << std::endl;
    
    //Tambem é possivel fazer buscas em Strings. Atravez do metodo 'find'(q retorna a posicao da busca dentro da string) e
    // do atributo 'npos'(que é o retorno que a funcao 'find' dá quando nao encontra uma posicao de resultado). Fica assim:
    bool contem = stringConcatenada.find("no") != std::string::npos;
    std::cout << contem << std::endl;
    
    return 0;
}
