	.globl cswitch
cswitch: // <@$\kappa_{cswitch}$@>
	// save the old kernel context
	leai	(%eax,%eax,2), %eax
	leai	KCtxtP(,%eax,8), %eax
	movi	%esp, (%eax)
	movi	%edi, 4(%eax)
	movi	%esi, 8(%eax)
	movi	%ebx, 12(%eax)
	movi	%ebp, 16(%eax)
	pop	%ecx
	movi	%ecx, 20(%eax)
	// load the new kernel context
	leal	(%edx,%edx,2), %edx
	leal	KCtxtP(,%edx,8), %edx
	movi	(%edx), %esp
	movi	4(%edx), %edi
	movi	8(%edx), %esi
	movi	12(%edx), %ebx
	movi	16(%edx), %ebp
	movi	20(%edx), %ecx
	push	%ecx
	xor	%eax, %eax
	ret
