library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity lc is
	Generic (        lc_number : STD_LOGIC:='0');
    Port ( 	        OP  :    in  STD_LOGIC_VECTOR (7 downto 0);
                    val :    out  STD_LOGIC);
end lc;

architecture Behavioral of lc is

begin

	val <=  '1' when (
                        lc_number = '0' AND (
                        OP=X"01" OR
                        OP=X"02" OR
                        OP=X"03" OR
                        OP=X"04" OR
                        OP=X"05" OR
                        OP=X"06" OR
                        OP=X"07"  )) else
                        
            '0' when (lc_number = '1' AND OP=X"08" ) else
            '1' when (lc_number = '1') else
            '0';
	

	
end Behavioral;
