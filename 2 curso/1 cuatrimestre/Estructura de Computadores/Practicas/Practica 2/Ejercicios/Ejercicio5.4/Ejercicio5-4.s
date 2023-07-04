.section .data

#ifndef TEST
#define TEST 20
#endif
    .macro linea
#if TEST==1
        .int 1, 2, 1, 2
#elif TEST==2
        .int -1, -2, -1, -2
#elif TEST==3
        .int 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF
#elif TEST==4
        .int 0x80000000, 0x80000000, 0x80000000, 0x80000000
#elif TEST==5
        .int 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
#elif TEST==6
        .int 2000000000, 2000000000, 2000000000, 2000000000
#elif TEST==7
        .int 3000000000, 3000000000, 3000000000, 3000000000 
#elif TEST==8
        .int -2000000000, -2000000000, -2000000000, -2000000000
#elif TEST==9
        .int -3000000000, -3000000000, -3000000000, -3000000000
#elif TEST==10
        .int 0, 2, 1, 1
#elif TEST==11
        .int 1, 2, 1, 1
#elif TEST==12
        .int 8, 2, 1, 1
#elif TEST==13
        .int 15, 2, 1, 1
#elif TEST==14
        .int 16, 2, 1, 1
#elif TEST==15
        .int 0, 2, -1, -1
#elif TEST==16
        .int -1, -2, -1, -1
#elif TEST==17
        .int -8, -2, -1, -1
#elif TEST==18
        .int -15, -2, -1, -1
#elif TEST==19
        .int -16, -2, -1, -1
#else
    .error "Definir TEST entre 1..19"
#endif
    .endm

lista: .irpc i, 1234
                linea
        .endr  

longlista:	.int   (.-lista)/4

resultado:	.quad   0
formato: 	.ascii "Media (decimal) = %11d \t Resto (decimal) = %11d\n"
		.ascii "Media (Hexadecimal) = [0x %08x] \t Resto (Hexadecimal)= [0x %08x]\n"

cociente: .int 0
resto: .int 0

.section .text
#_start: .global _start
 main: .global  main

	call trabajar	# subrutina de usuario
	call imprim_C	# printf()  de libC
	call acabar_C	# exit()    de libC
	ret

trabajar:
	mov  $lista, %rdi #Mueve la primera posicion de memoria lista al registro %rbx
	mov  longlista, %rsi #Mueve la longitud de la lista al registro %ecx
	call suma		# == suma(&lista, longlista);

	
	call media
	mov %eax, cociente
	mov %edx, resto
	

imprim_C:


	mov   $formato, %rdi
	mov   cociente,%esi
	mov   resto,%edx
	mov   %rax, %rcx			
	mov   %edx, %r8d

	mov   $0,%eax	
	call  printf		# == printf(formato, res, res);

acabar_C:			# requiere libC

	#mov  resultado, %edi
	movl $1, %eax
	xor %ebx, %ebx
	int $0x80 # int $0x80, en caso de que %eax valga 1, termina ejecucion y retorna %ebx

#EDX:EAX
suma:

	mov	 $0, %rcx # inicializo el indice
	mov  $0, %r8d # acumulador(no significativo) 
	mov  $0, %r9d # acumulador(significativo)
	mov  $0, %rdx
	mov  $0, %rax

bucle:

	mov (%rdi,%rcx,4), %eax #eax=Lista[i]
	cltd # cdq // Coge eax y lo amplia a edx con el signo.
	
	add %eax, %r8d
	adc %edx, %r9d

	inc %rcx # incrementar el indice

	cmp %rsi, %rcx # comparar indice con longitud
	jne bucle

	mov %r8d, %eax # Una vez acabado el bucle retornar los acmuladores %eax y %edx
	mov %r9d, %edx

	mov $0, %r8d
	mov $0, %r9d

	ret # retornar

media:

	idiv %esi # Siempre actua en edx:eax
	ret
