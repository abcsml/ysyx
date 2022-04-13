// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencoder42__Syms.h"


void Vencoder42___024root__traceInitSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencoder42___024root__traceInitTop(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencoder42___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vencoder42___024root__traceInitSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"x", false,-1, 3,0);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"y", false,-1, 1,0);
        tracep->declBus(c+1,"encoder42 x", false,-1, 3,0);
        tracep->declBit(c+2,"encoder42 en", false,-1);
        tracep->declBus(c+3,"encoder42 y", false,-1, 1,0);
        tracep->declBit(c+4,"encoder42 a", false,-1);
        tracep->declBit(c+5,"encoder42 b", false,-1);
        tracep->declBit(c+6,"encoder42 c", false,-1);
        tracep->declBit(c+5,"encoder42 d", false,-1);
    }
}

void Vencoder42___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vencoder42___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vencoder42___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vencoder42___024root__traceRegister(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vencoder42___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vencoder42___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vencoder42___024root__traceCleanup, vlSelf);
    }
}

void Vencoder42___024root__traceFullSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencoder42___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencoder42___024root* const __restrict vlSelf = static_cast<Vencoder42___024root*>(voidSelf);
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencoder42___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencoder42___024root__traceFullSub0(Vencoder42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->x),4);
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->y),2);
        tracep->fullBit(oldp+4,(((IData)((2U == (0xfU 
                                                 & (IData)(vlSelf->x)))) 
                                 & (IData)(vlSelf->en))));
        tracep->fullBit(oldp+5,(((IData)((8U == (0xfU 
                                                 & (IData)(vlSelf->x)))) 
                                 & (IData)(vlSelf->en))));
        tracep->fullBit(oldp+6,(((IData)((4U == (0xfU 
                                                 & (IData)(vlSelf->x)))) 
                                 & (IData)(vlSelf->en))));
    }
}
