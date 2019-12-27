

#include "Bancario.cpp"

#include <iostream>

using namespace std;

string IntToStr_ (int i) {
	if (i == 0) return "";
	char a [2];
	a[0] = '0' + (i%10);
	a[1] = '\0';
	return IntToStr_(i/10) + string(a);
}

string IntToStr (int i) {
	if (i == 0) return "0";
	char a [2];
	a[0] = '0' + (i%10);
	a[1] = '\0';
	return IntToStr_(i/10) + string(a);
}

int main () {
 Bancario prueba;
 int a;
 prueba.incluir ("banco1" , "cuenta001", "00000000D");
 prueba.incluir ("banco1" , "cuenta002", "00000000D");
 prueba.incluir ("banco1" , "cuenta003", "00000000D");
 prueba.incluir ("banco1" , "cuenta004", "00000000D");
 prueba.incluir ("banco1" , "cuenta004", "00000000D");
 prueba.incluir ("banco1" , "cuenta004", "00000000D");
 prueba.incluir ("banco1" , "cuenta001", "00000001D");
 prueba.incluir ("banco1" , "cuenta002", "00000001D");
 prueba.incluir ("banco1" , "cuenta003", "00000001D");
 prueba.incluir ("banco1" , "cuenta001", "00000002D");
 prueba.incluir ("banco1" , "cuenta002", "00000002D");
 prueba.incluir ("banco1" , "cuenta001", "00000003D");
 prueba.incluir ("banco1" , "cuenta001", "00000004D");

 prueba.incluir ("banco2" , "cuenta001", "00000000D");
 prueba.incluir ("banco2" , "cuenta002", "00000000D");
 prueba.incluir ("banco2" , "cuenta003", "00000000D");
 prueba.incluir ("banco2" , "cuenta004", "00000000D");
 prueba.incluir ("banco2" , "cuenta004", "00000000D");
 prueba.incluir ("banco2" , "cuenta004", "00000000D");
 prueba.incluir ("banco2" , "cuenta001", "00000001D");
 prueba.incluir ("banco2" , "cuenta002", "00000001D");
 prueba.incluir ("banco2" , "cuenta003", "00000001D");
 prueba.incluir ("banco2" , "cuenta001", "00000002D");
 prueba.incluir ("banco2" , "cuenta002", "00000002D");
 prueba.incluir ("banco2" , "cuenta001", "00000003D");
 prueba.incluir ("banco2" , "cuenta001", "00000004D");

 prueba.consulta_titulares( "banco1", "cuenta001");

 prueba.consulta_titulares( "banco2", "cuenta001");

// cin >> a;
 prueba.consulta_cuentas( "00000000D");
// cin >> a;
 prueba.elimina_cuenta ( "banco1", "cuenta001");
// cin >> a;
 prueba.consulta_titulares( "banco1", "cuenta001");
 prueba.consulta_titulares( "banco2", "cuenta001");

for (int i = 0; i < 1000; i++) {
prueba.incluir(IntToStr(i / 100), IntToStr(i/10), IntToStr(i%10));
cout << "Añadido " << IntToStr(i / 100) << " " << IntToStr(i/10) << " " <<  IntToStr(i%10) << endl;
//prueba.elimina_cuenta("1", "1");
} 

for (int i = 0; i < 1000; i+=10) {
prueba.consulta_titulares(IntToStr(i / 100), IntToStr(i/10));
} 

for (int i = 0; i < 10; i++) {
prueba.consulta_cuentas(IntToStr(i));
} 



for (int i = 0; i < 1000; i++) {
prueba.elimina_cuenta(IntToStr(i / 100), IntToStr(i/10));
cout << "Eliminado " << IntToStr(i / 100) << " " <<  IntToStr(i/10) << endl;
//prueba.elimina_cuenta("1", "1");
} 



for (int i = 0; i < 1000; i+=10) {
prueba.consulta_titulares(IntToStr(i / 100), IntToStr(i/10));
} 

for (int i = 0; i < 10; i++) {
prueba.consulta_cuentas(IntToStr(i));
} 


}



