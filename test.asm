global main
extern printf
extern scanf
section .data
    msg db 'This is program 1!', 0xA, 0
    prompt_name db 'Enter your name: ', 0
    hello_msg db 'Hello, ', 0
    
    instrct db 'this program only takes negative numbers  [-200, -100] or [-50, -1] (inclusive) ', 0

    invalid_msg db 'Invalid number Please enter a negative number within the specified ranges.', 0
    good db 'Good job', 0
    
    prompt db 'Enter a number: ', 0
    input db '%d',0
    
    noValidMsg db 'No valid input received.', 0

    countMsg db 'Count: %i ', 0
    sumMsg db 'Sum: %i ',  0
    maxMsg db 'Max: %i ', 0
    minMsg db 'Min: %i ', 0
    avgMsg db 'Average: %i ', 0x0a 
    
   
   

    newline db 0xA, 0
    buffer db 100
    counter dd '0', 0
    
    



section .bss
    buff resd 1
    num resd 1       ; Number input by the user
    count resd 1     ; Counter for valid numbers
    sum resd 1       ; Sum of valid numbers
    average resd 1
    min resd 1
    max resd 1



section .text


main:
    
    ; Write the message to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, msg        ; pointer to the message
    mov edx, 20         ; message length
    int 0x80            ; invoke syscall

    ; Write the prompt for name to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, prompt_name     ; pointer to the prompt
    mov edx, 17        ; store the length in edx
    int 0x80            ; invoke syscall

    ; Read input from stdin
    mov eax, 3          ; Syscall number for sys_read
    mov ebx, 0          ; File descriptor 0 (stdin)
    mov ecx, buffer     ; Pointer to the buffer
    mov edx, 20         ; Maximum number of bytes to read
    int 0x80            ; invoke syscall

    ; Write "Hello, " to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, hello_msg  ; pointer to the "Hello, " message
    mov edx, 7          ; message length
    int 0x80            ; invoke syscall


    

    ; Write user's name to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, buffer     ; pointer to the buffer containing user input
    mov edx, 15        ; store the length in edx
    int 0x80            ; invoke syscall

    ; Write newline to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; pointer to the newline character
    mov edx, 2          ; newline length
    int 0x80            ; invoke syscall

    ; write the instructions to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, instrct
    mov edx, 80         
    int 0x80  

    ; Write newline to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; pointer to the newline character
    mov edx, 2          ; newline length
    int 0x80            ; invoke syscall

    
    
    mov dword [count], 0
    mov dword [sum], 0
    mov dword [max], -201
    mov dword [min], 0

input_loop:
    
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; pointer to the newline character
    mov edx, 2          ; newline length
    int 0x80            ; invoke syscall
   
    
    push dword prompt 
    call printf
    add esp, 4
    push dword buff
    push dword input
    call scanf
    add esp, 8

  

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80

    mov eax, [buff]
    cmp eax, 0
    jns exit_program
    
   
         

second_check:
    cmp eax, -200
    jl invalid_input   ; Jump if AL is less than -200
    cmp eax, -100
    jle valid_input     ; Jump if AL is less than -100
    cmp eax, -50
    jl invalid_input   ; Jump if AL is greater than -50
    jmp valid_input    ; Jump to valid_input if none of the above conditions are 
    
    
    

     
valid_input:
  
   
    mov eax, [buff]
    inc dword [count]
    
    add dword [sum], eax
    mov edx, [max]
    cmp eax, edx
    jl not_Max
    mov [max], eax
not_Max:
    mov edx, [min]
    cmp eax, edx
    jg not_Min
    mov [min], eax
not_Min:
     
    jmp input_loop

invalid_input:
    ; Write invalid message to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, invalid_msg ; pointer to the invalid message
    mov edx, 72         ; length of the message
    int 0x80            ; invoke syscall

    ; Write newline to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; pointer to the newline character
    mov edx, 2          ; newline length
    int 0x80            ; invoke syscall

    cmp al , '0'
    jne exit_program
    


    jmp input_loop     ; Repeat the loop for the next input



exit_program:
      ; Calculate and print average
    mov ecx, [count]
    mov eax, [sum]
    cdq
    idiv ecx
    mov [average] , eax  
    push dword [count]   ; Push the value of count onto the stack
    push countMsg        ; Push the format string onto the stack
    call printf          ; Call printf to print the message
    add esp, 8 
    
     ; Write newline to stdout
    mov eax, 4          ; sys_write syscall number
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; pointer to the newline character
    mov edx, 2          ; newline length
    int 0x80            ; invoke syscall
    
    ; display sum 
     
    push dword [sum]   ; Push the value of count onto the stack
    push sumMsg        ; Push the format string onto the stack
    call printf          ; Call printf to print the message
    add esp, 8

    ; Write newline to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80


    ; Display maximum valid value entered
    push dword [max]   ; Push the value of count onto the stack
    push maxMsg        ; Push the format string onto the stack
    call printf          ; Call printf to print the message
    add esp, 8


    ; Write newline to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80


    ; Display minimum valid value entered
    push dword [min]   ; Push the value of count onto the stack
    push minMsg        ; Push the format string onto the stack
    call printf          ; Call printf to print the message
    add esp, 8

    ; Write newline to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80


    ; Display average rounded to nearest integer
    push dword [average]   ; Push the value of count onto the stack
    push avgMsg        ; Push the format string onto the stack
    call printf          ; Call printf to print the message
    add esp, 8

    ; Write newline to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80

    
        ; Exit the program
    mov eax, 1          ; sys_exit syscall number
    xor ebx, ebx        ; exit code 0
    int 0x80            ; call kernel

exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80
