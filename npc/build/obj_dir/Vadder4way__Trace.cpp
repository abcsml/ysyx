// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadder4way__Syms.h"


void Vadder4way___024root__traceChgSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep);

void Vadder4way___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vadder4way___024root* const __restrict vlSelf = static_cast<Vadder4way___024root*>(voidSelf);
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vadder4way___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vadder4way___024root__traceChgSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlSelf->x),4);
        tracep->chgCData(oldp+1,(vlSelf->y),4);
        tracep->chgCData(oldp+2,(vlSelf->s),4);
        tracep->chgBit(oldp+3,(vlSelf->c));
        tracep->chgBit(oldp+4,(vlSelf->o));
        tracep->chgBit(oldp+5,(vlSelf->z));
    }
}

void Vadder4way___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vadder4way___024root* const __restrict vlSelf = static_cast<Vadder4way___024root*>(voidSelf);
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
