.include "p24Fxxxx.inc"
.global __reset
.bss

src: .space 2
dst: .space 2
len: .space 2
 
    .text
__reset:
    mov #__SP_init, W15
    mov #__SPLIM_init,W0
    mov W0, SPLIM
    
    .equ SOURCE, 0x0900
    .equ DESTINATION, 0x0980
    .equ LENGTH, 10
    
    ;initalizes values at the start of the program
init:
    mov #SOURCE, W1
    mov W1, src
    mov #DESTINATION, W2
    mov W2, dst
    mov #LENGTH, W0
    mov WREG, len
    bra z, done
    
    
    
loop:
    mov [W1++], [W2++]
    dec W0, W0
    bra z, done 
    goto loop
    
done:
    goto done
    .end
    

