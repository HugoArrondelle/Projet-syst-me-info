library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all; 
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity alu is 
    Port (A     : in STD_LOGIC_VECTOR (7 downto 0);
          B     : in STD_LOGIC_VECTOR (7 downto 0);
          Out   : out STD_LOGIC_VECTOR (7 downto 0);
          OP    : in STD_LOGIC_VECTOR (1 downto 0);
          N     : out STD_LOGIC;
          O     : out STD_LOGIC;
          C     : out STD_LOGIC
         );
end alu;


architecture Behavioral of alu is
    
    -- signaux auxiliaires (pour les operations)
    signal S_add :      STD_LOGIC_VECTOR (8 downto 0);
    signal S_sou :      STD_LOGIC_VECTOR (7 downto 0);
    signal S_mul_aux :  STD_LOGIC_VECTOR (15 downto 0);
    signal S_mul :      STD_LOGIC_VECTOR (7 downto 0);
    signal S_div :      STD_LOGIC_VECTOR (7 downto 0);
	
    -- signaux auxiliaires (on ne peut pas recuperer la valeurs d'un out)
    signal Out_aux :   STD_LOGIC_VECTOR (7 downto 0);
    signal N_aux :      STD_LOGIC;
    signal O_aux :      STD_LOGIC;
    signal Z_aux :      STD_LOGIC;
    signal C_aux :      STD_LOGIC;


begin

	--operation******************
    
	S_add <= (b"0" & A) + (b"0" & B);
	S_sou <= A-B; 
	S_mul_aux <= A*B;
	S_mul <= S_mul_aux(7 downto 0);

	--affectation*****************
    
	Out_aux <=     S_add(7 downto 0) when OP=B"01" else
                   S_sou(7 downto 0) when OP=B"11" else
                   S_mul(7 downto 0) when OP=B"10" else
                    "00000000";

	--flags***********************

	--overflow
    
    S_mul_ov <= S_mul_aux(15 downto 7);
    O_aux <= '0' when S_mul_ov = x"00" else '1';

	--carry
	C_aux <= S_add(8) when (OP=B"001") else '0';

    --negative
    N_aux <= '1' when ( ( OP=B"001" and S_add(7)='1' ) or
                        ( OP=B"011" and S_sou(7)='1' ) or
                        ( OP=B"010" and S_mul(7)='1' ) ) else '0';
                        
                        
                        

out <= Out_aux;
O   <= O_aux;
Z   <= Z_aux;
N   <= N_aux;
C   <= C_aux;

end Behavioral;
