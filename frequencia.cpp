#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Função principal
vector<string> palavrasMaisFrequentes(vector<string>& palavras, int k) {
    unordered_map<string, int> freq;

    // 1. Contar a frequência
    for (const string& palavra : palavras) {
        freq[palavra]++;
    }

    // 2. Copiar para vetor de pares (palavra, frequencia)
    vector<pair<string, int>> lista(freq.begin(), freq.end());

    // 3. Ordenar com base na frequência e ordem alfabética
    sort(lista.begin(), lista.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;  // frequência decrescente
        return a.first < b.first;  // ordem alfabética
    });

    // 4. Obter os k primeiros
    vector<string> resultado;
    for (int i = 0; i < k && i < lista.size(); ++i) {
        resultado.push_back(lista[i].first);
    }

    return resultado;
}

int main() {
    vector<string> palavras = {"banana", "maçã", "banana", "laranja", "maçã", "banana"};
    int k = 2;

    vector<string> resultado = palavrasMaisFrequentes(palavras, k);

    for (const string& palavra : resultado) {
        cout << palavra << " ";
    }
    cout << endl;

    return 0;
}

