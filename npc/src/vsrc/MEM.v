module MEM(
  input              clock,
  input              reset,
  input              en,
  input              rw,
  input       [63:0] addr,
  input       [3:0]  len,
  input       [63:0] dataIn,
  output      [63:0] dataOut
);
import "DPI-C" function void vmem_read(
  input            en,
  input            rw,
  input  bit[63:0] addr,
  input  bit[3:0]  len,
  input  bit[63:0] dataIn,
  output bit[63:0] dataOut,
  input  bit       reset
);
always @(addr) begin
  vmem_read(en, rw, addr, len, dataIn, dataOut, reset);
end

endmodule