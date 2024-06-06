// armv8-a assembly script

.arch       armv8-a
.globl      abs32
.type       abs32, %function
.text
// @return: $w0
// @params: _num=$w0
abs32:
	.cfi_startproc
    cmp     w0, #0
    csneg   w0, w0, w0, ge
    ret
	.cfi_endproc


.arch       armv8-a
.globl      abs64
.type       abs64, %function
.text
// @returns: $x0
// @params: _num=$x0
abs64:
	.cfi_startproc
    cmp     x0, #0
    csneg   x0, x0, x0, ge
    ret
	.cfi_endproc

