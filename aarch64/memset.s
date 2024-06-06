// armv8-a assembly script

.arch       armv8-a
.globl      _memset
.type       _memset, %function
.text
// @return: _dest=$x0
// @params: _dest=$x0, _ch=$x1, _count=$x2
_memset:
	.cfi_startproc
    add     x3, x0, #0
_memset.L0:
    str     x1, [x3], #1
    subs    x2, x2, #1
    bge     _memset.L0
_memset.L1:
    ret
	.cfi_endproc

