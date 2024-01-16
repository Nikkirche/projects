%define DICT_SIZE 32768    
%define PREFS 16384
%define END 257
%define CLEAR 256
%define INC1 510
%define INC2 1022
%define INC3 2046
    global lzw_decode
    extern	printf
    section .text
inc_1:
    ADD EBP,2
    JMP count_e
inc_2:
    ADD EBP,3
    JMP count_e
inc_3:
    ADD EBP,4
    JMP count_e
write_bothsmall:

;                prefs[len] = out - 2;
    MOV ECX,EDI
    SUB ECX,2
    MOV [ESP+12+PREFS+4*EDX], ECX 
;                lens[len] = 2;
    MOV [ESP+12+4*EDX],dword 2
;                oldcode = code;
    MOV EBX, EAX
;                len++;
    INC EDX
;                goto iter;
    JMP get_next_code
write_small:

;  if (out_size < 1)
;            {
;                goto end;
;            };
    MOV ECX,[ESP+ 12+DICT_SIZE +32+16]
    CMP ECX,1
    JL err
;            out_size--;
    DEC ECX
    MOV [ESP+12+DICT_SIZE +32+16],ECX
;            *out = code;
    MOV [EDI],AL
;            out++;
    INC EDI
;            if (oldcode < 257)
;           
    CMP EBX, END
    JL write_bothsmall

;            uint16_t o = lens[oldcode] + 1;
    MOV ECX,[ESP+12+4*EBX]
    INC ECX
;            oldcode = code;
    MOV EBX, EAX
;            lens[len] = o;
    MOV [ESP+12+4*EDX], ECX
;            prefs[len] = out - o;
    MOV EAX, EDI
    SUB EAX, ECX
    MOV [ESP+12+PREFS+4*EDX], EAX
;            len++;
    INC EDX   
    JMP get_next_code

write_in_table_old_sm:
;               lens[len] = 2;
    MOV [ESP+12+4*EDX],dword 2
;                t++;
    INC ECX
;                prefs[len] = out - t;
    MOV EBP, EDI
    SUB EBP, ECX
    MOV [ESP +12+ PREFS+ 4*EDX],EBP
;                oldcode = code;
    MOV EBX, EAX

;                len++;
    INC EDX

;                goto iter;
    MOV EBP,[ESP+4]
    MOV ESI,[ESP]
        ;JMP end    
    JMP get_next_code
write_in_table_end:
    CMP EDX,ECX
    JL err
    SUB EDX, ECX
    MOV  [ESP+12+ DICT_SIZE +32+16],EDX
    MOV ESI,[ESP+12+PREFS+4*EAX]
    MOV EBP, ESI
    ADD EBP, ECX
tabl_last_loop:    
    MOV DL,[ESI]
    MOV [EDI], DL
    ADD EDI,1
    ADD ESI,1
    CMP ESI,EBP
    JL tabl_last_loop
    JMP write_end1

write_in_table:
; uint16_t t = lens[code];
    MOV ECX, [ESP+12+4*EAX]
    MOV [ESP], ESI
    MOV [ESP+4],EBP
    MOV [ESP+8],EDX
    MOV  EDX,[ESP+12+ DICT_SIZE +32+16]
    MOV EBP, ECX
    ADD EBP, 4
    CMP EDX, EBP
;            if (out_size < t + 4)
;            {
    JL write_in_table_end
;                if (out_size >= t)
;                {
;                    uint8_t *p = prefs[code];
;                    out_size -= t;
;                    uint8_t *e = (t + p);
;                    do
;                    {
;                        *out = *p;
;                        out++;
;                        p++;
;                    } while (p < e);
;                    goto write_end1;
;                }
;                goto end;
;            }
;            uint8_t *p = prefs[code];
    MOV ESI,[ESP+12+PREFS+4*EAX]
;            out_size -= t;
    SUB  EDX,ECX
    MOV  [ESP+12+ DICT_SIZE +32+16],EDX
;            uint8_t *e = (t + p);
    MOV EBP, ESI
    ADD EBP, ECX
in_loop:
;            do
;            {
;                *(uint32_t *)out = *(uint32_t *)(p);
    MOV EDX,[ESI]
    MOV [EDI], EDX
;                out += 4;
    ADD EDI,4
;                p += 4;
    ADD ESI,4
;            } while (p < e);
    CMP ESI,EBP
    JL in_loop
;  uint16_t l = t & 3;
    MOV EBP,ECX
    MOV EDX, ECX
    AND EBP, 1
    SUB EDI, EBP
    AND EDX,2
    SHL EBP, 1
    XOR EDX,EBP 
    SUB EDI, EDX
;            if (l == 0){
    ;CMP EBP,0
    ;JZ write_end1
;                goto write_end1;
;            }
;            out -= (4 - l);
    ;SUB EDI,4
 

;        write_end1:
write_end1: 
;            if (oldcode < 257)
;            {
;               lens[len] = 2;
;                t++;
;                prefs[len] = out - t;
;                oldcode = code;
;                len++;
;                goto iter;
;            }
    MOV EDX, [ESP+8]
    CMP EBX, 257
    JL write_in_table_old_sm
;            uint16_t k = lens[oldcode];
    MOV EBP, [ESP+12+4* EBX]
;            prefs[len] = out - t - k;
    MOV ESI, EDI
    SUB ESI, ECX
    SUB ESI, EBP
    MOV [ESP +12 + PREFS + 4*EDX], ESI
;            lens[len] = k + 1;
    INC EBP
    MOV [ESP+12+ 4*EDX], EBP
;            oldcode = code;
    MOV EBX, EAX
;            len++
    INC EDX
;            goto iter;
    MOV EBP,[ESP+4]
    MOV ESI,[ESP]
;JMP end
    JMP get_next_code
big_last:
;    do
;               {
;                    *out = *p;
;                    out++;
;                    p++;
;                } while (p < e);
;                goto write_end2;
    MOV DL, [ESI]
    MOV [EDI], DL
;                out += 4;
    ADD EDI, 1
;                p += 4;
    ADD ESI, 1
;            } while (p < e);
    CMP ESI,EBP
    JL big_last
    JMP write_end2
write_new_big:
;            uint16_t t = lens[oldcode] + 1;
    MOV ECX, [ESP +12+ 4*EBX]
    INC ECX

;            if (out_size < t)
;            {
;                goto end;
;            }
    CMP [ESP+12+DICT_SIZE +32+16],ECX
    JL err
;            out_size -= t;
    SUB [ESP+12+ DICT_SIZE +32+16],ECX
;            lens[len] = t;
    MOV [ESP +12+ EDX*4],ECX
;            prefs[len] = out;
    MOV [ESP+12+ PREFS + EDX*4], EDI
;            uint8_t *p = prefs[oldcode];
    MOV [ESP+8],ESI
    MOV [ESP+4], EBP
    MOV [ESP], EDX
    MOV ESI, [ESP+12+ PREFS + EBX*4]
;            t--;
    DEC ECX
;            uint8_t *e = (t + p);
    MOV EBP, ESI
    ADD EBP, ECX
;   if (out_size < 4)
;            {
;               do
;               {
;                    *out = *p;
;                    out++;
;                    p++;
;                } while (p < e);
;                goto write_end2;

;            }
    CMP [ESP+12+DICT_SIZE +32+16],dword 4
    JL big_last
;            
big_loop:
;            do
;           {
;                *(uint32_t *)out = (*(uint32_t *)p);
    MOV EDX, [ESI]
    MOV [EDI], EDX
;                out += 4;
    ADD EDI, 4
;                p += 4;
    ADD ESI, 4
;            } while (p < e);
    CMP ESI,EBP
    JL big_loop
;       write_end2:
write_end2:
;            t &= 3;
    AND ECX,3
;            out -= (4 - t);
    SUB EDI, 4
    ADD EDI, ECX
;            *out = *prefs[code];
    MOV ECX,[ESP+12+PREFS+4*EAX]
    MOV DL,[ECX] 
    MOV [EDI], DL
;            len++;
    MOV EDX,[ESP]
    INC EDX
;            out++;
    INC EDI
;            oldcode = code;
    MOV EBX, EAX
;            goto iter;
    MOV EBP,[ESP+4]
    MOV ESI,[ESP+8]
    JMP get_next_code;
    ;JMP end

last_code:
;c+=16
    ADD EBP,16

;if (in_size < 1)
;{
;   goto end;
;}
    CMP EAX,  1
    JL err
;else
;{
; in_size--;
    DEC EAX
    MOV [ESP+12+DICT_SIZE +32+8],EAX
;code = _bswap(*(uint16_t *)in);
    MOV   EAX, [ESI]
    BSWAP EAX
;in++;
    ADD ESI,1

;code <<= c;
    SHL EAX,CL
;code >>= (8 - offset + c);
    ADD ECX, 8
    SUB ECX, EBP
    SHR EAX,CL
    JMP loop_check

read_2:
;   c += 16;
    ADD ECX, 16
    MOV EAX,[ESP+12+ DICT_SIZE +32+8]
;if (in_size < 2)
;{read
;last_code             
;}
    CMP EAX, 2
    JL last_code
;else
;{  
    SUB EAX, 1
    MOV [ESP+12+ DICT_SIZE +32+8],EAX

;   code = ((_bswap(*(uint32_t *)(in-2))));
    MOV EAX, [ESI-2]
    BSWAP EAX
;   in += 1;
    ADD ESI, 1
;   code <<= c;
    SHL EAX,CL
;   code >>= (8 + c - offset);
    ADD ECX, 8
    SUB ECX, EBP
    SHR EAX,CL
;}
    JMP loop_check



;EAX code, EBX oldcode,ESI in,EDI out,EBP offset, EDX len,ECX tmp

;read_in+write_out+  prefs[uint32]x4096 lens[uint32]x4096 +8 or reg(where eax is start)
;size_t lzw_decode(uint8_t *in, size_t in_size, uint8_t*  out, size_t out_size)
lzw_decode: 
    PUSHAD
    MOV EDI,[ESP +32 +12]
    MOV ESI,[ESP +32 +4]
    MOV EBP, ESP
    SUB ESP, DICT_SIZE+12
    SUB EBP, 4096+12
    MOV [EBP],byte 0 
;special for windows...
loop_touch:
    SUB EBP, 4096
    MOV [EBP],byte 0 
    CMP EBP,ESP
    JNE loop_touch
first_code:
    MOV ECX,[ESP+12+ DICT_SIZE +32+8]
;    if (in_size < 2)
;    {
;        goto end;
;    }
    CMP ECX,2
    JL err
;    in_size--;
    DEC ECX
    MOV [ESP+12+ DICT_SIZE +32+8],ECX    
;    code = *in << 1;
    MOVZX EAX, byte [ESI]
    SHL EAX, 1 
;    in++;
    INC ESI 
;    code += (*in >> 7);
    MOVZX ECX, byte [ESI]
    SHR ECX, 7
    ADD EAX, ECX 
;    uint8_t offset = 1;
    MOV EBP, 1
;    uint8_t *start = out;
    CMP EAX, CLEAR  
    JNE err
start:
;    if (in_size < 1)
;        {
;            goto end;
;        }
    MOV EAX,[ESP+12+ DICT_SIZE +32+8]
    CMP EAX, 1
    JL err
;        in_size--;
    DEC EAX
    MOV [ESP+12+DICT_SIZE +32+8],EAX

;
;        len = 258;
    MOV EDX,258
;        offset++;
    INC EBP
;        code = ((*in) << (offset));
    MOV ECX, EBP
    MOVZX EAX,byte  [ESI]
    SHL EAX, CL
;        in++;
    ADD ESI,1
;        code += ((*in) >> (8 - offset));
    MOVZX EBX,byte  [ESI]
    MOV ECX, 8
    SUB ECX, EBP
    SHR EBX,CL
    ADD EAX, EBX
;        if (code == END)
;        {
;            return out - start;
;        }
    CMP EAX, END
    JE end
;        oldcode = code;
    MOV EBX,EAX
    MOV ECX,[ESP+12+DICT_SIZE +32+16]
    CMP ECX, 1
    JL err
    SUB ECX, 1
    MOV [ESP+12+DICT_SIZE +32+16],ECX
;        if (out_size < 1)
;        {
;            goto end;
;        }
;        out_size--;
;        *out = code;
    MOV [EDI],EAX
;        out++;
    INC EDI
;        goto iter; 
    JMP get_next_code
loop:
;    PUSHAD
;    PUSH dword [32+ESP+ DICT_SIZE +32+16]
;    PUSH format
;    CALL printf
;    ADD ESP, 8
;    POPAD
write:
    CMP EAX, CLEAR
    JL write_small
    JE start
    CMP EAX, EDX
    JL write_in_table
    CMP EBX, 257
    JGE write_new_big
write_new_small:
    MOV ECX,[ESP+12+DICT_SIZE +32+16]
;     if (out_size < 2)
;        {
;            goto end;
;        }
    CMP ECX, 2
    JL err
;        out_size -= 2;
    SUB ECX, 2
    MOV [ESP+12+DICT_SIZE +32+16],ECX
;        *out = oldcode;
        MOV [EDI], BL
;        prefs[len] = out;
    MOV [ESP+12+PREFS+ 4*EDX],EDI
;        lens[len] = 2;
    MOV [ESP+12+4*EDX], dword 2
;        out++;
    INC EDI
;        len++
    INC EDX
;        *out = oldcode;
    MOV [EDI], BL
;        out++;
    INC EDI
;        oldcode = code;
    MOV EBX, EAX




get_next_code:
    ;uint8_t c = offset;
    MOV ECX,EBP
    ;if (len > INC3)
    ;{
        ;offset += 4;
        ;goto count_e;
    ;}
    CMP EDX, INC3
    JG inc_3
    ;else if (len > INC2)
    ;{
    ;  offset += 3;
    ;   goto count_e;
    ;}
    CMP EDX,INC2
    JG inc_2
    ;else if (len > INC1)
    ;{
    ;   offset += 2;
    ;   goto count_e;
    ;}
    CMP EDX,INC1
    JG inc_1
    ;offset++;
    INC EBP
count_e:
       MOV EAX,[ESP+12+DICT_SIZE +32+8]
     ;if (offset <= 7)
     CMP EBP, 7
     JLE read_2
    ;  if (in_size < 2)
    ; { 
    ;    goto end;
    ;}
    CMP EAX, 2
    JL err
    ;in_size -= 2;
    SUB EAX,2
    MOV [ESP+12+DICT_SIZE+ 32+8], EAX 
    ;c += 8;
    ADD ECX, 8 
    ;code = ((_bswap(*(uint32_t *)(in-1))));
    MOV EAX, [ESI-1]
    BSWAP EAX
    ;in += 2;
    ADD ESI, 2
    ;code <<= c;
    SHL EAX,CL
    ;code >>= (16 + c - offset);
    ADD EBP, 16
    SUB ECX, EBP
    SHR EAX, CL
    ;offset &= 0x7;
    AND EBP, 7
    ;}
loop_check:
    CMP EAX,END
    JNE loop
end:
    ADD ESP, DICT_SIZE+12
    MOV ESI, [ESP+32+12]
    SUB EDI, ESI
    MOV [ESP+28], EDI
    POPAD
    RET
err:
    ADD ESP, DICT_SIZE+12
    POPAD
    MOV EAX, -1
    RET
format:
	DB	"%u", 10, 0