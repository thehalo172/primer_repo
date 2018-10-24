#include <iostream>
#include <cmath>
using namespace std;
int main() {
	
	float ans,b,d1,d2,e,f1,f2,ind,m,r,rad,s1,s2,sus;
	float hist[999][3];
	string histchar[999];
	int i,i2,suma;
	char operador;

	cout << "Bienvenido a la calculadora" << endl;
	cout << "_________________________________" << endl;
	cout << "" << endl;
	cout << "Para sumar inserta un: +" << endl;
	cout << "Para restar inserta un: -" << endl;
	cout << "Para multiplicar inserta una: x" << endl;
	cout << "Para dividir inserta una: /" << endl;
	cout << "Para potenciar inserta un: ^" << endl;
	cout << "Para radicar inserta un: r" << endl;
	cout << "" << endl;
	cout << "Si desea consultar el historial de operaciones, inserte: H" << endl;
	cout << "Si deseas reiniciar ingresa: A" << endl;
	cout << "Si desea parar, inserte: F" << endl;
	cout << "" << endl;
	suma = 0;
	ans = 0;
	cout << "Que accion deseas realizar?" << endl;
	do {
		cout << "Operacion: ";
		cin >> operador;
		switch (operador) {
		case '+':
			if (suma==0) {
				cout << "Inserte los sumandos" << endl;
				cin >> s1 >> s2;
				r = s1+s2;
				hist[suma][0] = s1;
				histchar[suma] = operador;
				hist[suma][1] = s2;
				hist[suma][2] = r;
			} else {
				cout << "Inserte sumando" << endl;
				cin >> s1;
				r = ans+s1;
				hist[suma][0] = ans;
				histchar[suma] = operador;
				hist[suma][1] = s2;
				hist[suma][2] = r;
			}
			cout << "Resultado: " << r << endl;
			suma = suma+1;
			ans = r;
			break;
		case '-':
			if (suma==0) {
				cout << "Inserta el minuendo, luego sustraendo" << endl;
				cin >> m >> sus;
				r = m-sus;
				hist[suma][0] = m;
				histchar[suma] = operador;
				hist[suma][1] = sus;
				hist[suma][2] = r;
			} else {
				cout << "Inserte sustraendo" << endl;
				cin >> sus;
				r = ans-sus;
				hist[suma][0] = ans;
				histchar[suma] = operador;
				hist[suma][1] = sus;
				hist[suma][2] = r;
			}
			cout << "Resultado: " << r << endl;
			suma = suma+1;
			ans = r;
			break;
		case 'x':
			if (suma==0) {
				cout << "Inserte los factores" << endl;
				cin >> f1 >> f2;
				r = f1*f2;
				hist[suma][0] = f1;
				histchar[suma] = operador;
				hist[suma][1] = f2;
				hist[suma][2] = r;
			} else {
				cout << "Inserte factor" << endl;
				cin >> f2;
				r = ans*f2;
				hist[suma][0] = ans;
				histchar[suma] = operador;
				hist[suma][1] = f2;
				hist[suma][2] = r;
			}
			cout << "Resultado: " << r << endl;
			suma = suma+1;
			ans = r;
			break;
		case '/':
			if (suma==0) {
				cout << "Inserte el dividendo, luego divisor" << endl;
				cin >> d1 >> d2;
				while (d2==0) {
					cout << "Inserte un divisor valido" << endl;
					cin >> d2;
				}
				r = d1/d2;
				hist[suma][0] = d1;
				histchar[suma] = operador;
				hist[suma][1] = d2;
				hist[suma][2] = r;
			} else {
				cout << "Inserte dividendo" << endl;
				cin >> d2;
				while (d2==0) {
					cout << "Inserte un divisor valido" << endl;
					cin >> d2;
				}
				r = ans/d2;
				hist[suma][0] = ans;
				histchar[suma] = operador;
				hist[suma][1] = d2;
				hist[suma][2] = r;
			}
			cout << "Resultado: " << r << endl;
			ans = r;
			suma = suma+1;
			break;
		case '^':
			if (suma==0) {
				cout << "Inserte la base, luegp el exponente" << endl;
				cin >> b >> e;
				r = pow(b,e);
				hist[suma][0] = b;
				histchar[suma] = operador;
				hist[suma][1] = e;
				hist[suma][2] = r;
			} else {
				cout << "Inserte exponente" << endl;
				cin >> e;
				r = pow(ans,e);
				hist[suma][0] = ans;
				histchar[suma] = operador;
				hist[suma][1] = e;
				hist[suma][2] = r;
			}
			cout << "Resultado: " << r << endl;
			ans = r;
			suma = suma+1;
			break;
		case 'r':
			if (suma==0) {
				cout << "Inserte el radicando, luego indice" << endl;
				cin >> rad >> ind;
				while (ind==0) {
					cout << "Ingrese un indice valido" << endl;
					cin >> ind;
				}
				while (rad<0) {
					cout << "Inserte un radicando valido" << endl;
					cin >> rad;
				}
				r = pow(rad,(1/ind));
				hist[suma][0] = rad;
				histchar[suma] = operador;
				hist[suma][1] = ind;
				hist[suma][2] = r;
				cout << "Resultado: " << r << endl;
				suma = suma+1;
				ans = r;
			} else {
				cout << "Inserte indice" << endl;
				cin >> ind;
				while (ind==0) {
					cout << "Ingrese un valor valido" << endl;
					cin >> ind;
				}
				if (ans<0) {
					cout << "Error" << endl;
					suma = 0;
					r = 0;
					ans = 0;
				} else {
					r = pow(ans,(1/ind));
					hist[suma][0] = ans;
					histchar[suma] = operador;
					hist[suma][1] = ind;
					hist[suma][2] = r;
					cout << "Resultado: " << r << endl;
					suma = suma+1;
					ans = r;
				}
			}
			break;
		case 'F':
			break;
		case 'A':
			if (suma!=0) {
				for (i=1;i<=suma;i++) {
					for (i2=1;i2<=3;i2++) {
						hist[i-1][i2-1] = 0;
						histchar[i-1] = "0";
					}
				}
			}
			suma = 0;
			ans = 0;
			break;
		case 'H':
			if (suma==0) {
				cout << "" << endl;
			} else {
				for (i=1;i<=suma;i++) {
					cout << i << ".- ";
					for (i2=1;i2<=3;i2++) {
						cout << hist[i-1][i2-1];
						if (i2==1) {
							cout << histchar[i-1];
						}
						if (i2==2) {
							cout << "=";
						}
					}
					cout << "" << endl;
				}
			}
			break;
		default:
			cout << "operación no valido, intente muevamente" << endl;
		}
		cout << "" << endl;
	} while (operador!='F');
	return 0;
}

