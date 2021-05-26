
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity registre is
    Port ( addrA    : in  STD_LOGIC_VECTOR (3 downto 0);
           addrB    : in  STD_LOGIC_VECTOR (3 downto 0);
           addrW    : in  STD_LOGIC_VECTOR (3 downto 0);
           W        : in  STD_LOGIC;
           DATA     : in  STD_LOGIC_VECTOR (7 downto 0);
           RST      : in  STD_LOGIC;
           CLK      : in  STD_LOGIC;
           QA       : out  STD_LOGIC_VECTOR (7 downto 0);
           QB       : out  STD_LOGIC_VECTOR (7 downto 0));
end registre;

architecture Behavioral of registre is

	type registres is array (NATURAL range <>) of STD_LOGIC_VECTOR(7 downto 0);
	signal reg : registres(15 downto 0);

begin

	process
	begin
		wait until CLK'event and CLK = '1';
			if (RST='0') then
				reg <= (others => X"00");
			elsif (W='1') then
				reg(to_integer(unsigned(addrW))) <= DATA;				
			end if;
	end process;
	
	--BYPASS
    QA <= DATA when (W='1' and addrA = addrW) else
        reg(to_integer(unsigned(addrA)));
    QB <= DATA when (W='1' and addrB = addrW) else
        reg(to_integer(unsigned(addrB)));
   
end Behavioral;
