
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use std.textio.all;
use ieee.std_logic_textio.all;

use IEEE.NUMERIC_STD.ALL;


entity instr_memory is
    
	Port (       addr : in  STD_LOGIC_VECTOR (7 downto 0);
                CLK : in  STD_LOGIC;
                OUT_instruction : out  STD_LOGIC_VECTOR (31 downto 0));
end instr_memory;

architecture Behavioral of instr_memory is

    type mem_instr is array(0 to 255) of std_logic_vector(31 downto 0);
    constant OUT_instruction_AUX : mem_instr := (
    X"06000500",
    X"06010A00",
    X"06020800",
    X"06010400",
    X"05030000",
    X"01040002",
    others => X"00000000");
begin
	
	process
	begin
		wait until CLK'event and CLK = '1';
		OUT_instruction <= OUT_instruction_AUX(to_integer(unsigned(addr)));
	end process;

end Behavioral;