LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY testProcesseur IS
END testProcesseur;
 
ARCHITECTURE behavior OF testProcesseur IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT processor
    PORT(
         CLK_PROC : IN  std_logic;
         RST_PROC : IN  std_logic;
         IP : IN  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK_PROC : std_logic := '0';
   signal RST_PROC : std_logic := '0';
   signal IP : std_logic_vector(7 downto 0) := (others => '0');

   -- Clock period definitions
   constant CLK_PROC_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: processor PORT MAP (
          CLK_PROC => CLK_PROC,
          RST_PROC => RST_PROC,
          IP => IP
        );

   -- Clock process definitions
   CLK_PROC_process :process
   begin
		CLK_PROC <= '0';
		wait for CLK_PROC_period/2;
		CLK_PROC <= '1';
		wait for CLK_PROC_period/2;
   end process;
 

   IP<=X"00" after 0 ns,
	X"01" after 50 ns,
	X"02" after 100 ns,
	X"03" after 150 ns,
	X"04" after 200 ns,
	X"05" after 250 ns,
	X"06" after 300 ns,
	X"07" after 350 ns,
	X"08" after 400 ns,
	X"09" after 450 ns,
	X"0A" after 500 ns,
	X"0B" after 550 ns,
	X"0C" after 600 ns,
	X"0D" after 650 ns,
	X"0E" after 700 ns,
	X"0F" after 750 ns;
	
END;
