// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadder4way__Syms.h"


void Vadder4way___024root__traceInitSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vadder4way___024root__traceInitTop(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vadder4way___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vadder4way___024root__traceInitSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"x", false,-1, 3,0);
        tracep->declBus(c+2,"y", false,-1, 3,0);
        tracep->declBus(c+3,"s", false,-1, 3,0);
        tracep->declBit(c+4,"c", false,-1);
        tracep->declBit(c+5,"o", false,-1);
        tracep->declBit(c+6,"z", false,-1);
        tracep->declBus(c+1,"adder4way x", false,-1, 3,0);
        tracep->declBus(c+2,"adder4way y", false,-1, 3,0);
        tracep->declBus(c+3,"adder4way s", false,-1, 3,0);
        tracep->declBit(c+4,"adder4way c", false,-1);
        tracep->declBit(c+5,"adder4way o", false,-1);
        tracep->declBit(c+6,"adder4way z", false,-1);
        tracep->declBus(c+7,"adder4way a1 n", false,-1, 31,0);
        tracep->declBus(c+1,"adder4way a1 x", false,-1, 3,0);
        tracep->declBus(c+2,"adder4way a1 y", false,-1, 3,0);
        tracep->declBus(c+3,"adder4way a1 s", false,-1, 3,0);
        tracep->declBit(c+4,"adder4way a1 c", false,-1);
        tracep->declBit(c+5,"adder4way a1 o", false,-1);
        tracep->declBit(c+6,"adder4way a1 z", false,-1);
    }
}

void Vadder4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vadder4way___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vadder4way___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vadder4way___024root__traceRegister(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vadder4way___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vadder4way___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vadder4way___024root__traceCleanup, vlSelf);
    }
}

void Vadder4way___024root__traceFullSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vadder4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vadder4way___024root* const __restrict vlSelf = static_cast<Vadder4way___024root*>(voidSelf);
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vadder4way___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vadder4way___024root__traceFullSub0(Vadder4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->x),4);
        tracep->fullCData(oldp+2,(vlSelf->y),4);
        tracep->fullCData(oldp+3,(vlSelf->s),4);
        tracep->fullBit(oldp+4,(vlSelf->c));
        tracep->fullBit(oldp+5,(vlSelf->o));
        tracep->fullBit(oldp+6,(vlSelf->z));
        tracep->fullIData(oldp+7,(4U),32);
    }
}
