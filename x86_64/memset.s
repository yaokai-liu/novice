# x64-64 assembly script

.globl      _memset
.type       _memset, @function
.text
# @returns: _dest=$rax
# @params: _dest=$rdi, _ch=$rsi, _count=$rdx
_memset:
    .cfi_startproc
    mov     %rsi, %rax
    xor     %rcx, %rcx
_memset.L0:
    cmp     %rdx, %rcx
    jge     _memset.L1
    movb    %al, 0(%rdi, %rcx)
    addq    $0x1, %rcx
    jmp     _memset.L0
_memset.L1:
    mov     %rdi, %rax
    ret
    .cfi_endproc
