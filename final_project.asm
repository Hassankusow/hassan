; hassan abdi 
;final project
;3/1/2024
;cs250
;x86 assembly nasm intel linux synthax

section .data
 ; my data section where my outputs and prompts and x o or _ is instilized 

 msg db 'This is MASTER MIND!', 0xA, 0
 msg_len equ $ - msg
 finish db 'Congratulations! You guessed the code' , 0xA, 0
 finish_len equ $ - finish
 ran_out db 'Sorry you run out of guesses! ', 0xA, 0
 ran_out_len equ $- ran_out
 correct_ans db ' is the correct answer! ' ,  0xA, 0
 correct_ans_len  equ $ - correct_ans
 instrct db 'Press 1 to start game or Press any number to exit ', 0
 instrct_len equ $ - instrct
 prompt_s db 'Enter your guess : ', 0
 prompt db 'Enter : ', 0
 ; i used a dev/urandom to get a random value where i need to pass in file name input i want to return count and size
 file db '/dev/urandom' ,0
 read db 'r' ,0
 s db ' %x, %x' ,0
 input db '%d' ,0
 g db '%06x' ,10,0
 input_hex db '%x',0
 
 
 mask dd 0x00f00000
 correct db 'x', 0
 not_correct db '_',0
    




    newline db  10, 0
    
    




;my.bbs dection wher are my valribles inputs sectret code and counters
section .bss
    buff resd 1
    guess resd 1
    cor   resd 1
    secrett resd 1
    count resd 1
    counterr resd 1
    counter resd 1

; my .text external things i am getting from complier gcc and beyond 
section .text
extern printf ; printf for priting 
extern scanf  ; scanf for input
extern fread  ; fread to read from file 
extern fopen  ; opening a file
extern fclose  ;clsoing a file 
; my code starts here with main:
global main

main:
    ; this couple of lines i am generating a secret code
    push dword read
    push dword file
    call fopen
    add esp, 8
    ; i used dev u random to get a rondom value it was stored in eax moved to ebx and called fread to get the input
    mov ebx, eax
    push  ebx
    push  1
    push  4
    push dword secrett
    call fread
    add esp, 4
     ;i procded to make to my value in secret to move to eax for i got 8 values wanted only 6 so did a bit shift to the right
     ; made another valrible correct short for cor and this keep to output if the person gueses the code or runs our of times to guess
    mov eax, [secrett]
    shr eax, 8
    mov [cor], eax
    mov [secrett], eax
    push eax
      
    ;push dword [secrett]
    ;push dword s
    ;call printf
     ;add esp, 12
    
    
    
        

    
    ; below is my instruction welcome and intizling my counters to zero or 20 for thats the amount i want to loop
    mov eax, 4          
    mov ebx, 1          
    mov ecx, msg       
    mov edx, msg_len      
    int 0x80

    
    mov eax, 4          
    mov ebx, 1          
    mov ecx, newline   
    mov edx, 2          
    int 0x80          

      
  
    mov eax, 4
    mov ebx, 1
    mov ecx, instrct
    mov edx, instrct_len
    int 0x80
    
    push dword prompt
    call printf
    add esp, 4
    push dword buff
    push dword input
    call scanf
    add esp, 8

   

    ;push dword [buff]
    ;push dword input
    ;call printf
    ;add esp, 8
    
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80
    
    mov eax, [buff]
    cmp eax, 1
    
    mov dword [count], 0
    jne exit_program
    mov dword [counterr],20
    mov dword [counter],0
input_loop:
    ; the start of my  loop right now i have a 1 value 6 hex stored in secrett
    ; this below gets my input in hex
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80
    inc dword [counter]
    push dword newline
    push dword prompt_s
    call printf
    add esp, 4
    push dword guess
    push dword input_hex
    call scanf
    add esp, 8

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80
    
    mov dword [count], 0
    mov edx, [mask] ; i used mask in a single out and  to bit shift to the right everytime i loop and and here is the varible 

    
    
loop:
    ; i used to assilate the the hex value i am intrest this loop loops 6 times and gets the value that secret and guess coline and i print x for it
    mov ebx, [guess]
    and ebx, edx
    

    
    ;push edx
    ;push ebx
    ;push dword g
    ;call printf
    ;add esp, 8
    ;pop edx
  
    
    mov ecx, [secrett]
    and ecx, edx
    ; now that i singles out using and/ nask i then procede to cmp the value of secret stored in ecx and and guess stored in ebx
    cmp ecx,ebx
    jne no_correct
    push edx
    push dword correct
    
    call printf
    add esp, 4

    jmp corect
no_correct:
    push edx
    push dword not_correct
    call printf
    add esp, 4
corect:
    pop edx
    ;push edx
    ;push ecx
    ;push dword g
    ;call printf
    ;add esp, 8
    ;pop edx

    ; below is my shifting to the right 4 times cause thats howmany bits i need to move for the second hex value for mask and guess
    inc dword [count]
    shr edx, 4
    shr ebx, 4
    cmp dword [count], 6

    ; and here is a comparison where compares 6 times cause that how many  hex values i have for my loop
    jl loop
    ; now that it looped 6 times then i procede to compare ecx to eax if secret and guess are the same 
    mov ecx, [secrett]
    mov eax, [guess]
    cmp ecx, eax
    je exit
    ; final compare is if i looped 20 times for input_loop if i did then it proceded to go to run_out function
    mov ecx, [counter]
    mov eax, [counterr]
    cmp ecx, eax
    je run_out
    jmp input_loop


run_out:
    ;run out function for if the user couldnt guess in 20 tries
    push dword ran_out
    call printf
    add esp, 4
    push dword [cor]
    push dword g
    call printf
    add esp, 12

    mov eax, 4
    mov ebx, 1
    mov ecx, correct_ans
    mov edx, correct_ans_len
    int 0x80
   
    jmp exit_program

exit:
    ; exit is for if the user guessed correctly and message pops up for him/her
    push dword finish
    call printf
    add esp, 4
    push dword [cor]
    push dword g
    call printf
    add esp, 12

    mov eax, 4
    mov ebx, 1
    mov ecx, correct_ans
    mov edx, correct_ans_len
    int 0x80

    
   
exit_program:
   mov eax, 1
   int 80h
