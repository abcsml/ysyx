module ps2_ROM(
	input R,
	input [7:0] addr,
	output [7:0] data_out);
	
	wire [7:0] rom[0:35];
	
	assign rom[0] = 8'h45;  // +d48
	assign rom[1] = 8'h16;
	assign rom[2] = 8'h1e;
	assign rom[3] = 8'h26;
	assign rom[4] = 8'h25;
	assign rom[5] = 8'h2e;
	assign rom[6] = 8'h36;
	assign rom[7] = 8'h3d;
	assign rom[8] = 8'h3e;
	assign rom[9] = 8'h46;
	assign rom[10] = 8'h1c;  // +d87
	assign rom[11] = 8'h32;
	assign rom[12] = 8'h21;  // C
	assign rom[13] = 8'h23;
	assign rom[14] = 8'h24;
	assign rom[15] = 8'h2b;
	assign rom[16] = 8'h34;
	assign rom[17] = 8'h33;
	assign rom[18] = 8'h43;
	assign rom[19] = 8'h3b;
	assign rom[20] = 8'h42;
	assign rom[21] = 8'h4b;
	assign rom[22] = 8'h3a;
	assign rom[23] = 8'h31;
	assign rom[24] = 8'h44;
	assign rom[25] = 8'h4d;
	assign rom[26] = 8'h15;
	assign rom[27] = 8'h2d;
	assign rom[28] = 8'h1b;
	assign rom[29] = 8'h2c;
	assign rom[30] = 8'h3c;
	assign rom[31] = 8'h2a;
	assign rom[32] = 8'h1d;
	assign rom[33] = 8'h22;
	assign rom[34] = 8'h35;
	assign rom[35] = 8'h1a;
	
	assign data_out = !R ? rom[addr[5:0]] : 8'bz;
endmodule