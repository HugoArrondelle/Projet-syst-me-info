library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all; 
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity alu is 
    Port (A     	: in STD_LOGIC_VECTOR (7 downto 0);
          B     	: in STD_LOGIC_VECTOR (7 downto 0);
          Out_alu : out STD_LOGIC_VECTOR (7 downto 0);
          OP    	: in STD_LOGIC_VECTOR (3 downto 0);
          O     	: out STD_LOGIC;
          C     	: out STD_LOGIC
         );
end alu;


architecture Behavioral of alu is
    
    signal S_add :      STD_LOGIC_VECTOR (8 downto 0);
    signal S_sou :      STD_LOGIC_VECTOR (7 downto 0);
    signal S_mul_aux :  STD_LOGIC_VECTOR (15 downto 0);
    signal S_mul :      STD_LOGIC_VECTOR (7 downto 0);
    signal S_div :      STD_LOGIC_VECTOR (7 downto 0);
	 signal S_mul_ov : STD_LOGIC_VECTOR (15 downto 7);
	
    signal Out_aux :   STD_LOGIC_VECTOR (7 downto 0);
    signal O_aux :      STD_LOGIC;
    signal C_aux :      STD_LOGIC;


begin

	S_add <= (b"0" & A) + (b"0" & B);
	S_sou <= A-B; 
	S_mul_aux <= A*B;
	S_mul <= S_mul_aux(7 downto 0);

	Out_aux <=     S_add(7 downto 0) when OP=B"0001" else
                  S_sou(7 downto 0) when OP=B"0011" else
                  S_mul(7 downto 0) when OP=B"0010" else
                  "00000000";
    
   S_mul_ov <= S_mul_aux(15 downto 7);
   O_aux <= '0' when S_mul_ov = x"00" else '1';

	C_aux <= S_add(8) when (OP=B"0001") else '0';

                        
out_alu <= Out_aux;
O   <= O_aux;
C   <= C_aux;

end Behavioral;
