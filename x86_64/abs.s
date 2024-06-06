# x64-64 assembly script

.globl     abs64
.type       abs64, @function
.text
# @return: $rax
# @params: _num=$rdi
abs64:
    .cfi_startproc
    mov     %rdi, %rax
    neg     %rax
    cmovs   %rdi, %rax
    ret
    .cfi_endproc



.globl      abs32
.type       abs32, @function
.text
# @returns: $eax
# @params: _num=$edi
abs32:
    .cfi_startproc
    mov     %edi, %eax
    neg     %eax
    cmovs   %edi, %eax
    ret
    .cfi_endproc
