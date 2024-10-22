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
	cout<<"Ingrese la cantidad de bits a operar (0 - 64): "<<endl;
	cin>>n;

	
	int base;
	
	cout<<"Ingresar el sistema numerico a trabajar (2 - 16): "<<endl;
	cin>>base;
	
	return 0;
}