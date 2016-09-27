   .globl kctx_switch
kctx_switch:
   // save old kernel context
   leal	0(%eax,%eax,2), %eax
   leal	ktxp_loc(,%eax,8), %eax
   // save return address (RA)
   popl	%ecx
   movl	%ecx, 20(%eax)
   movl	%ebp, 16(%eax)
   movl	%ebx, 12(%eax)
   movl	%esi, 8(%eax)
   movl	%edi, 4(%eax)
   movl	%esp, 0(%eax)
   // load new kernel context
   leal	0(%edx,%edx,2), %edx
   leal ktxp_loc(,%edx,8), %edx
   movl	0(%edx), %esp
   movl	4(%edx), %edi
   movl	8(%edx), %esi
   movl	12(%edx), %ebx
   movl	16(%edx), %ebp
   // load new return address
   movl	20(%edx), %ecx
   pushl	%ecx
   xorl	%eax, %eax
   ret
