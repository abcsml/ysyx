// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU4way__Syms.h"


void VALU4way___024root__traceInitSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4way___024root__traceInitTop(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4way___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VALU4way___024root__traceInitSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+5,"a", false,-1, 3,0);
        tracep->declBus(c+6,"b", false,-1, 3,0);
        tracep->declBus(c+7,"sel", false,-1, 2,0);
        tracep->declBus(c+8,"out", false,-1, 3,0);
        tracep->declBit(c+9,"cf", false,-1);
        tracep->declBit(c+10,"of", false,-1);
        tracep->declBit(c+11,"zf", false,-1);
        tracep->declBus(c+5,"ALU4way a", false,-1, 3,0);
        tracep->declBus(c+6,"ALU4way b", false,-1, 3,0);
        tracep->declBus(c+7,"ALU4way sel", false,-1, 2,0);
        tracep->declBus(c+8,"ALU4way out", false,-1, 3,0);
        tracep->declBit(c+9,"ALU4way cf", false,-1);
        tracep->declBit(c+10,"ALU4way of", false,-1);
        tracep->declBit(c+11,"ALU4way zf", false,-1);
        tracep->declBus(c+1,"ALU4way add", false,-1, 3,0);
        tracep->declBus(c+2,"ALU4way sub", false,-1, 3,0);
        tracep->declBit(c+12,"ALU4way addcf", false,-1);
        tracep->declBit(c+13,"ALU4way addof", false,-1);
        tracep->declBit(c+3,"ALU4way addzf", false,-1);
        tracep->declBit(c+14,"ALU4way subcf", false,-1);
        tracep->declBit(c+15,"ALU4way subof", false,-1);
        tracep->declBit(c+4,"ALU4way subzf", false,-1);
        tracep->declBus(c+17,"ALU4way a1 n", false,-1, 31,0);
        tracep->declBus(c+5,"ALU4way a1 x", false,-1, 3,0);
        tracep->declBus(c+6,"ALU4way a1 y", false,-1, 3,0);
        tracep->declBit(c+18,"ALU4way a1 sel", false,-1);
        tracep->declBus(c+1,"ALU4way a1 s", false,-1, 3,0);
        tracep->declBit(c+12,"ALU4way a1 c", false,-1);
        tracep->declBit(c+13,"ALU4way a1 o", false,-1);
        tracep->declBit(c+3,"ALU4way a1 z", false,-1);
        tracep->declBus(c+16,"ALU4way a1 t", false,-1, 3,0);
        tracep->declBus(c+17,"ALU4way a2 n", false,-1, 31,0);
        tracep->declBus(c+5,"ALU4way a2 x", false,-1, 3,0);
        tracep->declBus(c+6,"ALU4way a2 y", false,-1, 3,0);
        tracep->declBit(c+19,"ALU4way a2 sel", false,-1);
        tracep->declBus(c+2,"ALU4way a2 s", false,-1, 3,0);
        tracep->declBit(c+14,"ALU4way a2 c", false,-1);
        tracep->declBit(c+15,"ALU4way a2 o", false,-1);
        tracep->declBit(c+4,"ALU4way a2 z", false,-1);
        tracep->declBus(c+6,"ALU4way a2 t", false,-1, 3,0);
    }
}

void VALU4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VALU4way___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VALU4way___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VALU4way___024root__traceRegister(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VALU4way___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VALU4way___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VALU4way___024root__traceCleanup, vlSelf);
    }
}

void VALU4way___024root__traceFullSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VALU4way___024root* const __restrict vlSelf = static_cast<VALU4way___024root*>(voidSelf);
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4way___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VALU4way___024root__traceFullSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->ALU4way__DOT__add),4);
        tracep->fullCData(oldp+2,(vlSelf->ALU4way__DOT__sub),4);
        tracep->fullBit(oldp+3,((1U & (~ (IData)((0U 
                                                  != (IData)(vlSelf->ALU4way__DOT__add)))))));
        tracep->fullBit(oldp+4,((1U & (~ (IData)((0U 
                                                  != (IData)(vlSelf->ALU4way__DOT__sub)))))));
        tracep->fullCData(oldp+5,(vlSelf->a),4);
        tracep->fullCData(oldp+6,(vlSelf->b),4);
        tracep->fullCData(oldp+7,(vlSelf->sel),3);
        tracep->fullCData(oldp+8,(vlSelf->out),4);
        tracep->fullBit(oldp+9,(vlSelf->cf));
        tracep->fullBit(oldp+10,(vlSelf->of));
        tracep->fullBit(oldp+11,(vlSelf->zf));
        tracep->fullBit(oldp+12,((1U & (((IData)(1U) 
                                         + ((IData)(vlSelf->a) 
                                            + (0xfU 
                                               & (~ (IData)(vlSelf->b))))) 
                                        >> 4U))));
        tracep->fullBit(oldp+13,((1U & ((~ (((IData)(vlSelf->a) 
                                             >> 3U) 
                                            ^ (~ ((IData)(vlSelf->b) 
                                                  >> 3U)))) 
                                        & (((IData)(vlSelf->ALU4way__DOT__add) 
                                            ^ (IData)(vlSelf->a)) 
                                           >> 3U)))));
        tracep->fullBit(oldp+14,((1U & (((IData)(vlSelf->a) 
                                         + (IData)(vlSelf->b)) 
                                        >> 4U))));
        tracep->fullBit(oldp+15,((1U & ((~ (((IData)(vlSelf->a) 
                                             ^ (IData)(vlSelf->b)) 
                                            >> 3U)) 
                                        & (((IData)(vlSelf->ALU4way__DOT__sub) 
                                            ^ (IData)(vlSelf->a)) 
                                           >> 3U)))));
        tracep->fullCData(oldp+16,((0xfU & (~ (IData)(vlSelf->b)))),4);
        tracep->fullIData(oldp+17,(4U),32);
        tracep->fullBit(oldp+18,(1U));
        tracep->fullBit(oldp+19,(0U));
    }
}
