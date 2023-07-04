.section .data
lista:       .int 0x10000000,10,12 
longlista:    .int   (.-lista)/4
resultado:    .quad   0     # cambiamos de int(x32) a quad(x64) 
  formato:     .asciz    "suma = %lu = 0x%lx hex\n"

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
    jnc      no_acarreo
    inc      %edx

no_acarreo:
    inc   %rsi
    cmp   %rsi,%rcx
    jne    bucle

    ret
    
imprim_C:            # requiere libC
    mov   $formato, %rdi
    mov   resultado,%rsi
    mov   resultado,%rdx
    mov          $0,%eax    # varargin sin xmm
    call  printf        # == printf(formato, res, res);
    ret

acabar_C:            # requiere libC
    mov  resultado, %rdi
    call _exit        # ==  exit(resultado)
    ret
