library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;



entity pipeline is
    Port ( CLK   : in  STD_LOGIC;
           A_in   : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_in  : in  STD_LOGIC_VECTOR (7 downto 0);
           B_in   : in  STD_LOGIC_VECTOR (7 downto 0);
           C_in   : in  STD_LOGIC_VECTOR (7 downto 0);
           A_out  : out  STD_LOGIC_VECTOR (7 downto 0);
           OP_out : out  STD_LOGIC_VECTOR (7 downto 0);
           B_out  : out  STD_LOGIC_VECTOR (7 downto 0);
           C_out  : out  STD_LOGIC_VECTOR (7 downto 0));
end pipeline;

architecture Behavioral of pipeline is

begin

-- comportement synchrone
	process
	begin
		wait until CLK'event and CLK = '1';
			OP_out <= OP_in;
			A_out  <= A_in;
			B_out  <= B_in;
			C_out  <= C_in;
	end process;

end Behavioral;

