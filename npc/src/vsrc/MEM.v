module MEM(
  input              clock,
  input              reset,
  input       [63:0] addr,
  input       [2:0]  len,
  output      [31:0] data
);
import "DPI-C" function void vmem_read(
  input  bit[63:0] addr,
  input  bit[2:0]  len,
  output bit[31:0] data,
  input  bit       reset
);
always @(edge clock) begin
  vmem_read(addr, len, data, reset);
end

endmodule