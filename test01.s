mov ds,ax  
 
mov ax,[var]    
 
label:
jmp label  
var dw 0x99 