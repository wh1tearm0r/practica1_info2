#include <iostream>

using namespace std;

//Problema 1
int problema1(){
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;
    if (letra >= 'a' && letra <= 'z' || letra >= 'A' && letra <= 'Z'){
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
            cout << "La letra ingresada es una vocal" << endl;
        }
        else{
            cout << "La letra ingresada es una consonante" << endl;
        }
    }
    else {
        cout << "El caracter ingresado no es una letra" << endl;
    }
    return 0;
}

//Problema 3
int problema3(){
    unsigned int dia, mes;
    cout << "Ingresa el dia: ";
    cin >> dia;
    cout << "Ingresa el mes: ";
    cin >> mes;

    if (mes == 2){
        if (dia == 29){
            cout << dia << "/" << mes << " es una fecha valida si el año es bisisesto" << endl;
        }
        else{
            if (dia >= 1 && dia <= 28){
                cout << dia << "/" << mes << " es una fecha valida" << endl;
            }
            else{
                cout << dia << "/" << mes << " no es una fecha valida" << endl;
                return 1;
            }
        }
    }
    else{
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            if (dia >= 1 && dia <= 31){
                cout << dia << "/" << mes << " es una fecha valida" << endl;
            }
            else{
                cout << dia << "/" << mes << " no es una fecha valida" << endl;
            }
        }
        else{
            if (mes == 4 || mes == 6 || mes == 9 || mes == 10){
                if (dia >= 1 && dia <= 30){
                    cout << dia << "/" << mes << " es una fecha valida" << endl;
                }
                else{
                    cout << dia << "/" << mes << " no es una fecha valida" << endl;
                }
            }
            else{
                cout << dia << "/" << mes << " no es una fecha valida" << endl;
                return 1;
            }
        }
    }
    return 0;
}

//Problema 5
int problema5(){
    int x;
    cout << "Ingresa un numero (impar): ";
    cin >> x;

    if (x <= 0 || x % 2 == 0){
        cout << "El número debe ser impar y positivo" << endl;
        return 1;
    }

    int mitad = x / 2;

    for (int i = 0; i <= mitad; i++){
        for (int j = 0; j < mitad - i; j++){
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++){
            cout << "*";
        }
        cout << endl;
    }

    for (int i = mitad - 1; i >= 0; i--){
        for (int j = 0; j < mitad - i; j++){
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

//Problema 7
int problema7(){
    int n1 = 0, n2 = 1, siguienteTermino = 0, x;

    cout << "Ingresa un numero positivo: ";
    cin >> x; // ej: 10
    if (x <= 0){
        cout << "El numero debe ser positivo" << endl;
        return 1;
    }
    else{
        cout << "Serie de Fibonacci: " << n1 << ", " << n2; // F(0) = 0; F(1) = 1
        siguienteTermino = n1 + n2; // = 1

        while (siguienteTermino <= x){ // 1 <= 10, 2 <= 10
            cout << ", " << siguienteTermino; // "..., 1, ...", "..., 1, 2, ...", etc...
            n1 = n2; // n1 = 1
            n2 = siguienteTermino; // n2 = 1, n2 = 2, ...
            siguienteTermino = n1 + n2; // 1 + 1 = 2, 1 + 2 = 3, ...
        }
    }
    return 0;
}

//Problema 9
int problema9(){
    int n;
    cout << "Ingresa un numero 'n': ";
    cin >> n;

    if (n < 0){
        cout << "El numero ingresado debe ser positivo, por lo tanto se utilizará el valor absoluto de este";
        n = -n;
    }

    int suma = 0, numerotemporal = n;

    if (n == 0){
        suma = 1;
        cout << "0^0 = 1" << endl;
    }
    else{
        bool primerdigito = true;

        while (numerotemporal > 0){
            int digito = numerotemporal % 10;

            int digitoelevado = 1;
            for (int i = 0; i < digito; i++){
                digitoelevado *= digito;
            }

            suma += digitoelevado;

            if (!primerdigito){
                cout << " + ";
            }

            cout << digito << "^" << digito << " (" << digitoelevado << ") ";

            numerotemporal /= 10;
            primerdigito = false;
        }
        cout << endl;
    }
    cout << "La suma total es igual a: " << suma << endl;
    return 0;
}

int problema11(){
    int n;
    cout << "Ingresa un numero entero positivo: ";
    cin >> n;
    if (n <= 0){
        cout << "El numero debe ser positivo" << endl;
        return 1;
    }
    int resultado = 1;
    for (int i = 2; i <= n ; i++){
        int a = resultado, b = i;
        while (b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        int mcd = a;
        resultado = (resultado / mcd) * i;
    }
    cout << "El minimo comun multiplo de los numeros del 1 al " << n << " es: " << resultado << endl;
    return 0;
}


int main(){
    int problema;
    cout << "Ingresa numero del problema" << endl;
    cin >> problema;
    if (problema % 2 == 0){
        cout << "Solo problemas impares" << endl;
    }
    else{
        switch (problema)
        {
        case 1:
            problema1();
            break;
        case 3:
            problema3();
            break;
        case 5:
            problema5();
            break;
        case 7:
            problema7();
            break;
        case 9:
            problema9();
            break;
        case 11:
            problema11();
            break;
        default:
            break;
        }
    }
}
