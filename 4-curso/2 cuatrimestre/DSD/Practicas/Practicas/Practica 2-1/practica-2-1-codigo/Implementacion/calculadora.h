/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCULADORA_H_RPCGEN
#define _CALCULADORA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct Operacion {
	int a;
	char operador;
	int b;
};
typedef struct Operacion Operacion;

typedef struct {
	u_int vOper_len;
	Operacion *vOper_val;
} vOper;

typedef struct {
	u_int resVec_len;
	double *resVec_val;
} resVec;

struct calc_res {
	int errno;
	union {
		double resultado;
	} calc_res_u;
};
typedef struct calc_res calc_res;

struct calc_res_vec {
	int errno;
	union {
		resVec resultado;
	} calc_res_vec_u;
};
typedef struct calc_res_vec calc_res_vec;

#define OP_BASICA 0x20000155
#define DIRVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define SUMAR 1
extern  calc_res * sumar_1(Operacion , CLIENT *);
extern  calc_res * sumar_1_svc(Operacion , struct svc_req *);
#define RESTAR 2
extern  calc_res * restar_1(Operacion , CLIENT *);
extern  calc_res * restar_1_svc(Operacion , struct svc_req *);
#define MULTIPLICAR 3
extern  calc_res * multiplicar_1(Operacion , CLIENT *);
extern  calc_res * multiplicar_1_svc(Operacion , struct svc_req *);
#define DIVIDIR 4
extern  calc_res * dividir_1(Operacion , CLIENT *);
extern  calc_res * dividir_1_svc(Operacion , struct svc_req *);
extern int op_basica_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SUMAR 1
extern  calc_res * sumar_1();
extern  calc_res * sumar_1_svc();
#define RESTAR 2
extern  calc_res * restar_1();
extern  calc_res * restar_1_svc();
#define MULTIPLICAR 3
extern  calc_res * multiplicar_1();
extern  calc_res * multiplicar_1_svc();
#define DIVIDIR 4
extern  calc_res * dividir_1();
extern  calc_res * dividir_1_svc();
extern int op_basica_1_freeresult ();
#endif /* K&R C */

#define OP_COMPLEJA 0x20000156
#define DIRVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define OP_COMPLEJA_SERVER 1
extern  calc_res_vec * op_compleja_server_1(vOper , CLIENT *);
extern  calc_res_vec * op_compleja_server_1_svc(vOper , struct svc_req *);
extern int op_compleja_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define OP_COMPLEJA_SERVER 1
extern  calc_res_vec * op_compleja_server_1();
extern  calc_res_vec * op_compleja_server_1_svc();
extern int op_compleja_1_freeresult ();
#endif /* K&R C */

struct op_vectores_server_1_argument {
	resVec arg1;
	resVec arg2;
	int arg3;
};
typedef struct op_vectores_server_1_argument op_vectores_server_1_argument;

#define OP_VECTORES 0x20000157
#define DIRVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define OP_VECTORES_SERVER 1
extern  calc_res_vec * op_vectores_server_1(resVec , resVec , int , CLIENT *);
extern  calc_res_vec * op_vectores_server_1_svc(resVec , resVec , int , struct svc_req *);
extern int op_vectores_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define OP_VECTORES_SERVER 1
extern  calc_res_vec * op_vectores_server_1();
extern  calc_res_vec * op_vectores_server_1_svc();
extern int op_vectores_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_Operacion (XDR *, Operacion*);
extern  bool_t xdr_vOper (XDR *, vOper*);
extern  bool_t xdr_resVec (XDR *, resVec*);
extern  bool_t xdr_calc_res (XDR *, calc_res*);
extern  bool_t xdr_calc_res_vec (XDR *, calc_res_vec*);
extern  bool_t xdr_op_vectores_server_1_argument (XDR *, op_vectores_server_1_argument*);

#else /* K&R C */
extern bool_t xdr_Operacion ();
extern bool_t xdr_vOper ();
extern bool_t xdr_resVec ();
extern bool_t xdr_calc_res ();
extern bool_t xdr_calc_res_vec ();
extern bool_t xdr_op_vectores_server_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCULADORA_H_RPCGEN */
