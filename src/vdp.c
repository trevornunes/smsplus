
#include "shared.h"


/* VDP context */
t_vdp vdp;


/* Return values from the V counter */
uint8 vcnt[0x200] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA,
                                  0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
};

/* Return values from the H counter */
uint8 hcnt[0x200] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9,
                      0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
};


/*--------------------------------------------------------------------------*/


/* Initialize VDP emulation */
void vdp_init(void)
{
    vdp_reset();
}


/* Reset VDP emulation */
void vdp_reset(void)
{
    memset(&vdp, 0, sizeof(t_vdp));
    vdp.limit = 1;
}


/* Write data to the VDP's control port */
void vdp_ctrl_w(int data)
{
    /* Waiting for the reset of the command? */
    if(vdp.pending == 0)
    {
        /* Save data for later */
        vdp.latch = data;

        /* Set pending flag */
        vdp.pending = 1;
    }
    else
    {
        /* Clear pending flag */
        vdp.pending = 0;

        /* Extract code bits */
        vdp.code = (data >> 6) & 3;

        /* Make address */
        vdp.addr = (data << 8 | vdp.latch) & 0x3FFF;

        /* Read VRAM for code 0 */
        if(vdp.code == 0)
        {
            /* Load buffer with current VRAM byte */
            vdp.buffer = vdp.vram[vdp.addr & 0x3FFF];

            /* Bump address */
            vdp.addr += 1;
        }

        /* VDP register write */
        if(vdp.code == 2)
        {
            int r = (data & 0x0F);
            int d = vdp.latch;

            /* Store register data */
            vdp.reg[r] = d;

            /* Update table addresses */
            vdp.ntab = (vdp.reg[2] << 10) & 0x3800;
            vdp.satb = (vdp.reg[5] << 7) & 0x3F00;
        }
    }
}


/* Read the status flags */
int vdp_ctrl_r(void)
{
    /* Save the status flags */
    uint8 temp = vdp.status;

    /* Clear pending flag */
    vdp.pending = 0;

    /* Clear pending interrupt and sprite collision flags */
    vdp.status &= ~(0x80 | 0x40 | 0x20);

    /* Lower the IRQ line */
    if(sms.irq == 1)
    {
        sms.irq = 0;
        z80_set_irq_line(0, CLEAR_LINE);
    }

    /* Return the old status flags */
    return (temp);
}


/* Write data to the VDP's data port */
void vdp_data_w(int data)
{
    int index;

    /* Clear the pending flag */
    vdp.pending = 0;

    switch(vdp.code)
    {
        case 0: /* VRAM write */
        case 1: /* VRAM write */
        case 2: /* VRAM write */

            /* Get current address in VRAM */
            index = (vdp.addr & 0x3FFF);

            /* Only update if data is new */
            if(data != vdp.vram[index])
            {
                /* Store VRAM byte */
                vdp.vram[index] = data;

                /* Mark patterns as dirty */
                vram_dirty[(index >> 5)] = is_vram_dirty = 1;
            }
            break;

        case 3: /* CRAM write */
            if(cart.type == TYPE_GG)
            {
                index = (vdp.addr & 0x3F);
                if(data != vdp.cram[index])
                {
                    vdp.cram[index] = data;
                    index = (vdp.addr >> 1) & 0x1F;
                    palette_sync(index);
                }
            }
            else
            {
                index = (vdp.addr & 0x1F);
                if(data != vdp.cram[index])
                {
                    vdp.cram[index] = data;
                    palette_sync(index);
                }
            }
            break;
    }

    /* Bump the VRAM address */
    vdp.addr = (vdp.addr + 1) & 0x3FFF;
}


/* Read data from the VDP's data port */
int vdp_data_r(void)
{
    uint8 temp = 0;
    vdp.pending = 0;
    temp = vdp.buffer;
    vdp.buffer = vdp.vram[vdp.addr & 0x3FFF];
    vdp.addr = (vdp.addr + 1) & 0x3FFF;
    return temp;
}


/* Process frame events */
void vdp_run(void)
{
    if(vdp.line <= 0xC0)
    {
        if(vdp.line == 0xC0)
        {
            vdp.status |= 0x80;
        }

        if(vdp.line == 0)
        {
            vdp.left = vdp.reg[10];
        }

        if(vdp.left == 0)
        {
            vdp.left = vdp.reg[10];
            vdp.status |= 0x40;
        }
        else
        {
            vdp.left -= 1;
        }

        if((vdp.status & 0x40) && (vdp.reg[0] & 0x10))
        {
            sms.irq = 1;
            z80_set_irq_line(0, ASSERT_LINE);
        }
    }
    else
    {
        vdp.left = vdp.reg[10];

        if((vdp.line < 0xE0) && (vdp.status & 0x80) && (vdp.reg[1] & 0x20))
        {
            sms.irq = 1;
            z80_set_irq_line(0, ASSERT_LINE);
        }
    }
}


uint8 vdp_vcounter_r(void)
{
    return (vcnt[(vdp.line & 0x1FF)]);
}


uint8 vdp_hcounter_r(void)
{
    int pixel = (((z80_ICount % CYCLES_PER_LINE) / 4) * 3) * 2;
    return (hcnt[((pixel >> 1) & 0x1FF)]);
}
