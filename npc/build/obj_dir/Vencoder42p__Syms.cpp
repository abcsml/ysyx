// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vencoder42p__Syms.h"
#include "Vencoder42p.h"
#include "Vencoder42p___024root.h"

// FUNCTIONS
Vencoder42p__Syms::~Vencoder42p__Syms()
{
}

Vencoder42p__Syms::Vencoder42p__Syms(VerilatedContext* contextp, const char* namep,Vencoder42p* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
