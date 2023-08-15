#ifndef inshandler
#define inshandler
#include "setup.h"
typedef void (CPU::*InstructionFunc)();

InstructionFunc instruction_table[256];

void CPU::initialize_instruction_table() {
    instruction_table[0x80] = &CPU::add_b;
    instruction_table[0x81] = &CPU::add_c;
    instruction_table[0x82] = &CPU::add_d;
    instruction_table[0x83] = &CPU::add_e;
    instruction_table[0x84] = &CPU::add_h;
    instruction_table[0x85] = &CPU::add_l;
    instruction_table[0x86] = &CPU::add_m;
    instruction_table[0x87] = &CPU::add_a;
    instruction_table[0x88] = &CPU::adc_b;
    instruction_table[0x89] = &CPU::adc_c;
    instruction_table[0x8A] = &CPU::adc_d;
    instruction_table[0x8B] = &CPU::adc_e;
    instruction_table[0x8C] = &CPU::adc_h;
    instruction_table[0x8D] = &CPU::adc_l;
    instruction_table[0x8E] = &CPU::adc_m;
    instruction_table[0x8F] = &CPU::adc_a;
    instruction_table[0x09] = &CPU::dad_b;
    instruction_table[0x19] = &CPU::dad_d;
    instruction_table[0x29] = &CPU::dad_h;
    instruction_table[0x39] = &CPU::dad_sp;
    instruction_table[0x27] = &CPU::daa;

    instruction_table[0x90] = &CPU::sub_b;
    instruction_table[0x91] = &CPU::sub_c;
    instruction_table[0x92] = &CPU::sub_d;
    instruction_table[0x93] = &CPU::sub_e;
    instruction_table[0x94] = &CPU::sub_h;
    instruction_table[0x95] = &CPU::sub_l;
    instruction_table[0x96] = &CPU::sub_m;
    instruction_table[0x97] = &CPU::sub_a;
    instruction_table[0x98] = &CPU::sbb_b;
    instruction_table[0x99] = &CPU::sbb_c;
    instruction_table[0x9A] = &CPU::sbb_d;
    instruction_table[0x9B] = &CPU::sbb_e;
    instruction_table[0x9C] = &CPU::sbb_h;
    instruction_table[0x9D] = &CPU::sbb_l;
    instruction_table[0x9E] = &CPU::sbb_m;
    instruction_table[0x9F] = &CPU::sbb_a;

    instruction_table[0xA0] = &CPU::ana_b;
    instruction_table[0xA1] = &CPU::ana_c;
    instruction_table[0xA2] = &CPU::ana_d;
    instruction_table[0xA3] = &CPU::ana_e;
    instruction_table[0xA4] = &CPU::ana_h;
    instruction_table[0xA5] = &CPU::ana_l;
    instruction_table[0xA6] = &CPU::ana_m;
    instruction_table[0xA7] = &CPU::ana_a;

    instruction_table[0xA8] = &CPU::xra_b;
    instruction_table[0xA9] = &CPU::xra_c;
    instruction_table[0xAA] = &CPU::xra_d;
    instruction_table[0xAB] = &CPU::xra_e;
    instruction_table[0xAC] = &CPU::xra_h;
    instruction_table[0xAD] = &CPU::xra_l;
    instruction_table[0xAE] = &CPU::xra_m;
    instruction_table[0xAF] = &CPU::xra_a;

    instruction_table[0xB0] = &CPU::ora_b;
    instruction_table[0xB1] = &CPU::ora_c;
    instruction_table[0xB2] = &CPU::ora_d;
    instruction_table[0xB3] = &CPU::ora_e;
    instruction_table[0xB4] = &CPU::ora_h;
    instruction_table[0xB5] = &CPU::ora_l;
    instruction_table[0xB6] = &CPU::ora_m;
    instruction_table[0xB7] = &CPU::ora_a;

    instruction_table[0xB8] = &CPU::cmp_b;
    instruction_table[0xB9] = &CPU::cmp_c;
    instruction_table[0xBA] = &CPU::cmp_d;
    instruction_table[0xBB] = &CPU::cmp_e;
    instruction_table[0xBC] = &CPU::cmp_h;
    instruction_table[0xBD] = &CPU::cmp_l;
    instruction_table[0xBE] = &CPU::cmp_m;
    instruction_table[0xBF] = &CPU::cmp_a;

    instruction_table[0x2F] = &CPU::cma;
    instruction_table[0x3F] = &CPU::cmc;

    instruction_table[0xC6] = &CPU::adi;
    instruction_table[0xD6] = &CPU::sui;
    instruction_table[0xDE] = &CPU::sbi;
    instruction_table[0xEE] = &CPU::xri;
    instruction_table[0xE6] = &CPU::ani;
    instruction_table[0xF6] = &CPU::ori;
    instruction_table[0xFE] = &CPU::cpi;
    instruction_table[0xCE] = &CPU::aci;

    instruction_table[0xC3] = &CPU::jmp;
    instruction_table[0xC2] = &CPU::jz;
    instruction_table[0xC4] = &CPU::jnz;
    instruction_table[0xDA] = &CPU::jc;
    instruction_table[0xD2] = &CPU::jnc;
    instruction_table[0xF2] = &CPU::jp;
    instruction_table[0xFA] = &CPU::jm;

    instruction_table[0x78] = &CPU::mov_ab;
    instruction_table[0x79] = &CPU::mov_ac;
    instruction_table[0x7A] = &CPU::mov_ad;
    instruction_table[0x7B] = &CPU::mov_ae;
    instruction_table[0x7C] = &CPU::mov_ah;
    instruction_table[0x7D] = &CPU::mov_al;
    instruction_table[0x7E] = &CPU::mov_am;

    instruction_table[0x41] = &CPU::mov_bc;
    instruction_table[0x42] = &CPU::mov_bd;
    instruction_table[0x43] = &CPU::mov_be;
    instruction_table[0x44] = &CPU::mov_bh;
    instruction_table[0x45] = &CPU::mov_bl;
    instruction_table[0x47] = &CPU::mov_ba;
    instruction_table[0x46] = &CPU::mov_bm;

    instruction_table[0x48] = &CPU::mov_cb;
    instruction_table[0x4A] = &CPU::mov_cd;
    instruction_table[0x4B] = &CPU::mov_ce;
    instruction_table[0x4C] = &CPU::mov_ch;
    instruction_table[0x4D] = &CPU::mov_cl;
    instruction_table[0x4F] = &CPU::mov_ca;
    instruction_table[0x4E] = &CPU::mov_cm;

    instruction_table[0x50] = &CPU::mov_db;
    instruction_table[0x51] = &CPU::mov_dc;
    instruction_table[0x53] = &CPU::mov_de;
    instruction_table[0x54] = &CPU::mov_dh;
    instruction_table[0x55] = &CPU::mov_dl;
    instruction_table[0x57] = &CPU::mov_da;
    instruction_table[0x56] = &CPU::mov_dm;

    instruction_table[0x58] = &CPU::mov_eb;
    instruction_table[0x59] = &CPU::mov_ec;
    instruction_table[0x5A] = &CPU::mov_ed;
    instruction_table[0x5C] = &CPU::mov_eh;
    instruction_table[0x5D] = &CPU::mov_el;
    instruction_table[0x5F] = &CPU::mov_ea;
    instruction_table[0x5E] = &CPU::mov_em;

    instruction_table[0x60] = &CPU::mov_hb;
    instruction_table[0x61] = &CPU::mov_hc;
    instruction_table[0x62] = &CPU::mov_hd;
    instruction_table[0x63] = &CPU::mov_he;
    instruction_table[0x65] = &CPU::mov_hl;
    instruction_table[0x67] = &CPU::mov_ha;
    instruction_table[0x66] = &CPU::mov_hm;

    instruction_table[0x68] = &CPU::mov_lb;
    instruction_table[0x69] = &CPU::mov_lc;
    instruction_table[0x6A] = &CPU::mov_ld;
    instruction_table[0x6B] = &CPU::mov_le;
    instruction_table[0x6C] = &CPU::mov_lh;
    instruction_table[0x6F] = &CPU::mov_la;
    instruction_table[0x6E] = &CPU::mov_lm;

    instruction_table[0x70] = &CPU::mov_mb;
    instruction_table[0x71] = &CPU::mov_mc;
    instruction_table[0x72] = &CPU::mov_md;
    instruction_table[0x73] = &CPU::mov_me;
    instruction_table[0x74] = &CPU::mov_mh;
    instruction_table[0x75] = &CPU::mov_ml;
    instruction_table[0x77] = &CPU::mov_ma;

    instruction_table[0x06] = &CPU::mvi_b;
    instruction_table[0x0E] = &CPU::mvi_c;
    instruction_table[0x16] = &CPU::mvi_d;
    instruction_table[0x1E] = &CPU::mvi_e;
    instruction_table[0x26] = &CPU::mvi_h;
    instruction_table[0x2E] = &CPU::mvi_l;
    instruction_table[0x3E] = &CPU::mvi_a;
    instruction_table[0x36] = &CPU::mvi_m;

    instruction_table[0x2A] = &CPU::lhld;
    instruction_table[0x22] = &CPU::shld;
    instruction_table[0x3A] = &CPU::lda;
    instruction_table[0x32] = &CPU::sta;
    instruction_table[0x01] = &CPU::lxi_b;
    instruction_table[0x11] = &CPU::lxi_d;
    instruction_table[0x21] = &CPU::lxi_h;
    instruction_table[0x31] = &CPU::lxi_sp;
    instruction_table[0x0A] = &CPU::ldax_b;
    instruction_table[0x1A] = &CPU::ldax_d;
    instruction_table[0x02] = &CPU::stax_b;
    instruction_table[0x12] = &CPU::stax_d;
    instruction_table[0xEB] = &CPU::xchg;

    instruction_table[0x04] = &CPU::inr_b;
    instruction_table[0x0C] = &CPU::inr_c;
    instruction_table[0x14] = &CPU::inr_d;
    instruction_table[0x1C] = &CPU::inr_e;
    instruction_table[0x24] = &CPU::inr_h;
    instruction_table[0x2C] = &CPU::inr_l;
    instruction_table[0x3C] = &CPU::inr_a;
    instruction_table[0x34] = &CPU::inr_m;

    instruction_table[0x05] = &CPU::dcr_b;
    instruction_table[0x0D] = &CPU::dcr_c;
    instruction_table[0x15] = &CPU::dcr_d;
    instruction_table[0x1D] = &CPU::dcr_e;
    instruction_table[0x25] = &CPU::dcr_h;
    instruction_table[0x2D] = &CPU::dcr_l;
    instruction_table[0x35] = &CPU::dcr_m;
    instruction_table[0x3D] = &CPU::dcr_a;

    instruction_table[0x03] = &CPU::inx_b;
    instruction_table[0x13] = &CPU::inx_d;
    instruction_table[0x23] = &CPU::inx_h;
    instruction_table[0x33] = &CPU::inx_sp;
    instruction_table[0x0B] = &CPU::dcx_b;
    instruction_table[0x1B] = &CPU::dcx_d;
    instruction_table[0x2B] = &CPU::dcx_h;
    instruction_table[0x3B] = &CPU::dcx_sp;

    instruction_table[0x07] = &CPU::rlc;
    instruction_table[0x0F] = &CPU::rrc;
    instruction_table[0x1F] = &CPU::rar;
    instruction_table[0x17] = &CPU::ral;

    instruction_table[0xCD] = &CPU::call;
    instruction_table[0xDC] = &CPU::cc;
    instruction_table[0xD4] = &CPU::cnc;
    instruction_table[0xCC] = &CPU::cz;
    instruction_table[0xC4] = &CPU::cnz;
    instruction_table[0xf4] = &CPU::cp;
    instruction_table[0xfc] = &CPU::cm;
    instruction_table[0xEC] = &CPU::cpe;
    instruction_table[0xE4] = &CPU::cpo;
    instruction_table[0xC9] = &CPU::ret;
    instruction_table[0xD8] = &CPU::rc;
    instruction_table[0xD0] = &CPU::rnc;
    instruction_table[0xC8] = &CPU::rz;
    instruction_table[0xC0] = &CPU::rnz;
    instruction_table[0xF0] = &CPU::rp;
    instruction_table[0xF8] = &CPU::rm;
    instruction_table[0xE8] = &CPU::rpe;
    instruction_table[0xE0] = &CPU::rpo;

    instruction_table[0xC5] = &CPU::push_b;
    instruction_table[0xD5] = &CPU::push_d;
    instruction_table[0xE5] = &CPU::push_h;
    instruction_table[0xF5] = &CPU::push_psw;
    instruction_table[0xC1] = &CPU::pop_b;
    instruction_table[0xD1] = &CPU::pop_d;
    instruction_table[0xE1] = &CPU::pop_h;
    instruction_table[0xF1] = &CPU::pop_psw;
    instruction_table[0xE3] = &CPU::xthl;
    instruction_table[0xE9] = &CPU::pchl;
    instruction_table[0xF9] = &CPU::sphl;
}

void CPU::execute() {
    if(PC==0x0000)
    return;
    if(!bp.empty())
    {
        if(bp.front()!=PC)
        {
            uint8_t opcode =obj.mem[PC++];
            InstructionFunc func = instruction_table[opcode];
            if (func != nullptr) {
                (this->*func)();
            } else {
                std::cerr << "Invalid opcode: " << std::hex << static_cast<int>(opcode) << std::endl;
            }
            if(PC!=end)
            this->execute();
        }
        else
        {
            debug(PC);
            bp.pop();
            if(PC!=end)
            this->execute();
        }
    }
    else
    {
        uint8_t opcode =obj.mem[PC++];
            InstructionFunc func = instruction_table[opcode];
            if (func != nullptr) {
                (this->*func)();
            } else {
                std::cerr << "Invalid opcode: " << std::hex << static_cast<int>(opcode) << std::endl;
            }
            if(PC!=end)
            this->execute();
    }
}

#endif