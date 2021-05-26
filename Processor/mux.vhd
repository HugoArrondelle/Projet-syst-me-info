
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity mux is
	Generic ( mux_number : NATURAL := 0);
	Port ( 	 A          : in  STD_LOGIC_VECTOR (7 downto 0);
				 B          : in  STD_LOGIC_VECTOR (7 downto 0);
				 OP         : in  STD_LOGIC_VECTOR (7 downto 0);
				 OUT_mux    : out  STD_LOGIC_VECTOR (7 downto 0));
end mux;

architecture Behavioral of mux is
begin
	OUT_mux <=    A when (mux_number = 1 and OP = X"06") else 
			B when (mux_number = 1 and OP = X"05") else
			B when (mux_number = 1 and OP = X"07") else
			B when (mux_number = 1 and OP = X"08") else
			B when (mux_number = 1) else
			B when (mux_number = 2 and OP = X"01") else
			B when (mux_number = 2 and OP = X"02") else
         B when (mux_number = 2 and OP = X"03") else
			B when (mux_number = 2 and OP = X"04") else
			A when (mux_number = 2 ) else
			A when (mux_number = 3 and OP = X"07") else
			B when (mux_number = 3 ) else
			A when (mux_number = 4 and OP = X"08") else
			B;
end Behavioral;

