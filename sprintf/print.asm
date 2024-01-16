; void print(char *out_buf, const char *format, const char *hex_number);
global print
section .text
parse_width:
;[space,sign,0,+,-]
parse_width_rec:
    MOV EDX, 10
    CMP byte [ESI], 0 
    JE parse_format_clean
    CMP byte [ESI], '0'
    JL parse_rec
    MOVZX ECX,byte [ESI]
    SUB ECX,'0'
    MUL EDX
    ADD EAX, ECX
    INC ESI
    JMP parse_width_rec
parse_format:
    XOR EAX, EAX

parse_rec:
    CMP byte [ESI], 0 
    JE parse_format_clean
    CMP byte [ESI], '+' 
    JE parse_recp
    CMP byte [ESI], '-' 
    JE parse_recm
    CMP byte [ESI], '0'
    JG parse_width
    JE parse_set_0
    CMP byte [ESI], ' '
    JE parse_add_space

    
parse_step:
    INC ESI
    JMP parse_rec
parse_set_0:
    OR EBP,4
    JMP parse_step
parse_format_clean:
    SHL EAX, 5
    OR EBP, EAX
    JMP parse_e

parse_recp:
    OR EBP,2
    JMP parse_step
parse_recm:
    OR EBP,1
    JMP parse_step
parse_add_space:
    OR EBP, 16
    JMP parse_step
read_skip:
    ADD ESI, 2
    JMP read_first
read_skip_pref0:
    CMP byte [ESI+1],'x'
    JE read_skip
    CMP byte [ESI+1],'X'
    JE read_skip
    JMP read_rec

read_addm:
    OR EBP,8
    INC ESI
    JMP read_first

read_addp:
    OR EBP, 8
    INC ESI
    JMP read_first
;
;EAX,EBX,ECX,EDX are places for digits

read:
    XOR EAX, EAX
    XOR EBX, EBX
    XOR ECX, ECX
    XOR EDX, EDX
    XOR EDI, EDI
    ;Empty string case
    CMP byte [ESI], 0 
    JE read_e
    ;Check for  sign before
    CMP byte [ESI], '-'
    JE read_addm
read_first:
    CMP byte [ESI], '0'
    JE read_skip_pref0 
    
read_rec:
    MOVZX  EDI,byte [ESI]
    CMP byte [ESI], 0 
    JE read_e
    CMP byte [ESI],'A'
    JL read_num
    CMP byte[ESI], 'a'
    JL read_bsym
    JMP read_sym
read_step:
    SHLD EAX, EBX, 4
    SHLD EBX, ECX, 4
    SHLD ECX, EDX, 4
    SHL EDX, 4
    ADD EDX,EDI
    INC ESI
    JMP read_rec


read_num:
    SUB EDI,'0'
    JMP read_step
read_sym:
    SUB EDI, 'a'
    ADD EDI,10
    JMP read_step
read_bsym:
    SUB EDI, 'A'
    ADD EDI,10
    JMP read_step
convert_s1:
    CMP dword EBX, 0 
    JE convert_s2
    JMP convert_s
convert_s2:
    CMP dword ECX, 0 
    JE convert_s3
    JMP convert_s
convert_s3:
    CMP dword EDX, 10 
    JL convert_s4
    JMP convert_s
convert_s4:
    CMP dword EDX, 0 
    JGE convert_clean
    JMP convert_s


conver_add2:
    TEST EBP, 8
    JE conver_adds
    NOT EDX
    NOT ECX
    NOT EBX
    NOT EAX
    ADD EDX,1
    ADC ECX,0
    ADC EBX,0
    ADC EAX,0 
conver_adds:
    MOV ESI, 8
    NOT ESI
    AND  EBP, ESI
    TEST  EAX,0x80000000
    JZ convert_start
    OR EBP, 8
    NOT EDX
    NOT ECX
    NOT EBX
    NOT EAX
    ADD EDX,1
    ADC ECX,0
    ADC EBX,0
    ADC EAX,0 
    JMP convert_start
;EBP meta
;EDI buffer
;in ESI will count stored
convert:
   JMP  conver_add2
convert_start:
    XOR ESI,ESI
convert_loop:
    CMP dword EAX, 0
    JE convert_s1
convert_s:
    PUSH 0
    PUSH ESI
    PUSH EBP
    PUSH EDI
    MOV EBP, EDX 
    MOV ESI,10

    ;first
    XOR EDX, EDX
    DIV ESI
    MOV EDI, EAX 
    ;second
    MOV EAX, EBX
    DIV ESI
    MOV EBX, EAX 
    ;third
    MOV EAX, ECX
    DIV ESI
    MOV ECX, EAX
    ;four
    MOV EAX, EBP
    DIV ESI
    ADD EDX,'0'
    MOV [ESP + 12], EDX
    MOV EDX, EAX
    MOV EAX, EDI
    POP EDI
    POP EBP
    POP ESI
    INC ESI
    JMP convert_loop
convert_clean:
    INC ESI
    ADD EDX,'0'
    PUSH EDX
    JMP convert_e
output_ins_p:
    MOV byte [EDI], '+'
    INC EDI
    JMP output_rec
output_ins_m:
    MOV byte [EDI], '-'
    INC EDI
    JMP output_rec
output_ins_ws:
    CMP EDX, ESI
    JLE output_stws
    MOV [EDI],byte ' '
    INC EDI
    DEC EDX
    JMP output_ins_ws

output_ins_wse:
    CMP EDX, ESI
    JLE output_e
    MOV [EDI],byte ' '
    INC EDI
    DEC EDX
    JMP output_ins_wse
dec_width:
    DEC EDX
    JMP output_step

set_plus_sign:
    TEST EBP,2
    JZ output_sign_e
    MOV byte [EDI],'+'
    INC EDI
    JMP output_sign_e
set_minus_sign:
    MOV byte [EDI],'-'
    INC EDI
    JMP output_sign_e

has_plus_sign:
    TEST EBP,2
    JZ has_no_signs
    DEC EDX
    JMP output_ws
insert_ws:
    MOV byte [EDI], ' '
    INC EDI
    CMP EDX, 0
    JG dec_width1
    JMP output_ws
dec_width1:
    SUB EDX,1
    JMP output_ws
has_no_signs:
    TEST EBP, 0x10
    JNZ insert_ws
    JMP output_ws
has_minus_sign:
    DEC EDX
    JMP output_ws
need_ws:
    TEST EBP, 4
    JZ output_ins_ws
    JMP output_stws
output_ins_z:
    CMP EDX, ESI
    JLE output_rec
    MOV [EDI],byte '0'
    INC EDI
    DEC EDX
    JMP output_ins_z

need_zeroes:
    TEST EBP, 4
    JNZ output_ins_z
    JMP output_rec
output:

    XOR EDX,EDX
    MOV EDX, EBP
    SHR EDX, 5
    TEST EBP,8
    JZ has_plus_sign
    JMP has_minus_sign
output_ws:
    TEST EBP,1
    JZ need_ws
output_stws:
    TEST EBP,8
    JNZ set_minus_sign
    JMP set_plus_sign
output_sign_e:
    TEST EBP,1
    JZ need_zeroes
output_rec:
    CMP ESI,0
    JE  output_clean
    POP ECX
    MOV [EDI], ECX
    INC EDI
    DEC ESI
    CMP  EDX, 0
    JG dec_width
output_step:
    JMP output_rec
output_clean:
    TEST EBP, 1
    JNZ output_ins_wse
    JMP output_e
print:
    PUSHAD
    MOV EBX,[ESP+32+4]
    XOR EBP, EBP
                                                                             
    MOV ESI, [ESP+32+8]
    JMP parse_format

    ;EBP - flag,EAX EBX ECX EDX number, 
parse_e:
    MOV ESI,[ESP+32+12]
    JMP read
read_e:

    MOV EDI,[ESP+32+4]
    JMP convert
convert_e:
    JMP output
output_e:
    MOV byte [EDI],0
    POPAD
    RET


section .rdata
