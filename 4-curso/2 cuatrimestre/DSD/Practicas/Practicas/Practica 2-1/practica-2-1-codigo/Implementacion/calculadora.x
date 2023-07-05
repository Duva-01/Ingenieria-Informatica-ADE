struct Operacion {
    int a;
    char operador;
    int b;
};

typedef struct Operacion vOper<>; /* Polinomio (vector de operaciones) */
typedef double resVec<>;	/* vector de números */

/* la siguiente union se utiliza para discriminar entre llamadas con exito y llamadas con errores */
union calc_res switch (int errno) {
	case 0:
		double resultado;
	default:
		void; /* con error: nada */
};

/* la siguiente union se utiliza para discriminar entre llamadas con exito y llamadas con errores */
union calc_res_vec switch (int errno) {
	case 0:
		resVec resultado;
	default:
		void; /* con error: nada */
};

program OP_BASICA {
	version DIRVER {
		calc_res SUMAR(Operacion) = 1;
		calc_res RESTAR(Operacion) = 2;
		calc_res MULTIPLICAR(Operacion) = 3;
		calc_res DIVIDIR(Operacion) = 4;
	} =1;
} = 0x20000155;

program OP_COMPLEJA {
	version DIRVER {
		calc_res_vec OP_COMPLEJA_SERVER(vOper) = 1;
		
	} =1;
} = 0x20000156;

program OP_VECTORES {
	version DIRVER {
		calc_res_vec OP_VECTORES_SERVER(resVec, resVec, int) = 1;
		
	} =1;
} = 0x20000157;
