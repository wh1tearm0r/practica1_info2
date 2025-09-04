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

//Problema 11
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

//Problema 13 (funcion auxiliar para mirar si un numero es primo)
bool problema13_aux(int n){
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

//Problema 13 (principal)
int problema13(){
    int n;
    cout << "Ingrese un entero positivo: ";
    cin >> n;

    int suma = 0;
    for (int i = 2; i <= n; ++i) {
        if (problema13_aux(i)) {
            suma += i; //
        }
    }
    cout << "La suma de todos los numeros primos entre 1 y " << n << " es: " << suma << endl;
    return 0;
}

//Problema 15
int problema15(){
    int n;

    cout << "Ingrese el tamaño de la espiral (debe ser impar): ";
    cin >> n;

    // Validar que sea impar
    if (n % 2 == 0) {
        cout << "Error: El tamaño debe ser impar. Usando " << n + 1 << endl;
        n++;
    }

    cout << "\nGenerando espiral de " << n << "x" << n << ":" << endl;

    // Para mostrar la espiral, calculamos cada posición
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {

            // Variables para simular el recorrido de la espiral
            int f = n / 2;  // posición inicial fila (centro)
            int c = n / 2;  // posición inicial columna (centro)
            int num = 1;    // número actual
            int pasos = 1;  // pasos que debemos dar en la dirección actual
            int dir = 0;    // dirección: 0=izq, 1=abajo, 2=der, 3=arriba
            int cambios = 0; // contador de cambios de dirección
            int dados = 0;   // pasos dados en la dirección actual

            // Si estamos en el centro, es el número 1
            if (fila == f && col == c) {
                cout << 1 << " ";
                continue;
            }

            // Simular el recorrido hasta llegar a la posición buscada
            bool encontrado = false;
            while (num < n * n && !encontrado) {

                // Mover según la dirección actual
                if (dir == 0) {
                    c = c - 1;      // izquierda: columna disminuye
                } else if (dir == 1) {
                    f = f + 1;      // abajo: fila aumenta
                } else if (dir == 2) {
                    c = c + 1;      // derecha: columna aumenta
                } else if (dir == 3) {
                    f = f - 1;      // arriba: fila disminuye
                }

                num = num + 1;
                dados = dados + 1;

                // Verificar si llegamos a la posición buscada
                if (f == fila && c == col) {
                    cout << num << " ";
                    encontrado = true;
                    break;
                }

                // Cambiar dirección si completamos los pasos
                if (dados == pasos) {
                    if (dir == 0) {
                        dir = 1;  // de izquierda a abajo
                    } else if (dir == 1) {
                        dir = 2;  // de abajo a derecha
                    } else if (dir == 2) {
                        dir = 3;  // de derecha a arriba
                    } else if (dir == 3) {
                        dir = 0;  // de arriba a izquierda
                    }

                    cambios = cambios + 1;
                    dados = 0;

                    // Incrementar pasos cada 2 cambios de dirección
                    if (cambios % 2 == 0) {
                        pasos = pasos + 1;
                    }
                }
            }

            // Si no encontramos la posición (no debería pasar)
            if (!encontrado) {
                cout << 0 << " ";
            }
        }
        cout << endl;  // Nueva línea al final de cada fila
    }

    // Calcular suma de diagonal principal
    int suma_diagonal = 0;

    for (int i = 0; i < n; i++) {
        // Para cada posición diagonal, calcular su valor
        int fila_diag = i;
        int col_diag = i;

        // Caso especial: centro
        if (fila_diag == n/2 && col_diag == n/2) {
            suma_diagonal = suma_diagonal + 1;
            continue;
        }

        // Simular recorrido para encontrar el valor en la diagonal
        int f = n / 2;
        int c = n / 2;
        int num = 1;
        int pasos = 1;
        int dir = 0;
        int cambios = 0;
        int dados = 0;

        while (num < n * n) {
            if (dir == 0) {
                c = c - 1;
            } else if (dir == 1) {
                f = f + 1;
            } else if (dir == 2) {
                c = c + 1;
            } else if (dir == 3) {
                f = f - 1;
            }

            num = num + 1;
            dados = dados + 1;

            if (f == fila_diag && c == col_diag) {
                suma_diagonal = suma_diagonal + num;
                break;
            }

            if (dados == pasos) {
                if (dir == 0) {
                    dir = 1;
                } else if (dir == 1) {
                    dir = 2;
                } else if (dir == 2) {
                    dir = 3;
                } else if (dir == 3) {
                    dir = 0;
                }

                cambios = cambios + 1;
                dados = 0;

                if (cambios % 2 == 0) {
                    pasos = pasos + 1;
                }
            }
        }
    }

    cout << "\nInformacion:" << endl;
    cout << "- Suma de la diagonal: " << suma_diagonal << endl;
    cout << "- Numero en el centro: 1" << endl;
    cout << "- Total de numeros: " << n * n << endl;

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
        case 13:
            problema13();
            break;
        case 15:
            problema15();
            break;
        default:
            break;
        }
    }
}
