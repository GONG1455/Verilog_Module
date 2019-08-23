////////////////////////////////////////////////////////////////////////////////
// AHB-Lite Memory Module
////////////////////////////////////////////////////////////////////////////////
module AHB2MEM
   #(	parameter 	MEMWIDTH 	= 8,		//256 * data 
		parameter	DATAWIDTH 	= 32
   )               // Size = 32KB
   (
   input wire          	 			clk, 
   input wire          	 			wen,
   input wire	[MEMWIDTH-1:0]		waddr,		//д��ַ
   input wire	[MEMWIDTH-1:0]		raddr,		//����ַ
   input wire	[DATAWIDTH-1:0] 	data_in,	//д����
   output reg	[DATAWIDTH-1:0] 	data_out	//������
   );



// Memory Array
reg  [DATAWIDTH-1:0] memory[0:(2**(MEMWIDTH)-1)];

initial
begin
	$readmemh("initial_data.hex", memory);
end      

always@(posedge clk)
begin
	if(wen)
		memory[waddr]	<=	data_in;
end   

always@(posedge clk)
begin
	data_out	<=	memory[raddr];
end

endmodule
