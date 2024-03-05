section .data
    title db 'Program 2 - float program', 0xA, 0xD
    title_len equ $ - title
    
    prompt_name db 'Enter your name: ', 0xA, 0xD
    prompt_name_len equ $ - prompt_name
    
    greet_msg db 'Hello, ', 0xA, 0xD
    greet_msg_len equ $ - greet_msg
    
    instructions db 'Instructions: Enter floating point numbers in the range [e, π] or [17, 41]', 0xA, 0xD
    instructions_len equ $ - instructions
    
    invalid_msg db 'Invalid input. Please enter a number in the specified range.', 0xA, 0xD
    invalid_msg_len equ $ - invalid_msg
    
    max_numbers equ 10 ; or whatever maximum number of inputs you want

section .bss
    user_name resb 64
    valid_numbers resq max_numbers ; array to store valid numbers
    valid_count resq 1
    sum resq 1
    max_num resq 1
    min_num resq 1
    average resq 1
    input_buffer resb 16 ; buffer to read user input
    
section .text
    global _start

_start:
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
    mov edx, prompt_name_len
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
    mov edx, greet_msg_len
    int 80h
    
    ; Display instructions
    mov eax, 4
    mov ebx, 1
    mov ecx, instructions
    mov edx, instructions_len
    int 80h
    
    ; Initialize variables
    mov qword [valid_count], 0
    mov qword [sum], 0
    mov qword [max_num], 0
    mov qword [min_num], 999999999999 ; initialize to a large number
    
    ; Loop to read and process numbers
read_loop:
    ; Prompt user for input
    mov eax, 4
    mov ebx, 1
    mov ecx, input_prompt
    mov edx, input_prompt_len
    int 80h
    
    ; Read user input
    mov eax, 3 ; sys_read
    mov ebx, 0 ; stdin
    mov ecx, input_buffer
    mov edx, 16 ; buffer size
    int 80h
    
    ; Convert input to float
    fld qword [input_buffer]
    
    ; Check if input is within valid range
    fldpi ; load π
    fldl2e ; load e
    fcomp ; compare with e
    fstsw ax
    sahf
    ja invalid_input_e ; if input > e, jump to invalid_input_e
    fcomip st0, st1 ; compare with π
    ja invalid_input_pi ; if input > π, jump to invalid_input_pi
    fld qword [input_buffer]
    fcomi ; compare with 17
    jb invalid_input_17 ; if input < 17, jump to invalid_input_17
    fld qword [input_buffer]
    fcomi ; compare with 41
    ja invalid_input_41 ; if input > 41, jump to invalid_input_41
    
    ; Input is valid, store it
    mov eax, [valid_count]
    mov edx, 8
    imul edx
    add edx, valid_numbers
    fstp qword [edx] ; store the valid number
    inc qword [valid_count] ; increment valid count
    
    ; Update sum
    fld qword [sum]
    fadd qword [input_buffer]
    fstp qword [sum]
    
    ; Update max number
    fld qword [max_num]
    fcomip st0, st1
    jnae not_greater_than_max
    fstp qword [max_num]
not_greater_than_max:
    
    ; Update min number
    fld qword [min_num]
    fcomip st0, st1
    jb not_less_than_min
    fstp qword [min_num]
not_less_than_min:
    
    ; Continue loop if less than max numbers
    mov eax, [valid_count]
    cmp eax, max_numbers
    jl read_loop
    
    ; Calculate average
    mov eax, [valid_count]
    mov edx, [sum]
    cdq ; convert double to integer
    idiv qword [average]
    
    ; Display results
    ; Display count of validated numbers entered
    mov eax, 4
    mov ebx, 1
    mov ecx, valid_count_msg
    mov edx, valid_count_msg_len
    int 80h
    
    ; Display values entered, 10 per line
    mov eax, 4
    mov ebx, 1
    mov ecx, valid_numbers
    mov edx, [valid_count]
    call display_numbers
    
    ; Display sum of valid numbers
    mov eax, 4
    mov ebx, 1
    mov ecx, sum_msg
    mov edx, sum_msg_len
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, [sum]
    call print_float
    
    ; Display max valid user value entered
    mov eax, 4
    mov ebx, 1
    mov ecx, max_num_msg
    mov edx, max_num_msg_len
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, [max_num]
    call print_float
    
    ; Display min valid user value entered
    mov eax, 4
    mov ebx, 1
    mov ecx, min_num_msg
    mov edx, min_num_msg_len
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, [min_num]
    call print_float
    
    ; Display average
    mov eax, 4
    mov ebx, 1
    mov ecx, average_msg
    mov edx, average_msg_len
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, [average]
    call print_float
    
    ; Display parting message with the user's name
    mov eax, 4
    mov ebx, 1
    mov ecx, parting_msg
    mov edx, parting_msg_len
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, user_name
    mov edx, 64
    int 80h
    
    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 80h

print_float:
    pusha
    
    fld qword [ecx]
    fstp qword [esp - 8]
    
    mov eax, 2 ; sys_write
    mov ebx, 1 ; stdout
    lea ecx, [esp - 8]
    mov edx, 8 ; length of floating point number
    int 80h
    
    popa
    ret

display_numbers:
    pusha
    
    mov eax, [edx]
    mov ecx, 0
    
print_loop:
    fld qword [eax + ecx * 8]
    fstp qword [esp - 8]
    
    mov eax, 2 ; sys_write
    mov ebx, 1 ; stdout
    lea ecx, [esp - 8]
    mov edx, 8 ; length of floating point number
    int 80h
    
    inc ecx
    cmp ecx, 10
    jne print_loop
    
    popa
    ret

invalid_input_e:
    ; Display invalid input message for e
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, invalid_msg_len
    int 80h
    jmp read_loop

invalid_input_pi:
    ; Display invalid input message for π
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, invalid_msg_len
    int 80h
    jmp read_loop

invalid_input_17:
    ; Display invalid input message for 17
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, invalid_msg_len
    int 80h
    jmp read_loop

invalid_input_41:
    ; Display invalid input message for 41
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, invalid_msg_len
    int 80h
    jmp read_loop

section .rodata
    input_prompt db 'Enter a floating point number: ', 0xA, 0xD
    input_prompt_len equ $ - input_prompt
    
    valid_count_msg db 'Count of validated numbers entered: ', 0xA, 0xD
    valid_count_msg_len equ $ - valid_count_msg
    
    sum_msg db 'Sum of valid numbers: ', 0xA, 0xD
    sum_msg_len equ $ - sum_msg
    
    max_num_msg db 'Maximum valid user value entered: ', 0xA, 0xD
    max_num_msg_len equ $ - max_num_msg
    
    min_num_msg db 'Minimum valid user value entered: ', 0xA, 0xD
    min_num_msg_len equ $ - min_num_msg
    
    average_msg db 'Average of valid numbers: ', 0xA, 0xD
    average_msg_len equ $ - average_msg
    
    parting_msg db 'Goodbye, ', 0xA, 0xD
    parting_msg_len equ $ - parting_msg

