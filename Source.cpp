//////////////////////////////////////////////////
// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE      //
//                                              //
// DESCRIPCION DEL PROBLEMA: Deber Lambda       //
// AUTOR: Pablo Antonio Campoverde Jimenez      //
// FECHA DE CREACION: 14/05/2024                //
//////////////////////////////////////////////////


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    // una variable estatica local
    static int nextValue = 1;

    generate(v.begin(), v.end(), [] { return nextValue++; });
}

int main()
{
    // Thnumero de elementos en el vector 
    const int elementCount = 9;

    //crea un vector objeto con cada elemento colocado desde 1
    vector<int> v(elementCount, 1);

    //esas variables se mantienen previamente a los dos elementos del vector 
    int x = 1;
    int y = 1;

    // coloca cada elemneto en el vector a la suma de los dos elementos anteriores
    generate_n(v.begin() + 2,
        elementCount - 2,
        [=]() mutable throw() -> int { // lambda es el tercer parametro
            // genera un valor actual
            int n = x + y;
            // actualiza los dos valores anteriores
            x = y;
            y = n;
            return n;
        });
    print("vector v after call to generate_n() with lambda: ", v);

    // Imprime las variables x e y
    // Thlas variables x e y mantienen sus valores iniciales por que
    // son capturados por valor
    cout << "x: " << x << " y: " << y << endl;

    // llena el vector con una secuencia de numeros
    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    // Fllena el vector con la siguinte secuencia de vectores
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);
}