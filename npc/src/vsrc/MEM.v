module MEM(
  input              clk,
  input       [63:0] addr,
  input       [2:0]  len,
  output      [31:0] data
);
import "DPI-C" function void pmem_read(
  input  bit[63:0] addr,
  input  bit[2:0]  len,
  output bit[31:0] data
);
always @(posedge clk) begin
  pmem_read(addr, len, data);
end

endmodule