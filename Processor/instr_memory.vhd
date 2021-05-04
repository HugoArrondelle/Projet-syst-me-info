
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use std.textio.all;
use ieee.std_logic_textio.all;

use IEEE.NUMERIC_STD.ALL;


entity instr_memory is
    
	Port (      addr : in  STD_LOGIC_VECTOR (7 downto 0);
                CLK : in  STD_LOGIC;
                OUT_instruction : out  STD_LOGIC_VECTOR (31 downto 0));
end instr_memory;

--00120406 ecriture dans le fichier pour ADD 12 4 6

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






--
    -- Permet de recuperer un fichier avec les instructions a executer
--    type mem_array_t is array(0 to 2**8-1) of std_logic_vector(31 downto 0);
    -- Init memory with the filename "init_file" or not.
--    impure function init_mem(filename: in string) return mem_array_t is
--        file f_handler: text;
--        variable mem: mem_array_t;
--        variable f_line: line;
--        variable data_line : std_logic_vector(31 downto 0);
--        variable good: boolean;
--        variable lineno: integer := 0;
--        begin
--         mem := (others => (others => '0'));
--         file_open(f_handler, filename, READ_MODE);
--         while (not endfile(f_handler)) loop
--            readline(f_handler, f_line);
--            hread(f_line, data_line, good);
--            assert good report "READ ERROR" severity warning;
--            mem(lineno) := data_line;
--            lineno := lineno + 1;
--         end loop;
--         file_close(f_handler);
--         return mem;
--        end function;
        
--    signal OUT_instruction_AUX : mem_array_t := init_mem(filename => "./executable.hex");
    
