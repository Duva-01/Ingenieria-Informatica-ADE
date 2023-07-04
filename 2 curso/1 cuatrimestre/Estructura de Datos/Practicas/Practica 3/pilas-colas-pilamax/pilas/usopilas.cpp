#include <iostream>
#include <pila.h>

using namespace std;

int main(){

  Pila <int> p;
  int i;

  for ( i=0; i<10 ; i++) 
    p.poner(i);
   
  int x = p.tope();
  cout << x << endl;
     
  p.quitar();

  int y = p.tope();
  cout << y << endl;

  Pila <float> q;
  int j;
  
  for ( j=0; j<10 ; j++) 
    q.poner(j/10.0);
   
  float z = q.tope();
  cout << z << endl;
     
  q.quitar();

  float w = q.tope();
  cout << w << endl;

  Pila <char> pc;
  char k;

  for ( k='a'; k<='z' ; k++) 
    pc.poner(k);

  char zz = pc.tope();
  cout << zz << endl;

  pc.quitar();

  char ww = pc.tope();
  cout << ww << endl;
  
  cout << pc.num_elementos() << endl;

  return 0;
}
