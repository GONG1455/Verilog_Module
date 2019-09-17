////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
module BRAM 
   #(	parameter 	MEMWIDTH 	= 10,		//1024 * data 
		parameter	DATAWIDTH 	= 32
   )               
   (
   input wire          	 			clk, 
   input wire          	 			wr_en,
   input wire						rd_en,
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
	if( wr_en )
		memory[waddr]	<=	data_in;
end   

always@(posedge clk)
begin
	if( rd_en )
	data_out	<=	memory[raddr];
end

endmodule
