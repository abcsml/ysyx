// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vkeyboard_sim.h"
#include "Vkeyboard_sim__Syms.h"

//============================================================
// Constructors

Vkeyboard_sim::Vkeyboard_sim(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vkeyboard_sim__Syms(_vcontextp__, _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
}

Vkeyboard_sim::Vkeyboard_sim(const char* _vcname__)
    : Vkeyboard_sim(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vkeyboard_sim::~Vkeyboard_sim() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vkeyboard_sim___024root___eval_initial(Vkeyboard_sim___024root* vlSelf);
void Vkeyboard_sim___024root___eval_settle(Vkeyboard_sim___024root* vlSelf);
void Vkeyboard_sim___024root___eval(Vkeyboard_sim___024root* vlSelf);
QData Vkeyboard_sim___024root___change_request(Vkeyboard_sim___024root* vlSelf);
#ifdef VL_DEBUG
void Vkeyboard_sim___024root___eval_debug_assertions(Vkeyboard_sim___024root* vlSelf);
#endif  // VL_DEBUG
void Vkeyboard_sim___024root___final(Vkeyboard_sim___024root* vlSelf);

static void _eval_initial_loop(Vkeyboard_sim__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vkeyboard_sim___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vkeyboard_sim___024root___eval_settle(&(vlSymsp->TOP));
        Vkeyboard_sim___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vkeyboard_sim___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/exp7/keyboard_sim_tb.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vkeyboard_sim___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vkeyboard_sim::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkeyboard_sim::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vkeyboard_sim___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vkeyboard_sim___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vkeyboard_sim___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/exp7/keyboard_sim_tb.v", 2, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vkeyboard_sim___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vkeyboard_sim::final() {
    Vkeyboard_sim___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vkeyboard_sim::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vkeyboard_sim::name() const {
    return vlSymsp->name();
}
