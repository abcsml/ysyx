// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vencoder42.h"
#include "Vencoder42__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vencoder42::Vencoder42(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vencoder42__Syms(_vcontextp__, _vcname__, this)}
    , x{vlSymsp->TOP.x}
    , en{vlSymsp->TOP.en}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vencoder42::Vencoder42(const char* _vcname__)
    : Vencoder42(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vencoder42::~Vencoder42() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vencoder42___024root___eval_initial(Vencoder42___024root* vlSelf);
void Vencoder42___024root___eval_settle(Vencoder42___024root* vlSelf);
void Vencoder42___024root___eval(Vencoder42___024root* vlSelf);
QData Vencoder42___024root___change_request(Vencoder42___024root* vlSelf);
#ifdef VL_DEBUG
void Vencoder42___024root___eval_debug_assertions(Vencoder42___024root* vlSelf);
#endif  // VL_DEBUG
void Vencoder42___024root___final(Vencoder42___024root* vlSelf);

static void _eval_initial_loop(Vencoder42__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vencoder42___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vencoder42___024root___eval_settle(&(vlSymsp->TOP));
        Vencoder42___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vencoder42___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp2/encoder42.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vencoder42___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vencoder42::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vencoder42::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vencoder42___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vencoder42___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vencoder42___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp2/encoder42.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vencoder42___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vencoder42::final() {
    Vencoder42___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vencoder42::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vencoder42::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vencoder42___024root__traceInitTop(Vencoder42___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vencoder42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencoder42___024root*>(voidSelf);
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vencoder42___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vencoder42___024root__traceRegister(Vencoder42___024root* vlSelf, VerilatedVcd* tracep);

void Vencoder42::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vencoder42___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
