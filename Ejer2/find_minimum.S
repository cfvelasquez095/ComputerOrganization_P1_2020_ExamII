#import "libc.so.6":libc
#set dword[0x10000000] = [7, 5, 3, 4, 6, 9]
#set dword[0x10000024] = [4, 4, 4, 4, 4, 4]
#set dword[0x10000048] = [9, 7, 5, 3, 2, 1]
#set dword[0x10000072] = [1, 2, 3, 5, 7, 9]
#set dword[0x10000096] = [9, 7]
#set dword[0x10000104] = [7, 9]
#set byte[0x10000112] = ["%d",10]


call main
#stop

find_minimum:
    push    ebp
    mov     ebp, esp
    sub     esp, 4

    mov     dword[ebp-4], 0         ; int i = 0

    mov     eax, dword[ebp+12]      ; eax = size

    cmp     eax, 0                  ; if size == 0
    je      if_zero
    cmp     eax, 1                  ; if size == 1
    je      if_one

    mov     ebx, dword[ebp-4]
    push    ebx
    jmp     while
while:
    mov     eax, dword[ebp+12]      ; eax = size
    mov     ebx, dword[ebp-4]       ; ecx = i
    sub     eax, 1                  ; ecx = size - 1
    cmp     ebx, eax                ; if i < (size-1)
    jge     end_while               ; if i is not < (size-1) end while

    mov     eax, dword[ebp+8]       ; int v[]
    mov     ebx, dword[ebp-4]       ; i
    mov     ecx, dword[eax+ebx*4+4] ; v[i+1]
    mov     edx, dword[eax+ebx*4]   ; v[i]
    cmp     ecx, edx                ; if v[i+1] < v[i]
    jge     end_while               ; if v[i+1] is not < v[i] end while
    
    add     ebx, 1
    mov     [ebp-4], ebx             ; update i
    jmp     while
if_zero:
    mov     eax, -1
    jmp     end
if_one:
    mov     eax, 0
    jmp     end
end_while:
    mov     eax, dword[ebp-4]
    add     esp, 4
    jmp     end
end:
    leave
    ret
void_test:
    push    ebp
    mov     ebp, esp
    mov     eax, dword[ebp+8]       ; eax = int arr[]
    mov     ebx, dword[ebp+12]      ; ebx = size
    push    ebx
    push    eax
    call    find_minimum
    push    eax
    push    0x10000112
    call @libc.printf:"p,si32"
    leave
    ret
main:
    push    ebp
    mov     ebp, esp

    push    6                       ; size of arr1
    push    0x10000000              ; push arr1
    call    void_test
;------------------------------------------------;
    push    6                       ; size of arr2
    push    0x10000024
    call    void_test
;------------------------------------------------;
    push    6                       ; size of arr3
    push    0x10000048
    call    void_test
;------------------------------------------------;
    push    6                       ; size of arr4
    push    0x10000072
    call    void_test
;------------------------------------------------;
    push    2                       ; size of arr5
    push    0x10000096
    call    void_test
;------------------------------------------------;
    push    2                       ; size of arr6
    push    0x10000104
    call    void_test

    leave
    ret