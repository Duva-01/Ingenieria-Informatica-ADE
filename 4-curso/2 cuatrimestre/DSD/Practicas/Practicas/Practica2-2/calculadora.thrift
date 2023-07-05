struct Operacion {

   1: required double a ;
   2: required string operador ;
   3: required double b ;
}

service Calculadora{

   void ping(),

   double suma(1:double num1, 2:double num2),
   double resta(1:double num1, 2:double num2),
   double multiplicacion(1:double num1, 2:double num2),
   double division(1:double num1, 2:double num2),

   list<double> operacionCompuesta(1:list<Operacion> lista),

   list<double> operacionVectores(1:list<double> vec1, 2:list<double> vec2, 3:i32 opcion),

   list<list<double>> operacionMatrices(1:list<list<double>> mat1, 2:list<list<double>> mat2, 3:i32 opcion),

   double exponente(1:double num1, 2:double num2),
}
