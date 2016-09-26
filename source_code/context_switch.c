   .globl kctx_switch
kctx_switch:
   leal	0(%eax,%eax,2), %eax
   leal	ktxp_loc(,%eax,8), %eax
   popl	%ecx
   //save old kernel context
   movl	%esp, 0(%eax)
   movl	%edi, 4(%eax)
   movl	%esi, 8(%eax)
   movl	%ebx, 12(%eax)
   movl	%ebp, 16(%eax)
   movl	%ecx, 20(%eax)
   leal	0(%edx,%edx,2), %edx
   leal ktxp_loc(,%edx,8), %edx
   //load new kernel context
   movl	0(%edx), %esp
   movl	4(%edx), %edi
   movl	8(%edx), %esi
   movl	12(%edx), %ebx
   movl	16(%edx), %ebp
   movl	20(%edx), %ecx
   pushl	%ecx
   xorl	%eax, %eax
   ret
