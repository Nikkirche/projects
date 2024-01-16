#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <immintrin.h>

#define INITIAL 9
#define END 257
#define CLEAR 256
#define INC1 510
#define INC2 1022
#define INC3 2046

size_t lzw_decode(const uint8_t *in, size_t in_size, uint8_t *restrict out, size_t out_size)
{
    uint16_t lens[4096];
    uint8_t *prefs[4096];
    uint32_t code;
    uint32_t oldcode;
    uint16_t len;
    if (in_size < 2)
    {
        goto end;
    }

    in_size--;
    code = *in << 1;
    in++;
    code += (*in >> 7);
    uint8_t offset = 1;
    uint8_t *start = out;
    if (code == CLEAR)
    {
    start:
        if (in_size < 1)
        {
            goto end;
        }
        in_size--;
        len = 258;
        offset++;
        code = ((*in) << (offset));
        in++;
        code += ((*in) >> (8 - offset));
        if (code == END)
        {
            return out - start;
        }
        oldcode = code;
        if (out_size < 1)
        {
            goto end;
        }
        out_size--;
        *out = code;
        out++;
        goto iter;
    }
    else
    {
        goto end;
    }
    do
    {
        //fprintf(stderr,"%u\n",code);
        if (code < CLEAR)
        {
            if (out_size < 1)
            {
                goto end;
            }

            out_size--;

            *out = code;
            out++;
            if (oldcode < 257)
            {
                prefs[len] = out - 2;
                lens[len] = 2;
                oldcode = code;
                len++;
                goto iter;
            }
            uint16_t o = lens[oldcode] + 1;
            oldcode = code;
            prefs[len] = out - o;
            lens[len] = o;
            len++;
            goto iter;
        }
        else if (code == CLEAR)
        {
            goto start;
        }
        else if (code < len)
        {
            uint16_t t = lens[code];
            if (out_size < t + 4)
            {
                if (out_size >= t)
                {
                    uint8_t *p = prefs[code];
                    out_size -= t;
                    uint8_t *e = (t + p);
                    do
                    {
                        *out = *p;
                        out++;
                        p++;
                    } while (p < e);
                    goto write_end1;
                }
                goto end;
            }
            uint8_t *p = prefs[code];
            out_size -= t;
            uint8_t *e = (t + p);

            do
            {
                *(uint32_t *)out = *(uint32_t *)(p);
                out += 4;
                p += 4;
            } while (p < e);
            uint16_t l = t & 3;
            if (l == 0){
                goto write_end1;
            }
            out -= (4 - l);
        write_end1:
            if (oldcode < 257)
            {
                lens[len] = 2;
                t++;
                prefs[len] = out - t;
                oldcode = code;
                len++;
                goto iter;
            }
            uint16_t k = lens[oldcode];
            prefs[len] = out - t - k;
            lens[len] = k + 1;
            oldcode = code;
            len++;
            goto iter;
        }
        else if (oldcode >= 257)
        {
            uint16_t t = lens[oldcode] + 1;
            if (out_size < t)
            {
                goto end;
            }
            out_size -= t;
            lens[len] = t;
            prefs[len] = out;
            uint8_t *p = prefs[oldcode];
            t--;
            uint8_t *e = (t + p);
            if (out_size < 4)
            {
                do
                {
                    *out = *p;
                    out++;
                    p++;
                } while (p < e);
                goto write_end2;
            }
            do
            {
                *(uint32_t *)out = (*(uint32_t *)p);
                out += 4;
                p += 4;
            } while (p < e);
        write_end2:
            t &= 3;
            out -= (4 - t);
            *out = *prefs[code];
            len++;
            out++;
            oldcode = code;
            goto iter;
        }
        if (out_size < 2)
        {
            goto end;
        }
        out_size -= 2;
        *out = oldcode;
        prefs[len] = out;
        lens[len] = 2;
        out++;
        len++;

        *out = oldcode;
        out++;
        oldcode = code;
    iter:
        uint8_t c = offset;
        if (len > INC3)
        {
            offset += 4;
            goto count_e;
        }
        else if (len > INC2)
        {
            offset += 3;
            goto count_e;
        }
        else if (len > INC1)
        {
            offset += 2;
            goto count_e;
        }
        offset++;
    count_e:
        if (offset <= 7)
        {
            c += 16;
            if (in_size < 2)
            {

                if (in_size < 1)
                {
                    goto end;
                }
                else
                {
                    in_size--;
                    code = _bswap(*(uint16_t *)in);
                    in++;
                    code <<= (c);
                    code >>= (8 - offset + c);
                }
            }
            else
            {
                in_size -= 1;
                in -= 2;
                code = ((_bswap(*(uint32_t *)(in))));
                in += 3;
                code <<= c;
                code >>= (8 + c - offset);
                // fprintf(stderr, "%d\n", code);
            }
        }
        else
        {   
            
            c += 8;
            if (in_size < 2)
            {
                goto end;
            }
            in_size -= 2;
            code = ((_bswap(*(uint32_t *)(--in))));
            in += 3;
            code <<= c;
            code >>= (16 + c - offset);
            offset &= 0x7;
        }
    } while (code != END);
s_end:
    //printf("end %d,in %d",in_size,out_size);
    return out - start;
end:
    return -1;
}