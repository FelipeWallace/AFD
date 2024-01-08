#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main() {

  ifstream arquivo("teste5.txt"); //leitura do arquivo de testes

  int n;                     // váriavel para armazenar o número de casos de teste
  string linha;              // string para receber a entrada do arquivo linha por linha
  char estado_inicial;       // variável para armazenar o estado inicial i
  list<char> estados_finais; // conjunto de estados finais F
  list<char> estados;        // lista de todos os estados
  map<int, char> alfabeto;   // estrutura para armazenar o alfabeto e um indice para cada termo dele
  map<char, list<char>> AFD; // estrutura para armazenar o estado e uma lista com suas transições

  getline(arquivo, linha);   // entrada da primeira linha
  for (auto x : linha) {     // linha é percorrida como um vetor
    if (x != ' ')            // os espaços vazios são ignorados
      estados.push_back(x);  // os estados são guardadaos em uma lista de chars
  }

  getline(arquivo, linha);   // entrada da segunda linha
  int indice = 0;            // váriavel para adiconar um índice a cada termo do alfabeto
  for (auto x : linha) {     // linha é percorrida como um vetor
    if (x != ' '){           // os espaços vazios são ignorados
      alfabeto[indice] = x;  // a partir do indice 0, cada termo é adicionado ao alfabeto
      indice++;              // o indice é incrementado a cada nova entrada 
    }
  }

  while (!estados.empty()) {   // o tamanho da lista de estados é exatamente igual ao número
    getline(arquivo, linha);   // de linhas na entrada contendo as transições
    for (auto x : linha) {     // linha é percorrida como um vetor
      if (x != ' ')            // os espaços vazios são ignorados
        AFD[estados.front()].push_back(x); // para cada estado da lista vai ser associada 
    }                                      // uma lista com suas transições
    estados.pop_front();       // o estado já armazenada é retirado da lista e o laço continua
  }

  getline(arquivo, linha);
  estado_inicial = linha[0];     // entrada do estado inicial
  getline(arquivo, linha);   // entrada da linha que contém os estados finais
  for (auto x : linha) {       // linha é percorrida como um vetor
    if (x != ' ')              // os espaços vazios são ignorados
      estados_finais.push_back(x); // os estados finasi são guardadaos em uma lista de chars
  }

  getline(arquivo, linha);  // entrada do número de palavras testadas
  n = stoi(linha); // converte a linha em formato string para int
  int cont = 0; // váriavel para controlar as repetições do laço de testes
  while (cont < n) { // laço de testes
    getline(arquivo, linha); // entrada das palavras 
    string palavra = linha;
    map<char, list<char>> aux = AFD; // copia do mapa de estados e transições para ser manipulada
    char estado_atual = estado_inicial; // variavel que para armazenar o estado atual do AFD
    for (auto x : linha) { // a palavra de teste vai ser percorrida como um vetor
      for (int i = 0; i < alfabeto.size(); i++) { // laço para percorrer o alfabeto
        if (x == alfabeto[i]){ // verifica se o termo está no alfabeto
          int indice1 = i;     // guarda o indice desse termo
          //cout << endl << "INDICE: " << indice1 << " Letra: " << x << endl;
          if(indice1 == 0){ // caso seja o primeiro termo sabemos que é a primeira transição possivel
            estado_atual = aux[estado_atual].front(); // o estado alcançado é guardado
            //cout << "ESTADO ATUAL: " << estado_atual << endl;
          }
          else{ // caso o indice seja maior que 0, vamos procurar a próxima transição
            aux = AFD; // para evitar erros ao decorrer do próximo laço o AFD de testes é restaurado antes de cada execução
            for (int j = 1; j <= indice1; j++) { // a lista de transições será percorrida até o vamlor do indice armazenado
              aux[estado_atual].pop_front(); // a transição anterior é descartada
              estado_atual = aux[estado_atual].front(); // o próximo estado é armazenado
              //cout << "ESTADO ATUAL: " << estado_atual << endl;
            }
          }
        }
      }
    }
    
    list<char> aux1 = estados_finais; // copia da lista de estados finais que pode ser manipulada
    bool teste = false;               // variável booleana para dar a resposta do teste
      
    while (!aux1.empty()) { // toda lista de estados finais será percorrida
      if (estado_atual == aux1.front()) { // caso o estado atual esteja nela
        teste = true;                     // a varável teste será true 
        break;                            // o laço será interrompido pois já estamos em um estado de aceitação
      } else                              // caso contrário seguiremos ao próximo estado 
        aux1.pop_front();                 // até que a lista esteja vazia
    }

    if (teste)
      cout << "A palavra '" << palavra << "' pertence a linguagem" << endl; // a palavra pertence a linguagem descrita pelo AFD
    else
      cout << "A palavra '" << palavra << "' não pertence a linguagem" << endl; // a palavra não está no alfabeto
    
    cont++; // contador será incrementado para a próxima entrada 
  }
  arquivo.close();
  return 0;
}
