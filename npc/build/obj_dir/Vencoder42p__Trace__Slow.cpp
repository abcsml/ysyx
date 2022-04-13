// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencoder42p__Syms.h"


void Vencoder42p___024root__traceInitSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencoder42p___024root__traceInitTop(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencoder42p___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vencoder42p___024root__traceInitSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"x", false,-1, 3,0);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"y", false,-1, 1,0);
        tracep->declBus(c+1,"encoder42p x", false,-1, 3,0);
        tracep->declBit(c+2,"encoder42p en", false,-1);
        tracep->declBus(c+3,"encoder42p y", false,-1, 1,0);
        tracep->declBus(c+4,"encoder42p i", false,-1, 31,0);
    }
}

void Vencoder42p___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vencoder42p___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vencoder42p___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vencoder42p___024root__traceRegister(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vencoder42p___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vencoder42p___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vencoder42p___024root__traceCleanup, vlSelf);
    }
}

void Vencoder42p___024root__traceFullSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencoder42p___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencoder42p___024root* const __restrict vlSelf = static_cast<Vencoder42p___024root*>(voidSelf);
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencoder42p___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencoder42p___024root__traceFullSub0(Vencoder42p___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->x),4);
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->y),2);
        tracep->fullIData(oldp+4,(vlSelf->encoder42p__DOT__i),32);
    }
}
