// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencoder42__Syms.h"


void Vencoder42___024root__traceChgSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep);

void Vencoder42___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencoder42___024root* const __restrict vlSelf = static_cast<Vencoder42___024root*>(voidSelf);
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vencoder42___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencoder42___024root__traceChgSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlSelf->x),4);
        tracep->chgBit(oldp+1,(vlSelf->en));
        tracep->chgCData(oldp+2,(vlSelf->y),2);
        tracep->chgBit(oldp+3,(((IData)((2U == (0xfU 
                                                & (IData)(vlSelf->x)))) 
                                & (IData)(vlSelf->en))));
        tracep->chgBit(oldp+4,(((IData)((8U == (0xfU 
                                                & (IData)(vlSelf->x)))) 
                                & (IData)(vlSelf->en))));
        tracep->chgBit(oldp+5,(((IData)((4U == (0xfU 
                                                & (IData)(vlSelf->x)))) 
                                & (IData)(vlSelf->en))));
    }
}

void Vencoder42___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vencoder42___024root* const __restrict vlSelf = static_cast<Vencoder42___024root*>(voidSelf);
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
