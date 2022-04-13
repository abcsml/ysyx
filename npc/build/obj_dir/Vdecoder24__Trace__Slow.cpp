// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecoder24__Syms.h"


void Vdecoder24___024root__traceInitSub0(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vdecoder24___024root__traceInitTop(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vdecoder24___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vdecoder24___024root__traceInitSub0(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"x", false,-1, 1,0);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"y", false,-1, 3,0);
        tracep->declBus(c+1,"decoder24 x", false,-1, 1,0);
        tracep->declBit(c+2,"decoder24 en", false,-1);
        tracep->declBus(c+3,"decoder24 y", false,-1, 3,0);
    }
}

void Vdecoder24___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vdecoder24___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vdecoder24___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vdecoder24___024root__traceRegister(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vdecoder24___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vdecoder24___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vdecoder24___024root__traceCleanup, vlSelf);
    }
}

void Vdecoder24___024root__traceFullSub0(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vdecoder24___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vdecoder24___024root* const __restrict vlSelf = static_cast<Vdecoder24___024root*>(voidSelf);
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vdecoder24___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vdecoder24___024root__traceFullSub0(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->x),2);
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->y),4);
    }
}
