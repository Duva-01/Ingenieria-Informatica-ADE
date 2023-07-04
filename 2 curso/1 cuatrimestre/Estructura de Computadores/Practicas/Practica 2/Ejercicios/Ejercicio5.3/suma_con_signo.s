.section .data

#ifndef TEST
#define TEST 11
#endif
    .macro linea
#if TEST==1
        .int -1
#elif TEST==2
        .int 0x04000000
#elif TEST==3
        .int 0x08000000
#elif TEST==4
        .int 0x10000000
#elif TEST==5
        .int 0x7FFFFFFF
#elif TEST==6
        .int 0x80000000
#elif TEST==7
        .int 0xF0000000
#elif TEST==8
        .int 0xF8000000
#elif TEST==9
        .int 0xF7FFFFFF
#elif TEST==10
        .int 100000000

#else
    .error "Definir TEST entre 1..19"
#endif
    .endm

lista: .irpc i, 1234567812345678
                linea
        .endr  

longlista:    .int   (.-lista)/4
resultado:    .quad   0     # cambiamos de int(x32) a quad(x64) 
formato:    .ascii "resultado \t = %18lld (sgn)\n"
            .ascii        "\t\t = 0x%18llx (hex)\n"
            .asciz        "\t\t = 0x  %08x %08x\n"

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
    mov  $0, %r8d
    mov  $0, %r9d

bucle:

    mov   (%rbx,%rsi,4), %eax  
    cltd

    add %eax, %r8d
    adc %edx, %r9d

    inc   %rsi
    cmp   %rsi,%rcx
    jne    bucle

    mov %r8d, %eax
    mov %r9d, %edx

    ret
    
imprim_C:            # requiere libC
    mov   $formato, %rdi
    mov   resultado,%rsi
    mov   resultado,%rdx
    mov   resultado + 4,%rcx
    mov          $0,%eax    # varargin sin xmm
    call  printf        # == printf(formato, res, res);
    ret

acabar_C:            # requiere libC
    mov  resultado, %rdi
    call _exit        # ==  exit(resultado)
    ret
