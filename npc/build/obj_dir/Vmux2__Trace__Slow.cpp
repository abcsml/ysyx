// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux2__Syms.h"


void Vmux2___024root__traceInitSub0(Vmux2___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vmux2___024root__traceInitTop(Vmux2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vmux2___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vmux2___024root__traceInitSub0(Vmux2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"a", false,-1);
        tracep->declBit(c+2,"b", false,-1);
        tracep->declBit(c+3,"s", false,-1);
        tracep->declBit(c+4,"y", false,-1);
        tracep->declBit(c+1,"mux2 a", false,-1);
        tracep->declBit(c+2,"mux2 b", false,-1);
        tracep->declBit(c+3,"mux2 s", false,-1);
        tracep->declBit(c+4,"mux2 y", false,-1);
    }
}

void Vmux2___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vmux2___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vmux2___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vmux2___024root__traceRegister(Vmux2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vmux2___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vmux2___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vmux2___024root__traceCleanup, vlSelf);
    }
}

void Vmux2___024root__traceFullSub0(Vmux2___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vmux2___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vmux2___024root* const __restrict vlSelf = static_cast<Vmux2___024root*>(voidSelf);
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vmux2___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vmux2___024root__traceFullSub0(Vmux2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->a));
        tracep->fullBit(oldp+2,(vlSelf->b));
        tracep->fullBit(oldp+3,(vlSelf->s));
        tracep->fullBit(oldp+4,(vlSelf->y));
    }
}
