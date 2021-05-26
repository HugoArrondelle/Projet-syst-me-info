LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY testInstrMem IS
END testInstrMem;
 
ARCHITECTURE behavior OF testInstrMem IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT instr_memory
    PORT(
         addr : IN  std_logic_vector(7 downto 0);
         CLK : IN  std_logic;
         OUT_instruction : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal addr : std_logic_vector(7 downto 0) := (others => '0');
   signal CLK : std_logic := '0';

 	--Outputs
   signal OUT_instruction : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: instr_memory PORT MAP (
          addr => addr,
          CLK => CLK,
          OUT_instruction => OUT_instruction
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 
   addr <=X"01";

END;
