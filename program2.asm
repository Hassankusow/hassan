extern printf
extern scanf

section .data
    title db 'Program 2 - float program', 0xA, 0xD
    title_len equ $ - title
    
    prompt_name db 'Enter your name: ', 0xA, 0xD
    
    
    greet_msg db 'Hello, ', 0xA, 0xD
    
    
    instructions db 'Instructions: Enter floating point numbers in the range [e, π] or [17, 41]', 0xA, 0xD
    instructions_len equ $ - instructions
    
    invalid_msg db 'Invalid input. Please enter a number in the specified range.', 0xA, 0xD
    invalid_msg_len equ $ - invalid_msg
    newline db 10
    
    max_numbers dw 10 
    exit_value dq 0.0
    e dq 2.71828
    num1 dq 17.0
    num2 dq 41.0
    

section .bss
    user_name resb 64
    valid_numbers resq 10 ; array to store valid numbers
    valid_count resq 1
    sum resq 1
    max_num resq 1
    min_num resq 1
    average resq 1
    input_buffer resb 16 ; buffer to read user inputa
    
    
section .text
    global main

main:
    ; Display title and programmer's name
    mov eax, 4
    mov ebx, 1
    mov ecx, title
    mov edx, title_len
    int 80h
    
    ; Get user's name
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt_name
    mov edx, 17
    int 80h
    
    ; Read user's name
    mov eax, 3
    mov ebx, 0
    mov ecx, user_name
    mov edx, 64
    int 80h
    
    ; Greet the user
    mov eax, 4
    mov ebx, 1
    mov ecx, greet_msg
    mov edx, 7
    int 80h

    ;
    mov eax, 4
    mov ebx, 1
    mov ecx, user_name
    mov edx, 10
    int 80h
    
    ; Display instructions
    mov eax, 4
    mov ebx, 1
    mov ecx, instructions
    mov edx, instructions_len
    int 80h
    
    ; Initialize variables
    mov dword [valid_count], 0
    mov dword [sum], 0
    mov dword [max_num], 0
    mov dword [min_num], 999999 ; initialize to a large number
    
    ; Loop to read and process numbers
read_loop:
    
    finit
    push dword input_prompt
    call printf
    add esp, 4
    push dword input_buffer
    push dword input_data
    call scanf
    add esp, 8

    

    fld qword [input_buffer]
    fld qword [e]
    
    fcomip
    ja invalid_input
    
    fldpi
    fcomip
    ja valid_input
    
    fld qword [num1]
    fcomip
    ja invalid_input
   
    fld qword [num2]
    fcomip
    ja valid_input
    jmp invalid_input
    
     
    
valid_input: 
    ; Input is valid, store it
    ; inceremnt count wihtout adding to the stack
    inc dword [valid_count]
    
    
    ; Update sum
    fld qword [sum]
    fadd qword [input_buffer]
    fstp qword [sum]
    
    fld qword [input_buffer]
    ; Update max number
    fld qword [max_num]
    fcomip 
    ja not_greater_than_max
    fst qword [max_num]
not_greater_than_max:
    fstp dword [input_buffer]
    ; Update min number
    fld qword [input_buffer]
    fld qword [min_num]
    fcomip 
    jb not_less_than_min
    fst qword [min_num]
not_less_than_min:
    
    ; Continue loop if less than max numbers
    mov eax, [valid_count]
    cmp eax, [max_numbers]
    jl read_loop
    
    ; Calculate average
    fild dword [valid_count]
    fld qword [sum]
    fdiv st0,st1 
    fstp qword [average]

    
    jmp exit_program
invalid_input:
    ; Display invalid input message for e
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, invalid_msg_len
    int 80h
    jmp read_loop
exit_program:
    fld qword[average]
    push dword [average + 4]
    push dword [average]
    push dword input_data
    call printf
    add esp, 12
    push dword average_msg
    call printf
    add esp, 4
    
   
    fld qword[min_num]
    push dword [min_num +4]
    push dword [min_num + 4]
    push dword [min_num]
    push dword input_data
    call printf
    add esp, 16
    push dword min_num_msg
    call printf
    add esp, 4

   

    fld qword[max_num]
    push dword [max_num + 4]
    push dword [max_num]
    push dword input_data
    call printf
    add esp, 12
    
    push dword max_num_msg
    call printf
    add esp, 4
    
    

    
    fld qword[sum]
    push dword [sum + 4]
    push dword [sum]
    push dword input_data
    call printf
    add esp, 12
   
    push dword sum_msg
    call printf
    add esp, 4

    

    mov eax, 4
    mov ebx, 1
    mov ecx, parting_msg
    mov edx, 10
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, user_name
    mov edx, 10
    int 0x80

   
   ; Exit the program
   mov eax, 1
   int 80h

section .rodata
    input_prompt db 'Enter a floating point number: ', 0
    input_data db '%lf', 0
    
    
    valid_count_msg db 'Count of validated numbers entered: ' ,0
    sum_msg db ' is the sum ' ,10,0
    max_num_msg db ' is the max ' ,10 , 0
    min_num_msg db ' is the min ' ,10, 0
    average_msg db ' is the average ' ,10, 0
    parting_msg db "Goodbye, ",0
