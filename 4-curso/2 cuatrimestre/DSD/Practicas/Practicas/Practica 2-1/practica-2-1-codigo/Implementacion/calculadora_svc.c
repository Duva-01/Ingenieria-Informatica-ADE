/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static calc_res *
_sumar_1 (Operacion  *argp, struct svc_req *rqstp)
{
	return (sumar_1_svc(*argp, rqstp));
}

static calc_res *
_restar_1 (Operacion  *argp, struct svc_req *rqstp)
{
	return (restar_1_svc(*argp, rqstp));
}

static calc_res *
_multiplicar_1 (Operacion  *argp, struct svc_req *rqstp)
{
	return (multiplicar_1_svc(*argp, rqstp));
}

static calc_res *
_dividir_1 (Operacion  *argp, struct svc_req *rqstp)
{
	return (dividir_1_svc(*argp, rqstp));
}

static calc_res_vec *
_op_compleja_server_1 (vOper  *argp, struct svc_req *rqstp)
{
	return (op_compleja_server_1_svc(*argp, rqstp));
}

static calc_res_vec *
_op_vectores_server_1 (op_vectores_server_1_argument *argp, struct svc_req *rqstp)
{
	return (op_vectores_server_1_svc(argp->arg1, argp->arg2, argp->arg3, rqstp));
}

static void
op_basica_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		Operacion sumar_1_arg;
		Operacion restar_1_arg;
		Operacion multiplicar_1_arg;
		Operacion dividir_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case SUMAR:
		_xdr_argument = (xdrproc_t) xdr_Operacion;
		_xdr_result = (xdrproc_t) xdr_calc_res;
		local = (char *(*)(char *, struct svc_req *)) _sumar_1;
		break;

	case RESTAR:
		_xdr_argument = (xdrproc_t) xdr_Operacion;
		_xdr_result = (xdrproc_t) xdr_calc_res;
		local = (char *(*)(char *, struct svc_req *)) _restar_1;
		break;

	case MULTIPLICAR:
		_xdr_argument = (xdrproc_t) xdr_Operacion;
		_xdr_result = (xdrproc_t) xdr_calc_res;
		local = (char *(*)(char *, struct svc_req *)) _multiplicar_1;
		break;

	case DIVIDIR:
		_xdr_argument = (xdrproc_t) xdr_Operacion;
		_xdr_result = (xdrproc_t) xdr_calc_res;
		local = (char *(*)(char *, struct svc_req *)) _dividir_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
op_compleja_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		vOper op_compleja_server_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OP_COMPLEJA_SERVER:
		_xdr_argument = (xdrproc_t) xdr_vOper;
		_xdr_result = (xdrproc_t) xdr_calc_res_vec;
		local = (char *(*)(char *, struct svc_req *)) _op_compleja_server_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
op_vectores_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		op_vectores_server_1_argument op_vectores_server_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OP_VECTORES_SERVER:
		_xdr_argument = (xdrproc_t) xdr_op_vectores_server_1_argument;
		_xdr_result = (xdrproc_t) xdr_calc_res_vec;
		local = (char *(*)(char *, struct svc_req *)) _op_vectores_server_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (OP_BASICA, DIRVER);
	pmap_unset (OP_COMPLEJA, DIRVER);
	pmap_unset (OP_VECTORES, DIRVER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, OP_BASICA, DIRVER, op_basica_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (OP_BASICA, DIRVER, udp).");
		exit(1);
	}
	if (!svc_register(transp, OP_COMPLEJA, DIRVER, op_compleja_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (OP_COMPLEJA, DIRVER, udp).");
		exit(1);
	}
	if (!svc_register(transp, OP_VECTORES, DIRVER, op_vectores_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (OP_VECTORES, DIRVER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, OP_BASICA, DIRVER, op_basica_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (OP_BASICA, DIRVER, tcp).");
		exit(1);
	}
	if (!svc_register(transp, OP_COMPLEJA, DIRVER, op_compleja_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (OP_COMPLEJA, DIRVER, tcp).");
		exit(1);
	}
	if (!svc_register(transp, OP_VECTORES, DIRVER, op_vectores_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (OP_VECTORES, DIRVER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
