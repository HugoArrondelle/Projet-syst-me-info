library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use IEEE.NUMERIC_STD.ALL;


entity memory is
    Port ( addr : in  STD_LOGIC_VECTOR (7 downto 0);
           IN : in  STD_LOGIC_VECTOR (7 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           OUT : out  STD_LOGIC_VECTOR (7 downto 0));
end memory;

architecture Behavioral of memory is

	type data_array is array (NATURAL range <>) of STD_LOGIC_VECTOR(7 downto 0);
	signal data : data_array((2**8-1) downto 0); 
	signal OUT_aux : STD_LOGIC_VECTOR (7 downto 0);

begin

	process
	begin
		-- synchrone
		wait until CLK'event and CLK = '1';
			if (RST='0') then	
				-- mise a zero des donnees
				data <= (others => X"00"); 
			elsif (RST='1') then
				-- lecture
				if (RW='1') then
					OUT_aux <= data(to_integer(unsigned(addr)))  ;
				-- ecriture
				elsif (RW='0') then
					data(to_integer(unsigned(addr))) <= IN;
				end if;
			end if;
	end process;

	-- en //
	OUT <= OUT_aux;

end Behavioral;
