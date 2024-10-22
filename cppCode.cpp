#include <bits/stdc++.h>
using namespace std;

/*Funciones para el tipo de escritura*/
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string BLINK = "\033[5m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";

void tipoEscritura(string texto, int delay = 50, string color = RESET) {
	cout<<color;
    for (char c : texto) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout<<RESET;
}

/*Funciones para el input de los numeros*/
int charToValue(char c) {
    if (isdigit(c)) {
        return c - '0'; 
    } else {
        return toupper(c) - 'A' + 10; 
    }
}
int convToDec(const string &num, int base){
	int value = 0;
	int len = num.length();
	for(int i = 0; i < len; i++){
		char digit = num[len - i - 1]; //Tomar digitos desde la izq
		int numValue = charToValue(digit);
		
		if(numValue >= base){
			return -1;
		}
		
		value += numValue* pow(base, i);
	}
	return value;
}
void inputNumber(string &in, int n, int base) {
    string ans;
    int num;
    do {
        cin >> ans;
        num = convToDec(ans, base);
		if(num == 0){
			in = "0";
			return;
		} 
        if (num == -1) {
            cout << "Error: Digito invalido para la base" << endl;
        } else if ((int)log2(num) + 1 > n) { 
            cout << "Error: Solo se usan "<<(int)log2(num) + 1 << " bits, no se usan " << n << " bits" << endl;
        } else {
            in = ans; 
        }
    } while (num == -1 || (int)log2(num) + 1 > n);
}



tuple<int, int> fullAdder(int A, int B, int Cin){
	int S = A ^ B ^ Cin;
	int Cout = (A & B) | (B & Cin) | (A & Cin);
	 
	return make_tuple(S, Cout);
}

int main(){
	cout << "========================================\n";
    tipoEscritura(BOLD + BLUE + "===  ", 20);
    tipoEscritura(GREEN + "S U M A D O R", 50);
    tipoEscritura(GREEN + "  D E  ", 50);
    tipoEscritura(GREEN + "N  B I T S", 50);
    tipoEscritura(BLUE + "  ===\n", 20);
	cout << "========================================\n";
	cout<<"\n\n\n";
	int n;
	int base;
	string n1;
	string n2;
	
	do{
		cout<<"Ingrese la cantidad de bits a operar (0 - 64): "<<endl;
		cin>>n;	
		if(cin.fail() || n < 0 || n > 64){
			cin.clear();
			cin.ignore();
			cout << "Error: Entrada invalida. Debe ser un numero entre 0 y 64.\n";
		}
		
				
	}while(n < 0 || n > 64 || cin.fail());

	do{
		cout<<"Ingresar el sistema numerico a trabajar (2 - 16): "<<endl;
		cin>>base;	
		if(cin.fail() || base < 2 || base > 16){
			cin.clear();
			cin.ignore();
			cout << "Error: Entrada invalida. Debe ser un numero entre 2 y 16.\n";
		}
		
				
	}while(base < 2 || base > 16 || cin.fail());
	
	cout << "\033[42m" << "Valores seleccionados" << "\033[0m" << endl;

    cout << YELLOW << "Cantidad de bits: " << n << endl;
    cout << YELLOW << "Sistema numerico: " << base << endl;
	cout << RESET << endl;
	
	cout<<"Ingrese el numero 1"<<endl;
	inputNumber(n1, n, base);
	cout<<"Ingrese el numero 2"<<endl;
	inputNumber(n2, n, base);
	
	cout << "\033[42m" << "Numeros seleccionados" << "\033[0m" << endl;
    cout << YELLOW << "Numero 1: " << n1 << endl;
    cout << YELLOW << "Numero 2: " << n2 << endl;
	cout << RESET << endl;
	
	cout << "\033[43m" << RED  << "Comenzando operacion" << RESET << endl;

	
	
	return 0;
}