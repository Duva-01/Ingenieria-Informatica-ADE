/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_Operacion (XDR *xdrs, Operacion *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->operador))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_vOper (XDR *xdrs, vOper *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->vOper_val, (u_int *) &objp->vOper_len, ~0,
		sizeof (Operacion), (xdrproc_t) xdr_Operacion))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_resVec (XDR *xdrs, resVec *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->resVec_val, (u_int *) &objp->resVec_len, ~0,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_calc_res (XDR *xdrs, calc_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_double (xdrs, &objp->calc_res_u.resultado))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_calc_res_vec (XDR *xdrs, calc_res_vec *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_resVec (xdrs, &objp->calc_res_vec_u.resultado))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_op_vectores_server_1_argument (XDR *xdrs, op_vectores_server_1_argument *objp)
{
	 if (!xdr_resVec (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_resVec (xdrs, &objp->arg2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->arg3))
		 return FALSE;
	return TRUE;
}