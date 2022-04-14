// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU4way__Syms.h"


void VALU4way___024root__traceChgSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep);

void VALU4way___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VALU4way___024root* const __restrict vlSelf = static_cast<VALU4way___024root*>(voidSelf);
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VALU4way___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VALU4way___024root__traceChgSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlSelf->ALU4way__DOT__add),4);
            tracep->chgCData(oldp+1,(vlSelf->ALU4way__DOT__sub),4);
            tracep->chgBit(oldp+2,((1U & (~ (IData)(
                                                    (0U 
                                                     != (IData)(vlSelf->ALU4way__DOT__add)))))));
            tracep->chgBit(oldp+3,((1U & (~ (IData)(
                                                    (0U 
                                                     != (IData)(vlSelf->ALU4way__DOT__sub)))))));
        }
        tracep->chgCData(oldp+4,(vlSelf->a),4);
        tracep->chgCData(oldp+5,(vlSelf->b),4);
        tracep->chgCData(oldp+6,(vlSelf->sel),3);
        tracep->chgCData(oldp+7,(vlSelf->out),4);
        tracep->chgBit(oldp+8,(vlSelf->cf));
        tracep->chgBit(oldp+9,(vlSelf->of));
        tracep->chgBit(oldp+10,(vlSelf->zf));
        tracep->chgBit(oldp+11,((1U & (((IData)(vlSelf->a) 
                                        + (0xfU & (~ 
                                                   ((IData)(1U) 
                                                    + (IData)(vlSelf->b))))) 
                                       >> 4U))));
        tracep->chgBit(oldp+12,((1U & ((~ (((IData)(vlSelf->a) 
                                            >> 3U) 
                                           ^ (~ (1U 
                                                 & (((IData)(1U) 
                                                     + (IData)(vlSelf->b)) 
                                                    >> 3U))))) 
                                       & (((IData)(vlSelf->ALU4way__DOT__add) 
                                           ^ (IData)(vlSelf->a)) 
                                          >> 3U)))));
        tracep->chgBit(oldp+13,((1U & (((IData)(vlSelf->a) 
                                        + (IData)(vlSelf->b)) 
                                       >> 4U))));
        tracep->chgBit(oldp+14,((1U & ((~ (((IData)(vlSelf->a) 
                                            ^ (IData)(vlSelf->b)) 
                                           >> 3U)) 
                                       & (((IData)(vlSelf->ALU4way__DOT__sub) 
                                           ^ (IData)(vlSelf->a)) 
                                          >> 3U)))));
        tracep->chgCData(oldp+15,((0xfU & (~ ((IData)(1U) 
                                              + (IData)(vlSelf->b))))),4);
    }
}

void VALU4way___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VALU4way___024root* const __restrict vlSelf = static_cast<VALU4way___024root*>(voidSelf);
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
