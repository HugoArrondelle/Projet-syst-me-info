
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity lc is
	Generic (       num_lc : STD_LOGIC:='0');
    Port ( 	        OP  :    in  STD_LOGIC_VECTOR (3 downto 0);
                    val :    out  STD_LOGIC);
end lc;

architecture Behavioral of lc is

begin

	val <=  '1' when (
                        num_lc = '0' AND (
                        OP=X"1" OR
                        OP=X"2" OR
                        OP=X"3" OR
                        OP=X"4" OR
                        OP=X"5" OR
                        OP=X"6" OR
                        OP=X"7"  )) else --gestion de LOG_C (registre) AFC COP
                        
            '0' when (num_lc = '1' AND OP=X"8" ) else --gestion de LC_MEM (MEM) LOAD AND STORE
            '1' when (num_lc = '1') else
            '0';
	

	
end Behavioral;

-- LC permet de dire s'il faut ecrire dans le banc de registre


