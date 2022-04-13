// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencoder42p__Syms.h"


void Vencoder42p___024root__traceChgSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep);

void Vencoder42p___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencoder42p___024root* const __restrict vlSelf = static_cast<Vencoder42p___024root*>(voidSelf);
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vencoder42p___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencoder42p___024root__traceChgSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlSelf->x),4);
        tracep->chgBit(oldp+1,(vlSelf->en));
        tracep->chgCData(oldp+2,(vlSelf->y),2);
        tracep->chgIData(oldp+3,(vlSelf->encoder42p__DOT__i),32);
    }
}

void Vencoder42p___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vencoder42p___024root* const __restrict vlSelf = static_cast<Vencoder42p___024root*>(voidSelf);
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
