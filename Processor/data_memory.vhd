library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use IEEE.NUMERIC_STD.ALL;


entity data_memory is
    Port ( addr : in  STD_LOGIC_VECTOR (7 downto 0);
           IN_mem : in  STD_LOGIC_VECTOR (7 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           OUT_mem : out  STD_LOGIC_VECTOR (7 downto 0));
end data_memory;

architecture Behavioral of data_memory is

	type data_array is array (NATURAL range <>) of STD_LOGIC_VECTOR(7 downto 0);
	signal data : data_array((2**8-1) downto 0); 
	signal OUT_aux : STD_LOGIC_VECTOR (7 downto 0);

begin

	process
	begin
		wait until CLK'event and CLK = '1';
			if (RST='0') then	
				data <= (others => X"00"); 
			elsif (RST='1') then
				if (RW='1') then
					OUT_aux <= data(to_integer(unsigned(addr)));
				elsif (RW='0') then
					data(to_integer(unsigned(addr))) <= IN_mem;
				end if;
			end if;
	end process;

	OUT_mem <= OUT_aux;

end Behavioral;
