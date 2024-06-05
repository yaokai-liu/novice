// armv8-a assembly script

.arch       armv8-a
.globl      getSum
.type       getSum, %function
.text
// @return: $x0
// @params: _dest=$x0, _count=$x1
getSum:
	.cfi_startproc
	cbz     x1, getSum.L1
    lsl     x1, x1, 3
	mov     x2, x0
	add     x1, x1, x2
    mov     x0, xzr
getSum.L0:
    ldr     x3, [x2], #8
    add     x0, x0, x3
    cmp     x2, x1
    blt     getSum.L0
    ret
getSum.L1:
    mov     x0, xzr
    ret
	.cfi_endproc

