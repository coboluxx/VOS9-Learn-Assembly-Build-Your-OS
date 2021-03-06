;	Project		VOS/9 
;  	File name	KRNLSHL.INC	24.02.1996
;	File type	Assembly
;	
;  	(c)(r) 1995 by MZ Computer Systems
;  
; 	Version		Gamma		24.02.1996
; 	Release		0		24.02.1996
;	
;  	Autor		Marcus Zoller
;  	
;	Description	Internal Kernel BootUp Shell
;
;	Includes	-
;	Link Objects	-
;	
;	CPU Type	x86
;	CPU Mode	Real/V86
;	
;	Functions Used	..\VIDEO\VIDEO.INC, ..\KEYBOARD\KEYBOARD.INC
;	
;	Bugfix List 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
;	
;	Release Comments 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
;	
;	Function Ref 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
;


	shell_init	proc near
		call	vid_clr_scrn
		xor	cx, cx
		call	vid_gotoxy
		lea	esi, fs:vos_welcome
		mov	ah, 4fh
		call	vid_prn_ln
	  	call	vid_next_ln
		lea	esi, fs:inf_cpu
		mov	ah, 0eh
		call	vid_prn_ln
		lea	esi, fs:cpu_str
		mov	ah, 0fh
		call	vid_prn_ln
		call	vid_next_ln		
		lea	esi, fs:inf_fms
		mov	ah, 0eh
		call	vid_prn_ln
		call	vid_get_pos
		mov	edx, dword ptr fs:[fms]
		mov	ah, 0fh
		call	print32hex
		call	vid_next_ln		
		lea	esi, fs:inf_opta
		mov	ah, 0eh
		call	vid_prn_ln
		call	vid_get_pos
		mov	edx, dword ptr fs:[opta]
		mov	ah, 0fh
		call	print32hex
		call	vid_next_ln
		lea	esi, fs:inf_optb
		mov	ah, 0eh
		call	vid_prn_ln
		call	vid_get_pos
		mov	edx, dword ptr fs:[optb]
		mov	ah, 0fh
		call	print32hex
		call	vid_next_ln
		lea	esi, fs:inf_speed
		mov	ah, 0eh
		call	vid_prn_ln
		call	vid_get_pos
		mov	edx, dword ptr fs:[io_delay]
		mov	ah, 0fh
		call	print32hex		
		call	vid_next_ln
		lea	esi, fs:inf_mem
		mov	ah, 0eh
		call	vid_prn_ln
		call	vid_get_pos
		mov	edx, dword ptr fs:[total_ram_bytes]
		mov	ah, 0fh
		call	print32hex		
		call	vid_next_ln
		ret
	shell_init	endp
		
	kernel_shell	proc near
		call	shell_init
	  @@prompt:
	  	mov	ah, 07h
	  	mov	al, ':'
	  	call	vid_prn_out
	  	mov	al, ' '
	  	call	vid_prn_out
	  @@kbrd_wait:
	  	call	kbrd_read
	  	cmp	al, 0Dh
	  	je	@@Execute
	  	mov	ah, 07h
	  	call	vid_prn_out
	  	jmp	short @@kbrd_wait
	  @@execute:
	  	call	vid_next_ln
	  	jmp	short @@prompt
	kernel_shell	endp
	