.section .data

#ifndef TEST
#define TEST 9
#endif
	.macro linea
#if TEST==1
		.int 1, 1, 1, 1
#elif TEST==2
		.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
#elif TEST==3
		.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif TEST==4
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
#elif TEST==5
		.int -1, -1, -1, -1 
#elif TEST==6
		.int 200000000, 200000000, 200000000, 200000000
#elif TEST==7
		.int 300000000, 300000000, 300000000, 300000000 
#elif TEST==8
		.int 500000000, 500000000, 500000000, 500000000
#else
	.error "Definir TEST entre 1..8"
#endif
	.endm

lista: .irpc i, 1234
				linea
		.endr  

longlista:    .int   (.-lista)/4
resultado:    .quad   0     # cambiamos de int(x32) a quad(x64) 
formato:    .ascii "Suma \t = %18lu (uns) \n"
            .ascii "\t\t = 0x%18lx (hex)\n"
            .asciz "\t\t = 0x %08x %08x\n"



.section .text
# _start: .global _start
main: .global  main

    call trabajar    # subrutina de usuario
    call imprim_C    # printf()  de libC
    call acabar_C    # exit()    de libC
    ret

trabajar:
    mov     $lista, %rbx
    mov  longlista, %ecx
    call suma        # == suma(&lista, longlista);
    mov  %eax, resultado
    mov  %edx, resultado + 4    # 4 posiciones detras de resultado
    ret

suma:
    mov  $0, %rsi  # contador de la suma
    mov  $0, %eax  # suma
    mov  $0, %edx  # acumulador de acarreo

bucle:
    add   (%rbx,%rsi,4), %eax  # %eax += 4 * %rsi + %rbx 
    adc   $0, %edx
    inc   %rsi
    cmp   %rsi,%rcx
    jne    bucle
    ret
    
imprim_C:            # requiere libC
    mov   $formato, %rdi
    mov   resultado,%rsi
    mov   resultado,%rdx
    mov   resultado,%rcx
    mov          $0,%eax    # varargin sin xmm
    call  printf        # == printf(formato, res, res);
    ret

acabar_C:            # requiere libC
    mov  resultado, %rdi
    call _exit        # ==  exit(resultado)
    ret
