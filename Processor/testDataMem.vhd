LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY testDataMem IS
END testDataMem;
 
ARCHITECTURE behavior OF testDataMem IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT data_memory
    PORT(
         addr : IN  std_logic_vector(7 downto 0);
         IN_mem : IN  std_logic_vector(7 downto 0);
         RW : IN  std_logic;
         RST : IN  std_logic;
         CLK : IN  std_logic;
         OUT_mem : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal addr : std_logic_vector(7 downto 0) := (others => '0');
   signal IN_mem : std_logic_vector(7 downto 0) := (others => '0');
   signal RW : std_logic := '0';
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal OUT_mem : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: data_memory PORT MAP (
          addr => addr,
          IN_mem => IN_mem,
          RW => RW,
          RST => RST,
          CLK => CLK,
          OUT_mem => OUT_mem
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   RST<='0', '1' after 10 ns;
   RW<= '1' after 100 ns;
	IN_mem<=X"05";
	addr<=x"02";

END;
